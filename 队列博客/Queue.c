#include"Queue.h"

void QueueInit(Queue* pque)
{
	assert(pque);
	pque->head = NULL;
	pque->tail = NULL;
	pque->size = 0; //记录队列中数据个数
}

void QueuePush(Queue* pque,QUDateType x)
{
	//断言队列结构，当进行入队操作时，队列结构一定不能为空
	assert(pque);
	//申请空间
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//赋值
	newnode->date = x;
	newnode->next = NULL;
	//如果队列为空，此时入队的就是第一个数据，也将是队列的头尾数据
	if (pque->head == NULL)
	{
		pque->head = pque->tail = newnode;
	}
	//如果队列不为空，就将数据连接到队尾巴后面
	else
	{
		pque->tail->next = newnode;
		pque->tail = newnode;
	}
	//队列中数据个数加一
	pque->size++;
}

bool QueueEmpty(Queue* pque)
{
	assert(pque);

	return pque->head == NULL && pque->tail == NULL;
}

QUDateType QueueFront(Queue*pque)
{
	assert(pque);
	assert(!QueueEmpty(pque));
	return pque->head->date;
}

QUDateType QueueBack(Queue* pque)
{
	assert(pque);
	assert(!QueueEmpty(pque));
	return pque->tail->date;
}

int QueueSize(Queue* pque)
{
	assert(pque);
	return pque->size;
}

void QueuePop(Queue* pque)
{
	assert(pque);   //队列结构不能为空
	assert(!QueueEmpty(pque));   //删除数据时队列不能为空 
	//队列中只有一个数据的时候
	if (pque->head->next == NULL)
	{
		free(pque->head);
		pque->tail = pque->head = NULL;
	}
	//队列中数据个数大于1
	else
	{
		QueueNode* popnode = pque->head;
		pque->head = pque->head->next;
		free(popnode);
	}
	//数据个数减一
	pque->size--;
}


void QueueDestroy(Queue* pque)
{
	assert(pque);
	QueueNode* cur = pque->head;
	while (cur)
	{
		QueueNode* nextnode = cur->next;
		free(cur);
		cur = nextnode;
	}
	pque->head = pque->tail = NULL;
}

