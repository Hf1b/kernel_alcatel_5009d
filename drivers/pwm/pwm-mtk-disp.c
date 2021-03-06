
#include <linux/clk.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/pwm.h>
#include <linux/slab.h>

#define DISP_PWM_EN		0x00

#define DISP_PWM_COMMIT		0x08
#define PWM_COMMIT_MASK		BIT(0)

#define PWM_CLKDIV_SHIFT	16
#define PWM_CLKDIV_MAX		0x3ff
#define PWM_CLKDIV_MASK		(PWM_CLKDIV_MAX << PWM_CLKDIV_SHIFT)

#define PWM_PERIOD_BIT_WIDTH	12
#define PWM_PERIOD_MASK		((1 << PWM_PERIOD_BIT_WIDTH) - 1)

#define PWM_HIGH_WIDTH_SHIFT	16
#define PWM_HIGH_WIDTH_MASK	(0x1fff << PWM_HIGH_WIDTH_SHIFT)

#define PWM_MANUAL_SEL_MASK	BIT(1)

#define HW_VERSION_V1		1
#define HW_VERSION_V2		2

struct mtk_pwm_data {
	unsigned int enable_mask;
	unsigned int enable_value;
	unsigned int con0;
	unsigned int con0_sel;
	unsigned int con1;
	unsigned int version;
};

struct mtk_disp_pwm {
	struct pwm_chip chip;
	struct clk *clk_main;
	struct clk *clk_mm;
	void __iomem *base;
	const struct mtk_pwm_data *data;
};

static inline struct mtk_disp_pwm *to_mtk_disp_pwm(struct pwm_chip *chip)
{
	return container_of(chip, struct mtk_disp_pwm, chip);
}

static void mtk_disp_pwm_update_bits(struct mtk_disp_pwm *mdp, u32 offset,
				     u32 mask, u32 data)
{
	void __iomem *address = mdp->base + offset;
	u32 value;

	value = readl(address);
	value &= ~mask;
	value |= data;
	writel(value, address);
}

static int mtk_disp_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
			       int duty_ns, int period_ns)
{
	struct mtk_disp_pwm *mdp = to_mtk_disp_pwm(chip);
	u32 clk_div, period, high_width, value;
	u64 div, rate;
	int err;

	/*
	 * Find period, high_width and clk_div to suit duty_ns and period_ns.
	 * Calculate proper div value to keep period value in the bound.
	 *
	 * period_ns = 10^9 * (clk_div + 1) * (period + 1) / PWM_CLK_RATE
	 * duty_ns = 10^9 * (clk_div + 1) * high_width / PWM_CLK_RATE
	 *
	 * period = (PWM_CLK_RATE * period_ns) / (10^9 * (clk_div + 1)) - 1
	 * high_width = (PWM_CLK_RATE * duty_ns) / (10^9 * (clk_div + 1))
	 */
	rate = clk_get_rate(mdp->clk_main);
	clk_div = div_u64(rate * period_ns, NSEC_PER_SEC) >>
			  PWM_PERIOD_BIT_WIDTH;
	if (clk_div > PWM_CLKDIV_MAX)
		return -EINVAL;

	div = NSEC_PER_SEC * (clk_div + 1);
	period = div64_u64(rate * period_ns, div);
	if (period > 0)
		period--;

	high_width = div64_u64(rate * duty_ns, div);
	value = period | (high_width << PWM_HIGH_WIDTH_SHIFT);

	err = clk_enable(mdp->clk_main);
	if (err < 0)
		return err;

	err = clk_enable(mdp->clk_mm);
	if (err < 0) {
		clk_disable(mdp->clk_main);
		return err;
	}

	mtk_disp_pwm_update_bits(mdp, mdp->data->con0,
			PWM_CLKDIV_MASK, clk_div << PWM_CLKDIV_SHIFT);
	if (HW_VERSION_V2 == mdp->data->version)
		mtk_disp_pwm_update_bits(mdp, mdp->data->con0,
				PWM_MANUAL_SEL_MASK, mdp->data->con0_sel);
	mtk_disp_pwm_update_bits(mdp, mdp->data->con1,
			PWM_PERIOD_MASK | PWM_HIGH_WIDTH_MASK, value);
	if (HW_VERSION_V1 == mdp->data->version) {
		mtk_disp_pwm_update_bits(mdp, DISP_PWM_COMMIT, PWM_COMMIT_MASK, 1);
		mtk_disp_pwm_update_bits(mdp, DISP_PWM_COMMIT, PWM_COMMIT_MASK, 0);
	}


	clk_disable(mdp->clk_mm);
	clk_disable(mdp->clk_main);

	return 0;
}

