#include"HeapSort.h"

int test1()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

int main()
{
	test1();


	return 0;
}