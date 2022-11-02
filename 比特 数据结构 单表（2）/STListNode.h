#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	int date;
	struct SListNde* next;
}SListNode;

SListNode* BuySTLNode(SLTDateType x);

SListNode* CreateSList(n);

void PrintList(SListNode* phead);

void STLPushBank(SListNode** pphead, SLTDateType x);

void STLPopBank(SListNode** pphead);

void SLTPushFront(SListNode** pphead, SLTDateType x);

void SLTPopFront(SListNode** pphead);

SListNode* SListFind(SListNode* phead, SLTDateType x);

void SListInserAfter(SListNode* pos, SLTDateType x);

void SListEraseAfter(SListNode* pos);

void SListDestroy(SListNode* phead);


