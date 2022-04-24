#include"TREE.h"
int main()
{
	TreeNode* T;
	CreaTree(&T);
	PrevPriTree(T);
	printf("\n");
	MidPriTree(T);
	printf("\n");
	AftPriTree(T);
	return 0;
}