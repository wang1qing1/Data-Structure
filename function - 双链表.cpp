#include"SEQ.h"

void ListPrintf(ListNode* phead)//打印
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

ListNode* BuyListNode(SListdataType x)//结点创建
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListInit(ListNode **pphead)//初始化phead
{
	*pphead = BuyListNode(0);
	(* pphead)->next = *pphead;
	(* pphead)->prev = *pphead;
}

void ListPushBank(ListNode* phead, SListdataType x)//尾增结点
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead;
	phead->prev = newnode;
	newnode->prev = tail;
	tail->next = newnode;
}

void ListPopBank(ListNode* phead)//尾删
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* tail_prev = tail->prev;
	tail_prev->next = phead;
	phead->prev = tail_prev;
	free(tail);
	tail = NULL;
}

void ListPushFront(ListNode* phead, SListdataType x)//头插
{
	assert(phead);
	ListNode* frist = phead->next;
	ListNode* newnode = BuyListNode(x);
	newnode->next = frist;
	frist->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;
}

void ListPopFront(ListNode* phead)//头删
{
	assert(phead);
	ListNode* frist = phead->next;
	ListNode* second = frist->next;
	phead->next = second;
	second->prev = phead;
	free(frist);
	frist = NULL;
}

ListNode* ListFind(ListNode*phead, SListdataType x)//查询
{
	ListNode* cur = phead->next;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListPopPos(ListNode* pos)//删除pos结点
{
	assert(pos);
	ListNode* posnext = pos->next;
	ListNode* posprev = pos->prev;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
	pos = NULL;
}

void ListPushPosAfter(ListNode* pos, SListdataType x)//pos之后增加结点
{
	assert(pos);
	ListNode* posnext = pos->next;
	ListNode* newnode = BuyListNode(x);
	newnode->next = posnext;
	posnext->prev = newnode;
	newnode->prev = pos;
	pos->next = newnode;
}

void ListDestroy(ListNode*phead)//销毁链表，除头节点
{
	ListNode* cur = phead->next;
	while (cur!=phead)
	{
		ListNode* curnext = cur->next;
		free(cur);
		cur = curnext;
	}
	phead->prev = phead;
	phead->next = phead;
}

void ListDestroyAll(ListNode* phead)//删除所有结点，包括头结点
{
	assert(phead);
	ListDestroy(phead);
	free(phead);
	phead = NULL;
}
