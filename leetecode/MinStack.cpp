#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, greater<T>>
{
public:
    bool remove(const T &value)
    {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end())
        {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else
        {
            return false;
        }
    }
};
// two stack
class MinStack
{
public:
    stack<long long> st;
    stack<long long> mst;
    long long minel;
    MinStack()
    {
    }
    void push(long long val)
    {
        if(st.empty())
        {
            minel = val;
        }
        else{
            minel  = min(minel,val);
        }
        mst.push(minel);
        st.push(val);
    }

    void pop()
    {
        
        mst.pop();
        minel = mst.top();
        st.pop();
    }

    long long top()
    {
        return st.top();
    }

    long long getMin()
    {
        return minel;
    }
};
int main()
{
    MinStack sq;
    sq.push(-2);
    sq.push(0);
    sq.push(-3);
    cout << sq.getMin();
    return 0;
}
