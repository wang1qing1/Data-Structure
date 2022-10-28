#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType*date;   //����
	int size;   //��Ч���ݸ���
	int capacity;  //������
}SeqList;

void SeqListInit(SeqList* pSL);

void SeqListPushBank(SeqList* pSL, SLDateType date);

void SeqListPrintf(SeqList* pSL);

void SeqListDestroy(SeqList* pSL);

void SeqListPopbank(SeqList* pSL);

void SeqListPushFront(SeqList* pSL, SLDateType* date);

void SeqListPopFront(SeqList* pSL);

int SeqListFind(SeqList* pSL, SLDateType date);

void SeqListInsert(SeqList* pSL, size_t pos, SLDateType date);
