/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2021 Sanpe <sanpeqf@gmail.com>
 */

#ifndef __GX6605S_H__
#define __GX6605S_H__

#include <configs.h>
#include <stdint.h>
#include <types.h>
#include <sizes.h>
#include <io.h>
#include <sys-timer.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Processor and memory
 */
#define CSKY_CPU_FREQ		(CONFIG_PRELOAD_CPU_CLK * 1000 * 1000)
#define CSKY_AXI_FREQ		(CONFIG_PRELOAD_AXI_CLK * 1000 * 1000)
#define CSKY_AHB_FREQ		(CONFIG_PRELOAD_AHB_CLK * 1000 * 1000)
#define CSKY_APB_FREQ		(CONFIG_PRELOAD_APB_CLK * 1000 * 1000)
#define CSKY_DRAM_FREQ		(CONFIG_PRELOAD_DRAM_CLK * 1000 * 1000)
#define CSKY_DTO_FREQ		(CONFIG_PRELOAD_DTO_CLK * 1000 * 1000)
#define CSKY_UART_FREQ		(CONFIG_PRELOAD_UART_CLK)

/*
 * Image properties
 */
#define IMAGE_POS			(0x10000)
#define IMAGE_SIZE			(0x200000)

/*
 * DRAM
 */
#define DRAM_BASE			(0x90000000)

/*
 * Peripherals
 */
#define GCTL_BASE			(0xb0000000)
#define DRAMC_BASE			(0xb0010000)
#define SPI_BASE			(0xb0020000)
#define TIM_BASE			(0xb0030000)
#define SER_BASE			(0xb0040000)

#define SSEG1_BASE			(0x00000000)

#define IMAGE_MAGIC			(0x55aa55aa)

#define MHZ					(1000000)

#define osc_freq			(24 * MHZ)
#define dto_freq			(CSKY_DTO_FREQ)
#define dvb_freq			(CONFIG_PRELOAD_DVB_CLK * 1000 * 1000)

#define __startup			__attribute__((__section__(".startup.text")))
#define __startup_data		__attribute__((__section__(".startup.data")))

/*
 * The csky architecture uses a direct-mapped memory model, so the
 * physical address is the same as the virtual address.
 */
static inline virtual_addr_t cache_to_dma(virtual_addr_t addr)
{
	return addr;
}

#ifdef __cplusplus
}
#endif

#endif /* __GX6605S_H__ */
