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


Graph* InitGraph(int vexsNum);

void CreateGraph(Graph* G, char* vexs, int arcs[5][5]);

void DFS(Graph* G, int* visited, int index);








