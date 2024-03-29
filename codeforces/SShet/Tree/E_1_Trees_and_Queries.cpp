// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("fast-math") 
 
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
typedef int LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
typedef unordered_map<LL,unordered_map<LL,LL>> UPO;
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
#define put(x) cout<<x<<endl;
#define put2(x,y) cout<<x<<" "<<y<<endl;
#define put3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const int MAXN = 2*1e5;
bool mark[MAXN+1];
int anc[MAXN+1];
int depth[MAXN+1];
class DSU
{
public:
    int *par;
    int *sz;
    int cnt;
    DSU(int n)
    {
        this->par = new int[n];
        this->sz = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->par[i] = i;
            this->sz[i] = 1;
        }
        this->cnt = n;
    }
    int find(int x)
    {
        int p = x;
        while (p != this->par[p])
        {
            p = par[p];
        }
        return p;
    }
    void unionn(int u, int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if (rootu == rootv)
            return;
        if (sz[rootu] < sz[rootv])
        {
            par[rootu] = rootv;
            sz[rootv] += sz[rootu];
        }
        else
        {
            par[rootv] = rootu;
            sz[rootu] += sz[rootv];
        }
        this->cnt--;
    }
};


void dfs(int u,VII &adj,DSU &dsu,VII &queries,UPO &ans){
    mark[u] = true;
    anc[u] = u;
    trav(v,adj[u]){
        if(!mark[v]){
            dfs(v,adj,dsu,queries,ans);
            dsu.unionn(u,v);
            anc[dsu.find(u)] = u;
            
        }
    }
    trav(v,queries[u]){
        if( mark[v]) ans[v][u] = ans[u][v] = anc[dsu.find(v)];
    }
}

void dfs2(int u,VII &adj,int d){
    depth[u] =  d;
    mark[u] = true;
    trav(v,adj[u]){
        if(!mark[v]) dfs2(v,adj,d+1);
    }
}
struct Q{
    int x;
    int y;
    int u;
    int v;
    LL k;
};
LL dist(int x,int y,UPO &ans){
    int lca= ans[x][y];
    return (depth[x]+depth[y]-2*depth[lca]);

}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--){
        int n;
        cin >> n ;
        VII adj(n);
        FOR(i,1,n){
            int u,v;
            cin >> u>> v;
            v--;u--;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int q;
        cin >> q;
        VII queries(n);
        vector<Q> qu;
        FOR(i,0,q){
            int x,y,u,v;
            LL k;
            cin >> x >> y >> u >> v >> k;
            u--;v--;x--;y--;
            queries[u].push_back(v);
            queries[v].push_back(u);
            queries[u].push_back(x);
            queries[x].push_back(u);
            queries[u].push_back(y);
            queries[y].push_back(u);
            queries[v].push_back(x);
            queries[x].push_back(v);
            queries[v].push_back(y);
            queries[y].push_back(v);
            qu.push_back({x,y,u,v,k});
        }
        fill(begin(mark),end(mark),false);
        DSU dsu(n); 
        UPO ans;
        dfs(0,adj,dsu,queries,ans);
        fill(begin(mark),end(mark),false);
        dfs2(0,adj,0);
        trav(p,qu){
            bool f=0;
            LL d1 = dist(p.u,p.v,ans);
            if(p.k >= d1 && (p.k-d1)%2==0) f =1;
            LL d21 = dist(p.u,p.x,ans);
            LL d22 = dist(p.v,p.y,ans);
            if((p.k >= d22+d21+1) && (p.k-d22-d21-1)%2==0) f=1;
            d21 = dist(p.u,p.y,ans);
            d22 = dist(p.v,p.x,ans);
            if((p.k >= d22+d21+1) && (p.k-d22-d21-1)%2==0) f=1;
            if(f) put("YES")
            else put("NO");
        }
    }

    return 0;
}
