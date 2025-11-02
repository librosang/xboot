/* SPDX-License-Identifier: MIT */
/*
 * Copyright(c) 2021 Sanpe <sanpeqf@gmail.com>
 */

#ifndef __SYS_TIMER_H__
#define __SYS_TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

void tim_init(uint32_t freq);
void tim_mdelay(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif /* __SYS_TIMER_H__ */
