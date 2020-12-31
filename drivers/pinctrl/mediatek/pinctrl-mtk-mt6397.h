
#ifndef __PINCTRL_MTK_MT6397_H
#define __PINCTRL_MTK_MT6397_H

#include <linux/pinctrl/pinctrl.h>
#include "pinctrl-mtk-common.h"

static const struct mtk_desc_pin mtk_pins_mt6397[] = {
	MTK_PIN(
		PINCTRL_PIN(0, "INT"),
		"N2", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO0"),
		MTK_FUNCTION(1, "INT")
	),
	MTK_PIN(
		PINCTRL_PIN(1, "SRCVOLTEN"),
		"M4", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO1"),
		MTK_FUNCTION(1, "SRCVOLTEN"),
		MTK_FUNCTION(6, "TEST_CK1")
	),
	MTK_PIN(
		PINCTRL_PIN(2, "SRCLKEN_PERI"),
		"M2", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO2"),
		MTK_FUNCTION(1, "SRCLKEN_PERI"),
		MTK_FUNCTION(6, "TEST_CK2")
	),
	MTK_PIN(
		PINCTRL_PIN(3, "RTC_32K1V8"),
		"K3", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO3"),
		MTK_FUNCTION(1, "RTC_32K1V8"),
		MTK_FUNCTION(6, "TEST_CK3")
	),
	MTK_PIN(
		PINCTRL_PIN(4, "WRAP_EVENT"),
		"J2", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO4"),
		MTK_FUNCTION(1, "WRAP_EVENT")
	),
	MTK_PIN(
		PINCTRL_PIN(5, "SPI_CLK"),
		"L4", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO5"),
		MTK_FUNCTION(1, "SPI_CLK")
	),
	MTK_PIN(
		PINCTRL_PIN(6, "SPI_CSN"),
		"J3", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO6"),
		MTK_FUNCTION(1, "SPI_CSN")
	),
	MTK_PIN(
		PINCTRL_PIN(7, "SPI_MOSI"),
		"J1", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO7"),
		MTK_FUNCTION(1, "SPI_MOSI")
	),
	MTK_PIN(
		PINCTRL_PIN(8, "SPI_MISO"),
		"L3", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO8"),
		MTK_FUNCTION(1, "SPI_MISO")
	),
	MTK_PIN(
		PINCTRL_PIN(9, "AUD_CLK_MOSI"),
		"H2", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO9"),
		MTK_FUNCTION(1, "AUD_CLK"),
		MTK_FUNCTION(6, "TEST_IN0"),
		MTK_FUNCTION(7, "TEST_OUT0")
	),
	MTK_PIN(
		PINCTRL_PIN(10, "AUD_DAT_MISO"),
		"H3", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO10"),
		MTK_FUNCTION(1, "AUD_MISO"),
		MTK_FUNCTION(6, "TEST_IN1"),
		MTK_FUNCTION(7, "TEST_OUT1")
	),
	MTK_PIN(
		PINCTRL_PIN(11, "AUD_DAT_MOSI"),
		"H1", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO11"),
		MTK_FUNCTION(1, "AUD_MOSI"),
		MTK_FUNCTION(6, "TEST_IN2"),
		MTK_FUNCTION(7, "TEST_OUT2")
	),
	MTK_PIN(
		PINCTRL_PIN(12, "COL0"),
		"F3", "mt6397",
		MTK_EINT_FUNCTION(2, 10),
		MTK_FUNCTION(0, "GPIO12"),
		MTK_FUNCTION(1, "COL0_USBDL"),
		MTK_FUNCTION(2, "EINT10_1X"),
		MTK_FUNCTION(3, "PWM1_3X"),
		MTK_FUNCTION(6, "TEST_IN3"),
		MTK_FUNCTION(7, "TEST_OUT3")
	),
	MTK_PIN(
		PINCTRL_PIN(13, "COL1"),
		"G8", "mt6397",
		MTK_EINT_FUNCTION(2, 11),
		MTK_FUNCTION(0, "GPIO13"),
		MTK_FUNCTION(1, "COL1"),
		MTK_FUNCTION(2, "EINT11_1X"),
		MTK_FUNCTION(3, "SCL0_2X"),
		MTK_FUNCTION(6, "TEST_IN4"),
		MTK_FUNCTION(7, "TEST_OUT4")
	),
	MTK_PIN(
		PINCTRL_PIN(14, "COL2"),
		"H4", "mt6397",
		MTK_EINT_FUNCTION(2, 12),
		MTK_FUNCTION(0, "GPIO14"),
		MTK_FUNCTION(1, "COL2"),
		MTK_FUNCTION(2, "EINT12_1X"),
		MTK_FUNCTION(3, "SDA0_2X"),
		MTK_FUNCTION(6, "TEST_IN5"),
		MTK_FUNCTION(7, "TEST_OUT5")
	),
	MTK_PIN(
		PINCTRL_PIN(15, "COL3"),
		"G2", "mt6397",
		MTK_EINT_FUNCTION(2, 13),
		MTK_FUNCTION(0, "GPIO15"),
		MTK_FUNCTION(1, "COL3"),
		MTK_FUNCTION(2, "EINT13_1X"),
		MTK_FUNCTION(3, "SCL1_2X"),
		MTK_FUNCTION(6, "TEST_IN6"),
		MTK_FUNCTION(7, "TEST_OUT6")
	),
	MTK_PIN(
		PINCTRL_PIN(16, "COL4"),
		"F2", "mt6397",
		MTK_EINT_FUNCTION(2, 14),
		MTK_FUNCTION(0, "GPIO16"),
		MTK_FUNCTION(1, "COL4"),
		MTK_FUNCTION(2, "EINT14_1X"),
		MTK_FUNCTION(3, "SDA1_2X"),
		MTK_FUNCTION(6, "TEST_IN7"),
		MTK_FUNCTION(7, "TEST_OUT7")
	),
	MTK_PIN(
		PINCTRL_PIN(17, "COL5"),
		"G7", "mt6397",
		MTK_EINT_FUNCTION(2, 15),
		MTK_FUNCTION(0, "GPIO17"),
		MTK_FUNCTION(1, "COL5"),
		MTK_FUNCTION(2, "EINT15_1X"),
		MTK_FUNCTION(3, "SCL2_2X"),
		MTK_FUNCTION(6, "TEST_IN8"),
		MTK_FUNCTION(7, "TEST_OUT8")
	),
	MTK_PIN(
		PINCTRL_PIN(18, "COL6"),
		"J6", "mt6397",
		MTK_EINT_FUNCTION(2, 16),
		MTK_FUNCTION(0, "GPIO18"),
		MTK_FUNCTION(1, "COL6"),
		MTK_FUNCTION(2, "EINT16_1X"),
		MTK_FUNCTION(3, "SDA2_2X"),
		MTK_FUNCTION(4, "GPIO32K_0"),
		MTK_FUNCTION(5, "GPIO26M_0"),
		MTK_FUNCTION(6, "TEST_IN9"),
		MTK_FUNCTION(7, "TEST_OUT9")
	),
	MTK_PIN(
		PINCTRL_PIN(19, "COL7"),
		"J5", "mt6397",
		MTK_EINT_FUNCTION(2, 17),
		MTK_FUNCTION(0, "GPIO19"),
		MTK_FUNCTION(1, "COL7"),
		MTK_FUNCTION(2, "EINT17_1X"),
		MTK_FUNCTION(3, "PWM2_3X"),
		MTK_FUNCTION(4, "GPIO32K_1"),
		MTK_FUNCTION(5, "GPIO26M_1"),
		MTK_FUNCTION(6, "TEST_IN10"),
		MTK_FUNCTION(7, "TEST_OUT10")
	),
	MTK_PIN(
		PINCTRL_PIN(20, "ROW0"),
		"L7", "mt6397",
		MTK_EINT_FUNCTION(2, 18),
		MTK_FUNCTION(0, "GPIO20"),
		MTK_FUNCTION(1, "ROW0"),
		MTK_FUNCTION(2, "EINT18_1X"),
		MTK_FUNCTION(3, "SCL0_3X"),
		MTK_FUNCTION(6, "TEST_IN11"),
		MTK_FUNCTION(7, "TEST_OUT11")
	),
	MTK_PIN(
		PINCTRL_PIN(21, "ROW1"),
		"P1", "mt6397",
		MTK_EINT_FUNCTION(2, 19),
		MTK_FUNCTION(0, "GPIO21"),
		MTK_FUNCTION(1, "ROW1"),
		MTK_FUNCTION(2, "EINT19_1X"),
		MTK_FUNCTION(3, "SDA0_3X"),
		MTK_FUNCTION(4, "AUD_TSTCK"),
		MTK_FUNCTION(6, "TEST_IN12"),
		MTK_FUNCTION(7, "TEST_OUT12")
	),
	MTK_PIN(
		PINCTRL_PIN(22, "ROW2"),
		"J8", "mt6397",
		MTK_EINT_FUNCTION(2, 20),
		MTK_FUNCTION(0, "GPIO22"),
		MTK_FUNCTION(1, "ROW2"),
		MTK_FUNCTION(2, "EINT20_1X"),
		MTK_FUNCTION(3, "SCL1_3X"),
		MTK_FUNCTION(6, "TEST_IN13"),
		MTK_FUNCTION(7, "TEST_OUT13")
	),
	MTK_PIN(
		PINCTRL_PIN(23, "ROW3"),
		"J7", "mt6397",
		MTK_EINT_FUNCTION(2, 21),
		MTK_FUNCTION(0, "GPIO23"),
		MTK_FUNCTION(1, "ROW3"),
		MTK_FUNCTION(2, "EINT21_1X"),
		MTK_FUNCTION(3, "SDA1_3X"),
		MTK_FUNCTION(6, "TEST_IN14"),
		MTK_FUNCTION(7, "TEST_OUT14")
	),
	MTK_PIN(
		PINCTRL_PIN(24, "ROW4"),
		"L5", "mt6397",
		MTK_EINT_FUNCTION(2, 22),
		MTK_FUNCTION(0, "GPIO24"),
		MTK_FUNCTION(1, "ROW4"),
		MTK_FUNCTION(2, "EINT22_1X"),
		MTK_FUNCTION(3, "SCL2_3X"),
		MTK_FUNCTION(6, "TEST_IN15"),
		MTK_FUNCTION(7, "TEST_OUT15")
	),
	MTK_PIN(
		PINCTRL_PIN(25, "ROW5"),
		"N6", "mt6397",
		MTK_EINT_FUNCTION(2, 23),
		MTK_FUNCTION(0, "GPIO25"),
		MTK_FUNCTION(1, "ROW5"),
		MTK_FUNCTION(2, "EINT23_1X"),
		MTK_FUNCTION(3, "SDA2_3X"),
		MTK_FUNCTION(6, "TEST_IN16"),
		MTK_FUNCTION(7, "TEST_OUT16")
	),
	MTK_PIN(
		PINCTRL_PIN(26, "ROW6"),
		"L6", "mt6397",
		MTK_EINT_FUNCTION(2, 24),
		MTK_FUNCTION(0, "GPIO26"),
		MTK_FUNCTION(1, "ROW6"),
		MTK_FUNCTION(2, "EINT24_1X"),
		MTK_FUNCTION(3, "PWM3_3X"),
		MTK_FUNCTION(4, "GPIO32K_2"),
		MTK_FUNCTION(5, "GPIO26M_2"),
		MTK_FUNCTION(6, "TEST_IN17"),
		MTK_FUNCTION(7, "TEST_OUT17")
	),
	MTK_PIN(
		PINCTRL_PIN(27, "ROW7"),
		"P2", "mt6397",
		MTK_EINT_FUNCTION(2, 3),
		MTK_FUNCTION(0, "GPIO27"),
		MTK_FUNCTION(1, "ROW7"),
		MTK_FUNCTION(2, "EINT3_1X"),
		MTK_FUNCTION(3, "CBUS"),
		MTK_FUNCTION(4, "GPIO32K_3"),
		MTK_FUNCTION(5, "GPIO26M_3"),
		MTK_FUNCTION(6, "TEST_IN18"),
		MTK_FUNCTION(7, "TEST_OUT18")
	),
	MTK_PIN(
		PINCTRL_PIN(28, "PWM1(VMSEL1)"),
		"J4", "mt6397",
		MTK_EINT_FUNCTION(2, 4),
		MTK_FUNCTION(0, "GPIO28"),
		MTK_FUNCTION(1, "PWM1"),
		MTK_FUNCTION(2, "EINT4_1X"),
		MTK_FUNCTION(4, "GPIO32K_4"),
		MTK_FUNCTION(5, "GPIO26M_4"),
		MTK_FUNCTION(6, "TEST_IN19"),
		MTK_FUNCTION(7, "TEST_OUT19")
	),
	MTK_PIN(
		PINCTRL_PIN(29, "PWM2(VMSEL2)"),
		"N5", "mt6397",
		MTK_EINT_FUNCTION(2, 5),
		MTK_FUNCTION(0, "GPIO29"),
		MTK_FUNCTION(1, "PWM2"),
		MTK_FUNCTION(2, "EINT5_1X"),
		MTK_FUNCTION(4, "GPIO32K_5"),
		MTK_FUNCTION(5, "GPIO26M_5"),
		MTK_FUNCTION(6, "TEST_IN20"),
		MTK_FUNCTION(7, "TEST_OUT20")
	),
	MTK_PIN(
		PINCTRL_PIN(30, "PWM3(PWM)"),
		"R3", "mt6397",
		MTK_EINT_FUNCTION(2, 6),
		MTK_FUNCTION(0, "GPIO30"),
		MTK_FUNCTION(1, "PWM3"),
		MTK_FUNCTION(2, "EINT6_1X"),
		MTK_FUNCTION(3, "COL0"),
		MTK_FUNCTION(4, "GPIO32K_6"),
		MTK_FUNCTION(5, "GPIO26M_6"),
		MTK_FUNCTION(6, "TEST_IN21"),
		MTK_FUNCTION(7, "TEST_OUT21")
	),
	MTK_PIN(
		PINCTRL_PIN(31, "SCL0"),
		"N1", "mt6397",
		MTK_EINT_FUNCTION(2, 7),
		MTK_FUNCTION(0, "GPIO31"),
		MTK_FUNCTION(1, "SCL0"),
		MTK_FUNCTION(2, "EINT7_1X"),
		MTK_FUNCTION(3, "PWM1_2X"),
		MTK_FUNCTION(6, "TEST_IN22"),
		MTK_FUNCTION(7, "TEST_OUT22")
	),
	MTK_PIN(
		PINCTRL_PIN(32, "SDA0"),
		"N3", "mt6397",
		MTK_EINT_FUNCTION(2, 8),
		MTK_FUNCTION(0, "GPIO32"),
		MTK_FUNCTION(1, "SDA0"),
		MTK_FUNCTION(2, "EINT8_1X"),
		MTK_FUNCTION(6, "TEST_IN23"),
		MTK_FUNCTION(7, "TEST_OUT23")
	),
	MTK_PIN(
		PINCTRL_PIN(33, "SCL1"),
		"T1", "mt6397",
		MTK_EINT_FUNCTION(2, 9),
		MTK_FUNCTION(0, "GPIO33"),
		MTK_FUNCTION(1, "SCL1"),
		MTK_FUNCTION(2, "EINT9_1X"),
		MTK_FUNCTION(3, "PWM2_2X"),
		MTK_FUNCTION(6, "TEST_IN24"),
		MTK_FUNCTION(7, "TEST_OUT24")
	),
	MTK_PIN(
		PINCTRL_PIN(34, "SDA1"),
		"T2", "mt6397",
		MTK_EINT_FUNCTION(2, 0),
		MTK_FUNCTION(0, "GPIO34"),
		MTK_FUNCTION(1, "SDA1"),
		MTK_FUNCTION(2, "EINT0_1X"),
		MTK_FUNCTION(6, "TEST_IN25"),
		MTK_FUNCTION(7, "TEST_OUT25")
	),
	MTK_PIN(
		PINCTRL_PIN(35, "SCL2"),
		"T3", "mt6397",
		MTK_EINT_FUNCTION(2, 1),
		MTK_FUNCTION(0, "GPIO35"),
		MTK_FUNCTION(1, "SCL2"),
		MTK_FUNCTION(2, "EINT1_1X"),
		MTK_FUNCTION(3, "PWM3_2X"),
		MTK_FUNCTION(6, "TEST_IN26"),
		MTK_FUNCTION(7, "TEST_OUT26")
	),
	MTK_PIN(
		PINCTRL_PIN(36, "SDA2"),
		"U2", "mt6397",
		MTK_EINT_FUNCTION(2, 2),
		MTK_FUNCTION(0, "GPIO36"),
		MTK_FUNCTION(1, "SDA2"),
		MTK_FUNCTION(2, "EINT2_1X"),
		MTK_FUNCTION(6, "TEST_IN27"),
		MTK_FUNCTION(7, "TEST_OUT27")
	),
	MTK_PIN(
		PINCTRL_PIN(37, "HDMISD"),
		"H6", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO37"),
		MTK_FUNCTION(1, "HDMISD"),
		MTK_FUNCTION(6, "TEST_IN28"),
		MTK_FUNCTION(7, "TEST_OUT28")
	),
	MTK_PIN(
		PINCTRL_PIN(38, "HDMISCK"),
		"H5", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO38"),
		MTK_FUNCTION(1, "HDMISCK"),
		MTK_FUNCTION(6, "TEST_IN29"),
		MTK_FUNCTION(7, "TEST_OUT29")
	),
	MTK_PIN(
		PINCTRL_PIN(39, "HTPLG"),
		"H7", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO39"),
		MTK_FUNCTION(1, "HTPLG"),
		MTK_FUNCTION(6, "TEST_IN30"),
		MTK_FUNCTION(7, "TEST_OUT30")
	),
	MTK_PIN(
		PINCTRL_PIN(40, "CEC"),
		"J9", "mt6397",
		MTK_EINT_FUNCTION(NO_EINT_SUPPORT, NO_EINT_SUPPORT),
		MTK_FUNCTION(0, "GPIO40"),
		MTK_FUNCTION(1, "CEC"),
		MTK_FUNCTION(6, "TEST_IN31"),
		MTK_FUNCTION(7, "TEST_OUT31")
	),
};

#endif /* __PINCTRL_MTK_MT6397_H */
