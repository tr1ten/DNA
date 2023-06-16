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
typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) vi name(sz,value)
#define mk_mat(name,n,m,value) vector<vi> name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define mod(x) (x + MOD)%MOD
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;

int n, l; // nodes, logn
vector<vector<pi>> adj;

int timer;
vector<int> tin, tout;
vector<vector<pi>> up;
vector<int> depth;
void dfs(ll v, pi p,int d)
{
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;
    for (int i = 1; i <= l; ++i)
        up[v][i] = mp(up[up[v][i-1].first][i-1].first,min(up[up[v][i-1].first][i-1].second,up[v][i-1].second));

    for (auto u : adj[v]) {
        if (u.first!= p.first)
            dfs(u.first, mp(v,u.second),d+1);
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
        return  v;
    ll mn = INF;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i].first, v)) // similar to exhaustive binary search 
            u = up[u][i].first;
    }
    return up[u][0].first;
    }

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<pi>(l + 1));
    dfs(root, mp(root,INF),0);
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        int m;
        cin >> n >> m;
        adj.resize(n);
        rep(i,0,m){
            ll u,v;
            ll e;
            cin >> u >> v >> e;
            u--;v--;
            adj[u].push_back(mp(v,e));
            adj[v].push_back(mp(u,e));
        }
        preprocess(0);
        int q;
        cin >> q;
        rep(i,0,q){
            int u,v;
            cin >> u >> v;
            u--;v--;
            int lc = lca(u,v);
            ll mn1 = INF;
            rep(i,0,32){
                if(!is_ancestor(u,lc)){
                    mn1 = min(up[u][i].second,mn1);
                    u = up[u][i].first;
                }
            }
            if(u!=lc) mn1 = min(mn1,up[u][0].second);
            ll mn2 = INF;
            rep(i,0,32){
                if(!is_ancestor(v,lc)){
                    mn2 = min(up[v][i].second,mn2);
                    v = up[v][i].first;
                }
            }
            if(v!=lc) mn2 = min(mn2,up[v][0].second);
            put(min(mn1,mn2));
        }

    }

    return 0;
}
