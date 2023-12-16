/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 ******************************************************************************/

#ifndef _MAC_AX_SER_H_
#define _MAC_AX_SER_H_

#include "../type.h"

#if MAC_AX_SDIO_SUPPORT
#include "_sdio.h"
#endif

#if MAC_AX_PCIE_SUPPORT
#include "_pcie.h"
#endif

#if MAC_AX_USB_SUPPORT
#include "_usb.h"
#endif

#define SER_ENABLE 0XFFFFFFFF
#define SER_DISABLE 0X00000000

#if defined(PHL_FEATURE_AP)
/*--------------------CMAC ERROR ----------------------------------------*/
/*--------------------CMAC DMA IMR --------------------------------------*/
// 0xC800
// bit[14]
#define CMAC_DMA_RXSTS_FSM_HANG_SER_EN SER_ENABLE
// bit[15]
#define CMAC_DMA_RXDATA_FSM_HANG_SER_EN SER_DISABLE
// bit[23]
#define CMAC_DMA_NO_RSVD_PAGE_SER_EN SER_DISABLE
// 0xC828
// bit[31]
#define CMAC_DMA_RXDATA_SUBFSM_HANG_SER_EN SER_ENABLE

/*-------------------- PTCL IMR -----------------------------------------*/
// 0xC6C0
// bit[0]
#define PTCL_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[8]
#define PTCL_F2PCMDRPT_FULL_DROP_SER_EN SER_DISABLE
// bit[9]
#define PTCL_TXRPT_FULL_DROP_SER_EN SER_DISABLE
// bit[10]
#define PTCL_D_PKTID_ERR_SER_EN SER_DISABLE
// bit[11]
#define PTCL_Q_PKTID_ERR_SER_EN SER_DISABLE
// bit[12]
#define PTCL_BCNQ_ORDER_ERR_SER_EN SER_DISABLE
// bit[14]
#define PTCL_TWTSP_QSEL_ERR_SER_EN SER_DISABLE
// bit[15]
#define PTCL_F2PCMD_EMPTY_ERR_SER_EN SER_DISABLE
// bit[23]
#define PTCL_TX_RECORD_PKTID_ERR_SER_EN SER_ENABLE
// bit[24]
#define PTCL_TX_SPF_U3_PKTID_ERR_SER_EN SER_DISABLE
// bit[25]
#define PTCL_TX_SPF_U2_PKTID_ERR_SER_EN SER_DISABLE
// bit[26]
#define PTCL_TX_SPF_U1_PKTID_ERR_SER_EN SER_DISABLE
// bit[27]
#define PTCL_TX_SPF_U0_PKTID_ERR_SER_EN SER_DISABLE
// bit[28]
#define PTCL_F2PCMD_USER_ALLC_ERR_SER_EN SER_ENABLE
// bit[29]
#define PTCL_F2PCMD_ASSIGN_PKTID_ERR_SER_EN SER_DISABLE
// bit[30]
#define PTCL_F2PCMD_RD_PKTID_ERR_SER_EN SER_DISABLE
// bit[31]
#define PTCL_F2PCMD_PKTID_ERR_SER_EN SER_DISABLE

/*-------------------- Scheduler IMR ------------------------------------*/
// 0xC3E8 : 0x00000000
// bit[0]
#define SCHEDULER_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[1]
#define SCHEDULER_SORT_NON_IDLE_ERR_SER_EN SER_DISABLE

/*-------------------- PHY INTF IMR --------------------------------------*/
// 0xCCFE : 0x0000
// bit[0]
#define PHYINTF_PHY_TXON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[1]
#define PHYINTF_CCK_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[2]
#define PHYINTF_OFDM_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[3]
#define PHYINTF_DATA_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[4]
#define PHYINTF_STS_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[5]
#define PHYINTF_CSI_ON_TIMEOUT_ERR_SER_EN SER_DISABLE

/*-------------------- RMAC IMR -----------------------------------------*/
// 0xCEF6
// bit[4]
#define RMAC_CCA_TO_RX_IDLE_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[5]
#define RMAC_DATA_ON_TO_RX_IDLE_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[6]
#define RMAC_DMA_WRITE_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[7]
#define RMAC_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[8]
#define RMAC_DATA_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[9]
#define RMAC_CSI_DATA_ON_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[10]
#define RMAC_RX_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[11]
#define RMAC_CSI_MODE_TIMEOUT_ERR_SER_EN SER_ENABLE

