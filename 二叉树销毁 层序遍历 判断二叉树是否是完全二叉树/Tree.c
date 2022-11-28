#include"Tree.h"
#include"Queue.h"

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
	n4->Lchild = n8;

	return n1;
}

//判断二叉树相同
bool isSameTree(BTNode* p, BTNode* q)
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
	return isSameTree(p->Lchild, q->Lchild) && isSameTree(p->Rchild, q->Lchild);
}

//反转二叉树  
BTNode* invertTree(BTNode* root) 
{
	if (root == NULL)
	{
		return NULL;
	}
	BTNode* tmp = root->Lchild = invertTree(root->Lchild);
	root->Lchild = root->Rchild = invertTree(root->Rchild);
	root->Lchild = tmp;
	return root;
}

//对称二叉树
bool isSymmetric(BTNode* root) 
{
	if (root == NULL)
	{
		return true;
	}
	root->Rchild = invertTree(root->Rchild);
	return isSameTree(root->Lchild, root->Rchild);
}


//对称二叉树
bool _isSymmetric(BTNode* Lroot, BTNode* Rroot)
{
	if (Lroot == NULL && Rroot == NULL)
	{
		return true;
	}
	if (Lroot == NULL || Rroot == NULL)
	{
		return false;
	}
	if (Lroot->val != Rroot->val)
	{
		return false;
	}
	return _isSymmetric(Lroot->Lchild, Rroot->Rchild) && _isSymmetric(Lroot->Rchild, Rroot->Lchild);
}

bool IsSymmetric(BTNode* root) 
{
	if (root == NULL)
	{
		return true;
	}
	return _isSymmetric(root->Lchild, root->Rchild);
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->Lchild);
	BinaryTreeDestory(root->Rchild);
	free(root);
}

//层序遍历
void FloorOrder(BTNode*root)
{
	Queue Q;
	QueueInit(&Q);
	if (root)
		QueuePush(&Q, root);
	while (!QueueEmpty(&Q))
	{
		BTNode* tmp = QueueFront(&Q);
		printf("%d ", tmp->val);
		QueuePop(&Q);
		if (tmp->Lchild)
			QueuePush(&Q, tmp->Lchild);
		if (tmp->Rchild)
			QueuePush(&Q, tmp->Rchild);
	}
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue Q;
	QueueInit(&Q);
	if (root)
		QueuePush(&Q, root);
	while (!QueueEmpty(&Q))
	{
		BTNode* tmp = QueueFront(&Q);
		QueuePop(&Q);
		if (tmp == NULL)
		{
			break;
		}				
		QueuePush(&Q, tmp->Lchild);
		QueuePush(&Q, tmp->Rchild);
	}
	while (!QueueEmpty(&Q))
	{
		BTNode* tmp = QueueFront(&Q);
		QueuePop(&Q);
		if (tmp)
		{
			return false;
		}
	}
	return true;
}