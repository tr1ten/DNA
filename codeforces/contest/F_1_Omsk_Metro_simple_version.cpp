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
typedef int ll; 
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
const int N = 2*(1e5) + 5;
int d_min[N];
int d_max[N];
int amin[N];
int amax[N];
int cost[N];
vii adj;
void dfs(int u,int p,int sm){
    sm +=cost[u];
    amin[u] = min(sm,amin[p]);
    amax[u] = max(sm,amax[p]);
    d_min[u] = min(d_min[p],sm-amax[u]);
    d_max[u] = max(d_max[p],sm -amin[u]);
    trav(v,adj[u]){
        if(v!=p){
            dfs(v,u,sm);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin>>T;
    while(T--){
        int n;
        cin >> n;
        adj.clear();
        adj.push_back({1});
        adj[0].push_back(1); // 0 dummy node
        int cnt = 1;
        cost[1] = 1;
        cost[0] = 0;
        adj.push_back(vi());
        vector<pi> qrs;
        rep(i,0,n){
            char x;
            cin >> x;
            if(x=='+'){
                int p,c;
                cin >> p >> c;
                adj[p].push_back(++cnt);
                cost[cnt] = c;
                adj.push_back(vi());
            }
            else{
                int u,v,k;
                cin >> u >> v >> k;
                qrs.push_back(mp(v,k));
            }
        }
        amin[0] = 0;
        amax[0] = 0;
        d_min[0]=0;
        d_max[0] =0;
        dfs(1,0,0);
        trav(q,qrs){
            if((q.second>=0 && q.second<=d_max[q.first] ) || (q.second<=0 && q.second>=d_min[q.first])) put("YES")
            else put("NO")
        }
 
    }
 
    return 0;
}