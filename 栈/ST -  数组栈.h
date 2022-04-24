#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDATATYPE;
typedef struct Stack
{
	STDATATYPE* a;
	int top;
	int capacity;
}ST;

void StactInit(ST* stact);

void StactDestry(ST* stact);

void StactPush(ST* stact, STDATATYPE x);

void StactPrin(ST* stact);

void StactPop(ST* stact);

STDATATYPE GetStactData(ST* stact);

int Stactsize(ST* stact);

bool StactEmpty(ST* stact);