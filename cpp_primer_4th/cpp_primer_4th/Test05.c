/*******************************************************************************
* Project         DFL331
* (c) Copyright   2017
* Company         Shanghai Visteon Electronic Co, Ltd
*                 All rights reserved.
* @file           ring_buffer.c
* @module         common
* @author         Tian Yufang
* @brief          Implement Ring Buffer
* @changelog      1. Creat File
********************************************************************************/
#include <stdio.h>  
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <malloc.h>
#include <errno.h>

#include "Test05.h"

#ifdef	ENABLE_RB

#define RB_LOG		printf
#define RB_TRACE	printf
#define RB_ERROR	printf

typedef struct
{
	unsigned int pos_w;
	unsigned int pos_r;
	struct
	{
		unsigned int data_size;
		unsigned int buffer_len;
		void *pAddr;
	}stData;
}stRingBuffer;

typedef struct
{
	unsigned char data[8];
}stTest;

extern RB_Handle RB_InitProc(const unsigned int data_size, const unsigned int buffer_len)
{
	stRingBuffer *pHandle = NULL;
	pHandle = malloc(sizeof(stRingBuffer));
	if (NULL != pHandle)
	{
		pHandle->pos_w = 1;
		pHandle->pos_r = 1;
		pHandle->stData.data_size = data_size;
		pHandle->stData.buffer_len = buffer_len;
		pHandle->stData.pAddr = NULL;
		pHandle->stData.pAddr = malloc(data_size * buffer_len);
		if (NULL != pHandle->stData.pAddr)
		{
			memset(pHandle->stData.pAddr, 0, data_size * buffer_len);
			RB_LOG("Ring Buffer Init OK, Handle : [%08X], Data Addr : [%08X], Data Len : [%d x %d = %d]", pHandle, pHandle->stData.pAddr, data_size, buffer_len, data_size * buffer_len);
		}
		else
		{
			RB_ERROR("RingBuffer data malloc failed !");
		}
	}
	else
	{
		RB_ERROR("RingBuffer malloc failed !");
	}

	return (RB_Handle)pHandle;
}

extern bool RB_pushData(RB_Handle user, const void *data_addr)
{
	bool rslt = false;
	stRingBuffer *pHandle = (stRingBuffer *)user;
	stTest *parray;
	void *paddr;

	if (NULL != pHandle)
	{
		if ((pHandle->pos_w + 1) != pHandle->pos_r)
		{
			parray = (stTest *)pHandle->stData.pAddr;
			paddr = (unsigned char *)pHandle->stData.pAddr + (pHandle->pos_w * pHandle->stData.data_size);
			memcpy(paddr, data_addr, pHandle->stData.data_size);
			RB_TRACE("RingBuffer push data to [%d]", pHandle->pos_w);
			pHandle->pos_w = (pHandle->pos_w + 1) % pHandle->stData.buffer_len;
			rslt = true;
		}
		else
		{
			RB_ERROR("RingBuffer [%08X] is full", user);
		}
	}
	else
	{
		RB_ERROR("RingBuffer handle [%08X] is invalid !", user);
	}

	return rslt;
}

extern bool RB_popData(RB_Handle user, void *data_addr)
{
	bool rslt = false;
	stRingBuffer *pHandle = (stRingBuffer *)user;

	if (NULL != pHandle)
	{
		if (pHandle->pos_r != pHandle->pos_w)
		{
			memcpy(data_addr, ((unsigned char *)pHandle->stData.pAddr + (pHandle->pos_r * pHandle->stData.data_size)), pHandle->stData.data_size);
			RB_TRACE("RingBuffer pop data to [%d]", pHandle->pos_r);
			pHandle->pos_r = (pHandle->pos_r + 1) % pHandle->stData.buffer_len;
			rslt = true;
		}
		else
		{
			RB_ERROR("RingBuffer [%08X] is empty", user);
		}
	}
	else
	{
		RB_ERROR("RingBuffer handle [%08X] is invalid !", user);
	}

	return rslt;
}

extern void RB_destroyHandle(RB_Handle user)
{
	stRingBuffer *pHandle = (stRingBuffer *)user;

	if (NULL != pHandle)
	{
		if (NULL != pHandle->stData.pAddr)
		{
			free(pHandle->stData.pAddr);
			pHandle->stData.pAddr = NULL;
		}
		free(pHandle);
		pHandle = NULL;
	}
	else
	{
		RB_ERROR("RingBuffer handle [%08X] is invalid !", user);
	}
}

extern bool RB_isEmpty(RB_Handle user)
{
	bool rslt = false;
	stRingBuffer *pHandle = (stRingBuffer *)user;

	if (NULL != pHandle)
	{
		if (pHandle->pos_r == pHandle->pos_w)
		{
			rslt = true;
		}
	}

	return rslt;
}


typedef struct
{
	unsigned int msgid;
	unsigned int msgdata;
}stMsg;

int main(void)
{
	stMsg RcvMsg;
	stMsg SndMsg;

	SndMsg.msgid = 0xAA;
	SndMsg.msgdata = 0xBB;
	RB_Handle Handle;
	Handle = RB_InitProc(sizeof(stMsg), 10);
	RB_pushData(Handle, &SndMsg);
	RB_popData(Handle, &RcvMsg);

	return 0;
}

#endif

