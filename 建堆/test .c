#include"Heap.h"

int main()
{
	Heap hp;
	HeapInit(&hp);

	int array[] = { 27,15,19,18,28,34,65,49,25,37 };

	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		HeapPush(&hp, array[i]);
	}
	Print(&hp, sizeof(array) / sizeof(int));
	return;
}