#include"PRIM.h"

//��ʼ��ͼ�Ŀռ�
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

//����ͼ��
void CreatGraph(Graph* G, int arcs[][5], char* vexc)
{
	//������ĸ�ֵ
	for (int i = 0; i < G->vexsNum; i++)
	{
		G->vexc[i] = vexc[i];
	}
	//Ȩֵ��ĸ�ֵ
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

//��ʼ�����ϣ�
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

//��ü����е�Ȩֵ��С��ͼ�����±ꣻ
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

//����ķ�㷨
void Prim(Graph* G, int index)
{
	int min;
	Edge* E = InitEdga(G, index);
	for (int i = 0; i < G->vexsNum - 1; i++)
	{
		min = GetMinEdga(G, E);
	    //��ü�����Ȩֵ��С���±꣬���±꼴��Ȩֵ��ͷ��������E�е��±ꣻ����G->vexc�е��±ꣻ
		printf("%c-->%c,weight=%d\n", E[min].vex, G->vexc[min], E[min].weight);
		E[min].weight = 0;
		//�������ϵ�����
		for (int j = 0; j < G->vexsNum; j++)
		{
			//���ҵ���Ȩֵ��ͷ���ݵ�Ȩֵ����һһ�Ƚϣ�����С��Ȩֵ������ת�Ƶ�������ȥ��
			if (G->arcs[min][j] < E[j].weight)
			{
				E[j].weight = G->arcs[min][j];
				E[j].vex = G->vexc[min];
			}
		}
	}
}

//������ȱ���
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

