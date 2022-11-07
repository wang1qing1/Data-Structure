#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;


//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//��������(��)----���������ཻ˼��
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* frist = head;
    struct ListNode* slow = head;
    while (frist && frist->next)
    {
        frist = frist->next->next;
        slow = slow->next;
        if (frist == slow)
        {
            struct ListNode* phead = frist->next;
            slow->next = NULL;
            return getIntersectionNode(phead, head);
        }
    }
    return NULL;
}

//�ཻ����(ʱ�临�Ӷ�O(n))  ���㳤�ȣ�ͬ���ߣ����Ƿ�����ͬ���
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* listA = headA;
    struct ListNode* listB = headB;
    int countA = 0;
    int countB = 0;
    while (listA)
    {
        countA++;
        listA = listA->next;
    }
    while (listB)
    {
        countB++;
        listB = listB->next;
    }
    int n = abs(countA - countB);
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (countB > countA)
    {
        longlist = headB;
        shortlist = headA;
    }
    while (n--)
    {
        longlist = longlist->next;
    }
    while (longlist && shortlist)
    {
        if (longlist == shortlist)
        {
            return longlist;
        }
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return NULL;
}

//�ж��Ƿ���� ----����ָ��
bool hasCycle(struct ListNode* head) {

    struct ListNode* frist = head;
    struct ListNode* slow = head;
    while (frist && frist->next)
    {
        frist = frist->next->next;
        slow = slow->next;
        if (frist == slow)
        {
            return true;
        }
    }
    return false;

}

//�ָ�����---��������β�巨
ListNode* partition(ListNode* pHead, int x) {
    ListNode* Headb = (ListNode*)malloc(sizeof(ListNode));
    ListNode* Heads = (ListNode*)malloc(sizeof(ListNode));
    Headb->next = NULL;
    Heads->next = NULL;
    struct ListNode* Tailb = Headb;
    struct ListNode* Tails = Heads;
    struct ListNode* cur = pHead;
    while (cur)
    {
        if (cur->val < x)
        {
            Tails->next = cur;
            Tails = cur;
        }
        else
        {
            Tailb->next = cur;
            Tailb = cur;
        }
        cur = cur->next;
    }
    Tails->next = Headb->next;
    Tailb->next = NULL;
    return Heads->next;


}


//�������� ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
bool chkPalindrome(ListNode* A) {
    struct ListNode* fast = A;
    struct ListNode* slow = A;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* mid = slow;

    struct ListNode* prev = NULL;
    struct ListNode* NextNode = mid->next;

    while (mid)
    {
        mid->next = prev;
        prev = mid;
        mid = NextNode;
        if (NextNode)
            NextNode = NextNode->next;
    }

    while (prev && A)
    {
        if (prev->val != A->val)
        {
            return false;
        }
        prev = prev->next;
        A = A->next;
    }
    return true;
}

//������������
//��Ҫ���ӵ��߼��Ƶ�
struct ListNode* detectCycle(struct ListNode* head) {

    struct ListNode* frist = head;
    struct ListNode* slow = head;
    while (frist && frist->next)
    {
        frist = frist->next->next;
        slow = slow->next;
        if (frist == slow)
        {

            struct ListNode* meet = frist;
            struct ListNode* cur = head;
            while (meet != cur)
            {
                meet = meet->next;
                cur = cur->next;
            }
            return meet;
        }
    }
    return NULL;

}
