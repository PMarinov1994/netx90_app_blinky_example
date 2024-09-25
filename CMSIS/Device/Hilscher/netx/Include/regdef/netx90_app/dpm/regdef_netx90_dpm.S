/*********************************************************************/
/* Based on verilog file from: 190308_0616                           */
/* SVN Revision: $Rev: 1158 $        release-1.4.0.1                 */
/* from regdef.v by regdef2h auto-generated C-header file            */
/* please see the regdef.html file for detailed register description */
/*********************************************************************/

#ifndef __regdef_netx90_dpm_h__
#define __regdef_netx90_dpm_h__


/* ===================================================================== */

/* AREA dpm */
/* Area of dpm0_com, dpm1_com */

/* ===================================================================== */

#define Addr_NX90_dpm0_com 0xFF001900
#define Addr_NX90_dpm1_com 0xFF001A00

/* --------------------------------------------------------------------- */
/* Register dpm_cfg0x0 */
/* => DPM IO Control Register 0. */
/*    This register is accessible in any DPM-mode (8, 16 bit, SRAM, Intel, Motorola, little endian, big endian) by access to DPM address 0. */
/*    Basic DPM settings are configurable here to make higher addresses accessible. */
/*    To avoid instable system configurations, global changes of important configuration registers must be confirmed */
/*    (re)writing 'mode' bit field of this register. View 'mode' description for details. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_cfg0x0      0x00000000
#define Adr_NX90_dpm0_com_dpm_cfg0x0 0xFF001900
#define Adr_NX90_dpm1_com_dpm_cfg0x0 0xFF001A00
#define DFLT_VAL_NX90_dpm_cfg0x0     0x00000000

#define MSK_NX90_dpm_cfg0x0_mode           0x0000000f
#define SRT_NX90_dpm_cfg0x0_mode           0
#define DFLT_VAL_NX90_dpm_cfg0x0_mode      0x00000000
#define DFLT_BF_VAL_NX90_dpm_cfg0x0_mode   0x00000000
#define MSK_NX90_dpm_cfg0x0_endian         0x00000030
#define SRT_NX90_dpm_cfg0x0_endian         4
#define DFLT_VAL_NX90_dpm_cfg0x0_endian    0x00000000
#define DFLT_BF_VAL_NX90_dpm_cfg0x0_endian 0x00000000

/* all used bits of 'NX90_dpm_cfg0x0': */
#define MSK_USED_BITS_NX90_dpm_cfg0x0 0x0000003f

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

#define REL_Adr_NX90_dpm_if_cfg      0x00000004
#define Adr_NX90_dpm0_com_dpm_if_cfg 0xFF001904
#define Adr_NX90_dpm1_com_dpm_if_cfg 0xFF001A04
#define DFLT_VAL_NX90_dpm_if_cfg     0x00000000

#define MSK_NX90_dpm_if_cfg_dir_ctrl          0x00000003
#define SRT_NX90_dpm_if_cfg_dir_ctrl          0
#define DFLT_VAL_NX90_dpm_if_cfg_dir_ctrl     0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_dir_ctrl  0x00000000
#define MSK_NX90_dpm_if_cfg_be_sel            0x00000010
#define SRT_NX90_dpm_if_cfg_be_sel            4
#define DFLT_VAL_NX90_dpm_if_cfg_be_sel       0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_sel    0x00000000
#define MSK_NX90_dpm_if_cfg_be_rd_dis         0x00000040
#define SRT_NX90_dpm_if_cfg_be_rd_dis         6
#define DFLT_VAL_NX90_dpm_if_cfg_be_rd_dis    0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_rd_dis 0x00000000
#define MSK_NX90_dpm_if_cfg_be_wr_dis         0x00000080
#define SRT_NX90_dpm_if_cfg_be_wr_dis         7
#define DFLT_VAL_NX90_dpm_if_cfg_be_wr_dis    0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_wr_dis 0x00000000
#define MSK_NX90_dpm_if_cfg_be_pol            0x00000300
#define SRT_NX90_dpm_if_cfg_be_pol            8
#define DFLT_VAL_NX90_dpm_if_cfg_be_pol       0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_be_pol    0x00000000
#define MSK_NX90_dpm_if_cfg_aen_sel           0x00003000
#define SRT_NX90_dpm_if_cfg_aen_sel           12
#define DFLT_VAL_NX90_dpm_if_cfg_aen_sel      0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_aen_sel   0x00000000
#define MSK_NX90_dpm_if_cfg_aen_pol           0x00004000
#define SRT_NX90_dpm_if_cfg_aen_pol           14
#define DFLT_VAL_NX90_dpm_if_cfg_aen_pol      0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_aen_pol   0x00000000
#define MSK_NX90_dpm_if_cfg_addr_sh           0x00008000
#define SRT_NX90_dpm_if_cfg_addr_sh           15
#define DFLT_VAL_NX90_dpm_if_cfg_addr_sh      0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_addr_sh   0x00000000
#define MSK_NX90_dpm_if_cfg_cs_ctrl           0x00070000
#define SRT_NX90_dpm_if_cfg_cs_ctrl           16
#define DFLT_VAL_NX90_dpm_if_cfg_cs_ctrl      0x00000000
#define DFLT_BF_VAL_NX90_dpm_if_cfg_cs_ctrl   0x00000000

/* all used bits of 'NX90_dpm_if_cfg': */
#define MSK_USED_BITS_NX90_dpm_if_cfg 0x0007f3d3

/* --------------------------------------------------------------------- */
/* Register dpm_pio_cfg0 */
/* => DPM PIO Configuration Register0. */
/*    Signals to be used as PIOs when netX DPM is active must be selected here or in 'dpm_pio_cfg1' register. Since netx51/52 */
/*    PIO function will not be automatically activated depending on other settings. E.g. DPM_D15..8 can not be used */
/*    automatically when 8 bit data mode is selected. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_pio_cfg0      0x00000008
#define Adr_NX90_dpm0_com_dpm_pio_cfg0 0xFF001908
#define Adr_NX90_dpm1_com_dpm_pio_cfg0 0xFF001A08
#define DFLT_VAL_NX90_dpm_pio_cfg0     0x00000000

#define MSK_NX90_dpm_pio_cfg0_sel_d_pio         0x0000ffff
#define SRT_NX90_dpm_pio_cfg0_sel_d_pio         0
#define DFLT_VAL_NX90_dpm_pio_cfg0_sel_d_pio    0x00000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg0_sel_d_pio 0x00000000

/* all used bits of 'NX90_dpm_pio_cfg0': */
#define MSK_USED_BITS_NX90_dpm_pio_cfg0 0x0000ffff

/* --------------------------------------------------------------------- */
/* Register dpm_pio_cfg1 */
/* => DPM PIO Configuration Register1. */
/*    PIO usage of DPM_SIRQ, DPM_DIRQ and DPM_RDY has moved from 'dpm_io_cfg_misc' to this register since netx51/52. */
/*    Signals to be used as PIOs when netX DPM is active must be selected here or in 'dpm_pio_cfg0' register. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_pio_cfg1      0x0000000C
#define Adr_NX90_dpm0_com_dpm_pio_cfg1 0xFF00190C
#define Adr_NX90_dpm1_com_dpm_pio_cfg1 0xFF001A0C
#define DFLT_VAL_NX90_dpm_pio_cfg1     0xe0000000

#define MSK_NX90_dpm_pio_cfg1_sel_a_pio            0x000fffff
#define SRT_NX90_dpm_pio_cfg1_sel_a_pio            0
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_a_pio       0x00000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_a_pio    0x00000000
#define MSK_NX90_dpm_pio_cfg1_sel_bhe1_pio         0x01000000
#define SRT_NX90_dpm_pio_cfg1_sel_bhe1_pio         24
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_bhe1_pio    0x00000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_bhe1_pio 0x00000000
#define MSK_NX90_dpm_pio_cfg1_sel_csn_pio          0x04000000
#define SRT_NX90_dpm_pio_cfg1_sel_csn_pio          26
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_csn_pio     0x00000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_csn_pio  0x00000000
#define MSK_NX90_dpm_pio_cfg1_sel_rdn_pio          0x08000000
#define SRT_NX90_dpm_pio_cfg1_sel_rdn_pio          27
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_rdn_pio     0x00000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_rdn_pio  0x00000000
#define MSK_NX90_dpm_pio_cfg1_sel_wrn_pio          0x10000000
#define SRT_NX90_dpm_pio_cfg1_sel_wrn_pio          28
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_wrn_pio     0x00000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_wrn_pio  0x00000000
#define MSK_NX90_dpm_pio_cfg1_sel_rdy_pio          0x20000000
#define SRT_NX90_dpm_pio_cfg1_sel_rdy_pio          29
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_rdy_pio     0x20000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_rdy_pio  0x00000001
#define MSK_NX90_dpm_pio_cfg1_sel_dirq_pio         0x40000000
#define SRT_NX90_dpm_pio_cfg1_sel_dirq_pio         30
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_dirq_pio    0x40000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_dirq_pio 0x00000001
#define MSK_NX90_dpm_pio_cfg1_sel_sirq_pio         0x80000000
#define SRT_NX90_dpm_pio_cfg1_sel_sirq_pio         31
#define DFLT_VAL_NX90_dpm_pio_cfg1_sel_sirq_pio    0x80000000
#define DFLT_BF_VAL_NX90_dpm_pio_cfg1_sel_sirq_pio 0x00000001

/* all used bits of 'NX90_dpm_pio_cfg1': */
#define MSK_USED_BITS_NX90_dpm_pio_cfg1 0xfd0fffff

/* --------------------------------------------------------------------- */
/* Register dpm_addr_cfg */
/* => DPM External Address Configuration Register. */
/*    Note: */
/*       There are no internal address comparators and no DPM_SELA* functions available for netX90. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_addr_cfg      0x00000010
#define Adr_NX90_dpm0_com_dpm_addr_cfg 0xFF001910
#define Adr_NX90_dpm1_com_dpm_addr_cfg 0xFF001A10
#define DFLT_VAL_NX90_dpm_addr_cfg     0x00000002

#define MSK_NX90_dpm_addr_cfg_addr_range               0x0000000f
#define SRT_NX90_dpm_addr_cfg_addr_range               0
#define DFLT_VAL_NX90_dpm_addr_cfg_addr_range          0x00000002
#define DFLT_BF_VAL_NX90_dpm_addr_cfg_addr_range       0x00000002
#define MSK_NX90_dpm_addr_cfg_cfg_win_addr_cfg         0x00000030
#define SRT_NX90_dpm_addr_cfg_cfg_win_addr_cfg         4
#define DFLT_VAL_NX90_dpm_addr_cfg_cfg_win_addr_cfg    0x00000000
#define DFLT_BF_VAL_NX90_dpm_addr_cfg_cfg_win_addr_cfg 0x00000000

/* all used bits of 'NX90_dpm_addr_cfg': */
#define MSK_USED_BITS_NX90_dpm_addr_cfg 0x0000003f

