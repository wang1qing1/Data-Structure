#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int BTDataType;

typedef struct BTNode
{
	BTDataType val;
	struct BTNode* Lchild;
	struct BTNode* Rchild;
}BTNode;

BTNode* BuyNode(BTDataType val);

BTNode* CreatTree();

void PostOrder(BTNode* root);

void InOrder(BTNode* root);

void PrevOrder(BTNode* root);

int SizeNode(BTNode* root);

int SizeLeaf(BTNode* root);

int HighTree(BTNode* root);

int KSize(BTNode* root, int k);

int KSize_(BTNode* root, int k);