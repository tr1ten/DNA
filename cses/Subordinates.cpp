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

int dfs(int u,int p,vector<vector<int>> &adj,VI &res){
    int cnt = 0;
    for(int v:adj[u]){
        if(v==p) continue;
        cnt += dfs(v,u,adj,res);
    }
    res[u] = cnt;
    return ++cnt;
}
// actual solutions 
void solve(size_t n,VI vec){
    vector<vector<int>> adj(n);
    int v=1;
    mk_vec(res,n,0);
    for(int u:vec){
        adj[u-1].push_back(v);
        adj[v].push_back(u-1);
        v++;
    }
    dfs(0,-1,adj,res);

    trav(x,res){
        std::cout << x << " " ;
    }
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    mk_vec(vec,N-1,0);
    take_vec(vec,N-1);
    solve(N,vec);
    return 0;
}