/*-------------------- TMAC IMR -----------------------------------------*/
// 0xCCEC
// bit[7]
#define TMAC_MACTX_TIME_ERR_SER_EN SER_ENABLE
// bit[8]
#define TMAC_TRXPTCL_TXCTL_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[9]
#define TMAC_RESPONSE_TXCTL_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[10]
#define TMAC_TX_PLCP_INFO_ERR_SER_EN SER_ENABLE

#elif defined(PHL_FEATURE_STA)
/*--------------------CMAC ERROR ----------------------------------------*/
/*--------------------CMAC DMA IMR --------------------------------------*/
// 0xC800
// bit[14]
#define CMAC_DMA_RXSTS_FSM_HANG_SER_EN SER_ENABLE
// bit[15]
#define CMAC_DMA_RXDATA_FSM_HANG_SER_EN SER_DISABLE
// bit[23]
#define CMAC_DMA_NO_RSVD_PAGE_SER_EN SER_DISABLE
// 0xC828
// bit[31]
#define CMAC_DMA_RXDATA_SUBFSM_HANG_SER_EN SER_ENABLE

/*-------------------- PTCL IMR -----------------------------------------*/
// 0xC6C0
// bit[0]
#define PTCL_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[8]
#define PTCL_F2PCMDRPT_FULL_DROP_SER_EN SER_DISABLE
// bit[9]
#define PTCL_TXRPT_FULL_DROP_SER_EN SER_DISABLE
// bit[10]
#define PTCL_D_PKTID_ERR_SER_EN SER_DISABLE
// bit[11]
#define PTCL_Q_PKTID_ERR_SER_EN SER_DISABLE
// bit[12]
#define PTCL_BCNQ_ORDER_ERR_SER_EN SER_DISABLE
// bit[14]
#define PTCL_TWTSP_QSEL_ERR_SER_EN SER_DISABLE
// bit[15]
#define PTCL_F2PCMD_EMPTY_ERR_SER_EN SER_DISABLE
// bit[23]
#define PTCL_TX_RECORD_PKTID_ERR_SER_EN SER_ENABLE
// bit[24]
#define PTCL_TX_SPF_U3_PKTID_ERR_SER_EN SER_DISABLE
// bit[25]
#define PTCL_TX_SPF_U2_PKTID_ERR_SER_EN SER_DISABLE
// bit[26]
#define PTCL_TX_SPF_U1_PKTID_ERR_SER_EN SER_DISABLE
// bit[27]
#define PTCL_TX_SPF_U0_PKTID_ERR_SER_EN SER_DISABLE
// bit[28]
#define PTCL_F2PCMD_USER_ALLC_ERR_SER_EN SER_ENABLE
// bit[29]
#define PTCL_F2PCMD_ASSIGN_PKTID_ERR_SER_EN SER_DISABLE
// bit[30]
#define PTCL_F2PCMD_RD_PKTID_ERR_SER_EN SER_DISABLE
// bit[31]
#define PTCL_F2PCMD_PKTID_ERR_SER_EN SER_DISABLE

/*-------------------- Scheduler IMR ------------------------------------*/
// 0xC3E8 : 0x00000000
// bit[0]
#define SCHEDULER_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[1]
#define SCHEDULER_SORT_NON_IDLE_ERR_SER_EN SER_DISABLE

/*-------------------- PHY INTF IMR --------------------------------------*/
// 0xCCFE : 0x0000
// bit[0]
#define PHYINTF_PHY_TXON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[1]
#define PHYINTF_CCK_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[2]
#define PHYINTF_OFDM_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[3]
#define PHYINTF_DATA_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[4]
#define PHYINTF_STS_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[5]
#define PHYINTF_CSI_ON_TIMEOUT_ERR_SER_EN SER_DISABLE

/*-------------------- RMAC IMR -----------------------------------------*/
// 0xCEF6
// bit[4]
#define RMAC_CCA_TO_RX_IDLE_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[5]
#define RMAC_DATA_ON_TO_RX_IDLE_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[6]
#define RMAC_DMA_WRITE_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[7]
#define RMAC_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[8]
#define RMAC_DATA_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[9]
#define RMAC_CSI_DATA_ON_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[10]
#define RMAC_RX_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[11]
#define RMAC_CSI_MODE_TIMEOUT_ERR_SER_EN SER_ENABLE

/*-------------------- TMAC IMR -----------------------------------------*/
// 0xCCEC
// bit[7]
#define TMAC_MACTX_TIME_ERR_SER_EN SER_ENABLE
// bit[8]
#define TMAC_TRXPTCL_TXCTL_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[9]
#define TMAC_RESPONSE_TXCTL_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[10]
#define TMAC_TX_PLCP_INFO_ERR_SER_EN SER_ENABLE