static int mtk_disp_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct mtk_disp_pwm *mdp = to_mtk_disp_pwm(chip);
	int err;

	err = clk_enable(mdp->clk_main);
	if (err < 0)
		return err;

	err = clk_enable(mdp->clk_mm);
	if (err < 0) {
		clk_disable(mdp->clk_main);
		return err;
	}

	mtk_disp_pwm_update_bits(mdp, DISP_PWM_EN,
			mdp->data->enable_mask, mdp->data->enable_value);

	return 0;
}

static void mtk_disp_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct mtk_disp_pwm *mdp = to_mtk_disp_pwm(chip);

	mtk_disp_pwm_update_bits(mdp, DISP_PWM_EN,
			mdp->data->enable_mask, 0);

	clk_disable(mdp->clk_mm);
	clk_disable(mdp->clk_main);
}

static const struct pwm_ops mtk_disp_pwm_ops = {
	.config = mtk_disp_pwm_config,
	.enable = mtk_disp_pwm_enable,
	.disable = mtk_disp_pwm_disable,
	.owner = THIS_MODULE,
};

static const struct mtk_pwm_data mt8173_pwm_data = {
	.enable_mask = BIT(0),
	.enable_value = 0x1,
	.con0 = 0x10,
	.con0_sel = 0x0,
	.con1 = 0x14,
	.version = HW_VERSION_V1,
};

static const struct mtk_pwm_data mt2701_pwm_data = {
	.enable_mask = BIT(16),
	.enable_value = 0x10000,
	.con0 = 0xa8,
	.con0_sel = 0x2,
	.con1 = 0xac,
	.version = HW_VERSION_V2,
};

static const struct of_device_id mtk_disp_pwm_of_match[] = {
	{ .compatible = "mediatek,mt8173-disp-pwm", .data = &mt8173_pwm_data},
	{ .compatible = "mediatek,mt6595-disp-pwm", .data = &mt8173_pwm_data},
	{ .compatible = "mediatek,mt2701-disp-bls", .data = &mt2701_pwm_data},
	{ }
};
MODULE_DEVICE_TABLE(of, mtk_disp_pwm_of_match);

static int mtk_disp_pwm_probe(struct platform_device *pdev)
{
	const struct of_device_id *id;
	struct mtk_disp_pwm *mdp;
	struct resource *r;
	int ret;

	id = of_match_device(mtk_disp_pwm_of_match, &pdev->dev);
	if (!id)
		return -EINVAL;

	mdp = devm_kzalloc(&pdev->dev, sizeof(*mdp), GFP_KERNEL);
	if (!mdp)
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	mdp->base = devm_ioremap_resource(&pdev->dev, r);
	if (IS_ERR(mdp->base))
		return PTR_ERR(mdp->base);

	mdp->clk_main = devm_clk_get(&pdev->dev, "main");
	if (IS_ERR(mdp->clk_main))
		return PTR_ERR(mdp->clk_main);

	mdp->clk_mm = devm_clk_get(&pdev->dev, "mm");
	if (IS_ERR(mdp->clk_mm))
		return PTR_ERR(mdp->clk_mm);

	ret = clk_prepare(mdp->clk_main);
	if (ret < 0)
		return ret;

	ret = clk_prepare(mdp->clk_mm);
	if (ret < 0)
		goto disable_clk_main;

	mdp->chip.dev = &pdev->dev;
	mdp->chip.ops = &mtk_disp_pwm_ops;
	mdp->chip.base = -1;
	mdp->chip.npwm = 1;
	mdp->data = id->data;

	ret = pwmchip_add(&mdp->chip);
	if (ret < 0) {
		dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
		goto disable_clk_mm;
	}

	platform_set_drvdata(pdev, mdp);

	return 0;

disable_clk_mm:
	clk_unprepare(mdp->clk_mm);
disable_clk_main:
	clk_unprepare(mdp->clk_main);
	return ret;
}

static int mtk_disp_pwm_remove(struct platform_device *pdev)
{
	struct mtk_disp_pwm *mdp = platform_get_drvdata(pdev);
	int ret;

	ret = pwmchip_remove(&mdp->chip);
	clk_unprepare(mdp->clk_mm);
	clk_unprepare(mdp->clk_main);

	return ret;
}

static struct platform_driver mtk_disp_pwm_driver = {
	.driver = {
		.name = "mediatek-disp-pwm",
		.of_match_table = mtk_disp_pwm_of_match,
	},
	.probe = mtk_disp_pwm_probe,
	.remove = mtk_disp_pwm_remove,
};
module_platform_driver(mtk_disp_pwm_driver);

MODULE_AUTHOR("YH Huang <yh.huang@mediatek.com>");
MODULE_DESCRIPTION("MediaTek SoC display PWM driver");
MODULE_LICENSE("GPL v2");
