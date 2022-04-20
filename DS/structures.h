// g++ -I flag for header file
template<typename T>
struct Node
{
    T val;
    Node<T> *next;
    Node<T> *prev;
    Node(T val = 0, Node<T> *next = nullptr, Node<T> *prev = nullptr) : val(val), prev(prev), next(next) {}
};

template<typename T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList();
    LinkedList(T);
    void printLL();
    void insertNode(T, int index=-1);
    void deleteNode(int);
    ~LinkedList();
};