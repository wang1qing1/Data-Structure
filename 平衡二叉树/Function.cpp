#include"AVL.h"

TreeNode* newNode(int key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = key;
	node->height = 1;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

int Getheight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int GetBalance(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return Getheight(root->lchild) - Getheight(root->rchild);
}

void LL_Rotate(TreeNode** root)
{
	TreeNode* child = (*root)->lchild;
	(*root)->lchild = child->rchild;
	child->rchild = *root;

	child->height = max(Getheight(child->lchild), Getheight(child->rchild)) + 1;
	(*root)->height = max(Getheight((*root)->lchild), Getheight((*root)->rchild)) + 1;

	*root = child;
}

void RR_Rotate(TreeNode** root)
{
	TreeNode* child = (*root)->rchild;
	(*root)->rchild = child->lchild;
	child->lchild = *root;

	child->height = max(Getheight(child->lchild), Getheight(child->rchild)) + 1;
	(*root)->height = max(Getheight((*root)->lchild), Getheight((*root)->rchild)) + 1;

	*root = child;
} 


void InserAVL(TreeNode** root,int key)
{
	if (*root == NULL)
	{
		*root = newNode(key);
	}

	if (key > (*root)->data)
	{
		InserAVL(&(*root)->rchild, key);
	}
	else if (key < (*root)->data)
	{
		InserAVL(&(*root)->lchild, key);
	}
	else 
	{
		return;
	}

	(*root)->height = max(Getheight((*root)->lchild), Getheight((*root)->rchild)) + 1;

	int balance = GetBalance(*root);

	if (balance > 1 && key < (*root)->lchild->data)//LL
	{
		LL_Rotate(root);
	}

	if (balance < -1 && key >(*root)->rchild->data )//RR
	{
		RR_Rotate(root);
	}

	if (balance > 1 && key > (*root)->lchild->data)//LR
	{
		//TreeNode* child = (*root)->lchild;
		RR_Rotate(&(*root)->lchild);
		LL_Rotate(root);
	}

	if (balance < -1 && key < (*root)->rchild->data)//RL
	{
		//TreeNode* child = (*root)->rchild;
		LL_Rotate(&(*root)->rchild);
		RR_Rotate(root);
	}
}

void PrevClue(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", root->data);
		PrevClue(root->lchild);
		PrevClue(root->rchild);
	}
}