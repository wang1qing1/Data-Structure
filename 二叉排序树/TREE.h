#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

void SortTree(TreeNode** T, int data);

TreeNode* SeaTree(TreeNode* T, int key);

void MidClue(TreeNode* T);
