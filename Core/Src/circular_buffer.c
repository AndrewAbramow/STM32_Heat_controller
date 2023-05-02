/*
 * CircularBuffer.c
 *
 *  Created on: 1 ����. 2018 �.
 *      Author: VasinS
 */

#include "circular_buffer.h"

int CBuff_GetSaveCharCount(CircularBuffer* cb)
{
	int result = 0;

	int add_pos = cb->add_pos;
	int get_pos = cb->get_pos;

	if(add_pos >= get_pos)
	{
		result = add_pos - get_pos;
	}
	else
	{
		result = add_pos + cb->size - get_pos;
	}

	return result;
}

void CBuff_Init(CircularBuffer* cb, char* memory, int size)
{
	cb->size         = size;
	cb->c_bytes      = memory;
	cb->add_pos      = 0;
	cb->get_pos      = 0;
	cb->next_add_pos = 1;
}

void CBuff_AddChar(CircularBuffer* cb, char c)
{
	if(cb->next_add_pos != cb->get_pos)
	{
		(cb->c_bytes)[cb->add_pos] = c;
		cb->add_pos = cb->next_add_pos;
		cb->next_add_pos = (cb->next_add_pos + 1) % (cb->size);
		cb->add_res = 0;
	}
	else
	{
		cb->add_res = 255;
	}
}

char CBuff_GetChar(CircularBuffer* cb)
{
	char result = 255;

	if(cb->get_pos != cb->add_pos)
	{
		result = (cb->c_bytes)[cb->get_pos];
		cb->get_pos = (cb->get_pos + 1) % (cb->size);
		cb->get_res = 0;
	}
	else
	{
		cb->get_res = 255;
	}

	return result;
}

char CBuff_ReadChar(CircularBuffer* cb)
{
	char result = 255;

	if(cb->get_pos != cb->add_pos)
	{
		result = (cb->c_bytes)[cb->get_pos];
		cb->get_res = 0;
	}
	else
	{
		cb->get_res = 255;
	}

	return result;
}

char CBuff_IsEmpty(CircularBuffer* cb)
{
	char result = 0;

	if((cb->add_pos) == (cb->get_pos)) result = 1;

	return result;
}

