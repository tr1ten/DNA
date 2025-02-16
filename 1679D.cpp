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

const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;
vii adj;
vi a;
int n,m,k;
vi dp,states;

bool dfs(int u,int x){
    states[u] = 1;
    for(auto v:adj[u]){
        if(a[v]>x) continue;
        if(states[v]==0){
            if(dfs(v,x)) return true;
            dp[u] = max(dp[u],dp[v]+1);
        }  
        else if(states[v]==1){
            return true;
        }
        else {
            dp[u] = max(dp[u],dp[v]+1);
        }
    }
    states[u] =2;
    return false;
}
int check(int x){
    dp.clear();
    dp.resize(n);
    states.clear();
    states.resize(n);
    int cyl = 0;
    rep(i,0,n){
        if(states[i]==0){
            cyl |=dfs(i,x);

        }
    }    
    int mx = *max_element(all(dp));
    // cout << x << " " << cyl << endl;
    return cyl || (mx>=(k-1));z

}
void testcase(){
    cin >> n >> m >> k;
    adj.resize(n);
    a.resize(n);
    tkv(a,n);
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        --u;--v;
        adj[u].push_back(v);
    }
    int lo=*min_element(all(a)),hi=1e9+1;
    int ans = -1;
    while (lo<=hi)
    {
        int mid= (lo+hi)/2;
        if(check(mid)){
            ans =mid;
            hi = mid-1;
        }
        else lo = mid+1;
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
    while(T--) testcase();

    return 0;
}
