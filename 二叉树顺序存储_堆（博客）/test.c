#include"function.h"

void Print(Heap* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
}

int main()
{
	Heap hp;
	HeapInit(&hp);


	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(array) / sizeof(array[0]);

	/*for (int i = 0; i < n; i++)
	{
		HeapPush(&hp, array[i]);
	}*/
	HeapCreate(&hp, array, n);
	Print(&hp);
	return 0;
}