;/**************************************************************************//**
; * @file     startup_netx90_app.s
; * @brief    CMSIS Cortex-M4 Core Device Startup File for
; *           ARMCM4 Device netx90_app
; * @version  V5.00
; * @date     07. March 2016
; ******************************************************************************/
;/*
; * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
; *
; * SPDX-License-Identifier: Apache-2.0
; *
; * Licensed under the Apache License, Version 2.0 (the License); you may
; * not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; * www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an AS IS BASIS, WITHOUT
; * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; */


;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table
        PUBLIC  __vector_table_0x1c
        PUBLIC  __Vectors
        PUBLIC  __Vectors_End
        PUBLIC  __Vectors_Size

        DATA

__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler

        DCD     NMI_Handler
        DCD     HardFault_Handler
        DCD     MemManage_Handler
        DCD     BusFault_Handler
        DCD     UsageFault_Handler
__vector_table_0x1c
        DCD     0
        DCD     0
        DCD     0
        DCD     0
        DCD     SVC_Handler
        DCD     DebugMon_Handler
        DCD     0
        DCD     PendSV_Handler
        DCD     SysTick_Handler

        ; External Interrupts
        DCD     SW_IRQHandler             ;  0: software
        DCD     TIM0_IRQHandler           ;  1: timer_app0
        DCD     TIM1_IRQHandler           ;  2: timer_app1
        DCD     TIM2_IRQHandler           ;  3: timer_app2
        DCD     SYSTIME_IRQHandler        ;  4: timer_app_systime_s
        DCD     WDG_IRQHandler            ;  5: wdg_app
        DCD     DMAC_IRQHandler           ;  6: dmac_app
        DCD     MCP_IRQHandler            ;  7: mcp_app
        DCD     UART_IRQHandler           ;  8: uart_app
        DCD     I2C_IRQHandler            ;  9: i2c-app
        DCD     I2CXPIC_IRQHandler        ; 10: i2c_xpic_app
        DCD     ECC1_IRQHandler           ; 11: ecc_app_1bit_error
        DCD     XPICDEBUG_IRQHandler      ; 12: xpic_debug_app
        DCD     WDGXPIC_IRQHandler        ; 13: wdg_xpic_app_arm
        DCD     NFIFO_ARM_APP_IRQHandler  ; 14: nfifo_arm_app
        DCD     IOLINK_IRQHandler         ; 15: io_link_irq_xpic_app
        DCD     SPI0_IRQHandler           ; 16: spi0_app
        DCD     SPI1_IRQHandler           ; 17: spi1_app
        DCD     SPI2_IRQHandler           ; 18: spi2_app
        DCD     SPIXPIC_IRQHandler        ; 19: spi_xpic_app
        DCD     UARTAPP_IRQHandler        ; 20: uart_app
        DCD     UARTXPIC_IRQHandler       ; 21: uart_xpic_app
        DCD     ASIC_IRQHandler           ; 22: bod
        DCD     CLKSUP_IRQHandler         ; 23: clksup_app
        DCD     SQI_IRQHandler            ; 24: sqi
        DCD     HIFPIO_IRQHandler         ; 25: hif_pio_arm
        DCD     ETH_IRQHandler            ; 26: eth
        DCD     HASH_IRQHandler           ; 27: hash
        DCD     AES_IRQHandler            ; 28: aes
        DCD     MTGY_IRQHandler           ; 29: mtgy
        DCD     HIFRDY_IRQHandler         ; 30: hif_rdy_to
        DCD     IDPM_IRQHandler           ; 31: idpm_com_host
        DCD     HSC0_IRQHandler           ; 32: hanshake channel 0
        DCD     HSC1_IRQHandler           ; 33: hanshake channel 1
        DCD     HSC2_IRQHandler           ; 34: hanshake channel 2
        DCD     HSC3_IRQHandler           ; 35: hanshake channel 3
        DCD     HSC4_IRQHandler           ; 36: hanshake channel 4
        DCD     HSC5_IRQHandler           ; 37: hanshake channel 5
        DCD     HSC6_IRQHandler           ; 38: hanshake channel 6
        DCD     HSC7_IRQHandler           ; 39: hanshake channel 7
        DCD     HSC8TO15_IRQHandler       ; 40: hanshake channel 8 to 15
        DCD     ENDAT1_IRQHandler         ; 41: endat_app0
        DCD     ENDAT2_IRQHandler         ; 42: endat_app1
        DCD     BISS0_IRQHandler          ; 43: biss_app0
        DCD     BISS1_IRQHandler          ; 44: biss_app1
        DCD     MADC0_IRQHandler          ; 45: madc_seq0
        DCD     MADC1_IRQHandler          ; 46: madc_seq1
        DCD     MADC2_IRQHandler          ; 47: madc_seq2
        DCD     MADC3_IRQHandler          ; 48: madc_seq3
        DCD     MPWM_IRQHandler           ; 49: mpwm
        DCD     MENC0_IRQHandler          ; 50: menc_app_irq_enc0
        DCD     MENC1_IRQHandler          ; 51: menc_app_irq_enc1
        DCD     MENCCAP_IRQHandler        ; 52: menc_app_irq_cap_mp
        DCD     MENCERR_IRQHandler        ; 53: menc_app_irq_err
        DCD     GPIO0_IRQHandler          ; 54: gpio_app0
        DCD     GPIO1_IRQHandler          ; 55: gpio_app1
        DCD     GPIO2_IRQHandler          ; 56: gpio_app2
        DCD     GPIO3_IRQHandler          ; 57: gpio_app3
        DCD     GPIO4_IRQHandler          ; 58: gpio_app4
        DCD     GPIO5_IRQHandler          ; 59: gpio_app5
        DCD     GPIO6_IRQHandler          ; 60: gpio_app6
        DCD     GPIO7_IRQHandler          ; 61: gpio_app7
        DCD     GPIOTIM0_IRQHandler       ; 62: gpio_app_timer0
        DCD     GPIOTIM0_IRQHandler       ; 63: gpio_app_timer1
        DCD     GPIOTIM0_IRQHandler       ; 64: gpio_app_timer2
        DCD     PIO0_IRQHandler           ; 65: pio0_app
        DCD     PIO1_IRQHandler           ; 66: pio1_app
        DCD     PIO2_IRQHandler           ; 67: pio2_app
        DCD     PIO3_IRQHandler           ; 68: pio3_app
        DCD     XCTRIGGER0_IRQHandler     ; 69: trigger_out_edge0
        DCD     XCTRIGGER1_IRQHandler     ; 70: trigger_out_edge1
        DCD     CAN0_IRQHandler           ; 71: can_ctrl0_app
        DCD     CAN1_IRQHandler           ; 72: can_ctrl1_app
        DCD     SQI0_IRQHandler           ; 73: sqi0_app
        DCD     SQI1_IRQHandler           ; 74: sqi1_app
        DCD     CTI0_IRQHandler           ; 75: cti0_arm_app
        DCD     CTI1_IRQHandler           ; 76: cti1_arm_app
        DCD     FPU_IRQHandler            ; 77: fpu_arm_app
        DCD     0                         ; 78: Reserved
        DCD     0                         ; 79: Reserved
        DCD     0                         ; 80: Reserved
        DCD     0                         ; 81: Reserved
        DCD     0                         ; 82: Reserved
        DCD     0                         ; 83: Reserved
        DCD     0                         ; 84: Reserved
        DCD     0                         ; 85: Reserved
        DCD     0                         ; 86: Reserved
        DCD     0                         ; 87: Reserved
        DCD     0                         ; 88: Reserved
        DCD     0                         ; 89: Reserved
        DCD     0                         ; 90: Reserved
        DCD     0                         ; 91: Reserved
        DCD     0                         ; 92: Reserved
        DCD     0                         ; 93: Reserved
        DCD     0                         ; 94: Reserved
        DCD     0                         ; 95: Reserved

