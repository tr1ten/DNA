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
struct sum_kth_smallest {
 
	struct Node {
		long long sum;
		int cnt;
		int lCh, rCh;//children, indexes into `tree`
	};
 
	int mn, mx;
	vector<int> roots;
	deque<Node> tree;
 
	sum_kth_smallest(const vector<int>& arr) : mn(INF), mx(-INF), roots(arr.size() + 1, 0) {
		tree.push_back({0, 0, 0}); //acts as null
		for (int val : arr) mn = min(mn, val), mx = max(mx, val);
		for (int i = 0; i < (int)arr.size(); i++)
			roots[i + 1] = update(roots[i], -mx, mx, arr[i]);
	}
	int update(int v, int tl, int tr, int idx) {
		if (tl == tr) {
			tree.push_back({tree[v].sum + tl, tree[v].cnt + 1, 0, 0});
			return tree.size() - 1;
		}
		int tm = tl + (tr - tl) / 2;
		int lCh = tree[v].lCh;
		int rCh = tree[v].rCh;
		if (idx <= tm)
			lCh = update(lCh, tl, tm, idx);
		else
			rCh = update(rCh, tm + 1, tr, idx);
		tree.push_back({tree[lCh].sum + tree[rCh].sum, tree[lCh].cnt + tree[rCh].cnt, lCh, rCh});
		return tree.size() - 1;
	}
 
 
	/* find kth smallest number among arr[l], arr[l+1], ..., arr[r]
	 * k is 1-based, so find_kth(l,r,1) returns the min
	 */
	int query(int l, int r, int k) const {
		assert(1 <= k && k <= r - l + 1); //note this condition implies L <= R
		assert(0 <= l && r + 1 < (int)roots.size());
		return query(roots[l], roots[r + 1], -mx, mx, k);
	}
	int query(int vl, int vr, int tl, int tr, int k) const {
		if (tl == tr)
			return tl;
		int tm = tl + (tr - tl) / 2;
		int left_count = tree[tree[vr].lCh].cnt - tree[tree[vl].lCh].cnt;
		if (left_count >= k) return query(tree[vl].lCh, tree[vr].lCh, tl, tm, k);
		return query(tree[vl].rCh, tree[vr].rCh, tm + 1, tr, k - left_count);
	}
 
	/* find **sum** of k smallest numbers among arr[l], arr[l+1], ..., arr[r]
	 * k is 1-based, so find_kth(l,r,1) returns the min
	 */
	long long query_sum(int l, int r, int k) const {
		assert(1 <= k && k <= r - l + 1); //note this condition implies L <= R
		assert(0 <= l && r + 1 < (int)roots.size());
		return query_sum(roots[l], roots[r + 1], -mx, mx, k);
	}
	long long  query_sum(int vl, int vr, int tl, int tr, int k) const {
		if (tl == tr)
			return 1LL * tl * k;
		int tm = tl + (tr - tl) / 2;
		int left_count = tree[tree[vr].lCh].cnt - tree[tree[vl].lCh].cnt;
		long long left_sum = tree[tree[vr].lCh].sum - tree[tree[vl].lCh].sum;
		if (left_count >= k) return query_sum(tree[vl].lCh, tree[vr].lCh, tl, tm, k);
		return left_sum + query_sum(tree[vl].rCh, tree[vr].rCh, tm + 1, tr, k - left_count);
	}
};
 
 
int MA=1e9;
void testcase(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    tkv(a,n);
    rep(i,0,n) {a[i] += MA;}
    debug(a);
    sum_kth_smallest st(a);
    rep(i,0,q){
        int k;
        cin >> k;
        int r = (k==1) ? 0 : st.query_sum(0,k-1,k/2) ;
        int sm = st.query_sum(0,k-1,k) - 2*r;
        sm -= k%2 ? MA : 0;
        cout << (sm) << " ";
    }
    cout << endl;
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