#else
/*--------------------CMAC ERROR ----------------------------------------*/
/*--------------------CMAC DMA IMR --------------------------------------*/
// 0xC800
// bit[14]
#define CMAC_DMA_RXSTS_FSM_HANG_SER_EN SER_ENABLE
// bit[15]
#define CMAC_DMA_RXDATA_FSM_HANG_SER_EN SER_DISABLE
// bit[23]
#define CMAC_DMA_NO_RSVD_PAGE_SER_EN SER_DISABLE
// 0xC828
// bit[31]
#define CMAC_DMA_RXDATA_SUBFSM_HANG_SER_EN SER_ENABLE

/*-------------------- PTCL IMR -----------------------------------------*/
// 0xC6C0
// bit[0]
#define PTCL_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[8]
#define PTCL_F2PCMDRPT_FULL_DROP_SER_EN SER_DISABLE
// bit[9]
#define PTCL_TXRPT_FULL_DROP_SER_EN SER_DISABLE
// bit[10]
#define PTCL_D_PKTID_ERR_SER_EN SER_DISABLE
// bit[11]
#define PTCL_Q_PKTID_ERR_SER_EN SER_DISABLE
// bit[12]
#define PTCL_BCNQ_ORDER_ERR_SER_EN SER_DISABLE
// bit[14]
#define PTCL_TWTSP_QSEL_ERR_SER_EN SER_DISABLE
// bit[15]
#define PTCL_F2PCMD_EMPTY_ERR_SER_EN SER_DISABLE
// bit[23]
#define PTCL_TX_RECORD_PKTID_ERR_SER_EN SER_ENABLE
// bit[24]
#define PTCL_TX_SPF_U3_PKTID_ERR_SER_EN SER_DISABLE
// bit[25]
#define PTCL_TX_SPF_U2_PKTID_ERR_SER_EN SER_DISABLE
// bit[26]
#define PTCL_TX_SPF_U1_PKTID_ERR_SER_EN SER_DISABLE
// bit[27]
#define PTCL_TX_SPF_U0_PKTID_ERR_SER_EN SER_DISABLE
// bit[28]
#define PTCL_F2PCMD_USER_ALLC_ERR_SER_EN SER_ENABLE
// bit[29]
#define PTCL_F2PCMD_ASSIGN_PKTID_ERR_SER_EN SER_DISABLE
// bit[30]
#define PTCL_F2PCMD_RD_PKTID_ERR_SER_EN SER_DISABLE
// bit[31]
#define PTCL_F2PCMD_PKTID_ERR_SER_EN SER_DISABLE

/*-------------------- Scheduler IMR ------------------------------------*/
// 0xC3E8 : 0x00000000
// bit[0]
#define SCHEDULER_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[1]
#define SCHEDULER_SORT_NON_IDLE_ERR_SER_EN SER_DISABLE

/*-------------------- PHY INTF IMR --------------------------------------*/
// 0xCCFE : 0x0000
// bit[0]
#define PHYINTF_PHY_TXON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[1]
#define PHYINTF_CCK_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[2]
#define PHYINTF_OFDM_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[3]
#define PHYINTF_DATA_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[4]
#define PHYINTF_STS_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[5]
#define PHYINTF_CSI_ON_TIMEOUT_ERR_SER_EN SER_DISABLE

/*-------------------- RMAC IMR -----------------------------------------*/
// 0xCEF6
// bit[4]
#define RMAC_CCA_TO_RX_IDLE_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[5]
#define RMAC_DATA_ON_TO_RX_IDLE_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[6]
#define RMAC_DMA_WRITE_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[7]
#define RMAC_CCA_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[8]
#define RMAC_DATA_ON_TIMEOUT_ERR_SER_EN SER_DISABLE
// bit[9]
#define RMAC_CSI_DATA_ON_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[10]
#define RMAC_RX_FSM_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[11]
#define RMAC_CSI_MODE_TIMEOUT_ERR_SER_EN SER_ENABLE

/*-------------------- TMAC IMR -----------------------------------------*/
// 0xCCEC
// bit[7]
#define TMAC_MACTX_TIME_ERR_SER_EN SER_ENABLE
// bit[8]
#define TMAC_TRXPTCL_TXCTL_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[9]
#define TMAC_RESPONSE_TXCTL_TIMEOUT_ERR_SER_EN SER_ENABLE
// bit[10]
#define TMAC_TX_PLCP_INFO_ERR_SER_EN SER_ENABLE
#endif

