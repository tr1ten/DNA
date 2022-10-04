#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next, *prev;
};

// merge two doubly linked list
Node *merge(Node *first, Node *second,bool isReverse=false)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if(!isReverse)
    {
        if (first->data < second->data)
        {
            first->next = merge(first->next,second);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        }
        else
        {
            second->next = merge(first,second->next);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }
    else
    {
        if (first->data > second->data)
        {
            first->next = merge(first->next,second,true);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        }
        else
        {
            second->next = merge(first,second->next,true);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }
}

Node *mergeSort(Node* root,bool isReverse=false){
    if(root == NULL || root->next == NULL)
        return root;
    Node* slow = root;
    Node* fast = root;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = NULL;
    Node* left = mergeSort(root);
    Node* right = mergeSort(temp);
    Node* res = merge(left, right,isReverse);
    return res;
}

int main()
{
    // take LinkedList as input
    int T;
    cin>>T;
    while (T-->0)
    {
    Node* root = NULL;
    Node* temp = NULL;
        int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(root == NULL){
            root = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    root = mergeSort(root,false);
    Node *tempp = root;
    while(tempp != NULL){
        cout<<tempp->data<<" ";
        tempp = tempp->next;
    }
    cout << endl;
    root = mergeSort(root,true);
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    }
    
    

    return 0;
}
