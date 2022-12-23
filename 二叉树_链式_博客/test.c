#include"Tree.h"

int main()
{
	BTNode* n1 = BTNodeCreat(1);
	BTNode* n2 = BTNodeCreat(2);
	BTNode* n3 = BTNodeCreat(3);
	BTNode* n4 = BTNodeCreat(4);
	BTNode* n5 = BTNodeCreat(5);
	BTNode* n6 = BTNodeCreat(6);
	BTNode* n7 = BTNodeCreat(7);
	n1->right = n3;
	n1->left = n2;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	/*PrevOrder(n1);
	printf("nodesize=%d \n", SizeNode(n1));
	printf("LeafSize=%d \n", LeafSize(n1));*/
	BTNode* findnode = FindNode(n1, 8);
	if (findnode)
	{
		printf("%d \n", findnode->val);
	}
	else
	{
		printf("no find\n");
	}

	return 0;
}