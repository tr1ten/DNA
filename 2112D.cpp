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
vector<pi> ans;
vii g;
int sp;
void dfs(int u,int p,int r=0){
    if(p!=-1){
        ans.push_back({r?u:p,r?p:u});
    }
    if(sp==u) {
        r^=1;
    }
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u,r^1);
        }
    }
}
void testcase(){
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool f= false;
    rep(i,0,n){
        if(g[i].size()==2){
            sp = i;
            f=1;
            break;
        }
    }
    if(!f) {put("NO");return;}
    else put("YES");
    ans.clear();
    dfs(sp==0 ? 1 :0,-1);
    for(auto x:ans){
        cout << x.first + 1 << " " << x.second +1 << endl;
    } 
    
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
