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

void MidClue(TreeNode* T, TreeNode** prev);

TreeNode* GetFrist(TreeNode* node);

TreeNode* GetNext(TreeNode* node);