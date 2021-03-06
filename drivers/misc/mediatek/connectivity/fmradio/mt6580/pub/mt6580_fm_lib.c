#include <linux/slab.h>
#include <linux/vmalloc.h>

#include "osal_typedef.h"
#include "stp_exp.h"
#include "wmt_exp.h"

#include "fm_typedef.h"
#include "fm_dbg.h"
#include "fm_err.h"
#include "fm_interface.h"
#include "fm_stdlib.h"
#include "fm_patch.h"
#include "fm_utils.h"
#include "fm_link.h"
#include "fm_config.h"
#include "fm_cmd.h"

#include "mt6580_fm_reg.h"
#include "mt6580_fm_lib.h"

/* #include "mach/mt_gpio.h" */

static struct fm_patch_tbl mt6580_patch_tbl[5] = {
	{FM_ROM_V1, "mt6580_fm_v1_patch.bin", "mt6580_fm_v1_coeff.bin", NULL, NULL},
	{FM_ROM_V2, "mt6580_fm_v2_patch.bin", "mt6580_fm_v2_coeff.bin", NULL, NULL},
	{FM_ROM_V3, "mt6580_fm_v3_patch.bin", "mt6580_fm_v3_coeff.bin", NULL, NULL},
	{FM_ROM_V4, "mt6580_fm_v4_patch.bin", "mt6580_fm_v4_coeff.bin", NULL, NULL},
	{FM_ROM_V5, "mt6580_fm_v5_patch.bin", "mt6580_fm_v5_coeff.bin", NULL, NULL}
};

static struct fm_hw_info mt6580_hw_info = {
	.chip_id = 0x00006580,
	.eco_ver = 0x00000000,
	.rom_ver = 0x00000000,
	.patch_ver = 0x00000000,
	.reserve = 0x00000000,
};

fm_u8 *cmd_buf;
struct fm_lock *cmd_buf_lock;
struct fm_res_ctx *fm_res;
static struct fm_callback *fm_cb_op;
/* static fm_s32 Chip_Version = mt6580_E1; */

/* static fm_bool rssi_th_set = fm_false; */

#if 0				/* def CONFIG_MTK_FM_50KHZ_SUPPORT */
static struct fm_fifo *cqi_fifo;
#endif
static fm_s32 mt6580_is_dese_chan(fm_u16 freq);

#if 0
static fm_s32 mt6580_mcu_dese(fm_u16 freq, void *arg);
static fm_s32 mt6580_gps_dese(fm_u16 freq, void *arg);
static fm_s32 mt6580_I2s_Setting(fm_s32 onoff, fm_s32 mode, fm_s32 sample);
#endif
static fm_u16 mt6580_chan_para_get(fm_u16 freq);
static fm_s32 mt6580_desense_check(fm_u16 freq, fm_s32 rssi);
/*static fm_bool mt6580_TDD_chan_check(fm_u16 freq);*/
static fm_s32 mt6580_soft_mute_tune(fm_u16 freq, fm_s32 *rssi, fm_bool *valid);

static fm_s32 mt6580_pwron(fm_s32 data)
{
	if (MTK_WCN_BOOL_FALSE == mtk_wcn_wmt_func_on(WMTDRV_TYPE_FM)) {
		WCN_DBG(FM_ERR | CHIP, "WMT turn on FM Fail!\n");
		return -FM_ELINK;
	}

	WCN_DBG(FM_NTC | CHIP, "WMT turn on FM OK!\n");
	return 0;
}

static fm_s32 mt6580_pwroff(fm_s32 data)
{
	if (MTK_WCN_BOOL_FALSE == mtk_wcn_wmt_func_off(WMTDRV_TYPE_FM)) {
		WCN_DBG(FM_ERR | CHIP, "WMT turn off FM Fail!\n");
		return -FM_ELINK;
	}

	WCN_DBG(FM_NTC | CHIP, "WMT turn off FM OK!\n");
	return 0;
}

static fm_u16 mt6580_get_chipid(void)
{
	return 0x6580;
}

static fm_s32 mt6580_SetAntennaType(fm_s32 type)
{
	fm_u16 dataRead;

	WCN_DBG(FM_DBG | CHIP, "set ana to %s\n", type ? "short" : "long");
	fm_reg_read(FM_MAIN_CG2_CTRL, &dataRead);

	if (type)
		dataRead |= ANTENNA_TYPE;
	else
		dataRead &= (~ANTENNA_TYPE);

	fm_reg_write(FM_MAIN_CG2_CTRL, dataRead);

	return 0;
}

static fm_s32 mt6580_GetAntennaType(void)
{
	fm_u16 dataRead;

	fm_reg_read(FM_MAIN_CG2_CTRL, &dataRead);
	WCN_DBG(FM_DBG | CHIP, "get ana type: %s\n", (dataRead & ANTENNA_TYPE) ? "short" : "long");

	if (dataRead & ANTENNA_TYPE)
		return FM_ANA_SHORT;	/* short antenna */
	else
		return FM_ANA_LONG;	/* long antenna */
}

static fm_s32 mt6580_Mute(fm_bool mute)
{
	fm_s32 ret = 0;
	fm_u16 dataRead;

	WCN_DBG(FM_DBG | CHIP, "set %s\n", mute ? "mute" : "unmute");
	/* fm_reg_read(FM_MAIN_CTRL, &dataRead); */
	fm_reg_read(0x9C, &dataRead);

	/* fm_top_reg_write(0x0050,0x00000007); */

	if (mute == 1)
		ret = fm_reg_write(0x9C, (dataRead & 0xFFFC) | 0x0003);
	else
		ret = fm_reg_write(0x9C, (dataRead & 0xFFFC));

	/* fm_top_reg_write(0x0050,0x0000000F); */

	return ret;
}


static fm_s32 mt6580_rampdown_reg_op(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 4;

	if (NULL == buf) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid pointer\n", __func__);
		return -1;
	}
	if (buf_size < TX_BUF_SIZE) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid buf size(%d)\n", __func__, buf_size);
		return -2;
	}

	/* Clear DSP state */
	pkt_size += fm_bop_modify(FM_MAIN_CTRL, 0xFFF0, 0x0000, &buf[pkt_size], buf_size - pkt_size);
	/* Set DSP ramp down state */
	pkt_size += fm_bop_modify(FM_MAIN_CTRL, 0xFFFF, RAMP_DOWN, &buf[pkt_size], buf_size - pkt_size);
	/* @Wait for STC_DONE interrupt@ */
	pkt_size += fm_bop_rd_until(FM_MAIN_INTR, FM_INTR_STC_DONE, FM_INTR_STC_DONE, &buf[pkt_size],
				    buf_size - pkt_size);
	/* Clear DSP ramp down state */
	pkt_size += fm_bop_modify(FM_MAIN_CTRL, (~RAMP_DOWN), 0x0000, &buf[pkt_size], buf_size - pkt_size);
	/* Write 1 clear the STC_DONE interrupt status flag */
	pkt_size += fm_bop_modify(FM_MAIN_INTR, 0xFFFF, FM_INTR_STC_DONE, &buf[pkt_size], buf_size - pkt_size);

	return pkt_size - 4;
}
static fm_s32 mt6580_rampdown(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 0;

	pkt_size = mt6580_rampdown_reg_op(buf, buf_size);
	return fm_op_seq_combine_cmd(buf, FM_RAMPDOWN_OPCODE, pkt_size);
}

