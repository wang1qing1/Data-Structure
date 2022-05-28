#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Print(int *arr,int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void BubbleSort(int*arr,int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = { 12,65,84,62,34,82,62,45 };
	int length = sizeof(arr) / sizeof(int);
	BubbleSort(arr,length);
	Print(arr, length);


}