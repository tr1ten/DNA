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
const int N =  1e5+5;
vi g[N];
int par[N];
bool ex[N];
void dfs(int i,int p){
    par[i] = p;
    for(auto v:g[i]){
        if(v!=p){
        dfs(v,i);
        }
    }
}
vi ans;
void dfs2(int i,int p){
    for(auto v:g[i]){
        if(v!=p && !ex[v]){
            dfs2(v,i);
        }
    }
    ans.push_back(i+1);
}
void testcase(){
    int n,st,en;
    cin >> n >> st >> en;
    st--;en--;
    rep(i,0,n){
        g[i].clear();
        ex[i] = 0;
    } 
    ans.clear();
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(st,-1);
    int cur = en;
    vi path;
    while (cur!=-1)
    {
        path.push_back(cur);
        ex[cur] = 1;
        cur = par[cur]; 
    }
    reverse(all(path));
    for(auto v:path){
        dfs2(v,-1);
    }
    assert(ans.size()==n);
    pvc(ans);
    

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
