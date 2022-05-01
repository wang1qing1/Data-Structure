#include"AVL.h"
int main()
{
	TreeNode* root = NULL;
	
	int arr[] = {7,5,6,3,8,9 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		InserAVL(&root, arr[i]);
	}
	PrevClue(root);
	return 0;
}