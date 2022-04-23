
#include"SEQ.h"

void SlistPrintf(SlistNode* phead)//��ӡ����
{
	SlistNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

SlistNode* BuySListNode(SListdataType x)//���ٽ�㣻x ����洢�����ݣ�
{
	//���ӽ���ʱ�򣬽����һ���ṹ�壬������һ���ṹ�����͵�ָ�룬��һ�����ݴ洢������
	//��������ռ��ʱ��Ҫ����һ���ڵ�Ĵ�С��
	SlistNode* newNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (newNode == NULL)//�ж��Ƿ񿪱ٳɹ���
	{
		printf("����ʧ�ܣ�");
		exit(-1);
	}
	newNode->data = x;//��㿪�ٳɹ��󣬽��������� x������data��
	newNode->next = NULL;//�����ӵĽ��Ҳ�����һ����㣬��Ҫ���ڵ�����Ľṹ��ָ���ÿգ�
	return newNode;
}

void SListpushback(SlistNode** pphead, SListdataType x)//β�������ݣ�
{
	SlistNode* newNode = BuySListNode(x);
	if (*pphead == NULL)//�����*ppheadΪ�գ�����ζ�������һ�������ǿգ�ֱ������һ�����
	{
		*pphead = BuySListNode(x);//�������Ľڵ�ĵ�ַ��ֵ��*pphead��
	}
	else//�����һ����㲻�ǿ�
	{
		SlistNode* tail = *pphead;
		while (tail->next != NULL)//�ҵ����һ����㣻
		{
			tail = tail->next;
		}
		tail->next = newNode;//�ҵ����һ�����֮��,�����һ���������Ľṹ��ָ�룬��ֵΪ�����ӵĽڵ�ĵ�ַ��
	}
}

void SListpophback(SlistNode** pphead)//βɾ��㣻
{
	if (*pphead == NULL)//˵��һ����㶼û�У����������
	{
		return;
	}
	else if ((*pphead)->next == NULL)//��һ����㣬ֱ�Ӱѽ��Ŀռ��ַ�ÿգ�
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//�ж����㣻
	{
		SlistNode* prev = NULL;
		SlistNode* tail = *pphead;
		while (tail->next != NULL)//���ҵ����һ����㣻 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;//�����һ�����ĵ�ַ�ÿգ�

	}
}

SlistNode* FindList(SlistNode* phead, SListdataType x)//����һ����㣻
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

void SlistInserAfter(SlistNode** pos, SListdataType x)//��pos֮������һ����㣻
{
	assert(*pos);
	SlistNode* newnode = BuySListNode(x);
	newnode->next = (*pos)->next;
	(* pos)->next = newnode;

}

void SlistEraseAfter(SlistNode** pos)//ɾ��pos֮���һ����㣻
{
	assert(*pos);
	SlistNode*Next=(*pos)->next;
	(*pos)->next = Next->next;
	free(Next);
	Next = NULL;
}