/* --------------------------------------------------------------------- */
/* Register dpm_timing_cfg */
/* => DPM timing and access configuration register. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_timing_cfg      0x00000014
#define Adr_NX90_dpm0_com_dpm_timing_cfg 0xFF001914
#define Adr_NX90_dpm1_com_dpm_timing_cfg 0xFF001A14
#define DFLT_VAL_NX90_dpm_timing_cfg     0x00000027

#define MSK_NX90_dpm_timing_cfg_t_osa                     0x00000003
#define SRT_NX90_dpm_timing_cfg_t_osa                     0
#define DFLT_VAL_NX90_dpm_timing_cfg_t_osa                0x00000003
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_t_osa             0x00000003
#define MSK_NX90_dpm_timing_cfg_filter                    0x00000004
#define SRT_NX90_dpm_timing_cfg_filter                    2
#define DFLT_VAL_NX90_dpm_timing_cfg_filter               0x00000004
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_filter            0x00000001
#define MSK_NX90_dpm_timing_cfg_t_rds                     0x00000070
#define SRT_NX90_dpm_timing_cfg_t_rds                     4
#define DFLT_VAL_NX90_dpm_timing_cfg_t_rds                0x00000020
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_t_rds             0x00000002
#define MSK_NX90_dpm_timing_cfg_rd_burst_en               0x00000080
#define SRT_NX90_dpm_timing_cfg_rd_burst_en               7
#define DFLT_VAL_NX90_dpm_timing_cfg_rd_burst_en          0x00000000
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_rd_burst_en       0x00000000
#define MSK_NX90_dpm_timing_cfg_en_dpm_serial_sqi         0x40000000
#define SRT_NX90_dpm_timing_cfg_en_dpm_serial_sqi         30
#define DFLT_VAL_NX90_dpm_timing_cfg_en_dpm_serial_sqi    0x00000000
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_en_dpm_serial_sqi 0x00000000
#define MSK_NX90_dpm_timing_cfg_sdpm_miso_early           0x80000000
#define SRT_NX90_dpm_timing_cfg_sdpm_miso_early           31
#define DFLT_VAL_NX90_dpm_timing_cfg_sdpm_miso_early      0x00000000
#define DFLT_BF_VAL_NX90_dpm_timing_cfg_sdpm_miso_early   0x00000000

/* all used bits of 'NX90_dpm_timing_cfg': */
#define MSK_USED_BITS_NX90_dpm_timing_cfg 0xc00000f7

/* --------------------------------------------------------------------- */
/* Register dpm_rdy_cfg */
/* => DPM Ready (DPM_RDY) Signal Configuration Register. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_rdy_cfg      0x00000018
#define Adr_NX90_dpm0_com_dpm_rdy_cfg 0xFF001918
#define Adr_NX90_dpm1_com_dpm_rdy_cfg 0xFF001A18
#define DFLT_VAL_NX90_dpm_rdy_cfg     0x00000001

#define MSK_NX90_dpm_rdy_cfg_rdy_pol              0x00000001
#define SRT_NX90_dpm_rdy_cfg_rdy_pol              0
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_pol         0x00000001
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_pol      0x00000001
#define MSK_NX90_dpm_rdy_cfg_rdy_drv_mode         0x00000006
#define SRT_NX90_dpm_rdy_cfg_rdy_drv_mode         1
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_drv_mode    0x00000000
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_drv_mode 0x00000000
#define MSK_NX90_dpm_rdy_cfg_rdy_sig_mode         0x00000008
#define SRT_NX90_dpm_rdy_cfg_rdy_sig_mode         3
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_sig_mode    0x00000000
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_sig_mode 0x00000000
#define MSK_NX90_dpm_rdy_cfg_rdy_to_cfg           0x00000030
#define SRT_NX90_dpm_rdy_cfg_rdy_to_cfg           4
#define DFLT_VAL_NX90_dpm_rdy_cfg_rdy_to_cfg      0x00000000
#define DFLT_BF_VAL_NX90_dpm_rdy_cfg_rdy_to_cfg   0x00000000

/* all used bits of 'NX90_dpm_rdy_cfg': */
#define MSK_USED_BITS_NX90_dpm_rdy_cfg 0x0000003f

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

#define REL_Adr_NX90_dpm_status      0x0000001C
#define Adr_NX90_dpm0_com_dpm_status 0xFF00191C
#define Adr_NX90_dpm1_com_dpm_status 0xFF001A1C

#define MSK_NX90_dpm_status_unlocked                 0x00000001
#define SRT_NX90_dpm_status_unlocked                 0
#define MSK_NX90_dpm_status_rd_err                   0x00000002
#define SRT_NX90_dpm_status_rd_err                   1
#define MSK_NX90_dpm_status_wr_err                   0x00000004
#define SRT_NX90_dpm_status_wr_err                   2
#define MSK_NX90_dpm_status_rdy_to_err               0x00000008
#define SRT_NX90_dpm_status_rdy_to_err               3
#define MSK_NX90_dpm_status_bus_conflict_wr_err      0x00000010
#define SRT_NX90_dpm_status_bus_conflict_wr_err      4
#define MSK_NX90_dpm_status_bus_conflict_rd_err      0x00000020
#define SRT_NX90_dpm_status_bus_conflict_rd_err      5
#define MSK_NX90_dpm_status_bus_conflict_rd_addr_err 0x00000040
#define SRT_NX90_dpm_status_bus_conflict_rd_addr_err 6
#define MSK_NX90_dpm_status_sel_dpm_serial           0x00000080
#define SRT_NX90_dpm_status_sel_dpm_serial           7
#define MSK_NX90_dpm_status_abort_err                0x00000100
#define SRT_NX90_dpm_status_abort_err                8

/* all used bits of 'NX90_dpm_status': */
#define MSK_USED_BITS_NX90_dpm_status 0x000001ff

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

#define REL_Adr_NX90_dpm_status_err_reset      0x00000020
#define Adr_NX90_dpm0_com_dpm_status_err_reset 0xFF001920
#define Adr_NX90_dpm1_com_dpm_status_err_reset 0xFF001A20
#define DFLT_VAL_NX90_dpm_status_err_reset     0x00000000

#define MSK_NX90_dpm_status_err_reset_rd_err_rst                           0x00000002
#define SRT_NX90_dpm_status_err_reset_rd_err_rst                           1
#define DFLT_VAL_NX90_dpm_status_err_reset_rd_err_rst                      0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_rd_err_rst                   0x00000000
#define MSK_NX90_dpm_status_err_reset_wr_err_rst                           0x00000004
#define SRT_NX90_dpm_status_err_reset_wr_err_rst                           2
#define DFLT_VAL_NX90_dpm_status_err_reset_wr_err_rst                      0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_wr_err_rst                   0x00000000
#define MSK_NX90_dpm_status_err_reset_rdy_to_err_rst                       0x00000008
#define SRT_NX90_dpm_status_err_reset_rdy_to_err_rst                       3
#define DFLT_VAL_NX90_dpm_status_err_reset_rdy_to_err_rst                  0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_rdy_to_err_rst               0x00000000
#define MSK_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst              0x00000010
#define SRT_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst              4
#define DFLT_VAL_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst         0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_bus_conflict_wr_err_rst      0x00000000
#define MSK_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst              0x00000020
#define SRT_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst              5
#define DFLT_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst         0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_err_rst      0x00000000
#define MSK_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst         0x00000040
#define SRT_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst         6
#define DFLT_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst    0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_bus_conflict_rd_addr_err_rst 0x00000000
#define MSK_NX90_dpm_status_err_reset_abort_err_rst                        0x00000100
#define SRT_NX90_dpm_status_err_reset_abort_err_rst                        8
#define DFLT_VAL_NX90_dpm_status_err_reset_abort_err_rst                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_status_err_reset_abort_err_rst                0x00000000

/* all used bits of 'NX90_dpm_status_err_reset': */
#define MSK_USED_BITS_NX90_dpm_status_err_reset 0x0000017e

/* --------------------------------------------------------------------- */
/* Register dpm_status_err_addr */
/* => DPM Error Address Status Register. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_status_err_addr      0x00000024
#define Adr_NX90_dpm0_com_dpm_status_err_addr 0xFF001924
#define Adr_NX90_dpm1_com_dpm_status_err_addr 0xFF001A24

#define MSK_NX90_dpm_status_err_addr_err_addr 0x000fffff
#define SRT_NX90_dpm_status_err_addr_err_addr 0

/* all used bits of 'NX90_dpm_status_err_addr': */
#define MSK_USED_BITS_NX90_dpm_status_err_addr 0x000fffff

/* --------------------------------------------------------------------- */
/* Register dpm_misc_cfg */
/* => DPM Configuration Register for some Special Functions. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_misc_cfg      0x00000028
#define Adr_NX90_dpm0_com_dpm_misc_cfg 0xFF001928
#define Adr_NX90_dpm1_com_dpm_misc_cfg 0xFF001A28
#define DFLT_VAL_NX90_dpm_misc_cfg     0x00000006

#define MSK_NX90_dpm_misc_cfg_enable_flag_reset_on_rd             0x00000001
#define SRT_NX90_dpm_misc_cfg_enable_flag_reset_on_rd             0
#define DFLT_VAL_NX90_dpm_misc_cfg_enable_flag_reset_on_rd        0x00000000
#define DFLT_BF_VAL_NX90_dpm_misc_cfg_enable_flag_reset_on_rd     0x00000000
#define MSK_NX90_dpm_misc_cfg_dis_access_err_halt                 0x00000002
#define SRT_NX90_dpm_misc_cfg_dis_access_err_halt                 1
#define DFLT_VAL_NX90_dpm_misc_cfg_dis_access_err_halt            0x00000002
#define DFLT_BF_VAL_NX90_dpm_misc_cfg_dis_access_err_halt         0x00000001
#define MSK_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect         0x00000004
#define SRT_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect         2
#define DFLT_VAL_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect    0x00000004
#define DFLT_BF_VAL_NX90_dpm_misc_cfg_dis_bus_conflict_err_detect 0x00000001

/* all used bits of 'NX90_dpm_misc_cfg': */
#define MSK_USED_BITS_NX90_dpm_misc_cfg 0x00000007

/* --------------------------------------------------------------------- */
/* Register dpm_io_cfg_misc */
/* => DPM IO Configuration Register. */
/*    PIO usage of DPM_SIRQ, DPM_DIRQ and DPM_RDY has moved from this register to register'dpm_pio_cfg1' since netx51/52. */
/*    Signals which should be used as PIOs when netX DPM is active must be selected there. */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_io_cfg_misc      0x0000002C
#define Adr_NX90_dpm0_com_dpm_io_cfg_misc 0xFF00192C
#define Adr_NX90_dpm1_com_dpm_io_cfg_misc 0xFF001A2C
#define DFLT_VAL_NX90_dpm_io_cfg_misc     0x000000a0

#define MSK_NX90_dpm_io_cfg_misc_irq_pol         0x00000010
#define SRT_NX90_dpm_io_cfg_misc_irq_pol         4
#define DFLT_VAL_NX90_dpm_io_cfg_misc_irq_pol    0x00000000
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_irq_pol 0x00000000
#define MSK_NX90_dpm_io_cfg_misc_irq_oec         0x00000020
#define SRT_NX90_dpm_io_cfg_misc_irq_oec         5
#define DFLT_VAL_NX90_dpm_io_cfg_misc_irq_oec    0x00000020
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_irq_oec 0x00000001
#define MSK_NX90_dpm_io_cfg_misc_fiq_pol         0x00000040
#define SRT_NX90_dpm_io_cfg_misc_fiq_pol         6
#define DFLT_VAL_NX90_dpm_io_cfg_misc_fiq_pol    0x00000000
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_fiq_pol 0x00000000
#define MSK_NX90_dpm_io_cfg_misc_fiq_oec         0x00000080
#define SRT_NX90_dpm_io_cfg_misc_fiq_oec         7
#define DFLT_VAL_NX90_dpm_io_cfg_misc_fiq_oec    0x00000080
#define DFLT_BF_VAL_NX90_dpm_io_cfg_misc_fiq_oec 0x00000001

