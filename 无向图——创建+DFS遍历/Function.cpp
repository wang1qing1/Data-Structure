#include"GRAPH.h"

//初始化队列

//初始化图
Graph* InitGraph(int vexsNum)
{
	Graph* G = (Graph*)malloc(sizeof(Graph));//创建图的框架
	G->vexs = (char*)malloc(sizeof(char) * vexsNum);//开辟图的数据域空间
	G->arcs = (int**)malloc(sizeof(int*) * vexsNum);//开辟图的边域空间
	for (int i = 0; i < vexsNum; i++)
	{
		G->arcs[i] = (int*)malloc(sizeof(int) * vexsNum);//开辟图边域空间
	}
	G->vexsNum = vexsNum;//数据个数
	G->arcNum = 0;//边数——为初始数据时为零；
	return G;
}

//创建图
void CreateGraph(Graph* G, char* vexs, int arcs[5][5])
{
	//将数据转移到图中的数据域中； 
	for (int i = 0; i < G->vexsNum; i++)
	{
		G->vexs[i] = vexs[i];
	}
	//将边的结构转移到图的边域中；
	for (int i = 0; i < G->vexsNum; i++)
	{
		for (int j = 0; j < G->vexsNum; j++)
		{
			G->arcs[i][j] = arcs[i][j];
			if (G->arcs[i][j] == 1)
			{
				G->arcNum++;//每次增加一个边，变数就增加一；
			}
		}
	}
	G->arcNum /= 2;//因为是无向图，两个结点之间顶多只有一条边；
}

//遍历图——DFS深度优先遍历
void DFS(Graph* G, int* visited, int index)
{
	//先找一点进行开始遍历；
	printf("%c ", G->vexs[index]);
	//将遍历过的数据，用标记数组标记下；
	visited[index] = 1;
	//查找并访问与该节点有边且没有被访问过的结点，以该点开始进行递归性的访问与该节点有边且没有被访问过的结点
	for (int i = 0; i < G->vexsNum; i++)
	{
		if (G->arcs[index][i] == 1 && visited[i] == 0)
		{
			DFS(G, visited, i);
		}
	}
}

