/*
 * arch/arm/mach-ep93xx/cirroz.c
 *
 * CIRROZ board
 * Copyright (C) 2007-2013 Sergey Kostanbaev <sergey.kostanbaev@gmail.com>
 *
 * EDB93XX, EDB9301, EDB9307A
 * Copyright (C) 2008-2009 H Hartley Sweeten <hsweeten@visionengravers.com>
 *
 * EDB9302
 * Copyright (C) 2006 George Kashperko <george@chas.com.ua>
 *
 * EDB9302A, EDB9315, EDB9315A
 * Copyright (C) 2006 Lennert Buytenhek <buytenh@wantstofly.org>
 *
 * EDB9307
 * Copyright (C) 2007 Herbert Valerio Riedel <hvr@gnu.org>
 *
 * EDB9312
 * Copyright (C) 2006 Infosys Technologies Limited
 *                    Toufeeq Hussain <toufeeq_hussain@infosys.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/mtd/partitions.h>
#include <linux/i2c.h>
#include <linux/i2c-gpio.h>
#include <linux/spi/spi.h>
#include <linux/spi/flash.h>
#include <linux/spi/mmc_spi.h>
#include <linux/mmc/host.h>

#include <sound/cs4271.h>
#include <linux/spi/ds1305.h>

#include <mach/hardware.h>
#include <linux/platform_data/video-ep93xx.h>
#include <linux/platform_data/spi-ep93xx.h>
#include <mach/gpio-ep93xx.h>

#include <asm/mach-types.h>
#include <asm/mach/arch.h>

#include "soc.h"


static struct ep93xx_eth_data __initdata cirroz_eth_data = {
	.phy_id		= 1,
};

#if 0
/*************************************************************************
 * i2c peripheral handling
 *************************************************************************/
static struct i2c_gpio_platform_data __initdata cirroz_i2c_gpio_data = {
	.sda_pin		= EP93XX_GPIO_LINE_EEDAT,
	.sda_is_open_drain	= 0,
	.scl_pin		= EP93XX_GPIO_LINE_EECLK,
	.scl_is_open_drain	= 0,
	.udelay			= 0,	/* default to 100 kHz */
	.timeout		= 0,	/* default to 100 ms */
};

static struct i2c_board_info __initdata cirroz_i2c_board_info[] = {
	{
	},
};

static void __init cirroz_register_i2c(void)
{
    ep93xx_register_i2c(&cirroz_i2c_gpio_data,
                    cirroz_i2c_board_info,
                    ARRAY_SIZE(cirroz_i2c_board_info));
    }
}
#endif

/*************************************************************************
 * SPI SD/MMC host
 *************************************************************************/
#define CIRROZ_SPI_MMC_CS	EP93XX_GPIO_LINE_EGPIO4
#define CIRROZ_SPI_MMC_PWR	EP93XX_GPIO_LINE_EGPIO9
#define CIRROZ_SPI_MMC_CD	EP93XX_GPIO_LINE_EGPIO8

static struct mmc_spi_platform_data cirroz_spi_mmc_data = {
    .detect_delay	= 100,
    .powerup_msecs	= 100,
    .ocr_mask	= MMC_VDD_32_33 | MMC_VDD_33_34,
    .flags		= MMC_SPI_USE_CD_GPIO,
    .cd_gpio	= CIRROZ_SPI_MMC_CD,
    .cd_debounce	= 1,
    .ro_gpio	= -EINVAL,
    .caps2		= 0,
};

static int cirroz_spi_mmc_hw_setup(struct spi_device *spi)
{
    int err = gpio_request_one(CIRROZ_SPI_MMC_CS, GPIOF_INIT_HIGH,
                spi->modalias);
    if (err != 0) {
        return err;
    }

    err =  gpio_request_one(CIRROZ_SPI_MMC_PWR, GPIOF_INIT_LOW,
                            spi->modalias);
    if (err != 0) {
        gpio_free(CIRROZ_SPI_MMC_CS);
    }
    return err;
}