//WDRLS 0x9430
//bit[0]
#define DMAC_WDRLS_CTL_WDPKTID_ISNULL_ERR_SER_EN SER_ENABLE
//bit[1]
#define DMAC_WDRLS_CTL_PLPKTID_ISNULL_ERR_SER_EN SER_ENABLE
//bit[2]
#define DMAC_WDRLS_CTL_FRZTO_ERR_SER_EN SER_ENABLE
//bit[4]
#define DMAC_WDRLS_PLEBREQ_TO_ERR_SER_EN SER_DISABLE
//bit[5]
#define DMAC_WDRLS_PLEBREQ_PKTID_ISNULL_ERR_SER_EN SER_ENABLE
//bit[8]
#define DMAC_WDRLS_RPT0_AGGNUM0_ERR_SER_EN SER_ENABLE
//bit[9]
#define DMAC_WDRLS_RPT0_FRZTO_ERR_SER_EN SER_ENABLE
//bit[12]
#define DMAC_WDRLS_RPT1_AGGNUM0_ERR_SER_EN SER_ENABLE
//bit[13]
#define DMAC_WDRLS_RPT1_FRZTO_ERR_SER_EN SER_ENABLE

//SEC_DEBUG 0x9D1C
//bit[3]
#define DMAC_IMR_ERROR SER_ENABLE

//MPDU_TX_ERR_IMR 0x9BF4
//bit[1]
#define DMAC_TX_GET_ERRPKTID_SER_EN SER_DISABLE
//bit[2]
#define DMAC_TX_NXT_ERRPKTID_SER_EN SER_DISABLE
//bit[3]
#define DMAC_TX_MPDU_SIZE_ZERO_SER_EN SER_DISABLE
//bit[4]
#define DMAC_TX_OFFSET_ERR_SER_EN SER_DISABLE
//bit[5]
#define DMAC_TX_HDR3_SIZE_ERR_SER_EN SER_DISABLE

//MPDU_RX_ERR_IMR 0x9CF4
//bit[0]
#define DMAC_GETPKTID_ERR_SER_EN SER_DISABLE
//bit[1]
#define DMAC_MHDRLEN_ERR_SER_EN SER_DISABLE
//bit[3]
#define DMAC_RPT_ERR_SER_EN SER_DISABLE

//STA_SCHEDULER_ERR_IMR 0x9EF0
//bit[0]
#define DMAC_SEARCH_HANG_TIMEOUT_SER_EN SER_ENABLE
//bit[1]
#define DMAC_RPT_HANG_TIMEOUT_SER_EN SER_ENABLE
//bit[2]
#define DMAC_PLE_B_PKTID_ERR_SER_EN SER_ENABLE

//TXPKTCTL_ERR_IMR_ISR 0x9F1C
//bit[0]
#define DMAC_TXPKTCTL_USRCTL_REINIT_ERR_SER_EN SER_ENABLE
//bit[1]
#define DMAC_TXPKTCTL_USRCTL_NOINIT_ERR_SER_EN SER_DISABLE
//bit[2]
#define DMAC_TXPKTCTL_USRCTL_RDNRLSCMD_ERR_SER_EN SER_DISABLE
//bit[3]
#define DMAC_TXPKTCTL_USRCTL_RLSBMPLEN_ERR_SER_EN SER_DISABLE
//bit[8]
#define DMAC_TXPKTCTL_CMDPSR_CMDTYPE_ERR_SER_EN SER_ENABLE
//bit[9]
#define DMAC_TXPKTCTL_CMDPSR_FRZTO_ERR_SER_EN SER_DISABLE

//TXPKTCTL_ERR_IMR_ISR_B1 0x9F2C
//bit[0]
#define DMAC_TXPKTCTL_USRCTL_REINIT_B1_ERR_SER_EN SER_ENABLE
//bit[1]
#define DMAC_TXPKTCTL_USRCTL_NOINIT_B1_ERR_SER_EN SER_ENABLE
//bit[2]
#define DMAC_TXPKTCTL_USRCTL_RDNRLSCMD_B1_ERR_SER_EN SER_DISABLE
//bit[3]
#define DMAC_TXPKTCTL_USRCTL_RLSBMPLEN_B1_ERR_SER_EN SER_DISABLE
//bit[8]
#define DMAC_TXPKTCTL_CMDPSR_CMDTYPE_ERR_B1_SER_EN SER_ENABLE
//bit[9]
#define DMAC_TXPKTCTL_CMDPSR_FRZTO_ERR_B1_SER_EN SER_ENABLE

