#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stact.h"
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[100];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1000;
	}
	//int arr[] = { 2,3,5,6,3,8,7,4,3 ,3,3};
	//int arr[] = { 2,3,5,4,6,7,8,9,1 };
	int n = sizeof(arr)/sizeof(int);
	MergeSort(arr, n );
	//InsertSort(arr, n);
	Print(arr, n);
}