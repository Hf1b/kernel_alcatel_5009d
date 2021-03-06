



#include <linux/kernel.h>
#include <linux/workqueue.h>

#include "precomp.h"
#include "gl_rst.h"

#if CFG_CHIP_RESET_SUPPORT


static BOOLEAN fgResetTriggered = FALSE;
BOOLEAN fgIsResetting = FALSE;
UINT32 g_IsNeedDoChipReset;

static RESET_STRUCT_T wifi_rst;

static void mtk_wifi_reset(struct work_struct *work);
static void mtk_wifi_trigger_reset(struct work_struct *work);

static void *glResetCallback(ENUM_WMTDRV_TYPE_T eSrcType,
			     ENUM_WMTDRV_TYPE_T eDstType,
			     ENUM_WMTMSG_TYPE_T eMsgType, void *prMsgBody, unsigned int u4MsgLength);

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID glResetInit(VOID)
{
#if (defined(MT6797) && (MTK_WCN_SINGLE_MODULE == 0)) || defined(MT6630)
	/* 1. Register reset callback */
	mtk_wcn_wmt_msgcb_reg(WMTDRV_TYPE_WIFI, (PF_WMT_CB) glResetCallback);
#endif
	/* 2. Initialize reset work */
	INIT_WORK(&(wifi_rst.rst_work), mtk_wifi_reset);
	INIT_WORK(&(wifi_rst.rst_trigger_work), mtk_wifi_trigger_reset);
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID glResetUninit(VOID)
{
#if (defined(MT6797) && (MTK_WCN_SINGLE_MODULE == 0)) || defined(MT6630)
	/* 1. Deregister reset callback */
	mtk_wcn_wmt_msgcb_unreg(WMTDRV_TYPE_WIFI);
#endif
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static void *glResetCallback(ENUM_WMTDRV_TYPE_T eSrcType,
			     ENUM_WMTDRV_TYPE_T eDstType,
			     ENUM_WMTMSG_TYPE_T eMsgType, void *prMsgBody, unsigned int u4MsgLength)
{
	switch (eMsgType) {
	case WMTMSG_TYPE_RESET:
		if (u4MsgLength == sizeof(ENUM_WMTRSTMSG_TYPE_T)) {
			P_ENUM_WMTRSTMSG_TYPE_T prRstMsg = (P_ENUM_WMTRSTMSG_TYPE_T) prMsgBody;

			switch (*prRstMsg) {
			case WMTRSTMSG_RESET_START:
				DBGLOG(INIT, WARN, "Whole chip reset start!\n");
				fgIsResetting = TRUE;
				fgResetTriggered = FALSE;
				wifi_reset_start();
				break;

			case WMTRSTMSG_RESET_END:
				DBGLOG(INIT, WARN, "Whole chip reset end!\n");
				fgIsResetting = FALSE;
				wifi_rst.rst_data = RESET_SUCCESS;
				schedule_work(&(wifi_rst.rst_work));
				break;

			case WMTRSTMSG_RESET_END_FAIL:
				DBGLOG(INIT, WARN, "Whole chip reset fail!\n");
				fgIsResetting = FALSE;
				wifi_rst.rst_data = RESET_FAIL;
				schedule_work(&(wifi_rst.rst_work));
				break;

			default:
				break;
			}
		}
		break;

	default:
		break;
	}

	return NULL;
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static void mtk_wifi_reset(struct work_struct *work)
{
	RESET_STRUCT_T *rst = container_of(work, RESET_STRUCT_T, rst_work);

	wifi_reset_end(rst->rst_data);
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID glSendResetRequest(VOID)
{
	/* WMT thread would trigger whole chip reset itself */
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
BOOLEAN kalIsResetting(VOID)
{
	return fgIsResetting;
}

static void mtk_wifi_trigger_reset(struct work_struct *work)
{
	BOOLEAN fgResult = FALSE;

	fgResetTriggered = TRUE;
	fgResult = mtk_wcn_wmt_assert(WMTDRV_TYPE_WIFI, 0x40);
	DBGLOG(INIT, INFO, "reset result %d\n", fgResult);
}

BOOLEAN glResetTrigger(P_ADAPTER_T prAdapter)
{
	BOOLEAN fgResult = TRUE;

#if CFG_WMT_RESET_API_SUPPORT
	if (kalIsResetting() || fgResetTriggered) {
		DBGLOG(INIT, ERROR,
			"Skip triggering whole-chip reset during resetting! Chip[%04X E%u]\n",
			MTK_CHIP_REV,
			wlanGetEcoVersion(prAdapter));
		DBGLOG(INIT, ERROR,
			"FW Ver DEC[%u.%u] HEX[%x.%x], Driver Ver[%u.%u]\n",
			(prAdapter->rVerInfo.u2FwOwnVersion >> 8),
			(prAdapter->rVerInfo.u2FwOwnVersion & BITS(0, 7)),
			(prAdapter->rVerInfo.u2FwOwnVersion >> 8),
			(prAdapter->rVerInfo.u2FwOwnVersion & BITS(0, 7)),
			(prAdapter->rVerInfo.u2FwPeerVersion >> 8),
			(prAdapter->rVerInfo.u2FwPeerVersion & BITS(0, 7)));

		fgResult = TRUE;
	} else {
		DBGLOG(INIT, ERROR,
		"Trigger whole-chip reset! Chip[%04X E%u] FW Ver DEC[%u.%u] HEX[%x.%x], Driver Ver[%u.%u]\n",
			     MTK_CHIP_REV,
			     wlanGetEcoVersion(prAdapter),
			     (prAdapter->rVerInfo.u2FwOwnVersion >> 8),
			     (prAdapter->rVerInfo.u2FwOwnVersion & BITS(0, 7)),
			     (prAdapter->rVerInfo.u2FwOwnVersion >> 8),
			     (prAdapter->rVerInfo.u2FwOwnVersion & BITS(0, 7)),
			     (prAdapter->rVerInfo.u2FwPeerVersion >> 8),
			     (prAdapter->rVerInfo.u2FwPeerVersion & BITS(0, 7)));

		schedule_work(&(wifi_rst.rst_trigger_work));
	}
#endif

	return fgResult;
}

ENUM_CHIP_RESET_REASON_TYPE_T eResetReason;
UINT_64 u8ResetTime;
VOID glGetRstReason(ENUM_CHIP_RESET_REASON_TYPE_T eReason)
{
	u8ResetTime = sched_clock();
	eResetReason = eReason;
}

#endif /* CFG_CHIP_RESET_SUPPORT */
