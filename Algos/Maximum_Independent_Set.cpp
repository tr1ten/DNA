

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
ll popmax(ll x,ll y){
    return __builtin_popcountll(x) < __builtin_popcountll(y) ? y : x;
}
// maximum clique problem O(2^n)
// max possible completed subgraph

void max_clique(int n1,int shift,vector<ll> a,vector<ll> &f){
    for(ll mask=1;mask<1ll<<n1;mask++){
        for(int i=0;i<n1;i++){
            if((mask&(1LL<<i))==0) continue; // important! precedance
            ll sub = mask^(1ll << i);
            f[mask] = popmax(f[mask],f[sub & (a[i+shift]>>shift)] | (1ll<<i) );
        }
    }
}

void print_mask(ll mask,int n){
    for(int i=0;i<n;i++){
        if(mask&(1LL<<i)) cout<< i << " ";
    }
    cout << endl;
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
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<ll> a(n);
        rep(i,0,m){
            int u,v;
            cin >> u >> v;
            a[u] |= 1ll << v;
            a[v] |= 1ll << u;
        }
        ll amask = (1ll<<n) - 1;
        // complementary graph
        rep(i,0,n){
            a[i] ^= amask;
            a[i] ^= (1ll<<i);
        }
        int n1 = n/2;
        int n2 = n-n1;
        vector<ll> f1(1LL<<n1);
        vector<ll> f2(1LL<<n2);
        assert(n1<=20 && n2<=20);
        max_clique(n1,0,a,f1);
        max_clique(n2,n1,a,f2);
        // find subgraph of s1 connected with s2
        vector<ll> com(1LL<<n1);
        com[0] = (1ll<<n)-1;
        rep(mask,1,1LL<<n1){
            ll u  = (mask&(-mask));
            com[mask] = com[mask-u] & (a[__builtin_ctzll(mask)]);
        }
        ll ans = 0;
        // now for each S1 subgraph find complete grpah of both
        rep(mask,0,1ll<<n1){
            ans = popmax(ans,(f2[com[mask]>>n1]<<n1) | f1[mask]);            
        }
        put(__builtin_popcountll(ans));
        print_mask(ans,n);

    }

    return 0;
}
