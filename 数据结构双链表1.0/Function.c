#include"List.h"

//��ʼ��ͷ�ڵ�
ListNode*InitListNode()
{
	ListNode* Head = (ListNode*)malloc(sizeof(ListNode));
	Head->date = NULL;
	Head->next = Head;
	Head->prev = Head;
	return Head;
}
//�������
ListNode* AddNode()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->date = NULL;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//ͷ����
void HeadAdd(ListNode* head)
{
	ListNode* NewNode = AddNode();
	printf("������ͷ�����������:>");
	scanf("%d", &(NewNode->date));
	ListNode* frist = head->next;
	NewNode->next = frist;
	frist->prev = NewNode;
	NewNode->prev = head;
	head->next = NewNode;
}

//��ӡ����
void PrintList(ListNode*head)
{
	ListNode* frist = head->next;
	while (frist!= head)
	{
		printf("%d->", frist->date);
		frist = frist->next;
	}
	printf("NULL");
}

//β�����
void TailAdd(ListNode* head)
{
	ListNode* tail = head->prev;
	ListNode* newnode = AddNode();
	printf("��������Ҫβ����ӵ�����:>");
	scanf("%d", &(newnode->date));
	newnode->prev = tail;
	newnode->next = head;
	head->prev = newnode;
	tail->next = newnode;
}

ListNode*Find(ListNode* head, INT_TYPE date)
{
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

//�м��������
void MidAdd(ListNode* head)
{
	INT_TYPE date;
	printf("��������Ҫ�����λ��:>");
	scanf("%d" ,&date);
	ListNode*findnode=Find(head, date);
	ListNode* newnode = AddNode();
	printf("��������������:>");
	scanf("%d", &newnode->date);
	ListNode* next = findnode->next;
	newnode->next = next;
	newnode->prev = findnode;
	findnode->next = newnode;
	next->prev = newnode;
}


void Free(ListNode*p)
{
	free(p);
	p = NULL;
}

//ɾ��ָ������
void DeleteNode(ListNode* head)
{
	INT_TYPE date;
	printf("��������Ҫɾ��������:>");
	scanf("%d", &date);
	ListNode* findnode = Find(head, date);
	ListNode* prev = findnode->prev;
	ListNode* next = findnode->next;
	prev->next = next;
	next->prev = prev;
	Free(findnode);
}

//��������
void Seek(ListNode*head, INT_TYPE date)
{
	INT_TYPE SeekDate;
	printf("��������Ҫ���ҵ�����:>");
	scanf("%d", &SeekDate);
	ListNode* findnode = Find(head, SeekDate);
	printf("�ҵ��ˣ�%d", SeekDate);
}

//�޸�����
void Modify(ListNode* head)
{
	INT_TYPE ModifyDate;
	printf("��������Ҫ�޸ĵ�����:>");
	scanf("%d", &ModifyDate);
	ListNode* findnode = Find(head, ModifyDate);
	printf("�������޸ĺ������:>");
	scanf("%d", &findnode->date);
}

//��������
void destroy(ListNode* head)
{
	ListNode* frist = head->next;
	while (frist != head)
	{
		ListNode* next = frist->next;
		free(frist);
		frist = next;
	}
}