/* all used bits of 'NX90_dpm_io_cfg_misc': */
#define MSK_USED_BITS_NX90_dpm_io_cfg_misc 0x000000f0

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

#define REL_Adr_NX90_dpm_tunnel_cfg      0x00000038
#define Adr_NX90_dpm0_com_dpm_tunnel_cfg 0xFF001938
#define Adr_NX90_dpm1_com_dpm_tunnel_cfg 0xFF001A38
#define DFLT_VAL_NX90_dpm_tunnel_cfg     0x00000101

#define MSK_NX90_dpm_tunnel_cfg_wp_data              0x00000001
#define SRT_NX90_dpm_tunnel_cfg_wp_data              0
#define DFLT_VAL_NX90_dpm_tunnel_cfg_wp_data         0x00000001
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_wp_data      0x00000001
#define MSK_NX90_dpm_tunnel_cfg_wp_itbaddr           0x00000002
#define SRT_NX90_dpm_tunnel_cfg_wp_itbaddr           1
#define DFLT_VAL_NX90_dpm_tunnel_cfg_wp_itbaddr      0x00000000
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_wp_itbaddr   0x00000000
#define MSK_NX90_dpm_tunnel_cfg_enable               0x00000004
#define SRT_NX90_dpm_tunnel_cfg_enable               2
#define DFLT_VAL_NX90_dpm_tunnel_cfg_enable          0x00000000
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_enable       0x00000000
#define MSK_NX90_dpm_tunnel_cfg_tunnel_all           0x00000008
#define SRT_NX90_dpm_tunnel_cfg_tunnel_all           3
#define DFLT_VAL_NX90_dpm_tunnel_cfg_tunnel_all      0x00000000
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_tunnel_all   0x00000000
#define MSK_NX90_dpm_tunnel_cfg_byte_area            0x00000010
#define SRT_NX90_dpm_tunnel_cfg_byte_area            4
#define DFLT_VAL_NX90_dpm_tunnel_cfg_byte_area       0x00000000
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_byte_area    0x00000000
#define MSK_NX90_dpm_tunnel_cfg_dis_rd_latch         0x00000020
#define SRT_NX90_dpm_tunnel_cfg_dis_rd_latch         5
#define DFLT_VAL_NX90_dpm_tunnel_cfg_dis_rd_latch    0x00000000
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_dis_rd_latch 0x00000000
#define MSK_NX90_dpm_tunnel_cfg_base                 0x000fffc0
#define SRT_NX90_dpm_tunnel_cfg_base                 6
#define DFLT_VAL_NX90_dpm_tunnel_cfg_base            0x00000100
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_base         0x00000004
#define MSK_NX90_dpm_tunnel_cfg_wp_cfg_win           0x80000000
#define SRT_NX90_dpm_tunnel_cfg_wp_cfg_win           31
#define DFLT_VAL_NX90_dpm_tunnel_cfg_wp_cfg_win      0x00000000
#define DFLT_BF_VAL_NX90_dpm_tunnel_cfg_wp_cfg_win   0x00000000

/* all used bits of 'NX90_dpm_tunnel_cfg': */
#define MSK_USED_BITS_NX90_dpm_tunnel_cfg 0x800fffff

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

#define REL_Adr_NX90_dpm_itbaddr      0x0000003C
#define Adr_NX90_dpm0_com_dpm_itbaddr 0xFF00193C
#define Adr_NX90_dpm1_com_dpm_itbaddr 0xFF001A3C
#define DFLT_VAL_NX90_dpm_itbaddr     0x00000001

#define MSK_NX90_dpm_itbaddr_wp_data_ro            0x00000001
#define SRT_NX90_dpm_itbaddr_wp_data_ro            0
#define DFLT_VAL_NX90_dpm_itbaddr_wp_data_ro       0x00000001
#define DFLT_BF_VAL_NX90_dpm_itbaddr_wp_data_ro    0x00000001
#define MSK_NX90_dpm_itbaddr_wp_itbaddr_ro         0x00000002
#define SRT_NX90_dpm_itbaddr_wp_itbaddr_ro         1
#define DFLT_VAL_NX90_dpm_itbaddr_wp_itbaddr_ro    0x00000000
#define DFLT_BF_VAL_NX90_dpm_itbaddr_wp_itbaddr_ro 0x00000000
#define MSK_NX90_dpm_itbaddr_map                   0x0000003c
#define SRT_NX90_dpm_itbaddr_map                   2
#define DFLT_VAL_NX90_dpm_itbaddr_map              0x00000000
#define DFLT_BF_VAL_NX90_dpm_itbaddr_map           0x00000000
#define MSK_NX90_dpm_itbaddr_base                  0xffffffc0
#define SRT_NX90_dpm_itbaddr_base                  6
#define DFLT_VAL_NX90_dpm_itbaddr_base             0x00000000
#define DFLT_BF_VAL_NX90_dpm_itbaddr_base          0x00000000

/* all used bits of 'NX90_dpm_itbaddr': */
#define MSK_USED_BITS_NX90_dpm_itbaddr 0xffffffff

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

#define REL_Adr_NX90_dpm_win1_end      0x00000040
#define Adr_NX90_dpm0_com_dpm_win1_end 0xFF001940
#define Adr_NX90_dpm1_com_dpm_win1_end 0xFF001A40
#define DFLT_VAL_NX90_dpm_win1_end     0x00000000

#define MSK_NX90_dpm_win1_end_win_end         0x001fff80
#define SRT_NX90_dpm_win1_end_win_end         7
#define DFLT_VAL_NX90_dpm_win1_end_win_end    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_end_win_end 0x00000000

/* all used bits of 'NX90_dpm_win1_end': */
#define MSK_USED_BITS_NX90_dpm_win1_end 0x001fff80

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

#define REL_Adr_NX90_dpm_win1_map      0x00000044
#define Adr_NX90_dpm0_com_dpm_win1_map 0xFF001944
#define Adr_NX90_dpm1_com_dpm_win1_map 0xFF001A44
#define DFLT_VAL_NX90_dpm_win1_map     0x01800000

#define MSK_NX90_dpm_win1_map_byte_area            0x00000001
#define SRT_NX90_dpm_win1_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win1_map_byte_area       0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_map_byte_area    0x00000000
#define MSK_NX90_dpm_win1_map_read_ahead           0x00000002
#define SRT_NX90_dpm_win1_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win1_map_read_ahead      0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_map_read_ahead   0x00000000
#define MSK_NX90_dpm_win1_map_win_map_alt          0x0000000c
#define SRT_NX90_dpm_win1_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win1_map_win_map_alt     0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_map_win_map_alt  0x00000000
#define MSK_NX90_dpm_win1_map_dis_rd_latch         0x00000010
#define SRT_NX90_dpm_win1_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win1_map_dis_rd_latch    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_map_dis_rd_latch 0x00000000
#define MSK_NX90_dpm_win1_map_wp_cfg_win           0x00000020
#define SRT_NX90_dpm_win1_map_wp_cfg_win           5
#define DFLT_VAL_NX90_dpm_win1_map_wp_cfg_win      0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_map_wp_cfg_win   0x00000000
#define MSK_NX90_dpm_win1_map_win_map              0x000fff80
#define SRT_NX90_dpm_win1_map_win_map              7
#define DFLT_VAL_NX90_dpm_win1_map_win_map         0x00000000
#define DFLT_BF_VAL_NX90_dpm_win1_map_win_map      0x00000000
#define MSK_NX90_dpm_win1_map_win_page             0xfff00000
#define SRT_NX90_dpm_win1_map_win_page             20
#define DFLT_VAL_NX90_dpm_win1_map_win_page        0x01800000
#define DFLT_BF_VAL_NX90_dpm_win1_map_win_page     0x00000018

/* all used bits of 'NX90_dpm_win1_map': */
#define MSK_USED_BITS_NX90_dpm_win1_map 0xffffffbf

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

#define REL_Adr_NX90_dpm_win2_end      0x00000048
#define Adr_NX90_dpm0_com_dpm_win2_end 0xFF001948
#define Adr_NX90_dpm1_com_dpm_win2_end 0xFF001A48
#define DFLT_VAL_NX90_dpm_win2_end     0x00000000

#define MSK_NX90_dpm_win2_end_win_end         0x001fff80
#define SRT_NX90_dpm_win2_end_win_end         7
#define DFLT_VAL_NX90_dpm_win2_end_win_end    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win2_end_win_end 0x00000000

/* all used bits of 'NX90_dpm_win2_end': */
#define MSK_USED_BITS_NX90_dpm_win2_end 0x001fff80

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

#define REL_Adr_NX90_dpm_win2_map      0x0000004C
#define Adr_NX90_dpm0_com_dpm_win2_map 0xFF00194C
#define Adr_NX90_dpm1_com_dpm_win2_map 0xFF001A4C
#define DFLT_VAL_NX90_dpm_win2_map     0x01800000

#define MSK_NX90_dpm_win2_map_byte_area            0x00000001
#define SRT_NX90_dpm_win2_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win2_map_byte_area       0x00000000
#define DFLT_BF_VAL_NX90_dpm_win2_map_byte_area    0x00000000
#define MSK_NX90_dpm_win2_map_read_ahead           0x00000002
#define SRT_NX90_dpm_win2_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win2_map_read_ahead      0x00000000
#define DFLT_BF_VAL_NX90_dpm_win2_map_read_ahead   0x00000000
#define MSK_NX90_dpm_win2_map_win_map_alt          0x0000000c
#define SRT_NX90_dpm_win2_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win2_map_win_map_alt     0x00000000
#define DFLT_BF_VAL_NX90_dpm_win2_map_win_map_alt  0x00000000
#define MSK_NX90_dpm_win2_map_dis_rd_latch         0x00000010
#define SRT_NX90_dpm_win2_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win2_map_dis_rd_latch    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win2_map_dis_rd_latch 0x00000000
#define MSK_NX90_dpm_win2_map_win_map              0x000fff80
#define SRT_NX90_dpm_win2_map_win_map              7
#define DFLT_VAL_NX90_dpm_win2_map_win_map         0x00000000
#define DFLT_BF_VAL_NX90_dpm_win2_map_win_map      0x00000000
#define MSK_NX90_dpm_win2_map_win_page             0xfff00000
#define SRT_NX90_dpm_win2_map_win_page             20
#define DFLT_VAL_NX90_dpm_win2_map_win_page        0x01800000
#define DFLT_BF_VAL_NX90_dpm_win2_map_win_page     0x00000018

/* all used bits of 'NX90_dpm_win2_map': */
#define MSK_USED_BITS_NX90_dpm_win2_map 0xffffff9f

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

#define REL_Adr_NX90_dpm_win3_end      0x00000050
#define Adr_NX90_dpm0_com_dpm_win3_end 0xFF001950
#define Adr_NX90_dpm1_com_dpm_win3_end 0xFF001A50
#define DFLT_VAL_NX90_dpm_win3_end     0x00000000

