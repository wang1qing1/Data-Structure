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

void SlistPrintf(SlistNode* phead);//��ӡ��

void SListpushback(SlistNode** pphead, SListdataType num);//β�����ӽ�㣻

SlistNode* BuySListNode(SListdataType x);//���ӽ�㣻

void SListpophback(SlistNode** pphead);//β��ɾ����㣻

SlistNode* FindList(SlistNode* phead, SListdataType x);//����һ����㣻

void SlistInserAfter(SlistNode** pos, SListdataType x);//��pos֮������һ����㣻

void SlistEraseAfter(SlistNode** pos);//ɾ��pos֮���һ����㣻
