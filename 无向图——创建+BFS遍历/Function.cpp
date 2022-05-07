#include"GRAPH.h"

//��ʼ������
Queue* InitQueue()
{
	Queue* head = (Queue*)malloc(sizeof(Queue));
	head->data = NULL;
	head->next = head;
	head->prev = head;
	return head;
}

//���Ĵ���
Queue* NewNode(int data)
{
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//�������ݽ��
void InserNode(Queue*head,int data)
{
	Queue* newnode = NewNode(data);
	Queue* tail = head->prev;
	newnode->prev = tail;
	newnode->next = head;
	tail->next = newnode;
	head->prev = newnode;
}

//�õ�����
int GetQueue(Queue* head)
{
	Queue* frist = head->next;
	Queue* second = frist->next;
	int data = frist->data;
	head->next = second;
	second->prev = head;
	return data;
}

//��ʼ��ͼ
Graph* InitGraph( int vexsNum)
{
	Graph*G = (Graph*)malloc(sizeof(Graph));//����ͼ�Ŀ��
	G->vexs = (char*)malloc(sizeof(char) * vexsNum);//����ͼ��������ռ�
	G->arcs = (int**)malloc(sizeof(int*)*vexsNum);//����ͼ�ı���ռ�
	for (int i = 0; i < vexsNum; i++)
	{
		G->arcs[i] = (int*)malloc(sizeof(int)*vexsNum);//����ͼ����ռ�
	}
	G->vexsNum = vexsNum;//���ݸ���
	G->arcNum = 0;//��������Ϊ��ʼ����ʱΪ�㣻
	return G;
}

//����ͼ
void CreateGraph(Graph* G, char* vexs,int arcs[5][5])
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
			G->arcs[i][j] = arcs [i][j];
			if (G->arcs[i][j] == 1)
			{
				G->arcNum++;//ÿ������һ���ߣ�����������һ��
			}
		}
	}
	G->arcNum /= 2;//��Ϊ������ͼ���������֮�䶥��ֻ��һ���ߣ�
}

//������ȱ���
void BFS(Graph* G,int* visited,int index )
{
	Queue* head = InitQueue();
    //�����е�ͬʱ���ʣ�
	InserNode(head, index);
	printf("%c ", G->vexs[index]);
	//�������������ݣ��ñ���������£�
	visited[index] = 1;
	//��ջ��ʱ����������
	while (head->next != head)
	{
		//�����е�ͬʱ������ýڵ��б���û�б����ʹ��Ľ�������
		int i = GetQueue(head);
		for (int j = 0; j < G->vexsNum; j++)
		{
			if (G->arcs[i][j] == 1 && visited[j] == 0)
			{
				printf("%c ", G->vexs[j]);
				visited[j] = 1;
				InserNode(head, j);
			}
		}
	}
}




