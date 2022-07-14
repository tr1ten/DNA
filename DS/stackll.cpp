#include "./structures.h"
struct Stack
{
    LinkedList<int> stack;
    int top;
    Stack();
    Stack(int);
    void push(int);
    void pop();
};
Stack::Stack()
{
    LinkedList<int> stack;
    top=-1;
}
Stack::Stack(int val)
{
    LinkedList<int> stack(val);
    top = 0;
}
void Stack::push(int val)
{
    stack.insertNode(val,-1);
    top++;
}
void Stack::pop()
{   
    stack.deleteNode(top);
}

void testStack()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.stack.printLL();
}
int main()
{
    testStack();
    return 0;
}
