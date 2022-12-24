
#include"Queue.h"


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
//第K层节点数
int BTKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	int LKsize = BTKSize(root->left, k - 1);
	int RKsize = BTKSize(root->right, k - 1);
	return LKsize + RKsize;
}

//最大深度
int BTdeep(BTNode*root)
{
	if (root == NULL)
	{
		return 0;
	}
	int Ldeep = BTdeep(root->left);
	int Rdeep = BTdeep(root->right);
	return (Ldeep > Rdeep? Ldeep : Rdeep) + 1;
}

//单值二叉树
bool isUnivalTree(struct TreeNode* root) 
{
	if (root == NULL)
	{
		return true;
	}

	if (root->left && root->val != root->left->val)
	{
		return false;
	}
	if (root->right && root->val != root->right->val)
	{
		return false;
	}
	return isUnivalTree(root->right) && isUnivalTree(root->left);
}

//判断两个二叉树相等
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//反转二叉树
struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return NULL;
	}
	struct TreeNode* Right = invertTree(root->right);
	struct TreeNode* Left = invertTree(root->left);
	root->left = Right;
	root->right = Left;
	return root;
}

//层序遍历
void LevelOrder(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q,root);
	while (!QueueEmpty(&Q))
	{
		int n = QueueSize(&Q);
		while (n--)
		{
			BTNode* tmp = QueueFront(&Q);
			QueuePop(&Q);
			printf("%d ", tmp->val);
			if (tmp->left)
			{
				QueuePush(&Q, tmp->left);
			}
			if (tmp->right)
			{
				QueuePush(&Q, tmp->right);
			}
		}
		printf("\n");
		
	}

	QueueDestroy(&Q);

}