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

// 尾插尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

// 头插头删
void SLPushBack(SL* ps);
void SLPopFront(SL* ps);

// 中间插入删除
// 在pos位置插入数据
void SLInsert(SL* ps, int pos, SLDataType x);
// 删除pos位置数据
void SLErase(SL* ps, int pos);

//int SLFind(SL* ps, SLDataType x);

// begin查找x的起始位置
int SLFind(SL* ps, SLDataType x, int begin);

