#include"TREE.h"

void SortTree(TreeNode** T, int data)
{
	if (*T == NULL)//只有找到空位置我们才能插入；
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));//为这个我们准被插入的结点开辟空间，
		(*T)->data = data;//数据转移
		(*T)->lchild = NULL;//新插入的结点一定是一个叶子节点，所以左右子树都需要为NULL；
		(*T)->rchild = NULL;
	}
	else if (data < (*T)->data)//将传入的值与树中存储的值进行比较，如果比该节点小，
							   //就往他的左子树继续寻找；
	{
		SortTree(&(*T)->lchild, data);
	}
	else if (data == (*T)->data)//因为二叉排序树无法处理相同的值，所以当传入的值与该节点的值相等，
								//我们就不做处理；
	{
		return;
	}
	else//如果比该节点的值大，我们就往该节点的右子树寻找，
	{
		SortTree(&(*T)->rchild, data);
	}
	//这样递归性的寻找，传入的值比该节点的值小就往还结点的左子树寻找，
	//相等不做处理，传入的值比该节点的值大就往该节点的右子树寻找，直到找到最后，
	//某一个结点的左子树或者右子树为空，这个空位置就是我们传入的值准备放的位置，
}

TreeNode* SeaTree(TreeNode* T, int key)
{
	if (key == T->data)
	{
		return T;
	}
	else if(key < T->data)
	{
		SeaTree(T->lchild, key);
	}
	else
	{
		SeaTree(T->lchild, key);
	}
}

void MidClue(TreeNode*T)//中序遍历
{
	if (T)
	{
		MidClue(T->lchild);
		printf("%d ", T->data);
		MidClue(T->rchild);
	}
}

 