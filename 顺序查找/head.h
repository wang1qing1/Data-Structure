#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct List
{
	int* data;
	int lengh;
	int count;
}List;

List* ListInit(int lengh);

void ListAdd(List*L,int num);

int ListSearch(List* L, int key);