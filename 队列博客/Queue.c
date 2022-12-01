#include"Queue.h"

void QueueInit(Queue* pque)
{
	assert(pque);
	pque->head = NULL;
	pque->tail = NULL;
	pque->size = 0; //��¼���������ݸ���
}

void QueuePush(Queue* pque,QUDateType x)
{
	//���Զ��нṹ����������Ӳ���ʱ�����нṹһ������Ϊ��
	assert(pque);
	//����ռ�
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//��ֵ
	newnode->date = x;
	newnode->next = NULL;
	//�������Ϊ�գ���ʱ��ӵľ��ǵ�һ�����ݣ�Ҳ���Ƕ��е�ͷβ����
	if (pque->head == NULL)
	{
		pque->head = pque->tail = newnode;
	}
	//������в�Ϊ�գ��ͽ��������ӵ���β�ͺ���
	else
	{
		pque->tail->next = newnode;
		pque->tail = newnode;
	}
	//���������ݸ�����һ
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
	assert(pque);   //���нṹ����Ϊ��
	assert(!QueueEmpty(pque));   //ɾ������ʱ���в���Ϊ�� 
	//������ֻ��һ�����ݵ�ʱ��
	if (pque->head->next == NULL)
	{
		free(pque->head);
		pque->tail = pque->head = NULL;
	}
	//���������ݸ�������1
	else
	{
		QueueNode* popnode = pque->head;
		pque->head = pque->head->next;
		free(popnode);
	}
	//���ݸ�����һ
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

