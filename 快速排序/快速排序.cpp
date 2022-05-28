#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Print(int* arr,int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int partition(int* arr, int i, int j)
{
	int x = arr[i];
	while (i < j)
	{
		while (arr[j] > x && i < j)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (arr[i] < x && i < j)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = x;
	return i;
}

void QuickSort(int* arr, int i, int j)
{
	if (i < j)
	{
		int index=partition(arr, i, j);
		QuickSort(arr, i, index - 1);
		QuickSort(arr, index + 1, j);
	}
}

int main(){

	int arr[] = { 12,54,65,98,65,35,62,51 };
	int length = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, length-1);
	Print(arr,length);

	return 0;
}
