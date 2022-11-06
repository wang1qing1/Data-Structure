#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;


//链表分割
ListNode* partition(ListNode* pHead, int x) {
    ListNode* Head1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* Head2 = (ListNode*)malloc(sizeof(ListNode));
    Head1->next = pHead;
    Head2->next = NULL;
    ListNode* prev = Head1;
    ListNode* cur = prev->next;
    ListNode* Tail2 = Head2;
    while (cur)
    {
        if (cur->val < x)
        {
            Tail2->next = cur;
            Tail2 = cur;
            cur = cur->next;
            prev->next = cur;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    Tail2->next = Head1->next;
    ListNode* pp = Head2->next;
    free(Head1);
    free(Head2);
    return pp;
}

//链表的回文结构
bool chkPalindrome(ListNode* A) {
    ListNode* cur = A;
    int m = 0;

    while (cur)
    {
        m++;
        cur = cur->next;
    }
    int n = m / 2;
    int count = n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < count; i++, cur = cur->next)
    {
        arr[i] = cur->val;
    }
    if (m % 2 == 1)
    {
        cur = cur->next;
    }

    for (int i = count - 1; i >= 0; i--, cur = cur->next)
    {
        if (arr[i] != cur->val)
        {
            return false;
        }
    }
    return true;

}

//两数相加
struct ListNode* Buy(int x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->next = NULL;
    newnode->val = x;
    return newnode;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode* pTail = pHead;
    int flag = 0;
    while (l1 && l2)
    {
        struct ListNode* newnode = Buy((l1->val + l2->val + flag) % 10);
        flag = (flag + l1->val + l2->val) / 10;
        pTail->next = newnode;
        pTail = newnode;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        struct ListNode* newnode = Buy((l1->val + flag) % 10);
        flag = (flag + l1->val) / 10;
        pTail->next = newnode;
        pTail = newnode;
        l1 = l1->next;
    }
    while (l2)
    {
        struct ListNode* newnode = Buy((l2->val + flag) % 10);
        flag = (flag + l2->val) / 10;
        pTail->next = newnode;
        pTail = newnode;
        l2 = l2->next;
    }
    if (flag == 1)
    {
        struct ListNode* newnode = Buy(flag);
        pTail->next = newnode;
    }
    return pHead->next;
}

//环形链表
bool hasCycle(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* frist = head;
    struct ListNode* slow = head;
    int flag = 0;
    while (frist)
    {
        if (frist == slow)
        {
            flag++;
        }
        if (frist == slow && flag > 1)
        {
            return true;
        }
        if (frist->next)
            frist = frist->next->next;
        else
            break;

        slow = slow->next;
    }
    return false;
}

//链表相交
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    for (struct ListNode* i = headA; i != NULL; i = i->next)
    {
        for (struct ListNode* j = headB; j != NULL; j = j->next)
        {
            if (i == j)
            {
                return i;
            }
        }
    }
    return NULL;
}

int main()
{
    return 0;
}