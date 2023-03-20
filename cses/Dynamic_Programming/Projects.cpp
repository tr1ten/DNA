#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL; 
typedef pair<int,int> PI;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
LL solve(int n,vector<vector<int>> intervals){
        map<int,LL> ts;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        ts[0] = 0;
        trav(x,intervals){
            auto it = ts.lower_bound(x[0]);
            if(it != ts.begin()){
                it--;
            }
            LL val = x[2] + (*it).second;
            if(val>(*ts.rbegin()).second) ts[x[1]] = max(ts[x[1]],val);
        }
        return (*ts.rbegin()).second;
    }

// driver code
int main()
{
    int N;
    cin>>N;
    mk_mat(ivals,N,3,0);
    FOR(i,0,N){
        cin>>ivals[i][0]>>ivals[i][1]>>ivals[i][2];
    }
    cout << solve(N,ivals) << endl;
    return 0;
}