__Vectors_End

__Vectors       EQU   __vector_table
__Vectors_Size  EQU   __Vectors_End - __Vectors


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B MemManage_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B UsageFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B DebugMon_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK SW_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SW_IRQHandler
        B SW_IRQHandler

        PUBWEAK TIM0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM0_IRQHandler
        B TIM0_IRQHandler

        PUBWEAK TIM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_IRQHandler
        B TIM1_IRQHandler

        PUBWEAK TIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM2_IRQHandler
        B TIM2_IRQHandler

        PUBWEAK SYSTIME_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SYSTIME_IRQHandler
        B SYSTIME_IRQHandler

        PUBWEAK WDG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WDG_IRQHandler
        B WDG_IRQHandler

        PUBWEAK DMAC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMAC_IRQHandler
        B DMAC_IRQHandler
        
        PUBWEAK MCP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MCP_IRQHandler
        B MCP_IRQHandler

        PUBWEAK UART_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART_IRQHandler
        B UART_IRQHandler

        PUBWEAK I2C_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C_IRQHandler
        B I2C_IRQHandler

        PUBWEAK I2CXPIC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2CXPIC_IRQHandler
        B I2CXPIC_IRQHandler

        PUBWEAK ECC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECC1_IRQHandler
        B ECC1_IRQHandler

        PUBWEAK XPICDEBUG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
XPICDEBUG_IRQHandler
        B XPICDEBUG_IRQHandler

        PUBWEAK WDGXPIC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WDGXPIC_IRQHandler
        B WDGXPIC_IRQHandler

        PUBWEAK NFIFO_ARM_APP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
OSAC_IRQHandler
        B OSAC_IRQHandler

        PUBWEAK IOLINK_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
