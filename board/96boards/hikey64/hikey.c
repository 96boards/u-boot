/*
 * (C) Copyright 2015 Linaro
 * Peter Griffin <peter.griffin@linaro.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <asm/arch/dwmmc.h>
#include <asm/arch/hi6120.h>

#ifdef CONFIG_DM_GPIO
static const struct hikey_gpio_platdata hi6220_gpio[] = {
	{ 0, HI6220_GPIO0_BASE},
	{ 1, HI6220_GPIO1_BASE},
	{ 2, HI6220_GPIO2_BASE},
	{ 3, HI6220_GPIO3_BASE},
	{ 4, HI6220_GPIO4_BASE},
	{ 5, HI6220_GPIO5_BASE},
	{ 6, HI6220_GPIO6_BASE},
	{ 7, HI6220_GPIO7_BASE},
	{ 8, HI6220_GPIO8_BASE},
	{ 9, HI6220_GPIO9_BASE},
	{ 10, HI6220_GPIO10_BASE},
	{ 11, HI6220_GPIO11_BASE},
	{ 12, HI6220_GPIO12_BASE},
	{ 13, HI6220_GPIO13_BASE},
	{ 14, HI6220_GPIO14_BASE},
	{ 15, HI6220_GPIO15_BASE},
	{ 16, HI6220_GPIO16_BASE},
	{ 17, HI6220_GPIO17_BASE},
	{ 18, HI6220_GPIO18_BASE},
	{ 19, HI6220_GPIO19_BASE},

};

U_BOOT_DEVICES(hi6220_gpios) = {
	{ "gpio_hi6220", &hi6220_gpio[0] },
	{ "gpio_hi6220", &hi6220_gpio[1] },
	{ "gpio_hi6220", &hi6220_gpio[2] },
	{ "gpio_hi6220", &hi6220_gpio[3] },
	{ "gpio_hi6220", &hi6220_gpio[4] },
	{ "gpio_hi6220", &hi6220_gpio[5] },
	{ "gpio_hi6220", &hi6220_gpio[6] },
	{ "gpio_hi6220", &hi6220_gpio[7] },
	{ "gpio_hi6220", &hi6220_gpio[8] },
	{ "gpio_hi6220", &hi6220_gpio[9] },
	{ "gpio_hi6220", &hi6220_gpio[10] },
	{ "gpio_hi6220", &hi6220_gpio[11] },
	{ "gpio_hi6220", &hi6220_gpio[12] },
	{ "gpio_hi6220", &hi6220_gpio[13] },
	{ "gpio_hi6220", &hi6220_gpio[14] },
	{ "gpio_hi6220", &hi6220_gpio[15] },
	{ "gpio_hi6220", &hi6220_gpio[16] },
	{ "gpio_hi6220", &hi6220_gpio[17] },
	{ "gpio_hi6220", &hi6220_gpio[18] },
	{ "gpio_hi6220", &hi6220_gpio[19] },
};
#endif

DECLARE_GLOBAL_DATA_PTR;

#if defined(CONFIG_SHOW_BOOT_PROGRESS)
void show_boot_progress(int progress)
{
	printf("Boot reached stage %d\n", progress);
}
#endif

static inline void delay(ulong loops)
{
	__asm__ volatile ("1:\n"
		"subs %0, %1, #1\n"
		"bne 1b" : "=r" (loops) : "0" (loops));
}


#define EYE_PATTERN	0x70533483

static void init_usb_and_picophy(void)
{
	unsigned int data;

	/* enable USB clock */
	writel(PERI_CLK_USBOTG, PERI_SC_PERIPH_CLKEN0);
	do {
		data = readl(PERI_SC_PERIPH_CLKSTAT0);
	} while ((data & PERI_CLK_USBOTG) == 0);

	/* out of reset */
	writel(PERI_RST_USBOTG_BUS | PERI_RST_PICOPHY |
		PERI_RST_USBOTG | PERI_RST_USBOTG_32K,
		PERI_SC_PERIPH_RSTDIS0);
	do {
		data = readl(PERI_SC_PERIPH_RSTSTAT0);
		data &= PERI_RST_USBOTG_BUS | PERI_RST_PICOPHY |
			PERI_RST_USBOTG | PERI_RST_USBOTG_32K;
	} while (data);

	/*CTRL 5*/
	data = readl(PERI_SC_PERIPH_CTRL5);
	data &= ~PERIPH_CTRL5_PICOPHY_BC_MODE;
	data |= PERIPH_CTRL5_USBOTG_RES_SEL | PERIPH_CTRL5_PICOPHY_ACAENB;
	data |= 0x300;
	writel(data, PERI_SC_PERIPH_CTRL5);

	debug("PERI_SC_PERIPH_CTRL5 = 0x%x\n",data);

	/*CTRL 4*/

	/* configure USB PHY */
	data = readl(PERI_SC_PERIPH_CTRL4);

	/* make PHY out of low power mode */
	data &= ~PERIPH_CTRL4_PICO_SIDDQ;
	data &= ~PERIPH_CTRL4_PICO_OGDISABLE;
	data |= PERIPH_CTRL4_PICO_VBUSVLDEXTSEL | PERIPH_CTRL4_PICO_VBUSVLDEXT;

	debug("PERI_SC_PERIPH_CTRL4 = 0x%x \n",data);
	writel(data, PERI_SC_PERIPH_CTRL4);

	writel(EYE_PATTERN, PERI_SC_PERIPH_CTRL8);
	debug("PERI_SC_PERIPH_CTRL8 = 0x%x\n",readl(PERI_SC_PERIPH_CTRL8));

	delay(20000);
}

/*
 * Routine: misc_init_r
 * Description: A basic misc_init_r
 */
int __weak misc_init_r(void)
{
	init_usb_and_picophy();

	return 0;
}

int board_init(void)
{
	gd->bd->bi_boot_params = LINUX_BOOT_PARAM_ADDR;
	gd->bd->bi_arch_number = MACH_TYPE_VEXPRESS;
	gd->flags = 0;

	icache_enable();
/*	hikey_timer_init();*/

	return 0;
}

#ifdef CONFIG_GENERIC_MMC
static int init_mmc(void)
{
#ifdef CONFIG_SDHCI
	return 0;
/* TODO - IP is not clocked or out of reset atm*/
/*	hikey_mmc_init();*/
#else
	return 0;
#endif
}

static int init_dwmmc(void)
{
#ifdef CONFIG_DWMMC
	return hikey_dwmci_add_port(0, CONFIG_HIKEY_DWMMC_REG_ADDR, 8);
#else
	return 0;
#endif
}

int board_mmc_init(bd_t *bis)
{
	int ret;

	ret = init_dwmmc();

	if (ret)
		debug("mmc init failed\n");

	return ret;
}
#endif

int dram_init(void)
{
	gd->ram_size =
		get_ram_size((long *)CONFIG_SYS_SDRAM_BASE, PHYS_SDRAM_1_SIZE);
	return 0;
}

void dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size =
			get_ram_size((long *)PHYS_SDRAM_1, PHYS_SDRAM_1_SIZE);

}

/* Use the Watchdog to cause reset */
void reset_cpu(ulong addr)
{
	/* TODO program the watchdog */
}



