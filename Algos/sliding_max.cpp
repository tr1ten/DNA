// https://cp-algorithms.com/data_structures/stack_queue_modification.html#queue-modification-method-3
// https://leetcode.com/problems/sliding-window-maximum/description/
#include <bits/stdc++.h>

using namespace std;


template<typename T>
struct sliding_max
{
    stack<pair<T,T>> s1,s2; // s2...s1 
    T comb(T a,T b) {return max(a,b); }// change to any function 
    void push(T x){
        T el = !s1.empty() ? comb(x,s1.top().second) : x;
        s1.push({x,el});
    }
    void pop(){
        assert(!s1.empty() || !s2.empty());
        if(s2.empty()){
            while (!s1.empty())
            {
                T el = s1.top().first;
                s1.pop();
                T min_e = s2.empty() ? el : comb(el,s2.top().second);
                s2.push({el,min_e});
            }
            
        }
        s2.pop();
    }
    T query(){
        if(s2.size() && s1.size()) return comb(s2.top().second,s1.top().second);
        if(s1.size()) return s1.top().second;
        if(s2.size()) return s2.top().second;
        return 0; // sentinel
    }

};

int main(){
}