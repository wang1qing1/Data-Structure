#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode
{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

typedef struct QueueNode
{
	TreeNode *Qdata;
	struct QueueNode* prev;
	struct QueueNode* next;
}QueueNode;

void InitQueue(QueueNode** pphead);

void PushQeueNode(QueueNode** pphead, TreeNode* X);

void PrinQueue(QueueNode* phead);

void CreatTree(TreeNode** T);

void PrevPrinTree(TreeNode* T);

void LayerSequence(TreeNode* T, QueueNode* phead);

TreeNode* GetQueueNode(QueueNode* phead);

bool JaEmpty(QueueNode* phead);
