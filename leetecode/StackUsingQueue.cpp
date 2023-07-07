#include <bits/stdc++.h>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        while(sz-->1) {q.push(q.front()); q.pop();}
        // while(!temp.empty()) {q.push(temp.front()); temp.pop();}
    }
    
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
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