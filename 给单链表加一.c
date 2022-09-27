#define _CRT_SECURE_NO_WARNINGS 1

void Addone(struct ListNode* head)
{
    if (head->next != NULL)
    {
        Addone(head->next);
    }
    else
    {
        head->val += 1;
        return;
    }
    if (head->next->val == 10)
    {
        head->next->val -= 10;
        head->val += 1;
    }
    return;
}
struct ListNode* plusOne(struct ListNode* head) {
    struct ListNode* H = head;
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = 1;
    Addone(H);
    if (H->val == 10)
    {
        newnode->next = H;
        H->val = 0;
        H = newnode;
    }
    return H;
}