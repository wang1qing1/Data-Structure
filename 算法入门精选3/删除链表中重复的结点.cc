
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
            while (right->next != nullptr && right->val != right->next->val)//ȷ���ظ���ʼλ��
            {
                left = right;
                right = right->next;
            }
            while (right->next != nullptr && right->val == right->next->val)//ȷ���ظ�����λ��
            {
                right = right->next;
            }
            //ɾ��
            if (left->next == right)//û����Ҫɾ���Ľ����
            {
                return head->next;
            }
            //����
            left->next = right->next;//ɾ�������ڽڵ�
            right = left->next;
        }
        return head->next;

    }
};