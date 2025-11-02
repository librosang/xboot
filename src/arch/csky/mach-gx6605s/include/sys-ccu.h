/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2021 Sanpe <sanpeqf@gmail.com>
 */

#ifndef __SYS_CCU_H__
#define __SYS_CCU_H__

#ifdef __cplusplus
extern "C" {
#endif

void sys_ccu_init(void);
void sys_ccu_cpu(uint32_t dto, uint32_t freq);
void sys_ccu_axi(uint32_t cpu, uint32_t freq);
void sys_ccu_ahb(uint32_t cpu, uint32_t freq);
void sys_ccu_apb(uint32_t dto, uint32_t freq);
void sys_ccu_dram(uint32_t freq);
void sys_dramc_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __SYS_CCU_H__ */
