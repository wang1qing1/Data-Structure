#include"TREE.h"
int main()
{
	TreeNode* T = NULL;
	int arr[] = { 2,6,1,45,21,65,84,120,62,3,54 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		SortTree(&T, arr[i]);
	}
	MidClue(T);


	return 0;
}