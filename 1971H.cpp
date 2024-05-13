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
namespace SS {
    vector<int> ids;
    vector<int> low;
    vector<bool> onStack;
    stack<int> st;
    vector<vector<int>> g;
    vector<bool> sols;
    int n=0;
    int n_terms=0;
    int timer;
    void dfs(int u){
        onStack[u] = 1;
        st.push(u);
        ids[u] = low[u] = timer++;
        for(int v:g[u]){
            if(ids[v]==-1) dfs(v);
            if(onStack[v]) low[u] = min(low[u],low[v]); // maintain stack invariant, only include node in scc
        }
        if(low[u]==ids[u]){
            while(!st.empty()) {
                int v = st.top();
                onStack[v] = 0;
                low[v] = low[u];// once scc completed, reset back to start
                st.pop();
                if(v==u) break;

            } 
        }
    }
    void stronglyConnectedComponents()
    {
        timer=0;
        ids.resize(n);
        fill(ids.begin(),ids.end(),-1);
        onStack.clear();
        onStack.resize(n);
        low.resize(n);
        for(int i=0;i<n;i++){
            if(ids[i]==-1){
                dfs(i);
            }
        }
    }
    // 1. call me to initialize graph
    void init(int terms) {
        n_terms = terms;
        n = 2*terms;
        g.clear();
        g.resize(n);
        sols.clear();
        sols.resize(n);
    }
    // ensure the equation is in CNF, eg (PvQ) ^ (~PvQ) ^ ... OR AND OR AND 
    void add_impl(int i,int j){
        g[i].push_back(j);
    }
    int neg(int i){
        if(i<n_terms){
            return i+n_terms;
        }
        return i-n_terms;
    }
    void add_or(int i,int j){
        add_impl(neg(i),j);
        add_impl(neg(j),i);
    }
    void make_equal(int i,int j) {
        add_or(neg(i),j);
        add_or(i,neg(j));
    }

    void add_xor(int i,int j){
        add_or(i,j);
        add_or(neg(i),neg(j));
    }
    void force_var(int i){
        add_impl(i,i);
    }
    // 1. call me to get ans
    bool solve(){
        stronglyConnectedComponents();
        for(int i=0;i<n_terms;i++){
            if(low[i]==low[neg(i)]) return false;
            sols[i] = low[i] > low[neg(i)]; // i am not sure if this works, can use reverse topo as well but since this is same as ordering so should work
        }
        return true;
    }
}

void testcase(){
    int n;
    cin >>n;
    SS::init(n);
    vii mat(3,vi(n));
    rep(i,0,3){
        rep(j,0,n){
            cin >> mat[i][j];
            if(mat[i][j]<0) {
                mat[i][j] = abs(mat[i][j]);
                mat[i][j]--;
                mat[i][j] = SS::neg(mat[i][j]);
            }
            else mat[i][j]--;
        }
    }
    rep(i,0,n){
        rep(j,0,3){
            rep(k,j+1,3){
                int a=mat[j][i],b=mat[k][i];
                SS::add_or(a,b);
            }
        }
    }
    pyn(SS::solve());
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
