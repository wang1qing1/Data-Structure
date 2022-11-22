#include"Tree.h"
int main()
{
	BTNode*root=CreatTree();
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");

	printf("NodeSize:%d\n", SizeNode(root));
	printf("LeafSize:%d\n", SizeLeaf(root));
	printf("HighTree:%d\n", HighTree(root));
	printf("KSize:%d\n", KSize_(root,2));
	return 0;
}