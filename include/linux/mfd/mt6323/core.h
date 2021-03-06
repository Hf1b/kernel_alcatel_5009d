
#ifndef __MFD_MT6323_CORE_H__
#define __MFD_MT6323_CORE_H__

enum RG_INT_STATUS_numbers {
	RG_INT_STATUS_SPKL_AB = 0,
	RG_INT_STATUS_SPKL,
	RG_INT_STATUS_BAT_L,
	RG_INT_STATUS_BAT_H,
	RG_INT_STATUS_WATCHDOG,
	RG_INT_STATUS_PWRKEY,
	RG_INT_STATUS_THR_L,
	RG_INT_STATUS_THR_H,
	RG_INT_STATUS_VBATON_UNDET,
	RG_INT_STATUS_BVALID_DET,
	RG_INT_STATUS_CHRDET,
	RG_INT_STATUS_OV,
	RG_INT_STATUS_LDO = 16,
	RG_INT_STATUS_FCHRKEY,
	RG_INT_STATUS_ACCDET,
	RG_INT_STATUS_AUDIO,
	RG_INT_STATUS_RTC,
	RG_INT_STATUS_VPROC,
	RG_INT_STATUS_VSYS,
	RG_INT_STATUS_VPA,
	MT6323_IRQ_NR,
};

#endif /* __MFD_MT6323_CORE_H__ */
