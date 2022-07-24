#include <list>
using namespace std;
struct Stack
{
    list<int> stack;
    int top;
    Stack(){};
    Stack(int);
    void push(int);
    void pop();
};
Stack::Stack(int val)
{
    stack.push_front(val);
}
void Stack::push(int val)
{
        stack.push_front(val);

}
void Stack::pop()
{   
   stack.pop_front();
}

void testStack()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    
}
int main()
{
    testStack();
    return 0;
}
