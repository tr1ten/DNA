#include <iostream>
using namespace std;

struct Poly
{
    int c;
    int degree;
    friend ostream &operator<<(ostream &output, const Poly &p)
    {
        output << p.c << "x(" << p.degree << ")";
        return output;
    }
};

template <typename T>
struct Node
{
    T val;
    Node<T> *next;
    Node<T> *prev;
    Node(T val = 0, Node<T> *next = nullptr, Node<T> *prev = nullptr) : val(val), prev(prev), next(next) {}
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList();
    LinkedList(T);
    void printLL() const;
    void insertNode(T, int index = -1);
    void deleteNode(int);
    ~LinkedList();
};

template <typename T>
void LinkedList<T>::printLL() const
{
    Node<T> *temp = head;
    cout << "linked list: ";
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp = head;
    while (temp)
    {
        Node<T> *ntemp = temp->next;
        delete temp;
        temp = ntemp;
    }
}
template <typename T>
void LinkedList<T>::deleteNode(int index)
{
    Node<T> *temp = head;
    int i = 0;
    while (temp->next && i < index)
    {
        temp = temp->next;
        i++;
    }
    if (index == 0)
    {
        // delete head ie whole LinkedList
        head = nullptr;
    }
    else
    {
        // delete arbitary index
        Node<T> *ptemp = temp->prev;
        Node<T> *ntemp = temp->next;
        delete temp;
        ptemp->next = ntemp;
    }
}
template <typename T>
void LinkedList<T>::insertNode(T val, int index)
{
    if (!head)
    {
        head = new Node<T>(val);
        return;
    }
    Node<T> *temp = head;
    int i = 0;
    while (temp->next && (index < 0 || (index > 0 && i < index)))
    {
        temp = temp->next;
        i++;
    }
    // append at last position
    if (index < 0 || !temp)
    {
        Node<T> *node = new Node<T>(val, nullptr, temp);
        temp->next = node;
    }
    else if (index == 0)
    {
        // at begining
        head = new Node<T>(val, temp);
        temp->prev = head;
    }

    else
    {
        // insert at arbitary pos except last
        Node<T> *ptemp = temp->prev;
        ptemp->next = new Node<T>(val, temp, ptemp);
        temp->prev = ptemp->next;
    }
}
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList(T val)
{
    head = new Node<T>(val);
}
void testLL()
{
    LinkedList<int> linkedList(1);
    // inserting
    linkedList.insertNode(2);
    linkedList.insertNode(3);
    linkedList.insertNode(4, 1);
    linkedList.insertNode(5, 0);
    // deleting
    linkedList.deleteNode(4);
    linkedList.deleteNode(1);
    linkedList.printLL();
}

LinkedList<Poly> &addPoly(const LinkedList<Poly> &p1, const LinkedList<Poly> &p2)
{
    Node<Poly> *temp = p1.head->val.degree > p2.head->val.degree ? p1.head : p2.head;
    Node<Poly> *temp2 = p1.head->val.degree > p2.head->val.degree ? p2.head : p1.head;
    LinkedList<Poly> *summedLL = new LinkedList<Poly>;
    while (temp)
    {
        if (temp2->val.degree < temp->val.degree)
        {
            summedLL->insertNode(temp->val);
        }
        else
        {
            Poly sp = {temp->val.c + temp2->val.c, temp->val.degree};
            summedLL->insertNode(sp);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return *summedLL;
}
void testAddPoly()
{
    LinkedList<Poly> p1;
    LinkedList<Poly> p2;
    p1.insertNode({5, 2});
    p1.insertNode({4, 1});
    p1.insertNode({2, 0});
    p2.insertNode({-5, 1});
    p2.insertNode({-5, 0});
    LinkedList<Poly> p3 = addPoly(p1, p2);
    p3.printLL();
}
//
template class LinkedList<int>;
int main()
{
    testAddPoly();
    return 0;
}
