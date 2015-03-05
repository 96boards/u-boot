/*
 * (C) Copyright 2015 Linaro
 * peter.griffin <peter.griffin@linaro.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <dwmmc.h>
#include <malloc.h>
#include <asm-generic/errno.h>

#define	DWMMC_MAX_CH_NUM		4

/*
#define	DWMMC_MAX_FREQ			52000000
#define	DWMMC_MIN_FREQ			400000
*/

/*TODO we should probably use the frequencies above, but atf uses
  the ones below so stick with that for the moment */
#define	DWMMC_MAX_FREQ			50000000
#define	DWMMC_MIN_FREQ			378000

/* Source clock is configured to 100Mhz by atf bl1*/
#define MMC0_DEFAULT_FREQ		100000000

/* TODO need to implement get/set clock rate functions */
#if 0
unsigned int hikey_dwmci_get_clk(struct dwmci_host *host)
{
	unsigned long sclk;
	int8_t clk_div;

	/*return cached value for now */
	return host->bus_hz;
}
#endif

static int hikey_dwmci_core_init(struct dwmci_host *host, int index)
{
	host->name = "HiKey DWMMC";

	host->dev_index = index;
	/*host->get_mmc_clk = hikey_dwmci_get_clk;*/

	/* Add the mmc channel to be registered with mmc core */
	if (add_dwmci(host, DWMMC_MAX_FREQ, DWMMC_MIN_FREQ)) {
		printf("DWMMC%d registration failed\n", index);
		return -1;
	}
	return 0;
}

/*
 * This function adds the mmc channel to be registered with mmc core.
 * index -	mmc channel number.
 * regbase -	register base address of mmc channel specified in 'index'.
 * bus_width -	operating bus width of mmc channel specified in 'index'.
 */
int hikey_dwmci_add_port(int index, u32 regbase, int bus_width)
{
	struct dwmci_host *host = NULL;

	host = malloc(sizeof(struct dwmci_host));
	if (!host) {
		error("dwmci_host malloc fail!\n");
		return -ENOMEM;
	}

	host->ioaddr = (void *)regbase;
	host->buswidth = bus_width;
	host->bus_hz = MMC0_DEFAULT_FREQ;

	return hikey_dwmci_core_init(host, index);
}
