#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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
struct BinaryTreeNode
{
	struct BinTreeNode* _pParent; // ָ��ǰ�ڵ��˫��
	struct BinTreeNode* _pLeft; // ָ��ǰ�ڵ�����
	struct BinTreeNode* _pRight; // ָ��ǰ�ڵ��Һ���
	BTDataType _data; // ��ǰ�ڵ�ֵ��
};
