


#ifndef _CNM_H
#define _CNM_H





typedef enum _ENUM_CH_REQ_TYPE_T {
	CH_REQ_TYPE_JOIN,
	CH_REQ_TYPE_P2P_LISTEN,
	CH_REQ_TYPE_OFFCHNL_TX,
	CH_REQ_TYPE_GO_START_BSS,
	CH_REQ_TYPE_NUM
} ENUM_CH_REQ_TYPE_T, *P_ENUM_CH_REQ_TYPE_T;

typedef struct _MSG_CH_REQ_T {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_8 ucBssIndex;
	UINT_8 ucTokenID;
	UINT_8 ucPrimaryChannel;
	ENUM_CHNL_EXT_T eRfSco;
	ENUM_BAND_T eRfBand;
	ENUM_CHANNEL_WIDTH_T eRfChannelWidth;	/* To support 80/160MHz bandwidth */
	UINT_8 ucRfCenterFreqSeg1;	/* To support 80/160MHz bandwidth */
	UINT_8 ucRfCenterFreqSeg2;	/* To support 80/160MHz bandwidth */
	ENUM_CH_REQ_TYPE_T eReqType;
	UINT_32 u4MaxInterval;	/* In unit of ms */
} MSG_CH_REQ_T, *P_MSG_CH_REQ_T;

typedef struct _MSG_CH_ABORT_T {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_8 ucBssIndex;
	UINT_8 ucTokenID;
} MSG_CH_ABORT_T, *P_MSG_CH_ABORT_T;

typedef struct _MSG_CH_GRANT_T {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_8 ucBssIndex;
	UINT_8 ucTokenID;
	UINT_8 ucPrimaryChannel;
	ENUM_CHNL_EXT_T eRfSco;
	ENUM_BAND_T eRfBand;
	ENUM_CHANNEL_WIDTH_T eRfChannelWidth;	/* To support 80/160MHz bandwidth */
	UINT_8 ucRfCenterFreqSeg1;	/* To support 80/160MHz bandwidth */
	UINT_8 ucRfCenterFreqSeg2;	/* To support 80/160MHz bandwidth */
	ENUM_CH_REQ_TYPE_T eReqType;
	UINT_32 u4GrantInterval;	/* In unit of ms */
} MSG_CH_GRANT_T, *P_MSG_CH_GRANT_T;

typedef struct _MSG_CH_REOCVER_T {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_8 ucBssIndex;
	UINT_8 ucTokenID;
	UINT_8 ucPrimaryChannel;
	ENUM_CHNL_EXT_T eRfSco;
	ENUM_BAND_T eRfBand;
	ENUM_CHANNEL_WIDTH_T eRfChannelWidth;	/* To support 80/160MHz bandwidth */
	UINT_8 ucRfCenterFreqSeg1;	/* To support 80/160MHz bandwidth */
	UINT_8 ucRfCenterFreqSeg2;	/* To support 80/160MHz bandwidth */
	ENUM_CH_REQ_TYPE_T eReqType;
} MSG_CH_RECOVER_T, *P_MSG_CH_RECOVER_T;

struct MSG_REQ_CH_UTIL {
	MSG_HDR_T rMsgHdr;	/* Must be the first member */
	UINT_16 u2Duration;
	UINT_16 u2ReturnMID;
	UINT_8 ucChnlNum;
	UINT_8 aucChnlList[100];
};

struct MSG_CH_UTIL_RSP {
	MSG_HDR_T rMsgHdr;
	UINT_8 ucChnlNum;
	UINT_8 aucChnlList[100];
	UINT_8 aucChUtil[100];
};

typedef struct _CNM_INFO_T {
	BOOLEAN fgChGranted;
	UINT_8 ucBssIndex;
	UINT_8 ucTokenID;

	UINT_16 u2ReturnMID;
	TIMER_T rReqChnlUtilTimer;
} CNM_INFO_T, *P_CNM_INFO_T;

#if CFG_ENABLE_WIFI_DIRECT
/* Moved from p2p_fsm.h */
typedef struct _DEVICE_TYPE_T {
	UINT_16 u2CategoryId;	/* Category ID */
	UINT_8 aucOui[4];	/* OUI */
	UINT_16 u2SubCategoryId;	/* Sub Category ID */
} __KAL_ATTRIB_PACKED__ DEVICE_TYPE_T, *P_DEVICE_TYPE_T;
#endif



