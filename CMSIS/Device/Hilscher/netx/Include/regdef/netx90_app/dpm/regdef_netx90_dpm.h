/*********************************************************************/
/* Based on verilog file from: 190308_0616                           */
/* SVN Revision: $Rev: 1158 $        release-1.4.0.1                 */
/* from regdef.v by regdef2h auto-generated C-header file            */
/* please see the regdef.html file for detailed register description */
/*********************************************************************/

#ifndef __regdef_netx90_dpm_h__
#define __regdef_netx90_dpm_h__

#include <stdint.h>

/* ===================================================================== */

/* AREA dpm */
/* Area of dpm0_com, dpm1_com */

/* ===================================================================== */

#define Addr_NX90_dpm0_com 0xFF001900U
#define Addr_NX90_dpm1_com 0xFF001A00U

/* --------------------------------------------------------------------- */
/* Register dpm_cfg0x0 */
/* => DPM IO Control Register 0. */
/*    This register is accessible in any DPM-mode (8, 16 bit, SRAM, Intel, Motorola, little endian, big endian) by access to DPM address 0. */
/*    Basic DPM settings are configurable here to make higher addresses accessible. */
/*    To avoid instable system configurations, global changes of important configuration registers must be confirmed */
/*    (re)writing 'mode' bit field of this register. View 'mode' description for details. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_cfg0x0      0x00000000U
#define Adr_NX90_dpm0_com_dpm_cfg0x0 0xFF001900U
#define Adr_NX90_dpm1_com_dpm_cfg0x0 0xFF001A00U
#define DFLT_VAL_NX90_dpm_cfg0x0     0x00000000U

#define MSK_NX90_dpm_cfg0x0_mode           0x0000000fU
#define SRT_NX90_dpm_cfg0x0_mode           0
#define DFLT_VAL_NX90_dpm_cfg0x0_mode      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_cfg0x0_mode   0x00000000U
#define MSK_NX90_dpm_cfg0x0_endian         0x00000030U
#define SRT_NX90_dpm_cfg0x0_endian         4
#define DFLT_VAL_NX90_dpm_cfg0x0_endian    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_cfg0x0_endian 0x00000000U

/* all used bits of 'NX90_dpm_cfg0x0': */
#define MSK_USED_BITS_NX90_dpm_cfg0x0 0x0000003fU

enum {
  BFW_NX90_dpm_cfg0x0_mode      = 4,  /* [3:0] */
  BFW_NX90_dpm_cfg0x0_endian    = 2,  /* [5:4] */
  BFW_NX90_dpm_cfg0x0_reserved1 = 26  /* [31:6] */
};

typedef struct NX90_DPM_CFG0X0_BIT_Ttag {
  unsigned int mode      : BFW_NX90_dpm_cfg0x0_mode;      /* Basic DPM interface mode:                                                                               */
                                                          /* Additionally writing to this bit field will confirm global interface configuration changes:             */
                                                          /* Interface configuration can not always be written one single access (e.g. in 8 bit data mode            */
                                                          /* changing of 'dpm_if_cfg' is not possible in one single access as there are more than 8 bits             */
                                                          /* for configuration). However changing interface configuration by more than one single access could       */
                                                          /* lead to instable interfaces. This is avoided by following procedure:                                    */
                                                          /* For proper interface configuration, values of important interface configuration                         */
                                                          /* registers are buffered in temporary registers first. Interface configuration is changed                 */
                                                          /* finally by (re)writing 'mode' bits. There is no need to really change a prior programmed 'mode'         */
                                                          /* setting, interface change is done when low byte of this registers is target of a write access.          */
                                                          /* Temporary registers which must be confirmed by this are:                                                */
                                                          /* - All bits of 'dpm_if_cfg' register.                                                                    */
                                                          /* Note:                                                                                                   */
                                                          /*   The address comparators and the 'addr_cmp_a*' bit fields in 'dpm_addr_cfg' of earlier netX versions   */
                                                          /*   were dropped since netX90.                                                                            */
                                                          /* Note:                                                                                                   */
                                                          /*    Interface configuration confirm must be done regardless wether programmed by host via                */
                                                          /*    external interfaces or by internal ARM via internal INTLOGIC configuration channel.                  */
                                                          /* DPM interface mode must be further configured in 'dpm_if_cfg' register. Data width and                  */
                                                          /* address multiplexing mode must be configure here.                                                       */
                                                          /* Supported basic DPM modes are:                                                                          */
                                                          /* {     |                                                                                                 */
                                                          /*  0000  8 bit data non multiplexed mode.                                                                 */
                                                          /*        DPM_D7..0 are used as data lines, DPM_D15..8 can be used as PIOs (+8 PIOs).                      */
                                                          /*        DPM_A16 can be used as Address-Enable DPM_AEN/DPM_ALE.                                           */
                                                          /*  0001  reserved.                                                                                        */
                                                          /*  0010  8 bit data multiplexed mode.                                                                     */
                                                          /*        DPM_D7..0 are used as address and data lines, DPM_A16 as ALE.                                    */
                                                          /*        DPM_A7..0 and DPM_D15..8 can be used as PIOs (+16 PIOs).                                         */
                                                          /*        DPM_A10..8 will used as address lines.                                                           */
                                                          /*        DPM_A17, DPM_A15..11 can used as address lines (depending on selected 'addr_range'.              */
                                                          /*        High address lines will be sampled at the same time when lower address bits are                  */
                                                          /*        latched from DPM_D7..0.                                                                          */
                                                          /*  0011  reserved.                                                                                        */
                                                          /*  0100  16 bit data non multiplexed mode.                                                                */
                                                          /*        DPM_D15..0 are used as data lines.                                                               */
                                                          /*        DPM_A16 can be used as Address-Enable DPM_AEN/DPM_ALE.                                           */
                                                          /*  0101  reserved.                                                                                        */
                                                          /*  0110  16 bit data multiplexed mode with 2 byte-enables on separated lines.                             */
                                                          /*        DPM_D15..0 are used as address and data lines, DPM_A16 as ALE.                                   */
                                                          /*        DPM_A15..0 can be used as PIOs (+16 PIOs).                                                       */
                                                          /*        Two byte-enable signals can be used additionally. View register 'dpm_if_cfg' 'be_sel'.           */
                                                          /*        DPM_A17 can used as address lines (depending on selected 'addr_range'.                           */
                                                          /*        High address lines will be sampled at the same time when lower address bits are                  */
                                                          /*        latched from DPM_D15..0.                                                                         */
                                                          /*  0111  reserved                                                                                         */
                                                          /*    :   reserved.                                                                                        */
                                                          /*  1111  reserved.}                                                                                       */
                                                          /* Note:                                                                                                   */
                                                          /*    For DPM modes with less than 32 bit data, write data could not written immediate to netX memory or   */
                                                          /*    registers ('byte_area' and 'dis_rd_latch' of 'dpm_win1_map' register).                               */
  unsigned int endian    : BFW_NX90_dpm_cfg0x0_endian;    /* Endianess of 32 bit (DWord) address alignment (B0: least significant byte, B3: most significant byte):  */
                                                          /* {      |                     |      |      |      |                                                     */
                                                          /*  coding   Address               A+3    A+2    A+1    A+0                                                */
                                                          /*    00     little endian         B3     B2     B1     B0                                                 */
                                                          /*    01     16 bit big endian     B2     B3     B0     B1                                                 */
                                                          /*    10     32 bit big endian     B0     B1     B2     B3                                                 */
                                                          /*    11     reserved                                        }                                             */
                                                          /* Little endian is used netX inside. If big endian host device is used, set to this 01 or 10 according to */
                                                          /* host device data width.                                                                                 */
  unsigned int reserved1 : BFW_NX90_dpm_cfg0x0_reserved1; /* reserved                                                                                                */
} NX90_DPM_CFG0X0_BIT_T;

typedef union {
  uint32_t              val;
  NX90_DPM_CFG0X0_BIT_T bf;
} NX90_DPM_CFG0X0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_if_cfg */
/* => DPM interface configuration register. */
/*    DPM interface mode must be basically configured in 'dpm_cfg0x0' register. Interface configuration is */
/*    split up into two registers to support setup from external host CPU when DPM is in 8 bit non-multiplexed default mode after reset. */
/*    However this does not work for all interfaces. E.g. for modes where DPM_WRN is not write trigger this is not */
/*    possible. Interface setup must be done by netX internal CPU then. */
/*    To avoid instable system configurations, changes of this registers must be confirmed */
/*    (re)writing 'mode' bit field of dpm_cfg0x0 register. View 'mode' description there for details. */
/*     */
/*    {                                            |         |         |         |         |           |       |        |        |          | */
/*      Host connection                              cs_ctrl   addr_sh   aen_pol   aen_sel   be_wr       be_rd   be_pol   be_sel   dir_ctrl */
/* cfg_0x0.mode */
/*                                                                                           _dis        _dis */
/*      SRAM or Intel 8bit                                0         x         x        0       x           x       x         0         0         0x0 */
/*      SRAM, 16bit,byte-enable                           0         0         x        0       0           0       0         0         0         0x4 */
/*      SRAM, or Intel, 8bit multiplexed                  0         x         1        2       x           x       x         0         0         0x2 */
/*      SRAM, 16bit mul. (netx50: Intel, no BEs)          0         0         1        2       1           1       x         0         0         0x6 */
/*      SRAM, 16bit mul. 2BEs, byte-addr                  0         0         1        2       0           0       0         0         0         0x6 */
/*      SRAM, 16bit mul. 2BEs, word-addr                  0         1         1        2       0           0       0         0         0         0x6 */
/*      Intel, 16bit,byte-write                           0         0         x        0       0           1       0         1         1         0x4 */
/*      Intel, 16bit mul. byte-write                      0         1         1        2       0           1       0         1         1         0x6 */
/*      TI OMAP, 16bit non-multiplexed                    0         0         x        0       0           0       0         0         0         0x4 */
/*      TI OMAP, 16bit multiplexed                        0         1         0        2       0           0       0         0         0         0x6 */
/*      Motorola, 8bit (6800)                             0         x         x        0       0           0       1         1         2         0x0 */
/*      Motorola, 16bit                                   0         0         x        0       0           0       0         0         2         0x4 */
/*      Motorola, 16bit (68000)                           0         0         0        2       0           0       0         0         2         0x4 */
/*      Motorola, 8bit multiplexed                        0         x         x        0       0           0       1         1         2         0x2 */
/*      Motorola, 16bit mul.netx50: byte-addr             0         0         1        2       0           0       0         0         2         0x6 */
/*      Motorola, 16bit mul.word-addr                     0         1         1        2       0           0       0         0         2         0x6} */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_if_cfg      0x00000004U
#define Adr_NX90_dpm0_com_dpm_if_cfg 0xFF001904U
#define Adr_NX90_dpm1_com_dpm_if_cfg 0xFF001A04U
#define DFLT_VAL_NX90_dpm_if_cfg     0x00000000U

#define MSK_NX90_dpm_if_cfg_dir_ctrl          0x00000003U
#define SRT_NX90_dpm_if_cfg_dir_ctrl          0
#define DFLT_VAL_NX90_dpm_if_cfg_dir_ctrl     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_dir_ctrl  0x00000000U
#define MSK_NX90_dpm_if_cfg_be_sel            0x00000010U
#define SRT_NX90_dpm_if_cfg_be_sel            4
#define DFLT_VAL_NX90_dpm_if_cfg_be_sel       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_sel    0x00000000U
#define MSK_NX90_dpm_if_cfg_be_rd_dis         0x00000040U
#define SRT_NX90_dpm_if_cfg_be_rd_dis         6
#define DFLT_VAL_NX90_dpm_if_cfg_be_rd_dis    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_rd_dis 0x00000000U
#define MSK_NX90_dpm_if_cfg_be_wr_dis         0x00000080U
#define SRT_NX90_dpm_if_cfg_be_wr_dis         7
#define DFLT_VAL_NX90_dpm_if_cfg_be_wr_dis    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_wr_dis 0x00000000U
#define MSK_NX90_dpm_if_cfg_be_pol            0x00000300U
#define SRT_NX90_dpm_if_cfg_be_pol            8
#define DFLT_VAL_NX90_dpm_if_cfg_be_pol       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_pol    0x00000000U
#define MSK_NX90_dpm_if_cfg_aen_sel           0x00003000U
#define SRT_NX90_dpm_if_cfg_aen_sel           12
#define DFLT_VAL_NX90_dpm_if_cfg_aen_sel      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_aen_sel   0x00000000U
#define MSK_NX90_dpm_if_cfg_aen_pol           0x00004000U
#define SRT_NX90_dpm_if_cfg_aen_pol           14
#define DFLT_VAL_NX90_dpm_if_cfg_aen_pol      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_aen_pol   0x00000000U
#define MSK_NX90_dpm_if_cfg_addr_sh           0x00008000U
#define SRT_NX90_dpm_if_cfg_addr_sh           15
#define DFLT_VAL_NX90_dpm_if_cfg_addr_sh      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_addr_sh   0x00000000U
#define MSK_NX90_dpm_if_cfg_cs_ctrl           0x00070000U
#define SRT_NX90_dpm_if_cfg_cs_ctrl           16
#define DFLT_VAL_NX90_dpm_if_cfg_cs_ctrl      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_if_cfg_cs_ctrl   0x00000000U

/* all used bits of 'NX90_dpm_if_cfg': */
#define MSK_USED_BITS_NX90_dpm_if_cfg 0x0007f3d3U

enum {
  BFW_NX90_dpm_if_cfg_dir_ctrl  = 2,  /* [1:0] */
  BFW_NX90_dpm_if_cfg_reserved1 = 2,  /* [3:2] */
  BFW_NX90_dpm_if_cfg_be_sel    = 1,  /* [4] */
  BFW_NX90_dpm_if_cfg_reserved2 = 1,  /* [5] */
  BFW_NX90_dpm_if_cfg_be_rd_dis = 1,  /* [6] */
  BFW_NX90_dpm_if_cfg_be_wr_dis = 1,  /* [7] */
  BFW_NX90_dpm_if_cfg_be_pol    = 2,  /* [9:8] */
  BFW_NX90_dpm_if_cfg_reserved3 = 2,  /* [11:10] */
  BFW_NX90_dpm_if_cfg_aen_sel   = 2,  /* [13:12] */
  BFW_NX90_dpm_if_cfg_aen_pol   = 1,  /* [14] */
  BFW_NX90_dpm_if_cfg_addr_sh   = 1,  /* [15] */
  BFW_NX90_dpm_if_cfg_cs_ctrl   = 3,  /* [18:16] */
  BFW_NX90_dpm_if_cfg_reserved4 = 13  /* [31:19] */
};

typedef struct NX90_DPM_IF_CFG_BIT_Ttag {
  unsigned int dir_ctrl  : BFW_NX90_dpm_if_cfg_dir_ctrl;  /* DPM access direction control.                                                                                      */
                                                          /*  00: dedicated low active read- and write control signals (RDn + WRn) with optional byte-enables.                  */
                                                          /*      byte-enables have address character i.e. they must be stable while read- or write-control                     */
                                                          /*      signal is active. byte-enables are not used as Strobe signals.                                                */
                                                          /*      A read-access is started when RDn signal becomes active low at access start. Address, chip-select and         */
                                                          /*      byte-enable signals must be stable then.                                                                      */
                                                          /*      A write-access is done when WRn becomes inactive high at access end. Address, chip-select, data and           */
                                                          /*      byte-enable signals must be stable then.                                                                      */
                                                          /*      Ready/Busy signal is asserted when RDn or WRn is active.                                                      */
                                                          /*      This setting can be used for standard SRAM interfaces.                                                        */
                                                          /*  01: RDn is direction signal nRW (signal high: write, low: read).                                                  */
                                                          /*      For read byte-enables have address character i.e. they must be stable when RDn becomes low.                   */
                                                          /*      For write byte-enables have strobe character i.e. Address, Data and RDn must be stable when they              */
                                                          /*      become inactive at access end..                                                                               */
                                                          /*      A read-access is started when RDn signal becomes low at access start. Address, chip-select and                */
                                                          /*      byte-enable signals must be stable then.                                                                      */
                                                          /*      A write-access is done when byte-enables becomes inactive at access end. Address, chip-select, data and       */
                                                          /*      RDn signals must be stable then.                                                                              */
                                                          /*      Ready/Busy signal is asserted when RDn is low or byte-enables are active.                                     */
                                                          /*      This setting is typically used for Intel-like interfaces with Byte-Write-Strobe signals..                     */
                                                          /*  10: RDn is direction signal nWR (signal low: write, high: read).                                                  */
                                                          /*      byte-enables have strobe character for both read and write i.e. Address, and RDn must be stable when they     */
                                                          /*      become active at access start. These signals must remain stable until byte-enables become inactive            */
                                                          /*      at access end. For write data must be stable then.                                                            */
                                                          /*      Ready/Busy signal is asserted when at least one byte-enables is active.                                       */
                                                          /*      This setting is typically used for Motorola-like interfaces with Byte-Write-Strobe signals.                   */
  unsigned int reserved1 : BFW_NX90_dpm_if_cfg_reserved1; /* reserved                                                                                                           */
  unsigned int be_sel    : BFW_NX90_dpm_if_cfg_be_sel;    /* DPM access byte-enable signal selection.                                                                           */
                                                          /* Basically BE signals depend on selected data width (cfg0x0).                                                       */
                                                          /* {        |            |         |                                                                                  */
                                                          /*  setting   data width   D[15:8]   D[7:0]                                                                           */
                                                          /*        0     8bit                      -                                                                           */
                                                          /*        0    16bit         BHE1n       A0                                                                           */
                                                          /*  ----------------------------------------                                                                          */
                                                          /*        1     8bit                  BHE1n                                                                           */
                                                          /*        1    16bit         A17      WRn}                                                                            */
                                                          /* Note:                                                                                                              */
                                                          /*    For 8 bit data modes this bit must only be set when an additional                                               */
                                                          /*    byte-enable Signal is required (e.g. Motorola 6800). Do not set 'be_sel' and ignore                             */
                                                          /*    for read and write (be_wr_dis, be_rd_dis) - DPM Ready generation will care                                      */
                                                          /*    for BHE1n anyhow.                                                                                               */
                                                          /* Note:                                                                                                              */
                                                          /*    Internal read access data width is always 32 bit.                                                               */
  unsigned int reserved2 : BFW_NX90_dpm_if_cfg_reserved2; /* reserved                                                                                                           */
  unsigned int be_rd_dis : BFW_NX90_dpm_if_cfg_be_rd_dis; /* DPM read access byte-enable configuration.                                                                         */
                                                          /*   0: byte-enables will be used on read access, only data lines of enabled bytes will be driven.                    */
                                                          /*   1: byte-enables will be ignored on read access, all used data lines will be driven.                              */
                                                          /* Note:                                                                                                              */
                                                          /*    Do not set this bit when 'dir_ctrl' is set to nRW-mode ('10'). Byte-Write-Strobes are essentially in this case. */
                                                          /* Note:                                                                                                              */
                                                          /*    This bit is ignored for 8 bit data modes when 'be_sel' bit is not set.                                          */
  unsigned int be_wr_dis : BFW_NX90_dpm_if_cfg_be_wr_dis; /* DPM write access byte-enable configuration.                                                                        */
                                                          /*   0: byte-enables will be used on write access, only data lines of enabled bytes will be written.                  */
                                                          /*   1: byte-enables will be ignored on write access, all used data lines will be written.                            */
                                                          /* Note:                                                                                                              */
                                                          /*    Do not set this bit when 'dir_ctrl' is set to nWR-mode ('01'). Byte-Write-Strobes are essentially in this case. */
                                                          /* Note:                                                                                                              */
                                                          /*    This bit is ignored for 8 bit data modes when 'be_sel' bit is not set.                                          */
  unsigned int be_pol    : BFW_NX90_dpm_if_cfg_be_pol;    /* DPM access byte-enable active level polarity.                                                                      */
                                                          /* byte-enable active polarity can be set for each data byte separately. byte-enable signals                          */
                                                          /* can be selected by 'be_sel'.                                                                                       */
                                                          /* Bits inside this bit field are associated as follows:                                                              */
                                                          /* {            |                                                                                                     */
                                                          /*   Bit         data lines                                                                                           */
                                                          /*   be_pol[0]       D[7:0]                                                                                           */
                                                          /*   be_pol[1]      D[15:8]}                                                                                          */
                                                          /* Function:                                                                                                          */
                                                          /*   0: BE signals are low active byte-enables.                                                                       */
                                                          /*   1: BE signals are high active byte-enables (e.g. 8 bit Motorola 6800).                                           */
  unsigned int reserved3 : BFW_NX90_dpm_if_cfg_reserved3; /* reserved                                                                                                           */
  unsigned int aen_sel   : BFW_NX90_dpm_if_cfg_aen_sel;   /* Address-Enable (AEN-modes) or Address-Latch-Enable (multiplexed modes) Control.                                    */
                                                          /*  00: No additional Address controlling function.                                                                   */
                                                          /*  01: reserved                                                                                                      */
                                                          /*  10: AEN on HIF_A16 (up to 64kB address space for non-multiplexed modes).                                          */
                                                          /*  11: reserved.                                                                                                     */
                                                          /* Note:                                                                                                              */
                                                          /*    In multiplexed modes read or write access will not be started netX internally while address-phase               */
                                                          /*    is active. ALE signal must return to idle state first.                                                          */
  unsigned int aen_pol   : BFW_NX90_dpm_if_cfg_aen_pol;   /* Address-Enable active level polarity.                                                                              */
                                                          /*   0: Address is latched while ALE-signal is low (i.e. low active ALE/AEN).                                         */
                                                          /*   1: Address is latched while ALE-signal is high (i.e. high active ALE/AEN).                                       */
                                                          /* In non-multiplexed modes, address is only latched when chip-select is additionally active (as programmed           */
                                                          /* in 'cs_ctrl').                                                                                                     */
                                                          /* In multiplexed modes, address latching is not controlled by chip-select. Address is latched all time               */
                                                          /* when ALE is active then.                                                                                           */
  unsigned int addr_sh   : BFW_NX90_dpm_if_cfg_addr_sh;   /* Address is Byte address or shifted according to selected data size.                                                */
                                                          /* This bit is irrelevant in 8 bit data modes. Address comparator logic works always with unshifted                   */
                                                          /* address.                                                                                                           */
                                                          /* {  |                                                                                                               */
                                                          /*   0 Address is always Byte address (not shifted).                                                                  */
                                                          /*     In 16 bit data modes: Address bit 0 can be used as low byte-enable or can be ignored.                          */
                                                          /*     Use 'be_sel' to select byte-enables and 'be_wr_dis' or 'be_rd_dis' to ignore them.                             */
                                                          /*   1 Address is shifted according to programmed data width.                                                         */
                                                          /*     In 16 bit data modes: Address from host starting at A0 (or AD0 when multiplexed ) is 16 bit word address.}     */
  unsigned int cs_ctrl   : BFW_NX90_dpm_if_cfg_cs_ctrl;   /* Chip-select controlling.                                                                                           */
                                                          /*  000:     Use 1 low active chip-select signal (DPM_CSN).                                                           */
                                                          /*  001:     Use 2 low active chip-select signals (DPM_CSN or DPM_BHE1n must be low).                                 */
                                                          /*  010:     Use high active chip-select signal (DPM_CSN).                                                            */
                                                          /*  011:     Use 2 high active chip-select signals (DPM_CSN or DPM_BHE1n must be high).                               */
                                                          /*  100:     No chip-select signal. Behaves like DPM_CSN is permanent active.                                         */
                                                          /*  111:     Chip access is disabled.                                                                                 */
                                                          /*  others:  reserved                                                                                                 */
                                                          /* Note:                                                                                                              */
                                                          /*   The address comparators and the 'addr_cmp_a*' bit fields in 'dpm_addr_cfg' of earlier netX versions              */
                                                          /*   were dropped since netX90.                                                                                       */
  unsigned int reserved4 : BFW_NX90_dpm_if_cfg_reserved4; /* reserved                                                                                                           */
} NX90_DPM_IF_CFG_BIT_T;

typedef union {
  uint32_t              val;
  NX90_DPM_IF_CFG_BIT_T bf;
} NX90_DPM_IF_CFG_T;

/* --------------------------------------------------------------------- */
/* Register dpm_pio_cfg0 */
/* => DPM PIO Configuration Register0. */
/*    Signals to be used as PIOs when netX DPM is active must be selected here or in 'dpm_pio_cfg1' register. Since netx51/52 */
/*    PIO function will not be automatically activated depending on other settings. E.g. DPM_D15..8 can not be used */
/*    automatically when 8 bit data mode is selected. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_pio_cfg0      0x00000008U
#define Adr_NX90_dpm0_com_dpm_pio_cfg0 0xFF001908U
#define Adr_NX90_dpm1_com_dpm_pio_cfg0 0xFF001A08U
#define DFLT_VAL_NX90_dpm_pio_cfg0     0x00000000U

#define MSK_NX90_dpm_pio_cfg0_sel_d_pio         0x0000ffffU
#define SRT_NX90_dpm_pio_cfg0_sel_d_pio         0
#define DFLT_VAL_NX90_dpm_pio_cfg0_sel_d_pio    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg0_sel_d_pio 0x00000000U

/* all used bits of 'NX90_dpm_pio_cfg0': */
#define MSK_USED_BITS_NX90_dpm_pio_cfg0 0x0000ffffU

enum {
  BFW_NX90_dpm_pio_cfg0_sel_d_pio = 16, /* [15:0] */
  BFW_NX90_dpm_pio_cfg0_reserved1 = 16  /* [31:16] */
};

typedef struct NX90_DPM_PIO_CFG0_BIT_Ttag {
  unsigned int sel_d_pio : BFW_NX90_dpm_pio_cfg0_sel_d_pio; /* Use related DPM_D-pin as PIO pin. */
  unsigned int reserved1 : BFW_NX90_dpm_pio_cfg0_reserved1; /* reserved                          */
} NX90_DPM_PIO_CFG0_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_PIO_CFG0_BIT_T bf;
} NX90_DPM_PIO_CFG0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_pio_cfg1 */
/* => DPM PIO Configuration Register1. */
/*    PIO usage of DPM_SIRQ, DPM_DIRQ and DPM_RDY has moved from 'dpm_io_cfg_misc' to this register since netx51/52. */
/*    Signals to be used as PIOs when netX DPM is active must be selected here or in 'dpm_pio_cfg0' register. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_pio_cfg1      0x0000000CU
#define Adr_NX90_dpm0_com_dpm_pio_cfg1 0xFF00190CU
#define Adr_NX90_dpm1_com_dpm_pio_cfg1 0xFF001A0CU
#define DFLT_VAL_NX90_dpm_pio_cfg1     0xe0000000U

#define MSK_NX90_dpm_pio_cfg1_sel_a_pio            0x000fffffU
#define SRT_NX90_dpm_pio_cfg1_sel_a_pio            0
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_a_pio       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_a_pio    0x00000000U
#define MSK_NX90_dpm_pio_cfg1_sel_bhe1_pio         0x01000000U
#define SRT_NX90_dpm_pio_cfg1_sel_bhe1_pio         24
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_bhe1_pio    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_bhe1_pio 0x00000000U
#define MSK_NX90_dpm_pio_cfg1_sel_csn_pio          0x04000000U
#define SRT_NX90_dpm_pio_cfg1_sel_csn_pio          26
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_csn_pio     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_csn_pio  0x00000000U
#define MSK_NX90_dpm_pio_cfg1_sel_rdn_pio          0x08000000U
#define SRT_NX90_dpm_pio_cfg1_sel_rdn_pio          27
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_rdn_pio     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_rdn_pio  0x00000000U
#define MSK_NX90_dpm_pio_cfg1_sel_wrn_pio          0x10000000U
#define SRT_NX90_dpm_pio_cfg1_sel_wrn_pio          28
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_wrn_pio     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_wrn_pio  0x00000000U
#define MSK_NX90_dpm_pio_cfg1_sel_rdy_pio          0x20000000U
#define SRT_NX90_dpm_pio_cfg1_sel_rdy_pio          29
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_rdy_pio     0x20000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_rdy_pio  0x00000001U
#define MSK_NX90_dpm_pio_cfg1_sel_dirq_pio         0x40000000U
#define SRT_NX90_dpm_pio_cfg1_sel_dirq_pio         30
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_dirq_pio    0x40000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_dirq_pio 0x00000001U
#define MSK_NX90_dpm_pio_cfg1_sel_sirq_pio         0x80000000U
#define SRT_NX90_dpm_pio_cfg1_sel_sirq_pio         31
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_sirq_pio    0x80000000U
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_sirq_pio 0x00000001U

/* all used bits of 'NX90_dpm_pio_cfg1': */
#define MSK_USED_BITS_NX90_dpm_pio_cfg1 0xfd0fffffU

enum {
  BFW_NX90_dpm_pio_cfg1_sel_a_pio    = 20, /* [19:0] */
  BFW_NX90_dpm_pio_cfg1_reserved1    = 4,  /* [23:20] */
  BFW_NX90_dpm_pio_cfg1_sel_bhe1_pio = 1,  /* [24] */
  BFW_NX90_dpm_pio_cfg1_reserved2    = 1,  /* [25] */
  BFW_NX90_dpm_pio_cfg1_sel_csn_pio  = 1,  /* [26] */
  BFW_NX90_dpm_pio_cfg1_sel_rdn_pio  = 1,  /* [27] */
  BFW_NX90_dpm_pio_cfg1_sel_wrn_pio  = 1,  /* [28] */
  BFW_NX90_dpm_pio_cfg1_sel_rdy_pio  = 1,  /* [29] */
  BFW_NX90_dpm_pio_cfg1_sel_dirq_pio = 1,  /* [30] */
  BFW_NX90_dpm_pio_cfg1_sel_sirq_pio = 1   /* [31] */
};

typedef struct NX90_DPM_PIO_CFG1_BIT_Ttag {
  unsigned int sel_a_pio    : BFW_NX90_dpm_pio_cfg1_sel_a_pio;    /* Use related DPM_A-pin as PIO pin.                                                            */
                                                                  /* Note:                                                                                        */
                                                                  /*    PIO selects for DPM_A19..18 are only used for test purpose here. To select PIO function   */
                                                                  /*    of high DPM_A lines which are multiplexed on DPM_D23..22 use related bits of 'sel_d_pio'  */
                                                                  /*    Bit field in 'dpm_pio_cfg0' register. DPM_A17..16 are treated in the same way in netx50   */
                                                                  /*    compatibility mode (located on DPM_D21..20 then). However they are located on HIF_AHI1..0 */
                                                                  /*    when netx50 compatibility is globally disabled (ASIC_CTRL-area).                          */
  unsigned int reserved1    : BFW_NX90_dpm_pio_cfg1_reserved1;    /* reserved                                                                                     */
  unsigned int sel_bhe1_pio : BFW_NX90_dpm_pio_cfg1_sel_bhe1_pio; /* Use DPM_BHE1-pin as PIO pin.                                                                 */
  unsigned int reserved2    : BFW_NX90_dpm_pio_cfg1_reserved2;    /* reserved                                                                                     */
  unsigned int sel_csn_pio  : BFW_NX90_dpm_pio_cfg1_sel_csn_pio;  /* Use DPM_CSN-pin as PIO pin.                                                                  */
  unsigned int sel_rdn_pio  : BFW_NX90_dpm_pio_cfg1_sel_rdn_pio;  /* Use DPM_RDN-pin as PIO pin.                                                                  */
  unsigned int sel_wrn_pio  : BFW_NX90_dpm_pio_cfg1_sel_wrn_pio;  /* Use DPM_WRN-pin as PIO pin.                                                                  */
  unsigned int sel_rdy_pio  : BFW_NX90_dpm_pio_cfg1_sel_rdy_pio;  /* Use DPM_RDY-pin as PIO pin. RDY is by default PIO to avoid RDY-conflicts during reset.       */
  unsigned int sel_dirq_pio : BFW_NX90_dpm_pio_cfg1_sel_dirq_pio; /* Use DPM_DIRQ-pin as PIO pin.                                                                 */
                                                                  /* Note:                                                                                        */
                                                                  /*    For serial DPM this bit is related to netX51/52 IO HIF_D12. Setting of for HIF_D12        */
                                                                  /*    inside 'dpm_pio_cfg0 register is ignored then. I.e. this bit must be programmed           */
                                                                  /*    to '0' for DPM_DIRQ/IRQ usage regardless whether serial or parallel DPM is used.          */
  unsigned int sel_sirq_pio : BFW_NX90_dpm_pio_cfg1_sel_sirq_pio; /* Use DPM_SIRQ-pin as PIO pin.                                                                 */
                                                                  /* Note:                                                                                        */
                                                                  /*    For serial DPM this bit is related to netX51/52 IO HIF_D13. Setting of for HIF_D13        */
                                                                  /*    inside 'dpm_pio_cfg0 register is ignored then. I.e. this bit must be programmed           */
                                                                  /*    to '0' for DPM_SIRQ/FIQ usage regardless whether serial or parallel DPM is used.          */
} NX90_DPM_PIO_CFG1_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_PIO_CFG1_BIT_T bf;
} NX90_DPM_PIO_CFG1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_addr_cfg */
/* => DPM External Address Configuration Register. */
/*    Note: */
/*       There are no internal address comparators and no DPM_SELA* functions available for netX90. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_addr_cfg      0x00000010U
#define Adr_NX90_dpm0_com_dpm_addr_cfg 0xFF001910U
#define Adr_NX90_dpm1_com_dpm_addr_cfg 0xFF001A10U
#define DFLT_VAL_NX90_dpm_addr_cfg     0x00000002U

#define MSK_NX90_dpm_addr_cfg_addr_range               0x0000000fU
#define SRT_NX90_dpm_addr_cfg_addr_range               0
#define DFLT_VAL_NX90_dpm_addr_cfg_addr_range          0x00000002U
#define DFLT_BF_VAL_NX90_dpm_addr_cfg_addr_range       0x00000002U
#define MSK_NX90_dpm_addr_cfg_cfg_win_addr_cfg         0x00000030U
#define SRT_NX90_dpm_addr_cfg_cfg_win_addr_cfg         4
#define DFLT_VAL_NX90_dpm_addr_cfg_cfg_win_addr_cfg    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_addr_cfg_cfg_win_addr_cfg 0x00000000U

/* all used bits of 'NX90_dpm_addr_cfg': */
#define MSK_USED_BITS_NX90_dpm_addr_cfg 0x0000003fU

