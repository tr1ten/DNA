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
LL dfs(int i,int j,vector<vector<bool>> &mat,vector<vector<int>> &dp){
    if(mat[i][j]==0) return 0;
    if(i==dp.size()-1 and j==dp.size()-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    LL res=0;
    if(i+1<dp.size()) res = (res+dfs(i+1,j,mat,dp))%MOD;
    if(j+1<dp.size()) res = (res+dfs(i,j+1,mat,dp))%MOD;
    return dp[i][j]=res;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<vector<bool>> mat(N,vector<bool>(N,false));
    F0R(i,N){
        string s;
        cin>>s;
        F0R(j,N){
            mat[i][j] = s[j] == '.';
        }
    }
    mk_mat(dp,N,N,-1);
    cout << dfs(0,0,mat,dp) << endl;
    return 0;
}
