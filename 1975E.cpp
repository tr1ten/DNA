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
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
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
const int N = 2*(1e5)+5;
int c[N],deg[N],par[N],bpc,cnt1,cnt2,cnt3,bad=0; // bad is black vertex with 2 child 
vii adj;
void dfs(int u,int p){
    par[u] = p;
    cnt1+=c[u];
    if(c[u] && c[p]==0){
        bpc++;
    }
    int sm = 0;
    for(auto v:adj[u]){
        if(v!=p){
            dfs(v,u);
            sm += c[v];
        }
    }
    if(c[u]){
        if(sm==2) cnt2++;
        else if(sm>2) cnt3++;
    }
    if(c[u] && sm==2) bad ^=u;
}
void flip(int x){
    c[x] ^=1;
    int d = c[x] ? 1: -1;
    int p = par[x];
    int oldd = deg[p];
    deg[p]+=d;
    if(c[p]==0){
        bpc += d;
    }
    if(deg[p]==2){
        if(oldd==3) cnt3--;
        cnt2++;
        bad ^=p;
    }
    if(deg[p]==3){
        if(oldd==2) {cnt2--;bad^=p;}
        cnt3++;
    }
    for(auto v:adj[x]){
        if(v!=p){
            if(c[v]) bpc += -1*d; 
        }
    }
    cnt1+=d;
}
int n,q;

bool check() {
    // cout << cnt1 << "  "<< cnt2 << " " << cnt3 << " "  << bpc << " "<< bad << endl;
    if(cnt1==0) return false;
    if(cnt2>1 || cnt3 || bpc>1) return false;
    if(cnt2 && c[par[bad]]) return false;
    return true;
}
void init(){
    adj.clear();
    adj.resize(n+1);
    rep(i,1,n+1) deg[i]=0;
    bpc = 0,cnt2=0,cnt3=0,bad=0,cnt1=0;

}
void testcase(){
    cin >> n >> q;
    init();
    rep(i,1,n+1) {cin>>c[i];}
    rep(i,0,n-1) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    check();
    rep(i,0,q){
        int u;
        cin >> u;
        flip(u);
        int ans = check();        
        cout << (ans?"Yes":"No") << endl;
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
