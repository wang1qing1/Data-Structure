#include"TREE.h"
int main()
{
	TreeNode* T;
	TreeNode* prev = NULL;
	CreateTree(&T,NULL);
	AfteClue(T,&prev);
	for (TreeNode* node = GetFrist(T); node != NULL; node = GetNext(node))
	{
		printf("%c ", node->data);
	}

	return 0;
}