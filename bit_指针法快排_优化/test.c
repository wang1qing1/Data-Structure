#include"QSort.h"

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
		arr[i] = rand()%1000 ;
	}
	//int arr[] = { 2,1,5,6,9,8,7,4,3 };
	int n = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, n - 1);
	//InsertSort(arr, n);
	Print(arr, n);

}