#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	char data;
}BTnode;

typedef BTnode DATA_TYPE;

typedef struct Qnode
{
	DATA_TYPE* pdata;
	struct Qnode* prov;
	struct Qnode* next;
}Queue;

int LeafNodeSize(BTnode* root);

int NodeSize(BTnode* root);

void NodeSize1(BTnode* root, int* size);

void AfTrave(BTnode* root);

void MidTrave(BTnode* root);

void ProTrave(BTnode* root);

Queue* InitQueue();

void InputQueue(Queue* head, DATA_TYPE* pdata);

void PutQueue(Queue* head);

void DeleQueue(Queue* head);

int Judge(Queue* head);