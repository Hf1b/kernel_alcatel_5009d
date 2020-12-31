

#ifndef _MT_SPM_REG_
#define _MT_SPM_REG_

#include "sleep_def.h"
#include "pcm_def.h"


#define POWERON_CONFIG_EN              (SPM_BASE + 0x0000)
#define SPM_POWER_ON_VAL0              (SPM_BASE + 0x0004)
#define SPM_POWER_ON_VAL1              (SPM_BASE + 0x0008)
#define SPM_CLK_CON                    (SPM_BASE + 0x000C)
#define SPM_CLK_SETTLE                 (SPM_BASE + 0x0010)
#define SPM_AP_STANDBY_CON             (SPM_BASE + 0x0014)
#define PCM_CON0                       (SPM_BASE + 0x0018)
#define PCM_CON1                       (SPM_BASE + 0x001C)
#define PCM_IM_PTR                     (SPM_BASE + 0x0020)
#define PCM_IM_LEN                     (SPM_BASE + 0x0024)
#define PCM_REG_DATA_INI               (SPM_BASE + 0x0028)
#define PCM_PWR_IO_EN                  (SPM_BASE + 0x002C)
#define PCM_TIMER_VAL                  (SPM_BASE + 0x0030)
#define PCM_WDT_VAL                    (SPM_BASE + 0x0034)
#define PCM_IM_HOST_RW_PTR             (SPM_BASE + 0x0038)
#define PCM_IM_HOST_RW_DAT             (SPM_BASE + 0x003C)
#define PCM_EVENT_VECTOR0              (SPM_BASE + 0x0040)
#define PCM_EVENT_VECTOR1              (SPM_BASE + 0x0044)
#define PCM_EVENT_VECTOR2              (SPM_BASE + 0x0048)
#define PCM_EVENT_VECTOR3              (SPM_BASE + 0x004C)
#define PCM_EVENT_VECTOR4              (SPM_BASE + 0x0050)
#define PCM_EVENT_VECTOR5              (SPM_BASE + 0x0054)
#define PCM_EVENT_VECTOR6              (SPM_BASE + 0x0058)
#define PCM_EVENT_VECTOR7              (SPM_BASE + 0x005C)
#define PCM_EVENT_VECTOR8              (SPM_BASE + 0x0060)
#define PCM_EVENT_VECTOR9              (SPM_BASE + 0x0064)
#define PCM_EVENT_VECTOR10             (SPM_BASE + 0x0068)
#define PCM_EVENT_VECTOR11             (SPM_BASE + 0x006C)
#define PCM_EVENT_VECTOR12             (SPM_BASE + 0x0070)
#define PCM_EVENT_VECTOR13             (SPM_BASE + 0x0074)
#define PCM_EVENT_VECTOR14             (SPM_BASE + 0x0078)
#define PCM_EVENT_VECTOR15             (SPM_BASE + 0x007C)
#define PCM_EVENT_VECTOR_EN            (SPM_BASE + 0x0080)
#define SPM_MD32_IRQ                   (SPM_BASE + 0x0094)
#define SPM_SCP_IRQ                    (SPM_BASE + 0x009C)
#define SPM_TWAM_CON                   (SPM_BASE + 0x00A0)
#define SPM_TWAM_WINDOW_LEN            (SPM_BASE + 0x00A4)
#define SPM_TWAM_IDLE_SEL              (SPM_BASE + 0x00A8)
#define SPM_CPU_WAKEUP_EVENT           (SPM_BASE + 0x00B0)
#define SPM_IRQ_MASK                   (SPM_BASE + 0x00B4)
#define SPM_SRC_REQ                    (SPM_BASE + 0x00B8)
#define SPM_SRC_MASK                   (SPM_BASE + 0x00BC)
#define SPM_SRC2_MASK                  (SPM_BASE + 0x00C0)
#define SPM_WAKEUP_EVENT_MASK          (SPM_BASE + 0x00C4)
#define SPM_EXT_WAKEUP_EVENT_MASK      (SPM_BASE + 0x00C8)
#define SCP_CLK_CON                    (SPM_BASE + 0x00D0)
#define PCM_DEBUG_CON                  (SPM_BASE + 0x00D4)
#define DDR_EN_DBC_LEN                 (SPM_BASE + 0x00D8)
#define PCM_REG0_DATA                  (SPM_BASE + 0x0100)
#define PCM_REG1_DATA                  (SPM_BASE + 0x0104)
#define PCM_REG2_DATA                  (SPM_BASE + 0x0108)
#define PCM_REG3_DATA                  (SPM_BASE + 0x010C)
#define PCM_REG4_DATA                  (SPM_BASE + 0x0110)
#define PCM_REG5_DATA                  (SPM_BASE + 0x0114)
#define PCM_REG6_DATA                  (SPM_BASE + 0x0118)
#define PCM_REG7_DATA                  (SPM_BASE + 0x011C)
#define PCM_REG8_DATA                  (SPM_BASE + 0x0120)
#define PCM_REG9_DATA                  (SPM_BASE + 0x0124)
#define PCM_REG10_DATA                 (SPM_BASE + 0x0128)
#define PCM_REG11_DATA                 (SPM_BASE + 0x012C)
#define PCM_REG12_DATA                 (SPM_BASE + 0x0130)
#define PCM_REG13_DATA                 (SPM_BASE + 0x0134)
#define PCM_REG14_DATA                 (SPM_BASE + 0x0138)
#define PCM_REG15_DATA                 (SPM_BASE + 0x013C)
#define PCM_REG12_MASK_B_STA           (SPM_BASE + 0x0140)
#define PCM_REG12_EXT_DATA             (SPM_BASE + 0x0144)
#define PCM_REG12_EXT_MASK_B_STA       (SPM_BASE + 0x0148)
#define PCM_EVENT_REG_STA              (SPM_BASE + 0x014C)
#define PCM_TIMER_OUT                  (SPM_BASE + 0x0150)
#define PCM_WDT_OUT                    (SPM_BASE + 0x0154)
#define SPM_IRQ_STA                    (SPM_BASE + 0x0158)
#define SPM_WAKEUP_STA                 (SPM_BASE + 0x015C)
#define SPM_WAKEUP_EXT_STA             (SPM_BASE + 0x0160)
#define SPM_WAKEUP_MISC                (SPM_BASE + 0x0164)
#define BUS_PROTECT_RDY                (SPM_BASE + 0x0168)
#define BUS_PROTECT2_RDY               (SPM_BASE + 0x016C)
#define SUBSYS_IDLE_STA                (SPM_BASE + 0x0170)
#define CPU_IDLE_STA                   (SPM_BASE + 0x0174)
#define PCM_FSM_STA                    (SPM_BASE + 0x017C)
#define PWR_STATUS                     (SPM_BASE + 0x0180)
#define PWR_STATUS_2ND                 (SPM_BASE + 0x0184)
#define CPU_PWR_STATUS                 (SPM_BASE + 0x0188)
#define CPU_PWR_STATUS_2ND             (SPM_BASE + 0x018C)
#define PCM_WDT_LATCH_0                (SPM_BASE + 0x0190)
#define PCM_WDT_LATCH_1                (SPM_BASE + 0x0194)
#define PCM_WDT_LATCH_2                (SPM_BASE + 0x0198)
#define SPM_TWAM_LAST_STA0             (SPM_BASE + 0x01A0)
#define SPM_TWAM_LAST_STA1             (SPM_BASE + 0x01A4)
#define SPM_TWAM_LAST_STA2             (SPM_BASE + 0x01A8)
#define SPM_TWAM_LAST_STA3             (SPM_BASE + 0x01AC)
#define SPM_TWAM_CURR_STA0             (SPM_BASE + 0x01B0)
#define SPM_TWAM_CURR_STA1             (SPM_BASE + 0x01B4)
#define SPM_TWAM_CURR_STA2             (SPM_BASE + 0x01B8)
#define SPM_TWAM_CURR_STA3             (SPM_BASE + 0x01BC)
#define SPM_TWAM_TIMER_OUT             (SPM_BASE + 0x01C0)
#define PCM_WDT_LATCH_3                (SPM_BASE + 0x01C4)
#define PCM_WDT_LATCH_4                (SPM_BASE + 0x01C8)
#define SPM_SRC_RDY_STA                (SPM_BASE + 0x01D0)
#define CPU_RET_STATUS                 (SPM_BASE + 0x01E4)
#define EVENT_STATUS_REG               (SPM_BASE + 0x01E8)
#define MCUSYS_PWR_CON                 (SPM_BASE + 0x0200)
#define MP_TOP_PWR_CON                 (SPM_BASE + 0x0204)
#define MP0_CPUTOP_PWR_CON             (SPM_BASE + 0x0210)
#define MP1_CPUTOP_PWR_CON             (SPM_BASE + 0x0214)
#define DEBUGTOP_PWR_CON               (SPM_BASE + 0x0218)
#define MP0_CPU0_PWR_CON               (SPM_BASE + 0x0220)
#define MP0_CPU1_PWR_CON               (SPM_BASE + 0x0224)
#define MP0_CPU2_PWR_CON               (SPM_BASE + 0x0228)
#define MP0_CPU3_PWR_CON               (SPM_BASE + 0x022C)
#define MP1_CPU0_PWR_CON               (SPM_BASE + 0x0230)
#define MP1_CPU1_PWR_CON               (SPM_BASE + 0x0234)
#define MP1_CPU2_PWR_CON               (SPM_BASE + 0x0238)
#define MP1_CPU3_PWR_CON               (SPM_BASE + 0x023C)
#define DEBUG0_PWR_CON                 (SPM_BASE + 0x0240)
#define DEBUG1_PWR_CON                 (SPM_BASE + 0x0244)
#define DEBUG2_PWR_CON                 (SPM_BASE + 0x0248)
#define DEBUG3_PWR_CON                 (SPM_BASE + 0x024C)
#define COMMON_TOP_PWR_ADDR            (SPM_BASE + 0x0250)
#define COMMON_CPU_PWR_ADDR            (SPM_BASE + 0x0254)
#define CPU_EXT_BUCK_ISO               (SPM_BASE + 0x0260)
#define ARMPLL_CLK_CON                 (SPM_BASE + 0x0264)
#define SPMC_DORMANT_ENABLE            (SPM_BASE + 0x026C)
#define SPMC_MISC                      (SPM_BASE + 0x0270)
#define SPMC_MISC2                     (SPM_BASE + 0x0274)
#define BYPASS_SPMC                    (SPM_BASE + 0x0278)
#define CPU_SRAM_DREQ                  (SPM_BASE + 0x0280)
#define CPU_SRAM_DREQ_SET              (SPM_BASE + 0x0284)
#define CPU_SRAM_DREQ_CLR              (SPM_BASE + 0x0288)
#define VDE0_PWR_CON                   (SPM_BASE + 0x0300)
#define VEN_PWR_CON                    (SPM_BASE + 0x0304)
#define ISP_PWR_CON                    (SPM_BASE + 0x0308)
#define CAM_PWR_CON                    (SPM_BASE + 0x030C)
#define DIS0T_PWR_CON                  (SPM_BASE + 0x0310)
#define AUD_PWR_CON                    (SPM_BASE + 0x0314)
#define IFR_PWR_CON                    (SPM_BASE + 0x0318)
#define MJC_PWR_CON                    (SPM_BASE + 0x031C)
#define DPYA_PWR_CON                   (SPM_BASE + 0x0320)
#define DPYB_PWR_CON                   (SPM_BASE + 0x0324)
#define MD1_PWR_CON                    (SPM_BASE + 0x0328)
#define C2K_PWR_CON                    (SPM_BASE + 0x032C)
#define CONN_PWR_CON                   (SPM_BASE + 0x0330)
#define MFG_ASYNC_PWR_CON              (SPM_BASE + 0x0334)
#define MFG_CORE0_PWR_CON              (SPM_BASE + 0x0340)
#define MFG_CORE1_PWR_CON              (SPM_BASE + 0x0344)
#define MFG_CORE2_PWR_CON              (SPM_BASE + 0x0348)
#define MFG_CORE3_PWR_CON              (SPM_BASE + 0x034C)
#define MFG_TOP_PWR_CON                (SPM_BASE + 0x0350)
#define DUMMY0_PWR_CON                 (SPM_BASE + 0x0354)
#define DUMMY1_PWR_CON                 (SPM_BASE + 0x0358)
#define SYSRAM_CON                     (SPM_BASE + 0x0370)
#define SYSROM_CON                     (SPM_BASE + 0x0374)
#define SCP_SRAM_CON                   (SPM_BASE + 0x0378)
#define PMCU_SRAM_CON                  (SPM_BASE + 0x037C)
#define BSI_TOP_SRAM_CON               (SPM_BASE + 0x038C)
#define AUD_ANC_SRAM_CON               (SPM_BASE + 0x0398)
#define EXT_BUCK_ISO                   (SPM_BASE + 0x039C)
#define UFS_SRAM_CON                   (SPM_BASE + 0x03A0)
#define DXCC_SRAM_CON                  (SPM_BASE + 0x03A4)
#define SPM_DVFS_CON                   (SPM_BASE + 0x0400)
#define SPM_MDBSI_CON                  (SPM_BASE + 0x0404)
#define SPM_MAS_PAUSE_MASK_B           (SPM_BASE + 0x0408)
#define SPM_MAS_PAUSE2_MASK_B          (SPM_BASE + 0x040C)
#define SPM_BSI_GEN                    (SPM_BASE + 0x0410)
#define SPM_BSI_EN_SR                  (SPM_BASE + 0x0414)
#define SPM_BSI_CLK_SR                 (SPM_BASE + 0x0418)
#define SPM_BSI_D0_SR                  (SPM_BASE + 0x041C)
#define SPM_BSI_D1_SR                  (SPM_BASE + 0x0420)
#define SPM_BSI_D2_SR                  (SPM_BASE + 0x0424)
#define AP2MD_CROSS_TRIGGER            (SPM_BASE + 0x0438)
#define AP_MDSRC_REQ                   (SPM_BASE + 0x043C)
#define SPM2MD_DVFS_CON                (SPM_BASE + 0x0444)
#define MD2SPM_DVFS_CON                (SPM_BASE + 0x0448)
#define SPM_PLL_CON                    (SPM_BASE + 0x0454)
#define AP2MD_PEER_WAKEUP              (SPM_BASE + 0x0458)
#define ULPOSC_CON                     (SPM_BASE + 0x045C)
#define DRAMC_DPY_CLK_SW_CON_SEL       (SPM_BASE + 0x0460)
#define DRAMC_DPY_CLK_SW_CON           (SPM_BASE + 0x0464)
#define DRAMC_DPY_CLK_SW_CON_SEL2      (SPM_BASE + 0x0470)
#define DRAMC_DPY_CLK_SW_CON2          (SPM_BASE + 0x0474)
#define DVFS_LEVEL                     (SPM_BASE + 0x0478)
#define MSDC_DVFS_HALT                 (SPM_BASE + 0x047C)
#define MP0_CPU0_IRQ_MASK              (SPM_BASE + 0x0500)
#define MP0_CPU1_IRQ_MASK              (SPM_BASE + 0x0504)
#define MP0_CPU2_IRQ_MASK              (SPM_BASE + 0x0508)
#define MP0_CPU3_IRQ_MASK              (SPM_BASE + 0x050C)
#define MP1_CPU0_IRQ_MASK              (SPM_BASE + 0x0510)
#define MP1_CPU1_IRQ_MASK              (SPM_BASE + 0x0514)
#define MP1_CPU2_IRQ_MASK              (SPM_BASE + 0x0518)
#define MP1_CPU3_IRQ_MASK              (SPM_BASE + 0x051C)
#define DEBUG0_IRQ_MASK                (SPM_BASE + 0x0520)
#define DEBUG1_IRQ_MASK                (SPM_BASE + 0x0524)
#define DEBUG2_IRQ_MASK                (SPM_BASE + 0x0528)
#define DEBUG3_IRQ_MASK                (SPM_BASE + 0x052C)
#define MP0_CPU0_WFI_EN                (SPM_BASE + 0x0540)
#define MP0_CPU1_WFI_EN                (SPM_BASE + 0x0544)
#define MP0_CPU2_WFI_EN                (SPM_BASE + 0x0548)
#define MP0_CPU3_WFI_EN                (SPM_BASE + 0x054C)
#define MP1_CPU0_WFI_EN                (SPM_BASE + 0x0550)
#define MP1_CPU1_WFI_EN                (SPM_BASE + 0x0554)
#define MP1_CPU2_WFI_EN                (SPM_BASE + 0x0558)
#define MP1_CPU3_WFI_EN                (SPM_BASE + 0x055C)
#define DEBUG0_WFI_EN                  (SPM_BASE + 0x0560)
#define DEBUG1_WFI_EN                  (SPM_BASE + 0x0564)
#define DEBUG2_WFI_EN                  (SPM_BASE + 0x0568)
#define DEBUG3_WFI_EN                  (SPM_BASE + 0x056C)
#define SPM_SW_FLAG                    (SPM_BASE + 0x0600)
#define SPM_SW_DEBUG                   (SPM_BASE + 0x0604)
#define SPM_SW_RSV_0                   (SPM_BASE + 0x0608)
#define SPM_SW_RSV_1                   (SPM_BASE + 0x060C)
#define SPM_SW_RSV_2                   (SPM_BASE + 0x0610)
#define SPM_SW_RSV_3                   (SPM_BASE + 0x0614)
#define SPM_SW_RSV_4                   (SPM_BASE + 0x0618)
#define SPM_SW_RSV_5                   (SPM_BASE + 0x061C)
#define SPM_RSV_CON                    (SPM_BASE + 0x0620)
#define SPM_RSV_STA                    (SPM_BASE + 0x0624)
#define SPM_RSV_STA2                   (SPM_BASE + 0x0628)
#define SPM_PASR_DPD_0                 (SPM_BASE + 0x0630)
#define SPM_PASR_DPD_1                 (SPM_BASE + 0x0634)
#define SPM_PASR_DPD_2                 (SPM_BASE + 0x0638)
#define SPM_PASR_DPD_3                 (SPM_BASE + 0x063C)
#define SPM2PMCU_INT_SET               (SPM_BASE + 0x10C00)
#define SPM2PMCU_INT_CLR               (SPM_BASE + 0x10C04)
#define SPM2PMCU_INT                   (SPM_BASE + 0x10C08)
#define PMCU2SPM_MAILBOX_0             (SPM_BASE + 0x10C20)
#define PMCU2SPM_MAILBOX_1             (SPM_BASE + 0x10C24)
#define PMCU2SPM_MAILBOX_2             (SPM_BASE + 0x10C28)
#define PMCU2SPM_MAILBOX_3             (SPM_BASE + 0x10C2C)
#define SPM2PMCU_MAILBOX_0             (SPM_BASE + 0x10C30)
#define SPM2PMCU_MAILBOX_1             (SPM_BASE + 0x10C34)
#define SPM2PMCU_MAILBOX_2             (SPM_BASE + 0x10C38)
#define SPM2PMCU_MAILBOX_3             (SPM_BASE + 0x10C3C)
#define PMCU2SPM_INT_SET               (SPM_BASE + 0x10C40)
#define PMCU2SPM_INT_CLR               (SPM_BASE + 0x10C44)
#define PMCU2SPM_INT                   (SPM_BASE + 0x10C48)
#define SPM_SWINT_SET                  (SPM_BASE + 0x20E00)
#define SPM_SWINT_CLR                  (SPM_BASE + 0x20E04)
#define SPM_SWINT                      (SPM_BASE + 0x20E08)
#define SPM_SW_NONSERSV_0              (SPM_BASE + 0x20E10)
#define SPM_SW_NONSERSV_1              (SPM_BASE + 0x20E14)
#define SPM_SW_NONSERSV_2              (SPM_BASE + 0x20E18)
#define SPM_SW_NONSERSV_3              (SPM_BASE + 0x20E1C)
#define SW2SPM_MAILBOX_0               (SPM_BASE + 0x20E20)
#define SW2SPM_MAILBOX_1               (SPM_BASE + 0x20E24)
#define SW2SPM_MAILBOX_2               (SPM_BASE + 0x20E28)
#define SW2SPM_MAILBOX_3               (SPM_BASE + 0x20E2C)
#define SPM2SW_MAILBOX_0               (SPM_BASE + 0x20E30)
#define SPM2SW_MAILBOX_1               (SPM_BASE + 0x20E34)
#define SPM2SW_MAILBOX_2               (SPM_BASE + 0x20E38)
#define SPM2SW_MAILBOX_3               (SPM_BASE + 0x20E3C)
#define SW2SPM_INT_SET                 (SPM_BASE + 0x20E40)
#define SW2SPM_INT_CLR                 (SPM_BASE + 0x20E44)
#define SW2SPM_INT                     (SPM_BASE + 0x20E48)
#define SPM_SEMA_M0                    (SPM_BASE + 0x20E50)
#define SPM_SEMA_M1                    (SPM_BASE + 0x20E54)
#define SPM_SEMA_M2                    (SPM_BASE + 0x20E58)
#define SPM_SEMA_M3                    (SPM_BASE + 0x20E5C)
#define CPU_HOTPLUG_SET                (SPM_BASE + 0x20E60)
#define CPU_HOTPLUG_CLR                (SPM_BASE + 0x20E64)
#define CPU_HOTPLUG                    (SPM_BASE + 0x20E68)

