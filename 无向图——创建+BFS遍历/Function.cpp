#include"GRAPH.h"

//初始化队列
Queue* InitQueue()
{
	Queue* head = (Queue*)malloc(sizeof(Queue));
	head->data = NULL;
	head->next = head;
	head->prev = head;
	return head;
}

//结点的创建
Queue* NewNode(int data)
{
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//插入数据结点
void InserNode(Queue*head,int data)
{
	Queue* newnode = NewNode(data);
	Queue* tail = head->prev;
	newnode->prev = tail;
	newnode->next = head;
	tail->next = newnode;
	head->prev = newnode;
}

//得到数据
int GetQueue(Queue* head)
{
	Queue* frist = head->next;
	Queue* second = frist->next;
	int data = frist->data;
	head->next = second;
	second->prev = head;
	return data;
}

//初始化图
Graph* InitGraph( int vexsNum)
{
	Graph*G = (Graph*)malloc(sizeof(Graph));//创建图的框架
	G->vexs = (char*)malloc(sizeof(char) * vexsNum);//开辟图的数据域空间
	G->arcs = (int**)malloc(sizeof(int*)*vexsNum);//开辟图的边域空间
	for (int i = 0; i < vexsNum; i++)
	{
		G->arcs[i] = (int*)malloc(sizeof(int)*vexsNum);//开辟图边域空间
	}
	G->vexsNum = vexsNum;//数据个数
	G->arcNum = 0;//边数——为初始数据时为零；
	return G;
}

//创建图
void CreateGraph(Graph* G, char* vexs,int arcs[5][5])
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
			G->arcs[i][j] = arcs [i][j];
			if (G->arcs[i][j] == 1)
			{
				G->arcNum++;//每次增加一个边，变数就增加一；
			}
		}
	}
	G->arcNum /= 2;//因为是无向图，两个结点之间顶多只有一条边；
}

//广度优先遍历
void BFS(Graph* G,int* visited,int index )
{
	Queue* head = InitQueue();
    //进队列的同时访问；
	InserNode(head, index);
	printf("%c ", G->vexs[index]);
	//将遍历过的数据，用标记数组标记下；
	visited[index] = 1;
	//当栈空时，结束遍历
	while (head->next != head)
	{
		//出队列的同时，将与该节点有边且没有被访问过的结点进队列
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




