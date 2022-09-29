#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define INT_TYPE int
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct ListNode
{
	struct ListNode* prev;
	INT_TYPE date;
	struct ListNode* next;
}ListNode;

ListNode* InitListNode();

void HeadAdd(ListNode* head);

void PrintList(ListNode* head);

void TailAdd(ListNode* head);

void MidAdd(ListNode* head);

void Seek(ListNode* head, INT_TYPE date);

void Seek(ListNode* head, INT_TYPE date);