#define MSK_NX90_dpm_win3_end_win_end         0x001fff80
#define SRT_NX90_dpm_win3_end_win_end         7
#define DFLT_VAL_NX90_dpm_win3_end_win_end    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win3_end_win_end 0x00000000

/* all used bits of 'NX90_dpm_win3_end': */
#define MSK_USED_BITS_NX90_dpm_win3_end 0x001fff80

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

#define REL_Adr_NX90_dpm_win3_map      0x00000054
#define Adr_NX90_dpm0_com_dpm_win3_map 0xFF001954
#define Adr_NX90_dpm1_com_dpm_win3_map 0xFF001A54
#define DFLT_VAL_NX90_dpm_win3_map     0x01800000

#define MSK_NX90_dpm_win3_map_byte_area            0x00000001
#define SRT_NX90_dpm_win3_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win3_map_byte_area       0x00000000
#define DFLT_BF_VAL_NX90_dpm_win3_map_byte_area    0x00000000
#define MSK_NX90_dpm_win3_map_read_ahead           0x00000002
#define SRT_NX90_dpm_win3_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win3_map_read_ahead      0x00000000
#define DFLT_BF_VAL_NX90_dpm_win3_map_read_ahead   0x00000000
#define MSK_NX90_dpm_win3_map_win_map_alt          0x0000000c
#define SRT_NX90_dpm_win3_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win3_map_win_map_alt     0x00000000
#define DFLT_BF_VAL_NX90_dpm_win3_map_win_map_alt  0x00000000
#define MSK_NX90_dpm_win3_map_dis_rd_latch         0x00000010
#define SRT_NX90_dpm_win3_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win3_map_dis_rd_latch    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win3_map_dis_rd_latch 0x00000000
#define MSK_NX90_dpm_win3_map_win_map              0x000fff80
#define SRT_NX90_dpm_win3_map_win_map              7
#define DFLT_VAL_NX90_dpm_win3_map_win_map         0x00000000
#define DFLT_BF_VAL_NX90_dpm_win3_map_win_map      0x00000000
#define MSK_NX90_dpm_win3_map_win_page             0xfff00000
#define SRT_NX90_dpm_win3_map_win_page             20
#define DFLT_VAL_NX90_dpm_win3_map_win_page        0x01800000
#define DFLT_BF_VAL_NX90_dpm_win3_map_win_page     0x00000018

/* all used bits of 'NX90_dpm_win3_map': */
#define MSK_USED_BITS_NX90_dpm_win3_map 0xffffff9f

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

#define REL_Adr_NX90_dpm_win4_end      0x00000058
#define Adr_NX90_dpm0_com_dpm_win4_end 0xFF001958
#define Adr_NX90_dpm1_com_dpm_win4_end 0xFF001A58
#define DFLT_VAL_NX90_dpm_win4_end     0x00000000

#define MSK_NX90_dpm_win4_end_win_end         0x001fff80
#define SRT_NX90_dpm_win4_end_win_end         7
#define DFLT_VAL_NX90_dpm_win4_end_win_end    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win4_end_win_end 0x00000000

/* all used bits of 'NX90_dpm_win4_end': */
#define MSK_USED_BITS_NX90_dpm_win4_end 0x001fff80

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

#define REL_Adr_NX90_dpm_win4_map      0x0000005C
#define Adr_NX90_dpm0_com_dpm_win4_map 0xFF00195C
#define Adr_NX90_dpm1_com_dpm_win4_map 0xFF001A5C
#define DFLT_VAL_NX90_dpm_win4_map     0x01800000

#define MSK_NX90_dpm_win4_map_byte_area            0x00000001
#define SRT_NX90_dpm_win4_map_byte_area            0
#define DFLT_VAL_NX90_dpm_win4_map_byte_area       0x00000000
#define DFLT_BF_VAL_NX90_dpm_win4_map_byte_area    0x00000000
#define MSK_NX90_dpm_win4_map_read_ahead           0x00000002
#define SRT_NX90_dpm_win4_map_read_ahead           1
#define DFLT_VAL_NX90_dpm_win4_map_read_ahead      0x00000000
#define DFLT_BF_VAL_NX90_dpm_win4_map_read_ahead   0x00000000
#define MSK_NX90_dpm_win4_map_win_map_alt          0x0000000c
#define SRT_NX90_dpm_win4_map_win_map_alt          2
#define DFLT_VAL_NX90_dpm_win4_map_win_map_alt     0x00000000
#define DFLT_BF_VAL_NX90_dpm_win4_map_win_map_alt  0x00000000
#define MSK_NX90_dpm_win4_map_dis_rd_latch         0x00000010
#define SRT_NX90_dpm_win4_map_dis_rd_latch         4
#define DFLT_VAL_NX90_dpm_win4_map_dis_rd_latch    0x00000000
#define DFLT_BF_VAL_NX90_dpm_win4_map_dis_rd_latch 0x00000000
#define MSK_NX90_dpm_win4_map_win_map              0x000fff80
#define SRT_NX90_dpm_win4_map_win_map              7
#define DFLT_VAL_NX90_dpm_win4_map_win_map         0x00000000
#define DFLT_BF_VAL_NX90_dpm_win4_map_win_map      0x00000000
#define MSK_NX90_dpm_win4_map_win_page             0xfff00000
#define SRT_NX90_dpm_win4_map_win_page             20
#define DFLT_VAL_NX90_dpm_win4_map_win_page        0x01800000
#define DFLT_BF_VAL_NX90_dpm_win4_map_win_page     0x00000018

/* all used bits of 'NX90_dpm_win4_map': */
#define MSK_USED_BITS_NX90_dpm_win4_map 0xffffff9f

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

#define REL_Adr_NX90_dpm_irq_raw0      0x00000080
#define Adr_NX90_dpm0_com_dpm_irq_raw0 0xFF001980
#define Adr_NX90_dpm1_com_dpm_irq_raw0 0xFF001A80

#define MSK_NX90_dpm_irq_raw0_dpm_sw        0x00000001
#define SRT_NX90_dpm_irq_raw0_dpm_sw        0
#define MSK_NX90_dpm_irq_raw0_dpm_err       0x00000002
#define SRT_NX90_dpm_irq_raw0_dpm_err       1
#define MSK_NX90_dpm_irq_raw0_firmware      0x00000004
#define SRT_NX90_dpm_irq_raw0_firmware      2
#define MSK_NX90_dpm_irq_raw0_host_hsc0     0x00000100
#define SRT_NX90_dpm_irq_raw0_host_hsc0     8
#define MSK_NX90_dpm_irq_raw0_host_hsc1     0x00000200
#define SRT_NX90_dpm_irq_raw0_host_hsc1     9
#define MSK_NX90_dpm_irq_raw0_host_hsc2     0x00000400
#define SRT_NX90_dpm_irq_raw0_host_hsc2     10
#define MSK_NX90_dpm_irq_raw0_host_hsc3     0x00000800
#define SRT_NX90_dpm_irq_raw0_host_hsc3     11
#define MSK_NX90_dpm_irq_raw0_host_hsc4     0x00001000
#define SRT_NX90_dpm_irq_raw0_host_hsc4     12
#define MSK_NX90_dpm_irq_raw0_host_hsc5     0x00002000
#define SRT_NX90_dpm_irq_raw0_host_hsc5     13
#define MSK_NX90_dpm_irq_raw0_host_hsc6     0x00004000
#define SRT_NX90_dpm_irq_raw0_host_hsc6     14
#define MSK_NX90_dpm_irq_raw0_host_hsc7     0x00008000
#define SRT_NX90_dpm_irq_raw0_host_hsc7     15
#define MSK_NX90_dpm_irq_raw0_host_hsc8to15 0x00010000
#define SRT_NX90_dpm_irq_raw0_host_hsc8to15 16

/* all used bits of 'NX90_dpm_irq_raw0': */
#define MSK_USED_BITS_NX90_dpm_irq_raw0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_raw1      0x00000084
#define Adr_NX90_dpm0_com_dpm_irq_raw1 0xFF001984
#define Adr_NX90_dpm1_com_dpm_irq_raw1 0xFF001A84

#define MSK_NX90_dpm_irq_raw1_ARM_TIMER           0x00000001
#define SRT_NX90_dpm_irq_raw1_ARM_TIMER           0
#define MSK_NX90_dpm_irq_raw1_timer_com_systime_s 0x00000002
#define SRT_NX90_dpm_irq_raw1_timer_com_systime_s 1
#define MSK_NX90_dpm_irq_raw1_wdg_com             0x00000004
#define SRT_NX90_dpm_irq_raw1_wdg_com             2
#define MSK_NX90_dpm_irq_raw1_dmac_com            0x00000008
#define SRT_NX90_dpm_irq_raw1_dmac_com            3
#define MSK_NX90_dpm_irq_raw1_mcp_com             0x00000010
#define SRT_NX90_dpm_irq_raw1_mcp_com             4
#define MSK_NX90_dpm_irq_raw1_uart                0x00000020
#define SRT_NX90_dpm_irq_raw1_uart                5
#define MSK_NX90_dpm_irq_raw1_i2c0_com            0x00000040
#define SRT_NX90_dpm_irq_raw1_i2c0_com            6
#define MSK_NX90_dpm_irq_raw1_i2c1_com            0x00000080
#define SRT_NX90_dpm_irq_raw1_i2c1_com            7
#define MSK_NX90_dpm_irq_raw1_ecc_com             0x00000100
#define SRT_NX90_dpm_irq_raw1_ecc_com             8
#define MSK_NX90_dpm_irq_raw1_xpic_debug_com      0x00000200
#define SRT_NX90_dpm_irq_raw1_xpic_debug_com      9
#define MSK_NX90_dpm_irq_raw1_wdg_xpic_com_arm    0x00000400
#define SRT_NX90_dpm_irq_raw1_wdg_xpic_com_arm    10
#define MSK_NX90_dpm_irq_raw1_nfifo_arm_com       0x00000800
#define SRT_NX90_dpm_irq_raw1_nfifo_arm_com       11
#define MSK_NX90_dpm_irq_raw1_com0                0x00001000
#define SRT_NX90_dpm_irq_raw1_com0                12
#define MSK_NX90_dpm_irq_raw1_com1                0x00002000
#define SRT_NX90_dpm_irq_raw1_com1                13
#define MSK_NX90_dpm_irq_raw1_msync0              0x00004000
#define SRT_NX90_dpm_irq_raw1_msync0              14
#define MSK_NX90_dpm_irq_raw1_msync1              0x00008000
#define SRT_NX90_dpm_irq_raw1_msync1              15
#define MSK_NX90_dpm_irq_raw1_trigger_lt          0x00010000
#define SRT_NX90_dpm_irq_raw1_trigger_lt          16
#define MSK_NX90_dpm_irq_raw1_lvds2mii0_com       0x00020000
#define SRT_NX90_dpm_irq_raw1_lvds2mii0_com       17
#define MSK_NX90_dpm_irq_raw1_lvds2mii1_com       0x00040000
#define SRT_NX90_dpm_irq_raw1_lvds2mii1_com       18
#define MSK_NX90_dpm_irq_raw1_sqi                 0x00080000
#define SRT_NX90_dpm_irq_raw1_sqi                 19
#define MSK_NX90_dpm_irq_raw1_hif_pio_arm         0x00100000
#define SRT_NX90_dpm_irq_raw1_hif_pio_arm         20
#define MSK_NX90_dpm_irq_raw1_eth                 0x00200000
#define SRT_NX90_dpm_irq_raw1_eth                 21
#define MSK_NX90_dpm_irq_raw1_madc_seq0           0x00400000
#define SRT_NX90_dpm_irq_raw1_madc_seq0           22
#define MSK_NX90_dpm_irq_raw1_madc_seq1           0x00800000
#define SRT_NX90_dpm_irq_raw1_madc_seq1           23
#define MSK_NX90_dpm_irq_raw1_madc_seq2           0x01000000
#define SRT_NX90_dpm_irq_raw1_madc_seq2           24
#define MSK_NX90_dpm_irq_raw1_madc_seq3           0x02000000
#define SRT_NX90_dpm_irq_raw1_madc_seq3           25
#define MSK_NX90_dpm_irq_raw1_GPIO_COM            0x04000000
#define SRT_NX90_dpm_irq_raw1_GPIO_COM            26
#define MSK_NX90_dpm_irq_raw1_CRYPT               0x08000000
#define SRT_NX90_dpm_irq_raw1_CRYPT               27
#define MSK_NX90_dpm_irq_raw1_bod                 0x10000000
#define SRT_NX90_dpm_irq_raw1_bod                 28
#define MSK_NX90_dpm_irq_raw1_clksup              0x20000000
#define SRT_NX90_dpm_irq_raw1_clksup              29
#define MSK_NX90_dpm_irq_raw1_phy                 0x40000000
#define SRT_NX90_dpm_irq_raw1_phy                 30

