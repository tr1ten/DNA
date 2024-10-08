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
const ll INF = 1e17+5;

inline int ctz(ll x) { return __builtin_ctzll(x);}
inline int clz(ll x) {return __builtin_clzll(x);}
inline int pc(ll x) {return  __builtin_popcount(x);} 
inline int hset(ll x) {return __lg(x);}
void pyn(int x) {put(x?"YES":"NO");}
// do not use unordered map use mll

const int N = 150005;

int a[N],bb[N],c[N],d[N];
void testcase(){
    int n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    tkv(a,n1);
    tkv(bb,n2);
    tkv(c,n3);
    tkv(d,n4);
    int m1;
    cin >> m1;
    vector<unordered_set<int>> ab(n1);
    vector<unordered_set<int>> bc(n2);
    vector<unordered_set<int>> cd(n3);
    rep(i,0,m1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        ab[u].insert(v);
    }
    int m2;
    cin >> m2;
    rep(i,0,m2){
        int u,v;
        cin >> u >> v;
        --u;--v;
        bc[u].insert(v);
    }
    int m3;
    cin >> m3;
    rep(i,0,m3){
        int u,v;
        cin >> u >> v;
        --u;--v;
        cd[u].insert(v);
    }
    vi indb(n2),indc(n3),indd(n4);
    iota(all(indb),0);
    iota(all(indc),0);
    iota(all(indd),0);
    sort(all(indd),[&](int i,int j) {
        return d[i] < d[j];
    });
    
    vi dp23(n2,INF),dp34(n3,INF);
    rep(i,0,n3){
        
        int j = 0;
        while(j<n4 && cd[i].count(indd[j])){j++;}
        if(j<n4){
            dp34[i] = d[indd[j]] + c[i];
        }
        debug(i,dp34[i],j,cd[i]);
    }
    sort(all(indc),[&](int i,int j) {
        return dp34[i] < dp34[j];
    });
    
    rep(i,0,n2){
        int j = 0;
        while(j<n3 && bc[i].count(indc[j])){j++;}
        if(j<n3){
            dp23[i] = dp34[indc[j]] + bb[i];
        }
        debug(i,dp23[i],j,bc[i]);
    }
    sort(all(indb),[&](int i,int j) {
        return dp23[i] < dp23[j];
    });
    int ans = INF;
    rep(i,0,n1){
        int j = 0;
        while(j<n2 && ab[i].count(indb[j])){j++;}
        if(j<n2){
            int dp = dp23[indb[j]] + a[i];
            ans = min(ans,dp);
        }
    }
    if(ans<INF) put(ans)
    else put(-1)
    
    
    
}
// driver code
int32_t main()
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
