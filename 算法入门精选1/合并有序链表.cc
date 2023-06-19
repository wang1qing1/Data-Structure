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
     * @param pHead1 ListNode��
     * @param pHead2 ListNode��
     * @return ListNode��
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
            //1.ѡ����ʽ��
            ListNode* tmp = pHead1->val < pHead2->val ? pHead1 : pHead2;
            if (tmp == pHead1)
            {
                pHead1 = pHead1->next;
            }
            else
            {
                pHead2 = pHead2->next;
            }
            //2.�����±�
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
        //3.�����������
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