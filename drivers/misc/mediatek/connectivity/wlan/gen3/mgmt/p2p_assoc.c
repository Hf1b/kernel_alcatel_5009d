




#include "precomp.h"








/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
PUINT_8 p2pBuildReAssocReqFrameCommonIEs(IN P_ADAPTER_T prAdapter, IN P_MSDU_INFO_T prMsduInfo, IN PUINT_8 pucBuffer)
{
	P_BSS_INFO_T prP2pBssInfo = (P_BSS_INFO_T) NULL;

	prP2pBssInfo = GET_BSS_INFO_BY_INDEX(prAdapter, prMsduInfo->ucBssIndex);

	/* Fill the SSID element. */
	SSID_IE(pucBuffer)->ucId = ELEM_ID_SSID;

	/* NOTE(Kevin): We copy the SSID from CONNECTION_SETTINGS for the case of
	 * Passive Scan and the target BSS didn't broadcast SSID on its Beacon Frame.
	 */

	COPY_SSID(SSID_IE(pucBuffer)->aucSSID,
		  SSID_IE(pucBuffer)->ucLength, prP2pBssInfo->aucSSID, prP2pBssInfo->ucSSIDLen);

	prMsduInfo->u2FrameLength += IE_SIZE(pucBuffer);
	pucBuffer += IE_SIZE(pucBuffer);
	return pucBuffer;
}
