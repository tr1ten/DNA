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
const int N = 1e6 + 5;
ll dist[N];
struct comp{
    bool operator()(int u,int v) const{
        if(dist[u]!=dist[v]) return dist[u]<dist[v];
        return u<v;
    }
};
// this is actually faster than original djistkra using priority queues
ll dijsktra(int S,vector<int> cont[],vector<vector<pair<int,ll>>> &adj){
    int n = adj.size();
    fill_n(dist,n,INF);
    dist[S] = 0;
    set<int,comp> pq;
    rep(i,0,n) pq.insert(i);
    while(!pq.empty()){
        int u = *pq.begin();
        pq.erase(pq.begin());
        if(u==n-1 || dist[u]==INF) return dist[n-1];
        auto it = lower_bound( all(cont[u]),(dist[u]));
        while(it!=cont[u].end() && (*it)==dist[u]){
            dist[u]++;
            it++;
        }
        rep(i,0,adj[u].size()){
            auto p  =adj[u][i];
            auto qi = pq.find(p.first);
            if(qi!=pq.end() && dist[p.first]>dist[u] + p.second){
                pq.erase(qi);
                dist[p.first] = dist[u] + p.second;
                pq.insert(p.first);
            }
        }
    }
    return INF; // or par according to needs
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    int D = n-1;
    int S = 0;
    vector<vector<pair<int,ll>>> adj(n);
    while(m--){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--;v--;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> cont[n];
    rep(i,0,n){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            cont[i].push_back(x);
        }
    }
    auto dist= dijsktra(0,cont,adj);
    if(dist<INF) put(dist)
    else put(-1)

    return 0;
}