static fm_s32 mt6580_RampDown(void)
{
	fm_s32 ret = 0;
	fm_u16 pkt_size;

	WCN_DBG(FM_DBG | CHIP, "ramp down\n");
	ret = fm_reg_write(0x60, 0x00000007);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "ramp down wr 0x60 failed\n");
		return ret;
	}
	ret = fm_reg_write(0x60, 0x0000000f);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "ramp down wr 0x60 failed\n");
		return ret;
	}

	if (FM_LOCK(cmd_buf_lock))
		return -FM_ELOCK;
	pkt_size = mt6580_rampdown(cmd_buf, TX_BUF_SIZE);
	ret = fm_cmd_tx(cmd_buf, pkt_size, FLAG_RAMPDOWN, SW_RETRY_CNT, RAMPDOWN_TIMEOUT, NULL);
	FM_UNLOCK(cmd_buf_lock);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "ramp down failed\n");
		return ret;
	}

	return ret;
}

static fm_s32 mt6580_get_rom_version(void)
{
	fm_u16 tmp;
	fm_s32 ret;

	fm_reg_write(0x90, 0xe);
	fm_reg_write(0x92, 0x0);
	fm_reg_write(0x90, 0x40);
	fm_reg_write(0x90, 0x0);

	/* DSP rom code version request enable --- set 0x61 b15=1 */
	fm_set_bits(0x61, 0x8000, 0x7FFF);

	/* Release ASIP reset --- set 0x61 b1=1 */
	fm_set_bits(0x61, 0x0002, 0xFFFD);

	/* Enable ASIP power --- set 0x61 b0=0 */
	fm_set_bits(0x61, 0x0000, 0xFFFE);

	/* Wait DSP code version ready --- wait 1ms */
	do {
		fm_delayus(1000);
		ret = fm_reg_read(0x84, &tmp);
		/* ret=-4 means signal got when control FM. usually get sig 9 to kill FM process. */
		/* now cancel FM power up sequence is recommended. */
		if (ret)
			return ret;

		WCN_DBG(FM_NTC | CHIP, "0x84=%x\n", tmp);
	} while (tmp != 0x0001);

	/* Get FM DSP code version --- rd 0x83[15:8] */
	fm_reg_read(0x83, &tmp);
	tmp = (tmp >> 8);

	/* DSP rom code version request disable --- set 0x61 b15=0 */
	fm_set_bits(0x61, 0x0000, 0x7FFF);

	/* Reset ASIP --- set 0x61[1:0] = 1 */
	fm_set_bits(0x61, 0x0001, 0xFFFC);

	/* WCN_DBG(FM_NTC | CHIP, "ROM version: v%d\n", (fm_s32)tmp); */
	return (fm_s32) tmp;
}

static fm_s32 mt6580_enable_pmic_tldo(void)
{
	fm_s32 ret = 0;
	fm_u32 hostreg = 0;

	/* set 26M clock mannual on */
	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg | (0x1 << 0));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg | (0x1 << 6));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg | (0x1 << 16));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg | (0x1 << 22));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	/* set RX_DET_OUT Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg | (0x1 << 16));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set ADC_QD Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg | (0x1 << 15));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set ADC_ID Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg | (0x1 << 14));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set ADC_CK Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg | (0x1 << 7));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set DIG_CK Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg | (0x1 << 6));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	return ret;
}

static fm_s32 mt6580_disable_pmic_tldo(void)
{
	fm_s32 ret = 0;
	fm_u32 hostreg = 0;

	/* set 26M clock mannual on */
	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg & (~(0x1 << 22)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg & (~(0x1 << 16)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg & (~(0x1 << 6)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	ret = fm_host_reg_read(MCUPLL_CON1, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd MCUPLL_CON1 failed\n");
		return ret;
	}
	ret = fm_host_reg_write(MCUPLL_CON1, hostreg & (~(0x1 << 0)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr MCUPLL_CON1 failed\n");
		return ret;
	}

	/* set RX_DET_OUT Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg & (~(0x1 << 16)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set ADC_QD Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg & (~(0x1 << 15)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set ADC_ID Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg & (~(0x1 << 14)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set ADC_CK Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg & (~(0x1 << 7)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	/* set DIG_CK Gating off */
	ret = fm_host_reg_read(CONN_RF_CG, &hostreg);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup rd CONN_RF_CG failed\n");
		return ret;
	}
	ret = fm_host_reg_write(CONN_RF_CG, hostreg & (~(0x1 << 6)));
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " pwrup wr CONN_RF_CG failed\n");
		return ret;
	}

	return ret;
}

