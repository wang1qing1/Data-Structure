#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
	int ltag;
	struct TreeNode* lchild;
	char data;
	int rtag;
	struct TreeNode* rchild;
}TreeNode;

void CreateTree(TreeNode** T);

//void Print(TreeNode* T);

void FroClue(TreeNode* T, TreeNode** prev);

TreeNode* GetNext(TreeNode* node);

