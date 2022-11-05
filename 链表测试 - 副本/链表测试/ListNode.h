#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType date;
	struct SListNode* next;
}SListNode;

SListNode* CreateSList(int* arr, int n)
{
	SListNode* phead = NULL;
	SListNode* tail = NULL;
	for (int i = 0; i < n; i++)
	{
		SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
		newnode->date = arr[i];
		newnode->next = NULL;
		if (phead == NULL)
		{
			phead = newnode;
			tail = phead;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
	return phead;
}

void PrintList(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL");
}