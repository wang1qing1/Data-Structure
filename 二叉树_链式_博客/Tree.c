#include"Tree.h"


BTNode* BTNodeCreat(int val)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->val = val;
	node->right = node->left = NULL;
	return node;
}

//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//节点数
int SizeNode(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int Lsize = SizeNode(root->left);
	int Rsize = SizeNode(root->right);
	return Lsize + Rsize + 1;
}

//叶子数
int LeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	int LLeafsize = LeafSize(root->left);
	int RLeafsize = LeafSize(root->right);
	return LLeafsize + RLeafsize;
}

//查找节点
BTNode* FindNode(BTNode* root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == x)
	{
		return root;
	}
	BTNode* Lfind = FindNode(root->left, x);
	if (Lfind)
	{
		return Lfind;
	}
	BTNode* Rfind = FindNode(root->right, x);
	if (Rfind)
	{
		return Rfind;
	}
	return NULL;
}
