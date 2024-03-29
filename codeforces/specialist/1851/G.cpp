// Problem: G. Vlad and the Mountains
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/contest/1851/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

// ht<int, null_type> g;
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

inline int ctz(ll x) { return __builtin_ctzll(x);}
inline int clz(ll x) {return __builtin_clzll(x);}
inline int pc(ll x) {return  __builtin_popcount(x);} 
inline int hset(ll x) {return __lg(x);}
struct DSU
{
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i; // oath compression
        size.resize(n,1);
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
        return 1;
    }
};

struct Q{
	int a;
	int b;
	int e;
};

void testcase(){
    int n,m;
    cin >> n >> m;
    vi A(n);
    tkv(A,n);
    vpi edges;
    rep(i,0,m){
    	int u,v;
    	cin >> u >> v;
    	--v;--u;
    	edges.push_back({u,v});
    }
    sort(all(edges),[&](pi &a,pi &b){
    	return max(A[a.first],A[a.second])<max(A[b.second],A[b.first]);
    });
    int q;
    cin >> q;
    vector<Q> qs(q);
    rep(i,0,q){
    	cin >> qs[i].a >> qs[i].b >> qs[i].e;
    	qs[i].a--;
    	qs[i].b--;
    }
	vi sis(q);
	iota(all(sis),0);
	sort(all(sis),[&](int i,int j){
		return A[qs[i].a] + qs[i].e < A[qs[j].a] + qs[j].e;
	});
	vector<int> ans(q);
	DSU ds(n);
	int j = 0;
	// debug(edges,sis);
	trav(i,sis){
		while(j<m && max(A[edges[j].first],A[edges[j].second])<=A[qs[i].a]+qs[i].e){
			ds.unite(edges[j].first,edges[j].second);
			j+=1;
		}
		if(ds.find(qs[i].a) == ds.find(qs[i].b)) ans[i] = 1;
		else ans[i] = 0;
	}
	trav(x,ans){
		put(x?"YES":"NO");
	}
	put("");
}
// driver code
int main()
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
