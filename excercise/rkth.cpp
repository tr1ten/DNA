#include <iostream>
#include <vector>
#include <string>
#include <structures.h>
using namespace std;
int rkth(Node<int>* node,int k)
{
    int size = 0;
    auto *temp = node;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    int ind = size-k;
    int j=0;
    temp = node;
    while (j<ind)
    {
        temp = temp->next;
        j++;
    }
    return temp->val;
    
    
}
int main()
{
    LinkedList<int> ll(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(4);
    // ll.printLL();
    cout << rkth(ll.head,2) << endl;
    // ll.printLL();

    return 0;
}
