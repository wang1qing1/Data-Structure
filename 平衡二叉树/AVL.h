#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int data;
	int height;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
};

TreeNode* newNode(int key);

void InserAVL(TreeNode** root, int key);

void PrevClue(TreeNode* root);

void RR_Rotate(TreeNode** root);

int GetBalance(TreeNode* root);

void LL_Rotate(TreeNode** root);

int max(int a, int b);

int Getheight(TreeNode* root);


