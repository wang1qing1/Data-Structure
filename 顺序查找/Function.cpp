#include"head.h"

List* ListInit(int lengh)
{
	List* L = (List*)malloc(sizeof(List));
	L->lengh = lengh;
	L->data = (int*)malloc(sizeof(int) * L->lengh);
	L->count = 1;
	return L;
}

void ListAdd(List*L,int num)
{
	L->data[L->count] = num;
	if (L->count <= L->lengh)
	{
		L->count++;
	}
	else
	{
		exit(-1);
	}
}

int ListSearch(List* L, int key)
{
	int i;
	L->data[0] = key;
	for (i = L->count - 1; L->data[i] != key; i--);
	return i;
}
