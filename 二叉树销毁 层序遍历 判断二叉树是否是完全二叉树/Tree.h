#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"Queue.h"

//typedef int BTDataType;
//
//typedef struct BTNode
//{
//	BTDataType val;
//	struct BTNode* Lchild;
//	struct BTNode* Rchild;
//}BTNode;

BTNode* BuyNode(BTDataType val);

BTNode* CreatTree();

bool isSameTree(BTNode* p, BTNode* q);

BTNode* invertTree(BTNode* root);

bool isSymmetric(BTNode* root);

bool _isSymmetric(BTNode* Lroot, BTNode* Rroot);

bool IsSymmetric(BTNode* root);

void BinaryTreeDestory(BTNode* root);

void FloorOrder(BTNode* root);

bool BinaryTreeComplete(BTNode* root);