/* all used bits of 'NX90_dpm_irq_raw1': */
#define MSK_USED_BITS_NX90_dpm_irq_raw1 0x7fffffff

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

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_set0      0x00000088
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_set0 0xFF001988
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_set0 0xFF001A88
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0     0x00000000

#define MSK_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw                0x00000001
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw           0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_sw        0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_dpm_err               0x00000002
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_err          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_dpm_err       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_firmware              0x00000004
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_firmware         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_firmware      0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0             0x00000100
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc0     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1             0x00000200
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc1     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2             0x00000400
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc2     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3             0x00000800
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc3     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4             0x00001000
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc4     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5             0x00002000
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc5     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6             0x00004000
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc6     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7             0x00008000
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc7     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15         0x00010000
#define SRT_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set0_host_hsc8to15 0x00000000

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_set0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_set0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_set1      0x0000008C
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_set1 0xFF00198C
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_set1 0xFF001A8C
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1     0x00000000

#define MSK_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER                   0x00000001
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_ARM_TIMER           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s         0x00000002
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_timer_com_systime_s 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_wdg_com                     0x00000004
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_com             0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_dmac_com                    0x00000008
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_dmac_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_dmac_com            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_mcp_com                     0x00000010
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_mcp_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_mcp_com             0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_uart                        0x00000020
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_uart                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_uart                0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com                    0x00000040
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c0_com            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com                    0x00000080
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_i2c1_com            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_ecc_com                     0x00000100
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_ecc_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_ecc_com             0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com              0x00000200
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_xpic_debug_com      0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm            0x00000400
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm       0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_wdg_xpic_com_arm    0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com               0x00000800
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_nfifo_arm_com       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_com0                        0x00001000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_com0                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_com0                0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_com1                        0x00002000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_com1                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_com1                0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_msync0                      0x00004000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync0                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync0              0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_msync1                      0x00008000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync1                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_msync1              0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt                  0x00010000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt             0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_trigger_lt          0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com               0x00020000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii0_com       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com               0x00040000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_lvds2mii1_com       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_sqi                         0x00080000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_sqi                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_sqi                 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm                 0x00100000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm            0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_hif_pio_arm         0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_eth                         0x00200000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_eth                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_eth                 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0                   0x00400000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq0           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1                   0x00800000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq1           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2                   0x01000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq2           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3                   0x02000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_madc_seq3           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM                    0x04000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_GPIO_COM            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_CRYPT                       0x08000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_CRYPT                  0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_CRYPT               0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_bod                         0x10000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_bod                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_bod                 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_clksup                      0x20000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_clksup                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_clksup              0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_set1_phy                         0x40000000
#define SRT_NX90_dpm_irq_host_sirq_mask_set1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_set1_phy                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_set1_phy                 0x00000000

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_set1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_set1 0x7fffffff

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

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_reset0      0x00000090
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_reset0 0xFF001990
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_reset0 0xFF001A90
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0     0x00000000

#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw                0x00000001
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw           0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_sw        0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err               0x00000002
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_dpm_err       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_firmware              0x00000004
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_firmware         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_firmware      0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0             0x00000100
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc0     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1             0x00000200
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc1     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2             0x00000400
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc2     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3             0x00000800
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc3     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4             0x00001000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc4     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5             0x00002000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc5     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6             0x00004000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc6     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7             0x00008000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc7     0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15         0x00010000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset0_host_hsc8to15 0x00000000

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_reset0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_reset0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_host_sirq_mask_reset1      0x00000094
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_mask_reset1 0xFF001994
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_mask_reset1 0xFF001A94
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1     0x00000000

#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER                   0x00000001
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ARM_TIMER           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s         0x00000002
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_timer_com_systime_s 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com                     0x00000004
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_com             0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com                    0x00000008
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_dmac_com            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com                     0x00000010
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_mcp_com             0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_uart                        0x00000020
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_uart                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_uart                0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com                    0x00000040
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c0_com            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com                    0x00000080
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_i2c1_com            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com                     0x00000100
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_ecc_com             0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com              0x00000200
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_xpic_debug_com      0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm            0x00000400
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm       0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_wdg_xpic_com_arm    0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com               0x00000800
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_nfifo_arm_com       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_com0                        0x00001000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com0                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com0                0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_com1                        0x00002000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com1                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_com1                0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_msync0                      0x00004000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync0                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync0              0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_msync1                      0x00008000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync1                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_msync1              0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt                  0x00010000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt             0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_trigger_lt          0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com               0x00020000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii0_com       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com               0x00040000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_lvds2mii1_com       0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_sqi                         0x00080000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_sqi                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_sqi                 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm                 0x00100000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm            0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_hif_pio_arm         0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_eth                         0x00200000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_eth                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_eth                 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0                   0x00400000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq0           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1                   0x00800000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq1           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2                   0x01000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq2           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3                   0x02000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_madc_seq3           0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM                    0x04000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_GPIO_COM            0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT                       0x08000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT                  0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_CRYPT               0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_bod                         0x10000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_bod                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_bod                 0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_clksup                      0x20000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_clksup                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_clksup              0x00000000
#define MSK_NX90_dpm_irq_host_sirq_mask_reset1_phy                         0x40000000
#define SRT_NX90_dpm_irq_host_sirq_mask_reset1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_sirq_mask_reset1_phy                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_sirq_mask_reset1_phy                 0x00000000

