#include"STListNode.h"

SListNode* BuySTLNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("newnode malloc");
	}
	else
	{
		newnode->date = x;
		newnode->next = NULL;
	}
	return newnode;
}

SListNode* CreateSList(n)
{
	SListNode* phead = NULL;
	SListNode* tail = NULL;
	for (int i = 0; i < n; i++)
	{
		SListNode* newnode = BuySTLNode(i);
		if (phead == NULL)
		{
			phead = newnode;
			tail = phead;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
	return phead;
}

void PrintList(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL");
}


//β��
void STLPushBank(SListNode** pphead, SLTDateType x)
{

	SListNode* newnode = BuySTLNode(x);
	//����տ��������ǿյģ�Ҳ�ͱ�ĵ�һ�����ǿ�(NULL)
	//��ʱ����Ҫ���ǰ��´����Ľ���������µĽ��
	//����Ҫ�ı����ǵ�ͷ����ָ�룬����ָ�����ǵ��µĽ�㡣
	//���µ������ݵĽ�㣬��Ϊ�µ�ͷ���
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//βɾ
void STLPopBank(SListNode**pphead)
{
	assert(*pphead);
	SListNode* tail = *pphead;
	SListNode* prev_tail = NULL;
	while (tail->next)
	{
		prev_tail = tail;
		tail = tail->next;
	}
	if ((*pphead)->next == NULL)
	{
		free(tail);
		*pphead = NULL;
	}
	else
	{
		free(tail);
		prev_tail->next = NULL;
	}
}

//ͷ��
void SLTPushFront(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySTLNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//ͷɾ
void SLTPopFront(SListNode** pphead)
{
	assert(*pphead);
	SListNode* nextnode = (*pphead)->next;
	free(*pphead);
	*pphead = nextnode;
}