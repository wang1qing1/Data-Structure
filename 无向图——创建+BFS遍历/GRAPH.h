#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//ͼ�ṹ
typedef struct Graph 
{
	char* vexs;     //����
	int** arcs;     //��
	int vexsNum;    //���ݸ���
	int arcNum;     //����
}Graph;

typedef struct QueueNode
{
	int data;
	struct QueueNode * prev;
	struct QueueNode * next;
}Queue;

Graph* InitGraph(int vexsNum);

void CreateGraph(Graph* G, char* vexs,int arcs[5][5]);

Queue* InitQueue();

int GetQueue(Queue* head);

void InserNode(Queue* head, int data);

Queue* NewNode(char data);

Queue* InitQueue();

void BFS(Graph* G, int* visited, int index);
