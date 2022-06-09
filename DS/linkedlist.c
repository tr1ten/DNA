#include <stdio.h>
struct Node;
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *appendNode(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node *mergeLL(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *newHead = NULL;
    Node *temp = NULL;
    while (p1 && p2)
    {
        Node *newNode = NULL;

        if (p1->data < p2->data)
        {
            newNode = p1;
            p1 = p1->next;
        }
        else
        {
            newNode = p2;
            p2 = p2->next;
        }
        if (!newHead)
        {
            newHead = newNode;
            temp = newHead;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    while (p1)
    {
        temp->next = p1;
        temp = temp->next;
        p1 = p1->next;
    }
    while (p2)
    {
        temp->next = p2;
        temp = temp->next;
        p2 = p2->next;
    }
    return newHead;
}
void printLL(Node *head)
{
    Node *temp = head;
    printf("\n");

    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
Node *findIntersaction(Node *head1, Node *head2)
{
    int l1 = 0;
    int l2 = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1)
    {
        l1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        l2++;
        temp2 = temp2->next;
    }
    Node *start = l2 > l1 ? head2 : head1;
    int d = l2 > l1 ? l2 - l1 : l1 - l2;
    while (d)
    {
        start = start->next;
        d--;
    }
    Node *other = l2 < l1 ? head2 : head1;
    while (other!=start)
    {
        other = other->next;
        start = start->next;
    }
    return other;
    

}
int main()
{
    Node *head = 0;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    Node *head2 = NULL;
    head2 = appendNode(head2, 3);
    head2 = appendNode(head2, 4);
    head2 = appendNode(head2, 7);
    head2 = appendNode(head2, 10);

    printLL(head);
    printLL(head2);
    Node *newH = mergeLL(head, head2);
    printLL(newH);

    return 0;
}
