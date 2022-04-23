#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct TreeNode//½áµã
{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

void CreaTree(TreeNode** T);

void PrevPriTree(TreeNode* T);

void MidPriTree(TreeNode* T);

void AftPriTree(TreeNode* T);