enum {
  BFW_NX90_dpm_addr_cfg_addr_range       = 4,  /* [3:0] */
  BFW_NX90_dpm_addr_cfg_cfg_win_addr_cfg = 2,  /* [5:4] */
  BFW_NX90_dpm_addr_cfg_reserved1        = 26  /* [31:6] */
};

typedef struct NX90_DPM_ADDR_CFG_BIT_Ttag {
  unsigned int addr_range       : BFW_NX90_dpm_addr_cfg_addr_range;       /* DPM external address range.                                                                                         */
                                                                          /* {        |                                  |                                                                       */
                                                                          /*  coding   Byte Address range                 address used signals                                                   */
                                                                          /*   0000    reserved                                                                                                  */
                                                                          /*   0001    reserved                                                                                                  */
                                                                          /*   0010    2KB address range                  DPM_A[10:0]                                                            */
                                                                          /*   0011    4KB address range                  DPM_A[11:0]                                                            */
                                                                          /*   0100    8KB address range                  DPM_A[12:0]                                                            */
                                                                          /*   0101    16KB address range                 DPM_A[13:0]                                                            */
                                                                          /*   0110    32KB address range                 DPM_A[14:0]                                                            */
                                                                          /*   0111    64KB address range                 DPM_A[15:0]                                                            */
                                                                          /*   1000    128KB address range                DPM_A[16:0]                                                            */
                                                                          /*   1001    256KB address range                DPM_A[17:0]                                                            */
                                                                          /*    :      reserved                                                                                                  */
                                                                          /*   1111    reserved }                                                                                                */
                                                                          /*                                                                                                                     */
                                                                          /* Following settings are only valid for 8 bit non-multiplexed data mode.                                              */
                                                                          /* {        |                                  |                                                                       */
                                                                          /*  coding   Byte Address range                 address used signals                                                   */
                                                                          /*   1010    512KB address range                HIF_D8, DPM_A[17:0]                                                    */
                                                                          /*   1011    1024KB address range               HIF_D9, HIF_D8, DPM_A[17:0]                                            */
                                                                          /*    :      reserved                                                                                                  */
                                                                          /*   1111    reserved }                                                                                                */
                                                                          /*                                                                                                                     */
                                                                          /* This setting is related to Byte address. I.e. it is not possible to expand address rage                             */
                                                                          /* by setting the 'addr_sh' bit inside the 'dpm_if_cfg' register. However required address lines                       */
                                                                          /* will decrease by 1 for 16 bit data mode when the 'addr_sh' bit is set.                                              */
                                                                          /*                                                                                                                     */
                                                                          /* For multiplexed modes:                                                                                              */
                                                                          /* If programmed address range exceeds number of data lines, high address bits will be sampled                         */
                                                                          /* from DPM_A lines starting above last used data line. High address will be sampled at the same moment                */
                                                                          /* when low address bits are sampled from data lines.                                                                  */
                                                                          /* Example 1:                                                                                                          */
                                                                          /* 8 bit data multiplexed mode, 64KB address range programmed and 'aen_pol' is set to 0:                               */
                                                                          /* Address bits A7..0 are sampled from DPM_D7..0 before DPM_ALE is released to 1. Address bits A15..8                  */
                                                                          /* are sampled from DPM_A15..8 also before DPM_ALE is released to 1.                                                   */
                                                                          /* Example 2:                                                                                                          */
                                                                          /* 16 bit data multiplexed mode, 64KB address range programmed, 'aen_pol' is set                                       */
                                                                          /* to 0 and 'addr_sh' is set to 1:                                                                                     */
                                                                          /* Address bits A15..1 are sampled from DPM_D14..0 before DPM_ALE is released to 1.                                    */
                                                                          /* I.e. a 16 bit word address is                                                                                       */
                                                                          /* carried on DPM_D14..0 and is left-shifted internally by 1 to resolve a byte address.                                */
  unsigned int cfg_win_addr_cfg : BFW_NX90_dpm_addr_cfg_cfg_win_addr_cfg; /* Location of the DPM Configuration Window (Window 0).                                                                */
                                                                          /* Supported settings are:                                                                                             */
                                                                          /*  00: Low Configuration Window: The Configuration Window is located in the first 256 bytes of external DPM address   */
                                                                          /*      range (0x0 to 0xff). It is located before the first enabled Data Window (1 to 4).                              */
                                                                          /*  01: High Configuration Window: The Configuration Window is located in the last 256 bytes of external DPM address   */
                                                                          /*      range.                                                                                                         */
                                                                          /*      Example: 'addr_range' is 8kB: Configuration Window is located in 0x1F00..0x1FFF.                               */
                                                                          /*  10: reserved.                                                                                                      */
                                                                          /*  11: Configuration Window is disabled for external DPM access. Full DPM address                                     */
                                                                          /*      range can be used for Windows 1 to 4.                                                                          */
                                                                          /* Note:                                                                                                               */
                                                                          /*   The Configuration Window 0 has higher priority than normal DPM Window. The location of the Configuration Window   */
                                                                          /*   does not depend on the Data Window configuration (the setting of the 'dpm_winX_end' or 'dpm_winX_map' registers). */
                                                                          /*   I.e. for setting '00' (low Configuration Window) the first enabled Data Window starts at address 0x100. For       */
                                                                          /*   setting '01' (high Configuration Window) it would hide the last 256 bytes of the last enabled Data Window when    */
                                                                          /*   this is configured to end on the last external address.                                                           */
                                                                          /*   The Configuration Window 0 has lower priority than Access Tunnel. I.e. the Access Tunnel could be laid over       */
                                                                          /*   the configuration window.                                                                                         */
  unsigned int reserved1        : BFW_NX90_dpm_addr_cfg_reserved1;        /* reserved                                                                                                            */
} NX90_DPM_ADDR_CFG_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_ADDR_CFG_BIT_T bf;
} NX90_DPM_ADDR_CFG_T;

/* --------------------------------------------------------------------- */
/* Register dpm_timing_cfg */
/* => DPM timing and access configuration register. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_timing_cfg      0x00000014U
#define Adr_NX90_dpm0_com_dpm_timing_cfg 0xFF001914U
#define Adr_NX90_dpm1_com_dpm_timing_cfg 0xFF001A14U
#define DFLT_VAL_NX90_dpm_timing_cfg     0x00000027U

#define MSK_NX90_dpm_timing_cfg_t_osa                     0x00000003U
#define SRT_NX90_dpm_timing_cfg_t_osa                     0
#define DFLT_VAL_NX90_dpm_timing_cfg_t_osa                0x00000003U
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_t_osa             0x00000003U
#define MSK_NX90_dpm_timing_cfg_filter                    0x00000004U
#define SRT_NX90_dpm_timing_cfg_filter                    2
#define DFLT_VAL_NX90_dpm_timing_cfg_filter               0x00000004U
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_filter            0x00000001U
#define MSK_NX90_dpm_timing_cfg_t_rds                     0x00000070U
#define SRT_NX90_dpm_timing_cfg_t_rds                     4
#define DFLT_VAL_NX90_dpm_timing_cfg_t_rds                0x00000020U
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_t_rds             0x00000002U
#define MSK_NX90_dpm_timing_cfg_rd_burst_en               0x00000080U
#define SRT_NX90_dpm_timing_cfg_rd_burst_en               7
#define DFLT_VAL_NX90_dpm_timing_cfg_rd_burst_en          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_rd_burst_en       0x00000000U
#define MSK_NX90_dpm_timing_cfg_en_dpm_serial_sqi         0x40000000U
#define SRT_NX90_dpm_timing_cfg_en_dpm_serial_sqi         30
#define DFLT_VAL_NX90_dpm_timing_cfg_en_dpm_serial_sqi    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_en_dpm_serial_sqi 0x00000000U
#define MSK_NX90_dpm_timing_cfg_sdpm_miso_early           0x80000000U
#define SRT_NX90_dpm_timing_cfg_sdpm_miso_early           31
#define DFLT_VAL_NX90_dpm_timing_cfg_sdpm_miso_early      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_sdpm_miso_early   0x00000000U

/* all used bits of 'NX90_dpm_timing_cfg': */
#define MSK_USED_BITS_NX90_dpm_timing_cfg 0xc00000f7U

enum {
  BFW_NX90_dpm_timing_cfg_t_osa             = 2,  /* [1:0] */
  BFW_NX90_dpm_timing_cfg_filter            = 1,  /* [2] */
  BFW_NX90_dpm_timing_cfg_reserved1         = 1,  /* [3] */
  BFW_NX90_dpm_timing_cfg_t_rds             = 3,  /* [6:4] */
  BFW_NX90_dpm_timing_cfg_rd_burst_en       = 1,  /* [7] */
  BFW_NX90_dpm_timing_cfg_reserved2         = 22, /* [29:8] */
  BFW_NX90_dpm_timing_cfg_en_dpm_serial_sqi = 1,  /* [30] */
  BFW_NX90_dpm_timing_cfg_sdpm_miso_early   = 1   /* [31] */
};

typedef struct NX90_DPM_TIMING_CFG_BIT_Ttag {
  unsigned int t_osa             : BFW_NX90_dpm_timing_cfg_t_osa;             /* Address Setup Time (t_osa * 10ns).                                                                                                       */
                                                                              /* Address sampling can be delayed for read and write accesses by this parameter.                                                           */
                                                                              /* E.g. host device asserts chip-select, Read-Enable and address lines simultaneously but                                                   */
                                                                              /* some address lines are not stable while chip-select and Read-Enable are both low, set t_osa                                              */
                                                                              /* to delay address sampling by t_osa * 10ns.                                                                                               */
                                                                              /* When data direction is controlled by RDn line ('if_cfg.dir_ctrl' not '00') and byte-enables are used                                     */
                                                                              /* for read ('if_cfg.be_rd_dis' not set), a read access is initiated when active byte-enable signals                                        */
                                                                              /* are detected stable for t_osa netX clock periods.                                                                                        */
                                                                              /* Valid settings are: 0..3.                                                                                                                */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    Read data access time will increased by t_osa * 10ns if t_osa is not 0.                                                               */
  unsigned int filter            : BFW_NX90_dpm_timing_cfg_filter;            /* Filter DPM Control Signals.                                                                                                              */
                                                                              /* If this bit is set, DPM signals chip-select, Read-Enable and Write-Enable (and Address latch enable if multiplexed                       */
                                                                              /* Parallel DPM modes are used) are filtered for spike suppression.                                                                         */
                                                                              /*  0: no spike suppression.                                                                                                                */
                                                                              /*  1: Spikes < 10ns are suppressed, read data access time increased by 10ns.                                                               */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    Data, address and byte-enable inputs are not filtered and must be stable when sampled. I.e. during                                    */
                                                                              /*    the last 20ns of a write access and at the first 10ns of read access start.                                                           */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    Read data access time is increased by 10ns if this bit is set.                                                                        */
  unsigned int reserved1         : BFW_NX90_dpm_timing_cfg_reserved1;         /* reserved                                                                                                                                 */
  unsigned int t_rds             : BFW_NX90_dpm_timing_cfg_t_rds;             /* Read data setup time (in steps of 10ns).                                                                                                 */
                                                                              /* For parallel DPM:                                                                                                                        */
                                                                              /* If DPM_RDY-signal is used (rdy_mode != 0), ready-state is generated t_rds*10ns after read data is stored on data bus.                    */
                                                                              /* Without using the DPM_RDY-signal (rdy_mode == 0) read access error is detected if access terminates before t_rds*10ns                    */
                                                                              /* passed after read data generation.                                                                                                       */
                                                                              /* Valid settings for parallel DPM are: 0..7.                                                                                               */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    The read-data-access-time will increased by t_rds * 10ns if t_rds is not 0.                                                           */
                                                                              /* For serial DPM (since final netX90):                                                                                                     */
                                                                              /* t_rds defines the guaranteed setup time of the first bit of serial read data before its sampling clock edge (MISO                        */
                                                                              /* before sampling edge of SCK). By default (t_rds=2) the first bit of serial read data may become valid on MISO                            */
                                                                              /* shortly befor the sampling edge of SCK (t_SPMOS, typically some nanoseconds, refer to the detailed IO-timing                             */
                                                                              /* description of the serial DPM). If the serial read data becomes valid later, a rd_err is detected (register dpm_status).                 */
                                                                              /* Typically t_SPMOS is sufficient. However, for serial masters requiring a longer  setup time, t_rds can be used to                        */
                                                                              /* shift the access-error-detection to an earlier point of time in steps of 10ns: The rd_err-state will be detected if the serial-read-data */
                                                                              /* is not generated at least t_SPMOS + (t_rds-2)*10ns before the sampling clock edge. Hence t_rds does not really provide                   */
                                                                              /* a longer setup time but it allows to detect accesses with too short setup-times and provides the possibility                             */
                                                                              /* to repeat them (similar to parallel DPM without DPM_RDY-signal).                                                                         */
                                                                              /* Valid settings for serial DPM are: 2..7. The recommended value is 2.                                                                     */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    It makes no sense to set t_rds in a way that leads to a setup-time larger than the half serial period. The serial                     */
                                                                              /*    clock rate must be reduced then additionally.                                                                                         */
  unsigned int rd_burst_en       : BFW_NX90_dpm_timing_cfg_rd_burst_en;       /* Read burst enable.                                                                                                                       */
                                                                              /* Read bursts are subsequent read accesses without toggling chip-select or read-enable in between.                                         */
                                                                              /* They are supported for non-multiplexed modes only.                                                                                       */
  unsigned int reserved2         : BFW_NX90_dpm_timing_cfg_reserved2;         /* reserved                                                                                                                                 */
  unsigned int en_dpm_serial_sqi : BFW_NX90_dpm_timing_cfg_en_dpm_serial_sqi; /* When DPM is in serial mode ('dpm_status.sel_dpm_serial' active), serial DPM                                                              */
                                                                              /* can be switched to SQI-compatible 4-bit mode.                                                                                            */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    Netx DPM changes serial configuration immediately when this bit is changed. Hence                                                     */
                                                                              /*    do not change this bit by a longer serial sequence from host.                                                                         */
                                                                              /*    E.g.: Change from SPI to SQI from host-side when host:                                                                                */
                                                                              /*    1.: Set this bit by SPI write sequence from host.                                                                                     */
                                                                              /*    2.: Terminate sequence after the byte containing this bit was written.                                                                */
                                                                              /*    3.: Ensure that host has completed writing this byte serially (host transfer could last                                               */
                                                                              /*        even when related commands are already finished, e.g. due to FIFOs inside host SPI module).                                       */
                                                                              /*    4.: Change host to SQI.                                                                                                               */
                                                                              /*    5.: Continue accessing netX DPM in SQI mode.                                                                                          */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    This bit has no effect when DPM is in parallel mode.                                                                                  */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    This is a new netx51/52 feature.                                                                                                      */
  unsigned int sdpm_miso_early   : BFW_NX90_dpm_timing_cfg_sdpm_miso_early;   /* Serial DPM early MISO (read-data) generation.                                                                                            */
                                                                              /* Serial DPM based on standard SPI changes read data on the edge following the sampling clock edge, i.e.                                   */
                                                                              /* works on both serial clock edges. That avoids hold timing errors on MISO-data but decreases                                              */
                                                                              /* maximum serial data rate on the other hand. Hence, for fast serial data rates this bit must be set.                                      */
                                                                              /* MISO hold times will always be positive but could get very short then. For details view netX                                             */
                                                                              /* timing characteristics.                                                                                                                  */
                                                                              /*  0: Change MISO on the clock edge following the sampling edge.                                                                           */
                                                                              /*  1: Change MISO on the sampling edge.                                                                                                    */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    Sampling and generating clock edges are determined by serial DPM mode (clock phase and polarity).                                     */
                                                                              /*    Related configuration must be done outside DPM module.                                                                                */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    Hold timings can be relaxed by decreasing serial clock rate when this bit is not set. When this                                       */
                                                                              /*    bit is set, MISO hold timing does not depend on serial clock rate.                                                                    */
                                                                              /* Note:                                                                                                                                    */
                                                                              /*    This is a new netx51/52 feature.                                                                                                      */
} NX90_DPM_TIMING_CFG_BIT_T;

typedef union {
  uint32_t                  val;
  NX90_DPM_TIMING_CFG_BIT_T bf;
} NX90_DPM_TIMING_CFG_T;

/* --------------------------------------------------------------------- */
/* Register dpm_rdy_cfg */
/* => DPM Ready (DPM_RDY) Signal Configuration Register. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_rdy_cfg      0x00000018U
#define Adr_NX90_dpm0_com_dpm_rdy_cfg 0xFF001918U
#define Adr_NX90_dpm1_com_dpm_rdy_cfg 0xFF001A18U
#define DFLT_VAL_NX90_dpm_rdy_cfg     0x00000001U

#define MSK_NX90_dpm_rdy_cfg_rdy_pol              0x00000001U
#define SRT_NX90_dpm_rdy_cfg_rdy_pol              0
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_pol         0x00000001U
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_pol      0x00000001U
#define MSK_NX90_dpm_rdy_cfg_rdy_drv_mode         0x00000006U
#define SRT_NX90_dpm_rdy_cfg_rdy_drv_mode         1
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_drv_mode    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_drv_mode 0x00000000U
#define MSK_NX90_dpm_rdy_cfg_rdy_sig_mode         0x00000008U
#define SRT_NX90_dpm_rdy_cfg_rdy_sig_mode         3
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_sig_mode    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_sig_mode 0x00000000U
#define MSK_NX90_dpm_rdy_cfg_rdy_to_cfg           0x00000030U
#define SRT_NX90_dpm_rdy_cfg_rdy_to_cfg           4
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_to_cfg      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_to_cfg   0x00000000U

/* all used bits of 'NX90_dpm_rdy_cfg': */
#define MSK_USED_BITS_NX90_dpm_rdy_cfg 0x0000003fU

enum {
  BFW_NX90_dpm_rdy_cfg_rdy_pol      = 1,  /* [0] */
  BFW_NX90_dpm_rdy_cfg_rdy_drv_mode = 2,  /* [2:1] */
  BFW_NX90_dpm_rdy_cfg_rdy_sig_mode = 1,  /* [3] */
  BFW_NX90_dpm_rdy_cfg_rdy_to_cfg   = 2,  /* [5:4] */
  BFW_NX90_dpm_rdy_cfg_reserved1    = 26  /* [31:6] */
};

typedef struct NX90_DPM_RDY_CFG_BIT_Ttag {
  unsigned int rdy_pol      : BFW_NX90_dpm_rdy_cfg_rdy_pol;      /* Ready signal ready-state polarity.                                                                                            */
                                                                 /* 1: DPM is ready when external RDY-signal is high.                                                                             */
                                                                 /* 0: DPM is busy when external RDY-signal is high.                                                                              */
  unsigned int rdy_drv_mode : BFW_NX90_dpm_rdy_cfg_rdy_drv_mode; /* Ready generation mode.                                                                                                        */
                                                                 /* 00: ready signal generation is disabled (High-Impedance mode).                                                                */
                                                                 /* 01: ready is driven when active and inactive. Never highZ. (Push-Pull mode)                                                   */
                                                                 /* 10: ready is driven when active and for a short time when inactive-phase starts for fast                                      */
                                                                 /*     busy to ready signal state change (Sustain-Tristate mode).                                                                */
                                                                 /*     Inactive-phase ready driving time (tRPm02, tRPm12) depends on rdy_sig_mode:                                               */
                                                                 /*     For rdy_sig_mode=0 this time (tRPm02) is 10ns.                                                                            */
                                                                 /*     For rdy_sig_mode=1 this time (tRPm12) depends on programmed input signal                                                  */
                                                                 /*     filtering (register dpm_timing_cfg bit filter): If filtering is disabled tRPm12 is 20ns to 30ns,                          */
                                                                 /*     if input filtering is enabled,  tRPm12 is 30ns to 40ns.                                                                   */
                                                                 /* 11: ready is only driven when cycle active (Open-Drain/Open-Source mode).                                                     */
                                                                 /* Note:                                                                                                                         */
                                                                 /*       Mode 2 and 3 are reordered in comparison to netX100/500/50.                                                             */
  unsigned int rdy_sig_mode : BFW_NX90_dpm_rdy_cfg_rdy_sig_mode; /* Ready signal mode.                                                                                                            */
                                                                 /* 1: DPM_RDY is generated as ready/acknowledge pulse.                                                                           */
                                                                 /*    In this mode, DPM_RDY is only in active state at access end to sign that host device is allowed to finish the              */
                                                                 /*    current access. If no access to DPM is done or if host device runs DPM access but is not allowed to finish it yet,         */
                                                                 /*    DPM_RDY will remain in inactive state.                                                                                     */
                                                                 /* 0: DPM_RDY is generated as wait/busy state signal.                                                                            */
                                                                 /*    In this mode, DPM_RDY becomes active at access start and will remain active while host device is not allowed to finish the */
                                                                 /*    current access. If no access to DPM is done or if host device runs DPM access and allowed to finish it and continue        */
                                                                 /*    access generation, DPM_RDY will be in inactive state.                                                                      */
  unsigned int rdy_to_cfg   : BFW_NX90_dpm_rdy_cfg_rdy_to_cfg;   /* Ready Timeout Configuration.                                                                                                  */
                                                                 /* Ready Timeout detection can controlled this bit. For further information                                                      */
                                                                 /* see description of rdy_to_err bit of dpm_status register.                                                                     */
                                                                 /* 00: Ready Timeout after 2048 netX system clock cycles (i.e. 20.48us, not netx50 compatible)                                   */
                                                                 /* 01: Ready Timeout after 256 netX system clock cycles (i.e. 2.56us, netx50 compatible)                                         */
                                                                 /* 10: reserved                                                                                                                  */
                                                                 /* 11: Ready Timeout disabled.                                                                                                   */
                                                                 /* The value programmed here is ignored for serial DPM with stream-type 'ready-polling'. In this mode                            */
                                                                 /* no ready-timeout will be generated to avoid additional status checking. A ready-polling timeout                               */
                                                                 /* counter should be implemented in serial DPM host application.                                                                 */
                                                                 /* Note:                                                                                                                         */
                                                                 /*    This is a new netx51/52 feature.                                                                                           */
  unsigned int reserved1    : BFW_NX90_dpm_rdy_cfg_reserved1;    /* reserved                                                                                                                      */
} NX90_DPM_RDY_CFG_BIT_T;

typedef union {
  uint32_t               val;
  NX90_DPM_RDY_CFG_BIT_T bf;
} NX90_DPM_RDY_CFG_T;

/* --------------------------------------------------------------------- */
/* Register dpm_status */
/* => DPM Status Register. */
/*    DPM access errors can generate IRQ for host device (view DPM IRQ registers further down). For */
/*    error handling, the address an error occurred with is logged in dpm_status_err_addr register. Error bits can be cleared by */
/*    access to dpm_status_err_reset register. */
/*    {    | */
/*    Note  for 'bus_conflict_rd_addr_err', 'bus_conflict_rd_err' and 'bus_conflict_wr_err': */
/*          Bus-conflict error detection is basically implemented as debug feature. Detected errors could be result of hazardous \ */
/*          signals, incorrect configured DPM mode or not supported host interfaces. However there could some be some applications \ */
/*          where error detection is too strict (see description of 'dis_bus_conflict_err_detect' of 'dpm_misc_cfg'). For that reason \ */
/*          bus-conflict error behaviour can be controlled by 'dis_bus_conflict_err_detect' of 'dpm_misc_cfg' \ */
/*          register. However, status bits inside this register (and inside 'dpm_status_err_reset') will always be set when an \ */
/*          error was detected. */
/*          When error detection is enabled ('dis_bus_conflict_err_detect' is not set), an error-access will be aborted (ready-signal will \ */
/*          be set to ready state when used) and DPM will wait for idle bus (dir_mode==0: deselected or read and write control signal \ */
/*          inactive, dir_mode!=0: deselected or all byte-enables inactive). The error IRQ ('dpm_err') will be asserted. Read data \ */
/*          of related access will be invalid and write data will be junked. */
/*          When error detection is disabled ('dis_bus_conflict_err_detect' is set) bus-conflict errors do not assert the 'dpm_err' \ */
/*          IRQ, erroneous access will not be aborted and DPM will not wait for bus idle state. I.e. the erroneous access will be \ */
/*          finished as read or write. However consequences of an error access are not predictable: Read or write data or address \ */
/*          could be invalid. */
/*          Error detection is disabled by default after power on and must be enabled before usage. */
/*    Note  for 'rdy_to_err', 'wr_err' and 'rd_err': */
/*          These errors are basically set when an host access is too fast to be handled by netX internally. NetX internal access \ */
/*          times depend on target address area. However there are some address areas where other netX modules have higher access \ */
/*          priority than DPM (especially local memories of netX internal CPUs like xPEC or xPIC). Fore these address areas \ */
/*          access times could become unpredictable (depending on application running netX inside). Especially when using host \ */
/*          devices without ready-signal handshaking (i.e. also serial DPM) where netX access times could not be met under all \ */
/*          conditions error detection handling becomes mandatory. It is recommended to check for errors after each access. In \ */
/*          error-case the last access must be repeated. If an error occurs permanently the host must stretch external DPM access \ */
/*          by inserting wait states. For all other DPM connections this error detection should only be a debug feature. */
/*          Behaviour of 'wr_err' and 'rd_err' can be additionally controlled by 'dis_access_err_halt' of 'dpm_misc_cfg' register: \ */
/*          When error detection is enabled ('dis_access_err_halt' is not set), all read-access after occurrence of a read-error \ */
/*          and all write-access after occurrence of a write-error will be ignored. Error states must be reset first before new \ */
/*          accesses are performed internally. This is implemented to protect netX from unpredictable results of access errors. \ */
/*          However some applications always require access to netX internal address area (e.g. as DPM configuration window 0 \ */
/*          for error handling was disabled). For this purpose error-detection could be disabled. */
/*          DPM error IRQ ('dpm_err') and error-status flags will always be set in error case independent of 'dis_access_err_halt'. \ */
/*          Error detection is disabled by default after power on and must be enabled before usage. */
/*    Note: Errors could be avoided by programming input filtering, burst support or timing. \ */
/*          That can be configured by dpm_timing_cfg register. */
/*    Note: Serial DPM status send on the first byte of a serial access by netX is reordered and bus_conflict-errors \ */
/*          are omitted (as they are related to parallel DPM only). Serial DPM status byte is transferred MSB first \ */
/*          and contains following information (serial DPM protocol was completely revised for netx51/52 and this is a new netx51/52 feature): */
/*    } */
/*    {                           | */
/*      bit of first serial byte   status information */
/*                 7 (MSB)                          0 */
/*                 6                                0 */
/*                 5                        abort_err */
/*                 4                   sel_dpm_serial */
/*                 3                       rdy_to_err */
/*                 2                           wr_err */
/*                 1                           rd_err */
/*                 0 (LSB)                   unlocked} */
/*    {    | */
/*    Note: */
/*          The first serial transfer after reset is always ignored by the DPM module (due to initial synchronizations between the serial */
/*          and parallel part of the DPM module).} */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_status      0x0000001CU
#define Adr_NX90_dpm0_com_dpm_status 0xFF00191CU
#define Adr_NX90_dpm1_com_dpm_status 0xFF001A1CU

#define MSK_NX90_dpm_status_unlocked                 0x00000001U
#define SRT_NX90_dpm_status_unlocked                 0
#define MSK_NX90_dpm_status_rd_err                   0x00000002U
#define SRT_NX90_dpm_status_rd_err                   1
#define MSK_NX90_dpm_status_wr_err                   0x00000004U
#define SRT_NX90_dpm_status_wr_err                   2
#define MSK_NX90_dpm_status_rdy_to_err               0x00000008U
#define SRT_NX90_dpm_status_rdy_to_err               3
#define MSK_NX90_dpm_status_bus_conflict_wr_err      0x00000010U
#define SRT_NX90_dpm_status_bus_conflict_wr_err      4
#define MSK_NX90_dpm_status_bus_conflict_rd_err      0x00000020U
#define SRT_NX90_dpm_status_bus_conflict_rd_err      5
#define MSK_NX90_dpm_status_bus_conflict_rd_addr_err 0x00000040U
#define SRT_NX90_dpm_status_bus_conflict_rd_addr_err 6
#define MSK_NX90_dpm_status_sel_dpm_serial           0x00000080U
#define SRT_NX90_dpm_status_sel_dpm_serial           7
#define MSK_NX90_dpm_status_abort_err                0x00000100U
#define SRT_NX90_dpm_status_abort_err                8

/* all used bits of 'NX90_dpm_status': */
#define MSK_USED_BITS_NX90_dpm_status 0x000001ffU

enum {
  BFW_NX90_dpm_status_unlocked                 = 1,  /* [0] */
  BFW_NX90_dpm_status_rd_err                   = 1,  /* [1] */
  BFW_NX90_dpm_status_wr_err                   = 1,  /* [2] */
  BFW_NX90_dpm_status_rdy_to_err               = 1,  /* [3] */
  BFW_NX90_dpm_status_bus_conflict_wr_err      = 1,  /* [4] */
  BFW_NX90_dpm_status_bus_conflict_rd_err      = 1,  /* [5] */
  BFW_NX90_dpm_status_bus_conflict_rd_addr_err = 1,  /* [6] */
  BFW_NX90_dpm_status_sel_dpm_serial           = 1,  /* [7] */
  BFW_NX90_dpm_status_abort_err                = 1,  /* [8] */
  BFW_NX90_dpm_status_reserved1                = 23  /* [31:9] */
};

