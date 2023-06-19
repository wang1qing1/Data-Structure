/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		int count = 0;
		ListNode* phead = pListHead;
		while (phead)
		{
			count++;
			phead = phead->next;
		}
		if (pListHead == nullptr || k > count || k == 0)
		{
			return nullptr;
		}
		int tmp = k;
		while (tmp--)
		{
			fast = fast->next;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};
