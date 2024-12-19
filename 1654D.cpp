#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define int long long
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define pvc(vec) for(auto x:vec) cout<<x<<" "; cout<<endl;
#define put(x) cout << (x)<< endl;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
inline int ctz(int x) { return __builtin_ctzll(x);}
inline int pc(int x) {return  __builtin_popcount(x);} 
inline int hset(int x) {return __lg(x);}
/*
    NOT use unordered map use map
    NOT use seg tree use fenwick tree
    THINK before you code
*/

const int MOD = 998244353; // change me for god sake look at problem mod
const int INF = 1e16+5;
const int N = 2*(1e5) + 5;
int sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x<=N;x++){
        if(sieve[x]!=0) continue; 
        sieve[x] = x;
        for(int u=2*x;u<=N;u +=x){
            sieve[u] = x;
        }
    }
}

map<int,int> factors(int x){
    map<int,int> res;
    while(x>1){
        int f = sieve[x];
        while(x%f==0) {res[f]++;x/=f;}
    }
    return res;
}
vi adj[N];
map<tuple<int,int>,pi> ed;
int a[N];
int a1[N];
int a0[N];


long long fast_pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void dfs1(int u,int p){
    for(auto v:adj[u]){
        if(v!=p){
                pi val = ed[{u,v}];
            auto fact = factors(val.first);
            auto fact2 = factors(val.second);
            auto ba1 = a1;
            for(auto f:fact2){
                a1[f.first] -=f.second;
            }
            for(auto f:fact){
                a1[f.first] +=f.second;
                a0[f.first] = max(a1[f.first],a0[f.first]);
            }
            dfs1(v,u);
            for(auto f:fact2){
                a1[f.first] +=f.second;
            }
            for(auto f:fact){
                a1[f.first] -=f.second;
            }
        }
    }
    
}
void dfs2(int u,int p){
    for(auto v:adj[u]){
        if(v!=p){
            pi val = ed[{u,v}];
            a[v] = (((a[u]*val.second)%MOD)*fast_pow(val.first,MOD-2,MOD))%MOD;
            dfs2(v,u);
        }
    }
}
void testcase(){
    int n;
    cin >> n;
    rep(i,0,n) adj[i].clear();
    ed.clear();
    rep(i,0,n+1){
        a1[i]= 0;a0[i]=0;
    }
    rep(i,0,n-1){
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        int g = __gcd(x,y);
        x /=g;
        y /=g;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ed[{u,v}] = {x,y};
        ed[{v,u}] = {y,x};
    }   
    dfs1(0,-1);
    a[0] = 1;
    rep(i,2,n+1){
        if(a0[i]) a[0] = a[0]*fast_pow(i,a0[i],MOD)%MOD;
    }
    dfs2(0,-1);
    // pvc(a);
    int ans = 0;
    rep(i,0,n){
        ans += a[i];
        ans %= MOD;
    }
    put(ans);


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    preprocess();
    while(T--) testcase();

    return 0;
}
