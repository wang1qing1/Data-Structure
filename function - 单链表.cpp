
#include"SEQ.h"

void SlistPrintf(SlistNode* phead)//打印函数
{
	SlistNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

SlistNode* BuySListNode(SListdataType x)//开辟结点；x 代表存储的数据；
{
	//增加结点的时候，结点是一个结构体，里面有一个结构体类型的指针，和一个数据存储变量，
	//所以申请空间的时候要申请一个节点的大小；
	SlistNode* newNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (newNode == NULL)//判断是否开辟成功；
	{
		printf("开辟失败！");
		exit(-1);
	}
	newNode->data = x;//结点开辟成功后，将待存数据 x，存入data；
	newNode->next = NULL;//新增加的结点也是最后一个结点，需要将节点里面的结构体指针置空；
	return newNode;
}

void SListpushback(SlistNode** pphead, SListdataType x)//尾插结点数据；
{
	SlistNode* newNode = BuySListNode(x);
	if (*pphead == NULL)//如果，*pphead为空，就意味着链表第一个结点就是空；直接增加一个结点
	{
		*pphead = BuySListNode(x);//将新增的节点的地址赋值给*pphead；
	}
	else//如果第一个结点不是空
	{
		SlistNode* tail = *pphead;
		while (tail->next != NULL)//找到最后一个结点；
		{
			tail = tail->next;
		}
		tail->next = newNode;//找到最后一个结点之后,将最后一个结点里面的结构体指针，赋值为新增加的节点的地址；
	}
}

void SListpophback(SlistNode** pphead)//尾删结点；
{
	if (*pphead == NULL)//说明一个结点都没有，无需操作；
	{
		return;
	}
	else if ((*pphead)->next == NULL)//就一个结点，直接把结点的空间地址置空；
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//有多个结点；
	{
		SlistNode* prev = NULL;
		SlistNode* tail = *pphead;
		while (tail->next != NULL)//先找到最后一个结点； 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;//将最后一个结点的地址置空；

	}
}

SlistNode* FindList(SlistNode* phead, SListdataType x)//查找一个结点；
{
	SlistNode* cur = phead;
	while (cur != NULL)
	{
		if ((cur->data) == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SlistInserAfter(SlistNode** pos, SListdataType x)//在pos之后增加一个结点；
{
	assert(*pos);
	SlistNode* newnode = BuySListNode(x);
	newnode->next = (*pos)->next;
	(* pos)->next = newnode;

}

void SlistEraseAfter(SlistNode** pos)//删除pos之后的一个结点；
{
	assert(*pos);
	SlistNode*Next=(*pos)->next;
	(*pos)->next = Next->next;
	free(Next);
	Next = NULL;
}




