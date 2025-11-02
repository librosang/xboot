/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2021 Sanpe <sanpeqf@gmail.com>
 */

#ifndef __SYS_UART_H__
#define __SYS_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

void sys_uart_init(int, int);
void sys_uart_putc(char);
void sys_uart_print(const char *);

#ifdef __cplusplus
}
#endif

#endif /* __SYS_UART_H__ */