/* all used bits of 'NX90_dpm_irq_host_sirq_mask_reset1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_mask_reset1 0x7fffffff

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

#define REL_Adr_NX90_dpm_irq_host_sirq_masked0      0x00000098
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_masked0 0xFF001998
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_masked0 0xFF001A98

#define MSK_NX90_dpm_irq_host_sirq_masked0_dpm_sw        0x00000001
#define SRT_NX90_dpm_irq_host_sirq_masked0_dpm_sw        0
#define MSK_NX90_dpm_irq_host_sirq_masked0_dpm_err       0x00000002
#define SRT_NX90_dpm_irq_host_sirq_masked0_dpm_err       1
#define MSK_NX90_dpm_irq_host_sirq_masked0_firmware      0x00000004
#define SRT_NX90_dpm_irq_host_sirq_masked0_firmware      2
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc0     0x00000100
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc0     8
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc1     0x00000200
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc1     9
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc2     0x00000400
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc2     10
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc3     0x00000800
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc3     11
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc4     0x00001000
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc4     12
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc5     0x00002000
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc5     13
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc6     0x00004000
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc6     14
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc7     0x00008000
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc7     15
#define MSK_NX90_dpm_irq_host_sirq_masked0_host_hsc8to15 0x00010000
#define SRT_NX90_dpm_irq_host_sirq_masked0_host_hsc8to15 16

/* all used bits of 'NX90_dpm_irq_host_sirq_masked0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_masked0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_host_sirq_masked1      0x0000009C
#define Adr_NX90_dpm0_com_dpm_irq_host_sirq_masked1 0xFF00199C
#define Adr_NX90_dpm1_com_dpm_irq_host_sirq_masked1 0xFF001A9C

#define MSK_NX90_dpm_irq_host_sirq_masked1_ARM_TIMER           0x00000001
#define SRT_NX90_dpm_irq_host_sirq_masked1_ARM_TIMER           0
#define MSK_NX90_dpm_irq_host_sirq_masked1_timer_com_systime_s 0x00000002
#define SRT_NX90_dpm_irq_host_sirq_masked1_timer_com_systime_s 1
#define MSK_NX90_dpm_irq_host_sirq_masked1_wdg_com             0x00000004
#define SRT_NX90_dpm_irq_host_sirq_masked1_wdg_com             2
#define MSK_NX90_dpm_irq_host_sirq_masked1_dmac_com            0x00000008
#define SRT_NX90_dpm_irq_host_sirq_masked1_dmac_com            3
#define MSK_NX90_dpm_irq_host_sirq_masked1_mcp_com             0x00000010
#define SRT_NX90_dpm_irq_host_sirq_masked1_mcp_com             4
#define MSK_NX90_dpm_irq_host_sirq_masked1_uart                0x00000020
#define SRT_NX90_dpm_irq_host_sirq_masked1_uart                5
#define MSK_NX90_dpm_irq_host_sirq_masked1_i2c0_com            0x00000040
#define SRT_NX90_dpm_irq_host_sirq_masked1_i2c0_com            6
#define MSK_NX90_dpm_irq_host_sirq_masked1_i2c1_com            0x00000080
#define SRT_NX90_dpm_irq_host_sirq_masked1_i2c1_com            7
#define MSK_NX90_dpm_irq_host_sirq_masked1_ecc_com             0x00000100
#define SRT_NX90_dpm_irq_host_sirq_masked1_ecc_com             8
#define MSK_NX90_dpm_irq_host_sirq_masked1_xpic_debug_com      0x00000200
#define SRT_NX90_dpm_irq_host_sirq_masked1_xpic_debug_com      9
#define MSK_NX90_dpm_irq_host_sirq_masked1_wdg_xpic_com_arm    0x00000400
#define SRT_NX90_dpm_irq_host_sirq_masked1_wdg_xpic_com_arm    10
#define MSK_NX90_dpm_irq_host_sirq_masked1_nfifo_arm_com       0x00000800
#define SRT_NX90_dpm_irq_host_sirq_masked1_nfifo_arm_com       11
#define MSK_NX90_dpm_irq_host_sirq_masked1_com0                0x00001000
#define SRT_NX90_dpm_irq_host_sirq_masked1_com0                12
#define MSK_NX90_dpm_irq_host_sirq_masked1_com1                0x00002000
#define SRT_NX90_dpm_irq_host_sirq_masked1_com1                13
#define MSK_NX90_dpm_irq_host_sirq_masked1_msync0              0x00004000
#define SRT_NX90_dpm_irq_host_sirq_masked1_msync0              14
#define MSK_NX90_dpm_irq_host_sirq_masked1_msync1              0x00008000
#define SRT_NX90_dpm_irq_host_sirq_masked1_msync1              15
#define MSK_NX90_dpm_irq_host_sirq_masked1_trigger_lt          0x00010000
#define SRT_NX90_dpm_irq_host_sirq_masked1_trigger_lt          16
#define MSK_NX90_dpm_irq_host_sirq_masked1_lvds2mii0_com       0x00020000
#define SRT_NX90_dpm_irq_host_sirq_masked1_lvds2mii0_com       17
#define MSK_NX90_dpm_irq_host_sirq_masked1_lvds2mii1_com       0x00040000
#define SRT_NX90_dpm_irq_host_sirq_masked1_lvds2mii1_com       18
#define MSK_NX90_dpm_irq_host_sirq_masked1_sqi                 0x00080000
#define SRT_NX90_dpm_irq_host_sirq_masked1_sqi                 19
#define MSK_NX90_dpm_irq_host_sirq_masked1_hif_pio_arm         0x00100000
#define SRT_NX90_dpm_irq_host_sirq_masked1_hif_pio_arm         20
#define MSK_NX90_dpm_irq_host_sirq_masked1_eth                 0x00200000
#define SRT_NX90_dpm_irq_host_sirq_masked1_eth                 21
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq0           0x00400000
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq0           22
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq1           0x00800000
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq1           23
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq2           0x01000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq2           24
#define MSK_NX90_dpm_irq_host_sirq_masked1_madc_seq3           0x02000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_madc_seq3           25
#define MSK_NX90_dpm_irq_host_sirq_masked1_GPIO_COM            0x04000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_GPIO_COM            26
#define MSK_NX90_dpm_irq_host_sirq_masked1_CRYPT               0x08000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_CRYPT               27
#define MSK_NX90_dpm_irq_host_sirq_masked1_bod                 0x10000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_bod                 28
#define MSK_NX90_dpm_irq_host_sirq_masked1_clksup              0x20000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_clksup              29
#define MSK_NX90_dpm_irq_host_sirq_masked1_phy                 0x40000000
#define SRT_NX90_dpm_irq_host_sirq_masked1_phy                 30

/* all used bits of 'NX90_dpm_irq_host_sirq_masked1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_sirq_masked1 0x7fffffff

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

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_set0      0x000000A0
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_set0 0xFF0019A0
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_set0 0xFF001AA0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0     0x00000000

#define MSK_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw                0x00000001
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw           0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_sw        0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_dpm_err               0x00000002
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_err          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_dpm_err       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_firmware              0x00000004
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_firmware         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_firmware      0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0             0x00000100
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc0     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1             0x00000200
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc1     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2             0x00000400
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc2     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3             0x00000800
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc3     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4             0x00001000
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc4     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5             0x00002000
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc5     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6             0x00004000
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc6     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7             0x00008000
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc7     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15         0x00010000
#define SRT_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set0_host_hsc8to15 0x00000000

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_set0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_set0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_set1      0x000000A4
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_set1 0xFF0019A4
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_set1 0xFF001AA4
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1     0x00000000

#define MSK_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER                   0x00000001
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_ARM_TIMER           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s         0x00000002
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_timer_com_systime_s 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_wdg_com                     0x00000004
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_com             0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_dmac_com                    0x00000008
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_dmac_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_dmac_com            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_mcp_com                     0x00000010
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_mcp_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_mcp_com             0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_uart                        0x00000020
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_uart                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_uart                0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com                    0x00000040
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c0_com            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com                    0x00000080
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_i2c1_com            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_ecc_com                     0x00000100
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_ecc_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_ecc_com             0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com              0x00000200
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_xpic_debug_com      0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm            0x00000400
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm       0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_wdg_xpic_com_arm    0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com               0x00000800
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_nfifo_arm_com       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_com0                        0x00001000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_com0                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_com0                0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_com1                        0x00002000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_com1                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_com1                0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_msync0                      0x00004000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync0                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync0              0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_msync1                      0x00008000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync1                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_msync1              0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt                  0x00010000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt             0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_trigger_lt          0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com               0x00020000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii0_com       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com               0x00040000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_lvds2mii1_com       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_sqi                         0x00080000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_sqi                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_sqi                 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm                 0x00100000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm            0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_hif_pio_arm         0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_eth                         0x00200000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_eth                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_eth                 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0                   0x00400000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq0           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1                   0x00800000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq1           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2                   0x01000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq2           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3                   0x02000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_madc_seq3           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM                    0x04000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_GPIO_COM            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_CRYPT                       0x08000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_CRYPT                  0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_CRYPT               0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_bod                         0x10000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_bod                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_bod                 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_clksup                      0x20000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_clksup                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_clksup              0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_set1_phy                         0x40000000
#define SRT_NX90_dpm_irq_host_dirq_mask_set1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_set1_phy                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_set1_phy                 0x00000000

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_set1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_set1 0x7fffffff

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

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_reset0      0x000000A8
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_reset0 0xFF0019A8
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_reset0 0xFF001AA8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0     0x00000000

#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw                0x00000001
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw                0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw           0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_sw        0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err               0x00000002
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err               1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_dpm_err       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_firmware              0x00000004
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_firmware              2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_firmware         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_firmware      0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0             0x00000100
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0             8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc0     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1             0x00000200
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1             9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc1     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2             0x00000400
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2             10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc2     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3             0x00000800
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3             11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc3     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4             0x00001000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4             12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc4     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5             0x00002000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5             13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc5     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6             0x00004000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6             14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc6     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7             0x00008000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7             15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7        0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc7     0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15         0x00010000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15         16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset0_host_hsc8to15 0x00000000

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_reset0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_reset0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_host_dirq_mask_reset1      0x000000AC
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_mask_reset1 0xFF0019AC
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_mask_reset1 0xFF001AAC
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1     0x00000000

#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER                   0x00000001
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER                   0
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ARM_TIMER           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s         0x00000002
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s         1
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_timer_com_systime_s 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com                     0x00000004
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com                     2
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_com             0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com                    0x00000008
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com                    3
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_dmac_com            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com                     0x00000010
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com                     4
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_mcp_com             0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_uart                        0x00000020
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_uart                        5
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_uart                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_uart                0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com                    0x00000040
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com                    6
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c0_com            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com                    0x00000080
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com                    7
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_i2c1_com            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com                     0x00000100
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com                     8
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com                0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_ecc_com             0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com              0x00000200
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com              9
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com         0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_xpic_debug_com      0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm            0x00000400
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm            10
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm       0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_wdg_xpic_com_arm    0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com               0x00000800
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com               11
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_nfifo_arm_com       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_com0                        0x00001000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_com0                        12
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com0                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com0                0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_com1                        0x00002000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_com1                        13
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com1                   0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_com1                0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_msync0                      0x00004000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_msync0                      14
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync0                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync0              0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_msync1                      0x00008000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_msync1                      15
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync1                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_msync1              0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt                  0x00010000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt                  16
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt             0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_trigger_lt          0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com               0x00020000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com               17
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii0_com       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com               0x00040000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com               18
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com          0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_lvds2mii1_com       0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_sqi                         0x00080000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_sqi                         19
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_sqi                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_sqi                 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm                 0x00100000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm                 20
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm            0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_hif_pio_arm         0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_eth                         0x00200000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_eth                         21
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_eth                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_eth                 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0                   0x00400000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0                   22
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq0           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1                   0x00800000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1                   23
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq1           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2                   0x01000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2                   24
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq2           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3                   0x02000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3                   25
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3              0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_madc_seq3           0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM                    0x04000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM                    26
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM               0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_GPIO_COM            0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT                       0x08000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT                       27
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT                  0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_CRYPT               0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_bod                         0x10000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_bod                         28
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_bod                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_bod                 0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_clksup                      0x20000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_clksup                      29
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_clksup                 0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_clksup              0x00000000
#define MSK_NX90_dpm_irq_host_dirq_mask_reset1_phy                         0x40000000
#define SRT_NX90_dpm_irq_host_dirq_mask_reset1_phy                         30
#define DFLT_VAL_NX90_dpm_irq_host_dirq_mask_reset1_phy                    0x00000000
#define DFLT_BF_VAL_NX90_dpm_irq_host_dirq_mask_reset1_phy                 0x00000000

/* all used bits of 'NX90_dpm_irq_host_dirq_mask_reset1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_mask_reset1 0x7fffffff

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

#define REL_Adr_NX90_dpm_irq_host_dirq_masked0      0x000000B0
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_masked0 0xFF0019B0
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_masked0 0xFF001AB0

#define MSK_NX90_dpm_irq_host_dirq_masked0_dpm_sw        0x00000001
#define SRT_NX90_dpm_irq_host_dirq_masked0_dpm_sw        0
#define MSK_NX90_dpm_irq_host_dirq_masked0_dpm_err       0x00000002
#define SRT_NX90_dpm_irq_host_dirq_masked0_dpm_err       1
#define MSK_NX90_dpm_irq_host_dirq_masked0_firmware      0x00000004
#define SRT_NX90_dpm_irq_host_dirq_masked0_firmware      2
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc0     0x00000100
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc0     8
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc1     0x00000200
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc1     9
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc2     0x00000400
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc2     10
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc3     0x00000800
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc3     11
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc4     0x00001000
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc4     12
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc5     0x00002000
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc5     13
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc6     0x00004000
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc6     14
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc7     0x00008000
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc7     15
#define MSK_NX90_dpm_irq_host_dirq_masked0_host_hsc8to15 0x00010000
#define SRT_NX90_dpm_irq_host_dirq_masked0_host_hsc8to15 16

/* all used bits of 'NX90_dpm_irq_host_dirq_masked0': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_masked0 0x0001ff07

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

#define REL_Adr_NX90_dpm_irq_host_dirq_masked1      0x000000B4
#define Adr_NX90_dpm0_com_dpm_irq_host_dirq_masked1 0xFF0019B4
#define Adr_NX90_dpm1_com_dpm_irq_host_dirq_masked1 0xFF001AB4

#define MSK_NX90_dpm_irq_host_dirq_masked1_ARM_TIMER           0x00000001
#define SRT_NX90_dpm_irq_host_dirq_masked1_ARM_TIMER           0
#define MSK_NX90_dpm_irq_host_dirq_masked1_timer_com_systime_s 0x00000002
#define SRT_NX90_dpm_irq_host_dirq_masked1_timer_com_systime_s 1
#define MSK_NX90_dpm_irq_host_dirq_masked1_wdg_com             0x00000004
#define SRT_NX90_dpm_irq_host_dirq_masked1_wdg_com             2
#define MSK_NX90_dpm_irq_host_dirq_masked1_dmac_com            0x00000008
#define SRT_NX90_dpm_irq_host_dirq_masked1_dmac_com            3
#define MSK_NX90_dpm_irq_host_dirq_masked1_mcp_com             0x00000010
#define SRT_NX90_dpm_irq_host_dirq_masked1_mcp_com             4
#define MSK_NX90_dpm_irq_host_dirq_masked1_uart                0x00000020
#define SRT_NX90_dpm_irq_host_dirq_masked1_uart                5
#define MSK_NX90_dpm_irq_host_dirq_masked1_i2c0_com            0x00000040
#define SRT_NX90_dpm_irq_host_dirq_masked1_i2c0_com            6
#define MSK_NX90_dpm_irq_host_dirq_masked1_i2c1_com            0x00000080
#define SRT_NX90_dpm_irq_host_dirq_masked1_i2c1_com            7
#define MSK_NX90_dpm_irq_host_dirq_masked1_ecc_com             0x00000100
#define SRT_NX90_dpm_irq_host_dirq_masked1_ecc_com             8
#define MSK_NX90_dpm_irq_host_dirq_masked1_xpic_debug_com      0x00000200
#define SRT_NX90_dpm_irq_host_dirq_masked1_xpic_debug_com      9
#define MSK_NX90_dpm_irq_host_dirq_masked1_wdg_xpic_com_arm    0x00000400
#define SRT_NX90_dpm_irq_host_dirq_masked1_wdg_xpic_com_arm    10
#define MSK_NX90_dpm_irq_host_dirq_masked1_nfifo_arm_com       0x00000800
#define SRT_NX90_dpm_irq_host_dirq_masked1_nfifo_arm_com       11
#define MSK_NX90_dpm_irq_host_dirq_masked1_com0                0x00001000
#define SRT_NX90_dpm_irq_host_dirq_masked1_com0                12
#define MSK_NX90_dpm_irq_host_dirq_masked1_com1                0x00002000
#define SRT_NX90_dpm_irq_host_dirq_masked1_com1                13
#define MSK_NX90_dpm_irq_host_dirq_masked1_msync0              0x00004000
#define SRT_NX90_dpm_irq_host_dirq_masked1_msync0              14
#define MSK_NX90_dpm_irq_host_dirq_masked1_msync1              0x00008000
#define SRT_NX90_dpm_irq_host_dirq_masked1_msync1              15
#define MSK_NX90_dpm_irq_host_dirq_masked1_trigger_lt          0x00010000
#define SRT_NX90_dpm_irq_host_dirq_masked1_trigger_lt          16
#define MSK_NX90_dpm_irq_host_dirq_masked1_lvds2mii0_com       0x00020000
#define SRT_NX90_dpm_irq_host_dirq_masked1_lvds2mii0_com       17
#define MSK_NX90_dpm_irq_host_dirq_masked1_lvds2mii1_com       0x00040000
#define SRT_NX90_dpm_irq_host_dirq_masked1_lvds2mii1_com       18
#define MSK_NX90_dpm_irq_host_dirq_masked1_sqi                 0x00080000
#define SRT_NX90_dpm_irq_host_dirq_masked1_sqi                 19
#define MSK_NX90_dpm_irq_host_dirq_masked1_hif_pio_arm         0x00100000
#define SRT_NX90_dpm_irq_host_dirq_masked1_hif_pio_arm         20
#define MSK_NX90_dpm_irq_host_dirq_masked1_eth                 0x00200000
#define SRT_NX90_dpm_irq_host_dirq_masked1_eth                 21
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq0           0x00400000
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq0           22
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq1           0x00800000
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq1           23
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq2           0x01000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq2           24
#define MSK_NX90_dpm_irq_host_dirq_masked1_madc_seq3           0x02000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_madc_seq3           25
#define MSK_NX90_dpm_irq_host_dirq_masked1_GPIO_COM            0x04000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_GPIO_COM            26
#define MSK_NX90_dpm_irq_host_dirq_masked1_CRYPT               0x08000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_CRYPT               27
#define MSK_NX90_dpm_irq_host_dirq_masked1_bod                 0x10000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_bod                 28
#define MSK_NX90_dpm_irq_host_dirq_masked1_clksup              0x20000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_clksup              29
#define MSK_NX90_dpm_irq_host_dirq_masked1_phy                 0x40000000
#define SRT_NX90_dpm_irq_host_dirq_masked1_phy                 30

/* all used bits of 'NX90_dpm_irq_host_dirq_masked1': */
#define MSK_USED_BITS_NX90_dpm_irq_host_dirq_masked1 0x7fffffff

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

