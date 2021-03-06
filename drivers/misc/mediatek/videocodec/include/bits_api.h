
#ifndef _BITS_API_H_
#define _BITS_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "val_types_public.h"
#include "hal_api.h"

typedef VAL_UINT32_T(*fgPrepare32FN)(VAL_HANDLE_T * a_phBitsHandle);

typedef struct __VBITS_HANDLE_T {
	VAL_HANDLE_T    hHALHandle;                             /* /< HAL Handle */
	VAL_HANDLE_T    hVALHandle;                             /* /< VAL Handle */
	VAL_MEM_ADDR_T  BitsStart;                              /* /< Bits Start */
	VAL_MEMORY_T    rHandleMem;                             /* /< Handle memory */
	VAL_UINT32_T    nReadingMode;                           /* /< 0 for software, 1 for mmap, 2 for hardware */
	VAL_ULONG_T     StartAddr;                              /* /< used for software mode fast access */
	VAL_ULONG_T     nSize;                                  /* /< Size */
	VAL_UINT32_T    nBitCnt;                                /* /< bits count */
	VAL_UINT32_T    nZeroCnt;                               /* /< zero count */
	VAL_UINT32_T    Cur32Bits;                              /* /< current 32 bits */
	VAL_UINT32_T    CurBitCnt;                              /* /< current bits count */
	VAL_UINT32_T    n03RemoveCount;                         /* /< 03 Remove Count */
	VAL_UINT32_T    n03CountBit;                            /* /< 03 Count Bit */
	VAL_INT32_T     n03FirstIndex;                          /* /< 03 First Index */
	VAL_INT32_T     n03SecondIndex;                         /* /< 03 Second Index */
	VAL_UINT32_T    n03RemoveIgnore;                        /* /< 03 Remove Ignore */
	VAL_BOOL_T      bFirstCheck;                            /* /< First Check */
	VAL_BOOL_T      bEverRemove;                            /* /< Ever Remove */
	VAL_BOOL_T      bIgnoreByBS;                            /* /< Ignore By BS */
	VAL_BOOL_T      bEOF;                                   /* /< EOF */
	fgPrepare32FN   Prepare32Bits;                          /* /< Prepare 32 Bits */
	VAL_DRIVER_TYPE_T vFormat;                              /* /< Format */
	VAL_UINT32_T    value;                                  /* /< value */
} VBITS_HANDLE_T;


typedef enum VBITS_READTYPE_T {
	VBITS_SOFTWARE = 0,         /* /< software */
	VBITS_MMAP,                 /* /< mmap */
	VBITS_HARDWARE,             /* /< hardware */
	VBITS_MAX                   /* /< MAX value */
} VBITS_READTYPE_T;


VAL_UINT32_T eBufEnable(
	VAL_HANDLE_T *a_phBitsHandle,
	VAL_HANDLE_T hHALHandle,
	VAL_UINT32_T nMode,
	VAL_DRIVER_TYPE_T vFormat
);


VAL_UINT32_T eBufDisable(
	VAL_HANDLE_T *a_phBitsHandle,
	VAL_HANDLE_T hHALHandle,
	VAL_UINT32_T nMode,
	VAL_DRIVER_TYPE_T vFormat
);


VAL_RESULT_T eBufInit(
	VAL_HANDLE_T *a_phBitsHandle,
	VAL_HANDLE_T hVALHandle,
	VAL_HANDLE_T hHALHandle,
	VAL_MEM_ADDR_T rBufAddrStart,
	VAL_UINT32_T nMode,
	VAL_DRIVER_TYPE_T vFormat
);


VAL_RESULT_T eBufDeinit(VAL_HANDLE_T *a_phBitsHandle);


VAL_UINT32_T eBufGetBitCnt(VAL_HANDLE_T *a_phBitsHandle);


VAL_UINT32_T eBufGetBits(VAL_HANDLE_T *a_phBitsHandle, VAL_UINT32_T numBits);


VAL_UINT32_T eBufNextBits(VAL_HANDLE_T *a_phBitsHandle, VAL_UINT32_T numBits);


VAL_UINT32_T eBufGetUEGolomb(VAL_HANDLE_T *a_phBitsHandle);


VAL_INT32_T  eBufGetSEGolomb(VAL_HANDLE_T *a_phBitsHandle);


VAL_BOOL_T   eBufCheckEOF(VAL_HANDLE_T *a_phBitsHandle);


VAL_UINT32_T eBufGetBufSize(VAL_HANDLE_T *a_phBitsHandle);


void NextBytesAlignment(VAL_HANDLE_T *a_phBitsHandle, VAL_UINT32_T nBytesAlignment);


VAL_BOOL_T   eBufInitBS(VAL_HANDLE_T *a_phBitsHandle, P_VCODEC_DRV_CMD_T cmd_queue, VAL_UINT32_T *pIndex);


VAL_UINT32_T eBufGetPAddr(VAL_HANDLE_T *a_phBitsHandle);


VAL_BOOL_T eBufReInite(VAL_HANDLE_T *a_phBitsHandle, VAL_UINT32_T nBytes, VAL_UINT32_T nBits);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _VAL_API_H_ */