typedef struct NX90_DPM_STATUS_BIT_Ttag {
  unsigned int unlocked                 : BFW_NX90_dpm_status_unlocked;                 /* DPM is locked during netX power up and boot phase.                                                  */
                                                                                        /* DPM access to other addresses than DPM configuration window 0 cannot be done before this bit is     */
                                                                                        /* set to 1. Write access to data windows (netX AHB area) will be ignored and read access              */
                                                                                        /* will deliver invalid data while locked.                                                             */
                                                                                        /* Poll for 1 after power-up or reset.                                                                 */
  unsigned int rd_err                   : BFW_NX90_dpm_status_rd_err;                   /* DPM Read Error Status Flag.                                                                         */
                                                                                        /* Read errors occur if ready signal (DPM_RDY) is not respected by host device and                     */
                                                                                        /* external DPM read access terminated before read data could be asserted on the external DPM data     */
                                                                                        /* bus (view also t_rds in dpm_timing_cfg register).                                                   */
                                                                                        /* In case of read error this bit is set immediately after the appropriate read access. Repeat the     */
                                                                                        /* read access until no error occurs.                                                                  */
                                                                                        /* 1: The external DPM read access was too fast. Repeat the read access.                               */
                                                                                        /* 0: Read data OK.                                                                                    */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    For additional information view note in register description header.                             */
  unsigned int wr_err                   : BFW_NX90_dpm_status_wr_err;                   /* DPM Write Error Status Flag.                                                                        */
                                                                                        /* Write errors occur if ready signal (DPM_RDY) is not respected by host device and                    */
                                                                                        /* external DPM write access terminated before data could be stored.                                   */
                                                                                        /* In some cases certain netX address areas could be busy for not predictable time. If DPM_RDY is      */
                                                                                        /* not used, check for write error after write access to these areas.                                  */
                                                                                        /* In case of write error this bit is set immediately after the appropriate write access. Repeat       */
                                                                                        /* the write access until no error occurs.                                                             */
                                                                                        /* 1: The external DPM write access was too fast to store write data. Repeat the write access.         */
                                                                                        /* 0: Write access terminated without error.                                                           */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    For additional information view note in register description header.                             */
  unsigned int rdy_to_err               : BFW_NX90_dpm_status_rdy_to_err;               /* DPM_RDY Timeout Error Status Flag.                                                                  */
                                                                                        /* This error could occur if host device tries to access permanently busy netX address area (e.g. netX */
                                                                                        /* xPEC program RAM while xPEC is running). To avoid host device stalling DPM_RDY signal is released   */
                                                                                        /* to ready state after 2048 or 256 system clock cycles (i.e. 20.48us or 2.56us) at least.             */
                                                                                        /* 1: Last access went to netX busy address and was broken to avoid host device stalling.              */
                                                                                        /* 0: Access was finished successfully by DPM_RDY assertion to ready state.                            */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    For additional information view note in register description header.                             */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    This flag is not affected by 'dpm_firmware_irq' registers.                                       */
  unsigned int bus_conflict_wr_err      : BFW_NX90_dpm_status_bus_conflict_wr_err;      /* Parallel DPM write access bus error detected.                                                       */
                                                                                        /* This bit is set if a write access was started and signals change to read access states.             */
                                                                                        /* I.e. for dir_mode 0: Read-control (nRD) signal becomes active (low, after filtering if enabled)     */
                                                                                        /* during a write access.                                                                              */
                                                                                        /* I.e. for dir_mode 2: Direction line (nRD) signal changes to read (low, after filtering if enabled)  */
                                                                                        /* during a write access.                                                                              */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    For additional information view note in register description header.                             */
  unsigned int bus_conflict_rd_err      : BFW_NX90_dpm_status_bus_conflict_rd_err;      /* Parallel DPM read access bus error detected.                                                        */
                                                                                        /* This bit is set if a read access was started and signals change to write access states.             */
                                                                                        /* I.e. for dir_mode 0: Write-control (nWR) signal becomes active (low, after filtering if enabled)    */
                                                                                        /* during a read access.                                                                               */
                                                                                        /* I.e. for dir_mode 1: Direction line (nRD) signal changes to write (low, after filtering if enabled) */
                                                                                        /* during a read access.                                                                               */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    For additional information view note in register description header.                             */
  unsigned int bus_conflict_rd_addr_err : BFW_NX90_dpm_status_bus_conflict_rd_addr_err; /* Parallel DPM read access address change bus error detected.                                         */
                                                                                        /* This bit is set if address lines change (after filtering if enabled) during a read access while     */
                                                                                        /* burst support is not enabled. byte-enables are not included in this error-detection.                */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    For additional information view note in register description header.                             */
  unsigned int sel_dpm_serial           : BFW_NX90_dpm_status_sel_dpm_serial;           /* Serial mode configuration state.                                                                    */
                                                                                        /* 0: DPM is in parallel mode.                                                                         */
                                                                                        /* 1: DPM is in serial mode.                                                                           */
                                                                                        /* Mode selection is done by hif_io_cfg register inside HIF_IO_CTRL address area.                      */
                                                                                        /* Note:                                                                                               */
                                                                                        /*    After enabling serial DPM 2 dummy read streams must be performed to initialize internal logic.   */
  unsigned int abort_err                : BFW_NX90_dpm_status_abort_err;                /* Abort error state (since netX90).                                                                   */
                                                                                        /* The internal netX-logic may return an abort response for an access. Reason could                    */
                                                                                        /* be that the access is blocked by a firewall or it targets address area, which is not                */
                                                                                        /* available for the DPM. An aborted access means data failure: An aborted read access                 */
                                                                                        /* will return invalid data. Data of an aborted write access is junked by the netX.                    */
                                                                                        /* 0: No access was aborted                                                                            */
                                                                                        /* 1: An access was aborted (AHB HRESP returned ERROR). Data is lost.                                  */
  unsigned int reserved1                : BFW_NX90_dpm_status_reserved1;                /* reserved                                                                                            */
} NX90_DPM_STATUS_BIT_T;

typedef union {
  uint32_t              val;
  NX90_DPM_STATUS_BIT_T bf;
} NX90_DPM_STATUS_T;

/* --------------------------------------------------------------------- */
/* Register dpm_status_err_reset */
/* => DPM Error Status Reset Register. */
/*    Each flags can be reset by writing a '1' to it. For fast error detection for DPM interfaces without ready usage, */
/*    reset-on-read-function can be enabled for this register. */
/*     */
/*    Note: */
/*       If reset-on-read-function is enabled, this register must be read with a single access as bits are cleared */
/*       immediately after the access. You should always use a byte access in this case. */
/*     */
/*    Note: */
/*       View dpm_status register for detailed error description. */
/*     */
/*    Note: */
/*       reset-on-read-function is controlled by enable_flag_reset_on_rd-bit in dpm_misc_cfg-register. */
/*     */
/*    Note: */
/*       In cases where internal access time is not predictable and host provides no */
/*       ready function, it is recommended to enable reset-on-read-function. There is only one access */
/*       necessary for error detection and clearing this flag then. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_status_err_reset      0x00000020U
#define Adr_NX90_dpm0_com_dpm_status_err_reset 0xFF001920U
#define Adr_NX90_dpm1_com_dpm_status_err_reset 0xFF001A20U
#define DFLT_VAL_NX90_dpm_status_err_reset     0x00000000U

#define MSK_NX90_dpm_status_err_reset_rd_err_rst                           0x00000002U
#define SRT_NX90_dpm_status_err_reset_rd_err_rst                           1
#define DFLT_VAL_NX90_dpm_status_err_reset_rd_err_rst                      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_rd_err_rst                   0x00000000U
#define MSK_NX90_dpm_status_err_reset_wr_err_rst                           0x00000004U
#define SRT_NX90_dpm_status_err_reset_wr_err_rst                           2
#define DFLT_VAL_NX90_dpm_status_err_reset_wr_err_rst                      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_wr_err_rst                   0x00000000U
#define MSK_NX90_dpm_status_err_reset_rdy_to_err_rst                       0x00000008U
#define SRT_NX90_dpm_status_err_reset_rdy_to_err_rst                       3
#define DFLT_VAL_NX90_dpm_status_err_reset_rdy_to_err_rst                  0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_rdy_to_err_rst               0x00000000U
#define MSK_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst              0x00000010U
#define SRT_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst              4
#define DFLT_VAL_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst      0x00000000U
#define MSK_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst              0x00000020U
#define SRT_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst              5
#define DFLT_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst      0x00000000U
#define MSK_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst         0x00000040U
#define SRT_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst         6
#define DFLT_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst 0x00000000U
#define MSK_NX90_dpm_status_err_reset_abort_err_rst                        0x00000100U
#define SRT_NX90_dpm_status_err_reset_abort_err_rst                        8
#define DFLT_VAL_NX90_dpm_status_err_reset_abort_err_rst                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_abort_err_rst                0x00000000U

/* all used bits of 'NX90_dpm_status_err_reset': */
#define MSK_USED_BITS_NX90_dpm_status_err_reset 0x0000017eU

enum {
  BFW_NX90_dpm_status_err_reset_reserved1                    = 1,  /* [0] */
  BFW_NX90_dpm_status_err_reset_rd_err_rst                   = 1,  /* [1] */
  BFW_NX90_dpm_status_err_reset_wr_err_rst                   = 1,  /* [2] */
  BFW_NX90_dpm_status_err_reset_rdy_to_err_rst               = 1,  /* [3] */
  BFW_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst      = 1,  /* [4] */
  BFW_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst      = 1,  /* [5] */
  BFW_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst = 1,  /* [6] */
  BFW_NX90_dpm_status_err_reset_reserved2                    = 1,  /* [7] */
  BFW_NX90_dpm_status_err_reset_abort_err_rst                = 1,  /* [8] */
  BFW_NX90_dpm_status_err_reset_reserved3                    = 23  /* [31:9] */
};

typedef struct NX90_DPM_STATUS_ERR_RESET_BIT_Ttag {
  unsigned int reserved1                    : BFW_NX90_dpm_status_err_reset_reserved1;                    /* reserved                                                                                                 */
  unsigned int rd_err_rst                   : BFW_NX90_dpm_status_err_reset_rd_err_rst;                   /* DPM read error detection bit with auto reset function.                                                   */
                                                                                                          /* For fast write error detection this bit can be checked after each write access. If it was set, the write */
                                                                                                          /* access must be repeated.                                                                                 */
  unsigned int wr_err_rst                   : BFW_NX90_dpm_status_err_reset_wr_err_rst;                   /* DPM write error detection bit with auto reset function.                                                  */
                                                                                                          /* For fast read error detection this bit can be checked after each read access. If it was set, the read    */
                                                                                                          /* access must be repeated.                                                                                 */
  unsigned int rdy_to_err_rst               : BFW_NX90_dpm_status_err_reset_rdy_to_err_rst;               /* DPM_RDY timeout error.                                                                                   */
  unsigned int bus_conflict_wr_err_rst      : BFW_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst;      /* Parallel DPM write access bus error detected.                                                            */
  unsigned int bus_conflict_rd_err_rst      : BFW_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst;      /* Parallel DPM read access bus error detected.                                                             */
  unsigned int bus_conflict_rd_addr_err_rst : BFW_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst; /* Parallel DPM read access address change bus error detected.                                              */
  unsigned int reserved2                    : BFW_NX90_dpm_status_err_reset_reserved2;                    /* reserved                                                                                                 */
  unsigned int abort_err_rst                : BFW_NX90_dpm_status_err_reset_abort_err_rst;                /* Abort error state (since netX90).                                                                        */
  unsigned int reserved3                    : BFW_NX90_dpm_status_err_reset_reserved3;                    /* reserved                                                                                                 */
} NX90_DPM_STATUS_ERR_RESET_BIT_T;

typedef union {
  uint32_t                        val;
  NX90_DPM_STATUS_ERR_RESET_BIT_T bf;
} NX90_DPM_STATUS_ERR_RESET_T;

/* --------------------------------------------------------------------- */
/* Register dpm_status_err_addr */
/* => DPM Error Address Status Register. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_status_err_addr      0x00000024U
#define Adr_NX90_dpm0_com_dpm_status_err_addr 0xFF001924U
#define Adr_NX90_dpm1_com_dpm_status_err_addr 0xFF001A24U

#define MSK_NX90_dpm_status_err_addr_err_addr 0x000fffffU
#define SRT_NX90_dpm_status_err_addr_err_addr 0

/* all used bits of 'NX90_dpm_status_err_addr': */
#define MSK_USED_BITS_NX90_dpm_status_err_addr 0x000fffffU

enum {
  BFW_NX90_dpm_status_err_addr_err_addr  = 20, /* [19:0] */
  BFW_NX90_dpm_status_err_addr_reserved1 = 12  /* [31:20] */
};

typedef struct NX90_DPM_STATUS_ERR_ADDR_BIT_Ttag {
  unsigned int err_addr  : BFW_NX90_dpm_status_err_addr_err_addr;  /* Access error address.                                                                                                                 */
                                                                   /* Address of first erroneous access. IRQ handler can use this value to repeat failed accesses after error                               */
                                                                   /* bits are set in dpm_status or dpm_status_err_reset register. However, only DPM Read Error (rd_err),                                   */
                                                                   /* DPM Write Error (wr_err) and DPM_RDY Timeout Error (rdy_to_err) are cared for address logging.                                        */
                                                                   /* This register is only valid if one of the error bits is set and should be read before error bits are cleared. If no error bit is set, */
                                                                   /* it is updated each access to the current address.                                                                                     */
                                                                   /* Note:                                                                                                                                 */
                                                                   /*    Address status during bus conflict errors will not be logged. Bus conflict error status information                                */
                                                                   /*    is for debug purpose of unstable systems. Purpose of this register is primarily access error                                       */
                                                                   /*    handling for systems without ready usage.                                                                                          */
  unsigned int reserved1 : BFW_NX90_dpm_status_err_addr_reserved1; /* reserved                                                                                                                              */
} NX90_DPM_STATUS_ERR_ADDR_BIT_T;

typedef union {
  uint32_t                       val;
  NX90_DPM_STATUS_ERR_ADDR_BIT_T bf;
} NX90_DPM_STATUS_ERR_ADDR_T;

/* --------------------------------------------------------------------- */
/* Register dpm_misc_cfg */
/* => DPM Configuration Register for some Special Functions. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_misc_cfg      0x00000028U
#define Adr_NX90_dpm0_com_dpm_misc_cfg 0xFF001928U
#define Adr_NX90_dpm1_com_dpm_misc_cfg 0xFF001A28U
#define DFLT_VAL_NX90_dpm_misc_cfg     0x00000006U

#define MSK_NX90_dpm_misc_cfg_enable_flag_reset_on_rd             0x00000001U
#define SRT_NX90_dpm_misc_cfg_enable_flag_reset_on_rd             0
#define DFLT_VAL_NX90_dpm_misc_cfg_enable_flag_reset_on_rd        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_misc_cfg_enable_flag_reset_on_rd     0x00000000U
#define MSK_NX90_dpm_misc_cfg_dis_access_err_halt                 0x00000002U
#define SRT_NX90_dpm_misc_cfg_dis_access_err_halt                 1
#define DFLT_VAL_NX90_dpm_misc_cfg_dis_access_err_halt            0x00000002U
#define DFLT_BF_VAL_NX90_dpm_misc_cfg_dis_access_err_halt         0x00000001U
#define MSK_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect         0x00000004U
#define SRT_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect         2
#define DFLT_VAL_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect    0x00000004U
#define DFLT_BF_VAL_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect 0x00000001U

/* all used bits of 'NX90_dpm_misc_cfg': */
#define MSK_USED_BITS_NX90_dpm_misc_cfg 0x00000007U

enum {
  BFW_NX90_dpm_misc_cfg_enable_flag_reset_on_rd     = 1,  /* [0] */
  BFW_NX90_dpm_misc_cfg_dis_access_err_halt         = 1,  /* [1] */
  BFW_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect = 1,  /* [2] */
  BFW_NX90_dpm_misc_cfg_reserved1                   = 29  /* [31:3] */
};

typedef struct NX90_DPM_MISC_CFG_BIT_Ttag {
  unsigned int enable_flag_reset_on_rd     : BFW_NX90_dpm_misc_cfg_enable_flag_reset_on_rd;     /* Enable Status Flag Reset by reading the 'dpm_status_err_reset' register.                                */
                                                                                                /* When enable_flag_reset_on_rd-bit is set to '1', there is only one access necessary for                  */
                                                                                                /* error detection and clearing the error status bits. In cases where internal access time is              */
                                                                                                /* not predictable and host provides no ready function, it is recommended to enable reset-on-read-function */
                                                                                                /* to minimize traffic.                                                                                    */
  unsigned int dis_access_err_halt         : BFW_NX90_dpm_misc_cfg_dis_access_err_halt;         /* Disable halt after access-errors where detected.                                                        */
                                                                                                /* When this bit is set access-error-detection ('rd_err', 'wr_err' and 'rdy_to_err' status bits            */
                                                                                                /* of 'dpm_status' register) will be set in error case but following accesses to netX internal             */
                                                                                                /* address area will not be blocked. Error IRQs will be generated.                                         */
                                                                                                /* Note:                                                                                                   */
                                                                                                /*    This bit is set by default, but it is strongly recommended to clear it. However keeping              */
                                                                                                /*    this bit set could be helpful for debugging, netx50 compatibility or when                            */
                                                                                                /*    DPM configuration window 0 is disabled and not available for error handling.                         */
                                                                                                /* Note:                                                                                                   */
                                                                                                /*    IRQ 'dpm_err' is asserted in case of access-errors even when this bit is set.                        */
                                                                                                /* Note:                                                                                                   */
                                                                                                /*    This is a new netx51/52 feature.                                                                     */
  unsigned int dis_bus_conflict_err_detect : BFW_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect; /* This bit controls bus-error-detection.                                                                  */
                                                                                                /* When this bit is set, detected bus errors will only be flagged inside 'dpm_status' register             */
                                                                                                /* without further action. When this bit is cleared, dpm_error IRQ will be asserted and erroneous          */
                                                                                                /* accesses are terminated (or ignored) in error case additionally.                                        */
                                                                                                /* View also 'bus_conflict' status bits and description of 'dpm_status' register for details.              */
                                                                                                /* Note:                                                                                                   */
                                                                                                /*    This bit is set by default, but it is strongly recommended to clear it. However keeping              */
                                                                                                /*    this bit set could be helpful for debugging, netx50 compatibility or when                            */
                                                                                                /*    DPM configuration window 0 is disabled and not available for error handling.                         */
                                                                                                /* Note:                                                                                                   */
                                                                                                /*    This bit could become necessary to be set for modes with direction signal                            */
                                                                                                /*    where byte-enables change (nearly) simultaneously to direction signal (e.g. old Motorola 8bit CPUs). */
                                                                                                /*    In this case DPM could detect an error at read access end when direction line is                     */
                                                                                                /*    already sampled inactive while byte-enables are still sampled active.                                */
                                                                                                /* Note:                                                                                                   */
                                                                                                /*    This is a new netx51/52 feature.                                                                     */
  unsigned int reserved1                   : BFW_NX90_dpm_misc_cfg_reserved1;                   /* reserved                                                                                                */
} NX90_DPM_MISC_CFG_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_MISC_CFG_BIT_T bf;
} NX90_DPM_MISC_CFG_T;

/* --------------------------------------------------------------------- */
/* Register dpm_io_cfg_misc */
/* => DPM IO Configuration Register. */
/*    PIO usage of DPM_SIRQ, DPM_DIRQ and DPM_RDY has moved from this register to register'dpm_pio_cfg1' since netx51/52. */
/*    Signals which should be used as PIOs when netX DPM is active must be selected there. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_io_cfg_misc      0x0000002CU
#define Adr_NX90_dpm0_com_dpm_io_cfg_misc 0xFF00192CU
#define Adr_NX90_dpm1_com_dpm_io_cfg_misc 0xFF001A2CU
#define DFLT_VAL_NX90_dpm_io_cfg_misc     0x000000a0U

#define MSK_NX90_dpm_io_cfg_misc_irq_pol         0x00000010U
#define SRT_NX90_dpm_io_cfg_misc_irq_pol         4
#define DFLT_VAL_NX90_dpm_io_cfg_misc_irq_pol    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_irq_pol 0x00000000U
#define MSK_NX90_dpm_io_cfg_misc_irq_oec         0x00000020U
#define SRT_NX90_dpm_io_cfg_misc_irq_oec         5
#define DFLT_VAL_NX90_dpm_io_cfg_misc_irq_oec    0x00000020U
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_irq_oec 0x00000001U
#define MSK_NX90_dpm_io_cfg_misc_fiq_pol         0x00000040U
#define SRT_NX90_dpm_io_cfg_misc_fiq_pol         6
#define DFLT_VAL_NX90_dpm_io_cfg_misc_fiq_pol    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_fiq_pol 0x00000000U
#define MSK_NX90_dpm_io_cfg_misc_fiq_oec         0x00000080U
#define SRT_NX90_dpm_io_cfg_misc_fiq_oec         7
#define DFLT_VAL_NX90_dpm_io_cfg_misc_fiq_oec    0x00000080U
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_fiq_oec 0x00000001U

/* all used bits of 'NX90_dpm_io_cfg_misc': */
#define MSK_USED_BITS_NX90_dpm_io_cfg_misc 0x000000f0U

enum {
  BFW_NX90_dpm_io_cfg_misc_reserved1 = 4,  /* [3:0] */
  BFW_NX90_dpm_io_cfg_misc_irq_pol   = 1,  /* [4] */
  BFW_NX90_dpm_io_cfg_misc_irq_oec   = 1,  /* [5] */
  BFW_NX90_dpm_io_cfg_misc_fiq_pol   = 1,  /* [6] */
  BFW_NX90_dpm_io_cfg_misc_fiq_oec   = 1,  /* [7] */
  BFW_NX90_dpm_io_cfg_misc_reserved2 = 24  /* [31:8] */
};

typedef struct NX90_DPM_IO_CFG_MISC_BIT_Ttag {
  unsigned int reserved1 : BFW_NX90_dpm_io_cfg_misc_reserved1; /* reserved                                                                                                                  */
  unsigned int irq_pol   : BFW_NX90_dpm_io_cfg_misc_irq_pol;   /* IRQ/DIRQ signal polarity.                                                                                                 */
                                                               /* 0: IRQ/DIRQ is active low.                                                                                                */
                                                               /* 1: IRQ/DIRQ is active high.                                                                                               */
  unsigned int irq_oec   : BFW_NX90_dpm_io_cfg_misc_irq_oec;   /* IRQ output enable controlled.                                                                                             */
                                                               /* 0: IRQ/DIRQ signal is always driven.                                                                                      */
                                                               /* 1: IRQ/DIRQ signal is only driven when active. Inactive level must be realized by external pull-up or pull-down resistor. */
  unsigned int fiq_pol   : BFW_NX90_dpm_io_cfg_misc_fiq_pol;   /* FIQ/SIRQ signal polarity.                                                                                                 */
                                                               /* 0: FIQ/SIRQ is active low.                                                                                                */
                                                               /* 1: FIQ/SIRQ is active high.                                                                                               */
  unsigned int fiq_oec   : BFW_NX90_dpm_io_cfg_misc_fiq_oec;   /* FIQ/SIRQ output enable controlled.                                                                                        */
                                                               /* 0: FIQ/SIRQ signal is always driven.                                                                                      */
                                                               /* 1: FIQ/SIRQ signal is only driven when active. Inactive level must be realized by external pull-up or pull-down resistor. */
  unsigned int reserved2 : BFW_NX90_dpm_io_cfg_misc_reserved2; /* reserved                                                                                                                  */
} NX90_DPM_IO_CFG_MISC_BIT_T;

typedef union {
  uint32_t                   val;
  NX90_DPM_IO_CFG_MISC_BIT_T bf;
} NX90_DPM_IO_CFG_MISC_T;

/* --------------------------------------------------------------------- */
/* Register dpm_tunnel_cfg */
/* => DPM Access Tunnel Configuration Register. */
/*    The DPM Access Tunnel (DATunnel) is a 64 byte (16DWord) address window which can be mapped on any 64 byte boundary of the external */
/*    visible address space. At the last DWord (offset 0x3C) of the DATunnel the Internal Target Base Address (ITBAddr) can be programmed. */
/*    This is the base address of the 64 byte tunnel target area inside the full 32-bit netX address range (however some address areas */
/*    could not be reachable as connections could be cut from the DPM inside the netX data-switch, refer to the data-switch documentation */
/*    of your netX). */
/*    By the DWords 0 to 14 of the tunnel the internal netX addresses starting at ITBAddr can be reached. The 'enable'-bit must be active */
/*    for this (read-only functionality can be configured by 'wp_data'-bit). */
/*    For access to netX data with ITBAddr DWord offset 15, the lower bits 5 to 2 of the programmed ITBAddr are interpreted as a mapping */
/*    value. This value will be added to the internal access address before tunnelling (wrapping around at the 64 byte boundary). Hence it */
/*    is possible to access always 15 of the 16 netX DWord while the one hidden by the ITBAddr can be selected by an appropriate mapping */
/*    value. */
/*    The ITBAddr can also be programmed by the 'dpm_itbaddr' register of the configuration window 0 (or the INTLOGIC area). The ITBAddr on */
/*    tunnel offset 0x3C can be write-protected by the 'wp_itbaddr'-bit. This could be useful to protect the NETX from reconfiguring the */
/*    tunnel from the host side but provides the host the internal NETX destination address anyhow. However this only makes sense when */
/*    the configuration window 0 is disabled ('dpm_addr_cfg' register). Otherwise the host could reconfigure the tunnel by the 'dpm_itbaddr' */
/*    register. */
/*    Additionally the 'tunnel_all'-bit provides the possibility of tunnelling all 16DWords to the NETX side. */
/*    To protect the NETX from reconfiguring the tunnel from the host side when the configuration window 0 is enabled, the 'wp_cfg_win' */
/*    can be activated. Then the tunnel configuration can only be changed from the NETX side (INTLOGIC area) but not from configuration */
/*    window 0 (in contrast to the 'wp_itbaddr'-bit which protects only offset 0x3C). */
/*     */
/*    Note: */
/*       To protect the netX completely from host-access to not permitted address areas it must be ensured that also the remapping */
/*       of the DPM data windows cannot be changed by the host (refer to registers 'dpm_winX_end' and 'dpm_winX_map'). */
/*     */
/*    External to internal address mapping for DATunnel area can be calculated by following formula: */
/*       INAAdr = (ITBAddr & 0xffffffc0) + ((EDAAdr + ITBAddr) & 0x3C) */
/*     */
/*    With: */
/*       INAAdr:  Internal netX Access Address */
/*       ITBAddr: Internal netX 32-bit Tunnel Target Base Address */
/*       EDAAdr:  External DPM Access Address */
/*     */
/*    Condition for DATunnel access is: */
/*       EDAAdr>>6 equals value of bit field 'base' from this register. */
/*     */
/*    To map netX internal DWord N to invisible last external DWord (15), use mapping value */
/*       map = (N - 15) & 0xf */
/*    on bits 5 to 2. */
/*    Internal to external address offset inside DATunnel area for internal DWord N can be calculated by following formula: */
/*       External offset = (N*4 - map*4) & 0x3C = (N*4 - ITBAddr) & 0x3C */
/*     */
/*    Example 1: */
/*       Access to netX sys_time module by host via DATunnel on external DPM addresses are starting at 0x240. */
/*       - Set bit field 'base' of this register to 9 (0x240>>6), set 'enable'-bit (and write protection depending on application). */
/*         DATunnel now is enabled on external DPM addresses 0x240 to 0x27f. */
/*       - ITBAddr of netX10 sys_time module is 0x101c1000. */
/*         For direct DATunnel to this address, host must write 0x101c1000 to external DPM address 0x27c. This */
/*         can be done e.g. by four byte accesses to 0x27c, 0x27d, 0x27e and 0x27f or by two 16-bit accesses to 0x27c and 0x27e. */
/*         Now sys_time module registers 0 to 14 can be accessed on external DPM address 0x240 to 0x27b. */
/*     */
/*    Example 2: */
/*       Register 15 of sys_time is hidden by ITBAddr configuration on 0x27c in example 1 but must also be accessed. However, sys_time */
/*       Register 6 is never kind of interest. */
/*       - Configure this register like described in example 1. */
/*       - To map Register 6 (Module offset 6*4) to external offset 0x3C (hidden data on DWord 15), */
/*         the following rule must be complied: */
/*            0x3C + map*4 = 6*4. */
/*         That leads to a mapping value of: */
/*            map*4 = (6*4 - 0x3C) & 0x3C = 1C */
/*         Hence, write 0x101c101C to DATunnel DWord 15 (external DPM address 0x27c) to map sys_time Register 6 to */
/*         hidden DWord 15. */
/*         INAAdr now will be derived from EDAAdr before tunnelling as follows: */
/*            INAAdr = 0x101c1000 + ((EDAAdr + 0x1C) & 0x3C) */
/*         External offset of Module DWord N results from: */
/*            External offset = (N*4 - 0x1C) & 0x3C */
/*         Register 15 of sys_time unit now can be accessed by external DPM address 0x240+((0xf*4-0x1C) & 0x3C) = 0x260 (i.e. Tunnel DWord 8). */
/*         Register 0  of sys_time unit now can be accessed by external DPM address 0x240+((0x0*4-0x1C) & 0x3C) = 0x264 (i.e. Tunnel DWord 9). */
/*         Register 1  of sys_time unit now can be accessed by external DPM address 0x240+((0x1*4-0x1C) & 0x3C) = 0x268 (i.e. Tunnel DWord 10). */
/*         and so on. */
/*         Register 6  of sys_time unit can not be accessed as it is hidden by ITBAddr configuration on 0x27c (i.e. Tunnel DWord 15). */
/*         Register 7  of sys_time unit now can be accessed by external DPM address 0x240+((0x7*4-0x1C) & 0x3C) = 0x240 (i.e. Tunnel DWord 0). */
/*     */
/*    Note: */
/*      Access to netX ITBAddr data is done without read ahead and with byte collecting (view adr_dpm_win1_map for details). */
/*     */
/*    Note: */
/*      Configuration Window 0 access detection has higher priority than normal DPM Window */
/*      detection but lower priority than Access Tunnel access detection. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_tunnel_cfg      0x00000038U
#define Adr_NX90_dpm0_com_dpm_tunnel_cfg 0xFF001938U
#define Adr_NX90_dpm1_com_dpm_tunnel_cfg 0xFF001A38U
#define DFLT_VAL_NX90_dpm_tunnel_cfg     0x00000101U

#define MSK_NX90_dpm_tunnel_cfg_wp_data              0x00000001U
#define SRT_NX90_dpm_tunnel_cfg_wp_data              0
#define DFLT_VAL_NX90_dpm_tunnel_cfg_wp_data         0x00000001U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_wp_data      0x00000001U
#define MSK_NX90_dpm_tunnel_cfg_wp_itbaddr           0x00000002U
#define SRT_NX90_dpm_tunnel_cfg_wp_itbaddr           1
#define DFLT_VAL_NX90_dpm_tunnel_cfg_wp_itbaddr      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_wp_itbaddr   0x00000000U
#define MSK_NX90_dpm_tunnel_cfg_enable               0x00000004U
#define SRT_NX90_dpm_tunnel_cfg_enable               2
#define DFLT_VAL_NX90_dpm_tunnel_cfg_enable          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_enable       0x00000000U
#define MSK_NX90_dpm_tunnel_cfg_tunnel_all           0x00000008U
#define SRT_NX90_dpm_tunnel_cfg_tunnel_all           3
#define DFLT_VAL_NX90_dpm_tunnel_cfg_tunnel_all      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_tunnel_all   0x00000000U
#define MSK_NX90_dpm_tunnel_cfg_byte_area            0x00000010U
#define SRT_NX90_dpm_tunnel_cfg_byte_area            4
#define DFLT_VAL_NX90_dpm_tunnel_cfg_byte_area       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_byte_area    0x00000000U
#define MSK_NX90_dpm_tunnel_cfg_dis_rd_latch         0x00000020U
#define SRT_NX90_dpm_tunnel_cfg_dis_rd_latch         5
#define DFLT_VAL_NX90_dpm_tunnel_cfg_dis_rd_latch    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_dis_rd_latch 0x00000000U
#define MSK_NX90_dpm_tunnel_cfg_base                 0x000fffc0U
#define SRT_NX90_dpm_tunnel_cfg_base                 6
#define DFLT_VAL_NX90_dpm_tunnel_cfg_base            0x00000100U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_base         0x00000004U
#define MSK_NX90_dpm_tunnel_cfg_wp_cfg_win           0x80000000U
#define SRT_NX90_dpm_tunnel_cfg_wp_cfg_win           31
#define DFLT_VAL_NX90_dpm_tunnel_cfg_wp_cfg_win      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_wp_cfg_win   0x00000000U

/* all used bits of 'NX90_dpm_tunnel_cfg': */
#define MSK_USED_BITS_NX90_dpm_tunnel_cfg 0x800fffffU

enum {
  BFW_NX90_dpm_tunnel_cfg_wp_data      = 1,  /* [0] */
  BFW_NX90_dpm_tunnel_cfg_wp_itbaddr   = 1,  /* [1] */
  BFW_NX90_dpm_tunnel_cfg_enable       = 1,  /* [2] */
  BFW_NX90_dpm_tunnel_cfg_tunnel_all   = 1,  /* [3] */
  BFW_NX90_dpm_tunnel_cfg_byte_area    = 1,  /* [4] */
  BFW_NX90_dpm_tunnel_cfg_dis_rd_latch = 1,  /* [5] */
  BFW_NX90_dpm_tunnel_cfg_base         = 14, /* [19:6] */
  BFW_NX90_dpm_tunnel_cfg_reserved1    = 11, /* [30:20] */
  BFW_NX90_dpm_tunnel_cfg_wp_cfg_win   = 1   /* [31] */
};

