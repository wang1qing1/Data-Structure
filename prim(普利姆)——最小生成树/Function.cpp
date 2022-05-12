#include"PRIM.h"

//初始化图的空间
Graph* InitGraph(int vexsNum)
{
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexc = (char*)malloc(sizeof(char)*vexsNum);
	G->arcs = (int**)malloc(sizeof(int*)*vexsNum);
	for (int i = 0; i < vexsNum; i++)
	{
		G->arcs[i] = (int*)malloc(sizeof(int) * vexsNum);
	}
	G->vexsNum = vexsNum;
	G->arcsNum = 0;
	return G;
}

//创建图；
void CreatGraph(Graph* G, int arcs[][5], char* vexc)
{
	//数据域的赋值
	for (int i = 0; i < G->vexsNum; i++)
	{
		G->vexc[i] = vexc[i];
	}
	//权值域的赋值
	for (int i = 0; i < G->vexsNum; i++)
	{
		for (int j = 0; j < G->vexsNum; j++)
		{
			G->arcs[i][j] = arcs[i][j];
			G->arcsNum++;
		}
	}
	G->arcsNum /= 2;
}

//初始化集合；
Edge* InitEdga(Graph* G,int index)
{
	Edge* E = (Edge*)malloc(sizeof(Edge)*G->vexsNum);
	for (int i = 0; i < G->vexsNum; i++)
	{
		E[i].vex = G->vexc[index];
		E[i].weight = G->arcs[index][i];
	}
	return E;
}

//获得集合中的权值最小的图结点的下标；
int GetMinEdga(Graph* G,Edge*E)
{
	int min = MAX;
	int index;
	for (int i = 0; i < G->vexsNum; i++)
	{  
		if (E[i].weight != 0 && min > E[i].weight)
		{
			min = E[i].weight;
			index = i;
		}
	}
	return index;
}

//普利姆算法
void Prim(Graph* G, int index)
{
	int min;
	Edge* E = InitEdga(G, index);
	for (int i = 0; i < G->vexsNum - 1; i++)
	{
		min = GetMinEdga(G, E);
	    //获得集合中权值最小的下标，此下标即是权值两头的数据在E中的下标；和在G->vexc中的下标；
		printf("%c-->%c,weight=%d\n", E[min].vex, G->vexc[min], E[min].weight);
		E[min].weight = 0;
		//调整集合的数据
		for (int j = 0; j < G->vexsNum; j++)
		{
			//将找到的权值两头数据的权值进行一一比较，将较小的权值的数据转移到集合中去；
			if (G->arcs[min][j] < E[j].weight)
			{
				E[j].weight = G->arcs[min][j];
				E[j].vex = G->vexc[min];
			}
		}
	}
}

//深度优先遍历
void DFS(Graph* G,int *visited,int index)
{
	printf("%c ", G->vexc[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vexsNum; i++)
	{
		if (G->arcs[index][i] > 0&&G->arcs[index][i]!=MAX && visited[i] == 0)
		{
			DFS(G, visited, i);
		}
	}
}

