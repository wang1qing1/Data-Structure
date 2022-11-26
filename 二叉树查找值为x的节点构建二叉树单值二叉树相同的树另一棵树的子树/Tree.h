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

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi);

void PrevOrder(BTNode* root);