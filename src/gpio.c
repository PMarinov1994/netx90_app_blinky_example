/*
 * gpio.c
 *
 *  Created on: Jun 23, 2021
 *      Author: PMarinova
 */

#include "gpio.h"
#include "netx_regdefs/netx90/netx90_regdef.h"


static NX90_GPIO_APP_AREA_T*  s_ptGpio = (NX90_GPIO_APP_AREA_T*) Addr_NX90_gpio_app;

#define DEV_FREQUENCY 100000000L // 100 Mhz


/*****************************************************************************/
/*! GPIO Setup Mode                                                          */
/*****************************************************************************/
void Gpio_SetupMode( unsigned long ulGpioNum, unsigned long ulMode, unsigned long ulInvert )
{
  s_ptGpio->aulGpio_app_cfg[ulGpioNum] = (unsigned long) (ulMode | ulInvert);
}


/*****************************************************************************/
/*! GPIO Set Output                                                          */
/*****************************************************************************/
void Gpio_SetOutput( unsigned long ulGpioNum, int fEnable )
{
  if( fEnable )
    s_ptGpio->ulGpio_app_line |= 1 << ulGpioNum;
  else
    s_ptGpio->ulGpio_app_line &= ~(1 << ulGpioNum);
}


/*****************************************************************************/
/*! GPIO Sleep                                                               */
/*****************************************************************************/
void Gpio_Sleep( unsigned long ulCounter, unsigned int uiTimeout )
{
  unsigned int uiVal;

  /* Convert counter value from µs to ns */
  uiTimeout = uiTimeout * (DEV_FREQUENCY/1000000);

  s_ptGpio->aulGpio_app_counter_ctrl[ulCounter]  = 0;          /* Clear the timer register         */
  s_ptGpio->aulGpio_app_counter_cnt[ulCounter]   = 0;          /* Clear the current counter value  */
  s_ptGpio->aulGpio_app_counter_max[ulCounter]   = uiTimeout;  /* Set the counter value            */
  s_ptGpio->aulGpio_app_counter_ctrl[ulCounter] |= (MSK_NX90_gpio_app_counter0_ctrl_run | MSK_NX90_gpio_app_counter0_ctrl_once  ); /* Enable the timer to one shot */

  /* poll timer ctrl for 'run' bit */
  do {
    uiVal  = s_ptGpio->aulGpio_app_counter_ctrl[ulCounter];
    uiVal &= MSK_NX90_gpio_app_counter0_ctrl_run;
  } while ( uiVal!=0 );
}
