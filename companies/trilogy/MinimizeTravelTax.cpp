#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
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
#define rep(N) FOR(i,0,N)
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
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define take(x) cin >> x;
#define take2(x,y) cin >> x >> y;
#define take3(x,y,z) cin >> x >> y >> z;

#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const LL MOD = 1e9+7;
const LL INF = 1e10+5;
const LL MXN = 1e5 + 5;
const int H = 1; // half 
const int NH = 0; // not half

LL dp[MXN][2]; // dp[u][0] - min tax on node u after not halfing u, dp[u][1] after halfing tax on u


using namespace std;

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int par[MXN];
LL contrib[MXN];

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

// get parents of each node
void dfs2(int u,int p)
{
    trav(v, adj[u])
    {
        if (v!=p)
        {
            par[v] = u;
            dfs2(v,u);
        }
    }
}

// contrib of each node using prefix sums on tree
void dfs3(int u, int p)
{
    trav(v, adj[u])
    {
        if (v!=p)
        {
            dfs3(v,u);
            contrib[u] +=contrib[v];
        }
    }
}

void dfs4(int u,int p,VI &T){
    LL half=0;
    LL nhalf = 0;
    trav(v,adj[u]){
        if(v==p) continue;
        dfs4(v,u,T);
        half += min(dp[v][NH],dp[v][H]);
        nhalf += dp[v][NH];
    }
    dp[u][H] = nhalf+(contrib[u]*T[u])/2;
    dp[u][NH] = half+(contrib[u]*T[u]);
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int m;
        take2(n,m);
        VI A(n);
        take_vec(A,n);
        adj.assign(n,vector<int>());
        rep(n-1){
            int u,v;
            take2(u,v);
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(contrib,0,sizeof contrib);
        int root=  0;
        preprocess(root);
        dfs2(root,-1);
        rep(m){
            int u,v;
            take2(u,v);
            u--;
            v--;
            int lc = lca(u,v);
            contrib[u]++;
            contrib[v]++;
            contrib[lc]--;
            if(lc!=root) contrib[par[lc]]--;
        }
        dfs3(root,-1);
        dfs4(root,-1,A);
        put(min(dp[root][0],dp[root][1]))
    }

    return 0;
}
