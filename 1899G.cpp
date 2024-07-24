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
vii adj;
// https://cses.fi/problemset/result/9393258/
template <typename T> 
class segtree{
    struct Node
    {
        Node *left,*right;
        T val;
        Node(T v,Node *lp=nullptr,Node* rp=nullptr): val(v), left(lp), right(rp) {}
    };
    public:
        int n;
        T basev;
        vector<Node *> roots;
        segtree() {}
        segtree(int _n,T _bv): n(_n),basev(_bv)  {
            roots.push_back(this->_build(0,n-1));
        };
        // Make sure to save node in roots when updating
        Node* update(int index,T new_val,int time=0) {
            assert(index<n);assert(time<roots.size());
            return _update(roots[time],0,n-1,index,new_val);
        }
        T query(int lq,int rq,int time=0){
            assert(lq>=0);assert(rq<n);assert(lq<=rq);assert(time<roots.size());
            return _query(roots[time],0,n-1,lq,rq);
        }

    private:
        T merge(T a,T b) {
            return a+b;
        }
        Node *_build(int l,int r){
            if(l>r) return nullptr;
            Node *node = new Node(this->basev);
            if(l==r) return node;
            int mid = (l+r) >> 1;
            node->left = _build(l,mid);
            node->right = _build(mid+1,r);
            return node;
        }

        Node *_update(Node *node,int l,int r,int ind,T new_val) {
            if(l>r) return nullptr;
            if(ind<l || ind>r) return node;
            Node *_node = new Node(node->val,node->left,node->right);
            if(l==r) {_node->val = new_val; }
            else {
                int mid = (l+r)/2;
                if(ind<=mid)  _node->left = _update(node->left,l,mid,ind,new_val);
                else _node->right = _update(node->right, mid+1,r,ind,new_val);
                _node->val = merge((_node->left)->val,_node->right->val);
            }
            return _node;
        }
        T _query(Node *node, int l,int r, int lq,int rq) {
            if(r<lq || l>rq) return this->basev;
            if(l>=lq && r<=rq)  return node->val;
            int mid = (l+r)/2;
            return merge(_query(node->left,l,mid,lq,rq),_query(node->right,mid+1,r,lq,rq));
        }
};
// int main(int argc, char const *argv[])
// {
//     segtree<int> s(10,0);
//     for(int i=1;i<10;i++){ s.roots[0]= s.update(i,i+1); cout << i << " sum " << (s.query(i-1,i)) << endl;}
    
//     return 0;
// }
int timer=0;
const int N = 1e5 + 5;
int start[N],ed[N];
int rev[N];
// 2 values for start and end, for path queries 

void dfs(int u,int p){
    rev[timer] = u;
    start[u] = timer++;
    trav(v,adj[u] ) {
        if(v==p) continue;
        dfs(v,u);
    }
    ed[u] = timer;

}

void testcase(){
    int n,q;
    cin >> n >> q;
    timer=0;
    adj.clear();
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi p(n);
    rep(i,0,n){
        int x;
        cin >> x;
        x--;
        p[x] = i;
    }
    dfs(0,-1);
    segtree<int> seg(n,0);
    rep(i,0,timer){
        seg.roots.push_back(seg.update(p[rev[i]],1,i));
    }
    rep(i,0,q){
        int l,r,x;
        cin >> l >> r >> x;
        l--;r--;x--;
        int lc = seg.query(l,r,start[x]);
        int rc = seg.query(l,r,ed[x]);
        pyn(lc<rc);
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
