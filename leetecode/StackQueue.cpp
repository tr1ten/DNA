#include <iostream>
#include <stack>
using namespace std;
class MyQueue
{
    stack<int> mainStack;
    stack<int> otherStack;
    int front=NULL;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        if (mainStack.empty())
        {
            front = x;
        }
        mainStack.push(x);
    }

    int pop()
    {
        while (!mainStack.empty())
        {
            otherStack.push(mainStack.top());
            mainStack.pop();
        }
        int temp = otherStack.top();
        otherStack.pop();
        front = !otherStack.empty() ? otherStack.top() : NULL;
        while (!otherStack.empty())
        {
            mainStack.push(otherStack.top());
            otherStack.pop();
        }
        return temp;
    }

    int peek()
    {
        return this->front;
    }

    bool empty()
    {
        return mainStack.empty();
    }
};
int main()
{
    return 0;
}
