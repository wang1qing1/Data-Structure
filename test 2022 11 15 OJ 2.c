#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//队列结构

typedef int QUDateType;
typedef struct QueueNode
{
	QUDateType date;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pque)
{
	assert(pque);
	pque->head = NULL;
	pque->tail = NULL;
	pque->size = 0;
}

void QueuePush(Queue* pque, QUDateType x)
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

QUDateType QueueFront(Queue* pque)
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


//封装两个队列
typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

//创建栈
MyStack* myStackCreate() {
	MyStack* Q = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&Q->q1);
	QueueInit(&Q->q2);
	return Q;
}

//将元素 x 压入栈顶。
void myStackPush(MyStack* obj, int x) {
	//找到空队列与非空队列
	QueueNode* empty = &obj->q1;
	QueueNode* noempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		noempty = &obj->q1;
	}
	//将数据入空队列
	QueuePush(noempty, x);
}

int myStackPop(MyStack* obj) {
	assert(obj);
	//找到空队列与非空队列
	QueueNode* empty = &obj->q1;
	QueueNode* noempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		noempty = &obj->q1;
	}
	//将非空队列只留一个数据，其他的全部出队到空队列
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	//返回非空队列的最后一个数据
	int ret = QueueFront(noempty);
	QueuePop(noempty);
	return ret;
}

int myStackTop(MyStack* obj) {
	assert(obj);
	QueueNode* empty = &obj->q1;
	QueueNode* noempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		noempty = &obj->q1;
	}
	return QueueBack(noempty);
}

bool myStackEmpty(MyStack* obj) {
	assert(obj);
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	assert(obj);
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}


int main()
{



	return 0;
}