//WDE_ERR_IMR 0x8C38
//bit[0]
#define DMAC_WDE_BUFREQ_QTAID_ERR_SER_EN SER_ENABLE
//bit[1]
#define DMAC_WDE_BUFREQ_UNAVAL_ERR_SER_EN SER_ENABLE
//bit[2]
#define DMAC_WDE_BUFRTN_INVLD_PKTID_ERR_SER_EN SER_ENABLE
//bit[3]
#define DMAC_WDE_BUFRTN_SIZE_ERR_SER_EN SER_ENABLE
//bit[4]
#define DMAC_WDE_BUFREQ_SRCHTAILPG_ERR_SER_EN SER_ENABLE
//bit[5]
#define DMAC_WDE_GETNPG_STRPG_ERR_SER_EN SER_ENABLE
//bit[6]
#define DMAC_WDE_GETNPG_PGOFST_ERR_SER_EN SER_ENABLE
//bit[7]
#define DMAC_WDE_BUFMGN_FRZTO_ERR_SER_EN SER_ENABLE
//bit[12]
#define DMAC_WDE_QUE_CMDTYPE_ERR_SER_EN SER_ENABLE
//bit[13]
#define DMAC_WDE_QUE_DSTQUEID_ERR_SER_EN SER_ENABLE
//bit[14]
#define DMAC_WDE_QUE_SRCQUEID_ERR_SER_EN SER_ENABLE
//bit[15]
#define DMAC_WDE_ENQ_PKTCNT_OVRF_ERR_SER_EN SER_ENABLE
//bit[16]
#define DMAC_WDE_ENQ_PKTCNT_NVAL_ERR_SER_EN SER_ENABLE
//bit[17]
#define DMAC_WDE_PREPKTLLT_AD_ERR_SER_EN SER_ENABLE
//bit[18]
#define DMAC_WDE_NXTPKTLL_AD_ERR_SER_EN SER_ENABLE
//bit[19]
#define DMAC_WDE_QUEMGN_FRZTO_ERR_SER_EN SER_ENABLE
//bit[24]
#define DMAC_WDE_DATCHN_ARBT_ERR_SER_EN SER_ENABLE
//bit[25]
#define DMAC_WDE_DATCHN_NULLPG_ERR_SER_EN SER_ENABLE
//bit[26]
#define DMAC_WDE_DATCHN_FRZTO_ERR_SER_EN SER_ENABLE

//PLE_ERR_IMR 0x9038
//bit[0]
#define DMAC_PLE_BUFREQ_QTAID_ERR_SER_EN SER_ENABLE
//bit[1]
#define DMAC_PLE_BUFREQ_UNAVAL_ERR_SER_EN SER_ENABLE
//bit[2]
#define DMAC_PLE_BUFRTN_INVLD_PKTID_ERR_SER_EN SER_ENABLE
//bit[3]
#define DMAC_PLE_BUFRTN_SIZE_ERR_SER_EN SER_ENABLE
//bit[4]
#define DMAC_PLE_BUFREQ_SRCHTAILPG_ERR_SER_EN SER_ENABLE
//bit[5]
#define DMAC_PLE_GETNPG_STRPG_ERR_SER_EN SER_DISABLE
//bit[6]
#define DMAC_PLE_GETNPG_PGOFST_ERR_SER_EN SER_ENABLE
//bit[7]
#define DMAC_PLE_BUFMGN_FRZTO_ERR_SER_EN SER_ENABLE
//bit[12]
#define DMAC_PLE_QUE_CMDTYPE_ERR_SER_EN SER_ENABLE
//bit[13]
#define DMAC_PLE_QUE_DSTQUEID_ERR_SER_EN SER_ENABLE
//bit[14]
#define DMAC_PLE_QUE_SRCQUEID_ERR_SER_EN SER_ENABLE
//bit[15]
#define DMAC_PLE_ENQ_PKTCNT_OVRF_ERR_SER_EN SER_ENABLE
//bit[16]
#define DMAC_PLE_ENQ_PKTCNT_NVAL_ERR_SER_EN SER_ENABLE
//bit[17]
#define DMAC_PLE_PREPKTLLT_AD_ERR_SER_EN SER_ENABLE
//bit[18]
#define DMAC_PLE_NXTPKTLL_AD_ERR_SER_EN SER_ENABLE
//bit[19]
#define DMAC_PLE_QUEMGN_FRZTO_ERR_SER_EN SER_ENABLE
//bit[24]
#define DMAC_PLE_DATCHN_ARBT_ERR_SER_EN SER_ENABLE
//bit[25]
#define DMAC_PLE_DATCHN_NULLPG_ERR_SER_EN SER_ENABLE
//bit[26]
#define DMAC_PLE_DATCHN_FRZTO_ERR_SER_EN SER_ENABLE