typedef struct NX90_DPM_TUNNEL_CFG_BIT_Ttag {
  unsigned int wp_data      : BFW_NX90_dpm_tunnel_cfg_wp_data;      /* Access Tunnel function is write-protected from data access (DWords 0 to 14 of DATunnel).                      */
                                                                    /* Write accesses to DWords 0 to 14 of DATunnel will be ignored.                                                 */
                                                                    /* Data write protection for host is enabled by default and can be disabled by clearing this bit.                */
  unsigned int wp_itbaddr   : BFW_NX90_dpm_tunnel_cfg_wp_itbaddr;   /* ITBAddr is write-protected from host.                                                                         */
                                                                    /* If this bit is set, ITBAddr (Internal netX 32 bit Tunnel Target Base Address)                                 */
                                                                    /* can only be changed from netX side using dpm_itbaddr address.                                                 */
                                                                    /* Write accesses to DWords 0 to 14 of DATunnel will be ignored.                                                 */
  unsigned int enable       : BFW_NX90_dpm_tunnel_cfg_enable;       /* Enable/disable Access Tunnel function.                                                                        */
  unsigned int tunnel_all   : BFW_NX90_dpm_tunnel_cfg_tunnel_all;   /* Enable/disable external access to Internal Target Base Address (ITBAddr) Configuration Register.              */
                                                                    /* If this bit is set Internal Target Base Address (ITBAddr) configuration is not available at tunnel            */
                                                                    /* offset 0x3C. All 64 tunnel target bytes can be accessed then (no hidden register). Target mapping and address */
                                                                    /* (base and map) will not be changed when enable or disabled.                                                   */
                                                                    /* Note:                                                                                                         */
                                                                    /*    This is a new netx51/52 feature.                                                                           */
  unsigned int byte_area    : BFW_NX90_dpm_tunnel_cfg_byte_area;    /* Tunnel is byte area or not. View 'byte_area' of 'dpm_win1_map' register for details.                          */
                                                                    /* Note:                                                                                                         */
                                                                    /*    This is a new netx51/52 feature.                                                                           */
  unsigned int dis_rd_latch : BFW_NX90_dpm_tunnel_cfg_dis_rd_latch; /* Disabled read data latch for Tunnel. View 'dis_rd_latch' of 'dpm_win1_map' register for details.              */
                                                                    /* Note:                                                                                                         */
                                                                    /*    This is a new netx51/52 feature.                                                                           */
  unsigned int base         : BFW_NX90_dpm_tunnel_cfg_base;         /* DPM Access Tunnel (DATunnel) Base Address divided by 64 on external visible address space.                    */
                                                                    /* Note:                                                                                                         */
                                                                    /*    Default setting for tunnel base is starting on external address 0x100.                                     */
  unsigned int reserved1    : BFW_NX90_dpm_tunnel_cfg_reserved1;    /* reserved                                                                                                      */
  unsigned int wp_cfg_win   : BFW_NX90_dpm_tunnel_cfg_wp_cfg_win;   /* Write-protect tunnel configuration inside the configuration window 0.                                         */
                                                                    /* 0: The two tunnel configuration registers ('idpm_tunnel_cfg' and 'idpm_itbaddr') can be programmed            */
                                                                    /*    via configuration window 0 and the INTLOGIC_SYS-IDPM address area.                                         */
                                                                    /* 1: The tunnel configuration registers ('idpm_tunnel_cfg' and 'idpm_itbaddr') cannot                           */
                                                                    /*    be programmed by the host via configuration window 0 (they are read-only for the host there).              */
                                                                    /*    They can only be programmed via the INTLOGIC_SYS-IDPM address area.                                        */
                                                                    /* Note: Set this bit to protect the NETX from reconfiguring the tunnel by the host when configuration           */
                                                                    /*    window 0 is activated for the host (e.g. for IRQ handling).                                                */
                                                                    /* Note:                                                                                                         */
                                                                    /*    The 'wp_cfg_win'-bit is a new feature since netX4000 and netX6.                                            */
} NX90_DPM_TUNNEL_CFG_BIT_T;

typedef union {
  uint32_t                  val;
  NX90_DPM_TUNNEL_CFG_BIT_T bf;
} NX90_DPM_TUNNEL_CFG_T;

/* --------------------------------------------------------------------- */
/* Register dpm_itbaddr */
/* => DPM Access Tunnel (DATunnel) netX Internal Target Base Address (ITBAddr) Configuration Register. */
/*    For DPM Access Tunnel (DATunnel) function view description of dpm_tunnel_cfg register. */
/*    This register contains ITBAddr value that can also be changed by host on last offset 0x3c (last DWord) of */
/*    external DATunnel area (defined by bit field 'base' in 'dpm_tunnel_cfg' register). However this register can */
/*    also be write-protected from host if bit 'wp_itbaddr' in 'dpm_tunnel_cfg' register is set. */
/*    Write protection bits of DATunnel configured in 'dpm_tunnel_cfg' register can also be read from this register. Host */
/*    can read access rights from these bits on last DWord of external DATunnel address area. */
/*     */
/*    Note: This register can be write-protected by the 'wp_cfg_win' and the 'wp_itbaddr'-bit of the 'dpm_tunnel_cfg' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_itbaddr      0x0000003CU
#define Adr_NX90_dpm0_com_dpm_itbaddr 0xFF00193CU
#define Adr_NX90_dpm1_com_dpm_itbaddr 0xFF001A3CU
#define DFLT_VAL_NX90_dpm_itbaddr     0x00000001U

#define MSK_NX90_dpm_itbaddr_wp_data_ro            0x00000001U
#define SRT_NX90_dpm_itbaddr_wp_data_ro            0
#define DFLT_VAL_NX90_dpm_itbaddr_wp_data_ro       0x00000001U
#define DFLT_BF_VAL_NX90_dpm_itbaddr_wp_data_ro    0x00000001U
#define MSK_NX90_dpm_itbaddr_wp_itbaddr_ro         0x00000002U
#define SRT_NX90_dpm_itbaddr_wp_itbaddr_ro         1
#define DFLT_VAL_NX90_dpm_itbaddr_wp_itbaddr_ro    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_itbaddr_wp_itbaddr_ro 0x00000000U
#define MSK_NX90_dpm_itbaddr_map                   0x0000003cU
#define SRT_NX90_dpm_itbaddr_map                   2
#define DFLT_VAL_NX90_dpm_itbaddr_map              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_itbaddr_map           0x00000000U
#define MSK_NX90_dpm_itbaddr_base                  0xffffffc0U
#define SRT_NX90_dpm_itbaddr_base                  6
#define DFLT_VAL_NX90_dpm_itbaddr_base             0x00000000U
#define DFLT_BF_VAL_NX90_dpm_itbaddr_base          0x00000000U

/* all used bits of 'NX90_dpm_itbaddr': */
#define MSK_USED_BITS_NX90_dpm_itbaddr 0xffffffffU

enum {
  BFW_NX90_dpm_itbaddr_wp_data_ro    = 1,  /* [0] */
  BFW_NX90_dpm_itbaddr_wp_itbaddr_ro = 1,  /* [1] */
  BFW_NX90_dpm_itbaddr_map           = 4,  /* [5:2] */
  BFW_NX90_dpm_itbaddr_base          = 26  /* [31:6] */
};

typedef struct NX90_DPM_ITBADDR_BIT_Ttag {
  unsigned int wp_data_ro    : BFW_NX90_dpm_itbaddr_wp_data_ro;    /* Access Tunnel function is write-protected from data access (DWords 0 to 14 of DATunnel). */
                                                                   /* This is a read-only bit here. Its setting can be changed in 'dpm_tunnel_cfg' register.   */
                                                                   /* View description of dpm_tunnel_cfg register.                                             */
  unsigned int wp_itbaddr_ro : BFW_NX90_dpm_itbaddr_wp_itbaddr_ro; /* ITBAddr is write-protected from host.                                                    */
                                                                   /* This is a read-only bit here. Its setting can be changed in 'dpm_tunnel_cfg' register.   */
                                                                   /* View description of dpm_tunnel_cfg register.                                             */
  unsigned int map           : BFW_NX90_dpm_itbaddr_map;           /* Mapping part of ITBAddr.                                                                 */
                                                                   /* View description of dpm_tunnel_cfg register.                                             */
  unsigned int base          : BFW_NX90_dpm_itbaddr_base;          /* Internal netX Tunnel Target Base Address (ITBAddr) divided by 64.                        */
                                                                   /* View description of dpm_tunnel_cfg register.                                             */
} NX90_DPM_ITBADDR_BIT_T;

typedef union {
  uint32_t               val;
  NX90_DPM_ITBADDR_BIT_T bf;
} NX90_DPM_ITBADDR_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win1_end */
/* => DPM Window 1 End Address Configuration Register. */
/*    Smallest DPM window configuration unit is 128 bytes (i.e. lowest 7 bits of address configuration are always 0). */
/*    At address 0x0 DPM configuration window is mapped after reset (length: 256 bytes, containing all DPM addresses defined here). Each window starts at */
/*    window end address of the preceding window. Hence external window 1 start address is 0x100, window 2 starts at value programmed in this register */
/* and so on. */
/*    Windows with programmed end addresses exceeding external address range (view dpm_addr_cfg) can not be accessed by host device. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/*    Note: */
/*      Configuration Window 0 access detection has higher priority than normal DPM Window */
/*      detection but lower priority than Access Tunnel access detection. */
/*     */
/*    Note: */
/*      Since netX10 window configuration can be done in steps of 128 bytes. In netx5 only steps of 256 bytes are possible. */
/*     */
/*    Note: */
/*      Since netX10 there are 4 programmable DPM windows provided. Only for netX5 there are 5 windows. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win1_end      0x00000040U
#define Adr_NX90_dpm0_com_dpm_win1_end 0xFF001940U
#define Adr_NX90_dpm1_com_dpm_win1_end 0xFF001A40U
#define DFLT_VAL_NX90_dpm_win1_end     0x00000000U

#define MSK_NX90_dpm_win1_end_win_end         0x001fff80U
#define SRT_NX90_dpm_win1_end_win_end         7
#define DFLT_VAL_NX90_dpm_win1_end_win_end    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_end_win_end 0x00000000U

/* all used bits of 'NX90_dpm_win1_end': */
#define MSK_USED_BITS_NX90_dpm_win1_end 0x001fff80U

enum {
  BFW_NX90_dpm_win1_end_reserved1 = 7,  /* [6:0] */
  BFW_NX90_dpm_win1_end_win_end   = 14, /* [20:7] */
  BFW_NX90_dpm_win1_end_reserved2 = 11  /* [31:21] */
};

typedef struct NX90_DPM_WIN1_END_BIT_Ttag {
  unsigned int reserved1 : BFW_NX90_dpm_win1_end_reserved1; /* reserved                                                                                      */
  unsigned int win_end   : BFW_NX90_dpm_win1_end_win_end;   /* Window 1 End Address divided by 128.                                                          */
                                                            /* Last external address is win_end*128-1.                                                       */
                                                            /* Setting win_end to 0 will disable this window.                                                */
                                                            /* If programmed external address range (adr_dpm_addr_cfg) is smaller than maximum               */
                                                            /* external address range, access addresses will be zero-expanded for upper unused address lines */
                                                            /* before window match detection.                                                                */
  unsigned int reserved2 : BFW_NX90_dpm_win1_end_reserved2; /* reserved                                                                                      */
} NX90_DPM_WIN1_END_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN1_END_BIT_T bf;
} NX90_DPM_WIN1_END_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win1_map */
/* => DPM Window 1 Address Map Configuration Register. */
/*    Smallest DPM window configuration unit is 128 bytes (i.e. lowest 7 bits of address configuration are always 0). */
/*    For further information view description of 'dpm_win1_end' register. */
/*     */
/*    Note: */
/*      Since netX10 window pages of 1MB is supported. For netX5 this was not necessary as all netX5 addresses are in bound of 1MB.. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win1_map      0x00000044U
#define Adr_NX90_dpm0_com_dpm_win1_map 0xFF001944U
#define Adr_NX90_dpm1_com_dpm_win1_map 0xFF001A44U
#define DFLT_VAL_NX90_dpm_win1_map     0x01800000U

#define MSK_NX90_dpm_win1_map_byte_area            0x00000001U
#define SRT_NX90_dpm_win1_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win1_map_byte_area       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_byte_area    0x00000000U
#define MSK_NX90_dpm_win1_map_read_ahead           0x00000002U
#define SRT_NX90_dpm_win1_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win1_map_read_ahead      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_read_ahead   0x00000000U
#define MSK_NX90_dpm_win1_map_win_map_alt          0x0000000cU
#define SRT_NX90_dpm_win1_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win1_map_win_map_alt     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_win_map_alt  0x00000000U
#define MSK_NX90_dpm_win1_map_dis_rd_latch         0x00000010U
#define SRT_NX90_dpm_win1_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win1_map_dis_rd_latch    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_dis_rd_latch 0x00000000U
#define MSK_NX90_dpm_win1_map_wp_cfg_win           0x00000020U
#define SRT_NX90_dpm_win1_map_wp_cfg_win           5
#define DFLT_VAL_NX90_dpm_win1_map_wp_cfg_win      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_wp_cfg_win   0x00000000U
#define MSK_NX90_dpm_win1_map_win_map              0x000fff80U
#define SRT_NX90_dpm_win1_map_win_map              7
#define DFLT_VAL_NX90_dpm_win1_map_win_map         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_win_map      0x00000000U
#define MSK_NX90_dpm_win1_map_win_page             0xfff00000U
#define SRT_NX90_dpm_win1_map_win_page             20
#define DFLT_VAL_NX90_dpm_win1_map_win_page        0x01800000U
#define DFLT_BF_VAL_NX90_dpm_win1_map_win_page     0x00000018U

/* all used bits of 'NX90_dpm_win1_map': */
#define MSK_USED_BITS_NX90_dpm_win1_map 0xffffffbfU

enum {
  BFW_NX90_dpm_win1_map_byte_area    = 1,  /* [0] */
  BFW_NX90_dpm_win1_map_read_ahead   = 1,  /* [1] */
  BFW_NX90_dpm_win1_map_win_map_alt  = 2,  /* [3:2] */
  BFW_NX90_dpm_win1_map_dis_rd_latch = 1,  /* [4] */
  BFW_NX90_dpm_win1_map_wp_cfg_win   = 1,  /* [5] */
  BFW_NX90_dpm_win1_map_reserved1    = 1,  /* [6] */
  BFW_NX90_dpm_win1_map_win_map      = 13, /* [19:7] */
  BFW_NX90_dpm_win1_map_win_page     = 12  /* [31:20] */
};

typedef struct NX90_DPM_WIN1_MAP_BIT_Ttag {
  unsigned int byte_area    : BFW_NX90_dpm_win1_map_byte_area;    /* Window is byte-write area.                                                                                            */
                                                                  /* 1: Target area of this window is byte accessible. Any write access are done immediately internally.                   */
                                                                  /* 0: Target area of this window is 32 bit accessible. Single write accesses are collected until a 32 bit data           */
                                                                  /*    word (DWord) is received completely from host (write-byte-collecting). Data is written to netX target address when */
                                                                  /*    the 32bit data word is complete.                                                                                   */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    Since netX51/52 write-byte-collecting buffer is cleared when host is leaving the current 4-byte-address-boundary   */
                                                                  /*    (e.g. changing address from 0x103 to 0x104). That means all sub-DWord access which should make up the whole DWord  */
                                                                  /*    must target the same 4-byte-boundary. In prior DPM versions only the last written data determined netX internal    */
                                                                  /*    access address and there was no check whether all prior written data was written to the same DWord. The            */
                                                                  /*    address-boundary check is implemented to avoid write-byte-collecting getting confused by single DPM access         */
                                                                  /*    errors (e.g. by a single missing byte-write).                                                                      */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    The setting of this bit does not affect read functionality. For details see 'dis_rd_latch' bit description.        */
  unsigned int read_ahead   : BFW_NX90_dpm_win1_map_read_ahead;   /* Read ahead.                                                                                                           */
                                                                  /* If this bit is set, read ahead will be done. This will minimize read cycle time if ready generation is                */
                                                                  /* used but could cause problems with read sensitive logic (e.g. FIFOs).                                                 */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    Read-ahead should not be enabled when 'dis_rd_latch' bit is set for the same window. Otherwise access              */
                                                                  /*    timing could decrease dramatically (does not apply to setting of another window).                                  */
  unsigned int win_map_alt  : BFW_NX90_dpm_win1_map_win_map_alt;  /* Window 1 Alternative Address Mapping Configuration.                                                                   */
                                                                  /* Alternative Address Mapping can be generated by Triple Buffer Managers inside HANDSHAKE_CTRL unit.                    */
                                                                  /* Coding:                                                                                                               */
                                                                  /*  00 : Alternative Address Mapping disabled.                                                                           */
                                                                  /*  01 : Alternative Address Mapping enabled: Use Triple Buffer Manager 0 from HANDSHAKE_CTRL unit.                      */
                                                                  /*  10 : Alternative Address Mapping enabled: Use Triple Buffer Manager 1 from HANDSHAKE_CTRL unit.                      */
                                                                  /*  11 : reserved                                                                                                        */
                                                                  /* If Alternative Address Mapping is enabled, mapping value is taken according to buffer status                          */
                                                                  /* of related HANDSHAKE_CTRL Triple Buffer Manager as follows.                                                           */
                                                                  /* {                    |                                                                                                */
                                                                  /*   buffer status        used mapping value                                                                             */
                                                                  /*   00 (buffer 0)        win_map entry of this register                                                                 */
                                                                  /*   01 (buffer 1)        Alternative win_map value 1 of related HANDSHAKE_CTRL Triple Buffer Manager.                   */
                                                                  /*   10 (buffer 2)        Alternative win_map value 2 of related HANDSHAKE_CTRL Triple Buffer Manager.                   */
                                                                  /*   11 (invalid buffer)  win_map entry of this register }                                                               */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    Alternative Triple Buffer Manager win_map values can be programmed in HANDSHAKE_CTRL address area.                 */
  unsigned int dis_rd_latch : BFW_NX90_dpm_win1_map_dis_rd_latch; /* Window 1 read data latch disable.                                                                                     */
                                                                  /* By default all netX internal read access are done as 32 bit access and read data is latched                           */
                                                                  /* inside DPM interface. This is done to provide data consistence when host is connected by                              */
                                                                  /* an interface smaller than 32 bit. Read data latch is updated (new read form netX logic)                               */
                                                                  /* when host read address is changing to another 32 bit address or if host read access repeats                           */
                                                                  /* reading the same data within the 32 bit address boundary of prior accesses (e.g. polling).                            */
                                                                  /* Reading 32 bit status information from netX should be done with byte latching (Example 1).                            */
                                                                  /* Read data latch can be disabled by setting this bit to avoid special handling of byte (or                             */
                                                                  /* 16 bit) data streams (Example 2).                                                                                     */
                                                                  /* Example 1: Enabled read data latching (default, 'dis_rd_latch' bit is not set):                                       */
                                                                  /*    Reading 32 bit systime from netX without data latching will fail when DPM                                          */
                                                                  /*    is not 32 bit wide. Considering an 8 bit DPM interface would lead to 4 single                                      */
                                                                  /*    host byte read accesses for complete systime. Without data latching systime will                                   */
                                                                  /*    be re-read for each byte requested by host. This will lead to invalid data as systime                              */
                                                                  /*    will change between single reads.                                                                                  */
                                                                  /*    When data latching is enabled, systime will be read from netX at the first host byte read                          */
                                                                  /*    access. Following 3 host byte reads will receive data from DPM data latch which contains                           */
                                                                  /*    complete 32 bit systime value read at the first access. Host will receive valid systime data.                      */
                                                                  /* Example 2 Disabled read data latching ('dis_rd_latch' bit is set):                                                    */
                                                                  /*    Reading a byte stream could fail when it is appended by an application running netX inside                         */
                                                                  /*    could fail. Considering an netX application providing 13 bytes starting at a 32 bit boundary                       */
                                                                  /*    for host and host is reading these bytes. After that netX application is appending new data                        */
                                                                  /*    bytes 14 to 20. When data read latch is enabled host will receive bytes 14 to 16 from data                         */
                                                                  /*    latch. However these bytes are not valid any longer as netX application changed them in                            */
                                                                  /*    background. In this case data latching must be disabled.                                                           */
                                                                  /*    However reading byte streams is also possible with enabled data latch. In this case                                */
                                                                  /*    host must always read full 32 bit data words (i.e. restart with byte 13 when reading the                           */
                                                                  /*    second part of the stream).                                                                                        */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    When read data latch is disable 'read_ahead' bit should not be set for the same window. Otherwise access           */
                                                                  /*    timing could decrease dramatically (does not apply to setting of another window).                                  */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    All netX internal read access are performed as 32 bit access.                                                      */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    This is a new netx51/52 feature.                                                                                   */
                                                                  /*    Behaviour of older netX versions (e.g. netX10) is similar to default setting 0. No functional                      */
                                                                  /*    changes are done for default case.                                                                                 */
  unsigned int wp_cfg_win   : BFW_NX90_dpm_win1_map_wp_cfg_win;   /* Write-protect window configuration inside the configuration window 0.                                                 */
                                                                  /* 0: All 8 window configuration registers ('dpm_winX_and' and 'dpm_winX_map') can be programmed                         */
                                                                  /*    via configuration window 0 and the INTLOGIC-DPM address area.                                                      */
                                                                  /* 1: All 8 window configuration registers ('dpm_winX_and' and 'dpm_winX_map') cannot                                    */
                                                                  /*    be programmed by the host via configuration window 0 (they are read-only for the host there).                      */
                                                                  /*    They can only be programmed via the INTLOGIC-DPM address area.                                                     */
                                                                  /* Note: Set this bit to protect the NETX from reconfiguring the window mapping by the host when configuration           */
                                                                  /*    window 0 is activated for the host (e.g. for IRQ handling).                                                        */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    To protect the netX completely from host-access to not permitted address areas it must be ensured that also        */
                                                                  /*    the remapping of the DPM tunnel cannot be changed by the host (refer to register 'dpm_tunnel_cfg').                */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    This bit does only exist in the 'dpm_win1_map'-register but not in the registers for the higher windows.           */
                                                                  /*    However this bit protect all DPM 'dpm_winX_and' and 'dpm_winX_map'-registers from being written via                */
                                                                  /*    configuration window 0.                                                                                            */
                                                                  /* Note:                                                                                                                 */
                                                                  /*    The 'wp_cfg_win'-bit is a new feature since netX4000 and netX6.                                                    */
  unsigned int reserved1    : BFW_NX90_dpm_win1_map_reserved1;    /* reserved                                                                                                              */
  unsigned int win_map      : BFW_NX90_dpm_win1_map_win_map;      /* Window 1 Address Mapping.                                                                                             */
                                                                  /* Internal access address HADDR to netX logic is combined by DPM interface by:                                          */
                                                                  /* HADDR[31:20]: win_page                                                                                                */
                                                                  /* HADDR[19:0]:  mapped DPM address. This part of address is defined by programmed win_map value for each window.        */
                                                                  /* The value to be programmed is address bits 19 to 0 of netX internal window start address minus start address of the   */
                                                                  /* external window (i.e. end address of preceding window) .                                                              */
                                                                  /* Example:                                                                                                              */
                                                                  /*    Window n starts at 0x400 of external DPM address range (i.e. programmed win_end value of window (n-1) and targets  */
                                                                  /*    netX address 0x01808000.                                                                                           */
                                                                  /*    For address calculation only lower 20 bits of netX address are relevant, i.e. 0x08000.                             */
                                                                  /*    The complete 20 bit address map value is then:0x08000-0x400=0x07C00.                                               */
                                                                  /*    Hence the programmed 13 bit value must be 0x07C00>>7=0xf8.                                                         */
  unsigned int win_page     : BFW_NX90_dpm_win1_map_win_page;     /* Window 1 address page.                                                                                                */
                                                                  /* Internal address space of netX is divided in 1MB pages. Changing win_map allows addressing inside                     */
                                                                  /* the whole currently set page.                                                                                         */
                                                                  /* Example:                                                                                                              */
                                                                  /*    Window n starts at 0x400 of external DPM address range (i.e. programmed win_end value of window (n-1) and targets  */
                                                                  /*    netX address 0x01808000.                                                                                           */
                                                                  /*    The programmed value for the related page is 0x018.                                                                */
} NX90_DPM_WIN1_MAP_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN1_MAP_BIT_T bf;
} NX90_DPM_WIN1_MAP_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win2_end */
/* => DPM Window 2 End Address Configuration Register. */
/*    For detailed information refer to 'dpm_win1_end' register description. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win2_end      0x00000048U
#define Adr_NX90_dpm0_com_dpm_win2_end 0xFF001948U
#define Adr_NX90_dpm1_com_dpm_win2_end 0xFF001A48U
#define DFLT_VAL_NX90_dpm_win2_end     0x00000000U

#define MSK_NX90_dpm_win2_end_win_end         0x001fff80U
#define SRT_NX90_dpm_win2_end_win_end         7
#define DFLT_VAL_NX90_dpm_win2_end_win_end    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win2_end_win_end 0x00000000U

/* all used bits of 'NX90_dpm_win2_end': */
#define MSK_USED_BITS_NX90_dpm_win2_end 0x001fff80U

enum {
  BFW_NX90_dpm_win2_end_reserved1 = 7,  /* [6:0] */
  BFW_NX90_dpm_win2_end_win_end   = 14, /* [20:7] */
  BFW_NX90_dpm_win2_end_reserved2 = 11  /* [31:21] */
};

typedef struct NX90_DPM_WIN2_END_BIT_Ttag {
  unsigned int reserved1 : BFW_NX90_dpm_win2_end_reserved1; /* reserved                                                                     */
  unsigned int win_end   : BFW_NX90_dpm_win2_end_win_end;   /* Window 2 End Address divided by 128. Last external address is win_end*128-1. */
  unsigned int reserved2 : BFW_NX90_dpm_win2_end_reserved2; /* reserved                                                                     */
} NX90_DPM_WIN2_END_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN2_END_BIT_T bf;
} NX90_DPM_WIN2_END_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win2_map */
/* => DPM Window 2 Address Map Configuration Register. */
/*    For detailed information refer to 'dpm_win1_map' register description. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win2_map      0x0000004CU
#define Adr_NX90_dpm0_com_dpm_win2_map 0xFF00194CU
#define Adr_NX90_dpm1_com_dpm_win2_map 0xFF001A4CU
#define DFLT_VAL_NX90_dpm_win2_map     0x01800000U

#define MSK_NX90_dpm_win2_map_byte_area            0x00000001U
#define SRT_NX90_dpm_win2_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win2_map_byte_area       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win2_map_byte_area    0x00000000U
#define MSK_NX90_dpm_win2_map_read_ahead           0x00000002U
#define SRT_NX90_dpm_win2_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win2_map_read_ahead      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win2_map_read_ahead   0x00000000U
#define MSK_NX90_dpm_win2_map_win_map_alt          0x0000000cU
#define SRT_NX90_dpm_win2_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win2_map_win_map_alt     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win2_map_win_map_alt  0x00000000U
#define MSK_NX90_dpm_win2_map_dis_rd_latch         0x00000010U
#define SRT_NX90_dpm_win2_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win2_map_dis_rd_latch    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win2_map_dis_rd_latch 0x00000000U
#define MSK_NX90_dpm_win2_map_win_map              0x000fff80U
#define SRT_NX90_dpm_win2_map_win_map              7
#define DFLT_VAL_NX90_dpm_win2_map_win_map         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win2_map_win_map      0x00000000U
#define MSK_NX90_dpm_win2_map_win_page             0xfff00000U
#define SRT_NX90_dpm_win2_map_win_page             20
#define DFLT_VAL_NX90_dpm_win2_map_win_page        0x01800000U
#define DFLT_BF_VAL_NX90_dpm_win2_map_win_page     0x00000018U

/* all used bits of 'NX90_dpm_win2_map': */
#define MSK_USED_BITS_NX90_dpm_win2_map 0xffffff9fU

enum {
  BFW_NX90_dpm_win2_map_byte_area    = 1,  /* [0] */
  BFW_NX90_dpm_win2_map_read_ahead   = 1,  /* [1] */
  BFW_NX90_dpm_win2_map_win_map_alt  = 2,  /* [3:2] */
  BFW_NX90_dpm_win2_map_dis_rd_latch = 1,  /* [4] */
  BFW_NX90_dpm_win2_map_reserved1    = 2,  /* [6:5] */
  BFW_NX90_dpm_win2_map_win_map      = 13, /* [19:7] */
  BFW_NX90_dpm_win2_map_win_page     = 12  /* [31:20] */
};

typedef struct NX90_DPM_WIN2_MAP_BIT_Ttag {
  unsigned int byte_area    : BFW_NX90_dpm_win2_map_byte_area;    /* Window is byte area.                              */
  unsigned int read_ahead   : BFW_NX90_dpm_win2_map_read_ahead;   /* Read ahead.                                       */
  unsigned int win_map_alt  : BFW_NX90_dpm_win2_map_win_map_alt;  /* Window Alternative Address Mapping Configuration. */
  unsigned int dis_rd_latch : BFW_NX90_dpm_win2_map_dis_rd_latch; /* Window read data latch disable.                   */
  unsigned int reserved1    : BFW_NX90_dpm_win2_map_reserved1;    /* reserved                                          */
  unsigned int win_map      : BFW_NX90_dpm_win2_map_win_map;      /* Window address mapping.                           */
  unsigned int win_page     : BFW_NX90_dpm_win2_map_win_page;     /* Window address page.                              */
} NX90_DPM_WIN2_MAP_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN2_MAP_BIT_T bf;
} NX90_DPM_WIN2_MAP_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win3_end */
/* => DPM Window 3 End Address Configuration Register. */
/*    For detailed information refer to 'dpm_win1_end' register description. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win3_end      0x00000050U
#define Adr_NX90_dpm0_com_dpm_win3_end 0xFF001950U
#define Adr_NX90_dpm1_com_dpm_win3_end 0xFF001A50U
#define DFLT_VAL_NX90_dpm_win3_end     0x00000000U

#define MSK_NX90_dpm_win3_end_win_end         0x001fff80U
#define SRT_NX90_dpm_win3_end_win_end         7
#define DFLT_VAL_NX90_dpm_win3_end_win_end    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win3_end_win_end 0x00000000U

/* all used bits of 'NX90_dpm_win3_end': */
#define MSK_USED_BITS_NX90_dpm_win3_end 0x001fff80U

enum {
  BFW_NX90_dpm_win3_end_reserved1 = 7,  /* [6:0] */
  BFW_NX90_dpm_win3_end_win_end   = 14, /* [20:7] */
  BFW_NX90_dpm_win3_end_reserved2 = 11  /* [31:21] */
};

typedef struct NX90_DPM_WIN3_END_BIT_Ttag {
  unsigned int reserved1 : BFW_NX90_dpm_win3_end_reserved1; /* reserved                                                                     */
  unsigned int win_end   : BFW_NX90_dpm_win3_end_win_end;   /* Window 3 End Address divided by 128. Last external address is win_end*128-1. */
  unsigned int reserved2 : BFW_NX90_dpm_win3_end_reserved2; /* reserved                                                                     */
} NX90_DPM_WIN3_END_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN3_END_BIT_T bf;
} NX90_DPM_WIN3_END_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win3_map */
/* => DPM Window 3 Address Map Configuration Register. */
/*    For detailed information refer to 'dpm_win1_map' register description. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win3_map      0x00000054U
#define Adr_NX90_dpm0_com_dpm_win3_map 0xFF001954U
#define Adr_NX90_dpm1_com_dpm_win3_map 0xFF001A54U
#define DFLT_VAL_NX90_dpm_win3_map     0x01800000U

#define MSK_NX90_dpm_win3_map_byte_area            0x00000001U
#define SRT_NX90_dpm_win3_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win3_map_byte_area       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win3_map_byte_area    0x00000000U
#define MSK_NX90_dpm_win3_map_read_ahead           0x00000002U
#define SRT_NX90_dpm_win3_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win3_map_read_ahead      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win3_map_read_ahead   0x00000000U
#define MSK_NX90_dpm_win3_map_win_map_alt          0x0000000cU
#define SRT_NX90_dpm_win3_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win3_map_win_map_alt     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win3_map_win_map_alt  0x00000000U
#define MSK_NX90_dpm_win3_map_dis_rd_latch         0x00000010U
#define SRT_NX90_dpm_win3_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win3_map_dis_rd_latch    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win3_map_dis_rd_latch 0x00000000U
#define MSK_NX90_dpm_win3_map_win_map              0x000fff80U
#define SRT_NX90_dpm_win3_map_win_map              7
#define DFLT_VAL_NX90_dpm_win3_map_win_map         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win3_map_win_map      0x00000000U
#define MSK_NX90_dpm_win3_map_win_page             0xfff00000U
#define SRT_NX90_dpm_win3_map_win_page             20
#define DFLT_VAL_NX90_dpm_win3_map_win_page        0x01800000U
#define DFLT_BF_VAL_NX90_dpm_win3_map_win_page     0x00000018U

/* all used bits of 'NX90_dpm_win3_map': */
#define MSK_USED_BITS_NX90_dpm_win3_map 0xffffff9fU

enum {
  BFW_NX90_dpm_win3_map_byte_area    = 1,  /* [0] */
  BFW_NX90_dpm_win3_map_read_ahead   = 1,  /* [1] */
  BFW_NX90_dpm_win3_map_win_map_alt  = 2,  /* [3:2] */
  BFW_NX90_dpm_win3_map_dis_rd_latch = 1,  /* [4] */
  BFW_NX90_dpm_win3_map_reserved1    = 2,  /* [6:5] */
  BFW_NX90_dpm_win3_map_win_map      = 13, /* [19:7] */
  BFW_NX90_dpm_win3_map_win_page     = 12  /* [31:20] */
};

