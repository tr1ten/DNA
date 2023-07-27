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
#define mk_mat(name,n,m,value) vii name(n, vi(m, value))
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


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;

struct Edge
{
    int fx;
    int fy;
    int tx;
    int ty;
    int w;
};

bool operator<(Edge &a,Edge &b){
    return a.w < b.w;
}
template <int N>
struct disjoint_set {
    int par[N + 1];

    disjoint_set() { memset(par, -1, sizeof(par)); }

    int find(int v) { return par[v] < 0 ? v : par[v] = find(par[v]); }

    void join(int u, int v) {
        if ((u = find(u)) != (v = find(v))) {
            if (par[u] > par[v]) swap(u, v);
            par[u] += par[v], par[v] = u;
        }
    }
};


struct DSU
{
    vector<int> parent;
    vector<int> size;
    int mx;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i; // oath compression
        size.resize(n,1);
        mx = 1;
    }
    int find(int u){
        if(parent[u]!=u) parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u,int v){
        int ra = find(u);
        int rb = find(v);
        if(ra==rb) return 0;
        if(size[ra]<size[rb]) swap(ra,rb); // merge smaller to bigger tree
        size[ra] +=size[rb]; // union by rank
        parent[rb] = ra;
        mx = max(size[ra],mx);
        return 1;
    }
};


// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);	  
    int T=1;
    // cin>>T;
    while(T--){
        int n;
        cin >> n;
        int mat[n+1][n+1];
        rep(i,0,n){
            rep(j,0,n) cin >> mat[i][j];
        }
        vector<Edge> edges;
        rep(i,0,n){
            rep(j,0,n){
                if(i+1<n && mat[i+1][j] >= mat[i][j]) edges.push_back({i,j,i+1,j,mat[i+1][j] - mat[i][j] });
                if(i-1>=0 && mat[i-1][j] > mat[i][j]) edges.push_back({i,j,i-1,j,mat[i-1][j] - mat[i][j] });
                if(j+1<n && mat[i][j+1] >= mat[i][j]) edges.push_back({i,j,i,j+1,mat[i][j+1] - mat[i][j] });
                if(j-1>=0 && mat[i][j-1] > mat[i][j]) edges.push_back({i,j,i,j-1,mat[i][j-1] - mat[i][j] });
            }
        }
        srv(edges);
        DSU ds(n*n);
        int res = 0;
        trav(ed,edges){
            ds.unite(ed.fy*n + ed.fx,ed.ty*n + ed.tx);
            res = max(res,ed.w);
            if(ds.mx>=(n*n+1)/2) break;
        }
        put(res);
    }

    return 0;
}
