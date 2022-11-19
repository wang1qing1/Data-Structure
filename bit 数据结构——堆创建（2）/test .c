#include"Heap.h"

int main()
{
	Heap hp;
	HeapInit(&hp);

	int array[] = { 27,15,19,18,28,34,65,49,25,37 };

	/*for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		HeapPush(&hp, array[i]);
	}*/
	HeapCreate(&hp, array, sizeof(array)/sizeof(int));

	//Print(&hp, sizeof(array) / sizeof(int));
	int k = 4;
	//topKÎÊÌâ
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	return 0;
}