typedef struct NX90_DPM_WIN3_MAP_BIT_Ttag {
  unsigned int byte_area    : BFW_NX90_dpm_win3_map_byte_area;    /* Window is byte area.                              */
  unsigned int read_ahead   : BFW_NX90_dpm_win3_map_read_ahead;   /* Read ahead.                                       */
  unsigned int win_map_alt  : BFW_NX90_dpm_win3_map_win_map_alt;  /* Window Alternative Address Mapping Configuration. */
  unsigned int dis_rd_latch : BFW_NX90_dpm_win3_map_dis_rd_latch; /* Window read data latch disable.                   */
  unsigned int reserved1    : BFW_NX90_dpm_win3_map_reserved1;    /* reserved                                          */
  unsigned int win_map      : BFW_NX90_dpm_win3_map_win_map;      /* Window map address.                               */
  unsigned int win_page     : BFW_NX90_dpm_win3_map_win_page;     /* Window address page.                              */
} NX90_DPM_WIN3_MAP_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN3_MAP_BIT_T bf;
} NX90_DPM_WIN3_MAP_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win4_end */
/* => DPM Window 4 End Address Configuration Register. */
/*    For detailed information refer to 'dpm_win1_end' register description. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win4_end      0x00000058U
#define Adr_NX90_dpm0_com_dpm_win4_end 0xFF001958U
#define Adr_NX90_dpm1_com_dpm_win4_end 0xFF001A58U
#define DFLT_VAL_NX90_dpm_win4_end     0x00000000U

#define MSK_NX90_dpm_win4_end_win_end         0x001fff80U
#define SRT_NX90_dpm_win4_end_win_end         7
#define DFLT_VAL_NX90_dpm_win4_end_win_end    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win4_end_win_end 0x00000000U

/* all used bits of 'NX90_dpm_win4_end': */
#define MSK_USED_BITS_NX90_dpm_win4_end 0x001fff80U

enum {
  BFW_NX90_dpm_win4_end_reserved1 = 7,  /* [6:0] */
  BFW_NX90_dpm_win4_end_win_end   = 14, /* [20:7] */
  BFW_NX90_dpm_win4_end_reserved2 = 11  /* [31:21] */
};

typedef struct NX90_DPM_WIN4_END_BIT_Ttag {
  unsigned int reserved1 : BFW_NX90_dpm_win4_end_reserved1; /* reserved                                                                     */
  unsigned int win_end   : BFW_NX90_dpm_win4_end_win_end;   /* Window 4 End Address divided by 128. Last external address is win_end*128-1. */
  unsigned int reserved2 : BFW_NX90_dpm_win4_end_reserved2; /* reserved                                                                     */
} NX90_DPM_WIN4_END_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN4_END_BIT_T bf;
} NX90_DPM_WIN4_END_T;

/* --------------------------------------------------------------------- */
/* Register dpm_win4_map */
/* => DPM Window 4 Address Map Configuration Register. */
/*    For detailed information refer to 'dpm_win1_map' register description. */
/*     */
/*    Note: */
/*      This register can be write-protected by the 'wp_cfg_win'-bit of the 'dpm_win1_map' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_win4_map      0x0000005CU
#define Adr_NX90_dpm0_com_dpm_win4_map 0xFF00195CU
#define Adr_NX90_dpm1_com_dpm_win4_map 0xFF001A5CU
#define DFLT_VAL_NX90_dpm_win4_map     0x01800000U

#define MSK_NX90_dpm_win4_map_byte_area            0x00000001U
#define SRT_NX90_dpm_win4_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win4_map_byte_area       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win4_map_byte_area    0x00000000U
#define MSK_NX90_dpm_win4_map_read_ahead           0x00000002U
#define SRT_NX90_dpm_win4_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win4_map_read_ahead      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win4_map_read_ahead   0x00000000U
#define MSK_NX90_dpm_win4_map_win_map_alt          0x0000000cU
#define SRT_NX90_dpm_win4_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win4_map_win_map_alt     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win4_map_win_map_alt  0x00000000U
#define MSK_NX90_dpm_win4_map_dis_rd_latch         0x00000010U
#define SRT_NX90_dpm_win4_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win4_map_dis_rd_latch    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win4_map_dis_rd_latch 0x00000000U
#define MSK_NX90_dpm_win4_map_win_map              0x000fff80U
#define SRT_NX90_dpm_win4_map_win_map              7
#define DFLT_VAL_NX90_dpm_win4_map_win_map         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_win4_map_win_map      0x00000000U
#define MSK_NX90_dpm_win4_map_win_page             0xfff00000U
#define SRT_NX90_dpm_win4_map_win_page             20
#define DFLT_VAL_NX90_dpm_win4_map_win_page        0x01800000U
#define DFLT_BF_VAL_NX90_dpm_win4_map_win_page     0x00000018U

/* all used bits of 'NX90_dpm_win4_map': */
#define MSK_USED_BITS_NX90_dpm_win4_map 0xffffff9fU

enum {
  BFW_NX90_dpm_win4_map_byte_area    = 1,  /* [0] */
  BFW_NX90_dpm_win4_map_read_ahead   = 1,  /* [1] */
  BFW_NX90_dpm_win4_map_win_map_alt  = 2,  /* [3:2] */
  BFW_NX90_dpm_win4_map_dis_rd_latch = 1,  /* [4] */
  BFW_NX90_dpm_win4_map_reserved1    = 2,  /* [6:5] */
  BFW_NX90_dpm_win4_map_win_map      = 13, /* [19:7] */
  BFW_NX90_dpm_win4_map_win_page     = 12  /* [31:20] */
};

typedef struct NX90_DPM_WIN4_MAP_BIT_Ttag {
  unsigned int byte_area    : BFW_NX90_dpm_win4_map_byte_area;    /* Window is byte area.                              */
  unsigned int read_ahead   : BFW_NX90_dpm_win4_map_read_ahead;   /* Read ahead.                                       */
  unsigned int win_map_alt  : BFW_NX90_dpm_win4_map_win_map_alt;  /* Window Alternative Address Mapping Configuration. */
  unsigned int dis_rd_latch : BFW_NX90_dpm_win4_map_dis_rd_latch; /* Window read data latch disable.                   */
  unsigned int reserved1    : BFW_NX90_dpm_win4_map_reserved1;    /* reserved                                          */
  unsigned int win_map      : BFW_NX90_dpm_win4_map_win_map;      /* Window map address.                               */
  unsigned int win_page     : BFW_NX90_dpm_win4_map_win_page;     /* Window address page.                              */
} NX90_DPM_WIN4_MAP_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_WIN4_MAP_BIT_T bf;
} NX90_DPM_WIN4_MAP_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_raw0 */
/* => DPM Raw (before masking) IRQ Status Register. */
/*    If a bit is set, the related interrupt is asserted. */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*     */
/*    Important: There are two completely independent sets of IRQ registers: */
/*       IRQ register-set 1: 'dpm_irq_raw' (and related registers e.g. 'dpm_irq_host_dirq_*' registers). */
/*       IRQ register-set 2: 'dpm_firmware_irq_* registers' (netx50 compatible register set: DPM_HOST_INT_EN0,2 DPM_HOST_INT_STA0,2). */
/*       Programming (masking or clearing IRQs) of one register-set has no impact to the other register-set even if some IRQs */
/*       can be found in both sets (e.g. com0). */
/*     */
/*    Note: */
/*       The 'dpm_sw' IRQ can be controlled by the 'dpm_sw_irq' register for each */
/*       IRQ target differently, i.e. there are 4 different 'dpm_sw' IRQs internally, one */
/*       for each IRQ target. However, 'dpm_sw' will be set inside the 'dpm_irq_raw' register here */
/*       when the 'dpm_sw' is activated for at least one IRQ target. But each IRQ target */
/*       obtains only the 'dpm_sw' IRQ state programmed for this target inside the 'dpm_sw_irq' */
/*       register. For an example view description of 'dpm_sw_irq' register. */
/*     */
/*    Note: */
/*        The 'test' function is obsolete since netX51/52, the 'dpm_sw' bit can be used instead of this. */
/*     */
/*    Note: */
/*        The 'firmware' IRQ can be used to flag handshake and netX firmware system status events to the */
/*        host. Firmware IRQ generation can be controlled by dpm_firmware_irq_mask register. Detailed */
/*        firmware IRQ status can be read from dpm_firmware_irq_raw register. */
/*     */
/*    Note: */
/*        For all netX modules which are capable generating IRQs for ARM and xPIC, ARM-IRQ is taken here. */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_raw0      0x00000080U
#define Adr_NX90_dpm0_com_dpm_irq_raw0 0xFF001980U
#define Adr_NX90_dpm1_com_dpm_irq_raw0 0xFF001A80U

#define MSK_NX90_dpm_irq_raw0_dpm_sw        0x00000001U
#define SRT_NX90_dpm_irq_raw0_dpm_sw        0
#define MSK_NX90_dpm_irq_raw0_dpm_err       0x00000002U
#define SRT_NX90_dpm_irq_raw0_dpm_err       1
#define MSK_NX90_dpm_irq_raw0_firmware      0x00000004U
#define SRT_NX90_dpm_irq_raw0_firmware      2
#define MSK_NX90_dpm_irq_raw0_host_hsc0     0x00000100U
#define SRT_NX90_dpm_irq_raw0_host_hsc0     8
#define MSK_NX90_dpm_irq_raw0_host_hsc1     0x00000200U
#define SRT_NX90_dpm_irq_raw0_host_hsc1     9
#define MSK_NX90_dpm_irq_raw0_host_hsc2     0x00000400U
#define SRT_NX90_dpm_irq_raw0_host_hsc2     10
#define MSK_NX90_dpm_irq_raw0_host_hsc3     0x00000800U
#define SRT_NX90_dpm_irq_raw0_host_hsc3     11
#define MSK_NX90_dpm_irq_raw0_host_hsc4     0x00001000U
#define SRT_NX90_dpm_irq_raw0_host_hsc4     12
#define MSK_NX90_dpm_irq_raw0_host_hsc5     0x00002000U
#define SRT_NX90_dpm_irq_raw0_host_hsc5     13
#define MSK_NX90_dpm_irq_raw0_host_hsc6     0x00004000U
#define SRT_NX90_dpm_irq_raw0_host_hsc6     14
#define MSK_NX90_dpm_irq_raw0_host_hsc7     0x00008000U
#define SRT_NX90_dpm_irq_raw0_host_hsc7     15
#define MSK_NX90_dpm_irq_raw0_host_hsc8to15 0x00010000U
#define SRT_NX90_dpm_irq_raw0_host_hsc8to15 16

/* all used bits of 'NX90_dpm_irq_raw0': */
#define MSK_USED_BITS_NX90_dpm_irq_raw0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_raw0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_raw0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_raw0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_raw0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_raw0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_raw0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_raw0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_raw0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_raw0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_raw0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_raw0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_raw0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_raw0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_raw0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_RAW0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_raw0_dpm_sw;        /* raw software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt   */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_raw0_dpm_err;       /* raw DPM access error IRQ of this DPM module interrupt                                 */
  unsigned int firmware      : BFW_NX90_dpm_irq_raw0_firmware;      /* raw combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt     */
  unsigned int reserved1     : BFW_NX90_dpm_irq_raw0_reserved1;     /* reserved                                                                              */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_raw0_host_hsc0;     /* raw IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_raw0_host_hsc1;     /* raw IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_raw0_host_hsc2;     /* raw IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_raw0_host_hsc3;     /* raw IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_raw0_host_hsc4;     /* raw IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_raw0_host_hsc5;     /* raw IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_raw0_host_hsc6;     /* raw IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_raw0_host_hsc7;     /* raw IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt        */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_raw0_host_hsc8to15; /* raw IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt */
  unsigned int reserved2     : BFW_NX90_dpm_irq_raw0_reserved2;     /* reserved                                                                              */
} NX90_DPM_IRQ_RAW0_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_IRQ_RAW0_BIT_T bf;
} NX90_DPM_IRQ_RAW0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_raw1 */
/* => DPM Raw (before masking) IRQ Status Register. */
/*    If a bit is set, the related interrupt is asserted. */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*     */
/*    Important: There are two completely independent sets of IRQ registers: */
/*       IRQ register-set 1: 'dpm_irq_raw' (and related registers e.g. 'dpm_irq_host_dirq_*' registers). */
/*       IRQ register-set 2: 'dpm_firmware_irq_* registers' (netx50 compatible register set: DPM_HOST_INT_EN0,2 DPM_HOST_INT_STA0,2). */
/*       Programming (masking or clearing IRQs) of one register-set has no impact to the other register-set even if some IRQs */
/*       can be found in both sets (e.g. com0). */
/*     */
/*    Note: */
/*       The 'dpm_sw' IRQ can be controlled by the 'dpm_sw_irq' register for each */
/*       IRQ target differently, i.e. there are 4 different 'dpm_sw' IRQs internally, one */
/*       for each IRQ target. However, 'dpm_sw' will be set inside the 'dpm_irq_raw' register here */
/*       when the 'dpm_sw' is activated for at least one IRQ target. But each IRQ target */
/*       obtains only the 'dpm_sw' IRQ state programmed for this target inside the 'dpm_sw_irq' */
/*       register. For an example view description of 'dpm_sw_irq' register. */
/*     */
/*    Note: */
/*        The 'test' function is obsolete since netX51/52, the 'dpm_sw' bit can be used instead of this. */
/*     */
/*    Note: */
/*        The 'firmware' IRQ can be used to flag handshake and netX firmware system status events to the */
/*        host. Firmware IRQ generation can be controlled by dpm_firmware_irq_mask register. Detailed */
/*        firmware IRQ status can be read from dpm_firmware_irq_raw register. */
/*     */
/*    Note: */
/*        For all netX modules which are capable generating IRQs for ARM and xPIC, ARM-IRQ is taken here. */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_raw1      0x00000084U
#define Adr_NX90_dpm0_com_dpm_irq_raw1 0xFF001984U
#define Adr_NX90_dpm1_com_dpm_irq_raw1 0xFF001A84U

#define MSK_NX90_dpm_irq_raw1_ARM_TIMER           0x00000001U
#define SRT_NX90_dpm_irq_raw1_ARM_TIMER           0
#define MSK_NX90_dpm_irq_raw1_timer_com_systime_s 0x00000002U
#define SRT_NX90_dpm_irq_raw1_timer_com_systime_s 1
#define MSK_NX90_dpm_irq_raw1_wdg_com             0x00000004U
#define SRT_NX90_dpm_irq_raw1_wdg_com             2
#define MSK_NX90_dpm_irq_raw1_dmac_com            0x00000008U
#define SRT_NX90_dpm_irq_raw1_dmac_com            3
#define MSK_NX90_dpm_irq_raw1_mcp_com             0x00000010U
#define SRT_NX90_dpm_irq_raw1_mcp_com             4
#define MSK_NX90_dpm_irq_raw1_uart                0x00000020U
#define SRT_NX90_dpm_irq_raw1_uart                5
#define MSK_NX90_dpm_irq_raw1_i2c0_com            0x00000040U
#define SRT_NX90_dpm_irq_raw1_i2c0_com            6
#define MSK_NX90_dpm_irq_raw1_i2c1_com            0x00000080U
#define SRT_NX90_dpm_irq_raw1_i2c1_com            7
#define MSK_NX90_dpm_irq_raw1_ecc_com             0x00000100U
#define SRT_NX90_dpm_irq_raw1_ecc_com             8
#define MSK_NX90_dpm_irq_raw1_xpic_debug_com      0x00000200U
#define SRT_NX90_dpm_irq_raw1_xpic_debug_com      9
#define MSK_NX90_dpm_irq_raw1_wdg_xpic_com_arm    0x00000400U
#define SRT_NX90_dpm_irq_raw1_wdg_xpic_com_arm    10
#define MSK_NX90_dpm_irq_raw1_nfifo_arm_com       0x00000800U
#define SRT_NX90_dpm_irq_raw1_nfifo_arm_com       11
#define MSK_NX90_dpm_irq_raw1_com0                0x00001000U
#define SRT_NX90_dpm_irq_raw1_com0                12
#define MSK_NX90_dpm_irq_raw1_com1                0x00002000U
#define SRT_NX90_dpm_irq_raw1_com1                13
#define MSK_NX90_dpm_irq_raw1_msync0              0x00004000U
#define SRT_NX90_dpm_irq_raw1_msync0              14
#define MSK_NX90_dpm_irq_raw1_msync1              0x00008000U
#define SRT_NX90_dpm_irq_raw1_msync1              15
#define MSK_NX90_dpm_irq_raw1_trigger_lt          0x00010000U
#define SRT_NX90_dpm_irq_raw1_trigger_lt          16
#define MSK_NX90_dpm_irq_raw1_lvds2mii0_com       0x00020000U
#define SRT_NX90_dpm_irq_raw1_lvds2mii0_com       17
#define MSK_NX90_dpm_irq_raw1_lvds2mii1_com       0x00040000U
#define SRT_NX90_dpm_irq_raw1_lvds2mii1_com       18
#define MSK_NX90_dpm_irq_raw1_sqi                 0x00080000U
#define SRT_NX90_dpm_irq_raw1_sqi                 19
#define MSK_NX90_dpm_irq_raw1_hif_pio_arm         0x00100000U
#define SRT_NX90_dpm_irq_raw1_hif_pio_arm         20
#define MSK_NX90_dpm_irq_raw1_eth                 0x00200000U
#define SRT_NX90_dpm_irq_raw1_eth                 21
#define MSK_NX90_dpm_irq_raw1_madc_seq0           0x00400000U
#define SRT_NX90_dpm_irq_raw1_madc_seq0           22
#define MSK_NX90_dpm_irq_raw1_madc_seq1           0x00800000U
#define SRT_NX90_dpm_irq_raw1_madc_seq1           23
#define MSK_NX90_dpm_irq_raw1_madc_seq2           0x01000000U
#define SRT_NX90_dpm_irq_raw1_madc_seq2           24
#define MSK_NX90_dpm_irq_raw1_madc_seq3           0x02000000U
#define SRT_NX90_dpm_irq_raw1_madc_seq3           25
#define MSK_NX90_dpm_irq_raw1_GPIO_COM            0x04000000U
#define SRT_NX90_dpm_irq_raw1_GPIO_COM            26
#define MSK_NX90_dpm_irq_raw1_CRYPT               0x08000000U
#define SRT_NX90_dpm_irq_raw1_CRYPT               27
#define MSK_NX90_dpm_irq_raw1_bod                 0x10000000U
#define SRT_NX90_dpm_irq_raw1_bod                 28
#define MSK_NX90_dpm_irq_raw1_clksup              0x20000000U
#define SRT_NX90_dpm_irq_raw1_clksup              29
#define MSK_NX90_dpm_irq_raw1_phy                 0x40000000U
#define SRT_NX90_dpm_irq_raw1_phy                 30

/* all used bits of 'NX90_dpm_irq_raw1': */
#define MSK_USED_BITS_NX90_dpm_irq_raw1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_raw1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_raw1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_raw1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_raw1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_raw1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_raw1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_raw1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_raw1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_raw1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_raw1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_raw1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_raw1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_raw1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_raw1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_raw1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_raw1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_raw1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_raw1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_raw1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_raw1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_raw1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_raw1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_raw1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_raw1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_raw1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_raw1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_raw1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_raw1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_raw1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_raw1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_raw1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_raw1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_RAW1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_raw1_ARM_TIMER;           /* raw combined IRQ from module ARM_TIMER (only DPM0) interrupt                 */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_raw1_timer_com_systime_s; /* raw IRQ from module ARM_TIMER (only DPM0) interrupt                          */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_raw1_wdg_com;             /* raw IRQ from module WDG_SYS (only DPM0) interrupt                            */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_raw1_dmac_com;            /* raw IRQ from module DMAC (only DPM0) interrupt                               */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_raw1_mcp_com;             /* raw IRQ from module MULTI_CPU_PING (only DPM0) interrupt                     */
  unsigned int uart                : BFW_NX90_dpm_irq_raw1_uart;                /* raw IRQ from module UART_PL010H (only DPM0) interrupt                        */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_raw1_i2c0_com;            /* raw IRQ from module I2C_ARM_COM0 (only DPM0) interrupt                       */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_raw1_i2c1_com;            /* raw IRQ from module I2C_ARM_COM1 (only DPM0) interrupt                       */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_raw1_ecc_com;             /* raw combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_raw1_xpic_debug_com;      /* raw IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt                     */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_raw1_wdg_xpic_com_arm;    /* raw IRQ from module XPIC_WDG_COM (only DPM0) interrupt                       */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_raw1_nfifo_arm_com;       /* raw IRQ from module OSAC (only DPM0) interrupt                               */
  unsigned int com0                : BFW_NX90_dpm_irq_raw1_com0;                /* raw IRQ from module XC (only DPM0) interrupt                                 */
  unsigned int com1                : BFW_NX90_dpm_irq_raw1_com1;                /* raw IRQ from module XC (only DPM0) interrupt                                 */
  unsigned int msync0              : BFW_NX90_dpm_irq_raw1_msync0;              /* raw IRQ from module XC (only DPM0) interrupt                                 */
  unsigned int msync1              : BFW_NX90_dpm_irq_raw1_msync1;              /* raw IRQ from module XC (only DPM0) interrupt                                 */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_raw1_trigger_lt;          /* raw IRQ from module TRIGGER_LT (only DPM0) interrupt                         */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_raw1_lvds2mii0_com;       /* raw IRQ from module LVDS (only DPM0) interrupt                               */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_raw1_lvds2mii1_com;       /* raw IRQ from module LVDS (only DPM0) interrupt                               */
  unsigned int sqi                 : BFW_NX90_dpm_irq_raw1_sqi;                 /* raw IRQ from module SQI (only DPM0) interrupt                                */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_raw1_hif_pio_arm;         /* raw IRQ from module HIF_IO_CTRL (only DPM0) interrupt                        */
  unsigned int eth                 : BFW_NX90_dpm_irq_raw1_eth;                 /* raw IRQ from module FETH (only DPM0) interrupt                               */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_raw1_madc_seq0;           /* raw IRQ from module MADC (only DPM0) interrupt                               */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_raw1_madc_seq1;           /* raw IRQ from module MADC (only DPM0) interrupt                               */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_raw1_madc_seq2;           /* raw IRQ from module MADC (only DPM0) interrupt                               */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_raw1_madc_seq3;           /* raw IRQ from module MADC (only DPM0) interrupt                               */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_raw1_GPIO_COM;            /* raw combined IRQ from module GPIO_COM (only DPM0) interrupt                  */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_raw1_CRYPT;               /* raw combined IRQ from module CRYPT (only DPM0) interrupt                     */
  unsigned int bod                 : BFW_NX90_dpm_irq_raw1_bod;                 /* raw Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt      */
  unsigned int clksup              : BFW_NX90_dpm_irq_raw1_clksup;              /* raw IRQ from module CLKSUP (only DPM0) interrupt                             */
  unsigned int phy                 : BFW_NX90_dpm_irq_raw1_phy;                 /* raw IRQ from module INT_PHY_CFG (only DPM0) interrupt                        */
  unsigned int reserved1           : BFW_NX90_dpm_irq_raw1_reserved1;           /* reserved                                                                     */
} NX90_DPM_IRQ_RAW1_BIT_T;

typedef union {
  uint32_t                val;
  NX90_DPM_IRQ_RAW1_BIT_T bf;
} NX90_DPM_IRQ_RAW1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_sirq_mask_set0 */
/* => DPM Interrupt Mask Register for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Write access with '1' sets related interrupt mask bits (enables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_set0      0x00000088U
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_set0 0xFF001988U
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_set0 0xFF001A88U
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0     0x00000000U

#define MSK_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw                0x00000001U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw           0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw        0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_dpm_err               0x00000002U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_err          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_err       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_firmware              0x00000004U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_firmware         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_firmware      0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0             0x00000100U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1             0x00000200U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2             0x00000400U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3             0x00000800U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4             0x00001000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5             0x00002000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6             0x00004000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7             0x00008000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15         0x00010000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_set0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_set0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_host_sirq_mask_set0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_HOST_SIRQ_MASK_SET0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw;        /* set software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_host_sirq_mask_set0_dpm_err;       /* set DPM access error IRQ of this DPM module interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int firmware      : BFW_NX90_dpm_irq_host_sirq_mask_set0_firmware;      /* set combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved1     : BFW_NX90_dpm_irq_host_sirq_mask_set0_reserved1;     /* reserved */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0;     /* set IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1;     /* set IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2;     /* set IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3;     /* set IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4;     /* set IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5;     /* set IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6;     /* set IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7;     /* set IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15; /* set IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved2     : BFW_NX90_dpm_irq_host_sirq_mask_set0_reserved2;     /* reserved */
} NX90_DPM_IRQ_HOST_SIRQ_MASK_SET0_BIT_T;

typedef union {
  uint32_t                               val;
  NX90_DPM_IRQ_HOST_SIRQ_MASK_SET0_BIT_T bf;
} NX90_DPM_IRQ_HOST_SIRQ_MASK_SET0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_sirq_mask_set1 */
/* => DPM Interrupt Mask Register for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Write access with '1' sets related interrupt mask bits (enables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_set1      0x0000008CU
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_set1 0xFF00198CU
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_set1 0xFF001A8CU
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1     0x00000000U

#define MSK_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER                   0x00000001U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s         0x00000002U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_wdg_com                     0x00000004U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_com             0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_dmac_com                    0x00000008U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_dmac_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_dmac_com            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_mcp_com                     0x00000010U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_mcp_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_mcp_com             0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_uart                        0x00000020U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_uart                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_uart                0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com                    0x00000040U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com                    0x00000080U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_ecc_com                     0x00000100U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_ecc_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_ecc_com             0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com              0x00000200U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com      0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm            0x00000400U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm    0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com               0x00000800U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_com0                        0x00001000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_com0                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_com0                0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_com1                        0x00002000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_com1                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_com1                0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_msync0                      0x00004000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync0                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync0              0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_msync1                      0x00008000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync1                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync1              0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt                  0x00010000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt             0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt          0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com               0x00020000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com               0x00040000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_sqi                         0x00080000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_sqi                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_sqi                 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm                 0x00100000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm         0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_eth                         0x00200000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_eth                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_eth                 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0                   0x00400000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1                   0x00800000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2                   0x01000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3                   0x02000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM                    0x04000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_CRYPT                       0x08000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_CRYPT                  0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_CRYPT               0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_bod                         0x10000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_bod                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_bod                 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_clksup                      0x20000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_clksup                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_clksup              0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_phy                         0x40000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_phy                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_phy                 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_set1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_set1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_host_sirq_mask_set1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_HOST_SIRQ_MASK_SET1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER;           /* set combined IRQ from module ARM_TIMER (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s; /* set IRQ from module ARM_TIMER (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_host_sirq_mask_set1_wdg_com;             /* set IRQ from module WDG_SYS (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_host_sirq_mask_set1_dmac_com;            /* set IRQ from module DMAC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_host_sirq_mask_set1_mcp_com;             /* set IRQ from module MULTI_CPU_PING (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int uart                : BFW_NX90_dpm_irq_host_sirq_mask_set1_uart;                /* set IRQ from module UART_PL010H (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com;            /* set IRQ from module I2C_ARM_COM0 (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com;            /* set IRQ from module I2C_ARM_COM1 (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_host_sirq_mask_set1_ecc_com;             /* set combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com;      /* set IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm;    /* set IRQ from module XPIC_WDG_COM (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com;       /* set IRQ from module OSAC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int com0                : BFW_NX90_dpm_irq_host_sirq_mask_set1_com0;                /* set IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int com1                : BFW_NX90_dpm_irq_host_sirq_mask_set1_com1;                /* set IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int msync0              : BFW_NX90_dpm_irq_host_sirq_mask_set1_msync0;              /* set IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int msync1              : BFW_NX90_dpm_irq_host_sirq_mask_set1_msync1;              /* set IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt;          /* set IRQ from module TRIGGER_LT (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com;       /* set IRQ from module LVDS (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com;       /* set IRQ from module LVDS (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int sqi                 : BFW_NX90_dpm_irq_host_sirq_mask_set1_sqi;                 /* set IRQ from module SQI (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm;         /* set IRQ from module HIF_IO_CTRL (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int eth                 : BFW_NX90_dpm_irq_host_sirq_mask_set1_eth;                 /* set IRQ from module FETH (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0;           /* set IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1;           /* set IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2;           /* set IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3;           /* set IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM;            /* set combined IRQ from module GPIO_COM (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_host_sirq_mask_set1_CRYPT;               /* set combined IRQ from module CRYPT (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int bod                 : BFW_NX90_dpm_irq_host_sirq_mask_set1_bod;                 /* set Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int clksup              : BFW_NX90_dpm_irq_host_sirq_mask_set1_clksup;              /* set IRQ from module CLKSUP (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int phy                 : BFW_NX90_dpm_irq_host_sirq_mask_set1_phy;                 /* set IRQ from module INT_PHY_CFG (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved1           : BFW_NX90_dpm_irq_host_sirq_mask_set1_reserved1;           /* reserved */
} NX90_DPM_IRQ_HOST_SIRQ_MASK_SET1_BIT_T;

typedef union {
  uint32_t                               val;
  NX90_DPM_IRQ_HOST_SIRQ_MASK_SET1_BIT_T bf;
} NX90_DPM_IRQ_HOST_SIRQ_MASK_SET1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_sirq_mask_reset0 */
/* => DPM Interrupt Mask Reset Register for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Write access with '1' resets related interrupt mask bits (disables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_reset0      0x00000090U
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_reset0 0xFF001990U
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_reset0 0xFF001A90U
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0     0x00000000U

#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw                0x00000001U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw           0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw        0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err               0x00000002U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_firmware              0x00000004U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_firmware         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_firmware      0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0             0x00000100U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1             0x00000200U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2             0x00000400U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3             0x00000800U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4             0x00001000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5             0x00002000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6             0x00004000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7             0x00008000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7     0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15         0x00010000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_reset0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_reset0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw;        /* reset software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err;       /* reset DPM access error IRQ of this DPM module interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int firmware      : BFW_NX90_dpm_irq_host_sirq_mask_reset0_firmware;      /* reset combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved1     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_reserved1;     /* reserved */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0;     /* reset IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1;     /* reset IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2;     /* reset IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3;     /* reset IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4;     /* reset IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5;     /* reset IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6;     /* reset IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7;     /* reset IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15; /* reset IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt mask for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved2     : BFW_NX90_dpm_irq_host_sirq_mask_reset0_reserved2;     /* reserved */
} NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET0_BIT_T;

typedef union {
  uint32_t                                 val;
  NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET0_BIT_T bf;
} NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_sirq_mask_reset1 */
/* => DPM Interrupt Mask Reset Register for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Write access with '1' resets related interrupt mask bits (disables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_reset1      0x00000094U
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_reset1 0xFF001994U
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_reset1 0xFF001A94U
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1     0x00000000U

#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER                   0x00000001U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s         0x00000002U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com                     0x00000004U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com             0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com                    0x00000008U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com                     0x00000010U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com             0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_uart                        0x00000020U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_uart                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_uart                0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com                    0x00000040U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com                    0x00000080U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com                     0x00000100U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com             0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com              0x00000200U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com      0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm            0x00000400U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm    0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com               0x00000800U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_com0                        0x00001000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com0                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com0                0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_com1                        0x00002000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com1                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com1                0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_msync0                      0x00004000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync0                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync0              0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_msync1                      0x00008000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync1                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync1              0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt                  0x00010000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt             0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt          0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com               0x00020000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com               0x00040000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com       0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_sqi                         0x00080000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_sqi                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_sqi                 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm                 0x00100000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm         0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_eth                         0x00200000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_eth                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_eth                 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0                   0x00400000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1                   0x00800000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2                   0x01000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3                   0x02000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3           0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM                    0x04000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM            0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT                       0x08000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT                  0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT               0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_bod                         0x10000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_bod                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_bod                 0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_clksup                      0x20000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_clksup                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_clksup              0x00000000U
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_phy                         0x40000000U
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_phy                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_phy                 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_reset1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_reset1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_host_sirq_mask_reset1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER;           /* reset combined IRQ from module ARM_TIMER (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s; /* reset IRQ from module ARM_TIMER (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com;             /* reset IRQ from module WDG_SYS (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com;            /* reset IRQ from module DMAC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com;             /* reset IRQ from module MULTI_CPU_PING (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int uart                : BFW_NX90_dpm_irq_host_sirq_mask_reset1_uart;                /* reset IRQ from module UART_PL010H (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com;            /* reset IRQ from module I2C_ARM_COM0 (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com;            /* reset IRQ from module I2C_ARM_COM1 (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com;             /* reset combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com;      /* reset IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm;    /* reset IRQ from module XPIC_WDG_COM (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com;       /* reset IRQ from module OSAC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int com0                : BFW_NX90_dpm_irq_host_sirq_mask_reset1_com0;                /* reset IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int com1                : BFW_NX90_dpm_irq_host_sirq_mask_reset1_com1;                /* reset IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int msync0              : BFW_NX90_dpm_irq_host_sirq_mask_reset1_msync0;              /* reset IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int msync1              : BFW_NX90_dpm_irq_host_sirq_mask_reset1_msync1;              /* reset IRQ from module XC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt;          /* reset IRQ from module TRIGGER_LT (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com;       /* reset IRQ from module LVDS (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com;       /* reset IRQ from module LVDS (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int sqi                 : BFW_NX90_dpm_irq_host_sirq_mask_reset1_sqi;                 /* reset IRQ from module SQI (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm;         /* reset IRQ from module HIF_IO_CTRL (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int eth                 : BFW_NX90_dpm_irq_host_sirq_mask_reset1_eth;                 /* reset IRQ from module FETH (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0;           /* reset IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1;           /* reset IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2;           /* reset IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3;           /* reset IRQ from module MADC (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM;            /* reset combined IRQ from module GPIO_COM (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT;               /* reset combined IRQ from module CRYPT (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int bod                 : BFW_NX90_dpm_irq_host_sirq_mask_reset1_bod;                 /* reset Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int clksup              : BFW_NX90_dpm_irq_host_sirq_mask_reset1_clksup;              /* reset IRQ from module CLKSUP (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int phy                 : BFW_NX90_dpm_irq_host_sirq_mask_reset1_phy;                 /* reset IRQ from module INT_PHY_CFG (only DPM0) interrupt mask for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved1           : BFW_NX90_dpm_irq_host_sirq_mask_reset1_reserved1;           /* reserved */
} NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET1_BIT_T;

