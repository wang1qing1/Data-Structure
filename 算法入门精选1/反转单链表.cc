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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @return ListNode��
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
            //1.ȡ���
            ListNode* p = head;
            head = head->next;
            //2.ͷ��
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @return ListNode��
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
