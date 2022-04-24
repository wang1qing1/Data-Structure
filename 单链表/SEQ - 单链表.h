#pragma once

#include<stdio.h>

#include<stdlib.h>

#include<assert.h>

typedef int SListdataType;

typedef struct SlistNode
{
	SListdataType data;
	struct SlistNode* next;
}SlistNode;

void SlistPrintf(SlistNode* phead);//打印；

void SListpushback(SlistNode** pphead, SListdataType num);//尾部增加结点；

SlistNode* BuySListNode(SListdataType x);//增加结点；

void SListpophback(SlistNode** pphead);//尾部删除结点；

SlistNode* FindList(SlistNode* phead, SListdataType x);//查找一个结点；

void SlistInserAfter(SlistNode** pos, SListdataType x);//在pos之后增加一个结点；

void SlistEraseAfter(SlistNode** pos);//删除pos之后的一个结点；
