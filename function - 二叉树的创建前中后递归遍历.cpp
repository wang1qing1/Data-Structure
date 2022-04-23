#include"TREE.h"

void CreaTree(TreeNode** T)//���Ĵ���
{
	char a;
	scanf("%c", &a);
	if (a == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = a;
		CreaTree( & (*T)->lchild);
		CreaTree( & (*T)->rchild);
	}
}

void PrevPriTree(TreeNode*T)//ǰ�����
{
	if (T==NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PrevPriTree(T->lchild);
		PrevPriTree(T->rchild);
	}
}
void MidPriTree(TreeNode* T)//�������
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		MidPriTree(T->lchild);
		printf("%c ", T->data);
		MidPriTree(T->rchild);
	}
}

void AftPriTree(TreeNode* T)//�������
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		AftPriTree(T->lchild);
		AftPriTree(T->rchild);
		printf("%c ", T->data);
	}
}