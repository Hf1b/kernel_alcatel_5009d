
#ifndef __MT_IDLE_H__
#define __MT_IDLE_H__

#if defined(CONFIG_ARCH_MT6755) || defined(CONFIG_ARCH_MT6757) || defined(CONFIG_ARCH_MT6797)

#include "spm_v2/mt_idle.h"

#elif defined(CONFIG_ARCH_MT6735) || defined(CONFIG_ARCH_MT6735M) || defined(CONFIG_ARCH_MT6753)

#elif defined(CONFIG_ARCH_ELBRUS)

#include "spm_v3/mt_idle.h"

#endif

#endif /* __MT_IDLE_H__ */

