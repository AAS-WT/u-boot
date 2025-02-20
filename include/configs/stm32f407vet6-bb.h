/*
 * (C) Copyright 2011-2013
 *
 * Yuri Tikhonov, Emcraft Systems, yur@emcraft.com
 * Alexander Potashev, Emcraft Systems, aspotashev@emcraft.com
 * Vladimir Khusainov, Emcraft Systems, vlad@emcraft.com
 * Pavel Boldin, Emcraft Systems, paboldin@emcraft.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Configuration settings for the STmicro STM32F429 Discovery board
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * Disable debug messages
 */
#undef DEBUG

/*
 * This is an ARM Cortex-M4 CPU core. Also use the common Cortex-M3 code.
 */
#define CONFIG_SYS_ARMCORTEXM3
#define CONFIG_SYS_ARMCORTEXM4

/*
 * This is the STM32-F4 device.
 * This is an extended STM32F4 device
 */
#define CONFIG_SYS_STM32

/*
 * Enable GPIO driver
 */
#define CONFIG_STM32F2_GPIO

/*
 * Display CPU and Board information
 */
#define CONFIG_DISPLAY_CPUINFO		1
#define CONFIG_DISPLAY_BOARDINFO	1

#define CONFIG_SYS_BOARD_REV_STR	"2.1"

/*
 * Monitor prompt
 */
#define CONFIG_SYS_PROMPT		"STM32F407VET6-BB> "

/*
 * We want to call the CPU specific initialization
 */
#define CONFIG_ARCH_CPU_INIT

/*
 * Clock configuration (see mach-stm32/clock.c for details):
 * - use PLL as the system clock;
 * - use HSE as the PLL source;
 * - configure PLL to get a 180 MHz system clock.
 */
#define CONFIG_STM32_SYS_CLK_PLL
#define CONFIG_STM32_PLL_SRC_HSE
#define CONFIG_STM32_HSE_HZ		8000000		/* 8 MHz */
#define CONFIG_STM32_PLL_M		8
#define CONFIG_STM32_PLL_N		336
#define CONFIG_STM32_PLL_P		2
#define CONFIG_STM32_PLL_Q		4

/*
 * Number of clock ticks in 1 sec
 */
#define CONFIG_SYS_HZ			1000

/*
 * Enable/disable h/w watchdog
 */
#undef CONFIG_HW_WATCHDOG

/*
 * No interrupts
 */
#undef CONFIG_USE_IRQ

/*
 * Memory layout configuration
 */
#define CONFIG_MEM_NVM_BASE		    0x08000000
#define CONFIG_MEM_NVM_LEN		    (1024 * 512)
#define CONFIG_ENVM			        1
#if defined(CONFIG_ENVM)
#define CONFIG_SYS_ENVM_BASE		0x08000000
#define CONFIG_SYS_ENVM_LEN		    CONFIG_MEM_NVM_LEN
#endif

#if 0
/*
 * Define the constant below to build U-boot for running
 * from offset 0x20000 (128KB) in eNVM. When built this way,
 * use the following commands to test the newly built U-boot:
 * - tftp u-boot.bin
 * - cptf 0x08020000 ${loadaddr} ${filesize} 0
 * - go 20375 (or check address of _start in u-boot.map)
 */
#define CONFIG_MEM_NVM_UBOOT_OFF	(128 * 1024)
#endif

#define CONFIG_MEM_RAM_BASE		    0x20000000
#define CONFIG_MEM_RAM_LEN		    (20 * 1024)
#define CONFIG_MEM_RAM_BUF_LEN		(88 * 1024)
#define CONFIG_MEM_MALLOC_LEN		(16 * 1024)
#define CONFIG_MEM_STACK_LEN		(4 * 1024)

/*
 * malloc() pool size
 */
#define CONFIG_SYS_MALLOC_LEN		CONFIG_MEM_MALLOC_LEN

/*
 * Configuration of the external SDRAM memory
 */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_RAM_SIZE		    (192 * 1024)
#define CONFIG_SYS_RAM_CS		    1
#define CONFIG_SYS_RAM_FREQ_DIV		2
#define CONFIG_SYS_RAM_BASE		    CONFIG_MEM_RAM_BASE

/*
 * No external Flash
 */
#define CONFIG_SYS_NO_FLASH

/*
 * Store env in embedded Flash
 */
#define CONFIG_ENV_IS_IN_ENVM
#define CONFIG_ENV_SIZE			    (4 * 1024)
#define CONFIG_ENV_ADDR                    \
       (CONFIG_SYS_ENVM_BASE + (128 * 1024))
