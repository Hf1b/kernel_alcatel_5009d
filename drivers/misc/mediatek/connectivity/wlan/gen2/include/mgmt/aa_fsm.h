
#ifndef _AA_FSM_H
#define _AA_FSM_H



/* Retry interval for retransmiting authentication-request MMPDU. */
#define TX_AUTHENTICATION_RETRY_TIMEOUT_TU          100	/* TU. */

/* Retry interval for retransmiting association-request MMPDU. */
#define TX_ASSOCIATION_RETRY_TIMEOUT_TU             100	/* TU. */

/* Wait for a response to a transmitted authentication-request MMPDU. */
#define DOT11_AUTHENTICATION_RESPONSE_TIMEOUT_TU    512	/* TU. */

/* Wait for a response to a transmitted association-request MMPDU. */
#define DOT11_ASSOCIATION_RESPONSE_TIMEOUT_TU       512	/* TU. */

/* The maximum time to wait for JOIN process complete. */
#define JOIN_FAILURE_TIMEOUT_BEACON_INTERVAL        20	/* Beacon Interval, 20 * 100TU = 2 sec. */

/* Retry interval for next JOIN request. */
#define JOIN_RETRY_INTERVAL_SEC                     10	/* Seconds */

/* Maximum Retry Count for accept a JOIN request. */
#define JOIN_MAX_RETRY_FAILURE_COUNT                2	/* Times */

#define JOIN_MAX_RETRY_OVERLOAD_RN		    1	/* Times */
typedef enum _ENUM_AA_STATE_T {
	AA_STATE_IDLE = 0,
	SAA_STATE_SEND_AUTH1,
	SAA_STATE_WAIT_AUTH2,
	SAA_STATE_SEND_AUTH3,
	SAA_STATE_WAIT_AUTH4,
	SAA_STATE_SEND_ASSOC1,
	SAA_STATE_WAIT_ASSOC2,
	AAA_STATE_SEND_AUTH2,
	AAA_STATE_SEND_AUTH4,	/* We may not use, because P2P GO didn't support WEP and 11r */
	AAA_STATE_SEND_ASSOC2,
	AA_STATE_RESOURCE,	/* A state for debugging the case of out of msg buffer. */
	AA_STATE_NUM
} ENUM_AA_STATE_T;

typedef enum _ENUM_AA_FRM_TYPE_T {
	FRM_DISASSOC = 0,
	FRM_DEAUTH
} ENUM_AA_FRM_TYPE_T;



/*----------------------------------------------------------------------------*/
/* Routines in saa_fsm.c                                                      */
/*----------------------------------------------------------------------------*/
VOID
saaFsmSteps(IN P_ADAPTER_T prAdapter,
	    IN P_STA_RECORD_T prStaRec, IN ENUM_AA_STATE_T eNextState, IN P_SW_RFB_T prRetainedSwRfb);

WLAN_STATUS
saaFsmSendEventJoinComplete(IN P_ADAPTER_T prAdapter,
			    WLAN_STATUS rJoinStatus, P_STA_RECORD_T prStaRec, P_SW_RFB_T prSwRfb);

VOID saaFsmRunEventStart(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

WLAN_STATUS
saaFsmRunEventTxDone(IN P_ADAPTER_T prAdapter, IN P_MSDU_INFO_T prMsduInfo, IN ENUM_TX_RESULT_CODE_T rTxDoneStatus);

VOID saaFsmRunEventTxReqTimeOut(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec);

VOID saaFsmRunEventRxRespTimeOut(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec);

VOID saaFsmRunEventRxAuth(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

WLAN_STATUS saaFsmRunEventRxAssoc(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

WLAN_STATUS saaFsmRunEventRxDeauth(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

WLAN_STATUS saaFsmRunEventRxDisassoc(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

VOID saaFsmRunEventAbort(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);

VOID saaSendDisconnectMsgHandler(IN P_ADAPTER_T prAdapter, IN P_STA_RECORD_T prStaRec,
				IN P_BSS_INFO_T prAisBssInfo, IN ENUM_AA_FRM_TYPE_T eFrmType);

VOID saaFsmRunEventFTContinue(IN P_ADAPTER_T prAdapter, IN P_MSG_HDR_T prMsgHdr);
/*----------------------------------------------------------------------------*/
/* Routines in aaa_fsm.c                                                      */
/*----------------------------------------------------------------------------*/
VOID aaaFsmRunEventRxAuth(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

WLAN_STATUS aaaFsmRunEventRxAssoc(IN P_ADAPTER_T prAdapter, IN P_SW_RFB_T prSwRfb);

WLAN_STATUS
aaaFsmRunEventTxDone(IN P_ADAPTER_T prAdapter, IN P_MSDU_INFO_T prMsduInfo, IN ENUM_TX_RESULT_CODE_T rTxDoneStatus);


#endif /* _AA_FSM_H */
