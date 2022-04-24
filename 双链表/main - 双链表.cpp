#include"SEQ.h"
int main()
{
	ListNode* phead = NULL;
	ListInit(&phead);
	ListPushBank(phead, 100);
	ListPushBank(phead, 200);
	ListPushBank(phead, 300);
	ListPushBank(phead, 400);
	//ListPrintf(phead);
	//ListPopBank(&phead);
	//ListPushFront(&phead, 100);
	//ListPrintf(phead);
	//ListPopFront(&phead);
	ListNode*pos=ListFind(phead, 200);
	//pos->data = 2000;
	//ListPopPos(pos);
	ListPushPosAfter(pos, 250);
	ListPrintf(phead);
	ListDestroyAll(phead);
	return 0;
}