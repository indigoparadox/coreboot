/* SPDX-License-Identifier: GPL-2.0-only */

#include <boot/coreboot_tables.h>
#include <drivers/tpm/cr50.h>
#include <gpio.h>

#include "gpio.h"

void setup_chromeos_gpios(void)
{
	gpio_input(GPIO_EC_AP_INT_ODL);
	gpio_input(GPIO_GSC_AP_INT_ODL);
	gpio_input(GPIO_SD_CD_AP_ODL);
	gpio_output(GPIO_AP_EC_WARM_RST_REQ, 0);
	gpio_output(GPIO_AP_FP_FW_UP_STRAP, 0);
	gpio_output(GPIO_BEEP_ON_OD, 0);
	gpio_output(GPIO_EN_PWR_FP, 0);
	gpio_output(GPIO_EN_SPKR, 0);
	gpio_output(GPIO_FP_RST_1V8_S3_L, 0);
	gpio_output(GPIO_XHCI_INIT_DONE, 0);
}

void fill_lb_gpios(struct lb_gpios *gpios)
{
	struct lb_gpio chromeos_gpios[] = {
		{ GPIO_XHCI_INIT_DONE.id, ACTIVE_HIGH, -1, "XHCI init done" },
		{ GPIO_EN_SPKR.id, ACTIVE_HIGH, -1, "speaker enable" },
		{ GPIO_EC_AP_INT_ODL.id, ACTIVE_LOW, -1, "EC interrupt" },
		{ GPIO_BEEP_ON_OD.id, ACTIVE_HIGH, -1, "beep enable" },
		{ GPIO_GSC_AP_INT_ODL.id, ACTIVE_HIGH, -1, "TPM interrupt" },
	};
	lb_add_gpios(gpios, chromeos_gpios, ARRAY_SIZE(chromeos_gpios));

	if (CONFIG(RAURU_SDCARD_INIT)) {
		struct lb_gpio sd_card_gpios[] = {
			{ GPIO_SD_CD_AP_ODL.id, ACTIVE_LOW, -1, "SD card detect" },
		};
		lb_add_gpios(gpios, sd_card_gpios, ARRAY_SIZE(sd_card_gpios));
	}
}

int cr50_plat_irq_status(void)
{
	return gpio_eint_poll(GPIO_GSC_AP_INT_ODL);
}
