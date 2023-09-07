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
struct DSU
{
    vector<int> parent;
    vector<int> size;
    int n;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
        size.resize(n);
        this->n  = n;
    }
    int find(int u){
        assert(u<n);
        if(parent[u]!=u) parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u,int v){
        assert(u<n);
        assert(v<n);
        int ra = find(u);
        int rb = find(v);
        if(ra==rb) return 0;
        if(size[ra]<size[rb]) swap(ra,rb);
        size[ra] +=size[rb];
        parent[rb] = ra;
        return 1;
    }
};
 
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);	  
    int T=1;
    // cin>>T;
    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        vi c(k);
        vi tt(n+1);
        int prev = 0;
        rep(i,0,k){
            int x;
            cin >> x;
            c[i] = x;
            tt[prev] +=i;
            tt[prev+x]  -=i;
            prev +=x;
        }
        rep(i,1,n){
            tt[i] +=tt[i-1];
        }
        vii dp(k,vi(k,INF));
        vector<vector<pi>> adj(n);
        DSU ds(n);
        rep(i,0,m){
            ll u,v,w;
            cin >> u>> v >> w;
            u--;v--;
            if(w==0){
                ds.unite(u,v);
            }
            if(tt[u]!=tt[v]){
                dp[tt[u]][tt[v]] = min(dp[tt[u]][tt[v]], w);
                dp[tt[v]][tt[u]] = min(dp[tt[v]][tt[u]], w);
            }
        }
        int f = 0;
        vector<bool> vis(k);
        rep(i,0,n){
            if(vis[tt[i]]) continue;
            int j = i;
            while (j<n && tt[i]==tt[j])
            {
                if(ds.find(i)!=ds.find(j)) {f=1;break;}
                j++;
            }
            if(f) break;
            vis[tt[i]] = 1;
        }
        if(f) put("No")
        else{
            put("Yes");
            rep(i,0,k){
                dp[i][i] = 0;
            }
            rep(c,0,k){
                rep(i,0,k){
                    rep(j,0,k){
                        dp[i][j] = min(dp[i][j],dp[i][c] + dp[c][j]);
                    }
                }
            }
            rep(i,0,k){
                rep(j,0,k){
                    if(dp[i][j]<INF) cout << dp[i][j] << " ";
                    else cout << "-1" << " ";
                }
                cout << endl;
            }
        }
        
    }

    return 0;
}
