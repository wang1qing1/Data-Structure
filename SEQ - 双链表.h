#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
typedef int SListdataType;
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListNode
{
	SListdataType data;
	struct ListNode *prev;
	struct ListNode* next;
}ListNode;

void ListInit(ListNode** pphead);

ListNode* BuyListNode(int x);

void ListPushBank(ListNode* phead, SListdataType x);

void ListPrintf(ListNode* phead);

void ListPopBank(ListNode* phead);

void ListPushFront(ListNode* phead, SListdataType x);

void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, SListdataType x);

void ListPopPos(ListNode* pos);

void ListPushPosAfter(ListNode* pos, SListdataType x);

void ListDestroy(ListNode* phead);

void ListDestroyAll(ListNode* phead);