#define _CRT_SECURE_NO_WARNINGS 1
#include"SBT.h"
int main()
{
	SerchBinaryTree<int> root;
	int arr[7] = { 8,4,10,3,5,9,12 };
	for (int i = 0; i < 7; i++)
	{
		root.Insert(arr[i]);
	}
	root.MidOrder();
	return 0;
}