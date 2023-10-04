// Problem: E. Great Grids
// Contest: Codeforces - Codeforces Round 884 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1844/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int n,m;
int to(int i,int j){
	return i*m + j;
}
vector<int> color;
bool dfs(int u,int c,vector<vector<pair<int,int>>> &adj){
	color[u] = c;
	debug("called ",u,c);
	trav(ed,adj[u]){
		if(color[ed.first]!=-1){
			if((ed.second^(c==color[ed.first]))==0) {
				color[u] = -1;
				return false;}
		}
		else{
			if(!ed.second){
				if(!dfs(ed.first,c,adj)){color[u] =-1; return false;}
			}
			else{
				int any = 0;
				rep(m,0,3){
					if(m==c) continue;
					if(dfs(ed.first,m,adj)) {any=1;break;}
				}
				if(!any){color[u] =-1; return false;}
			}
		}
	}
	debug(u,c);
	return true;
}
void testcase(){
    int k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n*m + 1);
    rep(i,0,k){
    	int i1,j1,i2,j2;
    	cin >> i1 >> j1 >> i2 >> j2;
    	--i1;--j1;--i2;--j2;
    	adj[to(i1,j1)].push_back({to(i2,j2),0});
		adj[to(i2,j2)].push_back({to(i1,j1), 0} );
    	
    }
    rep(i,0,n*m){
    	if((i+1)%m){
    	adj[i].push_back({i+1,1});
    	adj[i+1].push_back({i,1});
    		
    	}
    	if(i+m<n*m){
    	adj[i].push_back({i+m,1});
    	adj[i+m].push_back({i,1});		
    	}
    	if((i+m+1)%m and (i+m+1)<m*n and find(all(adj[i]),make_pair(i+m+1,0))==adj[i].end()){
    		adj[i].push_back({i+m+1,1});
    	adj[i+m+1].push_back({i,1});	
    	}
    
    }

    debug(adj[1]);
    color.resize(n*m,-1);
    bool res =1;
    rep(i,0,n*m){
    	if(color[i]==-1)
    	 {
    	 	if(!(dfs(i,0,adj))) {
    	 		debug(i,res);
    	 		res=0;break;
    	 		}
    	 	
    	 	}
    	
    }
    debug(color,res);
    cout << (res ? "YES" : "NO" )<< endl;
    
    
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
