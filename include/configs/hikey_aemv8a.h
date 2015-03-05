/*
 * Configuration for HiKey. Parts were derived from other ARM
 *   configurations.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __HIKEY_AEMV8A_H
#define __HIKEY_AEMV8A_H

/* We use generic board for hikey */
#define CONFIG_SYS_GENERIC_BOARD

#define CONFIG_REMAKE_ELF

/*#define CPU_RELEASE_ADDR 0x740fff8*/

/*#define CONFIG_ARMV8_SWITCH_TO_EL1*/

#define CONFIG_SUPPORT_RAW_INITRD

/* Cache Definitions */
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_SYS_ICACHE_OFF

#define CONFIG_IDENT_STRING		" hikey_aemv8a"
#define CONFIG_BOOTP_VCI_STRING		"U-boot.armv8.hikey_aemv8a"

/* Flat Device Tree Definitions */
#define CONFIG_OF_LIBFDT



#define CONFIG_SYS_LOAD_ADDR		(V2M_BASE + 0x8000)
#define LINUX_BOOT_PARAM_ADDR		(V2M_BASE + 0x2000)

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY              (0x1300000)     /* 19MHz */

/* Generic Interrupt Controller Definitions */
#define GICD_BASE			(0xf6801000)
#define GICC_BASE			(0xf6802000)

#define CONFIG_SYS_MEMTEST_START	V2M_BASE
#define CONFIG_SYS_MEMTEST_END		(V2M_BASE + 0x40000000)

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (8 << 20))

/* PL011 Serial Configuration */
#define CONFIG_PL011_SERIAL

#define CONFIG_PL011_CLOCK		19200000
#define CONFIG_PL01x_PORTS		{(void *)CONFIG_SYS_SERIAL0}
#define CONFIG_CONS_INDEX		0

#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_SERIAL0		0xF8015000
/*#define CONFIG_SYS_SERIAL1		0xF7111000*/

#define CONFIG_CMD_USB
#ifdef CONFIG_CMD_USB
#define CONFIG_USB_DWC2
#define CONFIG_USB_DWC2_REG_ADDR 0xF72C0000
/*#define CONFIG_DWC2_DFLT_SPEED_FULL*/
#define CONFIG_DWC2_ENABLE_DYNAMIC_FIFO

#define CONFIG_USB_STORAGE
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_SMSC95XX
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_MISC_INIT_R
#endif

#define CONFIG_HIKEY_GPIO
#define CONFIG_DM_GPIO
#define CONFIG_CMD_GPIO
#define CONFIG_DM

/* SD/MMC configuration */
#define CONFIG_GENERIC_MMC
#define CONFIG_MMC
#define CONFIG_DWMMC
#define CONFIG_HIKEY_DWMMC
#define CONFIG_HIKEY_DWMMC_REG_ADDR 0xF723D000
#define CONFIG_BOUNCE_BUFFER

#define CONFIG_CMD_MMC

/* Command line configuration */
#define CONFIG_MENU
/*#define CONFIG_MENU_SHOW*/
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_BDI
#define CONFIG_CMD_BOOTI
#define CONFIG_CMD_UNZIP
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PXE
#define CONFIG_CMD_ENV
#define CONFIG_CMD_IMI
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_RUN
#define CONFIG_CMD_BOOTD
#define CONFIG_CMD_ECHO
#define CONFIG_CMD_SOURCE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION

/* BOOTP options */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_PXE
#define CONFIG_BOOTP_PXE_CLIENTARCH	0x100

/* Physical Memory Map */

#define V2M_BASE			0x00000000
#define CONFIG_SYS_TEXT_BASE		0x37000000
/* RAM debug builds */
/*#define CONFIG_SYS_TEXT_BASE		0x27000000*/


#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1			(V2M_BASE)	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE		0x40000000	/* 1024 MB */
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1

#define CONFIG_SYS_INIT_RAM_SIZE	0x1000

#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_SDRAM_BASE + 0x7fff0)

/* Initial environment variables */

//TODO need updating for HiKey
/*
 * Defines where the kernel and FDT exist in NOR flash and where it will
 * be copied into DRAM
 */
#define CONFIG_EXTRA_ENV_SETTINGS	\
				"kernel_name=Image\0"	\
				"kernel_addr=0x0000000\0" \
				"fdt_name=hi6220-hikey.dtb\0" \
				"fdt_addr=0x0300000\0" \

/* Assume we boot with root on the first partition of a USB stick */
#define CONFIG_BOOTARGS		"console=ttyAMA0,115200n8 /dev/mmcblk0p7 rw "

/* Copy the kernel and FDT to DRAM memory and boot */
#define CONFIG_BOOTCOMMAND	"booti $kernel_addr_r - $fdt_addr_r"

#define CONFIG_BOOTDELAY		1

/* Do not preserve environment */
#define CONFIG_ENV_IS_NOWHERE		1
#define CONFIG_ENV_SIZE			0x1000

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		512	/* Console I/O Buffer Size */
#define CONFIG_SYS_PROMPT		"HiKey64# "
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING
#define CONFIG_SYS_MAXARGS		64	/* max command args */

/* Flash memory is available on the Juno board only */
#define CONFIG_SYS_NO_FLASH

#endif /* __HIKEY_AEMV8A_H */
