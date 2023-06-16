
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr)
        {
            return pHead;
        }
        ListNode* head = new ListNode(0);
        head->next = pHead;
        ListNode* left = head;
        ListNode* right = head->next;
        while (right)
        {
            while (right->next != nullptr && right->val != right->next->val)//确定重复开始位置
            {
                left = right;
                right = right->next;
            }
            while (right->next != nullptr && right->val == right->next->val)//确定重复结束位置
            {
                right = right->next;
            }
            //删除
            if (left->next == right)//没有需要删除的结点了
            {
                return head->next;
            }
            //存在
            left->next = right->next;//删除区间内节点
            right = left->next;
        }
        return head->next;

    }
};