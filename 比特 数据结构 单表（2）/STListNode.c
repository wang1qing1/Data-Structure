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


//尾插
void STLPushBank(SListNode** pphead, SLTDateType x)
{

	SListNode* newnode = BuySTLNode(x);
	//如果刚开单链表是空的，也就表的第一个就是空(NULL)
	//此时就需要我们把新创建的结点变成我们新的结点
	//就需要改变我们的头结点的指针，让他指向我们的新的结点。
	//让新的有数据的结点，作为新的头结点
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

//尾删
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

//头插
void SLTPushFront(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySTLNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//头删
void SLTPopFront(SListNode** pphead)
{
	assert(*pphead);
	SListNode* nextnode = (*pphead)->next;
	free(*pphead);
	*pphead = nextnode;
}

//单链表查找
SListNode* SListFind(SListNode* phead, SLTDateType x)
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

//单链表在pos位置之后插入x
void SListInserAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySTLNode(x);
	//1.先保存Next结点
	/*SListNode* Next = pos->next;
	pos->next = newnode;
	newnode->next = Next;*/

	//2.先与后面结点连接，在连接前面结点
	newnode->next = pos->next;
	pos->next = newnode;

}

//单链表删除pos位置之后的数据。
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* posnext = pos->next;
	pos->next = posnext->next;
}

//销毁单链表
void SListDestroy(SListNode* phead)
{
	assert(phead);
	SListNode* Next = phead->next;
	while (phead)
	{
		free(phead);
		phead = Next;
		if (Next!=NULL)
		{
			Next = Next->next;
		}
	}
}
