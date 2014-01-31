#include <linux/gpio.h>
#include <linux/serial_core.h>
#include <plat/devs.h>
#include <plat/gpio-cfg.h>
#include <plat/regs-serial.h>
#include <mach/gpio.h>
#include "px.h"

struct gpio_init_data {
	uint num;
	uint cfg;
	uint val;
	uint pud;
	uint drv;
};

static struct gpio_init_data p2_init_gpios[] = {
	{
		.num	= EXYNOS4_GPD0(2),	/* MSENSOR_MHL_SDA_2.8V */
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_NONE,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPD0(3),	/* MSENSOR_MHL_SCL_2.8V */
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_NONE,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	},  {
		.num	= EXYNOS4_GPD1(2),	/* SENSE_SDA_2.8V */
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_NONE,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPD1(3),	/* SENSE_SCL_2.8V */
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_NONE,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPK2(2),	/* PS_ALS_SDA_2.8V */
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_NONE,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPK3(2),	/* PS_ALS_SCL_2.8V */
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_NONE,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {	/* GPY0 */
		.num	= EXYNOS4_GPY0(0),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY0(1),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY0(2),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY0(3),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY0(4),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY0(5),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {	/* GPY1 */
		.num	= EXYNOS4_GPY1(0),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY1(1),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY1(2),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY1(3),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {	/* GPY2 */
		.num	= EXYNOS4_GPY2(0),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY2(1),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY2(2),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY2(3),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY2(4),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY2(5),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {	/* GPY3 */
		.num	= EXYNOS4_GPY3(1),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY3(3),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {	/* GPY4 */
		.num	= EXYNOS4_GPY4(4),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {	/* GPY6 */
		.num	= EXYNOS4_GPY6(0),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY6(2),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY6(3),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY6(4),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	}, {
		.num	= EXYNOS4_GPY6(5),
		.cfg	= S3C_GPIO_INPUT,
		.val	= S3C_GPIO_SETPIN_NONE,
		.pud	= S3C_GPIO_PULL_DOWN,
		.drv	= S5P_GPIO_DRVSTR_LV1,
	},
	/* BT UART */
	{GPIO_BT_RXD, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_UP},
	{GPIO_BT_TXD, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_NONE},
	{GPIO_BT_CTS, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_NONE},
	{GPIO_BT_RTS, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_NONE},
	/* GPS UART */
	{GPIO_GPS_RXD, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_UP},
	{GPIO_GPS_TXD, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_NONE},
	{GPIO_GPS_CTS, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_NONE},
	{GPIO_GPS_RTS, S3C_GPIO_SFN(2), 2, S3C_GPIO_PULL_NONE},
	{GPIO_GPS_PWR_EN, S3C_GPIO_OUTPUT, 0, S3C_GPIO_PULL_NONE},

	/* UART switch: configure as output */
	{GPIO_UART_SEL, S3C_GPIO_OUTPUT, 2, S3C_GPIO_PULL_NONE},

	/* USB switch: configure as output */
	{GPIO_USB_SEL1, S3C_GPIO_OUTPUT, 2, S3C_GPIO_PULL_NONE},
	{GPIO_USB_SEL2, S3C_GPIO_OUTPUT, 2, S3C_GPIO_PULL_NONE},
	{GPIO_USB_SEL3, S3C_GPIO_OUTPUT, 2, S3C_GPIO_PULL_NONE},

	/* JIG On */
	{GPIO_IF_CON_SENSE, S3C_GPIO_INPUT, 2, S3C_GPIO_PULL_NONE},

	/* 30PIN CONNECTOR */
	{GPIO_DOCK_INT, S3C_GPIO_INPUT, 2, S3C_GPIO_PULL_NONE},

	/* MIC */
	{GPIO_EAR_MIC_BIAS_EN, S3C_GPIO_OUTPUT, 0, S3C_GPIO_PULL_NONE},

	/*** GPX ***/
	{GPIO_GYRO_INT,		S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
/* REMOTE_SENSE_IRQ */
	{EXYNOS4_GPX0(2),	S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	{GPIO_ACCESSORY_INT,	S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	{GPIO_MSENSE_INT,	S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	{GPIO_FUEL_ALERT,	S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	/* {GPIO_BT_HOST_WAKE, S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE}, */
	{GPIO_DET_35,		S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	{GPIO_USB_OTG_EN,	S3C_GPIO_OUTPUT, 0, S3C_GPIO_PULL_NONE},
	/* T_FLASH_DETECT */
	{EXYNOS4_GPX3(4),	S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	/* TA_nCONNECTED */
	{EXYNOS4_GPX3(5),	S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
	{GPIO_HDMI_HPD,		S3C_GPIO_INPUT,  2, S3C_GPIO_PULL_NONE},
};

void p2_config_gpio_table(void)
{
	u32 i, gpio;
	u32 gps_gpio1, gps_gpio2;

	printk(KERN_DEBUG "%s\n", __func__);

	for (i = 0; i < ARRAY_SIZE(p2_init_gpios); i++) {
		gpio = p2_init_gpios[i].num;
		s3c_gpio_cfgpin(gpio, p2_init_gpios[i].cfg);
		s3c_gpio_setpull(gpio, p2_init_gpios[i].pud);

		if (p2_init_gpios[i].val != S3C_GPIO_SETPIN_NONE)
			gpio_set_value(gpio, p2_init_gpios[i].val);

		s5p_gpio_set_drvstr(gpio, p2_init_gpios[i].drv);
	}
	/* Set GPIO_GPS_nRST 2.8V Domain for HW rev 05 above
	 * Set GPIO_GPS_nRST 1.8V Domain for HW rev 04 under
	 */
	if (system_rev >= 5) {
		gps_gpio1 = GPIO_GPS_nRST_28V;
		gps_gpio2 = GPIO_GPS_nRST; /* NC */
	} else {
		gps_gpio1 = GPIO_GPS_nRST;
		gps_gpio2 = GPIO_GPS_nRST_28V; /* NC */
	}

	gpio_set_value(gps_gpio1, 1);
	s3c_gpio_cfgpin(gps_gpio1, S3C_GPIO_OUTPUT);
	s3c_gpio_setpull(gps_gpio1, S3C_GPIO_PULL_UP);
	s5p_gpio_set_drvstr(gps_gpio1, 0);

	gpio_set_value(gps_gpio2, 0);
	s3c_gpio_cfgpin(gps_gpio2, S3C_GPIO_OUTPUT);
	s3c_gpio_setpull(gps_gpio2, S3C_GPIO_PULL_NONE);
}

/* this table only for p2 board */
static unsigned int p2_sleep_gpio_table[][3] = {
	{EXYNOS4_GPA0(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPA0(1),  S3C_GPIO_SLP_OUT1,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPA0(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPA0(3),  S3C_GPIO_SLP_OUT1,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPA0(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPA0(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPA0(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPA0(7),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4_GPA1(0),  S3C_GPIO_SLP_INPUT,  S3C_GPIO_PULL_UP},
	{EXYNOS4_GPA1(1),  S3C_GPIO_SLP_INPUT,  S3C_GPIO_PULL_UP},
	{EXYNOS4_GPA1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPA1(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPA1(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPA1(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPB(0),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPB(1),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPB(2),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPB(3),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* IRDA_nINT */
	{EXYNOS4_GPB(4),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* IRDA_nRST */
	{EXYNOS4_GPB(5),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPB(6),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPB(7),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPC0(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC0(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPC0(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC0(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC0(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPC1(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC1(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC1(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPC1(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPD0(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPD0(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPD0(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPD0(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPD1(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPD1(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPD1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPD1(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},

	{EXYNOS4210_GPE0(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE0(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE0(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE0(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE0(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4210_GPE1(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE1(7),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4210_GPE2(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE2(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE2(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE2(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE2(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4210_GPE2(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4210_GPE3(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE3(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4210_GPE4(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPE4(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPF0(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF0(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPF1(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF1(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPF2(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF2(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPF3(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF3(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF3(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF3(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF3(4),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPF3(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4210_GPJ0(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ0(7),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},

	{EXYNOS4210_GPJ1(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ1(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4210_GPJ1(3),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4210_GPJ1(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4_GPK0(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK0(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK0(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPK0(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK0(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK0(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK0(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},

	/* IRDA_SCL_2.8V */
	{EXYNOS4_GPK1(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPK1(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	/* IRDA_SDA_2.8V */
	{EXYNOS4_GPK1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPK1(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK1(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK1(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK1(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},

	{EXYNOS4_GPK2(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK2(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK2(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPK2(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK2(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK2(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPK2(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},

	{EXYNOS4_GPK3(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPK3(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPK3(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPK3(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPK3(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPK3(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},
	{EXYNOS4_GPK3(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_UP},

	{EXYNOS4_GPL0(0),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL0(1),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL0(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	/* GPS_nRST 2.8V */
	{EXYNOS4_GPL0(3),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL0(4),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL0(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL0(6),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL0(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPL1(0),  S3C_GPIO_SLP_PREV, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL1(1),  S3C_GPIO_SLP_OUT0, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL1(2),  S3C_GPIO_SLP_PREV, S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPL2(0),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL2(1),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL2(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL2(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN},
	{EXYNOS4_GPL2(4),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL2(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPL2(6),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPL2(7),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPY0(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY0(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY0(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY0(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY0(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY0(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4_GPY1(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY1(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY1(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY1(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	{EXYNOS4_GPY2(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY2(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY2(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY2(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY2(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY2(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */

	/* MHL_SDA_1.8V */
	{EXYNOS4_GPY3(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY3(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	/* MHL_SCL_1.8V */
	{EXYNOS4_GPY3(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY3(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY3(4),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY3(5),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY3(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	/* USB_SEL2 */
	{EXYNOS4_GPY3(7),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPY4(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY4(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* GPIO_PDA_ACTIVE */
	{EXYNOS4_GPY4(2),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY4(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* V_ACCESSORY_5V CHECK */
	{EXYNOS4_GPY4(4),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	/* USB_SEL3 */
	{EXYNOS4_GPY4(5),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	/* GPIO_CP_REQ_RESET */
	{EXYNOS4_GPY4(6),  S3C_GPIO_SLP_OUT1,  S3C_GPIO_PULL_NONE},
	/* GPIO_UART_SEL */
	{EXYNOS4_GPY4(7),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},

	/* HW_REV0 */
	{EXYNOS4_GPY5(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* HW_REV1 */
	{EXYNOS4_GPY5(1),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* HW_REV2 */
	{EXYNOS4_GPY5(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* HW_REV3 */
	{EXYNOS4_GPY5(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	/* GPS_nRST */
	{EXYNOS4_GPY5(4),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY5(5),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY5(6),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY5(7),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPY6(0),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	/* ACCESSORY_EN */
	{EXYNOS4_GPY6(1),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPY6(2),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY6(3),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY6(4),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY6(5),  S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPY6(6),  S3C_GPIO_SLP_OUT0,  S3C_GPIO_PULL_NONE}, /* TA_EN */
	{EXYNOS4_GPY6(7),  S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},

	{EXYNOS4_GPZ(0),   S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPZ(1),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPZ(2),   S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPZ(3),   S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPZ(4),   S3C_GPIO_SLP_PREV,  S3C_GPIO_PULL_NONE},
	{EXYNOS4_GPZ(5),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
	{EXYNOS4_GPZ(6),   S3C_GPIO_SLP_INPUT, S3C_GPIO_PULL_DOWN}, /* NC */
};

static void config_sleep_gpio_table(int array_size,
				    unsigned int (*gpio_table)[3])
{
	u32 i, gpio;

	for (i = 0; i < array_size; i++) {
		gpio = gpio_table[i][0];
		s3c_gpio_slp_cfgpin(gpio, gpio_table[i][1]);
		s3c_gpio_slp_setpull_updown(gpio, gpio_table[i][2]);
	}
}

void p2_config_sleep_gpio_table(void)
{
	config_sleep_gpio_table(ARRAY_SIZE(p2_sleep_gpio_table),
			p2_sleep_gpio_table);
}
