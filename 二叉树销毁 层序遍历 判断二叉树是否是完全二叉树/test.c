#include"Tree.h"
#include"Queue.h"
int main()
{
	BTNode* root = CreatTree();
	FloorOrder(root);
	bool tmp=BinaryTreeComplete(root);
	if (tmp)
	{
		printf("the binaryTree is Complete\n");
	}
	else
	{
		printf("the binaryTree is not Complete\n");
	}
    BinaryTreeDestory(root);
	return 0;
}

