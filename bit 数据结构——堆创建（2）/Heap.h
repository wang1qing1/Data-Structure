#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php);

void HeapPush(Heap* php, HPDataType x);

void AdjustUp(HPDataType* a, int child);

void Print(Heap* php, int n);

void Swap(HPDataType* n1, HPDataType* n2);

void HeapPop(Heap* php);

void AdjustDown(Heap* php, int parent);

HPDataType HeapTop(Heap* php);

void HeapCreate(Heap* php, HPDataType* arr, int n);