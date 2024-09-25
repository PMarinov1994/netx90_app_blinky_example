/*
 * gpio.h
 *
 *  Created on: Jun 23, 2021
 *      Author: PMarinova
 */

#ifndef __GPIO_H_
#define __GPIO_H_

#define GPIO_MODE_OUTPUT_SET_TO_GPIO_LINE 0x6
#define GPIO_MODE_NOINVERT 0x0
#define GPIO_CNTR_0 0x0

void Gpio_SetupMode( unsigned long ulGpioNum, unsigned long ulMode, unsigned long ulInvert );
void Gpio_SetOutput( unsigned long ulGpioNum, int fEnable );
void Gpio_Sleep( unsigned long ulCounter, unsigned int uiTimeout );

#endif /* __GPIO_H_ */
