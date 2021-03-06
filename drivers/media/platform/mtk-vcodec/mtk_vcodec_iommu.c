
#include <linux/iommu.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>
#include <asm/dma-iommu.h>

#include "mtk_vcodec_iommu.h"
#include "mtk_vcodec_pm.h"
#include "mtk_vcodec_util.h"

int mtk_vcodec_iommu_init(struct device *dev)
{
	struct device_node *np;
	struct platform_device *pdev;
	int err;

	np = of_parse_phandle(dev->of_node, "iommus", 0);
	if (!np) {
		pr_debug("can't find iommus node\n");
		return 0;
	}

	pdev = of_find_device_by_node(np);
	if (!pdev) {
		of_node_put(np);
		pr_debug("can't find iommu device by node\n");
		return -1;
	}

	mtk_v4l2_debug(2, "%s() %s\n", __func__, dev_name(&pdev->dev));

	err = arm_iommu_attach_device(dev, pdev->dev.archdata.iommu);

	if (err) {
		of_node_put(np);
		mtk_v4l2_err("iommu_dma_attach_device fail %d\n", err);
		return -1;
	}

	return 0;
}

void mtk_vcodec_iommu_deinit(struct device *dev)
{
	arm_iommu_detach_device(dev);
}
