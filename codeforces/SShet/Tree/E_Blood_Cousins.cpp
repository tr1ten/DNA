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
#define mk_mat(name,n,m,value) vector<vi> name(n, vi(m, value))
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
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;

int n, l; // nodes, logn
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
void dfs(int v, int p,int d)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[v][i-1]>0 ? up[up[v][i-1]][i-1] : -1 ;

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,d+1);
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
        if (!is_ancestor(up[u][i], v)) // similar to exhaustive binary search 
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess() {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1,-1));
    rep(i,0,n){
        if(up[i][0]==-1) dfs(i, -1,0);
    }
}
int parent(int u,int k){
    int v = u;
    per(i,0,32){
        if(k&(1<<i)) v = up[v][i];
        if(v==-1) return -1;
        if(v==up[v][0]) break;
    }
    return v;
}
struct Q{
    int ni;
    int pi;
};
void dfs(int u,int p,int d,mll &dept,vector<unordered_map<int,int>> &ques){
    dept[d]++;
    trav(q,ques[u]){
        ques[u][q.first] -= dept[d+q.first];
    }
    trav(v,adj[u]){
        if(v==p) continue;
        dfs(v,u,d+1,dept,ques);
    }
    trav(q,ques[u]){
        ques[u][q.first] += dept[d+q.first];
    }


}
int main(int argc, char const *argv[])
{
    // assign adj list
    cin >> n;
    adj.resize(n);
    rep(i,0,n){
        int x;
        cin >> x;
        if(x==0) continue;
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    // max move to k steps 
    int root = 0;
    preprocess();
    int q;
    cin >>q;
    vector<Q> qi;
    vector<unordered_map<int,int>> ques(n);
    rep(i,0,q){
        int ni,pi;
        cin >> ni >> pi;
        ni--;
        int tar = parent(ni,pi); 
        if(tar!=-1) ques[tar][pi] = 0;
        qi.push_back({tar,pi});
    }
    rep(i,0,n){
        mll dept;
        if(up[i][0]==-1) {
            dept.clear();
            dfs(i,-1,0,dept,ques);
        }
    }
    trav(q,qi){
        if(q.ni==-1) cout << 0 << " ";
        else {
            cout << (ques[q.ni][q.pi]-1) << " ";
        }
    }
    cout << endl;



    return 0;
}