typedef union {
  uint32_t                                 val;
  NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET1_BIT_T bf;
} NX90_DPM_IRQ_HOST_SIRQ_MASK_RESET1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_sirq_masked0 */
/* => DPM Masked Interrupt Status Register for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    A bit is set, when the related mask bit is set in 'dpm_irq_host_sirq_mask'-register and the related interrupt is asserted. */
/*    IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) is asserted if at least one bit is set here. */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_sirq_masked0      0x00000098U
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_masked0 0xFF001998U
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_masked0 0xFF001A98U

#define MSK_NX90_dpm_irq_host_sirq_masked0_dpm_sw        0x00000001U
#define SRT_NX90_dpm_irq_host_sirq_masked0_dpm_sw        0
#define MSK_NX90_dpm_irq_host_sirq_masked0_dpm_err       0x00000002U
#define SRT_NX90_dpm_irq_host_sirq_masked0_dpm_err       1
#define MSK_NX90_dpm_irq_host_sirq_masked0_firmware      0x00000004U
#define SRT_NX90_dpm_irq_host_sirq_masked0_firmware      2
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc0     0x00000100U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc0     8
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc1     0x00000200U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc1     9
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc2     0x00000400U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc2     10
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc3     0x00000800U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc3     11
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc4     0x00001000U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc4     12
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc5     0x00002000U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc5     13
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc6     0x00004000U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc6     14
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc7     0x00008000U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc7     15
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc8to15 0x00010000U
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc8to15 16

/* all used bits of 'NX90_dpm_irq_host_sirq_masked0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_masked0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_host_sirq_masked0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_host_sirq_masked0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_host_sirq_masked0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_host_sirq_masked0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_host_sirq_masked0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_HOST_SIRQ_MASKED0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_host_sirq_masked0_dpm_sw;        /* masked software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_host_sirq_masked0_dpm_err;       /* masked DPM access error IRQ of this DPM module interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int firmware      : BFW_NX90_dpm_irq_host_sirq_masked0_firmware;      /* masked combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved1     : BFW_NX90_dpm_irq_host_sirq_masked0_reserved1;     /* reserved */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc0;     /* masked IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc1;     /* masked IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc2;     /* masked IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc3;     /* masked IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc4;     /* masked IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc5;     /* masked IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc6;     /* masked IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc7;     /* masked IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_host_sirq_masked0_host_hsc8to15; /* masked IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved2     : BFW_NX90_dpm_irq_host_sirq_masked0_reserved2;     /* reserved */
} NX90_DPM_IRQ_HOST_SIRQ_MASKED0_BIT_T;

typedef union {
  uint32_t                             val;
  NX90_DPM_IRQ_HOST_SIRQ_MASKED0_BIT_T bf;
} NX90_DPM_IRQ_HOST_SIRQ_MASKED0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_sirq_masked1 */
/* => DPM Masked Interrupt Status Register for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ). */
/*    A bit is set, when the related mask bit is set in 'dpm_irq_host_sirq_mask'-register and the related interrupt is asserted. */
/*    IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) is asserted if at least one bit is set here. */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_sirq_masked1      0x0000009CU
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_masked1 0xFF00199CU
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_masked1 0xFF001A9CU

#define MSK_NX90_dpm_irq_host_sirq_masked1_ARM_TIMER           0x00000001U
#define SRT_NX90_dpm_irq_host_sirq_masked1_ARM_TIMER           0
#define MSK_NX90_dpm_irq_host_sirq_masked1_timer_com_systime_s 0x00000002U
#define SRT_NX90_dpm_irq_host_sirq_masked1_timer_com_systime_s 1
#define MSK_NX90_dpm_irq_host_sirq_masked1_wdg_com             0x00000004U
#define SRT_NX90_dpm_irq_host_sirq_masked1_wdg_com             2
#define MSK_NX90_dpm_irq_host_sirq_masked1_dmac_com            0x00000008U
#define SRT_NX90_dpm_irq_host_sirq_masked1_dmac_com            3
#define MSK_NX90_dpm_irq_host_sirq_masked1_mcp_com             0x00000010U
#define SRT_NX90_dpm_irq_host_sirq_masked1_mcp_com             4
#define MSK_NX90_dpm_irq_host_sirq_masked1_uart                0x00000020U
#define SRT_NX90_dpm_irq_host_sirq_masked1_uart                5
#define MSK_NX90_dpm_irq_host_sirq_masked1_i2c0_com            0x00000040U
#define SRT_NX90_dpm_irq_host_sirq_masked1_i2c0_com            6
#define MSK_NX90_dpm_irq_host_sirq_masked1_i2c1_com            0x00000080U
#define SRT_NX90_dpm_irq_host_sirq_masked1_i2c1_com            7
#define MSK_NX90_dpm_irq_host_sirq_masked1_ecc_com             0x00000100U
#define SRT_NX90_dpm_irq_host_sirq_masked1_ecc_com             8
#define MSK_NX90_dpm_irq_host_sirq_masked1_xpic_debug_com      0x00000200U
#define SRT_NX90_dpm_irq_host_sirq_masked1_xpic_debug_com      9
#define MSK_NX90_dpm_irq_host_sirq_masked1_wdg_xpic_com_arm    0x00000400U
#define SRT_NX90_dpm_irq_host_sirq_masked1_wdg_xpic_com_arm    10
#define MSK_NX90_dpm_irq_host_sirq_masked1_nfifo_arm_com       0x00000800U
#define SRT_NX90_dpm_irq_host_sirq_masked1_nfifo_arm_com       11
#define MSK_NX90_dpm_irq_host_sirq_masked1_com0                0x00001000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_com0                12
#define MSK_NX90_dpm_irq_host_sirq_masked1_com1                0x00002000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_com1                13
#define MSK_NX90_dpm_irq_host_sirq_masked1_msync0              0x00004000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_msync0              14
#define MSK_NX90_dpm_irq_host_sirq_masked1_msync1              0x00008000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_msync1              15
#define MSK_NX90_dpm_irq_host_sirq_masked1_trigger_lt          0x00010000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_trigger_lt          16
#define MSK_NX90_dpm_irq_host_sirq_masked1_lvds2mii0_com       0x00020000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_lvds2mii0_com       17
#define MSK_NX90_dpm_irq_host_sirq_masked1_lvds2mii1_com       0x00040000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_lvds2mii1_com       18
#define MSK_NX90_dpm_irq_host_sirq_masked1_sqi                 0x00080000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_sqi                 19
#define MSK_NX90_dpm_irq_host_sirq_masked1_hif_pio_arm         0x00100000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_hif_pio_arm         20
#define MSK_NX90_dpm_irq_host_sirq_masked1_eth                 0x00200000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_eth                 21
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq0           0x00400000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq0           22
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq1           0x00800000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq1           23
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq2           0x01000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq2           24
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq3           0x02000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq3           25
#define MSK_NX90_dpm_irq_host_sirq_masked1_GPIO_COM            0x04000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_GPIO_COM            26
#define MSK_NX90_dpm_irq_host_sirq_masked1_CRYPT               0x08000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_CRYPT               27
#define MSK_NX90_dpm_irq_host_sirq_masked1_bod                 0x10000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_bod                 28
#define MSK_NX90_dpm_irq_host_sirq_masked1_clksup              0x20000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_clksup              29
#define MSK_NX90_dpm_irq_host_sirq_masked1_phy                 0x40000000U
#define SRT_NX90_dpm_irq_host_sirq_masked1_phy                 30

/* all used bits of 'NX90_dpm_irq_host_sirq_masked1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_masked1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_host_sirq_masked1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_host_sirq_masked1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_host_sirq_masked1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_host_sirq_masked1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_host_sirq_masked1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_host_sirq_masked1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_host_sirq_masked1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_host_sirq_masked1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_host_sirq_masked1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_host_sirq_masked1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_host_sirq_masked1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_host_sirq_masked1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_host_sirq_masked1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_host_sirq_masked1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_host_sirq_masked1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_host_sirq_masked1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_host_sirq_masked1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_host_sirq_masked1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_host_sirq_masked1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_host_sirq_masked1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_host_sirq_masked1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_host_sirq_masked1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_host_sirq_masked1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_host_sirq_masked1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_host_sirq_masked1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_host_sirq_masked1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_host_sirq_masked1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_host_sirq_masked1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_HOST_SIRQ_MASKED1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_host_sirq_masked1_ARM_TIMER;           /* masked combined IRQ from module ARM_TIMER (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_host_sirq_masked1_timer_com_systime_s; /* masked IRQ from module ARM_TIMER (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_host_sirq_masked1_wdg_com;             /* masked IRQ from module WDG_SYS (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_host_sirq_masked1_dmac_com;            /* masked IRQ from module DMAC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_host_sirq_masked1_mcp_com;             /* masked IRQ from module MULTI_CPU_PING (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int uart                : BFW_NX90_dpm_irq_host_sirq_masked1_uart;                /* masked IRQ from module UART_PL010H (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_host_sirq_masked1_i2c0_com;            /* masked IRQ from module I2C_ARM_COM0 (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_host_sirq_masked1_i2c1_com;            /* masked IRQ from module I2C_ARM_COM1 (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_host_sirq_masked1_ecc_com;             /* masked combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt state for high-priority netX interrupt output signal */
/* (DPM_FIQ/HIF_SIRQ) */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_host_sirq_masked1_xpic_debug_com;      /* masked IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_host_sirq_masked1_wdg_xpic_com_arm;    /* masked IRQ from module XPIC_WDG_COM (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_host_sirq_masked1_nfifo_arm_com;       /* masked IRQ from module OSAC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int com0                : BFW_NX90_dpm_irq_host_sirq_masked1_com0;                /* masked IRQ from module XC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int com1                : BFW_NX90_dpm_irq_host_sirq_masked1_com1;                /* masked IRQ from module XC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int msync0              : BFW_NX90_dpm_irq_host_sirq_masked1_msync0;              /* masked IRQ from module XC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int msync1              : BFW_NX90_dpm_irq_host_sirq_masked1_msync1;              /* masked IRQ from module XC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_host_sirq_masked1_trigger_lt;          /* masked IRQ from module TRIGGER_LT (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_host_sirq_masked1_lvds2mii0_com;       /* masked IRQ from module LVDS (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_host_sirq_masked1_lvds2mii1_com;       /* masked IRQ from module LVDS (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int sqi                 : BFW_NX90_dpm_irq_host_sirq_masked1_sqi;                 /* masked IRQ from module SQI (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_host_sirq_masked1_hif_pio_arm;         /* masked IRQ from module HIF_IO_CTRL (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int eth                 : BFW_NX90_dpm_irq_host_sirq_masked1_eth;                 /* masked IRQ from module FETH (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq0;           /* masked IRQ from module MADC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq1;           /* masked IRQ from module MADC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq2;           /* masked IRQ from module MADC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_host_sirq_masked1_madc_seq3;           /* masked IRQ from module MADC (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_host_sirq_masked1_GPIO_COM;            /* masked combined IRQ from module GPIO_COM (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_host_sirq_masked1_CRYPT;               /* masked combined IRQ from module CRYPT (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int bod                 : BFW_NX90_dpm_irq_host_sirq_masked1_bod;                 /* masked Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int clksup              : BFW_NX90_dpm_irq_host_sirq_masked1_clksup;              /* masked IRQ from module CLKSUP (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int phy                 : BFW_NX90_dpm_irq_host_sirq_masked1_phy;                 /* masked IRQ from module INT_PHY_CFG (only DPM0) interrupt state for high-priority netX interrupt output signal (DPM_FIQ/HIF_SIRQ) */
  unsigned int reserved1           : BFW_NX90_dpm_irq_host_sirq_masked1_reserved1;           /* reserved */
} NX90_DPM_IRQ_HOST_SIRQ_MASKED1_BIT_T;

typedef union {
  uint32_t                             val;
  NX90_DPM_IRQ_HOST_SIRQ_MASKED1_BIT_T bf;
} NX90_DPM_IRQ_HOST_SIRQ_MASKED1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_dirq_mask_set0 */
/* => DPM Interrupt Mask Register for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Write access with '1' sets related interrupt mask bits (enables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_set0      0x000000A0U
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_set0 0xFF0019A0U
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_set0 0xFF001AA0U
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0     0x00000000U

#define MSK_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw                0x00000001U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw           0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw        0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_dpm_err               0x00000002U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_err          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_err       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_firmware              0x00000004U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_firmware         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_firmware      0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0             0x00000100U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1             0x00000200U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2             0x00000400U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3             0x00000800U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4             0x00001000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5             0x00002000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6             0x00004000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7             0x00008000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15         0x00010000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_set0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_set0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_host_dirq_mask_set0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_HOST_DIRQ_MASK_SET0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw;        /* set software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_host_dirq_mask_set0_dpm_err;       /* set DPM access error IRQ of this DPM module interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int firmware      : BFW_NX90_dpm_irq_host_dirq_mask_set0_firmware;      /* set combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int reserved1     : BFW_NX90_dpm_irq_host_dirq_mask_set0_reserved1;     /* reserved */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0;     /* set IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1;     /* set IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2;     /* set IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3;     /* set IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4;     /* set IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5;     /* set IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6;     /* set IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7;     /* set IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15; /* set IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int reserved2     : BFW_NX90_dpm_irq_host_dirq_mask_set0_reserved2;     /* reserved */
} NX90_DPM_IRQ_HOST_DIRQ_MASK_SET0_BIT_T;

typedef union {
  uint32_t                               val;
  NX90_DPM_IRQ_HOST_DIRQ_MASK_SET0_BIT_T bf;
} NX90_DPM_IRQ_HOST_DIRQ_MASK_SET0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_dirq_mask_set1 */
/* => DPM Interrupt Mask Register for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Write access with '1' sets related interrupt mask bits (enables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_set1      0x000000A4U
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_set1 0xFF0019A4U
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_set1 0xFF001AA4U
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1     0x00000000U

#define MSK_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER                   0x00000001U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s         0x00000002U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_wdg_com                     0x00000004U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_com             0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_dmac_com                    0x00000008U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_dmac_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_dmac_com            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_mcp_com                     0x00000010U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_mcp_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_mcp_com             0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_uart                        0x00000020U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_uart                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_uart                0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com                    0x00000040U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com                    0x00000080U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_ecc_com                     0x00000100U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_ecc_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_ecc_com             0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com              0x00000200U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com      0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm            0x00000400U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm    0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com               0x00000800U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_com0                        0x00001000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_com0                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_com0                0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_com1                        0x00002000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_com1                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_com1                0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_msync0                      0x00004000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync0                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync0              0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_msync1                      0x00008000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync1                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync1              0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt                  0x00010000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt             0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt          0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com               0x00020000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com               0x00040000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_sqi                         0x00080000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_sqi                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_sqi                 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm                 0x00100000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm         0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_eth                         0x00200000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_eth                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_eth                 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0                   0x00400000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1                   0x00800000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2                   0x01000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3                   0x02000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM                    0x04000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_CRYPT                       0x08000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_CRYPT                  0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_CRYPT               0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_bod                         0x10000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_bod                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_bod                 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_clksup                      0x20000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_clksup                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_clksup              0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_phy                         0x40000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_phy                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_phy                 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_set1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_set1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_host_dirq_mask_set1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_HOST_DIRQ_MASK_SET1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER;           /* set combined IRQ from module ARM_TIMER (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                 */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s; /* set IRQ from module ARM_TIMER (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                          */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_host_dirq_mask_set1_wdg_com;             /* set IRQ from module WDG_SYS (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                            */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_host_dirq_mask_set1_dmac_com;            /* set IRQ from module DMAC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_host_dirq_mask_set1_mcp_com;             /* set IRQ from module MULTI_CPU_PING (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int uart                : BFW_NX90_dpm_irq_host_dirq_mask_set1_uart;                /* set IRQ from module UART_PL010H (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com;            /* set IRQ from module I2C_ARM_COM0 (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com;            /* set IRQ from module I2C_ARM_COM1 (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_host_dirq_mask_set1_ecc_com;             /* set combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com;      /* set IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm;    /* set IRQ from module XPIC_WDG_COM (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com;       /* set IRQ from module OSAC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int com0                : BFW_NX90_dpm_irq_host_dirq_mask_set1_com0;                /* set IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int com1                : BFW_NX90_dpm_irq_host_dirq_mask_set1_com1;                /* set IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int msync0              : BFW_NX90_dpm_irq_host_dirq_mask_set1_msync0;              /* set IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int msync1              : BFW_NX90_dpm_irq_host_dirq_mask_set1_msync1;              /* set IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt;          /* set IRQ from module TRIGGER_LT (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                         */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com;       /* set IRQ from module LVDS (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com;       /* set IRQ from module LVDS (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int sqi                 : BFW_NX90_dpm_irq_host_dirq_mask_set1_sqi;                 /* set IRQ from module SQI (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm;         /* set IRQ from module HIF_IO_CTRL (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int eth                 : BFW_NX90_dpm_irq_host_dirq_mask_set1_eth;                 /* set IRQ from module FETH (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0;           /* set IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1;           /* set IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2;           /* set IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3;           /* set IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM;            /* set combined IRQ from module GPIO_COM (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                  */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_host_dirq_mask_set1_CRYPT;               /* set combined IRQ from module CRYPT (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int bod                 : BFW_NX90_dpm_irq_host_dirq_mask_set1_bod;                 /* set Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)      */
  unsigned int clksup              : BFW_NX90_dpm_irq_host_dirq_mask_set1_clksup;              /* set IRQ from module CLKSUP (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                             */
  unsigned int phy                 : BFW_NX90_dpm_irq_host_dirq_mask_set1_phy;                 /* set IRQ from module INT_PHY_CFG (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int reserved1           : BFW_NX90_dpm_irq_host_dirq_mask_set1_reserved1;           /* reserved                                                                                                                                     */
} NX90_DPM_IRQ_HOST_DIRQ_MASK_SET1_BIT_T;

typedef union {
  uint32_t                               val;
  NX90_DPM_IRQ_HOST_DIRQ_MASK_SET1_BIT_T bf;
} NX90_DPM_IRQ_HOST_DIRQ_MASK_SET1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_dirq_mask_reset0 */
/* => DPM Interrupt Mask Reset Register for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Write access with '1' resets related interrupt mask bits (disables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_reset0      0x000000A8U
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_reset0 0xFF0019A8U
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_reset0 0xFF001AA8U
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0     0x00000000U

#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw                0x00000001U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw           0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw        0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err               0x00000002U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_firmware              0x00000004U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_firmware         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_firmware      0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0             0x00000100U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1             0x00000200U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2             0x00000400U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3             0x00000800U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4             0x00001000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5             0x00002000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6             0x00004000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7             0x00008000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7     0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15         0x00010000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_reset0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_reset0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw;        /* reset software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err;       /* reset DPM access error IRQ of this DPM module interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int firmware      : BFW_NX90_dpm_irq_host_dirq_mask_reset0_firmware;      /* reset combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int reserved1     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_reserved1;     /* reserved */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0;     /* reset IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1;     /* reset IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2;     /* reset IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3;     /* reset IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4;     /* reset IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5;     /* reset IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6;     /* reset IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7;     /* reset IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15; /* reset IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt mask for normal netX interrupt output signal */
/* (DPM_IRQ/HIF_DIRQ) */
  unsigned int reserved2     : BFW_NX90_dpm_irq_host_dirq_mask_reset0_reserved2;     /* reserved */
} NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET0_BIT_T;

typedef union {
  uint32_t                                 val;
  NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET0_BIT_T bf;
} NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_dirq_mask_reset1 */
/* => DPM Interrupt Mask Reset Register for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Write access with '1' resets related interrupt mask bits (disables interrupt request for corresponding interrupt source). */
/*    Write access with '0' does not influence related interrupt mask bit. */
/*    Read access shows actual interrupt mask. */
/*    If a mask bit is set, the related interrupt will activate the IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_reset1      0x000000ACU
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_reset1 0xFF0019ACU
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_reset1 0xFF001AACU
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1     0x00000000U

#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER                   0x00000001U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s         0x00000002U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com                     0x00000004U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com             0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com                    0x00000008U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com                     0x00000010U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com             0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_uart                        0x00000020U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_uart                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_uart                0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com                    0x00000040U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com                    0x00000080U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com                     0x00000100U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com                0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com             0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com              0x00000200U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com      0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm            0x00000400U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm    0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com               0x00000800U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_com0                        0x00001000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com0                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com0                0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_com1                        0x00002000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com1                   0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com1                0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_msync0                      0x00004000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync0                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync0              0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_msync1                      0x00008000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync1                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync1              0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt                  0x00010000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt             0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt          0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com               0x00020000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com               0x00040000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com       0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_sqi                         0x00080000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_sqi                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_sqi                 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm                 0x00100000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm         0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_eth                         0x00200000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_eth                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_eth                 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0                   0x00400000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1                   0x00800000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2                   0x01000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3                   0x02000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3           0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM                    0x04000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM               0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM            0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT                       0x08000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT                  0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT               0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_bod                         0x10000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_bod                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_bod                 0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_clksup                      0x20000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_clksup                 0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_clksup              0x00000000U
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_phy                         0x40000000U
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_phy                    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_phy                 0x00000000U

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_reset1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_reset1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_host_dirq_mask_reset1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER;           /* reset combined IRQ from module ARM_TIMER (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                 */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s; /* reset IRQ from module ARM_TIMER (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                          */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com;             /* reset IRQ from module WDG_SYS (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                            */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com;            /* reset IRQ from module DMAC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com;             /* reset IRQ from module MULTI_CPU_PING (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int uart                : BFW_NX90_dpm_irq_host_dirq_mask_reset1_uart;                /* reset IRQ from module UART_PL010H (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com;            /* reset IRQ from module I2C_ARM_COM0 (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com;            /* reset IRQ from module I2C_ARM_COM1 (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com;             /* reset combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com;      /* reset IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm;    /* reset IRQ from module XPIC_WDG_COM (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com;       /* reset IRQ from module OSAC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int com0                : BFW_NX90_dpm_irq_host_dirq_mask_reset1_com0;                /* reset IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int com1                : BFW_NX90_dpm_irq_host_dirq_mask_reset1_com1;                /* reset IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int msync0              : BFW_NX90_dpm_irq_host_dirq_mask_reset1_msync0;              /* reset IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int msync1              : BFW_NX90_dpm_irq_host_dirq_mask_reset1_msync1;              /* reset IRQ from module XC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt;          /* reset IRQ from module TRIGGER_LT (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                         */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com;       /* reset IRQ from module LVDS (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com;       /* reset IRQ from module LVDS (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int sqi                 : BFW_NX90_dpm_irq_host_dirq_mask_reset1_sqi;                 /* reset IRQ from module SQI (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm;         /* reset IRQ from module HIF_IO_CTRL (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int eth                 : BFW_NX90_dpm_irq_host_dirq_mask_reset1_eth;                 /* reset IRQ from module FETH (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0;           /* reset IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1;           /* reset IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2;           /* reset IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3;           /* reset IRQ from module MADC (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM;            /* reset combined IRQ from module GPIO_COM (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                  */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT;               /* reset combined IRQ from module CRYPT (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int bod                 : BFW_NX90_dpm_irq_host_dirq_mask_reset1_bod;                 /* reset Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)      */
  unsigned int clksup              : BFW_NX90_dpm_irq_host_dirq_mask_reset1_clksup;              /* reset IRQ from module CLKSUP (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                             */
  unsigned int phy                 : BFW_NX90_dpm_irq_host_dirq_mask_reset1_phy;                 /* reset IRQ from module INT_PHY_CFG (only DPM0) interrupt mask for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int reserved1           : BFW_NX90_dpm_irq_host_dirq_mask_reset1_reserved1;           /* reserved                                                                                                                                       */
} NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET1_BIT_T;

typedef union {
  uint32_t                                 val;
  NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET1_BIT_T bf;
} NX90_DPM_IRQ_HOST_DIRQ_MASK_RESET1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_dirq_masked0 */
/* => DPM Masked Interrupt Status Register for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    A bit is set, when the related mask bit is set in 'dpm_irq_host_dirq_mask'-register and the related interrupt is asserted. */
/*    IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) is asserted if at least one bit is set here. */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_dirq_masked0      0x000000B0U
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_masked0 0xFF0019B0U
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_masked0 0xFF001AB0U

#define MSK_NX90_dpm_irq_host_dirq_masked0_dpm_sw        0x00000001U
#define SRT_NX90_dpm_irq_host_dirq_masked0_dpm_sw        0
#define MSK_NX90_dpm_irq_host_dirq_masked0_dpm_err       0x00000002U
#define SRT_NX90_dpm_irq_host_dirq_masked0_dpm_err       1
#define MSK_NX90_dpm_irq_host_dirq_masked0_firmware      0x00000004U
#define SRT_NX90_dpm_irq_host_dirq_masked0_firmware      2
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc0     0x00000100U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc0     8
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc1     0x00000200U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc1     9
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc2     0x00000400U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc2     10
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc3     0x00000800U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc3     11
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc4     0x00001000U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc4     12
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc5     0x00002000U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc5     13
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc6     0x00004000U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc6     14
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc7     0x00008000U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc7     15
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc8to15 0x00010000U
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc8to15 16

/* all used bits of 'NX90_dpm_irq_host_dirq_masked0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_masked0 0x0001ff07U

enum {
  BFW_NX90_dpm_irq_host_dirq_masked0_dpm_sw        = 1,  /* [0] */
  BFW_NX90_dpm_irq_host_dirq_masked0_dpm_err       = 1,  /* [1] */
  BFW_NX90_dpm_irq_host_dirq_masked0_firmware      = 1,  /* [2] */
  BFW_NX90_dpm_irq_host_dirq_masked0_reserved1     = 5,  /* [7:3] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc0     = 1,  /* [8] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc1     = 1,  /* [9] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc2     = 1,  /* [10] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc3     = 1,  /* [11] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc4     = 1,  /* [12] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc5     = 1,  /* [13] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc6     = 1,  /* [14] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc7     = 1,  /* [15] */
  BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc8to15 = 1,  /* [16] */
  BFW_NX90_dpm_irq_host_dirq_masked0_reserved2     = 15  /* [31:17] */
};

typedef struct NX90_DPM_IRQ_HOST_DIRQ_MASKED0_BIT_Ttag {
  unsigned int dpm_sw        : BFW_NX90_dpm_irq_host_dirq_masked0_dpm_sw;        /* masked software IRQ of this DPM module for netX IRQ targets (e.g. ARM, xPIC) interrupt state for normal netX interrupt output signal */
/* (DPM_IRQ/HIF_DIRQ) */
  unsigned int dpm_err       : BFW_NX90_dpm_irq_host_dirq_masked0_dpm_err;       /* masked DPM access error IRQ of this DPM module interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int firmware      : BFW_NX90_dpm_irq_host_dirq_masked0_firmware;      /* masked combined handshake-cell and SYS_STA firmware IRQ of this DPM module interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int reserved1     : BFW_NX90_dpm_irq_host_dirq_masked0_reserved1;     /* reserved */
  unsigned int host_hsc0     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc0;     /* masked IRQ for host-side of handshake-cell 0 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc1     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc1;     /* masked IRQ for host-side of handshake-cell 1 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc2     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc2;     /* masked IRQ for host-side of handshake-cell 2 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc3     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc3;     /* masked IRQ for host-side of handshake-cell 3 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc4     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc4;     /* masked IRQ for host-side of handshake-cell 4 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc5     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc5;     /* masked IRQ for host-side of handshake-cell 5 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc6     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc6;     /* masked IRQ for host-side of handshake-cell 6 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc7     : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc7;     /* masked IRQ for host-side of handshake-cell 7 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int host_hsc8to15 : BFW_NX90_dpm_irq_host_dirq_masked0_host_hsc8to15; /* masked IRQ for host-side of handshake-cells 8 to 15 from module HANDSHAKE_CTRL interrupt state for normal netX interrupt output signal */
/* (DPM_IRQ/HIF_DIRQ) */
  unsigned int reserved2     : BFW_NX90_dpm_irq_host_dirq_masked0_reserved2;     /* reserved */
} NX90_DPM_IRQ_HOST_DIRQ_MASKED0_BIT_T;

typedef union {
  uint32_t                             val;
  NX90_DPM_IRQ_HOST_DIRQ_MASKED0_BIT_T bf;
} NX90_DPM_IRQ_HOST_DIRQ_MASKED0_T;

/* --------------------------------------------------------------------- */
/* Register dpm_irq_host_dirq_masked1 */
/* => DPM Masked Interrupt Status Register for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ). */
/*    A bit is set, when the related mask bit is set in 'dpm_irq_host_dirq_mask'-register and the related interrupt is asserted. */
/*    IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) is asserted if at least one bit is set here. */
/*    Interrupts must be reset in interrupt generating module. Interrupts cannot be cleared here. */
/*    To release IRQ for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) without clearing interrupt in module, reset related mask bit to 0. */
/*     */
/*    Note: */
/*       For further information view description of 'dpm_irq_raw' register. */
/*     */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_irq_host_dirq_masked1      0x000000B4U
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_masked1 0xFF0019B4U
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_masked1 0xFF001AB4U

#define MSK_NX90_dpm_irq_host_dirq_masked1_ARM_TIMER           0x00000001U
#define SRT_NX90_dpm_irq_host_dirq_masked1_ARM_TIMER           0
#define MSK_NX90_dpm_irq_host_dirq_masked1_timer_com_systime_s 0x00000002U
#define SRT_NX90_dpm_irq_host_dirq_masked1_timer_com_systime_s 1
#define MSK_NX90_dpm_irq_host_dirq_masked1_wdg_com             0x00000004U
#define SRT_NX90_dpm_irq_host_dirq_masked1_wdg_com             2
#define MSK_NX90_dpm_irq_host_dirq_masked1_dmac_com            0x00000008U
#define SRT_NX90_dpm_irq_host_dirq_masked1_dmac_com            3
#define MSK_NX90_dpm_irq_host_dirq_masked1_mcp_com             0x00000010U
#define SRT_NX90_dpm_irq_host_dirq_masked1_mcp_com             4
#define MSK_NX90_dpm_irq_host_dirq_masked1_uart                0x00000020U
#define SRT_NX90_dpm_irq_host_dirq_masked1_uart                5
#define MSK_NX90_dpm_irq_host_dirq_masked1_i2c0_com            0x00000040U
#define SRT_NX90_dpm_irq_host_dirq_masked1_i2c0_com            6
#define MSK_NX90_dpm_irq_host_dirq_masked1_i2c1_com            0x00000080U
#define SRT_NX90_dpm_irq_host_dirq_masked1_i2c1_com            7
#define MSK_NX90_dpm_irq_host_dirq_masked1_ecc_com             0x00000100U
#define SRT_NX90_dpm_irq_host_dirq_masked1_ecc_com             8
#define MSK_NX90_dpm_irq_host_dirq_masked1_xpic_debug_com      0x00000200U
#define SRT_NX90_dpm_irq_host_dirq_masked1_xpic_debug_com      9
#define MSK_NX90_dpm_irq_host_dirq_masked1_wdg_xpic_com_arm    0x00000400U
#define SRT_NX90_dpm_irq_host_dirq_masked1_wdg_xpic_com_arm    10
#define MSK_NX90_dpm_irq_host_dirq_masked1_nfifo_arm_com       0x00000800U
#define SRT_NX90_dpm_irq_host_dirq_masked1_nfifo_arm_com       11
#define MSK_NX90_dpm_irq_host_dirq_masked1_com0                0x00001000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_com0                12
#define MSK_NX90_dpm_irq_host_dirq_masked1_com1                0x00002000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_com1                13
#define MSK_NX90_dpm_irq_host_dirq_masked1_msync0              0x00004000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_msync0              14
#define MSK_NX90_dpm_irq_host_dirq_masked1_msync1              0x00008000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_msync1              15
#define MSK_NX90_dpm_irq_host_dirq_masked1_trigger_lt          0x00010000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_trigger_lt          16
#define MSK_NX90_dpm_irq_host_dirq_masked1_lvds2mii0_com       0x00020000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_lvds2mii0_com       17
#define MSK_NX90_dpm_irq_host_dirq_masked1_lvds2mii1_com       0x00040000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_lvds2mii1_com       18
#define MSK_NX90_dpm_irq_host_dirq_masked1_sqi                 0x00080000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_sqi                 19
#define MSK_NX90_dpm_irq_host_dirq_masked1_hif_pio_arm         0x00100000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_hif_pio_arm         20
#define MSK_NX90_dpm_irq_host_dirq_masked1_eth                 0x00200000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_eth                 21
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq0           0x00400000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq0           22
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq1           0x00800000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq1           23
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq2           0x01000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq2           24
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq3           0x02000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq3           25
#define MSK_NX90_dpm_irq_host_dirq_masked1_GPIO_COM            0x04000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_GPIO_COM            26
#define MSK_NX90_dpm_irq_host_dirq_masked1_CRYPT               0x08000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_CRYPT               27
#define MSK_NX90_dpm_irq_host_dirq_masked1_bod                 0x10000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_bod                 28
#define MSK_NX90_dpm_irq_host_dirq_masked1_clksup              0x20000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_clksup              29
#define MSK_NX90_dpm_irq_host_dirq_masked1_phy                 0x40000000U
#define SRT_NX90_dpm_irq_host_dirq_masked1_phy                 30

