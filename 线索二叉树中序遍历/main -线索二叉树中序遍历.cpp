#include"TREE.h"
int main()
{
	TreeNode* T;
	TreeNode* prev=NULL;
	CreateTree(&T);
	MidClue(T, &prev);
	prev->rtag = 1;
	prev->rchild = NULL;
	for (TreeNode* Tree = GetFrist(T); Tree != NULL; Tree = GetNext(Tree))
	{
		printf("%c ", Tree->data);
	}
	return 0;

}