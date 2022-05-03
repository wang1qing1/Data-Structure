#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}TreeNode;

typedef struct HaffTree
{
	TreeNode* data;
	int height;
}HaffTree;

HaffTree* hafTree_Init(int* weight, int num);

int* SelectMin(HaffTree* T);

void CreateHafmTree(HaffTree* T,  int num);

void PrevClue(HaffTree* T, int index);