#define CNM_CH_GRANTED_FOR_BSS(_prAdapter, _ucBssIndex) \
	((_prAdapter)->rCnmInfo.fgChGranted && \
	 (_prAdapter)->rCnmInfo.ucBssIndex == (_ucBssIndex))

VOID cnmInit(P_ADAPTER_T prAdapter);

VOID cnmUninit(P_ADAPTER_T prAdapter);

VOID cnmChMngrRequestPrivilege(P_ADAPTER_T prAdapter, P_MSG_HDR_T prMsgHdr);

VOID cnmChMngrAbortPrivilege(P_ADAPTER_T prAdapter, P_MSG_HDR_T prMsgHdr);

VOID cnmChMngrHandleChEvent(P_ADAPTER_T prAdapter, P_WIFI_EVENT_T prEvent);

BOOLEAN
cnmPreferredChannel(P_ADAPTER_T prAdapter, P_ENUM_BAND_T prBand, PUINT_8 pucPrimaryChannel, P_ENUM_CHNL_EXT_T prBssSCO);

BOOLEAN cnmAisInfraChannelFixed(P_ADAPTER_T prAdapter, P_ENUM_BAND_T prBand, PUINT_8 pucPrimaryChannel);

VOID cnmAisInfraConnectNotify(P_ADAPTER_T prAdapter);

BOOLEAN cnmAisIbssIsPermitted(P_ADAPTER_T prAdapter);

BOOLEAN cnmP2PIsPermitted(P_ADAPTER_T prAdapter);

BOOLEAN cnmBowIsPermitted(P_ADAPTER_T prAdapter);

BOOLEAN cnmBss40mBwPermitted(P_ADAPTER_T prAdapter, UINT_8 ucBssIndex);

BOOLEAN cnmBss40mBwPermittedForJoin(P_ADAPTER_T prAdapter, UINT_8 ucBssIndex);

BOOLEAN cnmBss80mBwPermitted(P_ADAPTER_T prAdapter, UINT_8 ucBssIndex);

UINT_8 cnmGetBssMaxBw(P_ADAPTER_T prAdapter, UINT_8 ucBssIndex);

P_BSS_INFO_T cnmGetBssInfoAndInit(P_ADAPTER_T prAdapter, ENUM_NETWORK_TYPE_T eNetworkType, BOOLEAN fgIsP2pDevice);

VOID cnmFreeBssInfo(P_ADAPTER_T prAdapter, P_BSS_INFO_T prBssInfo);
#if CFG_SUPPORT_CHNL_CONFLICT_REVISE
BOOLEAN cnmAisDetectP2PChannel(P_ADAPTER_T prAdapter, P_ENUM_BAND_T prBand, PUINT_8 pucPrimaryChannel);
#endif
VOID cnmRunEventReqChnlUtilTimeout(IN P_ADAPTER_T prAdapter, ULONG ulParamPtr);
VOID cnmHandleChannelUtilization(P_ADAPTER_T prAdapter,
				 struct EVENT_RSP_CHNL_UTILIZATION *prChnlUtil);
VOID cnmRequestChannelUtilization(P_ADAPTER_T prAdapter, P_MSG_HDR_T prMsgHdr);
BOOLEAN cnmChUtilIsRunning(P_ADAPTER_T prAdapter);


#ifndef _lint
static __KAL_INLINE__ VOID cnmMsgDataTypeCheck(VOID)
{
	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, rMsgHdr) == 0);

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, rMsgHdr) == OFFSET_OF(MSG_CH_RECOVER_T, rMsgHdr));

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, ucBssIndex) == OFFSET_OF(MSG_CH_RECOVER_T, ucBssIndex));

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, ucTokenID) == OFFSET_OF(MSG_CH_RECOVER_T, ucTokenID));

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, ucPrimaryChannel) ==
				     OFFSET_OF(MSG_CH_RECOVER_T, ucPrimaryChannel));

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, eRfSco) == OFFSET_OF(MSG_CH_RECOVER_T, eRfSco));

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, eRfBand) == OFFSET_OF(MSG_CH_RECOVER_T, eRfBand));

	DATA_STRUCT_INSPECTING_ASSERT(OFFSET_OF(MSG_CH_GRANT_T, eReqType) == OFFSET_OF(MSG_CH_RECOVER_T, eReqType));

}
#endif /* _lint */

#endif /* _CNM_H */
