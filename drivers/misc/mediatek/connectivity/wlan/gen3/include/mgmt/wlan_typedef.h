


#ifndef _WLAN_TYPEDEF_H
#define _WLAN_TYPEDEF_H




typedef struct _BSS_INFO_T BSS_INFO_T, *P_BSS_INFO_T;
typedef struct _BSS_INFO_T P2P_DEV_INFO_T, *P_P2P_DEV_INFO_T;

#if 0				/* Marked for MT6630 */
typedef BSS_INFO_T AIS_BSS_INFO_T, *P_AIS_BSS_INFO_T;
typedef BSS_INFO_T P2P_BSS_INFO_T, *P_P2P_BSS_INFO_T;
typedef BSS_INFO_T BOW_BSS_INFO_T, *P_BOW_BSS_INFO_T;
#endif

typedef struct _AIS_SPECIFIC_BSS_INFO_T AIS_SPECIFIC_BSS_INFO_T, *P_AIS_SPECIFIC_BSS_INFO_T;
typedef struct _P2P_SPECIFIC_BSS_INFO_T P2P_SPECIFIC_BSS_INFO_T, *P_P2P_SPECIFIC_BSS_INFO_T;
typedef struct _BOW_SPECIFIC_BSS_INFO_T BOW_SPECIFIC_BSS_INFO_T, *P_BOW_SPECIFIC_BSS_INFO_T;
/* CFG_SUPPORT_WFD */
typedef struct _WFD_CFG_SETTINGS_T WFD_CFG_SETTINGS_T, *P_WFD_CFG_SETTINGS_T;

/* BSS related structures */
/* Type definition for BSS_DESC_T structure, to describe parameter sets of a particular BSS */
typedef struct _BSS_DESC_T BSS_DESC_T, *P_BSS_DESC_T, **PP_BSS_DESC_T;
typedef struct _ROAM_BSS_DESC_T ROAM_BSS_DESC_T, *P_ROAM_BSS_DESC_T, **PP_ROAM_BSS_DESC_T;

#if CFG_SUPPORT_PASSPOINT
typedef struct _HS20_INFO_T HS20_INFO_T, *P_HS20_INFO_T;
#endif /* CFG_SUPPORT_PASSPOINT */





#endif /* _WLAN_TYPEDEF_H */
