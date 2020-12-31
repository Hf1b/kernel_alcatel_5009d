

#ifndef __MT_SPM_PMIC_WRAP__H__
#define __MT_SPM_PMIC_WRAP__H__

#if defined(CONFIG_ARCH_MT6755)

#include "mt_spm_pmic_wrap_mt6755.h"

#elif defined(CONFIG_ARCH_MT6757)

#include "mt_spm_pmic_wrap_mt6757.h"

#elif defined(CONFIG_ARCH_MT6797)

#include "mt_spm_pmic_wrap_mt6797.h"

#endif


/* APIs */
extern int mt_spm_pmic_wrap_init(void);
extern void mt_spm_pmic_wrap_set_phase(enum pmic_wrap_phase_id phase);
extern void mt_spm_pmic_wrap_set_cmd(enum pmic_wrap_phase_id phase, int idx,
				     unsigned int cmd_wdata);
extern void mt_spm_pmic_wrap_apply_cmd(int idx);
extern void mt_spm_pmic_wrap_get_cmd_full(enum pmic_wrap_phase_id phase, int idx,
					  unsigned int *p_cmd_addr, unsigned int *p_cmd_wdata);
extern void mt_spm_pmic_wrap_set_cmd_full(enum pmic_wrap_phase_id phase, int idx,
					  unsigned int cmd_addr, unsigned int cmd_wdata);


#endif /* __MT_SPM_PMIC_WRAP__H__ */