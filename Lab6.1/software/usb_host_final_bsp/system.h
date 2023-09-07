/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'DE10_LITE_Qsys'
 * SOPC Builder design path: ../../DE10_LITE_Qsys.sopcinfo
 *
 * Generated: Fri Apr 16 20:37:24 CDT 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x08000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 133000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x04000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 133000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x04000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x08000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 133000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x04000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x04000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_I2C
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x8001148
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x8001148
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x8001148
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "DE10_LITE_Qsys"


/*
 * altpll_0 configuration
 *
 */

#define ALTPLL_0_BASE 0x8001130
#define ALTPLL_0_IRQ -1
#define ALTPLL_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ALTPLL_0_NAME "/dev/altpll_0"
#define ALTPLL_0_SPAN 16
#define ALTPLL_0_TYPE "altpll"
#define ALT_MODULE_CLASS_altpll_0 altpll


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * hex_digits_pio configuration
 *
 */

#define ALT_MODULE_CLASS_hex_digits_pio altera_avalon_pio
#define HEX_DIGITS_PIO_BASE 0x80010e0
#define HEX_DIGITS_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_DIGITS_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_DIGITS_PIO_CAPTURE 0
#define HEX_DIGITS_PIO_DATA_WIDTH 16
#define HEX_DIGITS_PIO_DO_TEST_BENCH_WIRING 0
#define HEX_DIGITS_PIO_DRIVEN_SIM_VALUE 0
#define HEX_DIGITS_PIO_EDGE_TYPE "NONE"
#define HEX_DIGITS_PIO_FREQ 133000000
#define HEX_DIGITS_PIO_HAS_IN 0
#define HEX_DIGITS_PIO_HAS_OUT 1
#define HEX_DIGITS_PIO_HAS_TRI 0
#define HEX_DIGITS_PIO_IRQ -1
#define HEX_DIGITS_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_DIGITS_PIO_IRQ_TYPE "NONE"
#define HEX_DIGITS_PIO_NAME "/dev/hex_digits_pio"
#define HEX_DIGITS_PIO_RESET_VALUE 0
#define HEX_DIGITS_PIO_SPAN 16
#define HEX_DIGITS_PIO_TYPE "altera_avalon_pio"


/*
 * i2c_0 configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_0 altera_avalon_i2c
#define I2C_0_BASE 0x8001040
#define I2C_0_FIFO_DEPTH 4
#define I2C_0_FREQ 133000000
#define I2C_0_IRQ 4
#define I2C_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define I2C_0_NAME "/dev/i2c_0"
#define I2C_0_SPAN 64
#define I2C_0_TYPE "altera_avalon_i2c"
#define I2C_0_USE_AV_ST 0


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x8001148
#define JTAG_UART_IRQ 1
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x8001120
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 1
#define KEY_DATA_WIDTH 4
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "FALLING"
#define KEY_FREQ 133000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ 0
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY_IRQ_TYPE "EDGE"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * leds_pio configuration
 *
 */

#define ALT_MODULE_CLASS_leds_pio altera_avalon_pio
#define LEDS_PIO_BASE 0x80010d0
#define LEDS_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_PIO_CAPTURE 0
#define LEDS_PIO_DATA_WIDTH 14
#define LEDS_PIO_DO_TEST_BENCH_WIRING 0
#define LEDS_PIO_DRIVEN_SIM_VALUE 0
#define LEDS_PIO_EDGE_TYPE "NONE"
#define LEDS_PIO_FREQ 133000000
#define LEDS_PIO_HAS_IN 0
#define LEDS_PIO_HAS_OUT 1
#define LEDS_PIO_HAS_TRI 0
#define LEDS_PIO_IRQ -1
#define LEDS_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_PIO_IRQ_TYPE "NONE"
#define LEDS_PIO_NAME "/dev/leds_pio"
#define LEDS_PIO_RESET_VALUE 0
#define LEDS_PIO_SPAN 16
#define LEDS_PIO_TYPE "altera_avalon_pio"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x4000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 7.8125
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_SPAN 67108864
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.4
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 15.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 15.0
#define SDRAM_T_WR 14.0


/*
 * spi1_cs_usd configuration
 *
 */

#define ALT_MODULE_CLASS_spi1_cs_usd altera_avalon_pio
#define SPI1_CS_USD_BASE 0x80010c0
#define SPI1_CS_USD_BIT_CLEARING_EDGE_REGISTER 0
#define SPI1_CS_USD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SPI1_CS_USD_CAPTURE 0
#define SPI1_CS_USD_DATA_WIDTH 1
#define SPI1_CS_USD_DO_TEST_BENCH_WIRING 0
#define SPI1_CS_USD_DRIVEN_SIM_VALUE 0
#define SPI1_CS_USD_EDGE_TYPE "NONE"
#define SPI1_CS_USD_FREQ 133000000
#define SPI1_CS_USD_HAS_IN 0
#define SPI1_CS_USD_HAS_OUT 1
#define SPI1_CS_USD_HAS_TRI 0
#define SPI1_CS_USD_IRQ -1
#define SPI1_CS_USD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPI1_CS_USD_IRQ_TYPE "NONE"
#define SPI1_CS_USD_NAME "/dev/spi1_cs_usd"
#define SPI1_CS_USD_RESET_VALUE 1
#define SPI1_CS_USD_SPAN 16
#define SPI1_CS_USD_TYPE "altera_avalon_pio"