/* all used bits of 'NX90_dpm_irq_host_dirq_masked1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_masked1 0x7fffffffU

enum {
  BFW_NX90_dpm_irq_host_dirq_masked1_ARM_TIMER           = 1, /* [0] */
  BFW_NX90_dpm_irq_host_dirq_masked1_timer_com_systime_s = 1, /* [1] */
  BFW_NX90_dpm_irq_host_dirq_masked1_wdg_com             = 1, /* [2] */
  BFW_NX90_dpm_irq_host_dirq_masked1_dmac_com            = 1, /* [3] */
  BFW_NX90_dpm_irq_host_dirq_masked1_mcp_com             = 1, /* [4] */
  BFW_NX90_dpm_irq_host_dirq_masked1_uart                = 1, /* [5] */
  BFW_NX90_dpm_irq_host_dirq_masked1_i2c0_com            = 1, /* [6] */
  BFW_NX90_dpm_irq_host_dirq_masked1_i2c1_com            = 1, /* [7] */
  BFW_NX90_dpm_irq_host_dirq_masked1_ecc_com             = 1, /* [8] */
  BFW_NX90_dpm_irq_host_dirq_masked1_xpic_debug_com      = 1, /* [9] */
  BFW_NX90_dpm_irq_host_dirq_masked1_wdg_xpic_com_arm    = 1, /* [10] */
  BFW_NX90_dpm_irq_host_dirq_masked1_nfifo_arm_com       = 1, /* [11] */
  BFW_NX90_dpm_irq_host_dirq_masked1_com0                = 1, /* [12] */
  BFW_NX90_dpm_irq_host_dirq_masked1_com1                = 1, /* [13] */
  BFW_NX90_dpm_irq_host_dirq_masked1_msync0              = 1, /* [14] */
  BFW_NX90_dpm_irq_host_dirq_masked1_msync1              = 1, /* [15] */
  BFW_NX90_dpm_irq_host_dirq_masked1_trigger_lt          = 1, /* [16] */
  BFW_NX90_dpm_irq_host_dirq_masked1_lvds2mii0_com       = 1, /* [17] */
  BFW_NX90_dpm_irq_host_dirq_masked1_lvds2mii1_com       = 1, /* [18] */
  BFW_NX90_dpm_irq_host_dirq_masked1_sqi                 = 1, /* [19] */
  BFW_NX90_dpm_irq_host_dirq_masked1_hif_pio_arm         = 1, /* [20] */
  BFW_NX90_dpm_irq_host_dirq_masked1_eth                 = 1, /* [21] */
  BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq0           = 1, /* [22] */
  BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq1           = 1, /* [23] */
  BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq2           = 1, /* [24] */
  BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq3           = 1, /* [25] */
  BFW_NX90_dpm_irq_host_dirq_masked1_GPIO_COM            = 1, /* [26] */
  BFW_NX90_dpm_irq_host_dirq_masked1_CRYPT               = 1, /* [27] */
  BFW_NX90_dpm_irq_host_dirq_masked1_bod                 = 1, /* [28] */
  BFW_NX90_dpm_irq_host_dirq_masked1_clksup              = 1, /* [29] */
  BFW_NX90_dpm_irq_host_dirq_masked1_phy                 = 1, /* [30] */
  BFW_NX90_dpm_irq_host_dirq_masked1_reserved1           = 1  /* [31] */
};

typedef struct NX90_DPM_IRQ_HOST_DIRQ_MASKED1_BIT_Ttag {
  unsigned int ARM_TIMER           : BFW_NX90_dpm_irq_host_dirq_masked1_ARM_TIMER;           /* masked combined IRQ from module ARM_TIMER (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                 */
  unsigned int timer_com_systime_s : BFW_NX90_dpm_irq_host_dirq_masked1_timer_com_systime_s; /* masked IRQ from module ARM_TIMER (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                          */
  unsigned int wdg_com             : BFW_NX90_dpm_irq_host_dirq_masked1_wdg_com;             /* masked IRQ from module WDG_SYS (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                            */
  unsigned int dmac_com            : BFW_NX90_dpm_irq_host_dirq_masked1_dmac_com;            /* masked IRQ from module DMAC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int mcp_com             : BFW_NX90_dpm_irq_host_dirq_masked1_mcp_com;             /* masked IRQ from module MULTI_CPU_PING (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int uart                : BFW_NX90_dpm_irq_host_dirq_masked1_uart;                /* masked IRQ from module UART_PL010H (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int i2c0_com            : BFW_NX90_dpm_irq_host_dirq_masked1_i2c0_com;            /* masked IRQ from module I2C_ARM_COM0 (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int i2c1_com            : BFW_NX90_dpm_irq_host_dirq_masked1_i2c1_com;            /* masked IRQ from module I2C_ARM_COM1 (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int ecc_com             : BFW_NX90_dpm_irq_host_dirq_masked1_ecc_com;             /* masked combined IRQ from module ECC_CRTL_COM and ECC_CTRL (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ) */
  unsigned int xpic_debug_com      : BFW_NX90_dpm_irq_host_dirq_masked1_xpic_debug_com;      /* masked IRQ from module XPIC_DEBUG_COM (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int wdg_xpic_com_arm    : BFW_NX90_dpm_irq_host_dirq_masked1_wdg_xpic_com_arm;    /* masked IRQ from module XPIC_WDG_COM (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                       */
  unsigned int nfifo_arm_com       : BFW_NX90_dpm_irq_host_dirq_masked1_nfifo_arm_com;       /* masked IRQ from module OSAC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int com0                : BFW_NX90_dpm_irq_host_dirq_masked1_com0;                /* masked IRQ from module XC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int com1                : BFW_NX90_dpm_irq_host_dirq_masked1_com1;                /* masked IRQ from module XC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int msync0              : BFW_NX90_dpm_irq_host_dirq_masked1_msync0;              /* masked IRQ from module XC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int msync1              : BFW_NX90_dpm_irq_host_dirq_masked1_msync1;              /* masked IRQ from module XC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                 */
  unsigned int trigger_lt          : BFW_NX90_dpm_irq_host_dirq_masked1_trigger_lt;          /* masked IRQ from module TRIGGER_LT (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                         */
  unsigned int lvds2mii0_com       : BFW_NX90_dpm_irq_host_dirq_masked1_lvds2mii0_com;       /* masked IRQ from module LVDS (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int lvds2mii1_com       : BFW_NX90_dpm_irq_host_dirq_masked1_lvds2mii1_com;       /* masked IRQ from module LVDS (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int sqi                 : BFW_NX90_dpm_irq_host_dirq_masked1_sqi;                 /* masked IRQ from module SQI (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                                */
  unsigned int hif_pio_arm         : BFW_NX90_dpm_irq_host_dirq_masked1_hif_pio_arm;         /* masked IRQ from module HIF_IO_CTRL (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int eth                 : BFW_NX90_dpm_irq_host_dirq_masked1_eth;                 /* masked IRQ from module FETH (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq0           : BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq0;           /* masked IRQ from module MADC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq1           : BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq1;           /* masked IRQ from module MADC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq2           : BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq2;           /* masked IRQ from module MADC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int madc_seq3           : BFW_NX90_dpm_irq_host_dirq_masked1_madc_seq3;           /* masked IRQ from module MADC (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                               */
  unsigned int GPIO_COM            : BFW_NX90_dpm_irq_host_dirq_masked1_GPIO_COM;            /* masked combined IRQ from module GPIO_COM (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                  */
  unsigned int CRYPT               : BFW_NX90_dpm_irq_host_dirq_masked1_CRYPT;               /* masked combined IRQ from module CRYPT (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                     */
  unsigned int bod                 : BFW_NX90_dpm_irq_host_dirq_masked1_bod;                 /* masked Brown-out detection IRQ from module ASIC_CTRL (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)      */
  unsigned int clksup              : BFW_NX90_dpm_irq_host_dirq_masked1_clksup;              /* masked IRQ from module CLKSUP (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                             */
  unsigned int phy                 : BFW_NX90_dpm_irq_host_dirq_masked1_phy;                 /* masked IRQ from module INT_PHY_CFG (only DPM0) interrupt state for normal netX interrupt output signal (DPM_IRQ/HIF_DIRQ)                        */
  unsigned int reserved1           : BFW_NX90_dpm_irq_host_dirq_masked1_reserved1;           /* reserved                                                                                                                                         */
} NX90_DPM_IRQ_HOST_DIRQ_MASKED1_BIT_T;

typedef union {
  uint32_t                             val;
  NX90_DPM_IRQ_HOST_DIRQ_MASKED1_BIT_T bf;
} NX90_DPM_IRQ_HOST_DIRQ_MASKED1_T;

/* --------------------------------------------------------------------- */
/* Register dpm_sw_irq */
/* => DPM Register for Software Interrupt Generation. */
/*    To propagate interrupt states from this register to the interrupt target the 'dpm_sw' bit must */
/*    be set inside the appropriate interrupt mask (e.g. 'dpm_irq_arm_mask_set' register). */
/*     */
/*    Example: */
/*       The 'dpm_sw' IRQs can be used by the host to flag one IRQ to the ARM by */
/*       setting the arm-dpm_sw and another IRQ to the xPIC by setting the xpic-dpm_sw. The */
/*       ARM can use at the same time the irq-dpm_sw to flag an IRQ to the host while the */
/*       xPIC could use the fiq-dpm_sw to flag another IRQ to the host. */
/*     */
/*    Note: */
/*       For each netX interrupt target  there is a set and a reset bit provided to avoid read-modify-write sequences. */
/*       When both (set and reset) bits are set for the same target, the related interrupt will be set (set will win). */
/*       Reset bits are always 0 on read. Set-bits show current interrupt status when read. */
/*    Note: */
/*       This register is a new netx51/52 feature.. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_sw_irq      0x000000B8U
#define Adr_NX90_dpm0_com_dpm_sw_irq 0xFF0019B8U
#define Adr_NX90_dpm1_com_dpm_sw_irq 0xFF001AB8U
#define DFLT_VAL_NX90_dpm_sw_irq     0x00000000U

#define MSK_NX90_dpm_sw_irq_set_host_sirq           0x00000001U
#define SRT_NX90_dpm_sw_irq_set_host_sirq           0
#define DFLT_VAL_NX90_dpm_sw_irq_set_host_sirq      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sw_irq_set_host_sirq   0x00000000U
#define MSK_NX90_dpm_sw_irq_set_host_dirq           0x00000002U
#define SRT_NX90_dpm_sw_irq_set_host_dirq           1
#define DFLT_VAL_NX90_dpm_sw_irq_set_host_dirq      0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sw_irq_set_host_dirq   0x00000000U
#define MSK_NX90_dpm_sw_irq_reset_host_sirq         0x00000100U
#define SRT_NX90_dpm_sw_irq_reset_host_sirq         8
#define DFLT_VAL_NX90_dpm_sw_irq_reset_host_sirq    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sw_irq_reset_host_sirq 0x00000000U
#define MSK_NX90_dpm_sw_irq_reset_host_dirq         0x00000200U
#define SRT_NX90_dpm_sw_irq_reset_host_dirq         9
#define DFLT_VAL_NX90_dpm_sw_irq_reset_host_dirq    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sw_irq_reset_host_dirq 0x00000000U

/* all used bits of 'NX90_dpm_sw_irq': */
#define MSK_USED_BITS_NX90_dpm_sw_irq 0x00000303U

enum {
  BFW_NX90_dpm_sw_irq_set_host_sirq   = 1,  /* [0] */
  BFW_NX90_dpm_sw_irq_set_host_dirq   = 1,  /* [1] */
  BFW_NX90_dpm_sw_irq_reserved1       = 6,  /* [7:2] */
  BFW_NX90_dpm_sw_irq_reset_host_sirq = 1,  /* [8] */
  BFW_NX90_dpm_sw_irq_reset_host_dirq = 1,  /* [9] */
  BFW_NX90_dpm_sw_irq_reserved2       = 22  /* [31:10] */
};

typedef struct NX90_DPM_SW_IRQ_BIT_Ttag {
  unsigned int set_host_sirq   : BFW_NX90_dpm_sw_irq_set_host_sirq;   /* Set 'dpm_sw' IRQ for SIRQ/FIQ-signal (current 'dpm_sw' status for host_sirq when read) */
  unsigned int set_host_dirq   : BFW_NX90_dpm_sw_irq_set_host_dirq;   /* Set 'dpm_sw' IRQ for DIRQ/IRQ-signal (current 'dpm_sw' status for host_dirq when read) */
  unsigned int reserved1       : BFW_NX90_dpm_sw_irq_reserved1;       /* reserved                                                                               */
  unsigned int reset_host_sirq : BFW_NX90_dpm_sw_irq_reset_host_sirq; /* Reset 'dpm_sw' IRQ for SIRQ/FIQ-signal (always 0 when read)                            */
  unsigned int reset_host_dirq : BFW_NX90_dpm_sw_irq_reset_host_dirq; /* Reset 'dpm_sw' IRQ for DIRQ/IRQ-signal (always 0 when read)                            */
  unsigned int reserved2       : BFW_NX90_dpm_sw_irq_reserved2;       /* reserved                                                                               */
} NX90_DPM_SW_IRQ_BIT_T;

typedef union {
  uint32_t              val;
  NX90_DPM_SW_IRQ_BIT_T bf;
} NX90_DPM_SW_IRQ_T;

/* --------------------------------------------------------------------- */
/* Register dpm_crc */
/* => DPM CRC for access to NETX data (window1-4) */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_crc      0x000000BCU
#define Adr_NX90_dpm0_com_dpm_crc 0xFF0019BCU
#define Adr_NX90_dpm1_com_dpm_crc 0xFF001ABCU
#define DFLT_VAL_NX90_dpm_crc     0xffffffffU

#define MSK_NX90_dpm_crc_crc_rdata         0x0000ffffU
#define SRT_NX90_dpm_crc_crc_rdata         0
#define DFLT_VAL_NX90_dpm_crc_crc_rdata    0x0000ffffU
#define DFLT_BF_VAL_NX90_dpm_crc_crc_rdata 0x0000ffffU
#define MSK_NX90_dpm_crc_crc_wdata         0xffff0000U
#define SRT_NX90_dpm_crc_crc_wdata         16
#define DFLT_VAL_NX90_dpm_crc_crc_wdata    0xffff0000U
#define DFLT_BF_VAL_NX90_dpm_crc_crc_wdata 0x0000ffffU

/* all used bits of 'NX90_dpm_crc': */
#define MSK_USED_BITS_NX90_dpm_crc 0xffffffffU

enum {
  BFW_NX90_dpm_crc_crc_rdata = 16, /* [15:0] */
  BFW_NX90_dpm_crc_crc_wdata = 16  /* [31:16] */
};

typedef struct NX90_DPM_CRC_BIT_Ttag {
  unsigned int crc_rdata : BFW_NX90_dpm_crc_crc_rdata; /* Provides the current CRC of data read from DPM windows 1-4 since last read-CRC clear.          */
                                                       /* Write 0x1 to this bit field to clear read-CRC generation to restart CRC for a new read data.   */
  unsigned int crc_wdata : BFW_NX90_dpm_crc_crc_wdata; /* Provides the current CRC of data written to DPM windows 1-4 since last write-CRC clear.        */
                                                       /* Write 0x1 to this bit field to clear write-CRC generation to restart CRC for a new write data. */
} NX90_DPM_CRC_BIT_T;

typedef union {
  uint32_t           val;
  NX90_DPM_CRC_BIT_T bf;
} NX90_DPM_CRC_T;

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_wgd_host_timeout */
/* => Address reserved for netx50 DPM_HOST_WDG_HOST_TIMEOUT. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_wgd_host_timeout      0x000000C0U
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_wgd_host_timeout 0xFF0019C0U
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_wgd_host_timeout 0xFF001AC0U

#define MSK_NX90_dpm_reserved_netx50_wgd_host_timeout_zero_ro 0xffffffffU
#define SRT_NX90_dpm_reserved_netx50_wgd_host_timeout_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_wgd_host_timeout': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_wgd_host_timeout 0xffffffffU

enum {
  BFW_NX90_dpm_reserved_netx50_wgd_host_timeout_zero_ro = 32  /* [31:0] */
};

typedef struct NX90_DPM_RESERVED_NETX50_WGD_HOST_TIMEOUT_BIT_Ttag {
  unsigned int zero_ro : BFW_NX90_dpm_reserved_netx50_wgd_host_timeout_zero_ro; /* reserved for netx50 DPM_HOST_WDG_HOST_TIMEOUT. */
} NX90_DPM_RESERVED_NETX50_WGD_HOST_TIMEOUT_BIT_T;

typedef union {
  uint32_t                                        val;
  NX90_DPM_RESERVED_NETX50_WGD_HOST_TIMEOUT_BIT_T bf;
} NX90_DPM_RESERVED_NETX50_WGD_HOST_TIMEOUT_T;

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_wgd_host_trigger */
/* => Address reserved for netx50 DPM_HOST_WDG_HOST_TRIG. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_wgd_host_trigger      0x000000C4U
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_wgd_host_trigger 0xFF0019C4U
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_wgd_host_trigger 0xFF001AC4U

#define MSK_NX90_dpm_reserved_netx50_wgd_host_trigger_zero_ro 0xffffffffU
#define SRT_NX90_dpm_reserved_netx50_wgd_host_trigger_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_wgd_host_trigger': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_wgd_host_trigger 0xffffffffU

enum {
  BFW_NX90_dpm_reserved_netx50_wgd_host_trigger_zero_ro = 32  /* [31:0] */
};

typedef struct NX90_DPM_RESERVED_NETX50_WGD_HOST_TRIGGER_BIT_Ttag {
  unsigned int zero_ro : BFW_NX90_dpm_reserved_netx50_wgd_host_trigger_zero_ro; /* reserved for netx50 DPM_HOST_WDG_HOST_TRIG. */
} NX90_DPM_RESERVED_NETX50_WGD_HOST_TRIGGER_BIT_T;

typedef union {
  uint32_t                                        val;
  NX90_DPM_RESERVED_NETX50_WGD_HOST_TRIGGER_BIT_T bf;
} NX90_DPM_RESERVED_NETX50_WGD_HOST_TRIGGER_T;

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_wgd_netx_timeout */
/* => Address reserved for netx50 DPM_HOST_WDG_ARM_TIMEOUT. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_wgd_netx_timeout      0x000000C8U
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_wgd_netx_timeout 0xFF0019C8U
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_wgd_netx_timeout 0xFF001AC8U

#define MSK_NX90_dpm_reserved_netx50_wgd_netx_timeout_zero_ro 0xffffffffU
#define SRT_NX90_dpm_reserved_netx50_wgd_netx_timeout_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_wgd_netx_timeout': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_wgd_netx_timeout 0xffffffffU

enum {
  BFW_NX90_dpm_reserved_netx50_wgd_netx_timeout_zero_ro = 32  /* [31:0] */
};

typedef struct NX90_DPM_RESERVED_NETX50_WGD_NETX_TIMEOUT_BIT_Ttag {
  unsigned int zero_ro : BFW_NX90_dpm_reserved_netx50_wgd_netx_timeout_zero_ro; /* reserved for netx50 DPM_HOST_WDG_ARM_TIMEOUT. */
} NX90_DPM_RESERVED_NETX50_WGD_NETX_TIMEOUT_BIT_T;

typedef union {
  uint32_t                                        val;
  NX90_DPM_RESERVED_NETX50_WGD_NETX_TIMEOUT_BIT_T bf;
} NX90_DPM_RESERVED_NETX50_WGD_NETX_TIMEOUT_T;

/* --------------------------------------------------------------------- */
/* Register dpm_sys_sta_bigend16 */
/* => DPM System Status Information Register in big endianess 16 data mapping. */
/*    Read-only, use dpm_sys_sta for programming. */
/*    This register can be used for firmware status information. */
/*    Reading this register data can be done from uninitialized DPM interface in the same way */
/*    as reading netx version (adr_dpm_netx_version_bigend16, adr_dpm_netx_version) by using dpm_sys_sta_bigend16 register. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_sys_sta_bigend16      0x000000CCU
#define Adr_NX90_dpm0_com_dpm_sys_sta_bigend16 0xFF0019CCU
#define Adr_NX90_dpm1_com_dpm_sys_sta_bigend16 0xFF001ACCU

#define MSK_NX90_dpm_sys_sta_bigend16_NETX_STA_CODE_swap_ro 0x000000ffU
#define SRT_NX90_dpm_sys_sta_bigend16_NETX_STA_CODE_swap_ro 0
#define MSK_NX90_dpm_sys_sta_bigend16_RDY_ro                0x00000100U
#define SRT_NX90_dpm_sys_sta_bigend16_RDY_ro                8
#define MSK_NX90_dpm_sys_sta_bigend16_RUN_ro                0x00000200U
#define SRT_NX90_dpm_sys_sta_bigend16_RUN_ro                9
#define MSK_NX90_dpm_sys_sta_bigend16_NETX_STATE_swap_ro    0x00000c00U
#define SRT_NX90_dpm_sys_sta_bigend16_NETX_STATE_swap_ro    10
#define MSK_NX90_dpm_sys_sta_bigend16_HOST_STATE_swap_ro    0x0000f000U
#define SRT_NX90_dpm_sys_sta_bigend16_HOST_STATE_swap_ro    12

/* all used bits of 'NX90_dpm_sys_sta_bigend16': */
#define MSK_USED_BITS_NX90_dpm_sys_sta_bigend16 0x0000ffffU

enum {
  BFW_NX90_dpm_sys_sta_bigend16_NETX_STA_CODE_swap_ro = 8,  /* [7:0] */
  BFW_NX90_dpm_sys_sta_bigend16_RDY_ro                = 1,  /* [8] */
  BFW_NX90_dpm_sys_sta_bigend16_RUN_ro                = 1,  /* [9] */
  BFW_NX90_dpm_sys_sta_bigend16_NETX_STATE_swap_ro    = 2,  /* [11:10] */
  BFW_NX90_dpm_sys_sta_bigend16_HOST_STATE_swap_ro    = 4,  /* [15:12] */
  BFW_NX90_dpm_sys_sta_bigend16_reserved1             = 16  /* [31:16] */
};

typedef struct NX90_DPM_SYS_STA_BIGEND16_BIT_Ttag {
  unsigned int NETX_STA_CODE_swap_ro : BFW_NX90_dpm_sys_sta_bigend16_NETX_STA_CODE_swap_ro; /* Bit field for Hilscher firmware compatibility. */
  unsigned int RDY_ro                : BFW_NX90_dpm_sys_sta_bigend16_RDY_ro;                /* Output state of netX RDY LED IO.               */
  unsigned int RUN_ro                : BFW_NX90_dpm_sys_sta_bigend16_RUN_ro;                /* Output state of netX RUN LED IO.               */
  unsigned int NETX_STATE_swap_ro    : BFW_NX90_dpm_sys_sta_bigend16_NETX_STATE_swap_ro;    /* Bit field for Hilscher firmware compatibility. */
  unsigned int HOST_STATE_swap_ro    : BFW_NX90_dpm_sys_sta_bigend16_HOST_STATE_swap_ro;    /* Bit field for Hilscher firmware compatibility. */
  unsigned int reserved1             : BFW_NX90_dpm_sys_sta_bigend16_reserved1;             /* reserved                                       */
} NX90_DPM_SYS_STA_BIGEND16_BIT_T;

typedef union {
  uint32_t                        val;
  NX90_DPM_SYS_STA_BIGEND16_BIT_T bf;
} NX90_DPM_SYS_STA_BIGEND16_T;

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_timer_ctrl */
/* => Address reserved for netx50 DPM_HOST_TMR_CTRL. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_timer_ctrl      0x000000D0U
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_timer_ctrl 0xFF0019D0U
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_timer_ctrl 0xFF001AD0U

#define MSK_NX90_dpm_reserved_netx50_timer_ctrl_zero_ro 0xffffffffU
#define SRT_NX90_dpm_reserved_netx50_timer_ctrl_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_timer_ctrl': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_timer_ctrl 0xffffffffU

enum {
  BFW_NX90_dpm_reserved_netx50_timer_ctrl_zero_ro = 32  /* [31:0] */
};

typedef struct NX90_DPM_RESERVED_NETX50_TIMER_CTRL_BIT_Ttag {
  unsigned int zero_ro : BFW_NX90_dpm_reserved_netx50_timer_ctrl_zero_ro; /* reserved for netx50 DPM_HOST_TMR_CTRL. */
} NX90_DPM_RESERVED_NETX50_TIMER_CTRL_BIT_T;

typedef union {
  uint32_t                                  val;
  NX90_DPM_RESERVED_NETX50_TIMER_CTRL_BIT_T bf;
} NX90_DPM_RESERVED_NETX50_TIMER_CTRL_T;

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_timer_start_val */
/* => Address reserved for netx50 DPM_HOST_TMR_START_VAL. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_timer_start_val      0x000000D4U
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_timer_start_val 0xFF0019D4U
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_timer_start_val 0xFF001AD4U

#define MSK_NX90_dpm_reserved_netx50_timer_start_val_zero_ro 0xffffffffU
#define SRT_NX90_dpm_reserved_netx50_timer_start_val_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_timer_start_val': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_timer_start_val 0xffffffffU

enum {
  BFW_NX90_dpm_reserved_netx50_timer_start_val_zero_ro = 32  /* [31:0] */
};

typedef struct NX90_DPM_RESERVED_NETX50_TIMER_START_VAL_BIT_Ttag {
  unsigned int zero_ro : BFW_NX90_dpm_reserved_netx50_timer_start_val_zero_ro; /* reserved for netx50 DPM_HOST_TMR_START_VAL. */
} NX90_DPM_RESERVED_NETX50_TIMER_START_VAL_BIT_T;

typedef union {
  uint32_t                                       val;
  NX90_DPM_RESERVED_NETX50_TIMER_START_VAL_BIT_T bf;
} NX90_DPM_RESERVED_NETX50_TIMER_START_VAL_T;

/* --------------------------------------------------------------------- */
/* Register dpm_sys_sta */
/* => DPM System Status Information Register. */
/*    This register can be used for firmware status information. */
/*    Reading this register data can be done from uninitialized DPM interface in the same way */
/*    as reading netx version (adr_dpm_netx_version_bigend16, adr_dpm_netx_version) by using dpm_sys_sta_bigend16 register. */
/*     */
/*    Note: */
/*       For DPM0 This register is compatible to netx50 DPM_HOST_SYS_STAT register */
/*       Only the HOST_STATE-bits of DPM0 can be read from the 'netx_status'-register inside ASIC_CTRL address area. */
/*       The HOST_STATE-bits of DPM1 and IDPM can not be read from the 'netx_status'-register inside */
/*       ASIC_CTRL address area. */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_sys_sta      0x000000D8U
#define Adr_NX90_dpm0_com_dpm_sys_sta 0xFF0019D8U
#define Adr_NX90_dpm1_com_dpm_sys_sta 0xFF001AD8U
#define DFLT_VAL_NX90_dpm_sys_sta     0x00000000U

#define MSK_NX90_dpm_sys_sta_RDY_ro                   0x00000001U
#define SRT_NX90_dpm_sys_sta_RDY_ro                   0
#define DFLT_VAL_NX90_dpm_sys_sta_RDY_ro              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sys_sta_RDY_ro           0x00000000U
#define MSK_NX90_dpm_sys_sta_RUN_ro                   0x00000002U
#define SRT_NX90_dpm_sys_sta_RUN_ro                   1
#define DFLT_VAL_NX90_dpm_sys_sta_RUN_ro              0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sys_sta_RUN_ro           0x00000000U
#define MSK_NX90_dpm_sys_sta_NETX_STATE_ro            0x0000000cU
#define SRT_NX90_dpm_sys_sta_NETX_STATE_ro            2
#define DFLT_VAL_NX90_dpm_sys_sta_NETX_STATE_ro       0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sys_sta_NETX_STATE_ro    0x00000000U
#define MSK_NX90_dpm_sys_sta_HOST_STATE               0x000000f0U
#define SRT_NX90_dpm_sys_sta_HOST_STATE               4
#define DFLT_VAL_NX90_dpm_sys_sta_HOST_STATE          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sys_sta_HOST_STATE       0x00000000U
#define MSK_NX90_dpm_sys_sta_NETX_STA_CODE_ro         0x0000ff00U
#define SRT_NX90_dpm_sys_sta_NETX_STA_CODE_ro         8
#define DFLT_VAL_NX90_dpm_sys_sta_NETX_STA_CODE_ro    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_sys_sta_NETX_STA_CODE_ro 0x00000000U

/* all used bits of 'NX90_dpm_sys_sta': */
#define MSK_USED_BITS_NX90_dpm_sys_sta 0x0000ffffU

enum {
  BFW_NX90_dpm_sys_sta_RDY_ro           = 1,  /* [0] */
  BFW_NX90_dpm_sys_sta_RUN_ro           = 1,  /* [1] */
  BFW_NX90_dpm_sys_sta_NETX_STATE_ro    = 2,  /* [3:2] */
  BFW_NX90_dpm_sys_sta_HOST_STATE       = 4,  /* [7:4] */
  BFW_NX90_dpm_sys_sta_NETX_STA_CODE_ro = 8,  /* [15:8] */
  BFW_NX90_dpm_sys_sta_reserved1        = 16  /* [31:16] */
};

typedef struct NX90_DPM_SYS_STA_BIT_Ttag {
  unsigned int RDY_ro           : BFW_NX90_dpm_sys_sta_RDY_ro;           /* Output state of netX RDY LED IO.                                                                          */
                                                                         /* Note: This bit field can be changed by 'rdy_run_cfg'-register inside ASIC_CTRL address area.              */
  unsigned int RUN_ro           : BFW_NX90_dpm_sys_sta_RUN_ro;           /* Output state of netX RUN LED IO.                                                                          */
                                                                         /* Note: This bit field can be changed by 'rdy_run_cfg'-register inside ASIC_CTRL address area.              */
  unsigned int NETX_STATE_ro    : BFW_NX90_dpm_sys_sta_NETX_STATE_ro;    /* Bit field for Hilscher firmware compatibility.                                                            */
                                                                         /* Note: This bit field can be changed by 'netx_status'-register inside ASIC_CTRL address area.              */
  unsigned int HOST_STATE       : BFW_NX90_dpm_sys_sta_HOST_STATE;       /* Bit field for Hilscher firmware compatibility.                                                            */
                                                                         /* Note:                                                                                                     */
                                                                         /*    For DPM0: This bit field can be read also at 'netx_status'-register inside ASIC_CTRL address area.     */
                                                                         /*    For DPM1: This bit field can not be read also at 'netx_status'-register inside ASIC_CTRL address area. */
  unsigned int NETX_STA_CODE_ro : BFW_NX90_dpm_sys_sta_NETX_STA_CODE_ro; /* Bit field for Hilscher firmware compatibility (read only).                                                */
                                                                         /* Note: This bit field can be changed by 'netx_status'-register inside ASIC_CTRL address area.              */
  unsigned int reserved1        : BFW_NX90_dpm_sys_sta_reserved1;        /* reserved                                                                                                  */
} NX90_DPM_SYS_STA_BIT_T;

typedef union {
  uint32_t               val;
  NX90_DPM_SYS_STA_BIT_T bf;
} NX90_DPM_SYS_STA_T;

