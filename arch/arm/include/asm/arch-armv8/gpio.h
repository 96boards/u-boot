/*
 * Copyright (C) 2015 Linaro
 * Peter Griffin <peter.griffin@linaro.org>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _HI6220_GPIO_H_
#define _HI6220_GPIO_H_

#define HI6220_GPIO0_BASE	(void *)0xf8011000
#define HI6220_GPIO1_BASE	(void *)0xf8012000
#define HI6220_GPIO2_BASE	(void *)0xf8013000
#define HI6220_GPIO3_BASE	(void *)0xf8014000
#define HI6220_GPIO4_BASE	(void *)0xf7020000
#define HI6220_GPIO5_BASE	(void *)0xf7021000
#define HI6220_GPIO6_BASE	(void *)0xf7022000
#define HI6220_GPIO7_BASE	(void *)0xf7023000
#define HI6220_GPIO8_BASE	(void *)0xf7024000
#define HI6220_GPIO9_BASE	(void *)0xf7025000
#define HI6220_GPIO10_BASE	(void *)0xf7026000
#define HI6220_GPIO11_BASE	(void *)0xf7027000
#define HI6220_GPIO12_BASE	(void *)0xf7028000
#define HI6220_GPIO13_BASE	(void *)0xf7029000
#define HI6220_GPIO14_BASE	(void *)0xf702a000
#define HI6220_GPIO15_BASE	(void *)0xf702b000
#define HI6220_GPIO16_BASE	(void *)0xf702c000
#define HI6220_GPIO17_BASE	(void *)0xf702d000
#define HI6220_GPIO18_BASE	(void *)0xf702e000
#define HI6220_GPIO19_BASE	(void *)0xf702f000

#define BIT(x) 			(1 << (x))

#define HI6220_GPIO_PER_BANK	8
#define HI6220_GPIO_DIR		0x400

struct gpio_bank {
	u8 *base;	/* address of registers in physical memory */
};

/* Information about a GPIO bank */
struct hikey_gpio_platdata {
	int bank_index;
	void *base;     /* address of registers in physical memory */
};

#endif /* _HI6220_GPIO_H_ */