//PKTIN_ERR_IMR 0x9A20
//bit[0]
#define DMAC_PKTIN_GETPKTID_ERR_SER_EN SER_ENABLE

//HOST_DISPATCHER_ERR_IMR 0x8850
//bit[0]
#define DMAC_HDT_CHANNEL_DIFF_ERR_SER_EN SER_ENABLE
//bit[1]
#define DMAC_HDT_CHANNEL_ID_ERR_SER_EN SER_DISABLE
//bit[2]
#define DMAC_HDT_PKT_FAIL_DBG_SER_EN SER_DISABLE
//bit[3]
#define DMAC_HDT_PERMU_OVERFLOW_SER_EN SER_DISABLE
//bit[4]
#define DMAC_HDT_PERMU_UNDERFLOW_SER_EN SER_DISABLE
//bit[5]
#define DMAC_HDT_PAYLOAD_OVERFLOW_SER_EN SER_ENABLE
//bit[6]
#define DMAC_HDT_PAYLOAD_UNDERFLOW_SER_EN SER_ENABLE
//bit[7]
#define DMAC_HDT_OFFSET_UNMATCH_SER_EN SER_DISABLE
//bit[8]
#define DMAC_HDT_CHANNEL_DMA_ERR_SER_EN SER_ENABLE
//bit[9]
#define DMAC_HDT_WD_CHK_ERR_SER_EN SER_DISABLE
//bit[10]
#define DMAC_HDT_PRE_COST_ERR_SER_EN SER_DISABLE
//bit[11]
#define DMAC_HDT_TXPKTSIZE_ERR_SER_EN SER_DISABLE
//bit[12]
#define DMAC_HDT_TCP_CHK_ERR_SER_EN SER_DISABLE
//bit[13]
#define DMAC_HDT_TX_WRITE_OVERFLOW_SER_EN SER_DISABLE
//bit[14]
#define DMAC_HDT_TX_WRITE_UNDERFLOW_SER_EN SER_DISABLE
//bit[15]
#define DMAC_HDT_PLD_CMD_OVERLOW_SER_EN SER_DISABLE
//bit[16]
#define DMAC_HDT_PLD_CMD_UNDERFLOW_SER_EN SER_DISABLE
//bit[17]
#define DMAC_HDT_FLOW_CTRL_ERR_SER_EN SER_DISABLE
//bit[18]
#define DMAC_HDT_NULLPKT_ERR_SER_EN SER_DISABLE
//bit[19]
#define DMAC_HDT_BURST_NUM_ERR_SER_EN SER_DISABLE
//bit[24]
#define DMAC_HDT_RXAGG_CFG_ERR_SER_EN SER_DISABLE
//bit[25]
#define DMAC_HDT_SHIFT_EN_ERR_SER_EN SER_DISABLE
//bit[26]
#define DMAC_HDT_TOTAL_LEN_ERR_SER_EN SER_ENABLE
//bit[27]
#define DMAC_HDT_DMA_PROCESS_ERR_SER_EN SER_ENABLE
//bit[28]
#define DMAC_HDT_SHIFT_DMA_CFG_ERR_SER_EN SER_DISABLE
//bit[29]
#define DMAC_HDT_CHKSUM_FSM_ERR_SER_EN SER_DISABLE
//bit[30]
#define DMAC_HDT_RX_WRITE_OVERFLOW_SER_EN SER_DISABLE
//bit[31]
#define DMAC_HDT_RX_WRITE_UNDERFLOW_SER_EN SER_DISABLE

