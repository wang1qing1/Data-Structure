#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char BTDataType;

typedef struct BTNode
{
	BTDataType val;
	struct BTNode* Lchild;
	struct BTNode* Rchild;
}BTNode;

BTNode* CreatTree();

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a,int* pi);

void PrevOrder(BTNode* root);