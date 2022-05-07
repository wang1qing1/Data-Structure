#include"GRAPH.h"

//��ʼ������

//��ʼ��ͼ
Graph* InitGraph(int vexsNum)
{
	Graph* G = (Graph*)malloc(sizeof(Graph));//����ͼ�Ŀ��
	G->vexs = (char*)malloc(sizeof(char) * vexsNum);//����ͼ��������ռ�
	G->arcs = (int**)malloc(sizeof(int*) * vexsNum);//����ͼ�ı���ռ�
	for (int i = 0; i < vexsNum; i++)
	{
		G->arcs[i] = (int*)malloc(sizeof(int) * vexsNum);//����ͼ����ռ�
	}
	G->vexsNum = vexsNum;//���ݸ���
	G->arcNum = 0;//��������Ϊ��ʼ����ʱΪ�㣻
	return G;
}

//����ͼ
void CreateGraph(Graph* G, char* vexs, int arcs[5][5])
{
	//������ת�Ƶ�ͼ�е��������У� 
	for (int i = 0; i < G->vexsNum; i++)
	{
		G->vexs[i] = vexs[i];
	}
	//���ߵĽṹת�Ƶ�ͼ�ı����У�
	for (int i = 0; i < G->vexsNum; i++)
	{
		for (int j = 0; j < G->vexsNum; j++)
		{
			G->arcs[i][j] = arcs[i][j];
			if (G->arcs[i][j] == 1)
			{
				G->arcNum++;//ÿ������һ���ߣ�����������һ��
			}
		}
	}
	G->arcNum /= 2;//��Ϊ������ͼ���������֮�䶥��ֻ��һ���ߣ�
}

//����ͼ����DFS������ȱ���
void DFS(Graph* G, int* visited, int index)
{
	//����һ����п�ʼ������
	printf("%c ", G->vexs[index]);
	//�������������ݣ��ñ���������£�
	visited[index] = 1;
	//���Ҳ�������ýڵ��б���û�б����ʹ��Ľ�㣬�Ըõ㿪ʼ���еݹ��Եķ�����ýڵ��б���û�б����ʹ��Ľ��
	for (int i = 0; i < G->vexsNum; i++)
	{
		if (G->arcs[index][i] == 1 && visited[i] == 0)
		{
			DFS(G, visited, i);
		}
	}
}

