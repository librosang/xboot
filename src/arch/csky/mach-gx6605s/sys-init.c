/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2021 Sanpe <sanpeqf@gmail.com>
 */

#include <xboot.h>
#include <gx6605s.h>
#include <sys-spinor.h>
#include <sys-ccu.h>
#include <sys-uart.h>

static const char __startup_data preload_entry[] = "\nxboot\n";
static const char __startup_data preload_done[] = "booting...\n";

void __startup sys_init(void)
{
    sys_ccu_init();
    sys_ccu_cpu(CSKY_DTO_FREQ, CSKY_CPU_FREQ);
    sys_ccu_axi(CSKY_CPU_FREQ, CSKY_AXI_FREQ);
    sys_ccu_ahb(CSKY_CPU_FREQ, CSKY_AHB_FREQ);
    sys_ccu_apb(CSKY_DTO_FREQ, CSKY_APB_FREQ);
    sys_ccu_dram(CSKY_DRAM_FREQ);

    tim_init(CSKY_APB_FREQ);
    sys_uart_init(CSKY_APB_FREQ, CSKY_UART_FREQ);

    sys_dramc_init();
    sys_spinor_init();
    sys_uart_print(preload_entry);

    if (sys_spinor_read((void *)DRAM_BASE, IMAGE_POS, IMAGE_SIZE) != 0) {
        sys_uart_print("Error: Failed to read image from SPI NOR flash.\n");
        while (1);
    }
    sys_uart_print(preload_done);
}
