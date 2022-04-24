#include"TREE.h"
int main()
{
	TreeNode* T;
	TreeNode* prev = NULL;
	CreateTree(&T);
	/*Print(T);*/
	FroClue(T, &prev);
	prev->rtag = 1;
	prev->rchild = NULL;
	for (TreeNode* cur = T; cur != NULL; cur = GetNext(cur))
	{
		printf("%c ", cur->data);
	}
	return 0;
}