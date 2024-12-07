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
int ans= 0;
int dfs(int u,int p){
    vi mxi;
    int mx = adj[u].size()-1;
    for(int v:adj[u]){
        if(v!=p){
            auto s= dfs(v,u);
            mx = max((int)adj[u].size()-1+s-(p!=-1),mx);
            mxi.push_back(s);
        }
    }
    sort(all(mxi));
    int a = adj[u].size();
    int m = mxi.size();
    if(m>0) a +=max(0LL,mxi[m-1]-1);
    if(m>1) a +=max(0LL,mxi[m-2]-1);
    ans = max(a,ans);
    return mx;
}
void testcase(){
    int n;
    cin >> n;
    adj.clear();
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >>u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    dfs(0,-1);
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
    while(T--) testcase();

    return 0;
}
