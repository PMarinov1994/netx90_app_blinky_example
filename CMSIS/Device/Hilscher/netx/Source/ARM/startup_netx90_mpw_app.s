;/**************************************************************************//**
; * @file     startup_netx90_app.s
; * @brief    CMSIS Cortex-M ARMv7-M based Core Device Startup File for
; *           ARMCM4 Device netx90_app
; * @version  V5.00
; * @date     02. March 2016
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
;/*

;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000C00

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

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
                DCD     HIFPIO_IRQHandler          ; 24: hif_pio_arm
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
                DCD     0                         ; 65: Reserved
                DCD     0                         ; 66: Reserved
                DCD     0                         ; 67: Reserved
                DCD     0                         ; 68: Reserved
                DCD     0                         ; 69: Reserved
                DCD     0                         ; 70: Reserved
                DCD     0                         ; 71: Reserved
                DCD     0                         ; 72: Reserved
                DCD     0                         ; 73: Reserved
                DCD     0                         ; 74: Reserved
                DCD     0                         ; 75: Reserved
                DCD     0                         ; 76: Reserved
                DCD     0                         ; 77: Reserved
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
                        
__Vectors_Size  EQU     __Vectors_End - __Vectors
                        
                AREA    |.text|, CODE, READONLY
                        
                        
; Reset Handler         
                        
Reset_Handler   PROC    
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP    
                        
                        
; Dummy Exception Handlers (infinite loops which can be modified)
                        
NMI_Handler\
                PROC    
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler\
                PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  SW_IRQHandler             [WEAK]
                EXPORT  TIM0_IRQHandler           [WEAK]
                EXPORT  TIM1_IRQHandler           [WEAK]
                EXPORT  TIM2_IRQHandler           [WEAK]
                EXPORT  SYSTIME_IRQHandler        [WEAK]
                EXPORT  WDG_IRQHandler            [WEAK]
                EXPORT  DMAC_IRQHandler           [WEAK]
                EXPORT  MCP_IRQHandler            [WEAK]
                EXPORT  UART_IRQHandler           [WEAK]
                EXPORT  I2C_IRQHandler            [WEAK]
                EXPORT  I2CXPIC_IRQHandler        [WEAK]
                EXPORT  ECC1_IRQHandler           [WEAK]
                EXPORT  ECC2_IRQHandler           [WEAK]
                EXPORT  XPICDEBUG_IRQHandler      [WEAK]
                EXPORT  WDGXPIC_IRQHandler        [WEAK]
                EXPORT  NFIFO_ARM_APP_IRQHandler  [WEAK]
                EXPORT  IOLINK_IRQHandler         [WEAK]
                EXPORT  SPI0_IRQHandler           [WEAK]
                EXPORT  SPI1_IRQHandler           [WEAK]
                EXPORT  SPI2_IRQHandler           [WEAK]
                EXPORT  SPIXPIC_IRQHandler        [WEAK]
                EXPORT  UARTXPIC_IRQHandler       [WEAK]
                EXPORT  ASIC_IRQHandler           [WEAK]
                EXPORT  SQI_IRQHandler            [WEAK]
                EXPORT  HIFPIO_IRQHandler         [WEAK]
                EXPORT  FETH_IRQHandler           [WEAK]
                EXPORT  ADC0_IRQHandler           [WEAK]
                EXPORT  ADC1_IRQHandler           [WEAK]
                EXPORT  HASH_IRQHandler           [WEAK]
                EXPORT  AES_IRQHandler            [WEAK]
                EXPORT  MTGY_IRQHandler           [WEAK]
                EXPORT  HIFRDY_IRQHandler         [WEAK]
                EXPORT  GPIO0_IRQHandler          [WEAK]
                EXPORT  GPIO1_IRQHandler          [WEAK]
                EXPORT  GPIO2_IRQHandler          [WEAK]
                EXPORT  GPIO3_IRQHandler          [WEAK]
                EXPORT  GPIO4_IRQHandler          [WEAK]
                EXPORT  GPIO5_IRQHandler          [WEAK]
                EXPORT  GPIO6_IRQHandler          [WEAK]
                EXPORT  GPIO7_IRQHandler          [WEAK]
                EXPORT  GPIOTIM0_IRQHandler       [WEAK]
                EXPORT  GPIOTIM1_IRQHandler       [WEAK]
                EXPORT  GPIOTIM2_IRQHandler       [WEAK]
                EXPORT  XCTRIGGER0_IRQHandler     [WEAK]
                EXPORT  XCTRIGGER1_IRQHandler     [WEAK]
                EXPORT  CTI0_IRQHandler           [WEAK]
                EXPORT  CTI1_IRQHandler           [WEAK]
                EXPORT  FPU_IRQHandler            [WEAK]
                EXPORT  HSC0_IRQHandler           [WEAK]
                EXPORT  HSC1_IRQHandler           [WEAK]
                EXPORT  HSC2_IRQHandler           [WEAK]
                EXPORT  HSC3_IRQHandler           [WEAK]
                EXPORT  HSC4_IRQHandler           [WEAK]
                EXPORT  HSC5_IRQHandler           [WEAK]
                EXPORT  HSC6_IRQHandler           [WEAK]
                EXPORT  HSC7_IRQHandler           [WEAK]
                EXPORT  HSC8TO15_IRQHandler       [WEAK]
                EXPORT  IDPM_IRQHandler           [WEAK]
                EXPORT  ENDAT1_IRQHandler         [WEAK]
                EXPORT  ENDAT2_IRQHandler         [WEAK]
                EXPORT  BISS0_IRQHandler          [WEAK]
                EXPORT  BISS1_IRQHandler          [WEAK]
                EXPORT  CAN0_IRQHandler           [WEAK]
                EXPORT  CAN1_IRQHandler           [WEAK]
                EXPORT  FIREWALL_IRQHandler       [WEAK]

SW_IRQHandler
TIM0_IRQHandler
TIM1_IRQHandler
TIM2_IRQHandler
SYSTIME_IRQHandler
WDG_IRQHandler
DMAC_IRQHandler
MCP_IRQHandler
UART_IRQHandler
I2C_IRQHandler
I2CXPIC_IRQHandler
ECC1_IRQHandler
ECC2_IRQHandler
XPICDEBUG_IRQHandler
WDGXPIC_IRQHandler
OSAC_IRQHandler
IOLINK_IRQHandler
SPI0_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
SPIXPIC_IRQHandler
UARTXPIC_IRQHandler
ASIC_IRQHandler
SQI_IRQHandler
HIFPIO_IRQHandler
FETH_IRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
HASH_IRQHandler
AES_IRQHandler
MTGY_IRQHandler
HIFRDY_IRQHandler
GPIO0_IRQHandler
GPIO1_IRQHandler
GPIO2_IRQHandler
GPIO3_IRQHandler
GPIO4_IRQHandler
GPIO5_IRQHandler
GPIO6_IRQHandler
GPIO7_IRQHandler
GPIOTIM0_IRQHandler
GPIOTIM1_IRQHandler
GPIOTIM2_IRQHandler
XCTRIGGER0_IRQHandler
XCTRIGGER1_IRQHandler
CTI0_IRQHandler
CTI1_IRQHandler
FPU_IRQHandler
HSC0_IRQHandler
HSC1_IRQHandler
HSC2_IRQHandler
HSC3_IRQHandler
HSC4_IRQHandler
HSC5_IRQHandler
HSC6_IRQHandler
HSC7_IRQHandler
HSC8TO15_IRQHandler
IDPM_IRQHandler
ENDAT1_IRQHandler
ENDAT2_IRQHandler
BISS0_IRQHandler
BISS1_IRQHandler
CAN0_IRQHandler
CAN1_IRQHandler
FIREWALL_IRQHandler

                B       .
                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
