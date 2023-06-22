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
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e15 +5;
const int N = 2*(1e5 + 5);
vector<ll> dijsktra(int S,vector<vector<pair<int,ll>>> &adj){
    int n = adj.size();
    vector<ll> dist(n,INF);
    vector<int> par(n,-1);
    dist[S] = 0;
    par[S] = S;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push(make_pair(0LL,S));
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(u.first>dist[u.second]) continue;
        for(auto &v:adj[u.second]){
            if(dist[v.first]>dist[u.second] + v.second){
                dist[v.first] = dist[u.second] + v.second;
                par[v.first] = u.second;
                pq.push(make_pair(dist[v.first],v.first));
            }
        }
    }
    return dist; // or par according to needs
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int n,m,a,b,c;
        cin >> n >> m >> a >> b >> c;
        a--;b--;c--;
        vi prices(m);
        tkv(prices,m);
        srv(prices);
        vi pref(m+1);
        pref[0] = 0;
        rep(i,0,m) pref[i+1] = pref[i] + prices[i];
        
        vector<vector<pair<int,ll>>> adj(n);
        rep(i,0,m){
            int x,y;
            cin >> x >> y;
            x--;y--;
            adj[x].push_back(mp(y,1LL));
            adj[y].push_back(mp(x,1LL));
        }
        auto da = dijsktra(a,adj);
        auto db = dijsktra(b,adj);
        auto dc = dijsktra(c,adj);
        ll res= INF;
        rep(k,0,n){
            ll cb = da[k]>m ? INF : pref[db[k]];
            ll ca = (da[k] + db[k])>m ? INF :  pref[da[k] + db[k]] - cb;
            ll cc = (da[k] + db[k] + dc[k] )> m ? INF : pref[da[k] + db[k] + dc[k]] - cb - ca;
            res = min(res, ca  + 2*cb + cc);
        }
        put(res)
    }

    return 0;
}
