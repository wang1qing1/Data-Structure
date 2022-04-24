#include"TREE.h"

int main()
{
	TreeNode* tree;
	Stact* St;
	InitStact(&St);
	CreatTree(&tree);
	MyPreTra(St, tree);
	printf("\n");
	MyMidTra(St, tree);
	
	return 0;
}