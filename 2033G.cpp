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
typedef unsigned long long ull; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll,custom_hash> mll;
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define int long long
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
const ll MOD = 1e9+7; // change me for god sake look at problem mod
const ll INF = 1e16+5;

inline int ctz(ll x) { return __builtin_ctzll(x);}
inline int clz(ll x) {return __builtin_clzll(x);}
inline int pc(ll x) {return  __builtin_popcount(x);} 
inline int hset(ll x) {return __lg(x);}
void pyn(int x) {put(x?"YES":"NO");}
// do not use unordered map use mll
const int N = 2*(1e5) + 5;
int n; // MAKE SURE TO INITIALIZE THIS TO SIZE OF ARRAY
struct Segment{
    ll sum=-INF;
} segm[4*N]; // 0 index
Segment combine(Segment left,Segment right){
    Segment res;
    res.sum = max(left.sum ,right.sum);
    return res;
}

// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int i,ll value){
    if(left==i && right==i) {
            segm[node].sum = value;
        }
    else{
        int mid = (left+right)/2;
        if(i<=mid) update(2*node+1,left,mid,i,value);
        else update(2*node+2,mid+1,right,i,value);
        segm[node] = combine(segm[2*node+1] , segm[2*node+2]);
    }
    
}

Segment query(int node,int left,int right,int l,int r){
    if(left>=l && right<=r) {return segm[node];}
    int mid = (left+right)/2;
    Segment res;
    if(l<=mid) res = combine(res,query(2*node+1,left,mid,l,r));
    if(r>mid) res = combine(res,query(2*node+2,mid+1,right,l,r));

    return res;
}
// everything is zero indexed
void update(int i,ll x){
    update(0,0,n-1,i,x);
}
Segment query(int l,int r){
    if(r<l) return {-INF};
    return query(0,0,n-1,l,r);
}
vpi deps;
vii adj;
void dfs(int u,int p){
    trav(v,adj[u]){
        if(v!=p){
            dfs(v,u);
            if(deps[u].first<deps[v].first+1){
                deps[u].second = deps[u].first;
                deps[u].first = deps[v].first+1;
            }
            else if(deps[u].second<deps[v].first+1){
                deps[u].second = deps[v].first + 1;

            }
        }
    }
}
vector<vpi> queries;
vi res;
void dfs2(int u,int p, int d){
    trav(v,queries[u]){
        int d1 = query(max(0LL,d-v.first),d-1).sum;
        debug(u,v,d1);
        res[v.second] = max(d1+d,deps[u].first);
    }
    trav(v,adj[u]){
        if(v!=p){
            int d2 = deps[u].first==deps[v].first+1 ? deps[u].second : deps[u].first;
            update(d,d2-d);
            debug(d,d2-d);
            dfs2(v,u,d+1);
        }
    }
}
void testcase(){
    cin >> n;
    deps.clear();
    deps.resize(n);
    adj.clear();
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].pb(u);
    }
    int q;
    cin >> q;
    queries.clear();
    queries.resize(n);
    res.clear();
    res.resize(q);
    rep(i,0,q){
        int x,s;
        cin >> x >> s;
        x--;
        queries[x].push_back({s,i});
    }
    rep(i,0,n){
        update(i,-INF);
    }
    dfs(0,-1);
    dfs2(0,-1,0);
    pvc(res);

}
// driver code
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
