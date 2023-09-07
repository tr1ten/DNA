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

#include <bits/stdc++.h>
using namespace std;
// Fenwick Tree
// Time Complexity: O(logn) for both update and query
void update(long double BIT[], int x, long double val, int N)
{
    ++x;
    while (x <= N)
    {
        BIT[x] += val;
        x += (x & -x);
    }
}
long long query(long double BIT[], int x)
{
    ++x;
    long long res = 0;
    while (x > 0)
    {
        res += BIT[x];
        x -= (x & -x);
    }
    return res;
}
long long range(long double bit[], int a, int b) { return (query(bit, b) - query(bit, a - 1) ) ; }



const int N = 3*(1e5)  +5;
int tin[N];
int tout[N];
int timer;
vii adj;
void dfs(int u,int p){
    tin[u] = timer++;
    trav(v,adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    tout[u] = timer-1;
}

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
        int n,q;
        cin >> n;
        adj.resize(n);
        rep(i,0,n-1){
            int u,v;
            cin >> u >> v;
            --u;--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }  
        long double bit[n+1];
        memset(bit,0,sizeof bit);
        cin >> q;
        rep(i,0,q){
            int t,x,y;
            cin >> t >> x >> y;
            if(t==1){
                --x;
                long double logy = log10(y);
                long double diff = logy-range(bit,tin[x],tin[x]);
                update(bit,x,diff,n);
            }
            else{
                --x;--y;
                long double xsum = range(bit,tin[x],tout[x]);
                long double ysum = range(bit,tin[y],tout[y]);
                long double diff = xsum - ysum;
                if(diff>=9) put(1000000000)
                else{
                    long double ans = pow((long double)10,diff);
                    cout << setprecision(6) << ans << endl;;
                };
                
            }
        }
    }

    return 0;
}
