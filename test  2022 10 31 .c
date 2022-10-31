#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//去重算法
int removeDuplicates(int* nums, int numsSize) {
    int* cur = nums;
    int* ptr = nums;
    int* end = nums + numsSize - 1;
    while (cur <= end)
    {
        if (*cur == *ptr)
        {
            cur++;
        }
        else
        {
            ptr++;
            *ptr = *cur;

        }
    }
    return (ptr - nums) + 1;
}

// 合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* ptr = nums1 + m - 1;
    int* cur = nums2 + n - 1;
    int* end = nums1 + nums1Size - 1;
    while (ptr >= nums1 && cur >= nums2)
    {
        if (*ptr > *cur)
        {
            *end = *ptr;
            ptr--;
            end--;
        }
        else
        {
            *end = *cur;
            cur--;
            end--;
        }
    }
    if (ptr <= nums1)
    {
        int i = cur - nums2;
        while (cur >= nums2)
        {
            nums1[i] = *cur;
            cur--;
            i--;
        }
    }
}

//移除链表元素
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = head;
    struct ListNode* prev = phead;
    while (cur)
    {
        if (cur->val == val)
        {
            prev->next = cur->next;
            cur = cur->next;
        }
        else
        {
            cur = cur->next;
            prev = prev->next;
        }
    }
    return phead->next;
}

//反转链表
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* cur = head;
    struct ListNode* phead = NULL;
    struct ListNode* Next = head->next;
    while (cur)
    {
        cur->next = phead;
        phead = cur;
        cur = Next;
        if (Next)
        {
            Next = Next->next;
        }

    }
    return phead;
}