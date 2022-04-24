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

void MidClue(TreeNode* T, TreeNode** prev)
{
	if (T)
	{
		MidClue(T->lchild, prev);
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = *prev;
		}
		if (*prev != NULL && (*prev)->rchild == NULL)
		{
			(*prev)->rtag = 1;
			(*prev)->rchild = T;
		}
		*prev = T;
		MidClue(T->rchild, prev);
	}
}

TreeNode* GetFrist(TreeNode* node)
{
	while (node->ltag != 1)
	{
		node = node->lchild;
	}
	return node;
}

TreeNode* GetNext(TreeNode* node)
{
	if (node->rtag == 1)
	{
		return node->rchild;
	}
	else
	{
		return GetFrist(node->rchild);
	}
}