static fm_s32 mt6580_pwrup_clock_on_reg_op(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 4;
	fm_u16 de_emphasis;
	/* fm_u16 osc_freq; */

	if (NULL == buf) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid pointer\n", __func__);
		return -1;
	}
	if (buf_size < TX_BUF_SIZE) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid buf size(%d)\n", __func__, buf_size);
		return -2;
	}

	de_emphasis = fm_config.rx_cfg.deemphasis;	/* fm_cust_config_fetch(FM_CFG_RX_DEEMPHASIS); */
	de_emphasis &= 0x0001;	/* rang 0~1 */

	/* turn on top clock */
	pkt_size += fm_bop_top_write(0xA10, 0xFFFFFFFF, &buf[pkt_size], buf_size - pkt_size);	/* wr a10 ffffffff */
	/* enable MTCMOS */
	pkt_size += fm_bop_top_write(0x60, 0x00000030, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 30 */
	pkt_size += fm_bop_top_write(0x60, 0x00000005, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 5 */
	pkt_size += fm_bop_udelay(10, &buf[pkt_size], buf_size - pkt_size);	/* delay 10us */
	pkt_size += fm_bop_top_write(0x60, 0x00000045, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 45 */

	/* enable digital OSC */
	pkt_size += fm_bop_write(0x60, 0x00000001, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 1 */
	/* set OSC clock output to fm */
	pkt_size += fm_bop_write(0x60, 0x00000003, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 3 */
	/* release HW clock gating */
	pkt_size += fm_bop_write(0x60, 0x00000007, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 7 */
	/* enable DSP auto clock gating */
	pkt_size += fm_bop_write(0x70, 0x0040, &buf[pkt_size], buf_size - pkt_size);	/* wr 70 0040 */
	/* deemphasis setting */
	pkt_size += fm_bop_modify(0x61, ~DE_EMPHASIS, (de_emphasis << 12), &buf[pkt_size], buf_size - pkt_size);

	return pkt_size - 4;
}
static fm_s32 mt6580_pwrup_clock_on(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 0;

	pkt_size = mt6580_pwrup_clock_on_reg_op(buf, buf_size);
	return fm_op_seq_combine_cmd(buf, FM_ENABLE_OPCODE, pkt_size);
}

static fm_s32 mt6580_pwrup_digital_init_reg_op(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 4;

	if (NULL == buf) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid pointer\n", __func__);
		return -1;
	}
	if (buf_size < TX_BUF_SIZE) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid buf size(%d)\n", __func__, buf_size);
		return -2;
	}

	/* FM Digital Init: fm_rgf_maincon */
	pkt_size += fm_bop_write(0x6A, 0x0021, &buf[pkt_size], buf_size - pkt_size);
	/* wr 6A 0021, set 1 to enable interrupt  */
	pkt_size += fm_bop_write(0x6B, 0x0021, &buf[pkt_size], buf_size - pkt_size);	/* wr 6B 0021 */
	pkt_size += fm_bop_write(0x60, 0x0000000F, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 f */
	pkt_size += fm_bop_modify(0x61, 0xFFFD, 0x0002, &buf[pkt_size], buf_size - pkt_size);	/* wr 61 D1=1 */
	pkt_size += fm_bop_modify(0x61, 0xFFFE, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 61 D0=0 */
	pkt_size += fm_bop_udelay(100000, &buf[pkt_size], buf_size - pkt_size);	/* delay 100ms */
	pkt_size += fm_bop_rd_until(0x64, 0x001F, 0x0002, &buf[pkt_size], buf_size - pkt_size);	/* Poll 64[0~4] = 2 */
	pkt_size += fm_bop_write(0x60, 0x00000007, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 7 */
	pkt_size += fm_bop_write(0x2d, 0x000001fa, &buf[pkt_size], buf_size - pkt_size);	/* wr 2d 1fa */
	pkt_size += fm_bop_write(0x60, 0x0000000F, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 f */

	return pkt_size - 4;
}

static fm_s32 mt6580_pwrup_digital_init(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 0;

	pkt_size = mt6580_pwrup_digital_init_reg_op(buf, buf_size);
	return fm_op_seq_combine_cmd(buf, FM_ENABLE_OPCODE, pkt_size);
}

static fm_s32 mt6580_pwrdown_reg_op(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 4;

	if (NULL == buf) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid pointer\n", __func__);
		return -1;
	}
	if (buf_size < TX_BUF_SIZE) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid buf size(%d)\n", __func__, buf_size);
		return -2;
	}

	/* A1:set audio output I2S Tx mode: */
	pkt_size += fm_bop_modify(0x9B, 0xFFF8, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 9B[0~2] 0 */

	/* B0:Disable HW clock control */
	pkt_size += fm_bop_write(0x60, 0x330F, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 330F */
	/* B1:Reset ASIP */
	pkt_size += fm_bop_write(0x61, 0x0001, &buf[pkt_size], buf_size - pkt_size);	/* wr 61 0001 */
	/* B2:digital core + digital rgf reset */
	pkt_size += fm_bop_modify(0x6E, 0xFFF8, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 6E[0~2] 0 */
	pkt_size += fm_bop_modify(0x6E, 0xFFF8, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 6E[0~2] 0 */
	pkt_size += fm_bop_modify(0x6E, 0xFFF8, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 6E[0~2] 0 */
	pkt_size += fm_bop_modify(0x6E, 0xFFF8, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 6E[0~2] 0 */
	/* B3:Disable all clock */
	pkt_size += fm_bop_write(0x60, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 0000 */
	/* B4:Reset rgfrf */
	pkt_size += fm_bop_write(0x60, 0x4000, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 4000 */
	pkt_size += fm_bop_write(0x60, 0x0000, &buf[pkt_size], buf_size - pkt_size);	/* wr 60 0000 */
	/* MTCMOS power off */
	/* C0:disable MTCMOS */
	pkt_size += fm_bop_top_write(0x60, 0x0005, &buf[pkt_size], buf_size - pkt_size);	/* wr top60 0005 */
	pkt_size += fm_bop_top_write(0x60, 0x0015, &buf[pkt_size], buf_size - pkt_size);	/* wr top60 0015 */

	return pkt_size - 4;
}
static fm_s32 mt6580_pwrdown(fm_u8 *buf, fm_s32 buf_size)
{
	fm_s32 pkt_size = 0;

	pkt_size = mt6580_pwrdown_reg_op(buf, buf_size);
	return fm_op_seq_combine_cmd(buf, FM_ENABLE_OPCODE, pkt_size);
}

static fm_s32 mt6580_tune_reg_op(fm_u8 *buf, fm_s32 buf_size, fm_u16 freq, fm_u16 chan_para)
{
	fm_s32 pkt_size = 4;

	WCN_DBG(FM_ALT | CHIP, "%s enter mt6580_tune function\n", __func__);

	if (NULL == buf) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid pointer\n", __func__);
		return -1;
	}
	if (buf_size < TX_BUF_SIZE) {
		WCN_DBG(FM_ERR | CHIP, "%s invalid buf size(%d)\n", __func__, buf_size);
		return -2;
	}

	/* Set desired channel & channel parameter */
#ifdef FM_TUNE_USE_POLL
	pkt_size += fm_bop_write(0x6A, 0x0000, &buf[pkt_size], buf_size - pkt_size);
	pkt_size += fm_bop_write(0x6B, 0x0000, &buf[pkt_size], buf_size - pkt_size);
#endif
	/* Enable hardware controlled tuning sequence */
	pkt_size += fm_bop_modify(FM_MAIN_CTRL, 0xFFF8, TUNE, &buf[pkt_size], buf_size - pkt_size);
	/* Wait for STC_DONE interrupt */
#ifdef FM_TUNE_USE_POLL
	pkt_size += fm_bop_rd_until(FM_MAIN_INTR, FM_INTR_STC_DONE, FM_INTR_STC_DONE, &buf[pkt_size],
				    buf_size - pkt_size);
	/* Write 1 clear the STC_DONE interrupt status flag */
	pkt_size += fm_bop_modify(FM_MAIN_INTR, 0xFFFF, FM_INTR_STC_DONE, &buf[pkt_size], buf_size - pkt_size);
#endif

	WCN_DBG(FM_ALT | CHIP, "%s leave mt6580_tune function\n", __func__);

	return pkt_size - 4;
}

static fm_s32 mt6580_tune(fm_u8 *buf, fm_s32 buf_size, fm_u16 freq, fm_u16 chan_para)
{
	fm_s32 pkt_size = 0;

	pkt_size = mt6580_tune_reg_op(buf, buf_size, freq, chan_para);
	return fm_op_seq_combine_cmd(buf, FM_TUNE_OPCODE, pkt_size);
}

static fm_s32 mt6580_pwrup_DSP_download(struct fm_patch_tbl *patch_tbl)
{
#define PATCH_BUF_SIZE (4096*6)
	fm_s32 ret = 0;
	fm_s32 patch_len = 0;
	fm_u8 *dsp_buf = NULL;
	fm_u16 tmp_reg = 0;

	mt6580_hw_info.eco_ver = (fm_s32) mtk_wcn_wmt_hwver_get();
	WCN_DBG(FM_NTC | CHIP, "ECO version:0x%08x\n", mt6580_hw_info.eco_ver);
	mt6580_hw_info.eco_ver += 1;

	/* get mt6580 DSP rom version */
	ret = mt6580_get_rom_version();
	if (ret >= 0) {
		mt6580_hw_info.rom_ver = ret;
		WCN_DBG(FM_NTC | CHIP, "ROM version: v%d\n", mt6580_hw_info.rom_ver);
	} else {
		WCN_DBG(FM_ERR | CHIP, "get ROM version failed\n");
		/* ret=-4 means signal got when control FM. usually get sig 9 to kill FM process. */
		/* now cancel FM power up sequence is recommended. */
		goto out;
	}

	dsp_buf = fm_vmalloc(PATCH_BUF_SIZE);
	if (!dsp_buf) {
		WCN_DBG(FM_ALT | CHIP, "-ENOMEM\n");
		return -ENOMEM;
	}

	patch_len = fm_get_patch_path(mt6580_hw_info.rom_ver, dsp_buf, PATCH_BUF_SIZE, patch_tbl);
	if (patch_len <= 0) {
		WCN_DBG(FM_ALT | CHIP, " fm_get_patch_path failed\n");
		ret = patch_len;
		goto out;
	}

	ret = fm_download_patch((const fm_u8 *)dsp_buf, patch_len, IMG_PATCH);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " DL DSPpatch failed\n");
		goto out;
	}

	patch_len = fm_get_coeff_path(mt6580_hw_info.rom_ver, dsp_buf, PATCH_BUF_SIZE, patch_tbl);
	if (patch_len <= 0) {
		WCN_DBG(FM_ALT | CHIP, " fm_get_coeff_path failed\n");
		ret = patch_len;
		goto out;
	}

	mt6580_hw_info.rom_ver += 1;

	tmp_reg = dsp_buf[38] | (dsp_buf[39] << 8);	/* to be confirmed */
	mt6580_hw_info.patch_ver = (fm_s32) tmp_reg;
	WCN_DBG(FM_NTC | CHIP, "Patch version: 0x%08x\n", mt6580_hw_info.patch_ver);

	if (ret == 1) {
		dsp_buf[4] = 0x00;	/* if we found rom version undefined, we should disable patch */
		dsp_buf[5] = 0x00;
	}

	ret = fm_download_patch((const fm_u8 *)dsp_buf, patch_len, IMG_COEFFICIENT);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, " DL DSPcoeff failed\n");
		goto out;
	}
	fm_reg_write(0x92, 0x0000);
	fm_reg_write(0x90, 0x0040);
	fm_reg_write(0x90, 0x0000);
out:
	if (dsp_buf) {
		fm_vfree(dsp_buf);
		dsp_buf = NULL;
	}
	return ret;
}


static fm_s32 mt6580_PowerUp(fm_u16 *chip_id, fm_u16 *device_id)
{
	fm_s32 ret = 0;
	fm_u16 pkt_size;
	fm_u16 tmp_reg = 0;

	if (chip_id == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	if (device_id == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}

	WCN_DBG(FM_DBG | CHIP, "pwr on seq......\n");

	mt6580_enable_pmic_tldo();

	if (FM_LOCK(cmd_buf_lock))
		return -FM_ELOCK;
	pkt_size = mt6580_pwrup_clock_on(cmd_buf, TX_BUF_SIZE);
	ret = fm_cmd_tx(cmd_buf, pkt_size, FLAG_EN, SW_RETRY_CNT, EN_TIMEOUT, NULL);
	FM_UNLOCK(cmd_buf_lock);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, "mt6580_pwrup_clock_on failed\n");
		return ret;
	}

	fm_reg_read(0x62, &tmp_reg);
	*chip_id = tmp_reg;
	*device_id = tmp_reg;
	mt6580_hw_info.chip_id = (fm_s32) tmp_reg;
	WCN_DBG(FM_NTC | CHIP, "chip_id:0x%04x\n", tmp_reg);

	if (mt6580_hw_info.chip_id != 0x6580) {
		WCN_DBG(FM_NTC | CHIP, "fm sys error, reset hw\n");
		return -FM_EFW;
	}

	ret = mt6580_pwrup_DSP_download(mt6580_patch_tbl);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "mt6580_pwrup_DSP_download failed\n");
		return ret;
	}

	if (FM_LOCK(cmd_buf_lock))
		return -FM_ELOCK;
	pkt_size = mt6580_pwrup_digital_init(cmd_buf, TX_BUF_SIZE);
	ret = fm_cmd_tx(cmd_buf, pkt_size, FLAG_EN, SW_RETRY_CNT, EN_TIMEOUT, NULL);
	FM_UNLOCK(cmd_buf_lock);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, "mt6580_pwrup_digital_init failed\n");
		return ret;
	}

	/* set audio output I2S TX mode  */
	fm_reg_write(0x9B, 0x3);

	WCN_DBG(FM_NTC | CHIP, "pwr on seq ok\n");

	return ret;
}

static fm_s32 mt6580_PowerDown(void)
{
	fm_s32 ret = 0;
	fm_u16 pkt_size;
	fm_u16 dataRead;

	WCN_DBG(FM_DBG | CHIP, "pwr down seq\n");

	/*SW work around for MCUFA issue.
	 *if interrupt happen before doing rampdown, DSP can't switch MCUFA back well.
	 * In case read interrupt, and clean if interrupt found before rampdown.
	 */
	fm_reg_read(FM_MAIN_INTR, &dataRead);

	if (dataRead & 0x1) {
		ret = fm_reg_write(FM_MAIN_INTR, dataRead);	/* clear status flag */
		if (ret)
			WCN_DBG(FM_ALT | CHIP, "mt6580_pwrdown wr FM_MAIN_INTR failed\n");
	}
	/* mt6580_RampDown(); */

	/* set audio output I2X Rx mode: */
	if (FM_LOCK(cmd_buf_lock))
		return -FM_ELOCK;
	pkt_size = mt6580_pwrdown(cmd_buf, TX_BUF_SIZE);
	ret = fm_cmd_tx(cmd_buf, pkt_size, FLAG_EN, SW_RETRY_CNT, EN_TIMEOUT, NULL);
	FM_UNLOCK(cmd_buf_lock);
	if (ret) {
		WCN_DBG(FM_ALT | CHIP, "mt6580_pwrdown failed\n");
		return ret;
	}

	mt6580_disable_pmic_tldo();

	return ret;
}

static fm_bool mt6580_SetFreq(fm_u16 freq)
{
	fm_s32 ret = 0;
	fm_u16 pkt_size;
	fm_u16 chan_para = 0;
	fm_u16 freq_reg = 0;

	fm_cb_op->cur_freq_set(freq);

	chan_para = mt6580_chan_para_get(freq);
	WCN_DBG(FM_DBG | CHIP, "%d chan para = %d\n", (fm_s32) freq, (fm_s32) chan_para);
	freq_reg = freq;
	if (0 == fm_get_channel_space(freq_reg))
		freq_reg *= 10;
	WCN_DBG(FM_DBG | CHIP, "freq_reg = %d\n", freq_reg);
	ret = fm_reg_write(0x60, 0x00000007);
	if (ret)
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x60 failed\n");
	/* add this paragragh to resolve Rainier FM sensitivity bad in low band issue */
#if 0
	if (mt6580_TDD_chan_check(freq)) {
		ret = fm_set_bits(0x39, 0x0008, 0xFFF3);	/* use TDD solution */
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x30 failed\n");
	} else {
		ret = fm_set_bits(0x39, 0x0000, 0xFFF3);	/* default use FDD solution */
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x30 failed\n");
	}
#endif
	if ((6500 <= freq_reg) && (freq_reg <= 7290)) {
		ret = fm_reg_write(0x39, 0xd002);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((7295 <= freq_reg) && (freq_reg <= 8410)) {
		ret = fm_reg_write(0x39, 0xce02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((8415 <= freq_reg) && (freq_reg <= 9815)) {
		ret = fm_reg_write(0x39, 0xcc02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((9820 <= freq_reg) && (freq_reg <= 9830)) {
		ret = fm_reg_write(0x39, 0xca02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((9835 <= freq_reg) && (freq_reg <= 9940)) {
		ret = fm_reg_write(0x39, 0xcc02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((9845 <= freq_reg) && (freq_reg <= 10800)) {
		ret = fm_reg_write(0x39, 0xca02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else {
		ret = fm_reg_write(0x39, 0xca02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	}

	/* end */
	ret = fm_reg_write(0x6a, 0x00000021);
	if (ret)
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x6a failed\n");

	ret = fm_reg_write(0x6b, 0x00000021);
	if (ret)
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x6b failed\n");

	ret = fm_reg_write(0x60, 0x0000000F);
	if (ret)
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x60 failed\n");


	freq_reg = (freq_reg - 6400) * 2 / 10;
	ret = fm_set_bits(0x65, freq_reg, 0xFC00);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x65 failed\n");
		return fm_false;
	}
	ret = fm_set_bits(0x65, (chan_para << 12), 0x0FFF);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x65 failed\n");
		return fm_false;
	}

	if (FM_LOCK(cmd_buf_lock))
		return fm_false;
	pkt_size = mt6580_tune(cmd_buf, TX_BUF_SIZE, freq, chan_para);
	ret = fm_cmd_tx(cmd_buf, pkt_size, FLAG_TUNE | FLAG_TUNE_DONE, SW_RETRY_CNT, TUNE_TIMEOUT, NULL);
	FM_UNLOCK(cmd_buf_lock);

	if (ret) {
		WCN_DBG(FM_ALT | CHIP, "mt6580_tune failed\n");
		return fm_false;
	}

	WCN_DBG(FM_DBG | CHIP, "set freq to %d ok\n", freq);

	return fm_true;
}

#define FM_CQI_LOG_PATH "/mnt/sdcard/fmcqilog"

static fm_s32 mt6580_full_cqi_get(fm_s32 min_freq, fm_s32 max_freq, fm_s32 space, fm_s32 cnt)
{
	fm_s32 ret = 0;
	fm_u16 pkt_size;
	fm_u16 freq, orig_freq;
	fm_s32 i, j, k;
	fm_s32 space_val, max, min, num;
	struct mt6580_full_cqi *p_cqi;
	fm_u8 *cqi_log_title = "Freq, RSSI, PAMD, PR, FPAMD, MR, ATDC, PRX, ATDEV, SMGain, DltaRSSI\n";
	fm_u8 cqi_log_buf[100] = { 0 };
	fm_s32 pos;
	fm_u8 cqi_log_path[100] = { 0 };

	WCN_DBG(FM_DBG | CHIP, "6580 cqi log start\n");
	/* for soft-mute tune, and get cqi */
	freq = fm_cb_op->cur_freq_get();
	if (0 == fm_get_channel_space(freq))
		freq *= 10;

	/* get cqi */
	orig_freq = freq;
	if (0 == fm_get_channel_space(min_freq))
		min = min_freq * 10;
	else
		min = min_freq;

	if (0 == fm_get_channel_space(max_freq))
		max = max_freq * 10;
	else
		max = max_freq;

	if (space == 0x0001)
		space_val = 5;	/* 50Khz */
	else if (space == 0x0002)
		space_val = 10;	/* 100Khz */
	else if (space == 0x0004)
		space_val = 20;	/* 200Khz */
	else
		space_val = 10;

	num = (max - min) / space_val + 1;	/* Eg, (8760 - 8750) / 10 + 1 = 2 */
	for (k = 0; (10000 == orig_freq) && (0xffffffff == g_dbg_level) && (k < cnt); k++) {
		WCN_DBG(FM_NTC | CHIP, "cqi file:%d\n", k + 1);
		freq = min;
		pos = 0;
		fm_memcpy(cqi_log_path, FM_CQI_LOG_PATH, strlen(FM_CQI_LOG_PATH));
		sprintf(&cqi_log_path[strlen(FM_CQI_LOG_PATH)], "%d.txt", k + 1);
		fm_file_write(cqi_log_path, cqi_log_title, strlen(cqi_log_title), &pos);
		for (j = 0; j < num; j++) {
			if (FM_LOCK(cmd_buf_lock))
				return -FM_ELOCK;
			pkt_size = fm_full_cqi_req(cmd_buf, TX_BUF_SIZE, &freq, 1, 1);
			ret =
			    fm_cmd_tx(cmd_buf, pkt_size, FLAG_SM_TUNE, SW_RETRY_CNT,
				      SM_TUNE_TIMEOUT, fm_get_read_result);
			FM_UNLOCK(cmd_buf_lock);

			if (!ret && fm_res) {
				WCN_DBG(FM_NTC | CHIP, "smt cqi size %d\n", fm_res->cqi[0]);
				p_cqi = (struct mt6580_full_cqi *)&fm_res->cqi[2];
				for (i = 0; i < fm_res->cqi[1]; i++) {
					/* just for debug */
					WCN_DBG(FM_NTC | CHIP,
						"freq %d, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x\n",
						p_cqi[i].ch, p_cqi[i].rssi, p_cqi[i].pamd,
						p_cqi[i].pr, p_cqi[i].fpamd, p_cqi[i].mr,
						p_cqi[i].atdc, p_cqi[i].prx, p_cqi[i].atdev,
						p_cqi[i].smg, p_cqi[i].drssi);
					/* format to buffer */
					sprintf(cqi_log_buf,
						"%04d,%04x,%04x,%04x,%04x,%04x,%04x,%04x,%04x,%04x,%04x,\n",
						p_cqi[i].ch, p_cqi[i].rssi, p_cqi[i].pamd,
						p_cqi[i].pr, p_cqi[i].fpamd, p_cqi[i].mr,
						p_cqi[i].atdc, p_cqi[i].prx, p_cqi[i].atdev,
						p_cqi[i].smg, p_cqi[i].drssi);
					/* write back to log file */
					fm_file_write(cqi_log_path, cqi_log_buf, strlen(cqi_log_buf), &pos);
				}
			} else {
				WCN_DBG(FM_ALT | CHIP, "smt get CQI failed\n");
				ret = -1;
			}
			freq += space_val;
		}
		fm_cb_op->cur_freq_set(0);	/* avoid run too much times */
	}
	WCN_DBG(FM_DBG | CHIP, "6580 cqi log done\n");

	return ret;
}

static fm_s32 mt6580_GetCurRSSI(fm_s32 *pRSSI)
{
	fm_u16 tmp_reg;

	fm_reg_read(FM_RSSI_IND, &tmp_reg);
	tmp_reg = tmp_reg & 0x03ff;

	if (pRSSI) {
		*pRSSI = (tmp_reg > 511) ? (((tmp_reg - 1024) * 6) >> 4) : ((tmp_reg * 6) >> 4);
		WCN_DBG(FM_DBG | CHIP, "rssi:%d, dBm:%d\n", tmp_reg, *pRSSI);
	} else {
		WCN_DBG(FM_ERR | CHIP, "get rssi para error\n");
		return -FM_EPARA;
	}

	return 0;
}

static fm_u16 mt6580_vol_tbl[16] = { 0x0000, 0x0519, 0x066A, 0x0814,
	0x0A2B, 0x0CCD, 0x101D, 0x1449,
	0x198A, 0x2027, 0x287A, 0x32F5,
	0x4027, 0x50C3, 0x65AD, 0x7FFF
};

static fm_s32 mt6580_SetVol(fm_u8 vol)
{
	fm_s32 ret = 0;

	vol = (vol > 15) ? 15 : vol;
	ret = fm_reg_write(0x7D, mt6580_vol_tbl[vol]);
	if (ret) {
		WCN_DBG(FM_ERR | CHIP, "Set vol=%d Failed\n", vol);
		return ret;
	}

	WCN_DBG(FM_DBG | CHIP, "Set vol=%d OK\n", vol);

	if (vol == 10) {
		fm_print_cmd_fifo();	/* just for debug */
		fm_print_evt_fifo();
	}
	return 0;
}

static fm_s32 mt6580_GetVol(fm_u8 *pVol)
{
	int ret = 0;
	fm_u16 tmp;
	fm_s32 i;

	if (pVol == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}

	ret = fm_reg_read(0x7D, &tmp);
	if (ret) {
		*pVol = 0;
		WCN_DBG(FM_ERR | CHIP, "Get vol Failed\n");
		return ret;
	}

	for (i = 0; i < 16; i++) {
		if (mt6580_vol_tbl[i] == tmp) {
			*pVol = i;
			break;
		}
	}

	WCN_DBG(FM_DBG | CHIP, "Get vol=%d OK\n", *pVol);
	return 0;
}

static fm_s32 mt6580_dump_reg(void)
{
	fm_s32 i;
	fm_u16 TmpReg;

	for (i = 0; i < 0xff; i++) {
		fm_reg_read(i, &TmpReg);
		WCN_DBG(FM_NTC | CHIP, "0x%02x=0x%04x\n", i, TmpReg);
	}
	return 0;
}

/*0:mono, 1:stereo*/
static fm_bool mt6580_GetMonoStereo(fm_u16 *pMonoStereo)
{
#define FM_BF_STEREO 0x1000
	fm_u16 TmpReg;

	if (pMonoStereo) {
		fm_reg_read(FM_RSSI_IND, &TmpReg);
		*pMonoStereo = (TmpReg & FM_BF_STEREO) >> 12;
	} else {
		WCN_DBG(FM_ERR | CHIP, "MonoStero: para err\n");
		return fm_false;
	}

	WCN_DBG(FM_NTC | CHIP, "Get MonoStero:0x%04x\n", *pMonoStereo);
	return fm_true;
}

static fm_s32 mt6580_SetMonoStereo(fm_s32 MonoStereo)
{
	fm_s32 ret = 0;

	WCN_DBG(FM_NTC | CHIP, "set to %s\n", MonoStereo ? "mono" : "auto");
	fm_top_reg_write(0x50, 0x0007);

	if (MonoStereo) {	/*mono */
		ret = fm_set_bits(0x75, 0x0008, ~0x0008);
	} else {		/*auto switch */

		ret = fm_set_bits(0x75, 0x0000, ~0x0008);
	}

	fm_top_reg_write(0x50, 0x000F);
	return ret;
}

static fm_s32 mt6580_GetCapArray(fm_s32 *ca)
{
	fm_u16 dataRead;
	fm_u16 tmp = 0;

	if (ca == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	fm_reg_read(0x60, &tmp);
	fm_reg_write(0x60, tmp & 0xFFF7);	/* 0x60 D3=0 */

	fm_reg_read(0x26, &dataRead);
	*ca = dataRead;

	fm_reg_write(0x60, tmp);	/* 0x60 D3=1 */
	return 0;
}

static fm_bool mt6580_GetCurPamd(fm_u16 *pPamdLevl)
{
	fm_u16 tmp_reg;
	fm_u16 dBvalue, valid_cnt = 0;
	int i, total = 0;

	for (i = 0; i < 8; i++) {
		if (fm_reg_read(FM_ADDR_PAMD, &tmp_reg)) {
			*pPamdLevl = 0;
			return fm_false;
		}

		tmp_reg &= 0x03FF;
		dBvalue = (tmp_reg > 256) ? ((512 - tmp_reg) * 6 / 16) : 0;
		if (dBvalue != 0) {
			total += dBvalue;
			valid_cnt++;
			WCN_DBG(FM_DBG | CHIP, "[%d]PAMD=%d\n", i, dBvalue);
		}
		fm_delayms(3);
	}
	if (valid_cnt != 0)
		*pPamdLevl = total / valid_cnt;
	else
		*pPamdLevl = 0;

	WCN_DBG(FM_NTC | CHIP, "PAMD=%d\n", *pPamdLevl);
	return fm_true;
}

static fm_s32 mt6580_i2s_info_get(fm_s32 *ponoff, fm_s32 *pmode, fm_s32 *psample)
{
	if (ponoff == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	if (pmode == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	if (psample == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}

	*ponoff = fm_config.aud_cfg.i2s_info.status;
	*pmode = fm_config.aud_cfg.i2s_info.mode;
	*psample = fm_config.aud_cfg.i2s_info.rate;

	return 0;
}

static fm_s32 mt6580fm_get_audio_info(fm_audio_info_t *data)
{
	memcpy(data, &fm_config.aud_cfg, sizeof(fm_audio_info_t));
	return 0;
}

static fm_s32 mt6580_hw_info_get(struct fm_hw_info *req)
{
	if (req == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}

	req->chip_id = mt6580_hw_info.chip_id;
	req->eco_ver = mt6580_hw_info.eco_ver;
	req->patch_ver = mt6580_hw_info.patch_ver;
	req->rom_ver = mt6580_hw_info.rom_ver;

	return 0;
}

static fm_s32 mt6580_pre_search(void)
{
	mt6580_RampDown();
	/* disable audio output I2S Rx mode */
	fm_host_reg_write(0x80101054, 0x00000000);
	/* disable audio output I2S Tx mode */
	fm_reg_write(0x9B, 0x0000);

	return 0;
}

static fm_s32 mt6580_restore_search(void)
{
	mt6580_RampDown();
	/* set audio output I2S Tx mode */
	fm_reg_write(0x9B, 0xF9AB);
	/* set audio output I2S Rx mode */
	fm_host_reg_write(0x80101054, 0x00003f35);
	return 0;
}

static fm_s32 mt6580_soft_mute_tune(fm_u16 freq, fm_s32 *rssi, fm_bool *valid)
{
	fm_s32 ret = 0;
	fm_u16 pkt_size;
	struct mt6580_full_cqi *p_cqi;
	fm_s32 RSSI = 0, PAMD = 0, MR = 0, ATDC = 0;
	fm_u32 PRX = 0, ATDEV = 0;
	fm_u16 softmuteGainLvl = 0;
	fm_u16 freq_reg = 0;

	/* add this paragragh to resolve Rainier FM sensitivity bad in low band issue */
#if 0
	ret = mt6580_chan_para_get(freq);
	if (ret == 2)
		ret = fm_set_bits(FM_CHANNEL_SET, 0x2000, 0x0FFF);	/* mdf HiLo */
	else
		ret = fm_set_bits(FM_CHANNEL_SET, 0x0000, 0x0FFF);	/* clear FA/HL/ATJ */
#endif
	freq_reg = freq;
	if (0 == fm_get_channel_space(freq_reg))
		freq_reg *= 10;

	ret = fm_reg_write(0x60, 0x00000007);
	if (ret)
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x60 failed\n");

	if ((6500 <= freq_reg) && (freq_reg <= 7290)) {
		ret = fm_reg_write(0x39, 0xd002);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((7295 <= freq_reg) && (freq_reg <= 8410)) {
		ret = fm_reg_write(0x39, 0xce02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((8415 <= freq_reg) && (freq_reg <= 9815)) {
		ret = fm_reg_write(0x39, 0xcc02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((9820 <= freq_reg) && (freq_reg <= 9830)) {
		ret = fm_reg_write(0x39, 0xca02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((9835 <= freq_reg) && (freq_reg <= 9940)) {
		ret = fm_reg_write(0x39, 0xcc02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else if ((9845 <= freq_reg) && (freq_reg <= 10800)) {
		ret = fm_reg_write(0x39, 0xca02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	} else {
		ret = fm_reg_write(0x39, 0xca02);
		if (ret)
			WCN_DBG(FM_ERR | CHIP, "set freq wr 0x39 failed\n");
	}

	ret = fm_reg_write(0x60, 0x0000000f);
	if (ret)
		WCN_DBG(FM_ERR | CHIP, "set freq wr 0x60 failed\n");
	/* end */

	if (FM_LOCK(cmd_buf_lock))
		return -FM_ELOCK;
	pkt_size = fm_full_cqi_req(cmd_buf, TX_BUF_SIZE, &freq, 1, 1);
	ret = fm_cmd_tx(cmd_buf, pkt_size, FLAG_SM_TUNE, SW_RETRY_CNT, SM_TUNE_TIMEOUT, fm_get_read_result);
	FM_UNLOCK(cmd_buf_lock);

	if (!ret && fm_res) {
		WCN_DBG(FM_NTC | CHIP, "smt cqi size %d\n", fm_res->cqi[0]);
		p_cqi = (struct mt6580_full_cqi *)&fm_res->cqi[2];
		/* just for debug */
		WCN_DBG(FM_NTC | CHIP,
			"freq %d, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x\n",
			p_cqi->ch, p_cqi->rssi, p_cqi->pamd, p_cqi->pr, p_cqi->fpamd, p_cqi->mr,
			p_cqi->atdc, p_cqi->prx, p_cqi->atdev, p_cqi->smg, p_cqi->drssi);
		RSSI = ((p_cqi->rssi & 0x03FF) >= 512) ? ((p_cqi->rssi & 0x03FF) - 1024) : (p_cqi->rssi & 0x03FF);
		PAMD = ((p_cqi->pamd & 0x1FF) >= 256) ? ((p_cqi->pamd & 0x01FF) - 512) : (p_cqi->pamd & 0x01FF);
		MR = ((p_cqi->mr & 0x01FF) >= 256) ? ((p_cqi->mr & 0x01FF) - 512) : (p_cqi->mr & 0x01FF);
		ATDC = (p_cqi->atdc >= 32768) ? (65536 - p_cqi->atdc) : (p_cqi->atdc);
		if (ATDC < 0)
			ATDC = (~(ATDC)) - 1;	/* Get abs value of ATDC */

		PRX = (p_cqi->prx & 0x00FF);
		ATDEV = p_cqi->atdev;
		softmuteGainLvl = p_cqi->smg;
		/* check if the channel is valid according to each CQIs */
		if ((RSSI >= fm_config.rx_cfg.long_ana_rssi_th)
		    && (PAMD <= fm_config.rx_cfg.pamd_th)
		    && (ATDC <= fm_config.rx_cfg.atdc_th)
		    && (MR >= fm_config.rx_cfg.mr_th)
		    && (PRX >= fm_config.rx_cfg.prx_th)
		    && (ATDEV >= ATDC)	/* sync scan algorithm */
		    && (softmuteGainLvl >= fm_config.rx_cfg.smg_th)) {
			*valid = fm_true;
		} else {
			*valid = fm_false;
		}
		*rssi = RSSI;
	} else {
		WCN_DBG(FM_ALT | CHIP, "smt get CQI failed\n");
		return fm_false;
	}
	WCN_DBG(FM_NTC | CHIP, "valid=%d\n", *valid);
	return fm_true;
}

static fm_bool mt6580_em_test(fm_u16 group_idx, fm_u16 item_idx, fm_u32 item_value)
{
	return fm_true;
}

static fm_s32 mt6580_set_search_th(fm_s32 idx, fm_s32 val, fm_s32 reserve)
{
	switch (idx) {
	case 0:
		{
			fm_config.rx_cfg.long_ana_rssi_th = val;
			WCN_DBG(FM_NTC | CHIP, "set rssi th =%d\n", val);
			break;
		}
	case 1:
		{
			fm_config.rx_cfg.desene_rssi_th = val;
			WCN_DBG(FM_NTC | CHIP, "set desense rssi th =%d\n", val);
			break;
		}
	case 2:
		{
			fm_config.rx_cfg.smg_th = val;
			WCN_DBG(FM_NTC | CHIP, "set smg th =%d\n", val);
			break;
		}
	default:
		break;
	}
	return 0;
}

static fm_s32 MT6580fm_low_power_wa_default(fm_s32 fmon)
{
	return 0;
}

fm_s32 fm_low_ops_register(struct fm_callback *cb, struct fm_basic_interface *bi)
{
	fm_s32 ret = 0;
	/* Basic functions. */

	if (bi == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,bi invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	if (cb->cur_freq_get == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,cb->cur_freq_get invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	if (cb->cur_freq_set == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,cb->cur_freq_set invalid pointer\n", __func__);
		return -FM_EPARA;
	}
	fm_cb_op = cb;

	bi->pwron = mt6580_pwron;
	bi->pwroff = mt6580_pwroff;
	bi->chipid_get = mt6580_get_chipid;
	bi->mute = mt6580_Mute;
	bi->rampdown = mt6580_RampDown;
	bi->pwrupseq = mt6580_PowerUp;
	bi->pwrdownseq = mt6580_PowerDown;
	bi->setfreq = mt6580_SetFreq;
	bi->low_pwr_wa = MT6580fm_low_power_wa_default;
	bi->get_aud_info = mt6580fm_get_audio_info;
	bi->rssiget = mt6580_GetCurRSSI;
	bi->volset = mt6580_SetVol;
	bi->volget = mt6580_GetVol;
	bi->dumpreg = mt6580_dump_reg;
	bi->msget = mt6580_GetMonoStereo;
	bi->msset = mt6580_SetMonoStereo;
	bi->pamdget = mt6580_GetCurPamd;
	bi->em = mt6580_em_test;
	bi->anaswitch = mt6580_SetAntennaType;
	bi->anaget = mt6580_GetAntennaType;
	bi->caparray_get = mt6580_GetCapArray;
	bi->hwinfo_get = mt6580_hw_info_get;
	bi->i2s_get = mt6580_i2s_info_get;
	bi->is_dese_chan = mt6580_is_dese_chan;
	bi->softmute_tune = mt6580_soft_mute_tune;
	bi->desense_check = mt6580_desense_check;
	bi->cqi_log = mt6580_full_cqi_get;
	bi->pre_search = mt6580_pre_search;
	bi->restore_search = mt6580_restore_search;
	bi->set_search_th = mt6580_set_search_th;

	cmd_buf_lock = fm_lock_create("80_cmd");
	ret = fm_lock_get(cmd_buf_lock);

	cmd_buf = fm_zalloc(TX_BUF_SIZE + 1);

	if (!cmd_buf) {
		WCN_DBG(FM_ALT | CHIP, "6580 fm lib alloc tx buf failed\n");
		ret = -1;
	}
#if 0				/* def CONFIG_MTK_FM_50KHZ_SUPPORT */
	cqi_fifo = fm_fifo_create("6628_cqi_fifo", sizeof(struct adapt_fm_cqi), 640);
	if (!cqi_fifo) {
		WCN_DBG(FM_ALT | CHIP, "6627 fm lib create cqi fifo failed\n");
		ret = -1;
	}
#endif

	return ret;
}

fm_s32 fm_low_ops_unregister(struct fm_basic_interface *bi)
{
	fm_s32 ret = 0;
	/* Basic functions. */
	if (bi == NULL) {
		WCN_DBG(FM_ERR | CHIP, "%s,invalid pointer\n", __func__);
		return -FM_EPARA;
	}

#if 0				/* def CONFIG_MTK_FM_50KHZ_SUPPORT */
	fm_fifo_release(cqi_fifo);
#endif

	if (cmd_buf) {
		fm_free(cmd_buf);
		cmd_buf = NULL;
	}

	ret = fm_lock_put(cmd_buf_lock);
	fm_memset(bi, 0, sizeof(struct fm_basic_interface));
	return ret;
}

/* static struct fm_pub pub; */
/* static struct fm_pub_cb *pub_cb = &pub.pub_tbl; */

static const fm_u16 mt6580_mcu_dese_list[] = {
	0
};

static const fm_u16 mt6580_gps_dese_list[] = {
	7850, 7860
};

static const fm_s8 mt6580_chan_para_map[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 6500~6595 */
	0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,	/* 6600~6695 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 6700~6795 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 6800~6895 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,	/* 6900~6995 */
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 7000~7095 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 7100~7195 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,	/* 7200~7295 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,	/* 7300~7395 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 7400~7495 */
	0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,	/* 7500~7595 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 7600~7695 */
	0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 7700~7795 */
	8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,	/* 7800~7895 */
	0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 7900~7995 */
	0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8000~8095 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,	/* 8100~8195 */
	0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8200~8295 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0,	/* 8300~8395 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8400~8495 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8500~8595 */
	0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,	/* 8600~8695 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8700~8795 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8800~8895 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 8900~8995 */
	0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9000~9095 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9100~9195 */
	0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,	/* 9200~9295 */
	0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9300~9395 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9400~9495 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9500~9595 */
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9600~9695 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9700~9795 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9800~9895 */
	0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 9900~9995 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10000~10095 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10100~10195 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10200~10295 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10300~10395 */
	8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10400~10495 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10500~10595 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10600~10695 */
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 10700~10795 */
	0			/* 10800 */
};

static const fm_u16 mt6580_scan_dese_list[] = {
	6700, 7800, 9210, 9220, 9300, 1040, 1041
};

static const fm_u16 mt6580_TDD_list[] = {
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 6500~6595 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 6600~6695 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 6700~6795 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 6800~6895 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 6900~6995 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7000~7095 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7100~7195 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7200~7295 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7300~7395 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7400~7495 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7500~7595 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7600~7695 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7700~7795 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7800~7895 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 7900~7995 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8000~8095 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8100~8195 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8200~8295 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8300~8395 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8400~8495 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8500~8595 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8600~8695 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8700~8795 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8800~8895 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 8900~8995 */
	0x0000, 0x0000, 0x0000, 0x0100, 0x0000,	/* 9000~9095 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9100~9195 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9200~9295 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9300~9395 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9400~9495 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9500~9595 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9600~9695 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9700~9795 */
	0x0000, 0x0101, 0x0000, 0x0000, 0x0000,	/* 9800~9895 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 9900~9995 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10000~10095 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10100~10195 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10200~10295 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10300~10395 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10400~10495 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10500~10595 */
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	/* 10600~10695 */
	0x0000, 0x0001, 0x0000, 0x0000, 0x0000,	/* 10700~10795 */
	0x0000			/* 10800 */
};

static const fm_u16 mt6580_TDD_Mask[] = {
	0x0001, 0x0010, 0x0100, 0x1000
};

/* return value: 0, not a de-sense channel; 1, this is a de-sense channel; else error no */
static fm_s32 mt6580_is_dese_chan(fm_u16 freq)
{
	fm_s32 size;

	/* return 0;//HQA only :skip desense channel check. */
	size = sizeof(mt6580_scan_dese_list) / sizeof(mt6580_scan_dese_list[0]);

	if (0 == fm_get_channel_space(freq))
		freq *= 10;

	while (size) {
		if (mt6580_scan_dese_list[size - 1] == freq)
			return 1;

		size--;
	}

	return 0;
}

static fm_s32 mt6580_desense_check(fm_u16 freq, fm_s32 rssi)
{
	if (mt6580_is_dese_chan(freq)) {
		if (rssi < fm_config.rx_cfg.desene_rssi_th)
			return 1;

		WCN_DBG(FM_DBG | CHIP, "desen_rssi %d th:%d\n", rssi, fm_config.rx_cfg.desene_rssi_th);
	}
	return 0;
}
#if 0
static fm_bool mt6580_TDD_chan_check(fm_u16 freq)
{
	fm_u32 i = 0;
	fm_u16 freq_tmp = freq;
	fm_s32 ret = 0;

	ret = fm_get_channel_space(freq_tmp);
	if (0 == ret)
		freq_tmp *= 10;
	else if (-1 == ret)
		return fm_false;

	i = (freq_tmp - 6500) / 5;
	if ((i / 4) >= (sizeof(mt6580_TDD_list) / sizeof(mt6580_TDD_list[0]))) {
		WCN_DBG(FM_ERR | CHIP, "Freq index out of range(%d),max(%zd)\n",
			i / 4, (sizeof(mt6580_TDD_list) / sizeof(mt6580_TDD_list[0])));
		return fm_false;
	}

	WCN_DBG(FM_NTC | CHIP, "Freq %d is 0x%4x, mask is 0x%4x\n", freq, (mt6580_TDD_list[i / 4]),
		mt6580_TDD_Mask[i % 4]);
	if (mt6580_TDD_list[i / 4] & mt6580_TDD_Mask[i % 4]) {
		WCN_DBG(FM_NTC | CHIP, "Freq %d use TDD solution\n", freq);
		return fm_true;
	} else
		return fm_false;
}
#endif
/* get channel parameter, HL side/ FA / ATJ */
static fm_u16 mt6580_chan_para_get(fm_u16 freq)
{
	fm_s32 pos, size;

	/* return 0;//for HQA only: skip FA/HL/ATJ */
	if (0 == fm_get_channel_space(freq))
		freq *= 10;

	if (freq < 6500)
		return 0;

	pos = (freq - 6500) / 5;

	size = sizeof(mt6580_chan_para_map) / sizeof(mt6580_chan_para_map[0]);

	pos = (pos < 0) ? 0 : pos;
	pos = (pos > (size - 1)) ? (size - 1) : pos;

	return mt6580_chan_para_map[pos];
}
