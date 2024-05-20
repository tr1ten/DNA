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
struct TP {
    int l,r,c,i;
};
bool operator<(const TP &a,const TP &b){
    return a.l < b.l;
}

void solve(vector<TP> &a,vi &res){
    int mxi = 0;
    int mx2i= -1;
    set<pi> mx;
    mx.insert({a[0].r,0});
    set<pi> mx2;
    rep(i,1,a.size()){
        int ami = mxi;
        if(a[ami].c==a[i].c) ami = mx2i;
        debug(i,a[i].i,a[i].c,mxi,mx2i,ami,mx,mx2);
        assert(mx2i==-1 || a[mx2i].c!=a[mxi].c);
        if(ami!=-1){
            assert(a[ami].c!=a[i].c);
            if(a[ami].r>=a[i].l) {
                res[a[i].i] = 0;
                auto &sss = ami == mxi ? mx : mx2;
                while (sss.size())
                {
                    if((*sss.begin()).first>=a[i].l){
                        res[a[(*sss.begin()).second].i] = 0; 
                    }
                    sss.erase(sss.begin());
                }
            }
            else res[a[i].i] = min(res[a[i].i],a[i].l-a[ami].r);
        }
        if(a[mxi].r < a[i].r){
            if(a[mxi].c!=a[i].c) {
                if(a[mx2i].c!=a[mxi].c) mx2.clear();
                mx2i = mxi;
                mx2.insert({a[mx2i].r, mx2i});
            }
            if(a[i].c!=a[mxi].c) mx.clear();
            mxi =i;
            mx.insert({a[i].r,mxi});
        }
        else if((mx2i==-1 || a[i].r>a[mx2i].r) && a[mxi].c!=a[i].c){
            if(a[mx2i].c!=a[i].c) mx2.clear();
            mx2i=i;
            mx2.insert({a[mx2i].r, mx2i});
        }
        else{
        if(a[i].c==a[mxi].c) mx.insert({a[i].r,i});
        if(a[i].c==a[mx2i].c) mx2.insert({a[i].r,i});
        }
    }
}
void testcase(){
    int n;
    cin >> n;
    vector<TP> a(n);
    vector<TP> b(n);
    
    rep(i,0,n){
        int l,r,c;
        cin >> a[i].l >> a[i].r >> a[i].c;
        a[i].i = i;
        b[i].r=-a[i].l;b[i].l=-a[i].r;b[i].c=a[i].c;b[i].i=a[i].i;
    }
    srv(a);
    srv(b);
    vi res(n,INF);
    solve(a,res);
    debug(res);
    solve(b,res);
    debug(res);

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
