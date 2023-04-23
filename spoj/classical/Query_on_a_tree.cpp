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
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define rep(N) FOR(i,0,N)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define take(x) cin >> x;
#define take2(x,y) cin >> x >> y;
#define take3(x,y,z) cin >> x >> y >> z;

#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const LL MOD = 1e9+7;
const LL INF = 1e10+5;


// Segment Tree
const int N = 1e5;  // limit for array size
int n;  // array size, near power of two
LL t[2 * N]; // tree

int combine(int left,int right){return max(left,right);}

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void update(int p, const int value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

LL query(int l, int r) {
  LL resl=-INF, resr=-INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]); // l&1 mean l is right child, parent not included so shift to parent right
    if (r&1) resr = combine(t[--r], resr); // 
  }
  return combine(resl, resr);
}

// lca
int nn,l; // number of nodes, logn
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(nn);
    tout.resize(nn);
    timer = 0;
    l = ceil(log2(nn));
    up.assign(nn, vector<int>(l + 1));
    dfs(root, root);
}

// tree decomposition HLD
int parent[N],heavy[N],pos[N],head[N],depth[N];
int cur_pos;
unordered_map<LL,unordered_map<LL,LL>> cost;
int dfs(int u){
    int sz=1;
    int max_child = 0;
    trav(v,adj[u]){
        if(v==parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        int cz = dfs(v);
        sz +=cz;
        if(cz>max_child) {
            heavy[u] = v;
            max_child = cz;
        }
    }
    return sz;
}

void decompose(int u,int h){
    head[u] = h;
    pos[u] = cur_pos++;
    if(heavy[u]!=-1){
        int v = heavy[u];
        t[n + cur_pos] = cost[u][v];
        decompose(v,h);
    }
    trav(v,adj[u]){
        if(v==parent[u] || v==heavy[u]) continue;
        t[n + cur_pos] = cost[u][v];
        decompose(v,v);

    }
}
// make a and b belong to same chain
LL query_up(int a,int b){
    LL res = 0;
    while(head[a]!=head[b]){
        if(depth[a]>depth[b]) swap(a,b);
        res = max(res,query(pos[head[b]],pos[b]+1) );
        b = parent[head[b]];
    }
    if(depth[a]>depth[b]) swap(a,b);
    res = max(res,query(pos[a],pos[b]+1));
    return res;
}
void init(int root){
    nn = adj.size();
    n = (1<<(1+(int)log2(nn + 0.0)));
    cur_pos = 0;
    memset(heavy,-1,sizeof heavy);
    preprocess(root); // lca
    dfs(root); 
    decompose(root,root); // hld 
    build(); // segment tree
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        cin >> nn;
        adj.assign(nn,vector<int>());
        rep(nn-1){
            LL a,b,c;
            take3(a,b,c);
            --a;--b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a][b] = c;
            cost[b][a] = c;
        }
        init(0);
        while(1){
            string s;
            cin >> s;
            if(s=="DONE") break;
            int a,b;
            cin >> a >> b;
            if(s=="QUERY"){
                int l = lca(--a,--b);
                LL mx = query_up(l,a);
                mx = max(mx,query_up(l,b));
                put(mx);
            }
            else{
                update(n+pos[a-1],b);
            }
            
        }
    }

    return 0;
}