static void cirroz_spi_mmc_hw_cleanup(struct spi_device *spi)
{
    gpio_free(CIRROZ_SPI_MMC_CS);
    gpio_free(CIRROZ_SPI_MMC_PWR);
}

static void cirroz_spi_mmc_hw_cs_control(struct spi_device *spi, int value)
{
    gpio_set_value(CIRROZ_SPI_MMC_CS, value);
}

static struct ep93xx_spi_chip_ops cirroz_spi_mmc_hw = {
    .setup		= cirroz_spi_mmc_hw_setup,
    .cleanup	= cirroz_spi_mmc_hw_cleanup,
    .cs_control	= cirroz_spi_mmc_hw_cs_control,
};

/*************************************************************************
 * SPI peripheral handling
 *************************************************************************/
static struct cs4271_platform_data cirroz_cs4271_data = {
    .gpio_nreset	= EP93XX_GPIO_LINE_EGPIO14,
};

static int cirroz_cs4271_hw_setup(struct spi_device *spi)
{
	return gpio_request_one(EP93XX_GPIO_LINE_EGPIO6,
				GPIOF_OUT_INIT_HIGH, spi->modalias);
}

static void cirroz_cs4271_hw_cleanup(struct spi_device *spi)
{
	gpio_free(EP93XX_GPIO_LINE_EGPIO6);
}

static void cirroz_cs4271_hw_cs_control(struct spi_device *spi, int value)
{
	gpio_set_value(EP93XX_GPIO_LINE_EGPIO6, value);
}

static struct ep93xx_spi_chip_ops cirroz_cs4271_hw = {
    .setup		= cirroz_cs4271_hw_setup,
    .cleanup	= cirroz_cs4271_hw_cleanup,
    .cs_control	= cirroz_cs4271_hw_cs_control,
};

/*************************************************************************
 * ds1305/1306 RTC handling
 *************************************************************************/

static int cirroz_ds1305_hw_setup(struct spi_device *spi)
{
    return gpio_request_one(EP93XX_GPIO_LINE_EGPIO13,
                GPIOF_OUT_INIT_HIGH, spi->modalias);
}

static void cirroz_ds1305_hw_cleanup(struct spi_device *spi)
{
    gpio_free(EP93XX_GPIO_LINE_EGPIO13);
}

static void cirroz_ds1305_hw_cs_control(struct spi_device *spi, int value)
{
    gpio_set_value(EP93XX_GPIO_LINE_EGPIO13, value);
}

static struct ep93xx_spi_chip_ops cirroz_spi_rtc_hw = {
    .setup		= cirroz_ds1305_hw_setup,
    .cleanup	= cirroz_ds1305_hw_cleanup,
    .cs_control	= cirroz_ds1305_hw_cs_control,
};

static struct ds1305_platform_data cirroz_spi_rtc_data = {
    .is_ds1306 = 1,
    .en_1hz = 0,
};

/*************************************************************************
 * SPI Flash
 *************************************************************************/
#define CIRROZ_SPI_FLASH_CS	EP93XX_GPIO_LINE_EGPIO7

static struct mtd_partition cirroz_spi_flash_partitions[] = {
    {
        .name	= "SPI bootstrap",
        .offset	= 0,
        .size	= SZ_4K,
    }, {
        .name	= "Bootstrap config",
        .offset	= MTDPART_OFS_APPEND,
        .size	= SZ_4K,
    }, {
        .name	= "System config",
        .offset	= MTDPART_OFS_APPEND,
        .size	= MTDPART_SIZ_FULL,
    },
};

static struct flash_platform_data cirroz_spi_flash_data = {
    .name		= "at25f1024",
    .parts		= cirroz_spi_flash_partitions,
    .nr_parts	= ARRAY_SIZE(cirroz_spi_flash_partitions),
};

static int cirroz_spi_flash_hw_setup(struct spi_device *spi)
{
    return gpio_request_one(CIRROZ_SPI_FLASH_CS, GPIOF_INIT_HIGH,
                spi->modalias);
}