IOLINK_IRQHandler
        B IOLINK_IRQHandler

        PUBWEAK SPI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI0_IRQHandler
        B SPI0_IRQHandler

        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler

        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_IRQHandler
        B SPI2_IRQHandler

        PUBWEAK SPIXPIC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPIXPIC_IRQHandler
        B SPIXPIC_IRQHandler

        PUBWEAK UARTXPIC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UARTXPIC_IRQHandler
        B UARTXPIC_IRQHandler

        PUBWEAK ASIC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ASIC_IRQHandler
        B ASIC_IRQHandler

        PUBWEAK SQI_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SQI_IRQHandler
        B SQI_IRQHandler
        
        PUBWEAK HIFPIO_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIFPIO_IRQHandler
        B HIFPIO_IRQHandler

        PUBWEAK FETH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FETH_IRQHandler
        B FETH_IRQHandler

        PUBWEAK HASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HASH_IRQHandler
        B HASH_IRQHandler

        PUBWEAK AES_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
AES_IRQHandler
        B AES_IRQHandler

        PUBWEAK MTGY_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MTGY_IRQHandler
        B MTGY_IRQHandler

        PUBWEAK HIFRDY_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIFRDY_IRQHandler
        B HIFRDY_IRQHandler

        PUBWEAK GPIO0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO0_IRQHandler
        B GPIO0_IRQHandler

        PUBWEAK GPIO1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO1_IRQHandler
        B GPIO1_IRQHandler

        PUBWEAK GPIO2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO2_IRQHandler
        B GPIO2_IRQHandler

        PUBWEAK GPIO3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO3_IRQHandler
        B GPIO3_IRQHandler

        PUBWEAK GPIO4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO4_IRQHandler
        B GPIO4_IRQHandler

        PUBWEAK GPIO5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO5_IRQHandler
        B GPIO5_IRQHandler

        PUBWEAK GPIO6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO6_IRQHandler
        B GPIO6_IRQHandler

        PUBWEAK GPIO7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIO7_IRQHandler
        B GPIO7_IRQHandler

        PUBWEAK GPIOTIM0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOTIM0_IRQHandler
        B GPIOTIM0_IRQHandler
        
        PUBWEAK GPIOTIM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOTIM1_IRQHandler
        B GPIOTIM1_IRQHandler

        PUBWEAK GPIOTIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOTIM2_IRQHandler
        B GPIOTIM2_IRQHandler

        PUBWEAK XCTRIGGER0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
XCTRIGGER0_IRQHandler
        B XCTRIGGER0_IRQHandler

        PUBWEAK XCTRIGGER1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
XCTRIGGER1_IRQHandler
        B XCTRIGGER1_IRQHandler

        PUBWEAK CTI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CTI0_IRQHandler
        B CTI0_IRQHandler

        PUBWEAK CTI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CTI1_IRQHandler
        B CTI1_IRQHandler

        PUBWEAK FPU_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FPU_IRQHandler
        B FPU_IRQHandler

        PUBWEAK HSC0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC0_IRQHandler
        B HSC0_IRQHandler

        PUBWEAK HSC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC1_IRQHandler
        B HSC1_IRQHandler

        PUBWEAK HSC2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC2_IRQHandler
        B HSC2_IRQHandler

        PUBWEAK HSC3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC3_IRQHandler
        B HSC3_IRQHandler

        PUBWEAK HSC4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC4_IRQHandler
        B HSC4_IRQHandler

        PUBWEAK HSC5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC5_IRQHandler
        B HSC5_IRQHandler

        PUBWEAK HSC6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC6_IRQHandler
        B HSC6_IRQHandler

        PUBWEAK HSC7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC7_IRQHandler
        B HSC7_IRQHandler

        PUBWEAK HSC8TO15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
HSC8TO15_IRQHandler
        B HSC8TO15_IRQHandler

        PUBWEAK IDPM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
IDPM_IRQHandler
        B IDPM_IRQHandler

        PUBWEAK ENDAT1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ENDAT1_IRQHandler
        B ENDAT1_IRQHandler

        PUBWEAK ENDAT2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ENDAT2_IRQHandler
        B ENDAT2_IRQHandler

        PUBWEAK BISS0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
BISS0_IRQHandler
        B BISS0_IRQHandler

        PUBWEAK BISS1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
BISS1_IRQHandler
        B BISS1_IRQHandler

        PUBWEAK CAN0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN0_IRQHandler
        B CAN0_IRQHandler
        
        PUBWEAK CAN1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_IRQHandler
        B CAN1_IRQHandler

        PUBWEAK MADC0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MADC0_IRQHandler
        B MADC0_IRQHandler

        PUBWEAK MADC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MADC1_IRQHandler
        B MADC1_IRQHandler

        PUBWEAK MADC2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MADC2_IRQHandler
        B MADC2_IRQHandler

        PUBWEAK MADC3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MADC3_IRQHandler
        B MADC3_IRQHandler

        PUBWEAK MPWM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MPWM_IRQHandler
        B MPWM_IRQHandler

        PUBWEAK MENC0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MENC0_IRQHandler
        B MENC0_IRQHandler

        PUBWEAK MENC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MENC1_IRQHandler
        B MENC1_IRQHandler

        PUBWEAK MENCCAP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MENCCAP_IRQHandler
        B MENCCAP_IRQHandler

        PUBWEAK MENCERR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
MENCERR_IRQHandler
        B MENCERR_IRQHandler

        END
