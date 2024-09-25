#ifndef __MMIO_CONFIG_H
#define __MMIO_CONFIG_H

#include "netx90_mmio.h"
#include "netx90_regdef.h"

typedef struct MMIO_CONFIG_Ttag
{
  unsigned char bMmio;
  unsigned char bFunction;
  unsigned char fInvertIn;
  unsigned char fInvertOut;
} MMIO_CONFIG_T;

void mmio_config_netx90_app( void );

#endif // !__MMIO_CONFIG_H
