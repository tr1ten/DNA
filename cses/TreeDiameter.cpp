#include <cstdio>
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
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
const LL MOD = 1e9+7;
const int INF = 1e8+5;
// diameter of n-ary tree
int res = 0;
int f(int u,int p,vector<vector<int>> &adj){
    int mxl = 0; // max left child path
    int mxr = 0; // max right
    for(int v:adj[u]){
        if(v==p) continue;
        int temp = f(v,u,adj);
        if(mxl<temp){
            mxr = mxl;
            mxl = temp;
        }
        else if(mxr<temp) mxr = temp;
    }
    res = max(1+mxl+mxr,res);
    return 1+mxl;
}
// actual solutions 
size_t solve(size_t n,vector<vector<int>> &adj){
    res = 0;
    f(0,-1,adj);
    return res-1;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<vector<int>> adj(N);
    FOR(i,1,N){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    cout<<solve(N,adj);
    return 0;
}
