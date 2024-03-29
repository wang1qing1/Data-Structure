#include"List.h"

//初始化头节点
ListNode*InitListNode()
{
	ListNode* Head = (ListNode*)malloc(sizeof(ListNode));
	Head->date = NULL;
	Head->next = Head;
	Head->prev = Head;
	return Head;
}
//新增结点
ListNode* AddNode()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->date = NULL;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//头插结点
void HeadAdd(ListNode* head)
{
	assert(head);
	ListNode* NewNode = AddNode();
	printf("请输入头部插如的数据:>");
	scanf("%d", &(NewNode->date));
	ListNode* frist = head->next;
	NewNode->next = frist;
	frist->prev = NewNode;
	NewNode->prev = head;
	head->next = NewNode;
}

//打印链表
void PrintList(ListNode*head)
{
	assert(head);
	ListNode* frist = head->next;
	while (frist!= head)
	{
		printf("%d->", frist->date);
		frist = frist->next;
	}
	printf("NULL\n");
}

//尾部添加
void TailAdd(ListNode* head)
{
	assert(head);
	ListNode* tail = head->prev;
	ListNode* newnode = AddNode();
	printf("请输入需要尾部添加的数据:>");
	scanf("%d", &(newnode->date));
	newnode->prev = tail;
	newnode->next = head;
	head->prev = newnode;
	tail->next = newnode;
}

ListNode*Find(ListNode* head, INT_TYPE date)
{
	assert(head);
	ListNode* frist=head->next;
	while (frist!=head)
	{
		if (frist->date == date)
		{
			return frist;
		}
		frist = frist->next;
	}
	return NULL;
}

//中间添加数据
void MidAdd(ListNode* head)
{
	assert(head);
	INT_TYPE date;
	printf("请输入需要插入的位置:>");
	scanf("%d" ,&date);
	ListNode*findnode=Find(head, date);
	if (findnode == NULL)
	{
		printf("不存在%dzheg\n", date);
	}
	else
	{
		ListNode* newnode = AddNode();
		printf("请输入插入的数据:>");
		scanf("%d", &newnode->date);
		ListNode* next = findnode->next;
		newnode->next = next;
		newnode->prev = findnode;
		findnode->next = newnode;
		next->prev = newnode;
	}
	
}


void Free(ListNode*p)
{
	free(p);
	p = NULL;
}

//删除指定数据
void DeleteNode(ListNode* head)
{
	assert(head);
	INT_TYPE date;
	printf("请输入需要删除的数据:>");
	scanf("%d", &date);
	ListNode* findnode = Find(head, date);
	if (findnode == NULL)
	{
		printf("没有%d这个数据\n",date);
	}
	else
	{
		ListNode* prev = findnode->prev;
		ListNode* next = findnode->next;
		prev->next = next;
		next->prev = prev;
		Free(findnode);
	}
}

//查找数据
void Seek(ListNode* head)
{
	assert(head);
	INT_TYPE SeekDate;
	printf("请输入需要查找的数据:>");
	scanf("%d", &SeekDate);
	ListNode* findnode = Find(head, SeekDate);
	if (findnode == NULL)
	{
		printf("没有%d这个数据\n", SeekDate);
	}
	else
	{
		printf("找到了，%d\n", SeekDate);
	}
}

//修改数据
void Modify(ListNode* head)
{
	assert(head);
	PrintList(head);
	INT_TYPE ModifyDate;
	printf("请输入需要修改的数据:>");
	scanf("%d", &ModifyDate);
	ListNode* findnode = Find(head, ModifyDate);
	if (findnode == NULL)
	{
		printf("没有%d这个数据\n", ModifyDate);
	}
	else
	{
		printf("请输入修改后的数据:>");
		scanf("%d", &findnode->date);
		printf("修改成功\n");
	}
}

//销毁链表
void Destroy(ListNode* head)
{
	assert(head);
	ListNode* frist = head->next;
	while (frist != head)
	{
		ListNode* next = frist->next;
		free(frist);
		frist = next;
	}
}





