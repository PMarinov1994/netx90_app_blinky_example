#ifndef __NETX_REGDEF_H
#define __NETX_REGDEF_H

#include "asic_types.h"

#if ASIC_TYP==ASIC_TYP_NETX90_APP || ASIC_TYP==ASIC_TYP_NETX90
#include "netx90/netx90_regdef.h"
#elif ASIC_TYP==ASIC_TYP_NETX56
#include "netx56/netx56_regdef.h"
#elif ASIC_TYP == ASIC_TYP_NETX500
#include "netx500/netx500_regdef.h"
#elif ASIC_TYP == ASIC_TYP_NETX10
#include "netx10/netx10_regdef.h"
#endif

#endif // !__NETX_REGDEF_H
