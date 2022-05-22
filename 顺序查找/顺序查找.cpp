#include"head.h"
int main()
{
	List*L=ListInit(5);
	ListAdd(L,4);
	ListAdd(L,5);
	ListAdd(L,6);
	ListAdd(L,7);
	int p=ListSearch(L, 5);
	printf("%d", p);
	return 0;
}