/* POWERON_CONFIG_EN (0x108C0000+0x000) */
#define BCLK_CG_EN_LSB                      (1U << 0)       /* 1b */
#define PROJECT_CODE_LSB                    (1U << 16)      /* 16b */
/* SPM_POWER_ON_VAL0 (0x108C0000+0x004) */
#define INI_PWRON_REG0_RF_LSB               (1U << 0)       /* 32b */
/* SPM_POWER_ON_VAL1 (0x108C0000+0x008) */
#define INI_PWRON_REG7_RF_LSB               (1U << 0)       /* 32b */
/* SPM_CLK_CON (0x108C0000+0x00C) */
#define REG_SRCCLKEN0_CTL_LSB               (1U << 0)       /* 2b */
#define REG_SRCCLKEN1_CTL_LSB               (1U << 2)       /* 2b */
#define REG_SPM_LOCK_INFRA_DCM_LSB          (1U << 5)       /* 1b */
#define REG_SRCCLKEN_MASK_LSB               (1U << 6)       /* 3b */
#define REG_MD1_C32RM_EN_LSB                (1U << 9)       /* 1b */
#define REG_MD2_C32RM_EN_LSB                (1U << 10)      /* 1b */
#define REG_CLKSQ0_SEL_CTRL_LSB             (1U << 11)      /* 1b */
#define REG_CLKSQ1_SEL_CTRL_LSB             (1U << 12)      /* 1b */
#define REG_SRCCLKEN0_EN_LSB                (1U << 13)      /* 1b */
#define REG_SRCCLKEN1_EN_LSB                (1U << 14)      /* 1b */
#define REG_SYSCLK0_SRC_MASK_B_LSB          (1U << 16)      /* 7b */
#define REG_SYSCLK1_SRC_MASK_B_LSB          (1U << 23)      /* 7b */
/* SPM_CLK_SETTLE (0x108C0000+0x010) */
#define SYSCLK_SETTLE_LSB                   (1U << 0)       /* 8b */
/* SPM_AP_STANDBY_CON (0x108C0000+0x014) */
#define REG_MPWFI_OP_LSB                    (1U << 0)       /* 1b */
#define REG_MP0_CPUTOP_IDLE_MASK_LSB        (1U << 1)       /* 1b */
#define REG_MP1_CPUTOP_IDLE_MASK_LSB        (1U << 2)       /* 1b */
#define REG_DEBUGTOP_IDLE_MASK_LSB          (1U << 3)       /* 1b */
#define REG_MP_TOP_IDLE_MASK_LSB            (1U << 5)       /* 1b */
#define REG_MCUSYS_IDLE_MASK_LSB            (1U << 6)       /* 1b */
#define REG_MD_DDR_EN_0_DBC_EN_LSB          (1U << 16)      /* 1b */
#define REG_MD_DDR_EN_1_DBC_EN_LSB          (1U << 17)      /* 1b */
#define REG_CONN_DDR_EN_DBC_EN_LSB          (1U << 18)      /* 1b */
#define REG_MD32_MASK_B_LSB                 (1U << 19)      /* 1b */
#define REG_MD_0_MASK_B_LSB                 (1U << 20)      /* 1b */
#define REG_MD_1_MASK_B_LSB                 (1U << 21)      /* 1b */
#define REG_SCP_MASK_B_LSB                  (1U << 22)      /* 1b */
#define REG_SRCCLKENI0_MASK_B_LSB           (1U << 23)      /* 1b */
#define REG_SRCCLKENI1_MASK_B_LSB           (1U << 24)      /* 1b */
#define REG_MD_APSRC_1_SEL_LSB              (1U << 25)      /* 1b */
#define REG_MD_APSRC_0_SEL_LSB              (1U << 26)      /* 1b */
#define REG_CONN_MASK_B_LSB                 (1U << 27)      /* 1b */
#define REG_CONN_APSRC_SEL_LSB              (1U << 28)      /* 1b */
/* PCM_CON0 (0x108C0000+0x018) */
#define RG_PCM_KICK_L_LSB                   (1U << 0)       /* 1b */
#define RG_IM_KICK_L_LSB                    (1U << 1)       /* 1b */
#define PCM_CK_EN_LSB                       (1U << 2)       /* 1b */
#define RG_EN_IM_SLEEP_DVS_LSB              (1U << 3)       /* 1b */
#define IM_AUTO_PDN_EN_LSB                  (1U << 4)       /* 1b */
#define PCM_SW_RESET_LSB                    (1U << 15)      /* 1b */
#define PROJECT_CODE_LSB                    (1U << 16)      /* 16b */
/* PCM_CON1 (0x108C0000+0x01C) */
#define RG_IM_SLAVE_LSB                     (1U << 0)       /* 1b */
#define RG_IM_SLEEP_LSB                     (1U << 1)       /* 1b */
#define RG_AHBMIF_APBEN_LSB                 (1U << 3)       /* 1b */
#define RG_IM_PDN_LSB                       (1U << 4)       /* 1b */
#define RG_PCM_TIMER_EN_LSB                 (1U << 5)       /* 1b */
#define RG_IM_NONRP_EN_LSB                  (1U << 6)       /* 1b */
#define RG_DIS_MIF_CK_PROT_LSB              (1U << 7)       /* 1b */
#define RG_PCM_WDT_EN_LSB                   (1U << 8)       /* 1b */
#define RG_PCM_WDT_WAKE_LSB                 (1U << 9)       /* 1b */
#define REG_SPM_SRAM_SLEEP_B_LSB            (1U << 10)      /* 1b */
#define REG_SPM_SRAM_ISOINT_B_LSB           (1U << 11)      /* 1b */
#define REG_EVENT_LOCK_EN_LSB               (1U << 12)      /* 1b */
#define REG_SRCCLKEN_FAST_RESP_LSB          (1U << 13)      /* 1b */
#define RG_MD32_APB_INTERNAL_EN_LSB         (1U << 14)      /* 1b */
#define PROJECT_CODE_LSB                    (1U << 16)      /* 16b */
/* PCM_IM_PTR (0x108C0000+0x020) */
#define RG_IM_PTR_LSB                       (1U << 0)       /* 32b */
/* PCM_IM_LEN (0x108C0000+0x024) */
#define RG_IM_LEN_LSB                       (1U << 0)       /* 13b */
/* PCM_REG_DATA_INI (0x108C0000+0x028) */
#define PCM_REG_RF_INI_LSB                  (1U << 0)       /* 32b */
/* PCM_PWR_IO_EN (0x108C0000+0x02C) */
#define RG_PCM_PWR_IO_EN_LSB                (1U << 0)       /* 8b */
#define RG_RF_SYNC_EN_LSB                   (1U << 16)      /* 8b */
/* PCM_TIMER_VAL (0x108C0000+0x030) */
#define RG_PCM_TIMER_VAL_LSB                (1U << 0)       /* 32b */
/* PCM_WDT_VAL (0x108C0000+0x034) */
#define RG_PCM_WDT_VAL_LSB                  (1U << 0)       /* 32b */
/* PCM_IM_HOST_RW_PTR (0x108C0000+0x038) */
#define RG_IM_HOST_RW_PTR_LSB               (1U << 0)       /* 12b */
#define RG_IM_HOST_W_EN_LSB                 (1U << 30)      /* 1b */
#define RG_IM_HOST_EN_LSB                   (1U << 31)      /* 1b */
/* PCM_IM_HOST_RW_DAT (0x108C0000+0x03C) */
#define PCM_IM_HOST_RW_DAT_LSB              (1U << 0)       /* 32b */
/* PCM_EVENT_VECTOR0 (0x108C0000+0x040) */
#define PCM_EVENT_VECTOR_0_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_0_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_0_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_0_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR1 (0x108C0000+0x044) */
#define PCM_EVENT_VECTOR_1_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_1_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_1_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_1_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR2 (0x108C0000+0x048) */
#define PCM_EVENT_VECTOR_2_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_2_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_2_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_2_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR3 (0x108C0000+0x04C) */
#define PCM_EVENT_VECTOR_3_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_3_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_3_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_3_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR4 (0x108C0000+0x050) */
#define PCM_EVENT_VECTOR_4_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_4_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_4_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_4_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR5 (0x108C0000+0x054) */
#define PCM_EVENT_VECTOR_5_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_5_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_5_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_5_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR6 (0x108C0000+0x058) */
#define PCM_EVENT_VECTOR_6_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_6_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_6_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_6_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR7 (0x108C0000+0x05C) */
#define PCM_EVENT_VECTOR_7_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_7_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_7_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_7_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR8 (0x108C0000+0x060) */
#define PCM_EVENT_VECTOR_8_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_8_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_8_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_8_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR9 (0x108C0000+0x064) */
#define PCM_EVENT_VECTOR_9_LSB              (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_9_LSB              (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_9_LSB             (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_9_LSB              (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR10 (0x108C0000+0x068) */
#define PCM_EVENT_VECTOR_10_LSB             (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_10_LSB             (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_10_LSB            (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_10_LSB             (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR11 (0x108C0000+0x06C) */
#define PCM_EVENT_VECTOR_11_LSB             (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_11_LSB             (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_11_LSB            (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_11_LSB             (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR12 (0x108C0000+0x070) */
#define PCM_EVENT_VECTOR_12_LSB             (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_12_LSB             (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_12_LSB            (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_12_LSB             (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR13 (0x108C0000+0x074) */
#define PCM_EVENT_VECTOR_13_LSB             (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_13_LSB             (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_13_LSB            (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_13_LSB             (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR14 (0x108C0000+0x078) */
#define PCM_EVENT_VECTOR_14_LSB             (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_14_LSB             (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_14_LSB            (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_14_LSB             (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR15 (0x108C0000+0x07C) */
#define PCM_EVENT_VECTOR_15_LSB             (1U << 0)       /* 6b */
#define PCM_EVENT_RESUME_15_LSB             (1U << 6)       /* 1b */
#define PCM_EVENT_IMMEDIA_15_LSB            (1U << 7)       /* 1b */
#define PCM_EVENT_VECTPC_15_LSB             (1U << 16)      /* 11b */
/* PCM_EVENT_VECTOR_EN (0x108C0000+0x080) */
#define RG_EVENT_VEC_EN_LSB                 (1U << 0)       /* 16b */
/* SPM_MD32_IRQ (0x108C0000+0x094) */
#define REG_SPM_MD32_IRQ_LSB                (1U << 0)       /* 1b */
#define REG_SPM_MD32_IRQ_SEL_LSB            (1U << 4)       /* 1b */
/* SPM_SCP_IRQ (0x108C0000+0x09C) */
#define REG_SPM_SCP_IRQ_LSB                 (1U << 0)       /* 1b */
#define REG_SPM_SCP_IRQ_SEL_LSB             (1U << 4)       /* 1b */
/* SPM_TWAM_CON (0x108C0000+0x0A0) */
#define REG_TWAM_ENABLE_LSB                 (1U << 0)       /* 1b */
#define REG_SPEED_MODE_EN_LSB               (1U << 1)       /* 1b */
#define REG_TWAM_SW_RST_EN_LSB              (1U << 2)       /* 1b */
#define REG_TWAM_MON_TYPE_0_LSB             (1U << 4)       /* 2b */
#define REG_TWAM_MON_TYPE_1_LSB             (1U << 6)       /* 2b */
#define REG_TWAM_MON_TYPE_2_LSB             (1U << 8)       /* 2b */
#define REG_TWAM_MON_TYPE_3_LSB             (1U << 10)      /* 2b */
#define REG_TWAM_SIG_SEL_0_LSB              (1U << 12)      /* 5b */
#define REG_TWAM_SIG_SEL_1_LSB              (1U << 17)      /* 5b */
#define REG_TWAM_SIG_SEL_2_LSB              (1U << 22)      /* 5b */
#define REG_TWAM_SIG_SEL_3_LSB              (1U << 27)      /* 5b */
/* SPM_TWAM_WINDOW_LEN (0x108C0000+0x0A4) */
#define REG_TWAM_WINDOW_LEN_LSB             (1U << 0)       /* 32b */
/* SPM_TWAM_IDLE_SEL (0x108C0000+0x0A8) */
#define REG_TWAM_IDLE_SIG_SEL_LSB           (1U << 0)       /* 5b */
/* SPM_CPU_WAKEUP_EVENT (0x108C0000+0x0B0) */
#define REG_CPU_WAKEUP_LSB                  (1U << 0)       /* 1b */
/* SPM_IRQ_MASK (0x108C0000+0x0B4) */
#define REG_TWAM_IRQ_MASK_LSB               (1U << 2)       /* 1b */
#define RG_PCM_IRQ_MSK_LSB                  (1U << 3)       /* 1b */
#define REG_SPM_IRQ_MASK_LSB                (1U << 8)       /* 16b */
/* SPM_SRC_REQ (0x108C0000+0x0B8) */
#define REG_SPM_APSRC_REQ_LSB               (1U << 0)       /* 1b */
#define REG_SPM_F26M_REQ_LSB                (1U << 1)       /* 1b */
#define REG_SPM_INFRA_REQ_LSB               (1U << 2)       /* 1b */
#define REG_SPM_DDREN_REQ_LSB               (1U << 3)       /* 1b */
#define REG_SPM_VRF18_REQ_LSB               (1U << 4)       /* 1b */
#define REG_SPM_DVFS_LEVEL0_REQ_LSB         (1U << 5)       /* 1b */
#define REG_SPM_DVFS_LEVEL1_REQ_LSB         (1U << 6)       /* 1b */
#define REG_SPM_DVFS_LEVEL2_REQ_LSB         (1U << 7)       /* 1b */
#define REG_SPM_DVFS_LEVEL3_REQ_LSB         (1U << 8)       /* 1b */
#define REG_SPM_DVFS_LEVEL4_REQ_LSB         (1U << 9)       /* 1b */
#define REG_SPM_PMCU_MAILBOX_REQ_LSB        (1U << 10)      /* 1b */
#define REG_SPM_SW_MAILBOX_REQ_LSB          (1U << 11)      /* 1b */
#define REG_SPM_CKSEL2_REQ_LSB              (1U << 12)      /* 1b */
#define REG_SPM_CKSEL3_REQ_LSB              (1U << 13)      /* 1b */
/* SPM_SRC_MASK (0x108C0000+0x0BC) */
#define REG_CSYSPWREQ_MASK_LSB              (1U << 0)       /* 1b */
#define REG_MD_SRCCLKENA_0_INFRA_MASK_B_LSB (1U << 1)       /* 1b */
#define REG_MD_SRCCLKENA_1_INFRA_MASK_B_LSB (1U << 2)       /* 1b */
#define REG_MD_APSRC_REQ_0_INFRA_MASK_B_LSB (1U << 3)       /* 1b */
#define REG_MD_APSRC_REQ_1_INFRA_MASK_B_LSB (1U << 4)       /* 1b */
#define REG_CONN_SRCCLKENA_INFRA_MASK_B_LSB (1U << 5)       /* 1b */
#define REG_CONN_INFRA_REQ_MASK_B_LSB       (1U << 6)       /* 1b */
#define REG_MD32_SRCCLKENA_INFRA_MASK_B_LSB (1U << 7)       /* 1b */
#define REG_MD32_INFRA_REQ_MASK_B_LSB       (1U << 8)       /* 1b */
#define REG_SCP_SRCCLKENA_INFRA_MASK_B_LSB  (1U << 9)       /* 1b */
#define REG_SCP_INFRA_REQ_MASK_B_LSB        (1U << 10)      /* 1b */
#define REG_SRCCLKENI0_INFRA_MASK_B_LSB     (1U << 11)      /* 1b */
#define REG_SRCCLKENI1_INFRA_MASK_B_LSB     (1U << 12)      /* 1b */
#define REG_CCIF0_MD_EVENT_MASK_B_LSB       (1U << 13)      /* 1b */
#define REG_CCIF0_AP_EVENT_MASK_B_LSB       (1U << 14)      /* 1b */
#define REG_CCIF1_MD_EVENT_MASK_B_LSB       (1U << 15)      /* 1b */
#define REG_CCIF1_AP_EVENT_MASK_B_LSB       (1U << 16)      /* 1b */
#define REG_CCIF2_MD_EVENT_MASK_B_LSB       (1U << 17)      /* 1b */
#define REG_CCIF2_AP_EVENT_MASK_B_LSB       (1U << 18)      /* 1b */
#define REG_CCIF3_MD_EVENT_MASK_B_LSB       (1U << 19)      /* 1b */
#define REG_CCIF3_AP_EVENT_MASK_B_LSB       (1U << 20)      /* 1b */
#define REG_CCIFMD_MD1_EVENT_MASK_B_LSB     (1U << 21)      /* 1b */
#define REG_CCIFMD_MD2_EVENT_MASK_B_LSB     (1U << 22)      /* 1b */
#define REG_C2K_PS_RCCIF_WAKE_MASK_B_LSB    (1U << 23)      /* 1b */
#define REG_C2K_L1_RCCIF_WAKE_MASK_B_LSB    (1U << 24)      /* 1b */
#define REG_PS_C2K_RCCIF_WAKE_MASK_B_LSB    (1U << 25)      /* 1b */
#define REG_L1_C2K_RCCIF_WAKE_MASK_B_LSB    (1U << 26)      /* 1b */
#define REG_DQSSOC_REQ_MASK_B_LSB           (1U << 27)      /* 1b */
#define REG_DISP2_REQ_MASK_B_LSB            (1U << 28)      /* 1b */
#define REG_MD_DDR_EN_0_MASK_B_LSB          (1U << 29)      /* 1b */
#define REG_MD_DDR_EN_1_MASK_B_LSB          (1U << 30)      /* 1b */
#define REG_CONN_DDR_EN_MASK_B_LSB          (1U << 31)      /* 1b */
/* SPM_SRC2_MASK (0x108C0000+0x0C0) */
#define REG_DISP0_REQ_MASK_B_LSB            (1U << 0)       /* 1b */
#define REG_DISP1_REQ_MASK_B_LSB            (1U << 1)       /* 1b */
#define REG_DISP_OD_REQ_MASK_B_LSB          (1U << 2)       /* 1b */
#define REG_MFG_REQ_MASK_B_LSB              (1U << 3)       /* 1b */
#define REG_VDEC0_REQ_MASK_B_LSB            (1U << 4)       /* 1b */
#define REG_GCE_VRF18_REQ_MASK_B_LSB        (1U << 6)       /* 1b */
#define REG_GCE_REQ_MASK_B_LSB              (1U << 7)       /* 1b */
#define REG_LPDMA_REQ_MASK_B_LSB            (1U << 8)       /* 1b */
#define REG_SRCCLKENI1_CKSEL2_MASK_B_LSB    (1U << 9)       /* 1b */
#define REG_CONN_SRCCLKENA_CKSEL2_MASK_B_LSB (1U << 10)      /* 1b */
#define REG_SRCCLKENI0_CKSEL3_MASK_B_LSB    (1U << 11)      /* 1b */
#define REG_MD32_APSRC_REQ_DDREN_MASK_B_LSB (1U << 12)      /* 1b */
#define REG_SCP_APSRC_REQ_DDREN_MASK_B_LSB  (1U << 13)      /* 1b */
#define REG_MD_VRF18_REQ_0_MASK_B_LSB       (1U << 14)      /* 1b */
#define REG_MD_VRF18_REQ_1_MASK_B_LSB       (1U << 15)      /* 1b */
#define REG_NEXT_DVFS_LEVEL0_MASK_B_LSB     (1U << 16)      /* 1b */
#define REG_NEXT_DVFS_LEVEL1_MASK_B_LSB     (1U << 17)      /* 1b */
#define REG_NEXT_DVFS_LEVEL2_MASK_B_LSB     (1U << 18)      /* 1b */
#define REG_NEXT_DVFS_LEVEL3_MASK_B_LSB     (1U << 19)      /* 1b */
#define REG_NEXT_DVFS_LEVEL4_MASK_B_LSB     (1U << 20)      /* 1b */
#define REG_MSDC1_DVFS_HALT_MASK_LSB        (1U << 21)      /* 1b */
#define REG_MSDC2_DVFS_HALT_MASK_LSB        (1U << 22)      /* 1b */
#define REG_MSDC3_DVFS_HALT_MASK_LSB        (1U << 23)      /* 1b */
#define REG_SW2SPM_INT0_MASK_B_LSB          (1U << 24)      /* 1b */
#define REG_SW2SPM_INT1_MASK_B_LSB          (1U << 25)      /* 1b */
#define REG_SW2SPM_INT2_MASK_B_LSB          (1U << 26)      /* 1b */
#define REG_SW2SPM_INT3_MASK_B_LSB          (1U << 27)      /* 1b */
#define REG_PMCU2SPM_INT0_MASK_B_LSB        (1U << 28)      /* 1b */
#define REG_PMCU2SPM_INT1_MASK_B_LSB        (1U << 29)      /* 1b */
#define REG_PMCU2SPM_INT2_MASK_B_LSB        (1U << 30)      /* 1b */
#define REG_PMCU2SPM_INT3_MASK_B_LSB        (1U << 31)      /* 1b */
/* SPM_WAKEUP_EVENT_MASK (0x108C0000+0x0C4) */
#define REG_WAKEUP_EVENT_MASK_LSB           (1U << 0)       /* 32b */
/* SPM_EXT_WAKEUP_EVENT_MASK (0x108C0000+0x0C8) */
#define REG_EXT_WAKEUP_EVENT_MASK_LSB       (1U << 0)       /* 32b */
/* SCP_CLK_CON (0x108C0000+0x0D0) */
#define REG_SCP_26M_CK_SEL_LSB              (1U << 0)       /* 1b */
#define REG_SCP_DCM_EN_LSB                  (1U << 1)       /* 1b */
#define REG_MD32_26M_CK_SEL_LSB             (1U << 8)       /* 1b */
#define REG_MD32_DCM_EN_LSB                 (1U << 9)       /* 1b */
/* PCM_DEBUG_CON (0x108C0000+0x0D4) */
#define REG_PCM_DEBUG_OUT_EN_LSB            (1U << 0)       /* 1b */
/* DDR_EN_DBC_LEN (0x108C0000+0X0D8) */
#define MD_DDR_EN_0_DBC_LEN_LSB             (1U << 0)       /* 10b */
#define MD_DDR_EN_1_DBC_LEN_LSB             (1U << 10)      /* 10b */
#define CONN_DDR_EN_DBC_LEN_LSB             (1U << 20)      /* 10b */
/* PCM_REG0_DATA (0x108C0000+0x100) */
#define PCM_REG0_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG1_DATA (0x108C0000+0x104) */
#define PCM_REG1_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG2_DATA (0x108C0000+0x108) */
#define PCM_REG2_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG3_DATA (0x108C0000+0x10C) */
#define PCM_REG3_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG4_DATA (0x108C0000+0x110) */
#define PCM_REG4_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG5_DATA (0x108C0000+0x114) */
#define PCM_REG5_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG6_DATA (0x108C0000+0x118) */
#define PCM_REG6_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG7_DATA (0x108C0000+0x11C) */
#define PCM_REG7_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG8_DATA (0x108C0000+0x120) */
#define PCM_REG8_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG9_DATA (0x108C0000+0x124) */
#define PCM_REG9_RF_LSB                     (1U << 0)       /* 32b */
/* PCM_REG10_DATA (0x108C0000+0x128) */
#define PCM_REG10_RF_LSB                    (1U << 0)       /* 32b */
/* PCM_REG11_DATA (0x108C0000+0x12C) */
#define PCM_REG11_RF_LSB                    (1U << 0)       /* 32b */
/* PCM_REG12_DATA (0x108C0000+0x130) */
#define PCM_REG12_RF_LSB                    (1U << 0)       /* 32b */
/* PCM_REG13_DATA (0x108C0000+0x134) */
#define PCM_REG13_RF_LSB                    (1U << 0)       /* 32b */
/* PCM_REG14_DATA (0x108C0000+0x138) */
#define PCM_REG14_RF_LSB                    (1U << 0)       /* 32b */
/* PCM_REG15_DATA (0x108C0000+0x13C) */
#define PCM_REG15_RF_LSB                    (1U << 0)       /* 32b */
/* PCM_REG12_MASK_B_STA (0x108C0000+0x140) */
#define PCM_REG12_MASK_B_LSB                (1U << 0)       /* 32b */
/* PCM_REG12_EXT_DATA (0x108C0000+0x144) */
#define PCM_REG12_EXT_RF_LSB                (1U << 0)       /* 32b */
/* PCM_REG12_EXT_MASK_B_STA (0x108C0000+0x148) */
#define PCM_REG12_EXT_MASK_B_LSB            (1U << 0)       /* 32b */
/* PCM_EVENT_REG_STA (0x108C0000+0x14C) */
#define EVET_CNTER_STA_LSB                  (1U << 0)       /* 32b */
/* PCM_TIMER_OUT (0x108C0000+0x150) */
#define PCM_TIMER_LSB                       (1U << 0)       /* 32b */
/* PCM_WDT_OUT (0x108C0000+0x154) */
#define PCM_WDT_TIMER_VAL_OUT_LSB           (1U << 0)       /* 32b */
/* SPM_IRQ_STA (0x108C0000+0x158) */
#define TWAM_IRQ_LSB                        (1U << 2)       /* 1b */
#define PCM_IRQ_LSB                         (1U << 3)       /* 1b */
/* FIXME: */
/* #define SPM_SWINT_LSB                    (1U << 4) */    /* 16b */
/* SPM_WAKEUP_STA (0x108C0000+0x15C) */
#define SPM_WAKEUP_EVENT_STA_LSB            (1U << 0)       /* 32b */
/* SPM_WAKEUP_EXT_STA (0x108C0000+0x160) */
#define SPM_WAKEUP_EVENT_EXT_STA_LSB        (1U << 0)       /* 32b */
/* SPM_WAKEUP_MISC (0x108C0000+0x164) */
#define WAKEUP_EVENT_MISC_LSB               (1U << 0)       /* 25b */
#define PMIC_IRQ_ACK_LSB                    (1U << 30)      /* 1b */
#define PMIC_SCP_IRQ_LSB                    (1U << 31)      /* 1b */
/* BUS_PROTECT_RDY (0x108C0000+0x168) */
#define PROTECT_READY_LSB                   (1U << 0)       /* 32b */
/* BUS_PROTECT2_RDY (0x108C0000+0x16C) */
#define PROTECT2_READY_LSB                  (1U << 0)       /* 32b */
/* SUBSYS_IDLE_STA (0x108C0000+0x170) */
#define SUBSYS_IDLE_SIGNALS_LSB             (1U << 0)       /* 32b */
/* CPU_IDLE_STA (0x108C0000+0x174) */
#define WFI_AF_SEL_LSB                      (1U << 0)       /* 12b */
#define STANDBYWFI_LSB                      (1U << 12)      /* 12b */
#define MP0_CPUTOP_IDLE_LSB                 (1U << 24)      /* 1b */
#define MP1_CPUTOP_IDLE_LSB                 (1U << 25)      /* 1b */
#define DEBUGTOP_IDLE_LSB                   (1U << 26)      /* 1b */
#define MP_TOP_IDLE_LSB                     (1U << 27)      /* 1b */
#define MCUSYS_IDLE_LSB                     (1U << 28)      /* 1b */
/* PCM_FSM_STA (0x108C0000+0x17C) */
#define EXEC_INST_OP_LSB                    (1U << 0)       /* 4b */
#define PC_STATE_LSB                        (1U << 4)       /* 3b */
#define IM_STATE_LSB                        (1U << 7)       /* 3b */
#define NXT_MASTER_STATE_LSB                (1U << 10)      /* 5b */
#define EVENT_FSM_LSB                       (1U << 15)      /* 3b */
#define PCM_CK_SEL_O_LSB                    (1U << 18)      /* 3b */
#define RG_PCM_KICK_LSB                     (1U << 21)      /* 1b */
#define RG_IM_KICK_LSB                      (1U << 22)      /* 1b */
#define EXT_SRC_STA_LSB                     (1U << 23)      /* 3b */
/* PWR_STATUS (0x108C0000+0x180) */
#define PWR_STATUS_LSB                      (1U << 0)       /* 32b */
/* PWR_STATUS_2ND (0x108C0000+0x184) */
#define PWR_STATUS_2ND_LSB                  (1U << 0)       /* 32b */
/* CPU_PWR_STATUS (0x108C0000+0x188) */
#define CPU_PWR_STATUS_LSB                  (1U << 0)       /* 32b */
/* CPU_PWR_STATUS_2ND (0x108C0000+0x18C) */
#define CPU_PWR_STATUS_2ND_LSB              (1U << 0)       /* 32b */
/* PCM_WDT_LATCH_0 (0x108C0000+0x190) */
#define PCM_WDT_LATCH_0_LSB                 (1U << 0)       /* 32b */
/* PCM_WDT_LATCH_1 (0x108C0000+0x194) */
#define PCM_WDT_LATCH_1_LSB                 (1U << 0)       /* 32b */
/* PCM_WDT_LATCH_2 (0x108C0000+0x198) */
#define PCM_WDT_LATCH_2_LSB                 (1U << 0)       /* 32b */
/* SPM_TWAM_LAST_STA0 (0x108C0000+0x1A0) */
#define LAST_IDLE_CNT_0_LSB                 (1U << 0)       /* 32b */
/* SPM_TWAM_LAST_STA1 (0x108C0000+0x1A4) */
#define LAST_IDLE_CNT_1_LSB                 (1U << 0)       /* 32b */
/* SPM_TWAM_LAST_STA2 (0x108C0000+0x1A8) */
#define LAST_IDLE_CNT_2_LSB                 (1U << 0)       /* 32b */
/* SPM_TWAM_LAST_STA3 (0x108C0000+0x1AC) */
#define LAST_IDLE_CNT_3_LSB                 (1U << 0)       /* 32b */
/* SPM_TWAM_CURR_STA0 (0x108C0000+0x1B0) */
#define CURRENT_IDLE_CNT_0_LSB              (1U << 0)       /* 32b */
/* SPM_TWAM_CURR_STA1 (0x108C0000+0x1B4) */
#define CURRENT_IDLE_CNT_1_LSB              (1U << 0)       /* 32b */
/* SPM_TWAM_CURR_STA2 (0x108C0000+0x1B8) */
#define CURRENT_IDLE_CNT_2_LSB              (1U << 0)       /* 32b */
/* SPM_TWAM_CURR_STA3 (0x108C0000+0x1BC) */
#define CURRENT_IDLE_CNT_3_LSB              (1U << 0)       /* 32b */
/* SPM_TWAM_TIMER_OUT (0x108C0000+0x1C0) */
#define TWAM_TIMER_LSB                      (1U << 0)       /* 32b */
/* PCM_WDT_LATCH_3 (0x108C0000+0x1C4) */
#define PCM_WDT_LATCH_3_LSB                 (1U << 0)       /* 32b */
/* PCM_WDT_LATCH_4 (0x108C0000+0x1C8) */
#define PCM_WDT_LATCH_4_LSB                 (1U << 0)       /* 32b */
/* SPM_SRC_RDY_STA (0x108C0000+0x1D0) */
#define SPM_INFRA_SRC_ACK_LSB               (1U << 0)       /* 1b */
#define SPM_VRF18_SRC_ACK_LSB               (1U << 1)       /* 1b */
/* CPU_RET_STATUS (0x108C0000+0x1E4) */
#define CPU_RET_STATUS_LSB                  (1U << 0)       /* 32b */
/* EVENT_STATUS_REG (0x108C0000+0x1E8) */
#define DISP0_REQ_LSB                       (1U << 0)       /* 1b */
#define DISP1_REQ_LSB                       (1U << 1)       /* 1b */
#define DISP2_REQ_LSB                       (1U << 2)       /* 1b */
#define DISP_OD_REQ_LSB                     (1U << 3)       /* 1b */
#define DQSSOC_REQ_LSB                      (1U << 4)       /* 1b */
#define GCE_REQ_LSB                         (1U << 5)       /* 1b */
#define CCIF0_AP_EVENT_B_LSB                (1U << 11)      /* 1b */
#define CCIF1_AP_EVENT_B_LSB                (1U << 12)      /* 1b */
#define CCIF0_MD_EVENT_B_LSB                (1U << 13)      /* 1b */
#define CCIF1_MD_EVENT_B_LSB                (1U << 14)      /* 1b */
#define CCIF2_AP_EVENT_B_LSB                (1U << 15)      /* 1b */
#define CCIF3_AP_EVENT_B_LSB                (1U << 16)      /* 1b */
#define CCIF2_MD_EVENT_B_LSB                (1U << 17)      /* 1b */
#define CCIF3_MD_EVENT_B_LSB                (1U << 18)      /* 1b */
#define CCIFMD_MD1_EVENT_B_LSB              (1U << 19)      /* 1b */
#define CCIFMD_MD2_EVENT_B_LSB              (1U << 20)      /* 1b */
#define PS_C2K_RCCIF_WAKE_LSB               (1U << 21)      /* 1b */
#define C2K_PS_RCCIF_WAKE_LSB               (1U << 22)      /* 1b */
#define L1_C2K_RCCIF_WAKE_LSB               (1U << 23)      /* 1b */
#define C2K_L1_RCCIF_WAKE_LSB               (1U << 24)      /* 1b */
#define VDEC0_REQ_LSB                       (1U << 25)      /* 1b */
#define MFG_REQ_LSB                         (1U << 26)      /* 1b */
#define CONN_INFRA_REQ_LSB                  (1U << 27)      /* 1b */
#define MD32_INFRA_REQ_LSB                  (1U << 28)      /* 1b */
#define SCP_INFRA_REQ_LSB                   (1U << 29)      /* 1b */
#define LPDMA_REQ_LSB                       (1U << 30)      /* 1b */
/* MCUSYS_PWR_CON (0x108C0000+0x200) */
#define MCU_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define MCU_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define MCU_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define MCU_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define MCU_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
/* MP_TOP_PWR_CON (0x108C0000+0x204) */
#define MP_TOP_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define MP_TOP_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define MP_TOP_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define MP_TOP_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define MP_TOP_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
#define MP_TOP_SRAM_CKISO_LSB               (1U << 5)       /* 1b */
#define MP_TOP_SRAM_ISOINT_B_LSB            (1U << 6)       /* 1b */
#define MP_TOP_SRAM_PD_SLPB_CLAMP_LSB       (1U << 7)       /* 1b */
#define MP_TOP_SRAM_PDN_LSB                 (1U << 8)       /* 1b */
#define MP_TOP_SRAM_SLEEP_B_LSB             (1U << 12)      /* 1b */
#define SC_MP_TOP_SRAM_PDN_ACK_LSB          (1U << 24)      /* 1b */
#define SC_MP_TOP_SRAM_SLEEP_B_ACK_LSB      (1U << 28)      /* 1b */
/* MP0_CPUTOP_PWR_CON (0x108C0000+0x210) */
#define MP0_CPUTOP_PWR_RST_B_LSB            (1U << 0)       /* 1b */
#define MP0_CPUTOP_PWR_ISO_LSB              (1U << 1)       /* 1b */
#define MP0_CPUTOP_PWR_ON_LSB               (1U << 2)       /* 1b */
#define MP0_CPUTOP_PWR_ON_2ND_LSB           (1U << 3)       /* 1b */
#define MP0_CPUTOP_PWR_CLK_DIS_LSB          (1U << 4)       /* 1b */
#define MP0_CPUTOP_SRAM_CKISO_LSB           (1U << 5)       /* 1b */
#define MP0_CPUTOP_SRAM_ISOINT_B_LSB        (1U << 6)       /* 1b */
#define MP0_CPUTOP_SRAM_PD_SLPB_CLAMP_LSB   (1U << 7)       /* 1b */
#define MP0_CPUTOP_SRAM_PDN_LSB             (1U << 8)       /* 1b */
#define MP0_CPUTOP_SRAM_SLEEP_B_LSB         (1U << 12)      /* 1b */
#define SC_MP0_CPUTOP_SRAM_PDN_ACK_LSB      (1U << 24)      /* 1b */
#define SC_MP0_CPUTOP_SRAM_SLEEP_B_ACK_LSB  (1U << 28)      /* 1b */
/* MP1_CPUTOP_PWR_CON (0x108C0000+0x214) */
#define MP1_CPUTOP_PWR_RST_B_LSB            (1U << 0)       /* 1b */
#define MP1_CPUTOP_PWR_ISO_LSB              (1U << 1)       /* 1b */
#define MP1_CPUTOP_PWR_ON_LSB               (1U << 2)       /* 1b */
#define MP1_CPUTOP_PWR_ON_2ND_LSB           (1U << 3)       /* 1b */
#define MP1_CPUTOP_PWR_CLK_DIS_LSB          (1U << 4)       /* 1b */
#define MP1_CPUTOP_SRAM_CKISO_LSB           (1U << 5)       /* 1b */
#define MP1_CPUTOP_SRAM_ISOINT_B_LSB        (1U << 6)       /* 1b */
#define MP1_CPUTOP_SRAM_PD_SLPB_CLAMP_LSB   (1U << 7)       /* 1b */
#define MP1_CPUTOP_SRAM_PDN_LSB             (1U << 8)       /* 1b */
#define MP1_CPUTOP_SRAM_SLEEP_B_LSB         (1U << 12)      /* 1b */
#define SC_MP1_CPUTOP_SRAM_PDN_ACK_LSB      (1U << 24)      /* 1b */
#define SC_MP1_CPUTOP_SRAM_SLEEP_B_ACK_LSB  (1U << 28)      /* 1b */
/* DEBUGTOP_PWR_CON (0x108C0000+0x218) */
#define DEBUGTOP_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define DEBUGTOP_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define DEBUGTOP_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define DEBUGTOP_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define DEBUGTOP_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
/* MP0_CPU0_PWR_CON (0x108C0000+0x220) */
#define MP0_CPU0_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP0_CPU0_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP0_CPU0_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP0_CPU0_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP0_CPU0_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP0_CPU0_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP0_CPU0_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP0_CPU0_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP0_CPU0_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP0_CPU0_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP0_CPU0_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP0_CPU0_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP0_CPU1_PWR_CON (0x108C0000+0x224) */
#define MP0_CPU1_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP0_CPU1_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP0_CPU1_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP0_CPU1_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP0_CPU1_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP0_CPU1_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP0_CPU1_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP0_CPU1_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP0_CPU1_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP0_CPU1_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP0_CPU1_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP0_CPU1_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP0_CPU2_PWR_CON (0x108C0000+0x228) */
#define MP0_CPU2_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP0_CPU2_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP0_CPU2_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP0_CPU2_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP0_CPU2_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP0_CPU2_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP0_CPU2_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP0_CPU2_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP0_CPU2_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP0_CPU2_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP0_CPU2_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP0_CPU2_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP0_CPU3_PWR_CON (0x108C0000+0x22C) */
#define MP0_CPU3_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP0_CPU3_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP0_CPU3_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP0_CPU3_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP0_CPU3_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP0_CPU3_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP0_CPU3_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP0_CPU3_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP0_CPU3_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP0_CPU3_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP0_CPU3_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP0_CPU3_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP1_CPU0_PWR_CON (0x108C0000+0x230) */
#define MP1_CPU0_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP1_CPU0_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP1_CPU0_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP1_CPU0_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP1_CPU0_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP1_CPU0_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP1_CPU0_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP1_CPU0_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP1_CPU0_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP1_CPU0_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP1_CPU0_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP1_CPU0_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP1_CPU1_PWR_CON (0x108C0000+0x234) */
#define MP1_CPU1_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP1_CPU1_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP1_CPU1_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP1_CPU1_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP1_CPU1_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP1_CPU1_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP1_CPU1_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP1_CPU1_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP1_CPU1_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP1_CPU1_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP1_CPU1_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP1_CPU1_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP1_CPU2_PWR_CON (0x108C0000+0x238) */
#define MP1_CPU2_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP1_CPU2_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP1_CPU2_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP1_CPU2_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP1_CPU2_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP1_CPU2_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP1_CPU2_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP1_CPU2_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP1_CPU2_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP1_CPU2_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP1_CPU2_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP1_CPU2_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* MP1_CPU3_PWR_CON (0x108C0000+0x23C) */
#define MP1_CPU3_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define MP1_CPU3_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define MP1_CPU3_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define MP1_CPU3_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define MP1_CPU3_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
#define MP1_CPU3_SRAM_CKISO_LSB             (1U << 5)       /* 1b */
#define MP1_CPU3_SRAM_ISOINT_B_LSB          (1U << 6)       /* 1b */
#define MP1_CPU3_SRAM_PD_SLPB_CLAMP_LSB     (1U << 7)       /* 1b */
#define MP1_CPU3_SRAM_PDN_LSB               (1U << 8)       /* 1b */
#define MP1_CPU3_SRAM_SLEEP_B_LSB           (1U << 12)      /* 1b */
#define SC_MP1_CPU3_SRAM_PDN_ACK_LSB        (1U << 24)      /* 1b */
#define SC_MP1_CPU3_SRAM_SLEEP_B_ACK_LSB    (1U << 28)      /* 1b */
/* DEBUG0_PWR_CON (0x108C0000+0x240) */
#define DEBUG0_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define DEBUG0_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define DEBUG0_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define DEBUG0_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define DEBUG0_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
/* DEBUG1_PWR_CON (0x108C0000+0x244) */
#define DEBUG1_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define DEBUG1_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define DEBUG1_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define DEBUG1_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define DEBUG1_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
/* DEBUG2_PWR_CON (0x108C0000+0x248) */
#define DEBUG2_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define DEBUG2_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define DEBUG2_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define DEBUG2_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define DEBUG2_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
/* DEBUG3_PWR_CON (0x108C0000+0x24C) */
#define DEBUG3_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define DEBUG3_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define DEBUG3_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define DEBUG3_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define DEBUG3_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
/* COMMON_TOP_PWR_ADDR (0x108C0000+0x250) */
#define COMMON_TOP_PWR_ADDR_LSB             (1U << 0)       /* 32b */
/* COMMON_CPU_PWR_ADDR (0x108C0000+0x254) */
#define COMMON_CPU_PWR_ADDR_LSB             (1U << 0)       /* 32b */
/* CPU_EXT_BUCK_ISO (0x108C0000+0x260) */
#define MP0_EXT_BUCK_ISO_LSB                (1U << 0)       /* 1b */
#define MP1_EXT_BUCK_ISO_LSB                (1U << 1)       /* 1b */
#define MP2_EXT_BUCK_ISO_LSB                (1U << 2)       /* 1b */
/* ARMPLL_CLK_CON (0x108C0000+0x264) */
#define MUXSEL_SC_CCIPLL_LSB                (1U << 0)       /* 1b */
#define MUXSEL_SC_ARMPLL1_LSB               (1U << 1)       /* 1b */
#define MUXSEL_SC_ARMPLL2_LSB               (1U << 2)       /* 1b */
#define MUXSEL_SC_ARMPLL3_LSB               (1U << 3)       /* 1b */
#define REG_SC_ARM_CLK_OFF_LSB              (1U << 8)       /* 4b */
#define REG_SC_ARMPLL_OFF_LSB               (1U << 12)      /* 4b */
#define REG_SC_ARMPLLOUT_OFF_LSB            (1U << 16)      /* 4b */
#define REG_SC_FHC_PAUSE_LSB                (1U << 20)      /* 4b */
#define REG_SC_ARMPLL_S_OFF_LSB             (1U << 24)      /* 4b */
/* SPMC_DORMANT_ENABLE (0x108C0000+0X26C) */
#define MP0_SPMC_SRAM_DORMANT_EN_LSB        (1U << 0)       /* 1b */
#define MP1_SPMC_SRAM_DORMANT_EN_LSB        (1U << 1)       /* 1b */
#define MP2_SPMC_SRAM_DORMANT_EN_LSB        (1U << 2)       /* 1b */
/* SPMC_MISC (0x108C0000+0x270) */
#define SPMC_MISC_LSB                       (1U << 0)       /* 32b */
/* SPMC_MISC2 (0x108C0000+0x274) */
#define SPMC_MISC2_LSB                      (1U << 0)       /* 32b */
/* BYPASS_SPMC (0x108C0000+0x278) */
#define BYPASS_CPU_SPMC_MODE_LSB            (1U << 0)       /* 1b */
/* CPU_SRAM_DREQ (0x108C0000+0x280) */
#define CPU_SRAM_DREQ_LSB                   (1U << 0)       /* 16b */
/* CPU_SRAM_DREQ_SET (0x108C0000+0x284) */
#define CPU_SRAM_DREQ_SET_LSB               (1U << 0)       /* 16b */
/* CPU_SRAM_DREQ_CLR (0x108C0000+0x288) */
#define CPU_SRAM_DREQ_CLR_LSB               (1U << 0)       /* 16b */
/* VDE0_PWR_CON (0x108C0000+0x300) */
#define VDE0_PWR_RST_B_LSB                  (1U << 0)       /* 1b */
#define VDE0_PWR_ISO_LSB                    (1U << 1)       /* 1b */
#define VDE0_PWR_ON_LSB                     (1U << 2)       /* 1b */
#define VDE0_PWR_ON_2ND_LSB                 (1U << 3)       /* 1b */
#define VDE0_PWR_CLK_DIS_LSB                (1U << 4)       /* 1b */
#define VDE0_SRAM_PDN_LSB                   (1U << 8)       /* 4b */
#define SC_VDE0_SRAM_PDN_ACK_LSB            (1U << 24)      /* 4b */
/* VEN_PWR_CON (0x108C0000+0x304) */
#define VEN_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define VEN_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define VEN_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define VEN_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define VEN_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define VEN_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_VEN_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* ISP_PWR_CON (0x108C0000+0x308) */
#define ISP_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define ISP_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define ISP_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define ISP_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define ISP_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define ISP_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_ISP_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* CAM_PWR_CON (0x108C0000+0x30C) */
#define CAM_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define CAM_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define CAM_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define CAM_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define CAM_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define CAM_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_CAM_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* DIS0T_PWR_CON (0x108C0000+0x310) */
#define DIS0T_PWR_RST_B_LSB                 (1U << 0)       /* 1b */
#define DIS0T_PWR_ISO_LSB                   (1U << 1)       /* 1b */
#define DIS0T_PWR_ON_LSB                    (1U << 2)       /* 1b */
#define DIS0T_PWR_ON_2ND_LSB                (1U << 3)       /* 1b */
#define DIS0T_PWR_CLK_DIS_LSB               (1U << 4)       /* 1b */
#define DIS0T_SRAM_PDN_LSB                  (1U << 8)       /* 4b */
#define SC_DIS0T_SRAM_PDN_ACK_LSB           (1U << 24)      /* 4b */
/* AUD_PWR_CON (0x108C0000+0x314) */
#define AUD_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define AUD_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define AUD_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define AUD_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define AUD_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define AUD_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_AUD_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* IFR_PWR_CON (0x108C0000+0x318) */
#define IFR_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define IFR_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define IFR_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define IFR_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define IFR_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define IFR_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_IFR_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* MJC_PWR_CON (0x108C0000+0x31C) */
#define MJC_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define MJC_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define MJC_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define MJC_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define MJC_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define MJC_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_MJC_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* DPYA_PWR_CON (0x108C0000+0x320) */
#define DPYA_PWR_RST_B_LSB                  (1U << 0)       /* 1b */
#define DPYA_PWR_ISO_LSB                    (1U << 1)       /* 1b */
#define DPYA_PWR_ON_LSB                     (1U << 2)       /* 1b */
#define DPYA_PWR_ON_2ND_LSB                 (1U << 3)       /* 1b */
#define DPYA_PWR_CLK_DIS_LSB                (1U << 4)       /* 1b */
#define DPYA_SRAM_PDN_LSB                   (1U << 8)       /* 4b */
#define SC_DPYA_SRAM_PDN_ACK_LSB            (1U << 24)      /* 4b */
/* DPYB_PWR_CON (0x108C0000+0x324) */
#define REG_DPYB_PWR_RST_B_LSB              (1U << 0)       /* 1b */
#define REG_DPYB_PWR_ISO_LSB                (1U << 1)       /* 1b */
#define REG_DPYB_PWR_ON_LSB                 (1U << 2)       /* 1b */
#define REG_DPYB_PWR_ON_2ND_LSB             (1U << 3)       /* 1b */
#define REG_DPYB_PWR_CLK_DIS_LSB            (1U << 4)       /* 1b */
/* MD1_PWR_CON (0x108C0000+0x328) */
#define MD1_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define MD1_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define MD1_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define MD1_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define MD1_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
#define MD1_SRAM_PDN_LSB                    (1U << 8)       /* 4b */
#define SC_MD1_SRAM_PDN_ACK_LSB             (1U << 24)      /* 4b */
/* C2K_PWR_CON (0x108C0000+0x32C) */
#define C2K_PWR_RST_B_LSB                   (1U << 0)       /* 1b */
#define C2K_PWR_ISO_LSB                     (1U << 1)       /* 1b */
#define C2K_PWR_ON_LSB                      (1U << 2)       /* 1b */
#define C2K_PWR_ON_2ND_LSB                  (1U << 3)       /* 1b */
#define C2K_PWR_CLK_DIS_LSB                 (1U << 4)       /* 1b */
/* CONN_PWR_CON (0x108C0000+0x330) */
#define CONN_PWR_RST_B_LSB                  (1U << 0)       /* 1b */
#define CONN_PWR_ISO_LSB                    (1U << 1)       /* 1b */
#define CONN_PWR_ON_LSB                     (1U << 2)       /* 1b */
#define CONN_PWR_ON_2ND_LSB                 (1U << 3)       /* 1b */
#define CONN_PWR_CLK_DIS_LSB                (1U << 4)       /* 1b */
/* MFG_ASYNC_PWR_CON (0x108C0000+0x334) */
#define MFG_ASYNC_PWR_RST_B_LSB             (1U << 0)       /* 1b */
#define MFG_ASYNC_PWR_ISO_LSB               (1U << 1)       /* 1b */
#define MFG_ASYNC_PWR_ON_LSB                (1U << 2)       /* 1b */
#define MFG_ASYNC_PWR_ON_2ND_LSB            (1U << 3)       /* 1b */
#define MFG_ASYNC_PWR_CLK_DIS_LSB           (1U << 4)       /* 1b */
/* MFG_CORE0_PWR_CON (0x108C0000+0x340) */
#define MFG_CORE0_PWR_RST_B_LSB             (1U << 0)       /* 1b */
#define MFG_CORE0_PWR_ISO_LSB               (1U << 1)       /* 1b */
#define MFG_CORE0_PWR_ON_LSB                (1U << 2)       /* 1b */
#define MFG_CORE0_PWR_ON_2ND_LSB            (1U << 3)       /* 1b */
#define MFG_CORE0_PWR_CLK_DIS_LSB           (1U << 4)       /* 1b */
#define MFG_CORE0_SRAM_PDN_LSB              (1U << 8)       /* 4b */
#define SC_MFG_CORE0_SRAM_PDN_ACK_LSB       (1U << 24)      /* 4b */
/* MFG_CORE1_PWR_CON (0x108C0000+0x344) */
#define MFG_CORE1_PWR_RST_B_LSB             (1U << 0)       /* 1b */
#define MFG_CORE1_PWR_ISO_LSB               (1U << 1)       /* 1b */
#define MFG_CORE1_PWR_ON_LSB                (1U << 2)       /* 1b */
#define MFG_CORE1_PWR_ON_2ND_LSB            (1U << 3)       /* 1b */
#define MFG_CORE1_PWR_CLK_DIS_LSB           (1U << 4)       /* 1b */
#define MFG_CORE1_SRAM_PDN_LSB              (1U << 8)       /* 4b */
#define SC_MFG_CORE1_SRAM_PDN_ACK_LSB       (1U << 24)      /* 4b */
/* MFG_CORE2_PWR_CON (0x108C0000+0x348) */
#define MFG_CORE2_PWR_RST_B_LSB             (1U << 0)       /* 1b */
#define MFG_CORE2_PWR_ISO_LSB               (1U << 1)       /* 1b */
#define MFG_CORE2_PWR_ON_LSB                (1U << 2)       /* 1b */
#define MFG_CORE2_PWR_ON_2ND_LSB            (1U << 3)       /* 1b */
#define MFG_CORE2_PWR_CLK_DIS_LSB           (1U << 4)       /* 1b */
#define MFG_CORE2_SRAM_PDN_LSB              (1U << 8)       /* 4b */
#define SC_MFG_CORE2_SRAM_PDN_ACK_LSB       (1U << 24)      /* 4b */
/* MFG_CORE3_PWR_CON (0x108C0000+0x34C) */
#define MFG_CORE3_PWR_RST_B_LSB             (1U << 0)       /* 1b */
#define MFG_CORE3_PWR_ISO_LSB               (1U << 1)       /* 1b */
#define MFG_CORE3_PWR_ON_LSB                (1U << 2)       /* 1b */
#define MFG_CORE3_PWR_ON_2ND_LSB            (1U << 3)       /* 1b */
#define MFG_CORE3_PWR_CLK_DIS_LSB           (1U << 4)       /* 1b */
#define MFG_CORE3_SRAM_PDN_LSB              (1U << 8)       /* 4b */
#define SC_MFG_CORE3_SRAM_PDN_ACK_LSB       (1U << 24)      /* 4b */
/* MFG_TOP_PWR_CON (0x108C0000+0x350) */
#define MFG_TOP_PWR_RST_B_LSB               (1U << 0)       /* 1b */
#define MFG_TOP_PWR_ISO_LSB                 (1U << 1)       /* 1b */
#define MFG_TOP_PWR_ON_LSB                  (1U << 2)       /* 1b */
#define MFG_TOP_PWR_ON_2ND_LSB              (1U << 3)       /* 1b */
#define MFG_TOP_PWR_CLK_DIS_LSB             (1U << 4)       /* 1b */
#define MFG_TOP_SRAM_PDN_LSB                (1U << 8)       /* 4b */
#define SC_MFG_TOP_SRAM_PDN_ACK_LSB         (1U << 24)      /* 4b */
/* DUMMY0_PWR_CON (0x108C0000+0x354) */
#define DUMMY0_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define DUMMY0_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define DUMMY0_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define DUMMY0_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define DUMMY0_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
#define DUMMY0_SRAM_PDN_LSB                 (1U << 8)       /* 4b */
#define SC_DUMMY0_SRAM_PDN_ACK_LSB          (1U << 24)      /* 4b */
/* DUMMY1_PWR_CON (0x108C0000+0x358) */
#define DUMMY1_PWR_RST_B_LSB                (1U << 0)       /* 1b */
#define DUMMY1_PWR_ISO_LSB                  (1U << 1)       /* 1b */
#define DUMMY1_PWR_ON_LSB                   (1U << 2)       /* 1b */
#define DUMMY1_PWR_ON_2ND_LSB               (1U << 3)       /* 1b */
#define DUMMY1_PWR_CLK_DIS_LSB              (1U << 4)       /* 1b */
#define DUMMY1_SRAM_PDN_LSB                 (1U << 8)       /* 4b */
#define SC_DUMMY1_SRAM_PDN_ACK_LSB          (1U << 24)      /* 4b */
/* SYSRAM_CON (0x108C0000+0x370) */
#define SYSRAM_SRAM_CKISO_LSB               (1U << 0)       /* 1b */
#define SYSRAM_SRAM_ISOINT_B_LSB            (1U << 1)       /* 1b */
#define SYSRAM_SRAM_SLEEP_B_LSB             (1U << 4)       /* 12b */
#define SYSRAM_SRAM_PDN_LSB                 (1U << 16)      /* 12b */
/* SYSROM_CON (0x108C0000+0x374) */
#define SYSROM_SRAM_PDN_LSB                 (1U << 0)       /* 6b */
/* SCP_SRAM_CON (0x108C0000+0x378) */
#define SCP_SRAM_CKISO_LSB                  (1U << 0)       /* 1b */
#define SCP_SRAM_ISOINT_B_LSB               (1U << 1)       /* 1b */
#define SCP_SRAM_SLEEP_B_LSB                (1U << 4)       /* 1b */
#define SCP_SRAM_PDN_LSB                    (1U << 12)      /* 1b */
/* PMCU_SRAM_CON (0x108C0000+0x37C) */
#define PMCU_SRAM_CKISO_LSB                 (1U << 0)       /* 1b */
#define PMCU_SRAM_ISOINT_B_LSB              (1U << 1)       /* 1b */
#define PMCU_SRAM_SLEEP_B_LSB               (1U << 4)       /* 1b */
#define PMCU_SRAM_PDN_LSB                   (1U << 12)      /* 1b */
/* BSI_TOP_SRAM_CON (0x108C0000+0x38C) */
#define BSI_TOP_SRAM_CKISO_LSB              (1U << 0)       /* 1b */
#define BSI_TOP_SRAM_ISOINT_B_LSB           (1U << 1)       /* 1b */
#define BSI_TOP_SRAM_SLEEP_B_LSB            (1U << 4)       /* 12b */
#define BSI_TOP_SRAM_PDN_LSB                (1U << 16)      /* 12b */
/* AUD_ANC_SRAM_CON (0x108C0000+0x398) */
#define AUD_ANC_SRAM_CKISO_LSB              (1U << 0)       /* 1b */
#define AUD_ANC_SRAM_ISOINT_B_LSB           (1U << 1)       /* 1b */
#define AUD_ANC_SRAM_SLEEP_B_LSB            (1U << 4)       /* 2b */
#define AUD_ANC_SRAM_PDN_LSB                (1U << 12)      /* 2b */
/* EXT_BUCK_ISO (0x108C0000+0x39C) */
#define MD_EXT_BUCK_ISO_LSB                 (1U << 0)       /* 1b */
#define GPU_EXT_BUCK_ISO_LSB                (1U << 1)       /* 1b */
/* UFS_SRAM_CON (0x108C0000+0x3A0) */
#define UFS_SRAM_CKISO_LSB                  (1U << 0)       /* 1b */
#define UFS_SRAM_ISOINT_B_LSB               (1U << 1)       /* 1b */
#define UFS_SRAM_SLEEP_B_LSB                (1U << 4)       /* 5b */
#define UFS_SRAM_PDN_LSB                    (1U << 16)      /* 5b */
/* DXCC_SRAM_CON (0x108C0000+0x3A4) */
#define DXCC_SRAM_CKISO_LSB                 (1U << 0)       /* 2b */
#define DXCC_SRAM_ISOINT_B_LSB              (1U << 2)       /* 2b */
#define DXCC_SRAM_SLEEP_B_LSB               (1U << 4)       /* 12b */
#define DXCC_SRAM_PDN_LSB                   (1U << 16)      /* 12b */
/* SPM_DVFS_CON (0x108C0000+0x400) */
#define DVFS_CTRL_LSB                       (1U << 0)       /* 4b */
#define SPM_DVFS_ACK_LSB                    (1U << 30)      /* 2b */
/* SPM_MDBSI_CON (0x108C0000+0x404) */
#define AP_BSI_BUF_EN_LSB                   (1U << 0)       /* 3b */
/* SPM_MAS_PAUSE_MASK_B (0x108C0000+0x408) */
#define RG_PCM_PAUSE_MASK_B_LSB             (1U << 0)       /* 32b */
/* SPM_MAS_PAUSE2_MASK_B (0x108C0000+0x40C) */
#define RG_PCM_PAUSE2_MASK_B_LSB            (1U << 0)       /* 32b */
/* SPM_BSI_GEN (0x108C0000+0x410) */
#define SPM_BSI_START_LSB                   (1U << 0)       /* 1b */
/* SPM_BSI_EN_SR (0x108C0000+0x414) */
#define SPM_BSI_EN_SR_LSB                   (1U << 0)       /* 32b */
/* SPM_BSI_CLK_SR (0x108C0000+0x418) */
#define SPM_BSI_CLK_SR_LSB                  (1U << 0)       /* 32b */
/* SPM_BSI_D0_SR (0x108C0000+0x41C) */
#define SPM_BSI_D0_SR_LSB                   (1U << 0)       /* 32b */
/* SPM_BSI_D1_SR (0x108C0000+0x420) */
#define SPM_BSI_D1_SR_LSB                   (1U << 0)       /* 32b */
/* SPM_BSI_D2_SR (0x108C0000+0x424) */
#define SPM_BSI_D2_SR_LSB                   (1U << 0)       /* 32b */
/* AP2MD_CROSS_TRIGGER (0x108C0000+0x438) */
#define AP2MD_CROSS_TRIGGER_REQ_LSB         (1U << 0)       /* 1b */
#define AP2MD_CROSS_TRIGGER_ACK_LSB         (1U << 1)       /* 1b */
/* AP_MDSRC_REQ (0x108C0000+0x43C) */
#define AP_MD1SRC_REQ_LSB                   (1U << 0)       /* 1b */
#define AP_MD2SRC_REQ_LSB                   (1U << 1)       /* 1b */
#define AP_MD1SRC_ACK_LSB                   (1U << 4)       /* 1b */
#define AP_MD2SRC_ACK_LSB                   (1U << 5)       /* 1b */
/* SPM2MD_DVFS_CON (0x108C0000+0x444) */
#define SPM2MD_DVFS_CON_LSB                 (1U << 0)       /* 32b */
/* MD2SPM_DVFS_CON (0x108C0000+0x448) */
#define MD2SPM_DVFS_CON_LSB                 (1U << 0)       /* 32b */
/* SPM_PLL_CON (0x108C0000+0x454) */
#define SC_UNIPLLOUT_OFF_LSB                (1U << 1)       /* 1b */
#define SC_UNIPLL_OFF_LSB                   (1U << 2)       /* 1b */
#define SC_UNIDDS_OFF_LSB                   (1U << 3)       /* 1b */
#define SC_MD32K_CK_OFF_LSB                 (1U << 16)      /* 1b */
/* AP2MD_PEER_WAKEUP (0x108C0000+0x458) */
#define AP2MD_PEER_WAKEUP_LSB               (1U << 0)       /* 1b */
/* ULPOSC_CON (0x108C0000+0x45C) */
#define ULPOSC_EN_LSB                       (1U << 0)       /* 1b */
#define ULPOSC_RST_LSB                      (1U << 1)       /* 1b */
#define ULPOSC_CG_EN_LSB                    (1U << 2)       /* 1b */
#define ULPOSC_CLK_SEL_LSB                  (1U << 3)       /* 1b */
/* DRAMC_DPY_CLK_SW_CON_SEL (0x108C0000+0x460) */
#define SW_DR_GATE_RETRY_EN_SEL_LSB         (1U << 0)       /* 2b */
#define SW_EMI_CLK_OFF_SEL_LSB              (1U << 2)       /* 2b */
#define SW_DPY_MODE_SW_SEL_LSB              (1U << 4)       /* 2b */
#define SW_DMSUS_OFF_SEL_LSB                (1U << 6)       /* 2b */
#define SW_MEM_CK_OFF_SEL_LSB               (1U << 8)       /* 2b */
#define SW_DPY_2ND_DLL_EN_SEL_LSB           (1U << 10)      /* 2b */
#define SW_DPY_DLL_EN_SEL_LSB               (1U << 12)      /* 2b */
#define SW_DPY_DLL_CK_EN_SEL_LSB            (1U << 14)      /* 2b */
#define SW_DPY_VREF_EN_SEL_LSB              (1U << 16)      /* 2b */
#define SW_PHYPLL_EN_SEL_LSB                (1U << 18)      /* 2b */
#define SW_DDRPHY_FB_CK_EN_SEL_LSB          (1U << 20)      /* 2b */
#define SEPARATE_PHY_PWR_SEL_LSB            (1U << 23)      /* 1b */
#define SW_DMDRAMCSHU_ACK_SEL_LSB           (1U << 24)      /* 2b */
#define SW_EMI_CLK_OFF_ACK_SEL_LSB          (1U << 26)      /* 2b */
#define SW_DR_SHORT_QUEUE_ACK_SEL_LSB       (1U << 28)      /* 2b */
#define SW_DRAMC_DFS_STA_SEL_LSB            (1U << 30)      /* 2b */
/* DRAMC_DPY_CLK_SW_CON (0x108C0000+0x464) */
#define SW_DR_GATE_RETRY_EN_LSB             (1U << 0)       /* 2b */
#define SW_EMI_CLK_OFF_LSB                  (1U << 2)       /* 2b */
#define SW_DPY_MODE_SW_LSB                  (1U << 4)       /* 2b */
#define SW_DMSUS_OFF_LSB                    (1U << 6)       /* 2b */
#define SW_MEM_CK_OFF_LSB                   (1U << 8)       /* 2b */
#define SW_DPY_2ND_DLL_EN_LSB               (1U << 10)      /* 2b */
#define SW_DPY_DLL_EN_LSB                   (1U << 12)      /* 2b */
#define SW_DPY_DLL_CK_EN_LSB                (1U << 14)      /* 2b */
#define SW_DPY_VREF_EN_LSB                  (1U << 16)      /* 2b */
#define SW_PHYPLL_EN_LSB                    (1U << 18)      /* 2b */
#define SW_DDRPHY_FB_CK_EN_LSB              (1U << 20)      /* 2b */
#define SC_DR_SHU_EN_ACK_LSB                (1U << 24)      /* 2b */
#define EMI_CLK_OFF_ACK_LSB                 (1U << 26)      /* 2b */
#define SC_DR_SHORT_QUEUE_ACK_LSB           (1U << 28)      /* 2b */
#define SC_DRAMC_DFS_STA_LSB                (1U << 30)      /* 2b */
/* DRAMC_DPY_CLK_SW_CON_SEL2 (0x108C0000+0x470) */
#define SW_PHYPLL_SHU_EN_SEL_LSB            (1U << 0)       /* 1b */
#define SW_PHYPLL2_SHU_EN_SEL_LSB           (1U << 1)       /* 1b */
#define SW_PHYPLL_MODE_SW_SEL_LSB           (1U << 2)       /* 1b */
#define SW_PHYPLL2_MODE_SW_SEL_LSB          (1U << 3)       /* 1b */
#define SW_DR_SHORT_QUEUE_SEL_LSB           (1U << 4)       /* 1b */
#define SW_DR_SHU_EN_SEL_LSB                (1U << 5)       /* 1b */
#define SW_DR_SHU_LEVEL_SEL_LSB             (1U << 6)       /* 1b */
/* DRAMC_DPY_CLK_SW_CON2 (0x108C0000+0x474) */
#define SW_PHYPLL_SHU_EN_LSB                (1U << 0)       /* 1b */
#define SW_PHYPLL2_SHU_EN_LSB               (1U << 1)       /* 1b */
#define SW_PHYPLL_MODE_SW_LSB               (1U << 2)       /* 1b */
#define SW_PHYPLL2_MODE_SW_LSB              (1U << 3)       /* 1b */
#define SW_DR_SHORT_QUEUE_LSB               (1U << 4)       /* 1b */
#define SW_DR_SHU_EN_LSB                    (1U << 5)       /* 1b */
#define SW_DR_SHU_LEVEL_LSB                 (1U << 6)       /* 2b */
#define SPM2MM_ULTRAREQ_LSB                 (1U << 8)       /* 1b */
#define SPM2MD_ULTRAREQ_LSB                 (1U << 9)       /* 1b */
#define SPM2ISP_ULTRAACK_D2T_LSB            (1U << 29)      /* 1b */
#define SPM2MM_ULTRAACK_D2T_LSB             (1U << 30)      /* 1b */
#define SPM2MD_ULTRAACK_D2T_LSB             (1U << 31)      /* 1b */
/* DVFS_LEVEL (0x108C0000+0x478) */
#define CURRENT_DVFS_LEVEL_LSB              (1U << 0)       /* 5b */
#define REG_DVFS_PRE_START_LSB              (1U << 5)       /* 1b */
#define DVFS_PRE_START_SEL_LSB              (1U << 6)       /* 1b */
#define SPM_HWVCORE_DVFS_DISABLE_LSB        (1U << 7)       /* 1b */
#define CURRENT_DVS_LEVEL_LSB               (1U << 8)       /* 4b */
#define CURRENT_DFS_LEVEL_LSB               (1U << 12)      /* 4b */
#define NEXT_DVFS_LEVEL_LSB                 (1U << 16)      /* 5b */
/* MSDC_DVFS_HALT (0x108C0000+0x47C) */
#define MSDC_ALL_DVFS_HALT_LSB              (1U << 0)       /* 1b */
#define MSDC1_DVFS_HALT_LSB                 (1U << 1)       /* 1b */
#define MSDC2_DVFS_HALT_LSB                 (1U << 2)       /* 1b */
#define MSDC3_DVFS_HALT_LSB                 (1U << 3)       /* 1b */
/* MP0_CPU0_IRQ_MASK (0x108C0000+0x500) */
#define MP0_CPU0_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP0_CPU0_AUX_LSB                    (1U << 8)       /* 11b */
/* MP0_CPU1_IRQ_MASK (0x108C0000+0x504) */
#define MP0_CPU1_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP0_CPU1_AUX_LSB                    (1U << 8)       /* 11b */
/* MP0_CPU2_IRQ_MASK (0x108C0000+0x508) */
#define MP0_CPU2_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP0_CPU2_AUX_LSB                    (1U << 8)       /* 11b */
/* MP0_CPU3_IRQ_MASK (0x108C0000+0x50C) */
#define MP0_CPU3_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP0_CPU3_AUX_LSB                    (1U << 8)       /* 11b */
/* MP1_CPU0_IRQ_MASK (0x108C0000+0x510) */
#define MP1_CPU0_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP1_CPU0_AUX_LSB                    (1U << 8)       /* 11b */
/* MP1_CPU1_IRQ_MASK (0x108C0000+0x514) */
#define MP1_CPU1_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP1_CPU1_AUX_LSB                    (1U << 8)       /* 11b */
/* MP1_CPU2_IRQ_MASK (0x108C0000+0x518) */
#define MP1_CPU2_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP1_CPU2_AUX_LSB                    (1U << 8)       /* 11b */
/* MP1_CPU3_IRQ_MASK (0x108C0000+0x51C) */
#define MP1_CPU3_IRQ_MASK_LSB               (1U << 0)       /* 1b */
#define MP1_CPU3_AUX_LSB                    (1U << 8)       /* 11b */
/* DEBUG0_IRQ_MASK (0x108C0000+0x520) */
#define DEBUG0_IRQ_MASK_LSB                 (1U << 0)       /* 1b */
#define DEBUG0_AUX_LSB                      (1U << 8)       /* 11b */
/* DEBUG1_IRQ_MASK (0x108C0000+0x524) */
#define DEBUG1_IRQ_MASK_LSB                 (1U << 0)       /* 1b */
#define DEBUG1_AUX_LSB                      (1U << 8)       /* 11b */
/* DEBUG2_IRQ_MASK (0x108C0000+0x528) */
#define DEBUG2_IRQ_MASK_LSB                 (1U << 0)       /* 1b */
#define DEBUG2_AUX_LSB                      (1U << 8)       /* 11b */
/* DEBUG3_IRQ_MASK (0x108C0000+0x52C) */
#define DEBUG3_IRQ_MASK_LSB                 (1U << 0)       /* 1b */
#define DEBUG3_AUX_LSB                      (1U << 8)       /* 11b */
/* MP0_CPU0_WFI_EN (0x108C0000+0x540) */
#define MP0_CPU0_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP0_CPU1_WFI_EN (0x108C0000+0x544) */
#define MP0_CPU1_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP0_CPU2_WFI_EN (0x108C0000+0x548) */
#define MP0_CPU2_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP0_CPU3_WFI_EN (0x108C0000+0x54C) */
#define MP0_CPU3_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP1_CPU0_WFI_EN (0x108C0000+0x550) */
#define MP1_CPU0_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP1_CPU1_WFI_EN (0x108C0000+0x554) */
#define MP1_CPU1_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP1_CPU2_WFI_EN (0x108C0000+0x558) */
#define MP1_CPU2_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* MP1_CPU3_WFI_EN (0x108C0000+0x55C) */
#define MP1_CPU3_WFI_EN_LSB                 (1U << 0)       /* 1b */
/* DEBUG0_WFI_EN (0x108C0000+0x560) */
#define DEBUG0_WFI_EN_LSB                   (1U << 0)       /* 1b */
/* DEBUG1_WFI_EN (0x108C0000+0x564) */
#define DEBUG1_WFI_EN_LSB                   (1U << 0)       /* 1b */
/* DEBUG2_WFI_EN (0x108C0000+0x568) */
#define DEBUG2_WFI_EN_LSB                   (1U << 0)       /* 1b */
/* DEBUG3_WFI_EN (0x108C0000+0x56C) */
#define DEBUG3_WFI_EN_LSB                   (1U << 0)       /* 1b */
/* SPM_SW_FLAG (0x108C0000+0x600) */
#define SPM_SW_FLAG_LSB                     (1U << 0)       /* 32b */
/* SPM_SW_DEBUG (0x108C0000+0x604) */
#define SPM_SW_DEBUG_LSB                    (1U << 0)       /* 32b */
/* SPM_SW_RSV_0 (0x108C0000+0x608) */
#define SPM_SW_RSV_0_LSB                    (1U << 0)       /* 32b */
/* SPM_SW_RSV_1 (0x108C0000+0x60C) */
#define SPM_SW_RSV_1_LSB                    (1U << 0)       /* 32b */
/* SPM_SW_RSV_2 (0x108C0000+0x610) */
#define SPM_SW_RSV_2_LSB                    (1U << 0)       /* 32b */
/* SPM_SW_RSV_3 (0x108C0000+0x614) */
#define SPM_SW_RSV_3_LSB                    (1U << 0)       /* 32b */
/* SPM_SW_RSV_4 (0x108C0000+0x618) */
#define SPM_SW_RSV_4_LSB                    (1U << 0)       /* 32b */
/* SPM_SW_RSV_5 (0x108C0000+0x61C) */
#define SPM_SW_RSV_5_LSB                    (1U << 0)       /* 32b */
/* SPM_RSV_CON (0x108C0000+0x620) */
#define SPM_RSV_CON_LSB                     (1U << 0)       /* 16b */
/* SPM_RSV_STA (0x108C0000+0x624) */
#define SPM_RSV_STA_LSB                     (1U << 0)       /* 16b */
/* SPM_RSV_STA2 (0x108C0000+0x628) */
#define SPM_RSV_STA2_LSB                    (1U << 0)       /* 16b */
/* SPM_PASR_DPD_0 (0x108C0000+0x630) */
#define SPM_PASR_DPD_0_LSB                  (1U << 0)       /* 32b */
/* SPM_PASR_DPD_1 (0x108C0000+0x634) */
#define SPM_PASR_DPD_1_LSB                  (1U << 0)       /* 32b */
/* SPM_PASR_DPD_2 (0x108C0000+0x638) */
#define SPM_PASR_DPD_2_LSB                  (1U << 0)       /* 32b */
/* SPM_PASR_DPD_3 (0x108C0000+0x63C) */
#define SPM_PASR_DPD_3_LSB                  (1U << 0)       /* 32b */
/* SPM2PMCU_INT_SET (0x108C0000+0x10C00) */
#define SPM2PMCU_INT_SET_LSB                (1U << 0)       /* 4b */
/* SPM2PMCU_INT_CLR (0x108C0000+0x10C04) */
#define SPM2PMCU_INT_CLR_LSB                (1U << 0)       /* 4b */
/* SPM2PMCU_INT (0x108C0000+0x10C08) */
#define SPM2PMCU_INT_LSB                    (1U << 0)       /* 4b */
/* PMCU2SPM_MAILBOX_0 (0x108C0000+0x10C20) */
#define PMCU2SPM_MAILBOX_0_LSB              (1U << 0)       /* 32b */
/* PMCU2SPM_MAILBOX_1 (0x108C0000+0x10C24) */
#define PMCU2SPM_MAILBOX_1_LSB              (1U << 0)       /* 32b */
/* PMCU2SPM_MAILBOX_2 (0x108C0000+0x10C28) */
#define PMCU2SPM_MAILBOX_2_LSB              (1U << 0)       /* 32b */
/* PMCU2SPM_MAILBOX_3 (0x108C0000+0x10C2C) */
#define PMCU2SPM_MAILBOX_3_LSB              (1U << 0)       /* 32b */
/* SPM2PMCU_MAILBOX_0 (0x108C0000+0x10C30) */
#define SPM2PMCU_MAILBOX_0_LSB              (1U << 0)       /* 32b */
/* SPM2PMCU_MAILBOX_1 (0x108C0000+0x10C34) */
#define SPM2PMCU_MAILBOX_1_LSB              (1U << 0)       /* 32b */
/* SPM2PMCU_MAILBOX_2 (0x108C0000+0x10C38) */
#define SPM2PMCU_MAILBOX_2_LSB              (1U << 0)       /* 32b */
/* SPM2PMCU_MAILBOX_3 (0x108C0000+0x10C3C) */
#define SPM2PMCU_MAILBOX_3_LSB              (1U << 0)       /* 32b */
/* PMCU2SPM_INT_SET (0x108C0000+0x10C40) */
#define PMCU2SPM_INT_SET_LSB                (1U << 0)       /* 4b */
/* PMCU2SPM_INT_CLR (0x108C0000+0x10C44) */
#define PMCU2SPM_INT_CLR_LSB                (1U << 0)       /* 4b */
/* PMCU2SPM_INT (0x108C0000+0x10C48) */
#define PMCU2SPM_INT_LSB                    (1U << 0)       /* 4b */
/* SPM_SWINT_SET (0x108C0000+0x20E00) */
#define SPM_SWINT_SET_LSB                   (1U << 0)       /* 16b */
/* SPM_SWINT_CLR (0x108C0000+0x20E04) */
#define SPM_SWINT_CLR_LSB                   (1U << 0)       /* 16b */
/* SPM_SWINT (0x108C0000+0x20E08) */
#define SPM_SWINT_LSB                       (1U << 0)       /* 16b */
/* SPM_SW_NONSERSV_0 (0x108C0000+0x20E10) */
#define SPM_SW_NONSERSV_0_LSB               (1U << 0)       /* 32b */
/* SPM_SW_NONSERSV_1 (0x108C0000+0x20E14) */
#define SPM_SW_NONSERSV_1_LSB               (1U << 0)       /* 32b */
/* SPM_SW_NONSERSV_2 (0x108C0000+0x20E18) */
#define SPM_SW_NONSERSV_2_LSB               (1U << 0)       /* 32b */
/* SPM_SW_NONSERSV_3 (0x108C0000+0x20E1C) */
#define SPM_SW_NONSERSV_3_LSB               (1U << 0)       /* 32b */
/* SW2SPM_MAILBOX_0 (0x108C0000+0x20E20) */
#define SW2SPM_MAILBOX_0_LSB                (1U << 0)       /* 32b */
/* SW2SPM_MAILBOX_1 (0x108C0000+0x20E24) */
#define SW2SPM_MAILBOX_1_LSB                (1U << 0)       /* 32b */
/* SW2SPM_MAILBOX_2 (0x108C0000+0x20E28) */
#define SW2SPM_MAILBOX_2_LSB                (1U << 0)       /* 32b */
/* SW2SPM_MAILBOX_3 (0x108C0000+0x20E2C) */
#define SW2SPM_MAILBOX_3_LSB                (1U << 0)       /* 32b */
/* SPM2SW_MAILBOX_0 (0x108C0000+0x20E30) */
#define SPM2SW_MAILBOX_0_LSB                (1U << 0)       /* 32b */
/* SPM2SW_MAILBOX_1 (0x108C0000+0x20E34) */
#define SPM2SW_MAILBOX_1_LSB                (1U << 0)       /* 32b */
/* SPM2SW_MAILBOX_2 (0x108C0000+0x20E38) */
#define SPM2SW_MAILBOX_2_LSB                (1U << 0)       /* 32b */
/* SPM2SW_MAILBOX_3 (0x108C0000+0x20E3C) */
#define SPM2SW_MAILBOX_3_LSB                (1U << 0)       /* 32b */
/* SW2SPM_INT_SET (0x108C0000+0x20E40) */
#define SW2SPM_INT_SET_LSB                  (1U << 0)       /* 4b */
/* SW2SPM_INT_CLR (0x108C0000+0x20E44) */
#define SW2SPM_INT_CLR_LSB                  (1U << 0)       /* 4b */
/* SW2SPM_INT (0x108C0000+0x20E48) */
#define SW2SPM_INT_LSB                      (1U << 0)       /* 4b */
/* SPM_SEMA_M0 (0x108C0000+0x20E50) */
#define SPM_SEMA_M0_LSB                     (1U << 0)       /* 8b */
/* SPM_SEMA_M1 (0x108C0000+0x20E54) */
#define SPM_SEMA_M1_LSB                     (1U << 0)       /* 8b */
/* SPM_SEMA_M2 (0x108C0000+0x20E58) */
#define SPM_SEMA_M2_LSB                     (1U << 0)       /* 8b */
/* SPM_SEMA_M3 (0x108C0000+0x20E5C) */
#define SPM_SEMA_M3_LSB                     (1U << 0)       /* 8b */
/* CPU_HOTPLUG_SET (0x108C0000+0x20E60) */
#define CPU_HOTPLUG_SET_LSB                 (1U << 0)       /* 16b */
/* CPU_HOTPLUG_CLR (0x108C0000+0x20E64) */
#define CPU_HOTPLUG_CLR_LSB                 (1U << 0)       /* 16b */
/* CPU_HOTPLUG (0x108C0000+0x20E68) */
#define CPU_HOTPLUG_LSB                     (1U << 0)       /* 16b */

#define SPM_PROJECT_CODE	0xb16
#define SPM_REGWR_CFG_KEY	(SPM_PROJECT_CODE << 16)

#define spm_read(addr)			__raw_readl((void __force __iomem *)(addr))
#define spm_write(addr, val)		mt_reg_sync_writel(val, addr)

#endif
