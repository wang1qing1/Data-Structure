#include"STListNode.h"

TestList()
{
	SListNode* phead = NULL;
	STLPushBank(&phead, 30);
	STLPushBank(&phead, 100); 
	STLPushBank(&phead, 200);
	STLPushBank(&phead, 300);
	//SLTPushFront(&phead, 50);
	//STLPopBank(&phead);
	//SLTPopFront(&phead);
	SListNode*tmp=SListFind(phead, 100);
	/*if (tmp != NULL)
	{
		printf("%d \n", tmp->date);
	}
	else
	{
		printf("No Find\n");
	}*/
	SListEraseAfter(tmp);
	//SListInserAfter(tmp, 150);

	PrintList(phead);
	SListDestroy(phead);
}

int main()
{

	TestList();


	return 0;
}
