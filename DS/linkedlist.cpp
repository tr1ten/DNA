#include <iostream>
using namespace std;

struct Poly
{
    int c;
    int degree;
    Poly(int c, int d) : c(c), degree(d) {}
    Poly() {}
    friend ostream &operator<<(ostream &output, const Poly &p)
    {
        output << p.c << "x(" << p.degree << ")";
        return output;
    }
    bool operator<(const Poly &p)
    {
        return this->degree < p.degree;
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
    void sort();
    void reversed();
    ~LinkedList();
};
// reversing a linked list
template <typename T>
void LinkedList<T>::reversed()
{
    Node<T> *prev = nullptr;
    Node<T> *cur = this->head;
    Node<T> *next = nullptr;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    this->head = prev;
}

template <typename T>
void LinkedList<T>::sort()
{
    Node<T> *temp = this->head;
    while (temp)
    {
        Node<T> *temp2 = this->head;
        while (temp2->next)
        {
            if (temp2->val < temp2->next->val)
            {
                Node<T> *prev1 = temp2->prev;
                Node<T> *nextTemp = temp2->next;
                Node<T> *nextNextTemp = nextTemp->next;
                if (prev1)
                {

                    prev1->next = nextTemp;
                }
                else
                {
                    this->head = nextTemp;
                }
                nextTemp->prev = prev1;
                nextTemp->next = temp2;
                temp2->next = nextNextTemp;
                if (nextNextTemp)
                {

                    nextNextTemp->prev = temp2;
                }
                temp2->prev = nextTemp;

            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}
template <typename T>
void LinkedList<T>::printLL() const
{
    Node<T> *temp = head;
    cout << "linked list: ";
    while (temp)
    {
        cout << temp->val << (temp->next ? " + " : " ");
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
        delete this->head;
        this->head = nullptr;
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
    linkedList.insertNode(4);
    // linkedList.sort();
    linkedList.printLL();
    linkedList.reversed();
    linkedList.printLL();
}

LinkedList<Poly> *addPoly(const LinkedList<Poly> &p1, const LinkedList<Poly> &p2)
{
    Node<Poly> *temp = p1.head->val.degree > p2.head->val.degree ? p1.head : p2.head;
    Node<Poly> *temp2 = p1.head->val.degree > p2.head->val.degree ? p2.head : p1.head;
    LinkedList<Poly> *summedLL = new LinkedList<Poly>;
    while (temp && temp2)
    {
        if (temp2->val.degree < temp->val.degree)
        {
            summedLL->insertNode(temp->val);
            temp = temp->next;
        }
        else if (temp2->val.degree > temp->val.degree)
        {
            summedLL->insertNode(temp2->val);
            temp2 = temp2->next;
        }
        else
        {
            Poly sp = {temp->val.c + temp2->val.c, temp->val.degree};
            summedLL->insertNode(sp);
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    while (temp)
    {
        summedLL->insertNode(temp->val);
        temp = temp->next;
    }
    while (temp2)
    {
        summedLL->insertNode(temp2->val);
        temp2 = temp2->next;
    }

    return summedLL;
}
LinkedList<Poly> *multiplyPoly(LinkedList<Poly> &p1, LinkedList<Poly> &p2)
{
    auto &sortedLL = p1;
    auto &sortedLL2 = p2;
    sortedLL.sort();
    sortedLL2.sort();
    auto t1 = sortedLL.head;
    auto t2 = sortedLL2.head;
    LinkedList<Poly> *summedLL = nullptr;
    while (t1)
    {
        LinkedList<Poly> *newLL = new LinkedList<Poly>();
        t2 = sortedLL2.head;
        while (t2)
        {
            auto poly = Poly(t2->val.c * t1->val.c, t2->val.degree + t1->val.degree);
            newLL->insertNode(poly);
            t2 = t2->next;
        }

        if (!summedLL)
        {
            summedLL = newLL;
        }
        else
        {
            summedLL = addPoly(*summedLL, *newLL);
        }
        t1 = t1->next;
    }
    return summedLL;
}

bool areTwoPolyEqual(const LinkedList<Poly> &p1, const LinkedList<Poly> &p2)
{
    Node<Poly> *t1 = p1.head;
    Node<Poly> *t2 = p2.head;
    while (t1 && t2)
    {
        if (t1->val.c != t2->val.c || t1->val.degree != t2->val.degree)
        {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return !t1 && !t2;
}

void testTwoPolyEqual()
{
    LinkedList<Poly> p1;
    p1.insertNode(Poly(1, 0));
    p1.insertNode(Poly(2, 1));
    p1.insertNode(Poly(3, 2));
    LinkedList<Poly> p2;
    p2.insertNode(Poly(1, 0));
    p2.insertNode(Poly(2, 1));
    p2.insertNode(Poly(3, 2));
    cout << areTwoPolyEqual(p1, p2) << endl;
}

void testMulPoly()
{
    LinkedList<Poly> p1;
    LinkedList<Poly> p2;
    p1.insertNode({1, 1});
    p1.insertNode({2, 2});
    p1.insertNode({2, 3});
    p2.insertNode({1, 1});
    p2.insertNode({-5, 3});
    auto *p3 = multiplyPoly(p1, p2);
    p3->printLL();
    p3->~LinkedList();
}

template class LinkedList<int>;
int main()
{
    testTwoPolyEqual();
    return 0;
}
