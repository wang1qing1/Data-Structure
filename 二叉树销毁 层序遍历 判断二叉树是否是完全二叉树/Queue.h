#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int BTDataType;

typedef struct BTNode
{
	BTDataType val;
	struct BTNode* Lchild;
	struct BTNode* Rchild;
}BTNode;

typedef BTNode* QUDateType;
typedef struct QueueNode
{
	QUDateType date;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pque);

void QueuePush(Queue* pque, QUDateType x);

bool QueueEmpty(Queue* pque);

QUDateType QueueFront(Queue* pque);

QUDateType QueueBack(Queue* pque);

int QueueSize(Queue* pque);

void QueuePop(Queue* pque);

void QueueDestroy(Queue* pque);