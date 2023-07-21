#include <bits/stdc++.h>

using namespace std;

priority_queue<int> lpq; // max heap
priority_queue<int,vector<int>,greater<int>> rpq; // min heap
long long lsum =0,rsum = 0;
void balance(){
    while(lpq.size()<rpq.size()){
        lpq.push(rpq.top());
        lsum +=rpq.top();
        rsum -=rpq.top();
        rpq.pop();
    }
}
void insert(int x){
    lpq.push(x);
    lsum +=x;
    lsum -=(lpq.top());
    rsum +=(lpq.top());
    rpq.push((lpq.top()));
    lpq.pop();
    balance();
}
void reset(){  
    lsum=0;rsum=0;
    while(!lpq.empty()) lpq.pop();
    while(!rpq.empty()) rpq.pop();
}