#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

//图
typedef struct Graph
{
    char* vexc;
	int** arcs;
	int vexsNum;
	int arcsNum;
};

//集合———用于存储需要查找最小的权值的图结点集合
typedef struct Edge
{
	char vex;
	int weight;
}Edge;

Graph* InitGraph(int vexsNum);

void DFS(Graph* G, int* visited, int index);

void CreatGraph(Graph* G, int arcs[][5], char* vexc);

Edge* InitEdga(Graph* G, int index);

int GetMinEdga(Graph* G, Edge* E);

void Prim(Graph* G, int index);






/*
*       
        0,6,1,5,MAX,MAX,
		6,0,5,MAX,3,MAX,
		1 ,5 ,0 ,5 ,6 ,4,
		5,MAX,5,0,MAX,2,
		MAX,3,6,MAX,0,6,
		MAX,MAX,4,2,6,0
* 
* 
* 
* 
*/