static void cirroz_spi_flash_hw_cleanup(struct spi_device *spi)
{
    gpio_free(CIRROZ_SPI_FLASH_CS);
}

static void cirroz_spi_flash_hw_cs_control(struct spi_device *spi, int value)
{
    gpio_set_value(CIRROZ_SPI_FLASH_CS, value);
}

static struct ep93xx_spi_chip_ops cirroz_spi_flash_hw = {
    .setup		= cirroz_spi_flash_hw_setup,
    .cleanup	= cirroz_spi_flash_hw_cleanup,
    .cs_control	= cirroz_spi_flash_hw_cs_control,
};

static struct spi_board_info cirroz_spi_board_info[] __initdata = {
	{
		.modalias		= "cs4271",
        .platform_data		= &cirroz_cs4271_data,
        .controller_data	= &cirroz_cs4271_hw,
		.max_speed_hz		= 6000000,
		.bus_num		= 0,
		.chip_select		= 0,
		.mode			= SPI_MODE_3,
    }, {
        .modalias		= "rtc-ds1305",
        .platform_data		= &cirroz_spi_rtc_data,
        .controller_data	= &cirroz_spi_rtc_hw,
        .max_speed_hz		= 2000000,
        .bus_num		= 0,
        .chip_select		= 1,
        .mode			= SPI_MODE_3,
    }, {
        .modalias		= "m25p80",
        .platform_data		= &cirroz_spi_flash_data,
        .controller_data	= &cirroz_spi_flash_hw,
        .max_speed_hz		= 20000000,
        .bus_num		= 0,
        .chip_select		= 2,
        .mode			= SPI_MODE_3,
    }, {
        .modalias		= "mmc_spi",
        .platform_data		= &cirroz_spi_mmc_data,
        .controller_data	= &cirroz_spi_mmc_hw,
        .max_speed_hz		= 20000000,
        .bus_num		= 0,
        .chip_select		= 3,
        .mode			= SPI_MODE_3,
    },
};

static struct ep93xx_spi_info cirroz_spi_info __initdata = {
    .num_chipselect	= ARRAY_SIZE(cirroz_spi_board_info),
};

static void __init cirroz_register_spi(void)
{
    ep93xx_register_spi(&cirroz_spi_info, cirroz_spi_board_info,
                ARRAY_SIZE(cirroz_spi_board_info));
}


/*************************************************************************
 * I2S
 *************************************************************************/
static struct platform_device cirroz_audio_device = {
	.name		= "edb93xx-audio",
	.id		= -1,
};

static void __init cirroz_register_i2s(void)
{
    ep93xx_register_i2s();
    platform_device_register(&cirroz_audio_device);
}


/*************************************************************************
 * framebuffer
 *************************************************************************/
static struct ep93xxfb_mach_info __initdata cirroz_info = {
	.num_modes	= EP93XXFB_USE_MODEDB,
	.bpp		= 16,
    .flags		= EP93XXFB_USE_SDCSN0,
};

static void __init cirroz_init_machine(void)
{
    printk(KERN_WARNING "CIRROZ initializing");
	ep93xx_init_devices();
    ep93xx_register_flash(2, EP93XX_CS6_PHYS_BASE, SZ_16M);
    ep93xx_register_eth(&cirroz_eth_data, 1);
    /* cirroz_register_i2c(); */
    cirroz_register_spi();
    cirroz_register_i2s();
    ep93xx_register_pwm(1, 1);
    ep93xx_register_fb(&cirroz_info);
    ep93xx_register_ide();
}


MACHINE_START(EDB9315A, "CIRROZ Board")
	/* Maintainer: Lennert Buytenhek <buytenh@wantstofly.org> */
	.atag_offset	= 0x100,
	.map_io		= ep93xx_map_io,
	.init_irq	= ep93xx_init_irq,
	.init_time	= ep93xx_timer_init,
    .init_machine	= cirroz_init_machine,
	.init_late	= ep93xx_init_late,
	.restart	= ep93xx_restart,
MACHINE_END
