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


Graph* InitGraph(int vexsNum);

void CreateGraph(Graph* G, char* vexs, int arcs[5][5]);

void DFS(Graph* G, int* visited, int index);