//CPU_DISPATCHER_ERR_IMR 0x8854
//bit[0]
#define DMAC_CPU_CHANNEL_DIFF_ERR_SER_EN SER_DISABLE
//bit[1]
#define DMAC_CPU_PKT_FAIL_DBG_SER_EN SER_ENABLE
//bit[2]
#define DMAC_CPU_CHANNEL_ID_ERR_SER_EN SER_DISABLE
//bit[3]
#define DMAC_CPU_PERMU_OVERFLOW_SER_EN SER_DISABLE
//bit[4]
#define DMAC_CPU_PERMU_UNDERFLOW_SER_EN SER_DISABLE
//bit[5]
#define DMAC_CPU_PAYLOAD_OVERFLOW_SER_EN SER_ENABLE
//bit[6]
#define DMAC_CPU_PAYLOAD_UNDERFLOW_SER_EN SER_ENABLE
//bit[7]
#define DMAC_CPU_PAYLOAD_CHKSUM_ERR_SER_EN SER_DISABLE
//bit[8]
#define DMAC_CPU_OFFSET_UNMATCH_SER_EN SER_DISABLE
//bit[9]
#define DMAC_CPU_CHANNEL_DMA_ERR_SER_EN SER_DISABLE
//bit[10]
#define DMAC_CPU_WD_CHK_ERR_SER_EN SER_DISABLE
//bit[11]
#define DMAC_CPU_PRE_COST_ERR_SER_EN SER_DISABLE
//bit[12]
#define DMAC_CPU_PLD_CMD_OVERLOW_SER_EN SER_DISABLE
//bit[13]
#define DMAC_CPU_PLD_CMD_UNDERFLOW_SER_EN SER_DISABLE
//bit[14]
#define DMAC_CPU_F2P_QSEL_ERR_SER_EN SER_DISABLE
//bit[15]
#define DMAC_CPU_F2P_SEQ_ERR_SER_EN SER_DISABLE
//bit[16]
#define DMAC_CPU_FLOW_CTRL_ERR_SER_EN SER_DISABLE
//bit[17]
#define DMAC_CPU_NULLPKT_ERR_SER_EN SER_DISABLE
//bit[18]
#define DMAC_CPU_BURST_NUM_ERR_SER_EN SER_DISABLE
//bit[24]
#define DMAC_CPU_RXAGG_CFG_ERR_SER_EN SER_DISABLE
//bit[25]
#define DMAC_CPU_SHIFT_EN_ERR_SER_EN SER_DISABLE
//bit[26]
#define DMAC_CPU_TOTAL_LEN_ERR_SER_EN SER_ENABLE
//bit[27]
#define DMAC_CPU_DMA_PROCESS_ERR_SER_EN SER_DISABLE
//bit[28]
#define DMAC_CPU_SHIFT_DMA_CFG_ERR_SER_EN SER_DISABLE
//bit[29]
#define DMAC_CPU_CHKSUM_FSM_ERR_SER_EN SER_DISABLE

//OTHER_DISPATCHER_ERR_IMR 0x8858
//bit[0]
#define DMAC_WDE_FLOW_CTRL_ERR_SER_EN SER_DISABLE
//bit[1]
#define DMAC_WDE_NULL_PKT_ERR_SER_EN SER_DISABLE
//bit[2]
#define DMAC_WDE_BURST_NUM_ERR_SER_EN SER_DISABLE
//bit[3]
#define DMAC_WDE_RESP_ERR_SER_EN SER_DISABLE
//bit[4]
#define DMAC_WDE_OUTPUT_ERR_SER_EN SER_DISABLE
//bit[8]
#define DMAC_PLE_FLOW_CTRL_ERR_SER_EN SER_DISABLE
//bit[9]
#define DMAC_PLE_NULL_PKT_ERR_SER_EN SER_DISABLE
//bit[10]
#define DMAC_PLE_BURST_NUM_ERR_SER_EN SER_DISABLE
//bit[11]
#define DMAC_PLE_RESP_ERR_SER_EN SER_DISABLE
//bit[12]
#define DMAC_PLE_OUTPUT_ERR_SER_EN SER_DISABLE
//bit[16]
#define DMAC_CPU_ADDR_INFO_LEN_ZERO_ERR_SER_EN SER_DISABLE
//bit[17]
#define DMAC_HOST_ADDR_INFO_LEN_ZERO_ERR_SER_EN SER_DISABLE
//bit[24]
#define DMAC_OTHER_STF_CMD_OVERFLOW_SER_EN SER_DISABLE
//bit[25]
#define DMAC_OTHER_STF_CMD_UNDERFLOW_SER_EN SER_DISABLE
//bit[26]
#define DMAC_OTHER_STF_WRFF_OVERFLOW_SER_EN SER_DISABLE
//bit[27]
#define DMAC_OTHER_STF_WRFF_UNDERFLOW_SER_EN SER_DISABLE
//bit[28]
#define DMAC_OTHER_STF_WROQT_OVERFLOW_SER_EN SER_DISABLE
//bit[29]
#define DMAC_OTHER_STF_WROQT_UNDERFLOW_SER_EN SER_DISABLE

