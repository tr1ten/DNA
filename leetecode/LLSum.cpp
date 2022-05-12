#include <iostream>
#include <vector>
#include <string>
#include <structures.h>
using namespace std;
typedef Node<int> ListNode;
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    auto *temp1 = l1;
    auto *temp2 = l2;
    ListNode* node=nullptr;
    ListNode* head=nullptr;

    while (temp1 || temp2)
    {
        int a = temp1 ? temp1->val : 0;
        int b = temp2 ? temp2->val : 0;
        int sum = a+b+carry;
        if(!node)
        {
            node = new ListNode(sum%10);
            head = node;
        }
        else{
            node->next = new ListNode(sum%10);
            node = node->next;
        }
        carry = sum/10;
        temp1 = temp1 ? temp1->next : nullptr;
        temp2 = temp2 ? temp2->next : nullptr;
    }
    if(carry)
    {
        node->next  =  new  ListNode(carry);
    }
    return head;
}
int main()
{
    
    return 0;
}
