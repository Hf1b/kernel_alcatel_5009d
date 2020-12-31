




#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/soc.h>

#include "AudDrv_Common.h"
#include "AudDrv_Def.h"
#include "AudDrv_Afe.h"
#include "AudDrv_Ana.h"
#include "AudDrv_Clk.h"
#include "mt_soc_analog_type.h"
#include "mt_soc_pcm_common.h"


void Speaker_ClassD_Open(void)
{
	PRINTK_AUDDRV("%s\n", __func__);
	Ana_Set_Reg(SPK_CON2, 0x0214, 0xffff);	/* enable classAB OC function */
	Ana_Set_Reg(SPK_CON9, 0x0400, 0xffff);	/* Set Spk 6dB gain */

	/* enable SPK-Amp with 0dB gain, enable SPK amp offset triming, select class D mode */
	Ana_Set_Reg(SPK_CON0, 0x3008, 0xffff);

	Ana_Set_Reg(SPK_CON0, 0x3009, 0xffff);	/* Enable Class ABD */
	mdelay(5);
	Ana_Set_Reg(SPK_CON0, 0x3001, 0xffff);	/* enable SPK AMP with 0dB gain, select Class D. enable Amp. */
}

void Speaker_ClassD_close(void)
{
	PRINTK_AUDDRV("%s\n", __func__);
	/* Mute Spk amp, select to original class AB mode. disable class-D Amp */
	Ana_Set_Reg(SPK_CON0, 0x0004, 0xffff);
}


void Speaker_ClassAB_Open(void)
{
	PRINTK_AUDDRV("%s\n", __func__);
	Ana_Set_Reg(SPK_CON2, 0x0214, 0xffff);	/* enable classAB OC function */
	Ana_Set_Reg(SPK_CON9, 0x0400, 0xffff);	/* Set Spk 6dB gain */

	/* enable SPK-Amp with 0dB gain, enable SPK amp offset triming, select class D mode */
	Ana_Set_Reg(SPK_CON0, 0x3008, 0xffff);

	Ana_Set_Reg(SPK_CON0, 0x3009, 0xffff);	/* Enable Class ABD */
	mdelay(5);
	Ana_Set_Reg(SPK_CON0, 0x3000, 0xffff);	/* disable amp before switch to ClassAB */
	Ana_Set_Reg(SPK_CON0, 0x3005, 0xffff);	/* enable SPK AMP with 0dB gain, select Class AB. enable Amp. */
}

void Speaker_ClassAB_close(void)
{
	PRINTK_AUDDRV("%s\n", __func__);
	/* Mute Spk amp, select to original class D mode. disable class-AB Amp */
	Ana_Set_Reg(SPK_CON0, 0x0000, 0xffff);
}

void Speaker_ReveiverMode_Open(void)
{
	PRINTK_AUDDRV("%s\n", __func__);
	/* enable classAB OC function, enable speaker L receiver mode[6] */
	Ana_Set_Reg(SPK_CON2, 0x0614, 0xffff);

	Ana_Set_Reg(SPK_CON9, 0x0100, 0xffff);
	/* Ana_Set_Reg(SPK_CON9, 0x0400, 0xffff); // Set Spk 6dB gain */

	/* enable SPK AMP with -6dB gain for 2in1 speaker, select Class AB. enable Amp. */
	Ana_Set_Reg(SPK_CON0, 0x1005, 0xffff);
}

void Speaker_ReveiverMode_close(void)
{
	/* Mute Spk amp, select to original class D mode. disable class-AB Amp */
	Ana_Set_Reg(SPK_CON0, 0x0000, 0xffff);
}

bool GetSpeakerOcFlag(void)
{
	unsigned int OCregister = 0;
	unsigned int bitmask = 1;
	bool DmodeFlag = false;
	bool ABmodeFlag = false;
#if 0				/* no this */
	Ana_Set_Reg(TOP_CKPDN_CON2_CLR, 0x3, 0xffff);
#endif
	OCregister = Ana_Get_Reg(SPK_CON6);
	DmodeFlag = OCregister & (bitmask << 14);	/* no.14 bit is SPK_D_OC_L_DEG */
	ABmodeFlag = OCregister & (bitmask << 15);	/* no.15 bit is SPK_AB_OC_L_DEG */
	PRINTK_AUDDRV("OCregister = %d\n", OCregister);
	return (DmodeFlag | ABmodeFlag);
}
