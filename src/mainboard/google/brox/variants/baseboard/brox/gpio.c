/* SPDX-License-Identifier: GPL-2.0-or-later */

/* This header block is used to supply information to arbitrage, a
 * google-internal tool. Updating it incorrectly will lead to issues,
 * so please don't update it unless a change is specifically required.
 * BaseID: E3110FFB1FCDA587
 * Overrides: None
 */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <commonlib/helpers.h>
#include <soc/gpio.h>
#include <vendorcode/google/chromeos/chromeos.h>

/* Pad configuration in ramstage */
static const struct pad_config gpio_table[] = {
	/* GPD0 : [NF1: BATLOW#] ==> BATLOW_L */
	PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
	/* GPD1 : [NF1: ACPRESENT] ==> ACPRESENT */
	PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
	/* GPD2 : [NF1: LAN_WAKE#] ==> SOC_GPD2 */
	PAD_NC(GPD2, NONE),
	/* GPD3 : [NF1: PWRBTN#] ==> EC_PCH_PWR_BTN_ODL */
	PAD_CFG_NF(GPD3, NONE, DEEP, NF1),
	/* GPD4 : [NF1: SLP_S3#] ==> SLP_S3_R_L */
	PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
	/* GPD5 : [NF1: SLP_S4#] ==> SLP_S4_L */
	PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
	/* GPD6 : [NF1: SLP_A#] ==> SLP_A_L_CAP_SITE */
	PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
	/* GPD7 : GPD7_STRAP ==> SOC_GPD7_STRAP */
	PAD_NC(GPD7, DN_20K),
	/* GPD8 : [NF1: SUSCLK] ==> PCH_SUSCLK */
	PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
	/* GPD9 : [NF1: SLP_WLAN#] ==> SLP_WLAN_L_CAP_SITE */
	PAD_CFG_NF(GPD9, NONE, DEEP, NF1),
	/* GPD10 : [NF1: SLP_S5#] ==> SLP_S5_L */
	PAD_CFG_NF(GPD10, NONE, DEEP, NF1),
	/* GPD11 : LANPHYPC ==> TP99 */
	PAD_NC(GPD11, NONE),
	/* GPP_A0 : GPP_A0 ==> ESPI_PCH_D0_EC_R configured on reset, do not touch */
	/* GPP_A1 : GPP_A1 ==> ESPI_PCH_D1_EC_R configured on reset, do not touch */
	/* GPP_A2 : GPP_A2 ==> ESPI_PCH_D2_EC_R configured on reset, do not touch */
	/* GPP_A3 : GPP_A3 ==> ESPI_PCH_D3_EC_R configured on reset, do not touch */
	/* GPP_A4 : GPP_A4 ==> ESPI_PCH_CS_EC_R_L configured on reset, do not touch */
	/* GPP_A5 : [NF1: ESPI_ALERT0# NF6: USB_C_GPP_A5] ==> TP78 */
	PAD_NC(GPP_A5, NONE),
	/* GPP_A6 : [NF1: ESPI_ALERT1# NF6: USB_C_GPP_A6] ==> TP88 */
	PAD_NC(GPP_A6, NONE),
	/* GPP_A7 : SRCCLK_OE7_L ==> RAM_TYPE0 */
	PAD_CFG_GPI(GPP_A7, NONE, DEEP),
	/* GPP_A8 : SRCCLKREQ7_L ==> RAM_TYPE1 */
	PAD_CFG_GPI(GPP_A8, NONE, DEEP),
	/* GPP_A9 : GPP_A9 ==> ESPI_PCH_CLK_R configured on reset, do not touch */
	/* GPP_A10 : GPP_A10 ==> ESPI_PCH_RST_EC_L configured on reset, do not touch */
	/* GPP_A11 : BOARD_ID2 */
	PAD_CFG_GPI(GPP_A11, NONE, DEEP),
	/* GPP_A12 : [NF1: SATAXPCIE1 NF2: SATAGP1 NF4: SRCCLKREQ9B# NF6: USB_C_GPP_A12] ==> TPM_PWR_EN_L */
	PAD_CFG_GPO(GPP_A12, 0, DEEP),
	/* GPP_A13 : [NF6: USB_C_GPP_A13] ==> BT_DISABLE_L */
	PAD_CFG_GPO(GPP_A13, 1, DEEP),
	/* GPP_A14 : [NF1: USB_OC1# NF2: DDSP_HPD3 NF4: DISP_MISC3 NF6: USB_C_GPP_A14] ==> USB_A0_OC_ODL */
	PAD_CFG_NF(GPP_A14, NONE, DEEP, NF1),
	/* GPP_A15 : [NF1: USB_OC2# NF2: DDSP_HPD4 NF4: DISP_MISC4 NF6: USB_C_GPP_A15] ==> USB_A1_OC_ODL */
	PAD_CFG_NF(GPP_A15, NONE, DEEP, NF1),
	/* GPP_A16 : [NF1: USB_OC3# NF4: ISH_GP5 NF6: USB_C_GPP_A16] ==> TABLET_MODE_ODL */
	PAD_CFG_GPI(GPP_A16, NONE, DEEP),
	/* GPP_A17 : [NF4: DISP_MISCC NF6: USB_C_GPP_A17] ==> SOC_GPP_A17 */
	PAD_NC(GPP_A17, NONE),
	/* GPP_A18 : [NF1: DDSP_HPDB NF4: DISP_MISCB NF6: USB_C_GPP_A18] ==> HDMI_HPD */
	PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1),
	/* GPP_A19 : [NF1: DDSP_HPD1 NF4: DISP_MISC1 NF6: USB_C_GPP_A19] ==> USB_C2_AUX_DC_P */
	PAD_CFG_NF(GPP_A19, NONE, DEEP, NF6),
	/* GPP_A20 : [NF1: DDSP_HPD2 NF4: DISP_MISC2 NF6: USB_C_GPP_A20] ==> USB_C2_AUX_DC_N */
	PAD_CFG_NF(GPP_A20, NONE, DEEP, NF6),
	/* GPP_A21 : [NF1: DDPC_CTRLCLK NF6: USB_C_GPP_A21] ==> SOC_GPP_A21 */
	PAD_NC(GPP_A21, NONE),
	/* GPP_A22 : DDPC_CTRLDATA ==> PD_SOC_DBG_L */
	PAD_CFG_GPI(GPP_A22, NONE, DEEP),
	/* GPP_A23 : ESPI_CS1_L ==> RAM_INTERLEAVED */
	PAD_CFG_GPI(GPP_A23, NONE, DEEP),

	/* GPP_B0 : [NF1: CORE_VID0 NF6: USB_C_GPP_B0] ==> SOC_VID0 */
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
	/* GPP_B1 : [NF1: CORE_VID1 NF6: USB_C_GPP_B1] ==> SOC_VID1 */
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),
	/* GPP_B2 : [NF1: VRALERT# NF6: USB_C_GPP_B2] ==> VRALERT_L */
	PAD_CFG_NF(GPP_B2, NONE, DEEP, NF1),
	/* GPP_B3 : [NF1: PROC_GP2 NF4: ISH_GP4B NF6: USB_C_GPP_B3] ==> WLAN_PCIE_WAKE_ODL */
	PAD_CFG_GPI_INT(GPP_B3, NONE, PLTRST, EDGE_SINGLE),
	/* GPP_B4 : PROC_GP3/ISH_GP5B ==> BOARD_ID9 */
	PAD_CFG_GPI(GPP_B4, NONE, DEEP),
	/* GPP_B5 : [NF1: ISH_I2C0_SDA NF2: I2C2_SDA NF6: USB_C_GPP_B5] ==> ISH_I2C_SENSOR_SDA */
	PAD_CFG_NF(GPP_B5, NONE, DEEP, NF2),
	/* GPP_B6 : [NF1: ISH_I2C0_SCL NF2: I2C2_SCL NF6: USB_C_GPP_B6] ==> ISH_I2C_SENSOR_SCL */
	PAD_CFG_NF(GPP_B6, NONE, DEEP, NF2),
	/* GPP_B7 : [NF1: ISH_I2C1_SDA NF2: I2C3_SDA NF6: USB_C_GPP_B7] ==> SOC_I2C3_SDA */
	PAD_NC(GPP_B7, NONE),
	/* GPP_B8 : [NF1: ISH_I2C1_SCL NF2: I2C3_SCL NF6: USB_C_GPP_B8] ==> SOC_I2C3_SCL */
	PAD_NC(GPP_B8, NONE),
	/* GPP_B11 : [NF1: PMCALERT# NF6: USB_C_GPP_B11] ==> SOC_I2C_PD_INT_ODL */
	PAD_CFG_GPI_APIC_LOCK(GPP_B11, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_B12 : [NF1: SLP_S0# NF6: USB_C_GPP_B12] ==> SLP_S0_R_L */
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	/* GPP_B13 : [NF1: PLTRST# NF6: USB_C_GPP_B13] ==> PLT_RST_L */
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	/* GPP_B14 : [NF1: SPKR NF2: TIME_SYNC1 NF4: SATA_LED# NF5: ISH_GP6 NF6: USB_C_GPP_B14] ==> ACZ_SPKR */
	PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1),
	/* GPP_B15 : [NF2: TIME_SYNC0 NF5: ISH_GP7 NF6: USB_C_GPP_B15] ==> LID_OPEN_Q */
	PAD_CFG_GPI(GPP_B15, NONE, DEEP),
	/* GPP_B16 : [NF2: I2C5_SDA NF4: ISH_I2C2_SDA NF6: USB_C_GPP_B16] ==> ISH_I2C_EC_SDA */
	PAD_CFG_NF(GPP_B16, NONE, DEEP, NF2),
	/* GPP_B17 : [NF2: I2C5_SCL NF4: ISH_I2C2_SCL NF6: USB_C_GPP_B17] ==> ISH_I2C_EC_SCL */
	PAD_CFG_NF(GPP_B17, NONE, DEEP, NF2),
	/* GPP_B18 : GPP_B18 ==> GPP_B18_STRAP */
	PAD_NC(GPP_B18, DN_20K),
	/* GPP_B23 : SML1ALERT_L/PCHHOT_L ==> PCHHOT_ODL_STRAP */
	PAD_CFG_GPI(GPP_B23, DN_20K, DEEP),

	/* GPP_C0 : [NF1: SMBCLK NF6: USB_C_GPP_C0] ==> SOC_GPP_C0 */
	PAD_NC(GPP_C0, NONE),
	/* GPP_C1 : [NF1: SMBDATA NF6: USB_C_GPP_C1] ==> SOC_GPP_C1 */
	PAD_NC(GPP_C1, NONE),
	/* GPP_C2 : SMBALAERT_L ==> SOC_GPP_C2_STRAP */
	PAD_NC(GPP_C2, DN_20K),
	/* GPP_C3 : [NF1: SML0CLK NF6: USB_C_GPP_C3] ==> SMB_SML0_CLK */
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
	/* GPP_C4 : [NF1: SML0DATA NF6: USB_C_GPP_C4] ==> SMB_SML0_DAT */
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
	/* GPP_C5 : [NF1: SML0ALERT# NF6: USB_C_GPP_C5] ==> SOC_GPP_C5_BOOT_STRAP0 */
	PAD_CFG_GPI(GPP_C5, NONE, DEEP),
	/* GPP_C6 : SML1CLK ==> SOC_I2C_PD_SCL */
	PAD_CFG_NF(GPP_C6, NONE, DEEP, NF1),
	/* GPP_C7 : SML1DATA ==> SOC_I2C_PD_SDA */
	PAD_NC(GPP_C7, NONE),

	/* GPP_D0 : [NF1: ISH_GP0 NF2: BK0 NF5: SBK0 NF6: USB_C_GPP_D0] ==> SENSOR_MODE1_PCH_EC_PCH_WAKE_ODL */
	PAD_CFG_GPI_IRQ_WAKE(GPP_D0, NONE, PLTRST, EDGE_SINGLE, INVERT),
	/* GPP_D1 : [NF1: ISH_GP1 NF2: BK1 NF5: SBK1 NF6: USB_C_GPP_D1] ==> SENSOR_MODE2_PCH_EC_PCH_INT_ODL */
	PAD_CFG_GPI_INT(GPP_D1, NONE, PLTRST, LEVEL),
	/* GPP_D2 : [NF1: ISH_GP2 NF2: BK2 NF5: SBK2 NF6: USB_C_GPP_D2] ==> ISH_ACCEL_DB_INT_L */
	PAD_CFG_GPI_INT(GPP_D2, NONE, PLTRST, LEVEL),
	/* GPP_D3 : [NF1: ISH_GP3 NF2: BK3 NF5: SBK3 NF6: USB_C_GPP_D3] ==> ISH_ACCEL_MB_INT_L */
	PAD_CFG_GPI_INT(GPP_D3, NONE, PLTRST, LEVEL),
	/* GPP_D4 : [NF1: IMGCLKOUT0 NF2: BK4 NF5: SBK4 NF6: USB_C_GPP_D4] ==> SOC_GPP_D4 */
	PAD_NC(GPP_D4, NONE),
	/* GPP_D5 : SRCCLKREQ0_L ==> NC */
	PAD_NC(GPP_D5, NONE),
	/* GPP_D6 : [NF1: SRCCLKREQ1# NF6: USB_C_GPP_D6] ==> WLAN_CLKREQ_ODL */
	PAD_CFG_NF(GPP_D6, NONE, DEEP, NF1),
	/* GPP_D7 : SRCCLKREQ2_L ==> NC */
	PAD_NC(GPP_D7, NONE),
	/* GPP_D8 : [NF1: SRCCLKREQ3# NF6: USB_C_GPP_D8] ==> SSD_CLKREQ_ODL */
	PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
	/* GPP_D9 : [NF1: ISH_SPI_CS# NF2: DDP3_CTRLCLK NF4: TBT_LSX2_TXD NF5: BSSB_LS2_RX NF6: USB_C_GPP_D9 NF7: GSPI2_CS0#] ==> USB_C2_LSX_TX */
	PAD_CFG_NF(GPP_D9, NONE, DEEP, NF4),
	/* GPP_D10 : [NF1: ISH_SPI_CLK NF2: DDP3_CTRLDATA NF4: TBT_LSX2_RXD NF5: BSSB_LS2_TX NF6: USB_C_GPP_D10 NF7: GSPI2_CLK] ==> USB_C2_LSX_RX_STRAP */
	PAD_CFG_NF(GPP_D10, NONE, DEEP, NF4),
	/* GPP_D11 : [] ==> EN_PP3300_SSD */
	PAD_CFG_GPO(GPP_D11, 1, DEEP),
	/* GPP_D12 : [NF1: ISH_SPI_MOSI NF2: DDP4_CTRLDATA NF4: TBT_LSX3_RXD NF5: BSSB_LS3_TX NF6: USB_C_GPP_D12 NF7: GSPI2_MOSI] ==> SOC_GPP_D12 */
	PAD_NC(GPP_D12, DN_20K),
	/* GPP_D13 : [NF1: ISH_UART0_RXD NF3: I2C6_SDA NF6: USB_C_GPP_D13] ==> UART0_ISH_RX_DBG_TX */
	PAD_CFG_NF(GPP_D13, NONE, DEEP, NF1),
	/* GPP_D14 : [NF1: ISH_UART0_TXD NF3: I2C6_SCL NF6: USB_C_GPP_D14] ==> UART0_ISH_TX_DBG_RX */
	PAD_CFG_NF(GPP_D14, NONE, DEEP, NF1),
	/* GPP_D15 : ISH_UART0_RTS_L/I2C7B_SDA ==> SOC_ISH_UART0_RTS_L */
	PAD_CFG_NF(GPP_D15, NONE, DEEP, NF1),
	/* GPP_D16 : ISH_UART0_CTS_L/I2C7B_SCL ==> SOC_GPP_D16 */
	PAD_NC(GPP_D16, NONE),
	/* GPP_D17 : [NF1: UART1_RXD NF2: ISH_UART1_RXD NF6: USB_C_GPP_D17] ==> SLP_S0_GATE_R */
	PAD_CFG_GPO(GPP_D17, 1, DEEP),
	/* GPP_D18 : UART1_TXD/ISH_UART1_RXD ==> MS_MUTE_DMICLED */
	PAD_CFG_GPO(GPP_D18, 0, DEEP),
	/* GPP_D19 : [NF1: I2S_MCLK1_OUT NF6: USB_C_GPP_D19] ==> SOC_GPP_D19 */
	PAD_NC(GPP_D19, NONE),

	/* GPP_E0 : SATAXPCIE0/SATAGPO/SRCCLKREQ9_L ==> BOARD_ID1 */
	PAD_CFG_GPI(GPP_E0, NONE, DEEP),
	/* GPP_E1 : [NF2: THC0_SPI1_IO2 NF6: USB_C_GPP_E1] ==> WIFI_DISABLE_L */
	PAD_CFG_GPO(GPP_E1, 1, DEEP),
	/* GPP_E2  : THC0_SPI1_IO3 ==> GSC_PCH_INT_ODL */
	PAD_CFG_GPI_APIC_LOCK(GPP_E2, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_E3 : [NF1: PROC_GP0 NF6: USB_C_GPP_E3] ==> TCHPAD_INT_ODL */
	PAD_CFG_GPI_IRQ_WAKE(GPP_E3, NONE, PLTRST, LEVEL, INVERT),
	/* GPP_E4 : [NF1: DEVSLP0 NF6: USB_C_GPP_E4 NF7: SRCCLK_OE9#] ==> USB4_BB_RT_FORCE_PWR */
	PAD_CFG_GPO(GPP_E4, 1, DEEP),
	/* GPP_E5 : [NF1: DEVSLP1 NF6: USB_C_GPP_E5 NF7: SRCCLK_OE6#] ==> SOC_GPP_E5 */
	PAD_NC(GPP_E5, NONE),
	/* GPP_E6 : [NF2: THC0_SPI1_RST# NF6: USB_C_GPP_E6] ==> SOC_GPP_E6_STRAP */
	PAD_CFG_GPI(GPP_E6, NONE, DEEP),
	/* GPP_E7 : [NF1: PROC_GP1 NF6: USB_C_GPP_E7] ==> EN_UCAM_PWR */
	PAD_CFG_GPO(GPP_E7, 0, DEEP),
	/* GPP_E8 : GPP_E8 ==> PCH_WP_OD */
	PAD_CFG_GPI_LOCK(GPP_E8, NONE, LOCK_CONFIG),
	/* GPP_E9 : [NF1: USB_OC0# NF2: ISH_GP4 NF6: USB_C_GPP_E9] ==> SOC_GPP_E9 */
	PAD_NC(GPP_E9, NONE),
	/* GPP_E10 : THC0_SPI1_CS_L/GSPI0_CS0_L ==> MEM_STRAP_3 */
	PAD_CFG_GPI(GPP_E10, NONE, DEEP),
	/* GPP_E11 : [NF2: THC0_SPI1_CLK NF6: USB_C_GPP_E11 NF7: GSPI0_CLK] ==> SOC_GPP_E11 */
	PAD_NC(GPP_E11, NONE),
	/* GPP_E12 : THC0_SPI1_IO1/I2C0A_SDA/GSPI0_MISO ==> MEM_STRAP_1 */
	PAD_CFG_GPI(GPP_E12, NONE, DEEP),
	/* GPP_E13 : THC0_SPI1_IO0/I2C0A_SCL/GSPI0_MOSI ==> MEM_STRAP_2 */
	PAD_CFG_GPI(GPP_E13, NONE, DEEP),
	/* GPP_E14 : [NF1: DDSP_HPDA NF2: DISP_MISC_A NF6: USB_C_GPP_E14] ==> SOC_EDP_HPD */
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	/* GPP_E15 : SRCCLK_OE8_L ==> MEM_STRAP_0 */
	PAD_CFG_GPI(GPP_E15, NONE, DEEP),
	/* GPP_E16 : SRCCLKREQ8_L ==> BOARD_ID6 */
	PAD_CFG_GPI(GPP_E16, NONE, DEEP),
	/* GPP_E17 : [NF2: THC0_SPI1_INT# NF6: USB_C_GPP_E17] ==> SOC_GPP_E17 */
	PAD_NC(GPP_E17, NONE),
	/* GPP_E18 : [NF1: DDP1_CTRLCLK NF4: TBT_LSX0_TXD NF5: BSSB_LS0_RX NF6: USB_C_GPP_E18] ==> USB_C0_LSX_TX */
	PAD_CFG_NF(GPP_E18, NONE, DEEP, NF4),
	/* GPP_E19 : [NF1: DDP1_CTRLDATA NF4: TBT_LSX0_RXD NF5: BSSB_LS0_TX NF6: USB_C_GPP_E19] ==> USB_C0_LSX_RX_STRAP */
	PAD_CFG_NF(GPP_E19, NONE, DEEP, NF4),
	/* GPP_E20 : [NF1: DDP2_CTRLCLK NF4: TBT_LSX1_TXD NF5: BSSB_LS1_RX NF6: USB_C_GPP_E20] ==> SOC_GPP_E20 */
	PAD_NC(GPP_E20, NONE),
	/* GPP_E21 : DDP2_CTRLDATA/TBT_LSX1_RXD/BSSB_LS1_TX ==> USB_C1_LSX_RX_STRAP */
	PAD_NC(GPP_E21, DN_20K),
	/* GPP_E22 : DDPA_CTRLCLK/DNX_FORCE_RELOAD ==> USB_C0_AUX_DC_STRAP_P */
	PAD_NC(GPP_E22, DN_20K),
	/* GPP_E23 : [NF1: DDPA_CTRLDATA] ==> USB_C0_AUX_DC_N */
	PAD_CFG_NF(GPP_E23, NONE, DEEP, NF6),

	/* GPP_F0 : [NF1: CNV_BRI_DT NF2: UART2_RTS# NF6: USB_C_GPP_F0] ==> CNV_BRI_DT_STRAP */
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
	/* GPP_F1 : [NF1: CNV_BRI_RSP NF2: UART2_RXD NF6: USB_C_GPP_F1] ==> CNV_BRI_RSP */
	PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1),
	/* GPP_F2 : [NF1: CNV_RGI_DT NF2: UART2_TXD NF6: USB_C_GPP_F2] ==> CNV_RGI_DT_STRAP */
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),
	/* GPP_F3 : [NF1: CNV_RGI_RSP NF2: UART2_CTS# NF6: USB_C_GPP_F3] ==> CNV_RGI_RSP */
	PAD_CFG_NF(GPP_F3, NONE, DEEP, NF1),
	/* GPP_F4 : [NF1: CNV_RF_RESET# NF6: USB_C_GPP_F4] ==> CNV_RF_RST_L */
	PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1),
	/* GPP_F5 : [NF2: MODEM_CLKREQ NF3: CRF_XTAL_CLKREQ NF6: USB_C_GPP_F5] ==> CNV_CLKREQ0 */
	PAD_CFG_NF(GPP_F5, NONE, DEEP, NF2),
	/* GPP_F6 : [NF1: CNV_PA_BLANKING NF6: USB_C_GPP_F6] ==> SOC_GPP_F6 */
	PAD_NC(GPP_F6, NONE),
	/* GPP_F7 : [NF6: USB_C_GPP_F7] ==> EN_PP3300_TCHSCR */
	PAD_CFG_GPO(GPP_F7, 0, DEEP),
	/* GPP_F9 : [NF1: BOOTMPC NF6: USB_C_GPP_F9] ==> SSD_PERST_L */
	PAD_CFG_GPO(GPP_F9, 1, PLTRST),
	/* GPP_F10 : GPP_F10 ==> GPP_F10_STRAP */
	PAD_NC(GPP_F10, DN_20K),
	/* GPP_F11 : [NF3: THC1_SPI2_CLK NF4: GSPI1_CLK NF6: USB_C_GPP_F11] ==> SOC_GPP_F11 */
	PAD_NC(GPP_F11, NONE),
	/* GPP_F12 : [NF1: GSXDOUT NF3: THC1_SPI2_IO0 NF4: GSPI1_MOSI NF5: I2C1A_SCL NF6: USB_C_GPP_F12] ==> SOC_GPP_F12 */
	PAD_NC(GPP_F12, NONE),
	/* GPP_F13 : [NF1: GSXSLOAD NF3: THC1_SPI2_IO1 NF4: GSPI1_MISIO NF5: I2C1A_SDA NF6: USB_C_GPP_F13] ==> SOC_GPP_F13 */
	PAD_NC(GPP_F13, NONE),
	/* GPP_F14 : [NF1: GSXDIN NF3: THC1_SPI2_IO2 NF6: USB_C_GPP_F14] ==> SOC_GPP_F14 */
	PAD_NC(GPP_F14, NONE),
	/* GPP_F15 : [NF1: GSXSRESET# NF3: THC1_SPI2_IO3 NF6: USB_C_GPP_F15] ==> SOC_GPP_F15 */
	PAD_NC(GPP_F15, NONE),
	/* GPP_F16 : [NF1: GSXCLK NF3: THC1_SPI2_CS# NF4: GSPI1_CS0# NF6: USB_C_GPP_F16] ==> PCH_TCHSCR_REPORT_EN */
	PAD_CFG_GPO(GPP_F16, 0, DEEP),
	/* GPP_F17 : [NF3: THC1_SPI2_RST# NF6: USB_C_GPP_F17] ==> TCHSCR_RST_L */
	PAD_CFG_NF(GPP_F17, NONE, DEEP, NF3),
	/* GPP_F18 : [NF3: THC1_SPI2_INT# NF6: USB_C_GPP_F18] ==> TCHSCR_INT_ODL */
	PAD_CFG_NF(GPP_F18, NONE, DEEP, NF3),
	/* GPP_F19 : SRCCLKREQ6 ==> NC */
	PAD_NC(GPP_F19, NONE),
	/* GPP_F20 : [NF1: Reserved NF6: USB_C_GPP_F20] ==> SOC_GPP_F20 */
	PAD_NC(GPP_F20, NONE),
	/* GPP_F21 : [NF1: Reserved NF6: USB_C_GPP_F21] ==> SOC_GPP_F21 */
	PAD_NC(GPP_F21, NONE),
	/* GPP_F22 : [NF1: VNN_CTRL NF6: USB_C_GPP_F22] ==> TP153 */
	PAD_NC(GPP_F22, NONE),
	/* GPP_F23 : [NF1: V1P05_CTRL NF6: USB_C_GPP_F23] ==> TP154 */
	PAD_NC(GPP_F23, NONE),

	/* GPP_H0 : [NF6: USB_C_GPP_H0] ==> GPP_H0_BOOT_STRAP1 */
	PAD_NC(GPP_H0, DN_20K),
	/* GPP_H1 : [NF6: USB_C_GPP_H1] ==> GPP_H1_BOOT_STRAP2 */
	PAD_NC(GPP_H1, DN_20K),
	/* GPP_H2 : [NF6: USB_C_GPP_H2] ==> WLAN_PERST_L */
	PAD_CFG_GPO(GPP_H2, 1, DEEP),
	/* GPP_H3 : [NF1: SX_EXIT_HOLDOFF# NF6: USB_C_GPP_H3] ==> WLAN_PCIE_WAKE_ODL */
	PAD_CFG_GPI_INT(GPP_H3, NONE, PLTRST, EDGE_SINGLE),
	/* GPP_H4 : I2C0_SDA ==> PCH_I2C_TCHPAD_SDA */
	PAD_CFG_NF(GPP_H4, NONE, DEEP, NF1),
	/* GPP_H5 : [NF1: I2C0_SCL NF6: USB_C_GPP_H5] ==> PCH_I2C_TCHPAD_SCL */
	PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1),
	/* GPP_H6 : [NF1: I2C1_SDA NF6: USB_C_GPP_H6] ==> PCH_I2C_TCHSCR_SDA */
	PAD_CFG_NF(GPP_H6, NONE, DEEP, NF1),
	/* GPP_H7 : [NF1: I2C1_SCL NF6: USB_C_GPP_H7] ==> PCH_I2C_TCHSCR_SCL */
	PAD_CFG_NF(GPP_H7, NONE, DEEP, NF1),
	/* GPP_H8 : [NF1: I2C4_SDA NF2: CNV_MFUART2_RXD NF6: USB_C_GPP_H8] ==> PCH_I2C_GSC_SDA */
	PAD_CFG_NF(GPP_H8, NONE, DEEP, NF1),
	/* GPP_H9 : [NF1: I2C4_SCL NF2: CNV_MFUART2_TXD] ==> PCH_I2C_GSC_SCL */
	PAD_CFG_NF(GPP_H9, NONE, DEEP, NF1),
	/* GPP_H10 : [NF2: UART0_RXD NF3: M2_SKT2_CFG0 NF6: USB_C_GPP_H10] ==> UART_PCH_TX_DBG_RX */
	PAD_CFG_NF(GPP_H10, NONE, DEEP, NF2),
	/* GPP_H11 : [NF2: UART0_TXD NF3: M2_SKT2_CFG1 NF6: USB_C_GPP_H11] ==> UART_PCH_RX_DBG_TX */
	PAD_CFG_NF(GPP_H11, NONE, DEEP, NF2),
	/* GPP_H12 : [NF1: I2C7_SDA NF2: UART0_RTS# NF3: M2_SKT2_CFG2 NF4: ISH_GP6B NF5: DEVSLP0B NF6: USB_C_GPP_H12] ==> SOC_UART0_RTS_L */
	PAD_CFG_NF(GPP_H12, NONE, DEEP, NF2),
	/* GPP_H13 : I2C7_SCL/UART0_CTS_L/M2_SKT2CFG3/ISH_GP7B/DEVSLK1B ==> BOARD_ID0 */
	PAD_CFG_GPI(GPP_H13, NONE, DEEP),
	/* GPP_H15 : [NF1: DDPB_CTRLCLK NF3: PCIE_LINK_DOWN NF6: USB_C_GPP_H15] ==> DDIB_HDMI_CTRLCLK */
	PAD_CFG_NF(GPP_H15, NONE, DEEP, NF1),
	/* GPP_H17 : [NF1: DDPB_CTRLDATA NF6: USB_C_GPP_H17] ==> DDIB_HDMI_CTRLDATA */
	PAD_CFG_NF(GPP_H17, NONE, DEEP, NF1),
	/* GPP_H18 : [NF1: PROC_C10_GATE# NF6: USB_C_GPP_H18] ==> CPU_C10_GATE_L */
	PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1),
	/* GPP_H19 : SRCCLKREQ4_L ==> NC */
	PAD_NC(GPP_H19, NONE),
	/* GPP_H20 : IMGCLKOUT1 ==> BOARD_ID7 */
	PAD_CFG_GPI(GPP_H20, NONE, DEEP),
	/* GPP_H21 : [NF1: IMGCLKOUT2 NF6: USB_C_GPP_H21] ==> SOC_GPP_H21 */
	PAD_NC(GPP_H21, NONE),
	/* GPP_H22 : IMGCLKOUT3 ==> BOARD_ID8 */
	PAD_CFG_GPI(GPP_H22, NONE, DEEP),
	/* GPP_H23 : SRCCLKREQ5_L ==> NC */
	PAD_NC(GPP_H23, NONE),

	/* GPP_R0 : [NF1: HDA_BCLK NF2: I2S0_SCLK NF3: DMIC_CLK_B0 NF4: HDAPROC_BCLK] ==> HDA_HP_BCLK_R */
	PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1),
	/* GPP_R1 : [NF1: HDA_SYNC NF3: DMIC_CLK_B1] ==> HDA_HP_SYNC_R */
	PAD_CFG_NF(GPP_R1, NONE, DEEP, NF1),
	/* GPP_R2 : [NF1: HDA_SDO NF2: I2S0_TXD NF4: HDAPROC_SDO] ==> HDA_HP_SDO_R */
	PAD_CFG_NF(GPP_R2, NONE, DEEP, NF1),
	/* GPP_R3 : [NF1: HDA_SDI0 NF2: I2S0_RXD NF4: HDAPROC_SDI] ==> HDA_HP_SDI0 */
	PAD_CFG_NF(GPP_R3, NONE, DEEP, NF1),
	/* GPP_R4 : HDA_RST_L/I2S2_SCLK/DMIC_CLK_A0 ==> SOC_GPP_R4 */
	PAD_NC(GPP_R4, NONE),
	/* GPP_R5 : HDA_SDI1/I2S2_SFRM/DMIC_DATA0 ==> SOC_GPP_R4 */
	PAD_NC(GPP_R5, NONE),
	/* GPP_R6 : I2S2_TXD/DMIC_CLK_A1 ==> BOARD_ID5 */
	PAD_CFG_GPI(GPP_R6, NONE, DEEP),
	/* GPP_R7 : I2S2_RXD/DMIC_DATA1 ==> SOC_GPP_R7 */
	PAD_NC(GPP_R7, NONE),

	/* GPP_S0 : SNDW0_CLL/I2S1_SCLK ==> MEM_CH_SEL */
	PAD_CFG_GPI(GPP_S0, NONE, DEEP),
	/* GPP_S1 : SNDW0_DATA/I2S1_SFRM ==> SOC_GPP_S1 */
	PAD_NC(GPP_S1, NONE),
	/* GPP_S2 : [NF1: SNDW1_CLK NF2: DMIC_CKL_A0 NF4: I2S1_TXD] ==> DMIC_CLK0_R */
	PAD_CFG_NF(GPP_S2, NONE, DEEP, NF2),
	/* GPP_S3 : [NF1: SNDW1_DATA NF2: DMIC_DATA0 NF4: I2S1_RXD] ==> DMIC_DATA0_EDP */
	PAD_CFG_NF(GPP_S3, NONE, DEEP, NF2),
	/* GPP_S4 : SNDW2_CLK/DMIC_CLK_B0 ==> SOC_GPP_S3 */
	PAD_NC(GPP_S4, NONE),
	/* GPP_S5 : SNDW2_DATA/DMIC_CLK_B1 ==> SOC_GPP_S4 */
	PAD_NC(GPP_S5, NONE),
	/* GPP_S6 : SNDW3_CLK/DMIC_CLK_A1 ==> BOARD_ID3 */
	PAD_CFG_GPI(GPP_S6, NONE, DEEP),
	/* GPP_S7 : SNDW3_DATA/DMIC_DATA1 ==> BOARD_ID4 */
	PAD_CFG_GPI(GPP_S7, NONE, DEEP),

	/* GPP_T2 : GPP_T2 ==> TP70 */
	PAD_NC(GPP_T2, NONE),
	/* GPP_T3 : GPP_T3 ==> TP71 */
	PAD_NC(GPP_T3, NONE),
};

