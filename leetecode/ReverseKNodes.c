#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode *NodePtr;
NodePtr rev;

void printLL(NodePtr head)
{
    NodePtr temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
void reverseLL(NodePtr prev, NodePtr cur)
{
    if (!cur)
    {
        rev = prev;
        return;
    }
    reverseLL(cur, cur->next);
    cur->next = prev;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    NodePtr temp = head;
    int i = 0;
    NodePtr start = NULL;
    NodePtr end = NULL;
    NodePtr nhead = NULL;
    NodePtr prev = NULL;
    while (temp)
    {
        i++;
        if (i == 1)
        {
            start = temp;
            end=NULL;
        }
        if (i == k)
        {
            end = temp;
            temp = temp->next;
            end->next = NULL;
            rev = NULL;
            reverseLL(0, start);
            if (!nhead)
            {
                nhead = rev;
            }
            else
            {
                prev->next = rev;
            }
            prev = start;
            i = 0;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (!end && start)
    {
        prev->next = start;
    }
    return nhead;
}
int main()
{
    // test
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    // reverseLL(0,head);
    // 1 to 100
    // [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]
    printLL(reverseKGroup(head, 3));
    return 0;
}
