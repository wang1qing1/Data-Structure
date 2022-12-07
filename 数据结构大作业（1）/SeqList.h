#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>
#include"Function.h"



void SLPrint(SL* ps);
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLCheckCapacity(SL* ps);

// β��βɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

// ͷ��ͷɾ
void SLPushBack(SL* ps);
void SLPopFront(SL* ps);

// �м����ɾ��
// ��posλ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x);
// ɾ��posλ������
void SLErase(SL* ps, int pos);

//int SLFind(SL* ps, SLDataType x);

// begin����x����ʼλ��
int SLFind(SL* ps, SLDataType x, int begin);

