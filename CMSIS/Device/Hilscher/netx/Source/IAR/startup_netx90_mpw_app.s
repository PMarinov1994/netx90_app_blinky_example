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
        DCD     ECC2_IRQHandler           ; 12: ecc_app_2bit_error
        DCD     XPICDEBUG_IRQHandler      ; 13: xpic_debug_app
        DCD     WDGXPIC_IRQHandler        ; 14: wdg_xpic_app_arm
        DCD     NFIFO_ARM_APP_IRQHandler  ; 15: nfifo_arm_app
        DCD     IOLINK_IRQHandler         ; 16: io_link_irq_xpic_app
        DCD     SPI0_IRQHandler           ; 17: spi0_app
        DCD     SPI1_IRQHandler           ; 18: spi1_app
        DCD     SPI2_IRQHandler           ; 19: spi2_app
        DCD     SPIXPIC_IRQHandler        ; 20: spi_xpic_app
        DCD     UARTXPIC_IRQHandler       ; 21: uart_xpic_app
        DCD     ASIC_IRQHandler           ; 22: bod
        DCD     SQI_IRQHandler            ; 23: sqi
        DCD     HIFPIO_IRQHandler         ; 24: hif_pio_arm
        DCD     FETH_IRQHandler           ; 25: eth
        DCD     ADC0_IRQHandler           ; 26: adc0
        DCD     ADC1_IRQHandler           ; 27: adc1
        DCD     HASH_IRQHandler           ; 28: hash
        DCD     AES_IRQHandler            ; 29: aes
        DCD     MTGY_IRQHandler           ; 30: mtgy
        DCD     HIFRDY_IRQHandler         ; 31: hif_rdy_to
        DCD     GPIO0_IRQHandler          ; 32: gpio_app0
        DCD     GPIO1_IRQHandler          ; 33: gpio_app1
        DCD     GPIO2_IRQHandler          ; 34: gpio_app2
        DCD     GPIO3_IRQHandler          ; 35: gpio_app3
        DCD     GPIO4_IRQHandler          ; 36: gpio_app4
        DCD     GPIO5_IRQHandler          ; 37: gpio_app5
        DCD     GPIO6_IRQHandler          ; 38: gpio_app6
        DCD     GPIO7_IRQHandler          ; 39: gpio_app7
        DCD     GPIOTIM0_IRQHandler       ; 40: gpio_app_timer0
        DCD     GPIOTIM1_IRQHandler       ; 41: gpio_app_timer1
        DCD     GPIOTIM2_IRQHandler       ; 42: gpio_app_timer2
        DCD     XCTRIGGER0_IRQHandler     ; 43: trigger_out_edge0
        DCD     XCTRIGGER1_IRQHandler     ; 44: trigger_out_edge1
        DCD     CTI0_IRQHandler           ; 45: cti_arm_app0
        DCD     CTI1_IRQHandler           ; 46: cti_arm_app1
        DCD     FPU_IRQHandler            ; 47: fpu_arm_app
        DCD     HSC0_IRQHandler           ; 48: hs_com_host_hsc0
        DCD     HSC1_IRQHandler           ; 49: hs_com_host_hsc1
        DCD     HSC2_IRQHandler           ; 50: hs_com_host_hsc2
        DCD     HSC3_IRQHandler           ; 51: hs_com_host_hsc3
        DCD     HSC4_IRQHandler           ; 52: hs_com_host_hsc4
        DCD     HSC5_IRQHandler           ; 53: hs_com_host_hsc5
        DCD     HSC6_IRQHandler           ; 54: hs_com_host_hsc6
        DCD     HSC7_IRQHandler           ; 55: hs_com_host_hsc7
        DCD     HSC8TO15_IRQHandler       ; 56: hs_com_host_hsc8to15
        DCD     IDPM_IRQHandler           ; 57: idpm_com_host
        DCD     ENDAT1_IRQHandler         ; 58: endat_app0
        DCD     ENDAT2_IRQHandler         ; 59: endat_app1
        DCD     BISS0_IRQHandler          ; 60: biss_app0
        DCD     BISS1_IRQHandler          ; 61: biss_app1
        DCD     CAN0_IRQHandler           ; 62: can_ctrl0_app
        DCD     CAN1_IRQHandler           ; 63: can_ctrl1_app
        DCD     FIREWALL_IRQHandler       ; 64: firewall
        DCD     0                         ; 65: software0
        DCD     0                         ; 66: software1
        DCD     0                         ; 67: software2
        DCD     0                         ; 68: software3
        DCD     0                         ; 69: software4
        DCD     0                         ; 70: software5
        DCD     0                         ; 71: software6
        DCD     0                         ; 72: software7
        DCD     0                         ; 73: software8
        DCD     0                         ; 74: software9
        DCD     0                         ; 75: software10
        DCD     0                         ; 76: software11
        DCD     0                         ; 77: software12
        DCD     0                         ; 78: software13
        DCD     0                         ; 79: software14
        DCD     0                         ; 80: software15
        DCD     0                         ; 81: software16
        DCD     0                         ; 82: software17
        DCD     0                         ; 83: software18
        DCD     0                         ; 84: software19
        DCD     0                         ; 85: software20
        DCD     0                         ; 86: software21
        DCD     0                         ; 87: software22
        DCD     0                         ; 88: software23
        DCD     0                         ; 89: software24
        DCD     0                         ; 90: software25
        DCD     0                         ; 91: software26
        DCD     0                         ; 92: software27
        DCD     0                         ; 93: software28
        DCD     0                         ; 94: software29
        DCD     0                         ; 95: software30

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

        PUBWEAK ECC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECC1_IRQHandler
        B ECC1_IRQHandler

        PUBWEAK ECC2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ECC2_IRQHandler
        B ECC2_IRQHandler

        PUBWEAK XPICDEBUG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
XPICDEBUG_IRQHandler
        B XPICDEBUG_IRQHandler

        PUBWEAK WDGXPIC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WDGXPIC_IRQHandler
        B WDGXPIC_IRQHandler

        PUBWEAK OSAC_IRQHandler
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

        PUBWEAK ADC0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC0_IRQHandler
        B ADC0_IRQHandler

        PUBWEAK ADC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1_IRQHandler
        B ADC1_IRQHandler

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

        PUBWEAK FIREWALL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FIREWALL_IRQHandler
        B FIREWALL_IRQHandler

        END
