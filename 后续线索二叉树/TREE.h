#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
	int ltag;
	struct TreeNode* lchild;
	char data;
	struct TreeNode *parent;
	int rtag;
	struct TreeNode* rchild;
};

void CreateTree(TreeNode** T, TreeNode* par);

void AfteClue(TreeNode* T, TreeNode** prev);

TreeNode* GetNext(TreeNode* T);

TreeNode* GetFrist(TreeNode* T);

