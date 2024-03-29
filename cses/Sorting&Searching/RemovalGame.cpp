#pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
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
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;

// actual solutions 
PI f(int left,int right,VI &vec,vector<vector<PI>> &dp){
    if(left==right) return {vec[left],0}; // first sum, second sum
    if(dp[left][right].first!=-INF) return dp[left][right];
    auto l = f(left+1,right,vec,dp);
    auto r = f(left,right-1,vec,dp);
    if(vec[left]+l.second-l.first>vec[right]+r.second-r.first) {
        return dp[left][right]={vec[left]+l.second,l.first};
    }
    return dp[left][right]={vec[right]+r.second,r.first};
}
LL solve(int n,VI &vec){
    vector<vector<PI>> dp(n,vector<PI>(n,{-INF,-INF}));
    return f(0,n-1,vec,dp).first;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    cout << solve(N,vec) << endl;
    return 0;
}
