/*******************************************************************************
* Project         DFL331
* (c) Copyright   2017
* Company         Shanghai Visteon Electronic Co, Ltd
*                 All rights reserved.
* @file           ring_buffer.h
* @module         common
* @author         Tian Yufang
* @brief          interface of ring buffer Re-pack
* @changelog      1. Creat File
********************************************************************************/
#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#ifdef USE_TEST05_H

#define ENABLE_RB

#ifdef ENABLE_RB

typedef void * RB_Handle;

extern RB_Handle RB_InitProc(const unsigned int data_size, const unsigned int data_len);
extern bool RB_pushData(RB_Handle user, const void *data_addr);
extern bool RB_popData(RB_Handle user, void *data_addr);
extern void RB_destroyHandle(RB_Handle user);
extern bool RB_isEmpty(RB_Handle user);

#endif
#endif
#endif	/* __RING_BUFFER_H__ */

