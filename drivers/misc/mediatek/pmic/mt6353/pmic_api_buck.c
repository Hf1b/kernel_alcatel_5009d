
#include <linux/kernel.h>
#include <linux/module.h>

#include <mach/upmu_sw.h>
#include <mach/upmu_hw.h>
#include <mt-plat/upmu_common.h>
#include "include/pmic.h"

static DEFINE_SPINLOCK(vcore2_lock);
static unsigned int vcore2_use_count;

/* -------- generated by version : buck coda v1.0 ------------ */
/* -------- date : 2015-12-01                   ------------ */
/* -------- date : 2015-12-01                   ------------ */
/* -------- Buck VPROC  API ------------ Type3 */
/* define EN by sw mode */
void pmic_buck_vproc_sw_en(int en_value)
{
	unsigned short read_back;

	PMICLOG("buck : VPROC ; sw enable = %d\n", en_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_EN_CTRL, 0);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_EN, en_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VPROC_EN);
	PMICLOG("buck : VPROC ; sw en_value readback = %d\n", read_back);
}


/* define EN by hw mode */
void pmic_buck_vproc_hw_en(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VPROC ; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_EN_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_EN_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VPROC_EN_SEL);
	PMICLOG("buck : VPROC ; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by hw mode */
void pmic_buck_vproc_hw_vosel(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VPROC ; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_VOSEL_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_VSLEEP_EN, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_VOSEL_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VPROC_VOSEL_SEL);
	PMICLOG("buck : VPROC ; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by sw mode */
void pmic_buck_vproc_sw_vosel(void)
{
	unsigned short read_back;

	pmic_set_register_value_nolock(PMIC_BUCK_VPROC_VOSEL_CTRL, 0);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VPROC_VOSEL_CTRL);
	PMICLOG("buck : VPROC ; hw en_sel readback = %d\n", read_back);
}

/* -------- Buck VPROC  API end -------- */

/* -------- Buck VS1    API ------------ Type3 */
/* define EN by sw mode */
void pmic_buck_vs1_sw_en(int en_value)
{
	unsigned short read_back;

	PMICLOG("buck : VS1   ; sw enable = %d\n", en_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_EN_CTRL, 0);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_EN, en_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VS1_EN);
	PMICLOG("buck : VS1   ; sw en_value readback = %d\n", read_back);
}


/* define EN by hw mode */
void pmic_buck_vs1_hw_en(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VS1   ; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_EN_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_EN_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VS1_EN_SEL);
	PMICLOG("buck : VS1   ; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by hw mode */
void pmic_buck_vs1_hw_vosel(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VS1   ; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_VOSEL_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_VSLEEP_EN, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VS1_VOSEL_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VS1_VOSEL_SEL);
	PMICLOG("buck : VS1   ; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by sw mode */
void pmic_buck_vs1_sw_vosel(void)
{
	unsigned short read_back;

	pmic_set_register_value_nolock(PMIC_BUCK_VS1_VOSEL_CTRL, 0);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VS1_VOSEL_CTRL);
	PMICLOG("buck : VS1   ; hw en_sel readback = %d\n", read_back);
}
/* -------- Buck VS1    API end -------- */

/* -------- Buck VCORE  API ------------ Type3 */
/* define EN by sw mode */
void pmic_buck_vcore_sw_en(int en_value)
{
	unsigned short read_back;

	PMICLOG("buck : VCORE ; sw enable = %d\n", en_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_EN_CTRL, 0);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_EN, en_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE_EN);
	PMICLOG("buck : VCORE ; sw en_value readback = %d\n", read_back);
}


/* define EN by hw mode */
void pmic_buck_vcore_hw_en(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VCORE ; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_EN_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_EN_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE_EN_SEL);
	PMICLOG("buck : VCORE ; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by hw mode */
void pmic_buck_vcore_hw_vosel(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VCORE ; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_VOSEL_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_VSLEEP_EN, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_VOSEL_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE_VOSEL_SEL);
	PMICLOG("buck : VCORE ; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by sw mode */
void pmic_buck_vcore_sw_vosel(void)
{
	unsigned short read_back;

	pmic_set_register_value_nolock(PMIC_BUCK_VCORE_VOSEL_CTRL, 0);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE_VOSEL_CTRL);
	PMICLOG("buck : VCORE ; hw en_sel readback = %d\n", read_back);
}
/* -------- Buck VCORE  API end -------- */

/* -------- Buck VCORE2 API ------------ Type3 */
/* define EN by sw mode */
void pmic_buck_vcore2_sw_en(int en_value)
{
	unsigned short read_back;

	PMICLOG("buck : VCORE2; sw enable = %d\n", en_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_EN_CTRL, 0);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_EN, en_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE2_EN);
	PMICLOG("buck : VCORE2; sw en_value readback = %d\n", read_back);
}


