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
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // write code here
        ListNode* phead = new ListNode(0);
        while (head)
        {
            //1.取结点
            ListNode* p = head;
            head = head->next;
            //2.头插
            ListNode* frist = phead->next;
            phead->next = p;
            p->next = frist;
        }
        return phead->next;

    }
};
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* left = head;
        ListNode* mid = left->next;
        ListNode* right = mid->next;
        while (right)
        {
            mid->next = left;
            left = mid;
            mid = right;
            right = right->next;
        }
        mid->next = left;
        head->next = nullptr;
        return mid;

    }
};