/* --------------------------------------------------------------------- */
/* Register dpm_reset_request */
/* => DPM Reset Request Register. */
/*     */
/*    Note: This register is compatible to netx50 DPM_HOST_RESET_REQ register */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reset_request      0x000000DCU
#define Adr_NX90_dpm0_com_dpm_reset_request 0xFF0019DCU
#define Adr_NX90_dpm1_com_dpm_reset_request 0xFF001ADCU
#define DFLT_VAL_NX90_dpm_reset_request     0x00000000U

#define MSK_NX90_dpm_reset_request_reset_key         0x000000ffU
#define SRT_NX90_dpm_reset_request_reset_key         0
#define DFLT_VAL_NX90_dpm_reset_request_reset_key    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_reset_request_reset_key 0x00000000U

/* all used bits of 'NX90_dpm_reset_request': */
#define MSK_USED_BITS_NX90_dpm_reset_request 0x000000ffU

enum {
  BFW_NX90_dpm_reset_request_reset_key = 8,  /* [7:0] */
  BFW_NX90_dpm_reset_request_reserved1 = 24  /* [31:8] */
};

typedef struct NX90_DPM_RESET_REQUEST_BIT_Ttag {
  unsigned int reset_key : BFW_NX90_dpm_reset_request_reset_key; /* Reset key sequence register.                                                                        */
                                                                 /* A netx hardware reset is generated if the following sequence is written to this register:           */
                                                                 /*   1st access:    write 0x00                                                                         */
                                                                 /*   2nd access:    write 0x01                                                                         */
                                                                 /*   3rd access:    write 0x03                                                                         */
                                                                 /*   4th access:    write 0x07                                                                         */
                                                                 /*   5th access:    write 0x0f                                                                         */
                                                                 /*   6th access:    write 0x1f                                                                         */
                                                                 /*   7th access:    write 0x3f                                                                         */
                                                                 /*   8th access:    write 0x7f                                                                         */
                                                                 /* To issue a reset the sequence must not be interrupted by a write access to another register         */
                                                                 /* of this DPM module register area. Writing 0x00 will always restart the sequence.                    */
                                                                 /* Reading this register will always provide the next write data. Hence it is also possible            */
                                                                 /* performing 8 times a read-write sequence to this register (however this is not required,            */
                                                                 /* simply writing the sequence will also succeed).                                                     */
                                                                 /* Writing any other value than the next expected by the DPM module, the internal reset FSM will       */
                                                                 /* be cleared and the register will return 0x00 for the next read. The FSM will also be cleared        */
                                                                 /* if the sequence is interrupted by a write access to any other register of this DPM register         */
                                                                 /* area. The sequence must be restarted with the 1st access (writing 0x00) in this case.               */
                                                                 /* Note:                                                                                               */
                                                                 /*    The DPM reset request is internally a level-signal, not only a pulse. Additionally the           */
                                                                 /*    DPM reset request could be masked (disabled) by the global reset controller (netX4000).          */
                                                                 /*    If the DPM reset request is disabled globally but issued by the DPM module there are two         */
                                                                 /*    possibilities to get out of this:                                                                */
                                                                 /*    1.: Enable the DPM reset in the global reset controller. The NETX will be reset then             */
                                                                 /*        immediately (typically this must be done by the NETX-side CPU and cannot be done by a host). */
                                                                 /*    2.: Write 0x00 (or any other value except 0xFF) to this register or perform a write              */
                                                                 /*        access to any other register of this DPM register area. This will clear the DPM              */
                                                                 /*        reset FSM and the reset request of this DPM module to the global reset controller.           */
                                                                 /* Note:                                                                                               */
                                                                 /*   For netx10 a 9th access (write 0xff) was necessary to perform a reset  This access                */
                                                                 /*   is not netx50 compatible and not required any longer since netx51/52.                             */
  unsigned int reserved1 : BFW_NX90_dpm_reset_request_reserved1; /* reserved                                                                                            */
} NX90_DPM_RESET_REQUEST_BIT_T;

typedef union {
  uint32_t                     val;
  NX90_DPM_RESET_REQUEST_BIT_T bf;
} NX90_DPM_RESET_REQUEST_T;

/* --------------------------------------------------------------------- */
/* Register dpm_firmware_irq_raw */
/* => 1st netx50 compatible DPM Interrupt Status Register (related to 'dpm_firmware_irq_mask'-register). */
/*    Writing a '1' to an IRQ flag will clear the Interrupt. This is always done even if related bit inside */
/*    'dpm_firmware_irq_mask'-register is not set (this is compatible to netx50). */
/*     */
/*    Important: There are two completely independent sets of IRQ registers: */
/*       IRQ register-set 1: 'dpm_irq_raw' (and related registers e.g. 'dpm_irq_host_dirq_*' registers). */
/*       IRQ register-set 2: 'dpm_firmware_irq_* registers' (netx50 compatible register set: DPM_HOST_INT_EN0,2 DPM_HOST_INT_STA0,2). */
/*       Programming (masking or clearing IRQs) of one register-set has no impact to the other register-set even if some IRQs */
/*       can be found in both sets (e.g. com0). */
/*     */
/*    Note: This register is compatible to netx50 DPM_HOST_INT_STAT0 register, however some unused */
/*       IRQs have been removed. */
/*     */
/*    Note: The 2nd firmware IRQ register set (dpm_firmware_irq_mask2, DPM_HOST_INT_EN2, dpm_firmware_irq_raw2, DPM_HOST_INT_STAT2) */
/*       are obsolete since netx4000. Some functions moved to the main DPM IRQ register set (view dpm_irq_raw). */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_firmware_irq_raw      0x000000E0U
#define Adr_NX90_dpm0_com_dpm_firmware_irq_raw 0xFF0019E0U
#define Adr_NX90_dpm1_com_dpm_firmware_irq_raw 0xFF001AE0U
#define DFLT_VAL_NX90_dpm_firmware_irq_raw     0x00000000U

#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT0               0x00000001U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT0               0
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT0          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT0       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT1               0x00000002U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT1               1
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT1          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT1       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT2               0x00000004U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT2               2
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT2          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT2       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT3               0x00000008U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT3               3
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT3          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT3       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT4               0x00000010U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT4               4
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT4          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT4       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT5               0x00000020U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT5               5
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT5          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT5       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT6               0x00000040U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT6               6
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT6          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT6       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT7               0x00000080U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT7               7
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT7          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT7       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT8               0x00000100U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT8               8
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT8          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT8       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT9               0x00000200U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT9               9
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT9          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT9       0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT10              0x00000400U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT10              10
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT10         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT10      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT11              0x00000800U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT11              11
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT11         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT11      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT12              0x00001000U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT12              12
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT12         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT12      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT13              0x00002000U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT13              13
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT13         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT13      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT14              0x00004000U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT14              14
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT14         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT14      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT15              0x00008000U
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT15              15
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT15         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT15      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_IRQ_VECTOR              0x00ff0000U
#define SRT_NX90_dpm_firmware_irq_raw_IRQ_VECTOR              16
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_IRQ_VECTOR         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_IRQ_VECTOR      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_res_TMR_ro              0x02000000U
#define SRT_NX90_dpm_firmware_irq_raw_res_TMR_ro              25
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_res_TMR_ro         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_res_TMR_ro      0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_SYS_STA                 0x04000000U
#define SRT_NX90_dpm_firmware_irq_raw_SYS_STA                 26
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_SYS_STA            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_SYS_STA         0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT             0x10000000U
#define SRT_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT             28
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT     0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro         0x20000000U
#define SRT_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro         29
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro 0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro          0x40000000U
#define SRT_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro          30
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro  0x00000000U
#define MSK_NX90_dpm_firmware_irq_raw_INT_REQ                 0x80000000U
#define SRT_NX90_dpm_firmware_irq_raw_INT_REQ                 31
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_INT_REQ            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_INT_REQ         0x00000000U

/* all used bits of 'NX90_dpm_firmware_irq_raw': */
#define MSK_USED_BITS_NX90_dpm_firmware_irq_raw 0xf6ffffffU

enum {
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT0       = 1, /* [0] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT1       = 1, /* [1] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT2       = 1, /* [2] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT3       = 1, /* [3] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT4       = 1, /* [4] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT5       = 1, /* [5] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT6       = 1, /* [6] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT7       = 1, /* [7] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT8       = 1, /* [8] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT9       = 1, /* [9] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT10      = 1, /* [10] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT11      = 1, /* [11] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT12      = 1, /* [12] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT13      = 1, /* [13] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT14      = 1, /* [14] */
  BFW_NX90_dpm_firmware_irq_raw_HS_EVENT15      = 1, /* [15] */
  BFW_NX90_dpm_firmware_irq_raw_IRQ_VECTOR      = 8, /* [23:16] */
  BFW_NX90_dpm_firmware_irq_raw_reserved1       = 1, /* [24] */
  BFW_NX90_dpm_firmware_irq_raw_res_TMR_ro      = 1, /* [25] */
  BFW_NX90_dpm_firmware_irq_raw_SYS_STA         = 1, /* [26] */
  BFW_NX90_dpm_firmware_irq_raw_reserved2       = 1, /* [27] */
  BFW_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT     = 1, /* [28] */
  BFW_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro = 1, /* [29] */
  BFW_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro  = 1, /* [30] */
  BFW_NX90_dpm_firmware_irq_raw_INT_REQ         = 1  /* [31] */
};

typedef struct NX90_DPM_FIRMWARE_IRQ_RAW_BIT_Ttag {
  unsigned int HS_EVENT0       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT0;       /* Handshake Event 0  IRQ status flag.                                                              */
  unsigned int HS_EVENT1       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT1;       /* Handshake Event 1  IRQ status flag.                                                              */
  unsigned int HS_EVENT2       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT2;       /* Handshake Event 2  IRQ status flag.                                                              */
  unsigned int HS_EVENT3       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT3;       /* Handshake Event 3  IRQ status flag.                                                              */
  unsigned int HS_EVENT4       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT4;       /* Handshake Event 4  IRQ status flag.                                                              */
  unsigned int HS_EVENT5       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT5;       /* Handshake Event 5  IRQ status flag.                                                              */
  unsigned int HS_EVENT6       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT6;       /* Handshake Event 6  IRQ status flag.                                                              */
  unsigned int HS_EVENT7       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT7;       /* Handshake Event 7  IRQ status flag.                                                              */
  unsigned int HS_EVENT8       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT8;       /* Handshake Event 8  IRQ status flag.                                                              */
  unsigned int HS_EVENT9       : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT9;       /* Handshake Event 9  IRQ status flag.                                                              */
  unsigned int HS_EVENT10      : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT10;      /* Handshake Event 10 IRQ status flag.                                                              */
  unsigned int HS_EVENT11      : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT11;      /* Handshake Event 11 IRQ status flag.                                                              */
  unsigned int HS_EVENT12      : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT12;      /* Handshake Event 12 IRQ status flag.                                                              */
  unsigned int HS_EVENT13      : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT13;      /* Handshake Event 13 IRQ status flag.                                                              */
  unsigned int HS_EVENT14      : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT14;      /* Handshake Event 14 IRQ status flag.                                                              */
  unsigned int HS_EVENT15      : BFW_NX90_dpm_firmware_irq_raw_HS_EVENT15;      /* Handshake Event 15 IRQ status flag.                                                              */
  unsigned int IRQ_VECTOR      : BFW_NX90_dpm_firmware_irq_raw_IRQ_VECTOR;      /* Interrupt Vector according to status flags generated by enabled IRQ sources.                     */
                                                                                /* {     |                                                                                          */
                                                                                /*  Code   IRQ status                                                                               */
                                                                                /*  0x00   No IRQ.                                                                                  */
                                                                                /*  ----   -------                                                                                  */
                                                                                /*  0x10   Handshake Cell 0 IRQ.                                                                    */
                                                                                /*  0x11   Handshake Cell 1 IRQ.                                                                    */
                                                                                /*  0x12   Handshake Cell 2 IRQ.                                                                    */
                                                                                /*  0x13   Handshake Cell 3 IRQ.                                                                    */
                                                                                /*  0x14   Handshake Cell 4 IRQ.                                                                    */
                                                                                /*  0x15   Handshake Cell 5 IRQ.                                                                    */
                                                                                /*  0x16   Handshake Cell 6 IRQ.                                                                    */
                                                                                /*  0x17   Handshake Cell 7 IRQ.                                                                    */
                                                                                /*  0x18   Handshake Cell 8 IRQ.                                                                    */
                                                                                /*  0x19   Handshake Cell 9 IRQ.                                                                    */
                                                                                /*  0x1a   Handshake Cell 10 IRQ.                                                                   */
                                                                                /*  0x1b   Handshake Cell 11 IRQ.                                                                   */
                                                                                /*  0x1c   Handshake Cell 12 IRQ.                                                                   */
                                                                                /*  0x1d   Handshake Cell 13 IRQ.                                                                   */
                                                                                /*  0x1e   Handshake Cell 14 IRQ.                                                                   */
                                                                                /*  0x1f   Handshake Cell 15 IRQ.                                                                   */
                                                                                /*  ----   -------                                                                                  */
                                                                                /*  0x67   RDY_TIMEOUT IRQ                                                                          */
                                                                                /*  0x70   SYS_STA IRQ                                                                              */
                                                                                /*  Other  values are reserved.}                                                                    */
                                                                                /* Note:                                                                                            */
                                                                                /*    The current IRQ state in VECTOR depends only on the single IRQ enable bits. It                */
                                                                                /*    does not depend on global IRQ enable INT_EN. VECTOR shows always the highest priority enabled */
                                                                                /*    flagged IRQ even is INT_EN is '0'.                                                            */
  unsigned int reserved1       : BFW_NX90_dpm_firmware_irq_raw_reserved1;       /* reserved                                                                                         */
  unsigned int res_TMR_ro      : BFW_NX90_dpm_firmware_irq_raw_res_TMR_ro;      /* reserved for Timer IRQ flag (not available in this netX version).                                */
  unsigned int SYS_STA         : BFW_NX90_dpm_firmware_irq_raw_SYS_STA;         /* System Status Change IRQ flag.                                                                   */
  unsigned int reserved2       : BFW_NX90_dpm_firmware_irq_raw_reserved2;       /* reserved                                                                                         */
  unsigned int RDY_TIMEOUT     : BFW_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT;     /* DPM_RDY timeout error was detected.                                                              */
                                                                                /* Note:                                                                                            */
                                                                                /*    This flag is not affected by 'dpm_status_err' registers.                                      */
  unsigned int res_WDG_NETX_ro : BFW_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro; /* reserved for netX supervision Watchdog Timeout IRQ flag (not available in this netX version).    */
  unsigned int res_MEM_LCK_ro  : BFW_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro;  /* reserved for Memory Lock IRQ flag (not available in this netX version).                          */
  unsigned int INT_REQ         : BFW_NX90_dpm_firmware_irq_raw_INT_REQ;         /* Interrupt Request for IRQs handled in this register.                                             */
                                                                                /* 0: No Interrupts to host requested by IRQ sources handled in this register.                      */
                                                                                /* 1: IRQ sources handled in this register request a host IRQ.                                      */
                                                                                /* Note: This bit is masked by INT_EN-bit in dpm_firmware_irq_mask register.                        */
                                                                                /*    For propagation of INT_REQ to host, ARM or xPIC, INT_EN-bit must be set and firmware IRQ      */
                                                                                /*    must be activated in related dpm_irq_* register.                                              */
} NX90_DPM_FIRMWARE_IRQ_RAW_BIT_T;

typedef union {
  uint32_t                        val;
  NX90_DPM_FIRMWARE_IRQ_RAW_BIT_T bf;
} NX90_DPM_FIRMWARE_IRQ_RAW_T;

/* --------------------------------------------------------------------- */
/* Register dpm_firmware_irq_mask */
/* => DPM Handshake Interrupt Enable Register. */
/*    Only netx50 compatible 'dpm_firmware_irq' registers are related to settings of this register. */
/*     */
/*    Note: This register is compatible to netx50 DPM_HOST_INT_EN0 register, however some unused */
/*       IRQs have been removed. */
/*     */
/*    Note: HS_EVENT-bits are not read-only. This is netX50 compliant. */
/*       Recent netX50 Documentation marks HS_EVENT-bits as read-only. This is an documentation error. */
/*       For netX50 compatibility, these bits can also be controlled from netX-side in HANDSHAKE_CTRL address area. */
/*     */
/*    Note: The 2nd firmware IRQ register set (dpm_firmware_irq_mask2, DPM_HOST_INT_EN2, dpm_firmware_irq_raw2, DPM_HOST_INT_STAT2) */
/*       are obsolete since netx4000. Some functions moved to the main DPM IRQ register set (view dpm_irq_raw). */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_firmware_irq_mask      0x000000F0U
#define Adr_NX90_dpm0_com_dpm_firmware_irq_mask 0xFF0019F0U
#define Adr_NX90_dpm1_com_dpm_firmware_irq_mask 0xFF001AF0U
#define DFLT_VAL_NX90_dpm_firmware_irq_mask     0x00000000U

#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT0               0x00000001U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT0               0
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT0          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT0       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT1               0x00000002U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT1               1
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT1          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT1       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT2               0x00000004U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT2               2
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT2          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT2       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT3               0x00000008U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT3               3
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT3          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT3       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT4               0x00000010U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT4               4
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT4          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT4       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT5               0x00000020U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT5               5
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT5          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT5       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT6               0x00000040U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT6               6
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT6          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT6       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT7               0x00000080U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT7               7
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT7          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT7       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT8               0x00000100U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT8               8
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT8          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT8       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT9               0x00000200U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT9               9
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT9          0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT9       0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT10              0x00000400U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT10              10
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT10         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT10      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT11              0x00000800U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT11              11
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT11         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT11      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT12              0x00001000U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT12              12
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT12         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT12      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT13              0x00002000U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT13              13
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT13         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT13      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT14              0x00004000U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT14              14
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT14         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT14      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT15              0x00008000U
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT15              15
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT15         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT15      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_res_TMR_ro              0x02000000U
#define SRT_NX90_dpm_firmware_irq_mask_res_TMR_ro              25
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_res_TMR_ro         0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_res_TMR_ro      0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_SYS_STA                 0x04000000U
#define SRT_NX90_dpm_firmware_irq_mask_SYS_STA                 26
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_SYS_STA            0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_SYS_STA         0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT             0x10000000U
#define SRT_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT             28
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT        0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT     0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro         0x20000000U
#define SRT_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro         29
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro    0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro 0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro          0x40000000U
#define SRT_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro          30
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro     0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro  0x00000000U
#define MSK_NX90_dpm_firmware_irq_mask_INT_EN                  0x80000000U
#define SRT_NX90_dpm_firmware_irq_mask_INT_EN                  31
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_INT_EN             0x00000000U
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_INT_EN          0x00000000U

/* all used bits of 'NX90_dpm_firmware_irq_mask': */
#define MSK_USED_BITS_NX90_dpm_firmware_irq_mask 0xf600ffffU

enum {
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT0       = 1, /* [0] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT1       = 1, /* [1] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT2       = 1, /* [2] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT3       = 1, /* [3] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT4       = 1, /* [4] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT5       = 1, /* [5] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT6       = 1, /* [6] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT7       = 1, /* [7] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT8       = 1, /* [8] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT9       = 1, /* [9] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT10      = 1, /* [10] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT11      = 1, /* [11] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT12      = 1, /* [12] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT13      = 1, /* [13] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT14      = 1, /* [14] */
  BFW_NX90_dpm_firmware_irq_mask_HS_EVENT15      = 1, /* [15] */
  BFW_NX90_dpm_firmware_irq_mask_reserved1       = 9, /* [24:16] */
  BFW_NX90_dpm_firmware_irq_mask_res_TMR_ro      = 1, /* [25] */
  BFW_NX90_dpm_firmware_irq_mask_SYS_STA         = 1, /* [26] */
  BFW_NX90_dpm_firmware_irq_mask_reserved2       = 1, /* [27] */
  BFW_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT     = 1, /* [28] */
  BFW_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro = 1, /* [29] */
  BFW_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro  = 1, /* [30] */
  BFW_NX90_dpm_firmware_irq_mask_INT_EN          = 1  /* [31] */
};

typedef struct NX90_DPM_FIRMWARE_IRQ_MASK_BIT_Ttag {
  unsigned int HS_EVENT0       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT0;       /* Handshake Event 0  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT1       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT1;       /* Handshake Event 1  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT2       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT2;       /* Handshake Event 2  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT3       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT3;       /* Handshake Event 3  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT4       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT4;       /* Handshake Event 4  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT5       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT5;       /* Handshake Event 5  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT6       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT6;       /* Handshake Event 6  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT7       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT7;       /* Handshake Event 7  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT8       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT8;       /* Handshake Event 8  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT9       : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT9;       /* Handshake Event 9  IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT10      : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT10;      /* Handshake Event 10 IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT11      : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT11;      /* Handshake Event 11 IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT12      : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT12;      /* Handshake Event 12 IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT13      : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT13;      /* Handshake Event 13 IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT14      : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT14;      /* Handshake Event 14 IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int HS_EVENT15      : BFW_NX90_dpm_firmware_irq_mask_HS_EVENT15;      /* Handshake Event 15 IRQ Enable (also netX-controllable by HANDSHAKE_CTRL, netX50 comp.).       */
  unsigned int reserved1       : BFW_NX90_dpm_firmware_irq_mask_reserved1;       /* reserved                                                                                      */
  unsigned int res_TMR_ro      : BFW_NX90_dpm_firmware_irq_mask_res_TMR_ro;      /* reserved for Timer IRQ (not available in this netX version).                                  */
  unsigned int SYS_STA         : BFW_NX90_dpm_firmware_irq_mask_SYS_STA;         /* System Status Change IRQ Enable.                                                              */
  unsigned int reserved2       : BFW_NX90_dpm_firmware_irq_mask_reserved2;       /* reserved                                                                                      */
  unsigned int RDY_TIMEOUT     : BFW_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT;     /* Enable for 'dpm_firmware_irq_raw.RDY_TIMEOUT' bit.                                            */
  unsigned int res_WDG_NETX_ro : BFW_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro; /* reserved for netX supervision Watchdog Timeout IRQ (not available in this netX version).      */
  unsigned int res_MEM_LCK_ro  : BFW_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro;  /* reserved for Memory Lock IRQ (not available in this netX version).                            */
  unsigned int INT_EN          : BFW_NX90_dpm_firmware_irq_mask_INT_EN;          /* Interrupt Enable for IRQs handled in this register.                                           */
                                                                                 /* Only if this bit is set, global firmware IRQ will be asserted to host CPU, ARM or xPIC        */
                                                                                 /* by dpm_irq_* registers.                                                                       */
                                                                                 /* 0: No Interrupts to host, ARM or xPIC are generated by IRQ sources handled in this register.  */
                                                                                 /* 1: Enabled IRQ sources handled in this register generate a host, ARM or xPIC IRQ if asserted. */
                                                                                 /* Note: Enable bits for single IRQ events are not affected if this bit is set or reset.         */
} NX90_DPM_FIRMWARE_IRQ_MASK_BIT_T;

typedef union {
  uint32_t                         val;
  NX90_DPM_FIRMWARE_IRQ_MASK_BIT_T bf;
} NX90_DPM_FIRMWARE_IRQ_MASK_T;

/* --------------------------------------------------------------------- */
/* Register dpm_netx_version_bigend16 */
/* => DPM netX Version Register in big endianess 16 data mapping. */
/*    This registers content is mirrored form asic_ctrl register area and can be set during netX booting phase by netX firmware. */
/*    This register is not valid if unlocked bit is not set in dpm_status register. */
/*    Together with dpm_netx_version register, full 32 bit version can be read by any host device, even if DPM interface is not initialized yet. */
/*    Bytes byte1 and byte3 can be always read here even if DPM is uninitialized (8 bit default from dpm_cfg0x0 after power on) and */
/*    host device has 8, 16 or 32 bit data width. */
/*    {                 |                           |                           | */
/*                        8 bit DPM                   16 bit DPM                  32 bit DPM */
/*      byte 0 (D7:0)     byte read this address +1   adr_dpm_netx_version        adr_dpm_netx_version */
/*      byte 1 (D15:8)    byte read this address +0   byte read this address      DWord read this address */
/*      byte 2 (D23:16)   byte read this address +3   adr_dpm_netx_version        adr_dpm_netx_version */
/*      byte 3 (D31:24)   byte read this address +2   byte read this address +2   byte read this address +0 } */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_netx_version_bigend16      0x000000F4U
#define Adr_NX90_dpm0_com_dpm_netx_version_bigend16 0xFF0019F4U
#define Adr_NX90_dpm1_com_dpm_netx_version_bigend16 0xFF001AF4U

#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte1_swap 0x000000ffU
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte1_swap 0
#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte0_swap 0x0000ff00U
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte0_swap 8
#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte3_swap 0x00ff0000U
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte3_swap 16
#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte2_swap 0xff000000U
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte2_swap 24

/* all used bits of 'NX90_dpm_netx_version_bigend16': */
#define MSK_USED_BITS_NX90_dpm_netx_version_bigend16 0xffffffffU

enum {
  BFW_NX90_dpm_netx_version_bigend16_netx_version_byte1_swap = 8, /* [7:0] */
  BFW_NX90_dpm_netx_version_bigend16_netx_version_byte0_swap = 8, /* [15:8] */
  BFW_NX90_dpm_netx_version_bigend16_netx_version_byte3_swap = 8, /* [23:16] */
  BFW_NX90_dpm_netx_version_bigend16_netx_version_byte2_swap = 8  /* [31:24] */
};

typedef struct NX90_DPM_NETX_VERSION_BIGEND16_BIT_Ttag {
  unsigned int netx_version_byte1_swap : BFW_NX90_dpm_netx_version_bigend16_netx_version_byte1_swap; /* netX version bits 16 to 8.  */
  unsigned int netx_version_byte0_swap : BFW_NX90_dpm_netx_version_bigend16_netx_version_byte0_swap; /* netX version bits 8 to 0.   */
  unsigned int netx_version_byte3_swap : BFW_NX90_dpm_netx_version_bigend16_netx_version_byte3_swap; /* netX version bits 31 to 24. */
  unsigned int netx_version_byte2_swap : BFW_NX90_dpm_netx_version_bigend16_netx_version_byte2_swap; /* netX version bits 24 to 16. */
} NX90_DPM_NETX_VERSION_BIGEND16_BIT_T;

typedef union {
  uint32_t                             val;
  NX90_DPM_NETX_VERSION_BIGEND16_BIT_T bf;
} NX90_DPM_NETX_VERSION_BIGEND16_T;

/* --------------------------------------------------------------------- */
/* Register dpm_netx_version */
/* => DPM netX Version Register. */
/*    This register is mirrored form asic_ctrl register area and can be set during netX booting phase by netX firmware. */
/*    This register is not valid if unlocked bit is not set in dpm_status register. */
/*    Together with dpm_netx_version register, full 32 bit version can be read by any host device, even if DPM interface is not initialized yet. */
/*    Bytes byte0 and byte2 can be always read here even if DPM is uninitialized (8 bit default from dpm_cfg0x0 after power on) and */
/*    host device has 8, 16 or 32 bit data width. */
/*    {                 |                           |                               | */
/*                        8 bit DPM                   16 bit DPM                     32 bit DPM */
/*      byte 0 (D7:0)     byte read this address +0   byte read this address          DWord read this address */
/*      byte 1 (D15:8)    byte read this address +1   adr_dpm_netx_version_bigend16   adr_dpm_netx_version_bigend16 */
/*      byte 2 (D23:16)   byte read this address +2   byte read this address +2       byte read this address +0 */
/*      byte 3 (D31:24)   byte read this address +3   adr_dpm_netx_version_bigend16   adr_dpm_netx_version_bigend16 } */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_netx_version      0x000000FCU
#define Adr_NX90_dpm0_com_dpm_netx_version 0xFF0019FCU
#define Adr_NX90_dpm1_com_dpm_netx_version 0xFF001AFCU

#define MSK_NX90_dpm_netx_version_netx_version_byte0 0x000000ffU
#define SRT_NX90_dpm_netx_version_netx_version_byte0 0
#define MSK_NX90_dpm_netx_version_netx_version_byte1 0x0000ff00U
#define SRT_NX90_dpm_netx_version_netx_version_byte1 8
#define MSK_NX90_dpm_netx_version_netx_version_byte2 0x00ff0000U
#define SRT_NX90_dpm_netx_version_netx_version_byte2 16
#define MSK_NX90_dpm_netx_version_netx_version_byte3 0xff000000U
#define SRT_NX90_dpm_netx_version_netx_version_byte3 24

/* all used bits of 'NX90_dpm_netx_version': */
#define MSK_USED_BITS_NX90_dpm_netx_version 0xffffffffU

enum {
  BFW_NX90_dpm_netx_version_netx_version_byte0 = 8, /* [7:0] */
  BFW_NX90_dpm_netx_version_netx_version_byte1 = 8, /* [15:8] */
  BFW_NX90_dpm_netx_version_netx_version_byte2 = 8, /* [23:16] */
  BFW_NX90_dpm_netx_version_netx_version_byte3 = 8  /* [31:24] */
};

typedef struct NX90_DPM_NETX_VERSION_BIT_Ttag {
  unsigned int netx_version_byte0 : BFW_NX90_dpm_netx_version_netx_version_byte0; /* netX version bits 8 to 0.   */
  unsigned int netx_version_byte1 : BFW_NX90_dpm_netx_version_netx_version_byte1; /* netX version bits 16 to 8.  */
  unsigned int netx_version_byte2 : BFW_NX90_dpm_netx_version_netx_version_byte2; /* netX version bits 24 to 16. */
  unsigned int netx_version_byte3 : BFW_NX90_dpm_netx_version_netx_version_byte3; /* netX version bits 31 to 24. */
} NX90_DPM_NETX_VERSION_BIT_T;

typedef union {
  uint32_t                    val;
  NX90_DPM_NETX_VERSION_BIT_T bf;
} NX90_DPM_NETX_VERSION_T;




/*********************************************************************/
/* area structure definitions                                        */
/*********************************************************************/


typedef struct NX90_DPM_AREA_Ttag
{
  volatile uint32_t  ulDpm_cfg0x0;
  volatile uint32_t  ulDpm_if_cfg;
  volatile uint32_t aulDpm_pio_cfg[2];
  volatile uint32_t  ulDpm_addr_cfg;
  volatile uint32_t  ulDpm_timing_cfg;
  volatile uint32_t  ulDpm_rdy_cfg;
  volatile uint32_t  ulDpm_status;
  volatile uint32_t  ulDpm_status_err_reset;
  volatile uint32_t  ulDpm_status_err_addr;
  volatile uint32_t  ulDpm_misc_cfg;
  volatile uint32_t  ulDpm_io_cfg_misc;
  volatile uint32_t aulReserved0[2];
  volatile uint32_t  ulDpm_tunnel_cfg;
  volatile uint32_t  ulDpm_itbaddr;
  volatile uint32_t  ulDpm_win1_end;
  volatile uint32_t  ulDpm_win1_map;
  volatile uint32_t  ulDpm_win2_end;
  volatile uint32_t  ulDpm_win2_map;
  volatile uint32_t  ulDpm_win3_end;
  volatile uint32_t  ulDpm_win3_map;
  volatile uint32_t  ulDpm_win4_end;
  volatile uint32_t  ulDpm_win4_map;
  volatile uint32_t aulReserved1[8];
  volatile uint32_t aulDpm_irq_raw[2];
  volatile uint32_t aulDpm_irq_host_sirq_mask_set[2];
  volatile uint32_t aulDpm_irq_host_sirq_mask_reset[2];
  volatile uint32_t aulDpm_irq_host_sirq_masked[2];
  volatile uint32_t aulDpm_irq_host_dirq_mask_set[2];
  volatile uint32_t aulDpm_irq_host_dirq_mask_reset[2];
  volatile uint32_t aulDpm_irq_host_dirq_masked[2];
  volatile uint32_t  ulDpm_sw_irq;
  volatile uint32_t  ulDpm_crc;
  volatile uint32_t  ulDpm_reserved_netx50_wgd_host_timeout;
  volatile uint32_t  ulDpm_reserved_netx50_wgd_host_trigger;
  volatile uint32_t  ulDpm_reserved_netx50_wgd_netx_timeout;
  volatile uint32_t  ulDpm_sys_sta_bigend16;
  volatile uint32_t  ulDpm_reserved_netx50_timer_ctrl;
  volatile uint32_t  ulDpm_reserved_netx50_timer_start_val;
  volatile uint32_t  ulDpm_sys_sta;
  volatile uint32_t  ulDpm_reset_request;
  volatile uint32_t  ulDpm_firmware_irq_raw;
  volatile uint32_t aulReserved2[3];
  volatile uint32_t  ulDpm_firmware_irq_mask;
  volatile uint32_t  ulDpm_netx_version_bigend16;
  volatile uint32_t aulReserved3[1];
  volatile uint32_t  ulDpm_netx_version;
} NX90_DPM_AREA_T;


#endif
