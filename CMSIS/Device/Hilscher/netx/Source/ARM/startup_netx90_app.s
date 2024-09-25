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
                EXPORT  ECC_IRQHandler            [WEAK]
                EXPORT  XPICDEBUG_IRQHandler      [WEAK]
                EXPORT  WDGXPIC_IRQHandler        [WEAK]
                EXPORT  NFIFO_ARM_APP_IRQHandler  [WEAK]
                EXPORT  IOLINK_IRQHandler         [WEAK]
                EXPORT  SPI0_IRQHandler           [WEAK]
                EXPORT  SPI1_IRQHandler           [WEAK]
                EXPORT  SPI2_IRQHandler           [WEAK]
                EXPORT  SPIXPIC_IRQHandler        [WEAK]
                EXPORT  UARTAPP_IRQHandler        [WEAK]
                EXPORT  UARTXPIC_IRQHandler       [WEAK]
                EXPORT  ASIC_IRQHandler           [WEAK]
                EXPORT  SQI_IRQHandler            [WEAK]
                EXPORT  HIFPIO_IRQHandler          [WEAK]
                EXPORT  ETH_IRQHandler            [WEAK]
                EXPORT  HASH_IRQHandler           [WEAK]
                EXPORT  AES_IRQHandler            [WEAK]
                EXPORT  MTGY_IRQHandler           [WEAK]
                EXPORT  HIFRDY_IRQHandler         [WEAK]
                EXPORT  IDPM_IRQHandler           [WEAK]
                EXPORT  HSC0_IRQHandler           [WEAK]
                EXPORT  HSC1_IRQHandler           [WEAK]
                EXPORT  HSC2_IRQHandler           [WEAK]
                EXPORT  HSC3_IRQHandler           [WEAK]
                EXPORT  HSC4_IRQHandler           [WEAK]
                EXPORT  HSC5_IRQHandler           [WEAK]
                EXPORT  HSC6_IRQHandler           [WEAK]
                EXPORT  HSC7_IRQHandler           [WEAK]
                EXPORT  HSC8TO15_IRQHandler       [WEAK]
                EXPORT  ENDAT1_IRQHandler         [WEAK]
                EXPORT  ENDAT2_IRQHandler         [WEAK]
                EXPORT  BISS0_IRQHandler          [WEAK]
                EXPORT  BISS1_IRQHandler          [WEAK]
                EXPORT  MADC0_IRQHandler          [WEAK]
                EXPORT  MADC1_IRQHandler          [WEAK]
                EXPORT  MADC2_IRQHandler          [WEAK]
                EXPORT  MADC3_IRQHandler          [WEAK]
                EXPORT  MPWM_IRQHandler           [WEAK]
                EXPORT  MENC0_IRQHandler          [WEAK]
                EXPORT  MENC1_IRQHandler          [WEAK]
                EXPORT  MENCCAP_IRQHandler        [WEAK]
                EXPORT  MENERR_IRQHandler         [WEAK]
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
                EXPORT  PIO0_IRQHandler           [WEAK]
                EXPORT  PIO1_IRQHandler           [WEAK]
                EXPORT  PIO2_IRQHandler           [WEAK]
                EXPORT  PIO3_IRQHandler           [WEAK]
                EXPORT  XCTRIGGER0_IRQHandler     [WEAK]
                EXPORT  XCTRIGGER1_IRQHandler     [WEAK]
                EXPORT  CAN0_IRQHandler           [WEAK]
                EXPORT  CAN1_IRQHandler           [WEAK]
                EXPORT  SQI0_IRQHandler           [WEAK]
                EXPORT  SQI1_IRQHandler           [WEAK]
                EXPORT  CTI0_IRQHandler           [WEAK]
                EXPORT  CTI1_IRQHandler           [WEAK]
                EXPORT  FPU_IRQHandler            [WEAK]

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
