#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct BTNode
{
	int val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* BTNodeCreat(int val);

void PrevOrder(BTNode* root);

int SizeNode(BTNode* root);

int LeafSize(BTNode* root);

BTNode* FindNode(BTNode* root, int x);
