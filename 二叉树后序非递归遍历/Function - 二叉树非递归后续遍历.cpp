#include"TREE.h"

bool JaEmpty(Stact* phead)//ջ�п�
{
	assert(phead);
	return phead->next == phead;
}

void CreatTree(TreeNode** T)//����������
{
	char x;
	scanf("%c", &x);
	if (x == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = x;
		(*T)->sign = 0;
		CreatTree(&(*T)->lchild);
		CreatTree(&(*T)->rchild);
	}
}

void PrevTra(TreeNode* T)//�ݹ�ǰ�����
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PrevTra(T->lchild);
		PrevTra(T->rchild);
	}
}

void InitStact(Stact** pphead)//��ʼ��ջͷ���
{
	*pphead = (Stact*)malloc(sizeof(Stact));
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
	(*pphead)->Data = NULL;
}

void Printf(Stact* phead)//��ӡջ
{
	Stact* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->Data);
		cur = cur->next;
	}
}


void PushStact(Stact* phead, TreeNode* X)//��ջ
{
	Stact* tail = (phead)->prev;
	Stact* newnode = (Stact*)malloc(sizeof(Stact));
	if (newnode == NULL)
	{
		printf("ջ���ӿռ�ʧ�ܣ���");
		exit(-1);
	}
	newnode->Data = X;
	newnode->next = phead;
	newnode->prev = tail;
	tail->next = newnode;
	(phead)->prev = newnode;
}

Stact* GetStactNode(Stact* phead)//��ջ
{
	assert(phead);
	Stact* Retu = (phead)->prev;
	Stact* tail = (phead)->prev;
	Stact* pre_tail = tail->prev;
	pre_tail->next = phead;
	(phead)->prev = pre_tail;
	return Retu;
}

Stact* ReadStactNode(Stact* phead)//��ջ
{
	assert(phead);
	Stact* Retu = (phead)->prev;
	return Retu;
}


void MyAftTRa(Stact* phead, TreeNode* T)//�ǵݹ��������
{
	TreeNode* TR = T;
	while (TR != NULL || !JaEmpty(phead))
	{
		if (TR != NULL)
		{
			PushStact(phead, TR);
			TR->sign = 1;
			TR = TR->lchild;
		}
		else
		{
			TreeNode*top = ReadStactNode(phead)->Data;
			if (top->rchild != NULL&& top->rchild->sign==0)
			{
				TR = top->rchild;
			}
			else
			{
				TreeNode* tr = GetStactNode(phead)->Data;
				printf("%c ", tr->data);
			}
		}
	}
}







