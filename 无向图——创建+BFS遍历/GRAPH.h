#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//图结构
typedef struct Graph 
{
	char* vexs;     //数据
	int** arcs;     //边
	int vexsNum;    //数据个数
	int arcNum;     //边数
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
