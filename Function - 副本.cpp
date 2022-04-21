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
	while (cur!=phead)
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

void MyMidTra(Stact* phead, TreeNode* T)//�ǵݹ��������
{
	TreeNode* TR = T;
	while (TR!=NULL||!JaEmpty(phead))
	{
		if(TR)
		{
			PushStact(phead, TR);
			TR = TR->lchild;
		}
		else
		{
			TreeNode*Snode = GetStactNode(phead)->Data;
			printf("%c ", Snode->data);
			TR = Snode->rchild;
		}
	}
	
}

void MyPreTra(Stact* phead, TreeNode* T)//�ǵݹ�ǰ�����
{
	TreeNode* TR = T;
	while (TR != NULL || !JaEmpty(phead))
	{
		if (TR)
		{
			PushStact(phead, TR);
			printf("%c ", TR->data);
			TR = TR->lchild;
		}
		else
		{
			TreeNode* Snode = GetStactNode(phead)->Data;
			TR = Snode->rchild;
		}
	}

}







