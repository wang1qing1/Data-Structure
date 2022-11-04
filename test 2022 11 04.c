#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


//合并两个有序链表 (1)
struct ListNode* Buy(int x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

struct ListNode* mergeTwoLists1(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode* pTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    pTail->next = NULL;
    struct ListNode* pHead = pTail;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            struct ListNode* new = Buy(list1->val);
            pTail->next = new;
            pTail = new;
            list1 = list1->next;
        }
        else
        {
            struct ListNode* new = Buy(list2->val);
            pTail->next = new;
            pTail = new;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        while (list1)
        {
            struct ListNode* new = Buy(list1->val);
            pTail->next = new;
            pTail = new;
            list1 = list1->next;
        }
    }
    if (list2)
    {
        while (list2)
        {
            struct ListNode* new = Buy(list2->val);
            pTail->next = new;
            pTail = new;
            list2 = list2->next;
        }
    }
    return pHead->next;
}

//合并两个有序链表 (2) --不带哨兵位
struct ListNode* mergeTwoLists2(struct ListNode* list1, struct ListNode* list2) 
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    struct ListNode* phead = NULL;
    struct ListNode* ptail = NULL;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            if (ptail == NULL)
            {
                ptail = phead = list1;
            }
            else
            {
                ptail->next = list1;
                ptail = list1;

            }
            list1 = list1->next;
        }
        else
        {
            if (ptail == NULL)
            {
                ptail = phead = list2;
            }
            else
            {
                ptail->next = list2;
                ptail = list2;
            }
            list2 = list2->next;
        }
    }
    if (list1)
    {
        ptail->next = list1;
    }
    if (list2)
    {
        ptail->next = list2;
    }
    return phead;
}


//合并两个有序链表(3) ---带哨兵位
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = NULL;
    struct ListNode* ptail = phead;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            ptail->next = list1;
            ptail = list1;
            list1 = list1->next;
        }
        else
        {
            ptail->next = list2;
            ptail = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        ptail->next = list1;
    }
    if (list2)
    {
        ptail->next = list2;
    }
    return phead->next;
}

//移除链表元素 --不带哨兵位
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode* phead = NULL;
    struct ListNode* ptail = NULL;
    if (head == NULL)
        return NULL;
    while (head)
    {
        if (head->val != val)
        {
            if (ptail == NULL)
            {
                phead = ptail = head;
            }
            else
            {
                ptail->next = head;
                ptail = ptail->next;
            }
            head = head->next;
        }
        else
        {
            struct ListNode* valnode = head;
            head = head->next;
            free(valnode);
        }
    }
    if (ptail)
        ptail->next = NULL;
    return phead;
}

int main()
{



    return 0;
}
