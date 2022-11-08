#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};
struct Node* copyRandomList(struct Node* head) {

    if (head == NULL)
    {
        return NULL;
    }
    struct Node* Next = head->next;
    struct Node* prev = head;
    while (prev)
    {
        //创建结点并连接
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->next = NULL;
        newnode->random = NULL;
        prev->next = newnode;
        newnode->next = Next;

        //迭代
        prev = Next;
        if (Next)
        {
            Next = Next->next;
        }
    }
    prev = head;
    struct Node* new = head->next;
    while (prev)
    {
        //新节点连接
        new->val = prev->val;
        if (prev->random)
            new->random = prev->random->next;
        else
            new->random = NULL;
        //迭代
        if (new->next)
        {
            new = new->next->next;
        }
        prev = prev->next->next;
    }

    struct Node* phead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptail = phead;
    struct Node* cur = head->next;
    while (cur)
    {
        ptail->next = cur;
        ptail = cur;
        if (cur->next)
        {
            cur = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return phead->next;
}

int main()
{
    return 0;
}