
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QUEUETYPE;

typedef struct QueueData
{
	struct QueueData* next;
	QUEUETYPE data;
}QueueData;

typedef struct Queue
{
	QueueData* head;
	QueueData* tail;
}Queue;

void QInit(Queue* queue);

void QueuePrintf(Queue* queue);

void QueuePush(Queue* queue, int x);

void QueueDestoy(Queue* queue);

void QueueDestoy(Queue* queue);

void QueuePop(Queue* queue);

QUEUETYPE GetQueueFront(Queue* queue);

QUEUETYPE ReadQueueBank(Queue* queue);

QUEUETYPE ReadQueueFront(Queue* queue);

bool QueueEmpty(Queue* queue);

int QueueSize(Queue* queue);

