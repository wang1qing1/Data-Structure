#include"TREE.h"

void CreateTree(TreeNode** T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		CreateTree(&(*T)->lchild);
		CreateTree(&(*T)->rchild);
	}
}  

//void Print(TreeNode* T)
//{
//	if (T!= NULL)
//	{
//		printf("%c ", T->data);
//		Print(T->lchild);
//		Print(T->rchild);
//	}
//}

void FroClue(TreeNode* T, TreeNode** prev)
{
	if (T != NULL)
	{
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = *prev;
		}
		if ((*prev)!=NULL&&(*prev)->rchild == NULL)
		{
			(*prev)->rtag = 1;
			(*prev)->rchild = T;
		}
		(*prev) = T;
		if (T->ltag==0)
		{
			FroClue(T->lchild, prev);
		}
		FroClue(T->rchild, prev);
	}
}

TreeNode* GetNext(TreeNode* node)
{
	if (node->rtag == 1||node->ltag==1)
	{
		return node->rchild;
	}
	else
	{
		return node->lchild;
	}
}
