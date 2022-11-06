#include"STListNode.h"

SListNode* BuySTLNode(SLTDataType x)
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
void STLPushBank(SListNode** pphead, SLTDataType x)
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
void SLTPushFront(SListNode** pphead, SLTDataType x)
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

//���������
SListNode* SListFind(SListNode* phead, SLTDataType x)
{
	assert(phead);
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return cur;
}

//��������posλ��֮�����x
void SListInserAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySTLNode(x);
	//1.�ȱ���Next���
	/*SListNode* Next = pos->next;
	pos->next = newnode;
	newnode->next = Next;*/

	//2.������������ӣ�������ǰ����
	newnode->next = pos->next;
	pos->next = newnode;

}

//�� pos ǰ��������ݡ�
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x)
{
	assert(pos);
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
		
	}
	else
	{

		SListNode* prev = (* pphead);
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SListNode*newnode = BuySTLNode(x);
		newnode->next = pos;
		prev->next = newnode;
	}

}

//������ɾ��posλ��֮������ݡ�
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return NULL;
	}
	SListNode* posnext = pos->next;
	pos->next = posnext->next;
	free(posnext);
}

//ɾ��posλ�õ�����
void SLTErase(SListNode** pphead, SListNode* pos)
{
	assert(pos);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//���ٵ�����
void SListDestroy(SListNode** pphead)
{
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* curnext = cur->next;
		free(cur);
		cur = curnext;
	}
	*pphead = NULL;
}
