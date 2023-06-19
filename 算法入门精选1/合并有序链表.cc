/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        if (pHead1 == nullptr)
        {
            return pHead2;
        }
        if (pHead2 == nullptr)
        {
            return pHead1;
        }

        ListNode* newhead = nullptr;
        ListNode* newtail = nullptr;

        while (pHead1 && pHead2)
        {
            //1.选择合适结点
            ListNode* tmp = pHead1->val < pHead2->val ? pHead1 : pHead2;
            if (tmp == pHead1)
            {
                pHead1 = pHead1->next;
            }
            else
            {
                pHead2 = pHead2->next;
            }
            //2.插入新表
            if (newhead == nullptr)
            {
                newhead = tmp;
                newtail = tmp;
            }
            else
            {
                newtail->next = tmp;
                newtail = newtail->next;
            }
        }
        //3.有链表结束了
        if (pHead1)
        {
            newtail->next = pHead1;
        }
        if (pHead2)
        {
            newtail->next = pHead2;
        }
        return newhead;


    }
};