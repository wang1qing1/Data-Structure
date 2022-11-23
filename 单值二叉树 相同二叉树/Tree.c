#include"Tree.h"

BTNode* BuyNode(BTDataType val)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->val = val;
	node->Rchild = node->Lchild = NULL;
	return node;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	PrevOrder(root->Lchild);
	PrevOrder(root->Rchild);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->Lchild);
	printf("%d ", root->val);
	InOrder(root->Rchild);
	
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->Lchild);
	PostOrder(root->Rchild);
	printf("%d ", root->val);

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

//�ڵ���
int SizeNode(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int LSize = SizeNode(root->Lchild) ;
	int RSize = SizeNode(root->Rchild) ;
	return LSize + RSize + 1;
}


//Ҷ����
int SizeLeaf(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->Lchild == NULL && root->Rchild == NULL)
	{
		return 1;
	}
	int LleafSize = SizeLeaf(root->Lchild);
	int RlaefSize = SizeLeaf(root->Rchild);

	return LleafSize + RlaefSize;
}

//���߶�
int HighTree(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int HLTree = HighTree(root->Lchild)+1;
	int HRTree = HighTree(root->Rchild)+1;
	return HLTree > HRTree ? HLTree : HRTree;
}

//k��ڵ���
int KSize(BTNode* root,int k)
{
	if (k == 2)
	{
		return (root->Lchild != NULL) + (root->Rchild != NULL);
	}
	return KSize(root->Lchild,k-1) + KSize(root->Rchild,k-1);
}
//k��ڵ���
int KSize_(BTNode* root, int k)
{
	if (k == 1)
	{
		return root!= NULL;
	}
	return KSize_(root->Lchild, k - 1) + KSize_(root->Rchild, k - 1);
}

//��ֵ������
bool isUnivalTree(BTNode* root) {

	if (root == NULL)
		return true;

	bool L = 0;
	bool R = 0;

	if (root->Lchild == NULL || isUnivalTree(root->Lchild) && root->val == root->Lchild->val)
		L = true;
	else
		L = false;

	if (root->Rchild == NULL || isUnivalTree(root->Rchild) && root->val == root->Rchild->val)
		R = true;
	else
		R = false;

	return L && R;
}

//��ͬ�Ķ�����
bool isSameTree(struct BTNode* p, struct BTNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if ((p == NULL && q != NULL) || q == NULL && p != NULL)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->Lchild, q->Lchild) && isSameTree(p->Rchild, q->Rchild);
}




