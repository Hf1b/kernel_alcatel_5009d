
#ifndef __CCCI_IPC_MSG_ID_H__
#define __CCCI_IPC_MSG_ID_H__

typedef enum {
	IPC_L4C_MSG_ID_INVALID = IPC_L4C_MSG_ID_BEGIN,
	IPC_L4C_MSG_ID_END,

	IPC_EL1_MSG_ID_INVALID = IPC_EL1_MSG_ID_BEGIN,
	/* ccci_ipc_el1_msg_id.h */
	IPC_EL1_MSG_ID_END,

	IPC_CCCIIPC_MSG_ID_INVALID = IPC_CCCIIPC_MSG_ID_BEGIN,
	IPC_MSG_ID_CCCIIPC_CLIB_TIME_REQ,
	IPC_CCCIIPC_MSG_ID_END,

	IPC_IPCORE_MSG_ID_INVALID = IPC_IPCORE_MSG_ID_BEGIN,
	IPC_MSG_ID_IPCORE_GF_REG,
	IPC_MSG_ID_IPCORE_GF_UNREG,
	IPC_IPCORE_MSG_ID_END,

	IPC_MDT_MSG_ID_INVALID = IPC_MDT_MSG_ID_BEGIN,
	IPC_MSG_ID_MDT_ADD_RULE_IND,
	IPC_MSG_ID_MDT_DELETE_RULE_IND,
	IPC_MSG_ID_MDT_DELETE_RULE_RSP,
	IPC_MSG_ID_MDT_SYNC_RULE_STATUS,
	IPC_MDT_MSG_ID_END,

	IPC_UFPM_MSG_ID_INVALID = IPC_UFPM_MSG_ID_BEGIN,
	IPC_MSG_ID_UFPM_NOTIFY_MD_BUS_EVENT_REQ,
	IPC_MSG_ID_UFPM_NOTIFY_MD_BUS_EVENT_RSP,
	IPC_MSG_ID_UFPM_SEND_MD_USB_EP0_REQ,
	IPC_MSG_ID_UFPM_SEND_MD_USB_EP0_RSP,
	IPC_MSG_ID_UFPM_SEND_MD_USB_EP0_IND,
	IPC_MSG_ID_UFPM_SEND_AP_USB_EP0_IND,
	IPC_MSG_ID_UFPM_ENABLE_MD_FAST_PATH_REQ,
	IPC_MSG_ID_UFPM_ENABLE_MD_FAST_PATH_RSP,
	IPC_MSG_ID_UFPM_DISABLE_MD_FAST_PATH_REQ,
	IPC_MSG_ID_UFPM_DISABLE_MD_FAST_PATH_RSP,
	IPC_MSG_ID_UFPM_DEACTIVATE_MD_FAST_PATH_REQ,
	IPC_MSG_ID_UFPM_DEACTIVATE_MD_FAST_PATH_RSP,
	IPC_MSG_ID_UFPM_ACTIVATE_MD_FAST_PATH_REQ,
	IPC_MSG_ID_UFPM_ACTIVATE_MD_FAST_PATH_RSP,
	IPC_UFPM_MSG_ID_END,
} CCCI_IPC_MSG_ID_CODE;

#endif
