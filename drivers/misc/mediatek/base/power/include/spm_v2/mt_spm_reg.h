

#ifndef __MT_SPM_REG__H__
#define __MT_SPM_REG__H__

#if defined(CONFIG_ARCH_MT6755)

#include "mt_spm_reg_mt6755.h"

#define WAKE_SRC_CONN2AP R12_CONN2AP_SPM_WAKEUP_B

#elif defined(CONFIG_ARCH_MT6757)

#include "mt_spm_reg_mt6757.h"

#elif defined(CONFIG_ARCH_MT6797)

#include "mt_spm_reg_mt6797.h"

#define WAKE_SRC_CONN2AP R12_CONN2AP_SPM_WAKEUP_B

#endif

#endif /* __MT_SPM_REG__H__ */
