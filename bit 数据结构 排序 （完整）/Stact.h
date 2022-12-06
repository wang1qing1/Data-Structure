#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDateType;

typedef struct Stact
{
	STDateType* date;
	int capacity;
	int top;
}ST;

ST* StactInit();

void StactPushBank(ST* Stact, STDateType x);

int StactSize(ST* Stact);

void StactDestory(ST* Stact);

void StactPopBank(ST* Stact);

STDateType StactTop(ST* Stact);

bool StactEmpty(ST* stact);