/*
 * spi_0 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_0 altera_avalon_spi
#define SPI_0_BASE 0x80010a0
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 0
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 8
#define SPI_0_DATAWIDTH 16
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 0
#define SPI_0_IRQ 3
#define SPI_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NAME "/dev/spi_0"
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SPAN 32
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 16625000u
#define SPI_0_TARGETSSDELAY "0.0"
#define SPI_0_TYPE "altera_avalon_spi"


/*
 * spi_1 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_1 altera_avalon_spi
#define SPI_1_BASE 0x8001080
#define SPI_1_CLOCKMULT 1
#define SPI_1_CLOCKPHASE 0
#define SPI_1_CLOCKPOLARITY 0
#define SPI_1_CLOCKUNITS "Hz"
#define SPI_1_DATABITS 8
#define SPI_1_DATAWIDTH 16
#define SPI_1_DELAYMULT "1.0E-9"
#define SPI_1_DELAYUNITS "ns"
#define SPI_1_EXTRADELAY 0
#define SPI_1_INSERT_SYNC 0
#define SPI_1_IRQ 5
#define SPI_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_1_ISMASTER 1
#define SPI_1_LSBFIRST 0
#define SPI_1_NAME "/dev/spi_1"
#define SPI_1_NUMSLAVES 1
#define SPI_1_PREFIX "spi_"
#define SPI_1_SPAN 32
#define SPI_1_SYNC_REG_DEPTH 2
#define SPI_1_TARGETCLOCK 400000u
#define SPI_1_TARGETSSDELAY "0.0"
#define SPI_1_TYPE "altera_avalon_spi"


/*
 * sysid_qsys configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys altera_avalon_sysid_qsys
#define SYSID_QSYS_BASE 0x8001140
#define SYSID_QSYS_ID 305441741
#define SYSID_QSYS_IRQ -1
#define SYSID_QSYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_NAME "/dev/sysid_qsys"
#define SYSID_QSYS_SPAN 8
#define SYSID_QSYS_TIMESTAMP 1618623314
#define SYSID_QSYS_TYPE "altera_avalon_sysid_qsys"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x8001000
#define TIMER_COUNTER_SIZE 64
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 133000000
#define TIMER_IRQ 2
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 132999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 64
#define TIMER_TICKS_PER_SEC 1000
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * usb_gpx configuration
 *
 */

#define ALT_MODULE_CLASS_usb_gpx altera_avalon_pio
#define USB_GPX_BASE 0x8001100
#define USB_GPX_BIT_CLEARING_EDGE_REGISTER 0
#define USB_GPX_BIT_MODIFYING_OUTPUT_REGISTER 0
#define USB_GPX_CAPTURE 0
#define USB_GPX_DATA_WIDTH 1
#define USB_GPX_DO_TEST_BENCH_WIRING 0
#define USB_GPX_DRIVEN_SIM_VALUE 0
#define USB_GPX_EDGE_TYPE "NONE"
#define USB_GPX_FREQ 133000000
#define USB_GPX_HAS_IN 1
#define USB_GPX_HAS_OUT 0
#define USB_GPX_HAS_TRI 0
#define USB_GPX_IRQ -1
#define USB_GPX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define USB_GPX_IRQ_TYPE "NONE"
#define USB_GPX_NAME "/dev/usb_gpx"
#define USB_GPX_RESET_VALUE 0
#define USB_GPX_SPAN 16
#define USB_GPX_TYPE "altera_avalon_pio"


/*
 * usb_irq configuration
 *
 */

#define ALT_MODULE_CLASS_usb_irq altera_avalon_pio
#define USB_IRQ_BASE 0x8001110
#define USB_IRQ_BIT_CLEARING_EDGE_REGISTER 0
#define USB_IRQ_BIT_MODIFYING_OUTPUT_REGISTER 0
#define USB_IRQ_CAPTURE 0
#define USB_IRQ_DATA_WIDTH 1
#define USB_IRQ_DO_TEST_BENCH_WIRING 0
#define USB_IRQ_DRIVEN_SIM_VALUE 0
#define USB_IRQ_EDGE_TYPE "NONE"
#define USB_IRQ_FREQ 133000000
#define USB_IRQ_HAS_IN 1
#define USB_IRQ_HAS_OUT 0
#define USB_IRQ_HAS_TRI 0
#define USB_IRQ_IRQ -1
#define USB_IRQ_IRQ_INTERRUPT_CONTROLLER_ID -1
#define USB_IRQ_IRQ_TYPE "NONE"
#define USB_IRQ_NAME "/dev/usb_irq"
#define USB_IRQ_RESET_VALUE 0
#define USB_IRQ_SPAN 16
#define USB_IRQ_TYPE "altera_avalon_pio"


/*
 * usb_rst configuration
 *
 */

#define ALT_MODULE_CLASS_usb_rst altera_avalon_pio
#define USB_RST_BASE 0x80010f0
#define USB_RST_BIT_CLEARING_EDGE_REGISTER 0
#define USB_RST_BIT_MODIFYING_OUTPUT_REGISTER 0
#define USB_RST_CAPTURE 0
#define USB_RST_DATA_WIDTH 1
#define USB_RST_DO_TEST_BENCH_WIRING 0
#define USB_RST_DRIVEN_SIM_VALUE 0
#define USB_RST_EDGE_TYPE "NONE"
#define USB_RST_FREQ 133000000
#define USB_RST_HAS_IN 0
#define USB_RST_HAS_OUT 1
#define USB_RST_HAS_TRI 0
#define USB_RST_IRQ -1
#define USB_RST_IRQ_INTERRUPT_CONTROLLER_ID -1
#define USB_RST_IRQ_TYPE "NONE"
#define USB_RST_NAME "/dev/usb_rst"
#define USB_RST_RESET_VALUE 0
#define USB_RST_SPAN 16
#define USB_RST_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
