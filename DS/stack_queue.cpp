#include <bits/stdc++.h>

using namespace std;


class MyStack {
private:
    queue<void *> * last; // contians two element (void) type is like unknown type 

public:
    MyStack() {
        
    }
    void push(int x) {
         queue<void *> * q = new queue<void *>();
        q->push((void *)x);
        q->push((void *)last);
        last = q;
    }
    
    int pop() {
        int front = (int)last->front();
        last->pop();
        return front;
    }
    
    int top() {
        return (int)last->front();
    }
    
    bool empty() {
        return last->size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */