#include"List.h"
int main()
{
	ListNode* Head = InitListNode();
	HeadAdd(Head);
	HeadAdd(Head);
	HeadAdd(Head);
	TailAdd(Head);
	MidAdd(Head);
	PrintList(Head);
	return 0;
}