#define REL_Adr_NX90_dpm_sw_irq      0x000000B8
#define Adr_NX90_dpm0_com_dpm_sw_irq 0xFF0019B8
#define Adr_NX90_dpm1_com_dpm_sw_irq 0xFF001AB8
#define DFLT_VAL_NX90_dpm_sw_irq     0x00000000

#define MSK_NX90_dpm_sw_irq_set_host_sirq           0x00000001
#define SRT_NX90_dpm_sw_irq_set_host_sirq           0
#define DFLT_VAL_NX90_dpm_sw_irq_set_host_sirq      0x00000000
#define DFLT_BF_VAL_NX90_dpm_sw_irq_set_host_sirq   0x00000000
#define MSK_NX90_dpm_sw_irq_set_host_dirq           0x00000002
#define SRT_NX90_dpm_sw_irq_set_host_dirq           1
#define DFLT_VAL_NX90_dpm_sw_irq_set_host_dirq      0x00000000
#define DFLT_BF_VAL_NX90_dpm_sw_irq_set_host_dirq   0x00000000
#define MSK_NX90_dpm_sw_irq_reset_host_sirq         0x00000100
#define SRT_NX90_dpm_sw_irq_reset_host_sirq         8
#define DFLT_VAL_NX90_dpm_sw_irq_reset_host_sirq    0x00000000
#define DFLT_BF_VAL_NX90_dpm_sw_irq_reset_host_sirq 0x00000000
#define MSK_NX90_dpm_sw_irq_reset_host_dirq         0x00000200
#define SRT_NX90_dpm_sw_irq_reset_host_dirq         9
#define DFLT_VAL_NX90_dpm_sw_irq_reset_host_dirq    0x00000000
#define DFLT_BF_VAL_NX90_dpm_sw_irq_reset_host_dirq 0x00000000

/* all used bits of 'NX90_dpm_sw_irq': */
#define MSK_USED_BITS_NX90_dpm_sw_irq 0x00000303

/* --------------------------------------------------------------------- */
/* Register dpm_crc */
/* => DPM CRC for access to NETX data (window1-4) */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_crc      0x000000BC
#define Adr_NX90_dpm0_com_dpm_crc 0xFF0019BC
#define Adr_NX90_dpm1_com_dpm_crc 0xFF001ABC
#define DFLT_VAL_NX90_dpm_crc     0xffffffff

#define MSK_NX90_dpm_crc_crc_rdata         0x0000ffff
#define SRT_NX90_dpm_crc_crc_rdata         0
#define DFLT_VAL_NX90_dpm_crc_crc_rdata    0x0000ffff
#define DFLT_BF_VAL_NX90_dpm_crc_crc_rdata 0x0000ffff
#define MSK_NX90_dpm_crc_crc_wdata         0xffff0000
#define SRT_NX90_dpm_crc_crc_wdata         16
#define DFLT_VAL_NX90_dpm_crc_crc_wdata    0xffff0000
#define DFLT_BF_VAL_NX90_dpm_crc_crc_wdata 0x0000ffff

/* all used bits of 'NX90_dpm_crc': */
#define MSK_USED_BITS_NX90_dpm_crc 0xffffffff

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_wgd_host_timeout */
/* => Address reserved for netx50 DPM_HOST_WDG_HOST_TIMEOUT. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_wgd_host_timeout      0x000000C0
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_wgd_host_timeout 0xFF0019C0
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_wgd_host_timeout 0xFF001AC0

#define MSK_NX90_dpm_reserved_netx50_wgd_host_timeout_zero_ro 0xffffffff
#define SRT_NX90_dpm_reserved_netx50_wgd_host_timeout_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_wgd_host_timeout': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_wgd_host_timeout 0xffffffff

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_wgd_host_trigger */
/* => Address reserved for netx50 DPM_HOST_WDG_HOST_TRIG. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_wgd_host_trigger      0x000000C4
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_wgd_host_trigger 0xFF0019C4
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_wgd_host_trigger 0xFF001AC4

#define MSK_NX90_dpm_reserved_netx50_wgd_host_trigger_zero_ro 0xffffffff
#define SRT_NX90_dpm_reserved_netx50_wgd_host_trigger_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_wgd_host_trigger': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_wgd_host_trigger 0xffffffff

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_wgd_netx_timeout */
/* => Address reserved for netx50 DPM_HOST_WDG_ARM_TIMEOUT. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_wgd_netx_timeout      0x000000C8
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_wgd_netx_timeout 0xFF0019C8
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_wgd_netx_timeout 0xFF001AC8

#define MSK_NX90_dpm_reserved_netx50_wgd_netx_timeout_zero_ro 0xffffffff
#define SRT_NX90_dpm_reserved_netx50_wgd_netx_timeout_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_wgd_netx_timeout': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_wgd_netx_timeout 0xffffffff

/* --------------------------------------------------------------------- */
/* Register dpm_sys_sta_bigend16 */
/* => DPM System Status Information Register in big endianess 16 data mapping. */
/*    Read-only, use dpm_sys_sta for programming. */
/*    This register can be used for firmware status information. */
/*    Reading this register data can be done from uninitialized DPM interface in the same way */
/*    as reading netx version (adr_dpm_netx_version_bigend16, adr_dpm_netx_version) by using dpm_sys_sta_bigend16 register. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_sys_sta_bigend16      0x000000CC
#define Adr_NX90_dpm0_com_dpm_sys_sta_bigend16 0xFF0019CC
#define Adr_NX90_dpm1_com_dpm_sys_sta_bigend16 0xFF001ACC

#define MSK_NX90_dpm_sys_sta_bigend16_NETX_STA_CODE_swap_ro 0x000000ff
#define SRT_NX90_dpm_sys_sta_bigend16_NETX_STA_CODE_swap_ro 0
#define MSK_NX90_dpm_sys_sta_bigend16_RDY_ro                0x00000100
#define SRT_NX90_dpm_sys_sta_bigend16_RDY_ro                8
#define MSK_NX90_dpm_sys_sta_bigend16_RUN_ro                0x00000200
#define SRT_NX90_dpm_sys_sta_bigend16_RUN_ro                9
#define MSK_NX90_dpm_sys_sta_bigend16_NETX_STATE_swap_ro    0x00000c00
#define SRT_NX90_dpm_sys_sta_bigend16_NETX_STATE_swap_ro    10
#define MSK_NX90_dpm_sys_sta_bigend16_HOST_STATE_swap_ro    0x0000f000
#define SRT_NX90_dpm_sys_sta_bigend16_HOST_STATE_swap_ro    12

/* all used bits of 'NX90_dpm_sys_sta_bigend16': */
#define MSK_USED_BITS_NX90_dpm_sys_sta_bigend16 0x0000ffff

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_timer_ctrl */
/* => Address reserved for netx50 DPM_HOST_TMR_CTRL. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_timer_ctrl      0x000000D0
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_timer_ctrl 0xFF0019D0
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_timer_ctrl 0xFF001AD0

#define MSK_NX90_dpm_reserved_netx50_timer_ctrl_zero_ro 0xffffffff
#define SRT_NX90_dpm_reserved_netx50_timer_ctrl_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_timer_ctrl': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_timer_ctrl 0xffffffff

/* --------------------------------------------------------------------- */
/* Register dpm_reserved_netx50_timer_start_val */
/* => Address reserved for netx50 DPM_HOST_TMR_START_VAL. */
/* => Mode: R */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reserved_netx50_timer_start_val      0x000000D4
#define Adr_NX90_dpm0_com_dpm_reserved_netx50_timer_start_val 0xFF0019D4
#define Adr_NX90_dpm1_com_dpm_reserved_netx50_timer_start_val 0xFF001AD4

