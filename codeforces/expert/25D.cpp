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
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
// gp_hash_table<int, int, chash> table;
template <class K, class V>

using ht = gp_hash_table<

    K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>,

    hash_standard_resize_policy<hash_exponential_size_policy<>,

                                hash_load_check_resize_trigger<>, true>>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// ht<int, null_type> g;

typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll,custom_hash> mll;
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

inline int ctz(ll x) { return __builtin_ctzll(x);}
inline int clz(ll x) {return __builtin_clzll(x);}
inline int pc(ll x) {return  __builtin_popcount(x);} 
inline int hset(ll x) {return __lg(x);}
void ans(int x) {put(x?"YES":"NO");}
// do not use unordered map use mll
#include <bits/stdc++.h>
using namespace std;
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
         cnt= n;
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
    void connect(int u, int v)
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
        cnt--;
    }
};


const int N = 1e3 + 5;
vector<set<int>> adj;
int av[N]; // arrival
int low[N]; // lowest id reachable from current node
bool vis[N];
int n;
unordered_map<int,unordered_map<int,bool>> bridge;
int timer=0;
void dfs(int u,int p, set<pair<int,int>> &edges){
    av[u] = low[u] = timer++;
    vis[u]  = 1;
    for(auto v:adj[u]){
        if(v==p) continue;
        if(!vis[v]) dfs(v,u,edges);
        low[u] = min(low[v],low[u]);
        if(low[v]>av[u]){
            if(edges.find({min(u,v),max(u,v)}) != edges.end()) edges.erase(edges.find({min(u,v),max(u,v)}));
        }
    }
}
void not_bridge(set<pair<int,int>> &edges){
    adj.clear();
    adj.resize(n);
    trav(x,edges){
        adj[x.first].insert(x.second);
        adj[x.second].insert(x.first);
    }
    memset(vis,0,sizeof vis);
    memset(low,0,sizeof low);
    memset(av,0,sizeof av);
    timer = 0;
    rep(i,0,n){
        if(!vis[i]){
            dfs(i,-1,edges);
        }
    }
}
void testcase(){
    cin >> n;
    DSU ds(n);
    set<pair<int,int>> edges;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        edges.insert({min(u,v),max(u,v)});
        ds.connect(u,v);
    }
    cout << ds.cnt-1 << endl;
    rep(i,0,n){
        rep(j,i+1,n) {
            if(ds.find(i)!=ds.find(j)){
                auto ne = edges;
                not_bridge(ne);
                if(ne.size()==0) {debug(edges,ne);}
                assert(ne.size());
                auto p = *ne.begin();
                edges.erase(edges.find(p));
                edges.insert({i,j});
                cout << p.first+1 << " " << p.second+1 << " " << i+1 << " "<< j+1 << endl;
                ds.connect(i,j);
            }
        }
    }

}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    // cin>>T;
    while(T--) testcase();

    return 0;
}