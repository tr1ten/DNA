#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(vector<int> &bt,ll x,ll tar){
    multiset<ll> st;
    for(auto x:bt) st.insert(x);
    ll cur = 0;
    int cnt = 1;
    while (st.size())
    {
        auto it = (st.upper_bound(x-cur));
        if(it==st.begin()) {
            cur = 0;
            cnt ++;
        }
        else it = prev(it);
        cur += *it;
        st.erase(it);
    }
    return cnt<=tar;
    
}

ll solve(int n,int m,vector<int> bt){
    ll lo=1,hi = 1e15;
    ll ans = 0;
    while(lo<=hi){
        ll mid = lo+(hi-lo)/2;
        if(check(bt,mid,n)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    // cout << solve(2,5,{9,2,4,4,5});
    cout << solve(3,6,{4,3,2,2,2,6});
    return 0;
}