/* define EN by hw mode */
void pmic_buck_vcore2_hw_en(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VCORE2; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_EN_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_EN_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE2_EN_SEL);
	PMICLOG("buck : VCORE2; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by hw mode */
void pmic_buck_vcore2_hw_vosel(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VCORE2; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_VOSEL_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_VSLEEP_EN, 1);
	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_VOSEL_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE2_VOSEL_SEL);
	PMICLOG("buck : VCORE2; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by sw mode */
void pmic_buck_vcore2_sw_vosel(void)
{
	unsigned short read_back;

	pmic_set_register_value_nolock(PMIC_BUCK_VCORE2_VOSEL_CTRL, 0);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VCORE2_VOSEL_CTRL);
	PMICLOG("buck : VCORE2; hw en_sel readback = %d\n", read_back);
}


/*--------  SPM Support Start -----------*/
/*--return 0: use_count = 0--*/
/*--return 1: use_count > 0--*/
int pmic_buck_vcore2_en_status(void)
{
	unsigned int ret = 0;

	spin_lock(&vcore2_lock);
	if (!vcore2_use_count) {
		spin_unlock(&vcore2_lock);
		ret = 0;
	} else {
		spin_unlock(&vcore2_lock);
		ret = 1;
	}

	return ret;
}

/*--buck_name = VGPU/VMODEM, mode = 0 ,SW, en_value = 1/0 (on/off)--*/
/*--buck_name = VGPU/VMODEM, mode = 1 ,HW, en_value = srclk [0-7] --*/
int pmic_buck_vcore2_en(char *buck_name, int mode, int en_value)
{
	if (strcmp(buck_name, "VGPU") && strcmp(buck_name, "VMODEM"))
		return -1;

	PMICLOG("buck : %s, %s, en_value = %d\n", buck_name, (mode ? "HW" : "SW"), en_value);

	spin_lock(&vcore2_lock);
	if (!mode) {
		if (en_value)
			vcore2_use_count++;
		else
			vcore2_use_count--;
	} else
		vcore2_use_count++;
	spin_unlock(&vcore2_lock);

	/*pr_err("vcore2_use_count = %d\n", vcore2_use_count); */

	if (!mode) {
		if (!en_value) {
			if (!pmic_buck_vcore2_en_status())
				pmic_buck_vcore2_sw_en(en_value);
		} else
			pmic_buck_vcore2_sw_en(en_value);
	} else
		pmic_buck_vcore2_hw_en(en_value);

	return 0;
}

/*--------  SPM Support End -----------*/

/* -------- Buck VCORE2 API end -------- */

/* -------- Buck VPA    API ------------ Type0 */
/* define EN by sw mode */
void pmic_buck_vpa_sw_en(int en_value)
{
	unsigned short read_back;

	PMICLOG("buck : VPA   ; sw enable = %d\n", en_value);
	pmic_set_register_value_nolock(PMIC_BUCK_VPA_EN, en_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_BUCK_VPA_EN);
	PMICLOG("buck : VPA   ; sw en_value readback = %d\n", read_back);
}
/* -------- Buck VPA    API end -------- */

/* -------- Buck VSRAM_PROC API ------------ Type3 */
/* define EN by sw mode */
void pmic_ldo_vsram_proc_sw_en(int en_value)
{
	unsigned short read_back;

	PMICLOG("buck : VSRAM_PROC; sw enable = %d\n", en_value);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_EN_CTRL, 0);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_EN, en_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_LDO_VSRAM_PROC_EN);
	PMICLOG("buck : VSRAM_PROC; sw en_value readback = %d\n", read_back);
}


/* define EN by hw mode */
void pmic_ldo_vsram_proc_hw_en(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VSRAM_PROC; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_EN_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_EN_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_LDO_VSRAM_PROC_EN_SEL);
	PMICLOG("buck : VSRAM_PROC; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by hw mode */
void pmic_ldo_vsram_proc_hw_vosel(int ensel_value)
{
	unsigned short read_back;

	PMICLOG("buck : VSRAM_PROC; hw en_sel = %d\n", ensel_value);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_VOSEL_CTRL, 1);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_VSLEEP_EN, 1);
	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_VOSEL_SEL, ensel_value);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_LDO_VSRAM_PROC_VOSEL_SEL);
	PMICLOG("buck : VSRAM_PROC; hw en_sel readback = %d\n", read_back);
}


/* define VOSEL by sw mode */
void pmic_ldo_vsram_proc_sw_vosel(void)
{
	unsigned short read_back;

	pmic_set_register_value_nolock(PMIC_LDO_VSRAM_PROC_VOSEL_CTRL, 0);

	/* read back check */
	read_back = pmic_get_register_value_nolock(PMIC_LDO_VSRAM_PROC_VOSEL_CTRL);
	PMICLOG("buck : VSRAM_PROC; hw en_sel readback = %d\n", read_back);
}

/* -------- Buck VSRAM_PROC API end -------- */
