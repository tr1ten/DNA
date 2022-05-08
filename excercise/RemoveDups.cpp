#include <iostream>
#include <vector>
#include <string>
#include "../DS/structures.h"
#include <unordered_set>
using namespace std;
void removeDups(Node<int> *head)
{
    unordered_set<int> uset;
    Node<int> *temp = head;
    Node<int> *prev = nullptr;
    while (temp)
    {
        if(uset.find(temp->val)!=uset.end())
        {
            prev->next = temp->next;
        }
        else{
            uset.insert(temp->val);
        }
        prev = temp;
        temp = temp->next;
    }
    
}
int main()
{
    LinkedList<int> ll(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(3);
    // ll.printLL();
    removeDups(ll.head);
    // ll.printLL();

    return 0;
}
