
#ifndef _HAL_TYPES_PUBLIC_H_
#define _HAL_TYPES_PUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "val_types_public.h"

typedef struct _HAL_POWER_T {
	VAL_VOID_T          *pvHandle;              /* /< [IN]     The video codec driver handle */
	VAL_UINT32_T        u4HandleSize;           /* /< [IN]     The size of video codec driver handle */
	VAL_DRIVER_TYPE_T   eDriverType;            /* /< [IN]     The driver type */
	VAL_BOOL_T          fgEnable;               /* /< [IN]     Enable or not */
	VAL_VOID_T          *pvReserved;            /* /< [IN/OUT] The reserved parameter */
	VAL_UINT32_T        u4ReservedSize;         /* /< [IN]     The size of reserved parameter structure */
} HAL_POWER_T;

typedef struct _HAL_ISR_T {
	VAL_VOID_T *pvHandle;                /* /< [IN]     The video codec driver handle */
	VAL_UINT32_T u4HandleSize;           /* /< [IN]     The size of video codec driver handle */
	VAL_DRIVER_TYPE_T eDriverType;       /* /< [IN]     The driver type */
	VAL_BOOL_T  fgRegister;              /* /< [IN]     Register or un-register */
	VAL_VOID_T *pvReserved;              /* /< [IN/OUT] The reserved parameter */
	VAL_UINT32_T u4ReservedSize;         /* /< [IN]     The size of reserved parameter structure */
} HAL_ISR_T;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _HAL_TYPES_PUBLIC_H_ */
