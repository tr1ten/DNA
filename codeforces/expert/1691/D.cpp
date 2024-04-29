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
#define ss second
#define ff first
#define int ll
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
// void __print(long long x) {cerr << x;}
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
#define inf 0x3f3f
 

const int N = 200000 + 5;
int a[N];
struct node {
	int sum, res, pre, suf;
	node() {}
	node(int val) {
		sum = res = pre = suf = val;
	}
};
int n, m, s, e;
node seg[N * 4];

node merge(node left, node right) {
	node ret;
	ret.sum = left.sum + right.sum;
	ret.pre = max(left.pre, left.sum + right.pre);
	ret.suf = max(right.suf, right.sum + left.suf);
	ret.res = max(left.res, max(right.res, left.suf + right.pre));
	return ret;
}

void build(int at, int l, int r) {
	if(l == r) {
		seg[at] = node(a[l]);
		return;
	}

	int m = (l + r) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, r);
	seg[at] = merge(seg[at * 2], seg[at * 2 + 1]);
}

node get(int at, int l, int r) {
	if(l > e || r < s)
		return node(-10000000000);
 
	if(l >= s && r <= e)
		return seg[at];
 
	int m = (l + r) / 2;
	return merge(get(at * 2, l, m), get(at * 2 + 1, m + 1, r));
}

void testcase(){
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	rep(i,0,4*n+1) {
		node nd;
		seg[i] = nd;
		
	}
	build(1,1,n);
	s=1,e=n;
	stack<int> st;
	vi suff(n,n);
	per(i,0,n) {
		while(st.size() && a[1+st.top()]<=a[i+1]) {
			st.pop();
		}
		if(st.size()) suff[i] = st.top();
		st.push(i);
	}
	while(st.size()) st.pop();
	vi pref(n+1);
	rep(i,0,n) {
		pref[i+1] = pref[i] + a[i+1];
	}
	rep(i,0,n) {
		while(st.size() && a[1+st.top()]<=a[1+i]) {
			st.pop();
		}
		int p = -1;
		if(st.size()) p = st.top();
		s=p+2,e=i+1;
		ll mxl = max(pref[e]-pref[s-1],get(1,1,n).suf);
		debug(s,e,mxl);
		s=i+1,e=suff[i];
		ll mxr =max( get(1,1,n).pre,pref[e]-pref[s-1]);
		debug(s,e,mxr);
		ll mx = mxl+mxr-a[i+1];
		debug(i,mx,mxl,mxr,p);
		if(mx>a[i+1]) {
			// debug(i,s,e,mx);
			pyn(0);
			return;
		}
		st.push(i);
	}
	pyn(1);
	
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