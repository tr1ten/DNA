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
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    vi p1(n+1),p2(n+2),p3(n+2);
    rep(i,0,n){
        p1[i+1] += p1[i] + a[i];
    }
    
    p2[0] = 0;
    rep(i,0,n){
        p2[1] += a[i]*(n-i);
    }
    rep(i,2,n+1){
        p2[i] = p2[i-1] - (a[i-2]*(n-(i-2)));
    }
    rep(i,1,n+1){
        p3[i] += p3[i-1] + p2[i];
    }
    auto get_sm = [&](int i,int x) {
        if(i<0 || x<=0) return 0LL;
        int sm =  p2[i+1];
        int ex1 = p2[i+x+1] ;
        int ex2 = (n-(i+x))*(p1[i+x]-p1[i]);
        debug(i,x,sm,ex1,ex2);
        return sm-ex1-ex2;
    };
    auto get_cnt = [&](int mid) {
        if(mid<0) return 0LL;
        return (mid+1)*n - (mid*(mid+1))/2;
    };
    
    debug(a,p1,p2,p3);
    int q;
    cin >> q;
    rep(o,0,q){
        int l,r;
        cin >> l >> r;
        int lo=0,hi = n-1;
        int i=0;
        while (lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(get_cnt(mid) >= l){
                i = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        
        lo=0,hi = n-1;
        int j=0;
        while (lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(get_cnt(mid) >= r){
                j = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        int res = p3[j+1]-p3[i] ;
        int jrm = p2[j+1] - get_sm(j,n-j-(get_cnt(j)-r));
        int irm = get_sm(i,l-get_cnt(i-1)-1);
        // debug(i,j,res,jrm,irm);
        put(res-irm-jrm);
        
    }
    
    
    
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