#define CONFIG_INFERNO			    1
#define CONFIG_ENV_OVERWRITE		1

/*
 * Serial console configuration
 */
#define CONFIG_STM32_USART_CONSOLE
#define CONFIG_STM32_USART_PORT		    1	/* USART1 */
#define CONFIG_STM32_USART_TX_IO_PORT	0	/* PORTA */
#define CONFIG_STM32_USART_TX_IO_PIN	9	/* GPIO9 */
#define CONFIG_STM32_USART_RX_IO_PORT	0	/* PORTA */
#define CONFIG_STM32_USART_RX_IO_PIN	10	/* GPIO10 */
#define CONFIG_BAUDRATE			        115200
#define CONFIG_SYS_BAUDRATE_TABLE	    { 9600, 19200, 38400, 57600, 115200 }

/*
 * Console I/O buffer size
 */
#define CONFIG_SYS_CBSIZE		        256

/*
 * Print buffer size
 */
#define CONFIG_SYS_PBSIZE               (CONFIG_SYS_CBSIZE + \
                                        sizeof(CONFIG_SYS_PROMPT) + 16)

#define CONFIG_SYS_MEMTEST_START	    CONFIG_SYS_RAM_BASE
#define CONFIG_SYS_MEMTEST_END		    (CONFIG_SYS_RAM_BASE + \
					                    CONFIG_SYS_RAM_SIZE)

/*
 * Needed by "loadb"
 */
#define CONFIG_SYS_LOAD_ADDR		    CONFIG_SYS_RAM_BASE

/*
 * Monitor is actually in eNVM. In terms of U-Boot, it is neither "flash",
 * not RAM, but CONFIG_SYS_MONITOR_BASE must be defined.
 */
#define CONFIG_SYS_MONITOR_BASE		    0x0

/*
 * Monitor is not in flash. Needs to define this to prevent
 * U-Boot from running flash_protect() on the monitor code.
 */
#define CONFIG_MONITOR_IS_IN_RAM	    1

/*
 * Enable all those monitor commands that are needed
 */
#include <config_cmd_default.h>
#undef CONFIG_CMD_BOOTD
#undef CONFIG_CMD_CONSOLE
#undef CONFIG_CMD_ECHO
#undef CONFIG_CMD_EDITENV
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_IMI
#undef CONFIG_CMD_ITEST
#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_LOADS
#undef CONFIG_CMD_MISC
// #define CONFIG_CMD_NET
// #undef CONFIG_CMD_NFS
#undef CONFIG_CMD_SOURCE
#undef CONFIG_CMD_XIMG

/*
 * To save memory disable long help
 */
#undef CONFIG_SYS_LONGHELP

/*
 * Max number of command args
 */
#define CONFIG_SYS_MAXARGS		        16

/*
 * Auto-boot sequence configuration
 */
#define CONFIG_BOOTDELAY		        3
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_BOOTCOMMAND		        "run envmboot"

#define CONFIG_HOSTNAME	                stm
#define CONFIG_BOOTARGS	                "stm32_platform=stm "\
				                        "console=ttyS0,115200 panic=10"

/*
 * These are the good addresses to get Image data right at the 'Load Address'
 * (0xD0008000), and thus avoid additional uImage relocation:
 * - linux-2.6: 0xD0007FC0 (reserve place for uImage header)
 * - linux-4.2: 0xD0007FB4 (reserve place for 2-files multi-image header)
 */
#define LOADADDR		                "0xD0007FB4"

#define REV_EXTRA_ENV		            \
										"envmboot=run args;bootm ${envmaddr}\0"               \
		                                "cptf ${envmaddr} ${loadaddr} ${filesize}\0"

#define CONFIG_SYS_CONSOLE_IS_IN_ENV

/*
 * Short-cuts to some useful commands (macros)
 */
#define CONFIG_EXTRA_ENV_SETTINGS				\
	"loadaddr=" LOADADDR "\0"				\
	"args=setenv bootargs " CONFIG_BOOTARGS "\0"		\
	"envmaddr=08020000\0"					\
	"image=stm32f407vet6/uImage\0"				\
	REV_EXTRA_ENV

/*
 * Linux kernel boot parameters configuration
 */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG

/*
 * Enable support for booting with FDT
 */
#define CONFIG_OF_LIBFDT
#define CONFIG_OF_FORCE_RELOCATE
#define CONFIG_SYS_BOOTMAPSZ		CONFIG_SYS_RAM_SIZE

#endif /* __CONFIG_H */
