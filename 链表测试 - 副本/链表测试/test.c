#include"ListNode.h"
int main()
{
	
	int arr[] = { 1,2,3};
	SListNode* phead=CreateSList(arr, sizeof(arr) / sizeof(arr[0]));
	PrintList(phead);
	return 0;
}