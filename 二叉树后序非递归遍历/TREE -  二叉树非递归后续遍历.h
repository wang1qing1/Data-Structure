#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct TreeNode {
	char data;
	int sign;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

typedef struct Stact {
	TreeNode* Data;
	struct Stact* next;
	struct Stact* prev;

};

void CreatTree(TreeNode** T);

void PrevTra(TreeNode* T);

void InitStact(Stact** St);

void PushStact(Stact* phead, TreeNode* X);

Stact* GetStactNode(Stact* phead);

void Printf(Stact* phead);

Stact* ReadStactNode(Stact* phead);

void MyAftTRa(Stact* phead, TreeNode* T);

