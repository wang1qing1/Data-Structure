#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char BTDataType;

typedef struct BTNode
{
	BTDataType val;
	struct BTNode* Lchild;
	struct BTNode* Rchild;
}BTNode;


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

BTNode* invertTree(BTNode* root) {
    if (root == NULL)
    {
        return NULL;
    }
    BTNode* tmp = root->Lchild = invertTree(root->Lchild);
    root->Lchild = root->Rchild = invertTree(root->Rchild);
    root->Lchild = tmp;
    return root;
}

bool isSymmetric(BTNode* root) {
    if (root == NULL)
    {
        return true;
    }
    root->Rchild = invertTree(root->Rchild);
    return isSameTree(root->Lchild, root->Rchild);
}

int main()
{
	BTNode* root = CreatTree();


	return 0;
}