//CPUIO_ERR_IMR 0x9840
//bit[0]
#define DMAC_WDEBUF_OP_ERR_SER_EN SER_ENABLE
//bit[4]
#define DMAC_WDEQUE_OP_ERR_SER_EN SER_ENABLE
//bit[8]
#define DMAC_PLEBUF_OP_ERR_SER_EN SER_ENABLE
//bit[12]
#define DMAC_PLEQUE_OP_ERR_SER_EN SER_ENABLE

//BBRPT_COM_ERR_IMR_ISR 0x960C
//bit[0]
#define DMAC_BBRPT_COM_NULL_PLPKTID_ERR_SER_EN SER_ENABLE

//BBRPT_CHINFO_ERR_IMR_ISR 0x962C
//bit[0]
#define DMAC_BBPRT_CHIF_BB_TO_ERR_SER_EN SER_DISABLE
//bit[1]
#define DMAC_BBPRT_CHIF_OVF_ERR_SER_EN SER_DISABLE
//bit[2]
#define DMAC_BBPRT_CHIF_BOVF_ERR_SER_EN SER_DISABLE
//bit[3]
#define DMAC_BBPRT_CHIF_HDRL_ERR_SER_EN SER_DISABLE
//bit[4]
#define DMAC_BBPRT_CHIF_LEFT1_ERR_SER_EN SER_DISABLE
//bit[5]
#define DMAC_BBPRT_CHIF_LEFT2_ERR_SER_EN SER_DISABLE
//bit[6]
#define DMAC_BBPRT_CHIF_NULL_ERR_SER_EN SER_DISABLE
//bit[7]
#define DMAC_BBPRT_CHIF_TO_ERR_SER_EN SER_DISABLE

//BBRPT_DFS_ERR_IMR_ISR 0x963C
//bit[0]
#define DMAC_BBRPT_DFS_TO_ERR_SER_EN SER_ENABLE

//LA_ERRFLAG 0x966C
//bit[0]
#define DMAC_LA_IMR_DATA_LOSS_ERR SER_ENABLE

/*--------------------Define -------------------------------------------*/
#define MAC_SET_ERR_DLY_CNT 200
#define MAC_SET_ERR_DLY_US 50

#define DMAC_ERR_IMR_MASK 0xFFFFFFFF
#define DMAC_ERR_IMR_EN 0xFFFFFFFF
#define CMAC0_ERR_IMR_MASK 0xFFFFFFFF
#define CMAC0_ERR_IMR_EN 0xFFFFFFFF
#define CMAC1_ERR_IMR_MASK 0xFFFFFFFF
#define CMAC1_ERR_IMR_EN 0xFFFFFFFF
#define DMAC_ERR_IMR_DIS 0
#define CMAC0_ERR_IMR_DIS 0
#define CMAC1_ERR_IMR_DIS 0

#define FW_ST_MSK 0xFFFF
#define FW_ST_SH 8
#define FW_ST_ERR_IN 0x11

#define MAC_SER_STOP_DLY_CNT 200
#define MAC_SER_STOP_DLY_US 50

/*--------------------Define Enum---------------------------------------*/
enum WCPU_ERR_SCENARIO {
	RXI300_ERROR = 1,
	CPU_EXCEPTION  = 2,
	ASSERTION  = 3,
	WDT_ALARM = 4,
};

/*--------------------Define MACRO--------------------------------------*/
/*--------------------Define Struct-------------------------------------*/
/*--------------------Function declaration------------------------------*/
u32 mac_trigger_cmac_err(struct mac_ax_adapter *adapter);
u32 mac_trigger_cmac1_err(struct mac_ax_adapter *adapter);
u32 mac_trigger_dmac_err(struct mac_ax_adapter *adapter);

u32 mac_dump_err_status(struct mac_ax_adapter *adapter,
			enum mac_ax_err_info err);
u32 mac_set_err_status(struct mac_ax_adapter *adapter,
		       enum mac_ax_err_info err);
u32 mac_get_err_status(struct mac_ax_adapter *adapter,
		       enum mac_ax_err_info *err);

u32 mac_lv1_rcvy(struct mac_ax_adapter *adapter,
		 enum mac_ax_lv1_rcvy_step step);

u32 mac_err_imr_ctrl(struct mac_ax_adapter *adapter, enum mac_ax_func_sw sw);
u32 mac_ser_ctrl(struct mac_ax_adapter *adapter, enum mac_ax_func_sw sw);

#endif
