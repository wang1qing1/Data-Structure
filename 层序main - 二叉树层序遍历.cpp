#include"TREE.h"
int main()
{
	TreeNode* tree;
	QueueNode* phead;
	InitQueue(&phead);
	CreatTree(&tree);
	/*PrevPrinTree(tree);*/
	LayerSequence(tree, phead);
	return 0;
}