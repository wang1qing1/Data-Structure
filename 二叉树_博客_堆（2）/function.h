#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
typedef int DataType;
struct Node
{
	struct Node* Child1; // 第一个孩子
	struct Node* Child2; // 第二个孩子
	//
	// ...... 不能确定孩子书数
	//
	DataType data; // 结点中的数据域

};
typedef int BTDataType;
// 二叉链
struct BinaryTreeNode
{
	struct BinTreeNode* _pLeft; // 指向当前节点左孩子
	struct BinTreeNode* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
};
// 三叉链
struct BinaryTreeNode_
{
	struct BinTreeNode_* _pParent; // 指向当前节点的双亲
	struct BinTreeNode_* _pLeft; // 指向当前节点左孩子
	struct BinTreeNode_* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
};

typedef int HPDateType;
typedef struct Heap
{
	HPDateType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php);

void HeapPush(Heap* php, HPDateType x);

void HeapCreate(Heap* php, HPDateType* arr, int n);

void HeapPop(Heap* php);

HPDateType HeapTop(Heap* php);

int HeapSize(Heap* php);

bool HeapEmpty(Heap* php);

void AdjustDown_big(HPDateType* arr, int n, int parent);

void AdjustDown_samll(HPDateType* arr, int n, int parent);

void HeapTopK(Heap* php, int k);

void TopK_File( int k);

void Print(Heap* php);

void HeapDestroy(Heap* php);

