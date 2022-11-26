#include"Tree.h"

BTNode* BuyNode(BTDataType val)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->val = val;
	node->Rchild = node->Lchild = NULL;
	return node;
}

BTNode* CreatTree()
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);
	BTNode* n7 = BuyNode(7);
	BTNode* n8 = BuyNode(8);

	n1->Lchild = n2;
	n1->Rchild = n3;
	n2->Lchild = n4;
	n2->Rchild = n5;
	n3->Lchild = n6;
	n3->Rchild = n7;
	n5->Lchild = n8;

	return n1;
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	BTNode* Lfind = BinaryTreeFind(root->Lchild, x);
	if (Lfind)
	{
		return Lfind;
	}
	BTNode* Rfind = BinaryTreeFind(root->Rchild, x);
	if (Rfind)
	{
		return Rfind;
	}
	return NULL;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	if (*(a+(*pi)) == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	root->val = *(a + (*pi)++);
	root->Lchild = BinaryTreeCreate(a, pi);
	root->Rchild = BinaryTreeCreate(a, pi);
	return root;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	
	PrevOrder(root->Lchild);
	printf("%c ", root->val);
	PrevOrder(root->Rchild);
}