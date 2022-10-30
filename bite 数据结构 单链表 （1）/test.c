#include"STListNode.h"

TestList()
{
	SListNode* phead = NULL;
	STLPushBank(&phead, 30);
	STLPushBank(&phead, 100); 
	STLPushBank(&phead, 200);
	STLPushBank(&phead, 300);
	SLTPushFront(&phead, 50);
	//STLPopBank(&phead);
	SLTPopFront(&phead);
	PrintList(phead);
}

int main()
{
	TestList();


	return 0;
}
