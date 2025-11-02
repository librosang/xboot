/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2021 Sanpe <sanpeqf@gmail.com>
 */

#ifndef __SYS_SPINOR_H__
#define __SYS_SPINOR_H__

#ifdef __cplusplus
extern "C" {
#endif

void __startup sys_spinor_init(void);
int __startup sys_spinor_read(uint8_t *buff, size_t addr, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* __SYS_SPINOR_H__ */
