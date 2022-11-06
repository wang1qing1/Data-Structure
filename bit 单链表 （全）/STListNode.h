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

SListNode* BuySTLNode(SLTDataType x);

SListNode* CreateSList(n);

void PrintList(SListNode* phead);

void STLPushBank(SListNode** pphead, SLTDataType x);

void STLPopBank(SListNode** pphead);

void SLTPushFront(SListNode** pphead, SLTDataType x);

void SLTPopFront(SListNode** pphead);

SListNode* SListFind(SListNode* phead, SLTDataType x);

void SListInserAfter(SListNode* pos, SLTDataType x);

void SListEraseAfter(SListNode* pos);

void SListDestroy(SListNode** pphead);

void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x);

void SLTErase(SListNode** pphead, SListNode* pos);



