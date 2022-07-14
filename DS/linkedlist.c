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
Node *findNode(Node *head, int data)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

Node *deleteNode(Node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == data)
    {
        Node *temp = head->next;
        free(head);
        return temp;
    }
    Node *temp = head;
    while (temp->next)
    {
        if (temp->next->data == data)
        {
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            return head;
        }
        temp = temp->next;
    }
    return head;
}
Node *copyLinkedList(Node *head){
    Node *temp = head;
    Node *newHead = NULL;
    while (temp)
    {
        newHead = appendNode(newHead, temp->data);
        temp = temp->next;
    }
    return newHead;
}
void clearLinkedList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        Node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}
void printLL(Node *head)
{
    Node *temp = head;
    printf("\n");

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = 0;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = deleteNode(head, 2);
    Node *temp = findNode(head, 1);
    printf("found element-:%d\n", temp->data);
    printLL(head);
    clearLinkedList(head);
    printf("cleared linked list\n");
    return 0;
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
    if(p1)
    {
        temp->next = p1;
    }
    else
    {
        temp->next = p2;
    }
    return newHead;
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