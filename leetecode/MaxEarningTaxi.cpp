#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        map<ll,ll> ms;
        ms[0] = 0;
        sort(rides.begin(),rides.end());
        for(auto v:rides){
            ll start = v[0],end =v[1],tip=v[2];
            auto it = ms.upper_bound(start);
            it--;
            ll pos = (*it).second+end-start+tip;
            ms[end] = max(ms[end],pos);
        }
        ll res = (*ms.rbegin()).second;
        for(auto v:ms){
            res=  max(v.second,res);
        }
        return res;
    }
};