#define MSK_NX90_dpm_reserved_netx50_timer_start_val_zero_ro 0xffffffff
#define SRT_NX90_dpm_reserved_netx50_timer_start_val_zero_ro 0

/* all used bits of 'NX90_dpm_reserved_netx50_timer_start_val': */
#define MSK_USED_BITS_NX90_dpm_reserved_netx50_timer_start_val 0xffffffff

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

#define REL_Adr_NX90_dpm_sys_sta      0x000000D8
#define Adr_NX90_dpm0_com_dpm_sys_sta 0xFF0019D8
#define Adr_NX90_dpm1_com_dpm_sys_sta 0xFF001AD8
#define DFLT_VAL_NX90_dpm_sys_sta     0x00000000

#define MSK_NX90_dpm_sys_sta_RDY_ro                   0x00000001
#define SRT_NX90_dpm_sys_sta_RDY_ro                   0
#define DFLT_VAL_NX90_dpm_sys_sta_RDY_ro              0x00000000
#define DFLT_BF_VAL_NX90_dpm_sys_sta_RDY_ro           0x00000000
#define MSK_NX90_dpm_sys_sta_RUN_ro                   0x00000002
#define SRT_NX90_dpm_sys_sta_RUN_ro                   1
#define DFLT_VAL_NX90_dpm_sys_sta_RUN_ro              0x00000000
#define DFLT_BF_VAL_NX90_dpm_sys_sta_RUN_ro           0x00000000
#define MSK_NX90_dpm_sys_sta_NETX_STATE_ro            0x0000000c
#define SRT_NX90_dpm_sys_sta_NETX_STATE_ro            2
#define DFLT_VAL_NX90_dpm_sys_sta_NETX_STATE_ro       0x00000000
#define DFLT_BF_VAL_NX90_dpm_sys_sta_NETX_STATE_ro    0x00000000
#define MSK_NX90_dpm_sys_sta_HOST_STATE               0x000000f0
#define SRT_NX90_dpm_sys_sta_HOST_STATE               4
#define DFLT_VAL_NX90_dpm_sys_sta_HOST_STATE          0x00000000
#define DFLT_BF_VAL_NX90_dpm_sys_sta_HOST_STATE       0x00000000
#define MSK_NX90_dpm_sys_sta_NETX_STA_CODE_ro         0x0000ff00
#define SRT_NX90_dpm_sys_sta_NETX_STA_CODE_ro         8
#define DFLT_VAL_NX90_dpm_sys_sta_NETX_STA_CODE_ro    0x00000000
#define DFLT_BF_VAL_NX90_dpm_sys_sta_NETX_STA_CODE_ro 0x00000000

/* all used bits of 'NX90_dpm_sys_sta': */
#define MSK_USED_BITS_NX90_dpm_sys_sta 0x0000ffff

/* --------------------------------------------------------------------- */
/* Register dpm_reset_request */
/* => DPM Reset Request Register. */
/*     */
/*    Note: This register is compatible to netx50 DPM_HOST_RESET_REQ register */
/*     */
/* => Mode: R/W */
/* --------------------------------------------------------------------- */

#define REL_Adr_NX90_dpm_reset_request      0x000000DC
#define Adr_NX90_dpm0_com_dpm_reset_request 0xFF0019DC
#define Adr_NX90_dpm1_com_dpm_reset_request 0xFF001ADC
#define DFLT_VAL_NX90_dpm_reset_request     0x00000000

#define MSK_NX90_dpm_reset_request_reset_key         0x000000ff
#define SRT_NX90_dpm_reset_request_reset_key         0
#define DFLT_VAL_NX90_dpm_reset_request_reset_key    0x00000000
#define DFLT_BF_VAL_NX90_dpm_reset_request_reset_key 0x00000000

/* all used bits of 'NX90_dpm_reset_request': */
#define MSK_USED_BITS_NX90_dpm_reset_request 0x000000ff

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

#define REL_Adr_NX90_dpm_firmware_irq_raw      0x000000E0
#define Adr_NX90_dpm0_com_dpm_firmware_irq_raw 0xFF0019E0
#define Adr_NX90_dpm1_com_dpm_firmware_irq_raw 0xFF001AE0
#define DFLT_VAL_NX90_dpm_firmware_irq_raw     0x00000000

#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT0               0x00000001
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT0               0
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT0          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT0       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT1               0x00000002
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT1               1
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT1          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT1       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT2               0x00000004
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT2               2
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT2          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT2       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT3               0x00000008
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT3               3
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT3          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT3       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT4               0x00000010
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT4               4
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT4          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT4       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT5               0x00000020
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT5               5
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT5          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT5       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT6               0x00000040
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT6               6
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT6          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT6       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT7               0x00000080
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT7               7
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT7          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT7       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT8               0x00000100
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT8               8
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT8          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT8       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT9               0x00000200
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT9               9
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT9          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT9       0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT10              0x00000400
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT10              10
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT10         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT10      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT11              0x00000800
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT11              11
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT11         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT11      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT12              0x00001000
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT12              12
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT12         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT12      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT13              0x00002000
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT13              13
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT13         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT13      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT14              0x00004000
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT14              14
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT14         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT14      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_HS_EVENT15              0x00008000
#define SRT_NX90_dpm_firmware_irq_raw_HS_EVENT15              15
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT15         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_HS_EVENT15      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_IRQ_VECTOR              0x00ff0000
#define SRT_NX90_dpm_firmware_irq_raw_IRQ_VECTOR              16
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_IRQ_VECTOR         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_IRQ_VECTOR      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_res_TMR_ro              0x02000000
#define SRT_NX90_dpm_firmware_irq_raw_res_TMR_ro              25
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_res_TMR_ro         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_res_TMR_ro      0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_SYS_STA                 0x04000000
#define SRT_NX90_dpm_firmware_irq_raw_SYS_STA                 26
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_SYS_STA            0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_SYS_STA         0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT             0x10000000
#define SRT_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT             28
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT        0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_RDY_TIMEOUT     0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro         0x20000000
#define SRT_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro         29
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro    0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_res_WDG_NETX_ro 0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro          0x40000000
#define SRT_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro          30
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro     0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_res_MEM_LCK_ro  0x00000000
#define MSK_NX90_dpm_firmware_irq_raw_INT_REQ                 0x80000000
#define SRT_NX90_dpm_firmware_irq_raw_INT_REQ                 31
#define DFLT_VAL_NX90_dpm_firmware_irq_raw_INT_REQ            0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_raw_INT_REQ         0x00000000

/* all used bits of 'NX90_dpm_firmware_irq_raw': */
#define MSK_USED_BITS_NX90_dpm_firmware_irq_raw 0xf6ffffff

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

#define REL_Adr_NX90_dpm_firmware_irq_mask      0x000000F0
#define Adr_NX90_dpm0_com_dpm_firmware_irq_mask 0xFF0019F0
#define Adr_NX90_dpm1_com_dpm_firmware_irq_mask 0xFF001AF0
#define DFLT_VAL_NX90_dpm_firmware_irq_mask     0x00000000

#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT0               0x00000001
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT0               0
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT0          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT0       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT1               0x00000002
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT1               1
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT1          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT1       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT2               0x00000004
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT2               2
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT2          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT2       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT3               0x00000008
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT3               3
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT3          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT3       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT4               0x00000010
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT4               4
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT4          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT4       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT5               0x00000020
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT5               5
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT5          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT5       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT6               0x00000040
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT6               6
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT6          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT6       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT7               0x00000080
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT7               7
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT7          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT7       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT8               0x00000100
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT8               8
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT8          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT8       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT9               0x00000200
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT9               9
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT9          0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT9       0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT10              0x00000400
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT10              10
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT10         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT10      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT11              0x00000800
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT11              11
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT11         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT11      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT12              0x00001000
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT12              12
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT12         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT12      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT13              0x00002000
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT13              13
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT13         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT13      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT14              0x00004000
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT14              14
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT14         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT14      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_HS_EVENT15              0x00008000
#define SRT_NX90_dpm_firmware_irq_mask_HS_EVENT15              15
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT15         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_HS_EVENT15      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_res_TMR_ro              0x02000000
#define SRT_NX90_dpm_firmware_irq_mask_res_TMR_ro              25
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_res_TMR_ro         0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_res_TMR_ro      0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_SYS_STA                 0x04000000
#define SRT_NX90_dpm_firmware_irq_mask_SYS_STA                 26
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_SYS_STA            0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_SYS_STA         0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT             0x10000000
#define SRT_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT             28
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT        0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_RDY_TIMEOUT     0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro         0x20000000
#define SRT_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro         29
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro    0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_res_WDG_NETX_ro 0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro          0x40000000
#define SRT_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro          30
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro     0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_res_MEM_LCK_ro  0x00000000
#define MSK_NX90_dpm_firmware_irq_mask_INT_EN                  0x80000000
#define SRT_NX90_dpm_firmware_irq_mask_INT_EN                  31
#define DFLT_VAL_NX90_dpm_firmware_irq_mask_INT_EN             0x00000000
#define DFLT_BF_VAL_NX90_dpm_firmware_irq_mask_INT_EN          0x00000000

/* all used bits of 'NX90_dpm_firmware_irq_mask': */
#define MSK_USED_BITS_NX90_dpm_firmware_irq_mask 0xf600ffff

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

#define REL_Adr_NX90_dpm_netx_version_bigend16      0x000000F4
#define Adr_NX90_dpm0_com_dpm_netx_version_bigend16 0xFF0019F4
#define Adr_NX90_dpm1_com_dpm_netx_version_bigend16 0xFF001AF4

#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte1_swap 0x000000ff
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte1_swap 0
#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte0_swap 0x0000ff00
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte0_swap 8
#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte3_swap 0x00ff0000
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte3_swap 16
#define MSK_NX90_dpm_netx_version_bigend16_netx_version_byte2_swap 0xff000000
#define SRT_NX90_dpm_netx_version_bigend16_netx_version_byte2_swap 24

/* all used bits of 'NX90_dpm_netx_version_bigend16': */
#define MSK_USED_BITS_NX90_dpm_netx_version_bigend16 0xffffffff

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

#define REL_Adr_NX90_dpm_netx_version      0x000000FC
#define Adr_NX90_dpm0_com_dpm_netx_version 0xFF0019FC
#define Adr_NX90_dpm1_com_dpm_netx_version 0xFF001AFC

#define MSK_NX90_dpm_netx_version_netx_version_byte0 0x000000ff
#define SRT_NX90_dpm_netx_version_netx_version_byte0 0
#define MSK_NX90_dpm_netx_version_netx_version_byte1 0x0000ff00
#define SRT_NX90_dpm_netx_version_netx_version_byte1 8
#define MSK_NX90_dpm_netx_version_netx_version_byte2 0x00ff0000
#define SRT_NX90_dpm_netx_version_netx_version_byte2 16
#define MSK_NX90_dpm_netx_version_netx_version_byte3 0xff000000
#define SRT_NX90_dpm_netx_version_netx_version_byte3 24

/* all used bits of 'NX90_dpm_netx_version': */
#define MSK_USED_BITS_NX90_dpm_netx_version 0xffffffff



#endif
