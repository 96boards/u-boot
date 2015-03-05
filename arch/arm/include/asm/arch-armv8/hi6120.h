/*
 * (C) Copyright 2015 Linaro
 * Peter Griffin <peter.griffin@linaro.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __HI6120_H__
#define __HI6120_H__

#define PERI_BASE				0xf7030000
#define PERI_SC_PERIPH_CTRL2			(PERI_BASE + 0x004)
#define PERI_SC_PERIPH_CTRL4			(PERI_BASE + 0x00c)
#define PERI_SC_PERIPH_CTRL5			(PERI_BASE + 0x010)
#define PERI_SC_PERIPH_CTRL8			(PERI_BASE + 0x018)
#define PERI_SC_PERIPH_CTRL13			(PERI_BASE + 0x028)
#define PERI_SC_PERIPH_CTRL14			(PERI_BASE + 0x02c)
#define PERI_SC_DDR_CTRL0			(PERI_BASE + 0x050)
#define PERI_SC_PERIPH_STAT1			(PERI_BASE + 0x094)
#define PERI_SC_PERIPH_CLKEN0			(PERI_BASE + 0x200)
#define PERI_SC_PERIPH_CLKDIS0			(PERI_BASE + 0x204)
#define PERI_SC_PERIPH_CLKSTAT0			(PERI_BASE + 0x208)
#define PERI_SC_PERIPH_CLKEN8			(PERI_BASE + 0x240)
#define PERI_SC_PERIPH_CLKEN12			(PERI_BASE + 0x270)
#define PERI_SC_PERIPH_RSTEN0			(PERI_BASE + 0x300)
#define PERI_SC_PERIPH_RSTDIS0			(PERI_BASE + 0x304)
#define PERI_SC_PERIPH_RSTSTAT0			(PERI_BASE + 0x308)
#define PERI_SC_PERIPH_RSTEN8			(PERI_BASE + 0x340)
#define PERI_SC_PERIPH_RSTDIS8			(PERI_BASE + 0x344)
#define PERI_SC_CLK_SEL0			(PERI_BASE + 0x400)
#define PERI_SC_CLKCFG8BIT1			(PERI_BASE + 0x494)

#define PCLK_TIMER1				(1 << 16)
#define PCLK_TIMER0				(1 << 15)

#define PERIPH_CTRL4_OTG_PHY_SEL		(1 << 21)
#define PERIPH_CTRL4_PICO_VBUSVLDEXTSEL		(1 << 11)
#define PERIPH_CTRL4_PICO_VBUSVLDEXT		(1 << 10)
#define PERIPH_CTRL4_PICO_OGDISABLE		(1 << 8)
#define PERIPH_CTRL4_PICO_SIDDQ			(1 << 6)
#define PERIPH_CTRL4_FPGA_EXT_PHY_SEL		(1 << 3)


#define PERIPH_CTRL5_PICOPHY_BC_MODE		(1 << 5)
#define PERIPH_CTRL5_PICOPHY_ACAENB		(1 << 4)
#define PERIPH_CTRL5_USBOTG_RES_SEL		(1 << 3)

#define PERIPH_CTRL14_FM_CLK_SEL_SHIFT		8
#define PERIPH_CTRL14_FM_EN			(1 << 0)

#define PERI_CLK_USBOTG				(1 << 4)
#define PERI_CLK_MMC2				(1 << 2)
#define PERI_CLK_MMC1				(1 << 1)
#define PERI_CLK_MMC0				(1 << 0)

#define PERI_RST_USBOTG_32K			(1 << 7)
#define PERI_RST_USBOTG				(1 << 6)
#define PERI_RST_PICOPHY			(1 << 5)
#define PERI_RST_USBOTG_BUS			(1 << 4)
#define PERI_RST_MMC2				(1 << 2)
#define PERI_RST_MMC1				(1 << 1)
#define PERI_RST_MMC0				(1 << 0)

#define PERI_RST_USBOTG_32K			(1 << 7)
#define PERI_RST_USBOTG				(1 << 6)
#define PERI_RST_PICOPHY			(1 << 5)
#define PERI_RST_USBOTG_BUS			(1 << 4)
#define PERI_RST_MMC2				(1 << 2)
#define PERI_RST_MMC1				(1 << 1)
#define PERI_RST_MMC0				(1 << 0)

#endif /*__HI6120_H__*/
