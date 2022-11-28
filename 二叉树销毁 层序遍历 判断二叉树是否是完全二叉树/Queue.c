#include"Queue.h"

void QueueInit(Queue* pque)
{
	assert(pque);
	pque->head = NULL;
	pque->tail = NULL;
	pque->size = 0;
}

void QueuePush(Queue* pque,QUDateType x)
{
	assert(pque);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;
	if (pque->head == NULL)
	{
		pque->head = pque->tail = newnode;
	}
	else
	{
		pque->tail->next = newnode;
		pque->tail = newnode;
	}
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
	assert(pque);
	assert(!QueueEmpty(pque));
	//队列中只有一个数据的时候
	if (pque->head->next == NULL)
	{
		free(pque->head);
		pque->tail = pque->head = NULL;
	}
	else
	{
		QueueNode* popnode = pque->head;
		pque->head = pque->head->next;
		free(popnode);
	}
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

