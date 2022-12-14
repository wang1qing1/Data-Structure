#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int DataType;
struct Node
{
	struct Node* Child1; // ��һ������
	struct Node* Child2; // �ڶ�������
	//
	// ...... ����ȷ����������
	//
	DataType data; // ����е�������

};
typedef int BTDataType;
// ������
struct BinaryTreeNode
{
	struct BinTreeNode* _pLeft; // ָ��ǰ�ڵ�����
	struct BinTreeNode* _pRight; // ָ��ǰ�ڵ��Һ���
	BTDataType _data; // ��ǰ�ڵ�ֵ��
};
// ������
struct BinaryTreeNode_
{
	struct BinTreeNode_* _pParent; // ָ��ǰ�ڵ��˫��
	struct BinTreeNode_* _pLeft; // ָ��ǰ�ڵ�����
	struct BinTreeNode_* _pRight; // ָ��ǰ�ڵ��Һ���
	BTDataType _data; // ��ǰ�ڵ�ֵ��
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
