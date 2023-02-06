// #pragma GCC optimize(2, 3, "Ofast", "unroll-loops", "-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL, LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, arr) for (auto &a : (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name, sz, value) VI name(sz, value)
#define mk_mat(name, n, m, value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec, sz) FOR(i, 0, sz) cin >> vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
const LL MOD = 1e9 + 7;
const LL INF = 1e10 + 5;

// actual solutions
LL f(int prev,int m,int idx,VI &nums,VII &dp){
    int n = nums.size();
    // cout << idx << " " << prev << endl;
    if(idx==n) return 1;
    if(dp[idx][prev]!=-1) return dp[idx][prev];
    if(nums[idx]!=0){
        return dp[idx][prev] = f(nums[idx],m,idx+1,nums,dp);
    }
    LL res = 0;
    if((idx+1==n || nums[idx+1]==0 || abs(nums[idx+1]-prev)<=1)) res = (res+f(prev,m,idx+1,nums,dp))%MOD;
    if(prev+1<=m and (idx+1==n || nums[idx+1]==0 || abs(nums[idx+1]-prev-1)<=1)) res = (res+f(prev+1,m,idx+1,nums,dp))%MOD;
    if(prev-1>=1 and (idx+1==n || nums[idx+1]==0 || abs(nums[idx+1]-prev+1)<=1)) res= (res+f(prev-1,m,idx+1,nums,dp))%MOD; 
    return dp[idx][prev] = res;
}
LL solve(int n, int m, VI &vec)
{
    mk_mat(dp,n+1,m+1,-1);
    // check if not possible
    FOR(i,1,n) if(vec[i]!=0 && vec[i-1]!=0 && abs(vec[i]-vec[i-1])>1) return 0;
    if(vec[0]!=0) return f(0,m,0,vec,dp);
    else {
        if(n==1) return m;
        LL res = 0;
        FOR(i,1,m+1) if(vec[1]==0 || abs(vec[1]-i)<=1) res= (res+f(i,m,1,vec,dp))%MOD; 
        return res;
    }
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    mk_vec(vec, N, 0);
    take_vec(vec, N);
    cout << solve(N, M, vec) << endl;
    return 0;
}
