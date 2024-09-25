/**************************************************************************//**
 * @file    main.c
 * @brief   Main program body
 * $Revision: 4507 $
 * $Date: 2018-11-20 13:25:13 +0100 (Di, 20 Nov 2018) $
 * \copyright Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
 * \note Exclusion of Liability for this demo software:
 * The following software is intended for and must only be used for reference and in an
 * evaluation laboratory environment. It is provided without charge and is subject to
 * alterations. There is no warranty for the software, to the extent permitted by
 * applicable law. Except when otherwise stated in writing the copyright holders and/or
 * other parties provide the software "as is" without warranty of any kind, either
 * expressed or implied.
 * Please refer to the Agreement in README_DISCLAIMER.txt, provided together with this file!
 * By installing or otherwise using the software, you accept the terms of this Agreement.
 * If you do not agree to the terms of this Agreement, then do not install or use the
 * Software!
 ******************************************************************************/

#include "main.h"
#include "gpio.h"

#define CMAKE 1
#define WAF   2


/*!
 * \brief A very simple program which turns on and then off the LEDs connected to GPIO0-3
 * The hardware configuration defined in HWC/hardware_config.xml configures MMIO4-7 as GPIO0-3.
 * On an NXHX 90-JTAG board MMIO4-7 are connected to LEDs located right next to the reset button.
 * Make sure the S701.4 switch is set to ON to enable the user defined LEDs.
 * \return Will always return 0.
 */
int main(void) {
	Gpio_SetupMode(0, GPIO_MODE_OUTPUT_SET_TO_GPIO_LINE, GPIO_MODE_NOINVERT);
	Gpio_SetupMode(1, GPIO_MODE_OUTPUT_SET_TO_GPIO_LINE, GPIO_MODE_NOINVERT);
	Gpio_SetupMode(2, GPIO_MODE_OUTPUT_SET_TO_GPIO_LINE, GPIO_MODE_NOINVERT);
	Gpio_SetupMode(3, GPIO_MODE_OUTPUT_SET_TO_GPIO_LINE, GPIO_MODE_NOINVERT);

#if __BLD_SYSTEM__ == CMAKE
	const short sleep_time_ms = 100;
#elif __BLD_SYSTEM__ == WAF
	const short sleep_time_ms = 500;
#else
	#error "No BLD_SYSTEM defined"
#endif

	while (1) {
		// Turn all LEDs on
		for (int gpio = 0; gpio <= 3; gpio++) {
			Gpio_SetOutput(gpio, 1);
			// Wait for about 100ms
			Gpio_Sleep( GPIO_CNTR_0, sleep_time_ms * 1000);
		}

		// Wait for about 100ms
		Gpio_Sleep( GPIO_CNTR_0, sleep_time_ms * 1000);

		// Turn all LEDs off
		for (int gpio = 0; gpio <= 3; gpio++) {
			Gpio_SetOutput(gpio, 0);
			// Wait for about 100ms
			Gpio_Sleep( GPIO_CNTR_0, sleep_time_ms * 1000);
		}

		// Wait for about 100ms
		Gpio_Sleep( GPIO_CNTR_0, sleep_time_ms * 1000);
	}

	return 0;
}