const struct pad_config *__weak variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

const struct pad_config *__weak variant_gpio_override_table(size_t *num)
{
	*num = 0;
	return NULL;
}

/* Early pad configuration in bootblock */
static const struct pad_config early_gpio_table[] = {
	/* GPP_D11 : [] ==> EN_PP3300_SSD */
	PAD_CFG_GPO(GPP_D11, 1, DEEP),
	/* GPP_E2  : THC0_SPI1_IO3 ==> GSC_PCH_INT_ODL */
	PAD_CFG_GPI_APIC_LOCK(GPP_E2, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_E8 : GPP_E8 ==> PCH_WP_OD */
	PAD_CFG_GPI_LOCK(GPP_E8, NONE, LOCK_CONFIG),
	/* GPP_F9 : [NF1: BOOTMPC NF6: USB_C_GPP_F9] ==> SSD_PERST_L */
	PAD_CFG_GPO(GPP_F9, 0, DEEP),
	/* F21 : EXT_PWR_GATE2# ==> NC */
	PAD_NC(GPP_F21, NONE),
	/* GPP_H8 : [NF1: I2C4_SDA NF2: CNV_MFUART2_RXD NF6: USB_C_GPP_H8] ==> PCH_I2C_GSC_SDA */
	PAD_CFG_NF(GPP_H8, NONE, DEEP, NF1),
	/* GPP_H9 : [NF1: I2C4_SCL NF2: CNV_MFUART2_TXD] ==> PCH_I2C_GSC_SCL */
	PAD_CFG_NF(GPP_H9, NONE, DEEP, NF1),
	/* H10 : UART0_RXD ==> UART_PCH_RX_DBG_TX */
	PAD_CFG_NF(GPP_H10, NONE, DEEP, NF2),
	/* H11 : UART0_TXD ==> UART_PCH_TX_DBG_RX */
	PAD_CFG_NF(GPP_H11, NONE, DEEP, NF2),
	/* GPP_S0 : SNDW0_CLL/I2S1_SCLK ==> MEM_CH_SEL */
	PAD_CFG_GPI(GPP_S0, NONE, DEEP),
};

const struct pad_config *__weak variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

static const struct cros_gpio cros_gpios[] = {
	CROS_GPIO_REC_AL(CROS_GPIO_VIRTUAL, CROS_GPIO_DEVICE_NAME),
	CROS_GPIO_WP_AH(GPIO_PCH_WP, CROS_GPIO_DEVICE_NAME),
};

DECLARE_WEAK_CROS_GPIOS(cros_gpios);

const struct pad_config *__weak variant_romstage_gpio_table(size_t *num)
{
	*num = 0;
	return NULL;
}
