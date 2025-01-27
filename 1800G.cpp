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
const int N = 2*(1e5) + 5;
vi g[N];
int ans = 1;
const int M = 1LL<<64;
const int p = 31;
pi dfs(int u,int par){
    pi hs = {0,1};
    unordered_map<int,int> cnt;
    unordered_map<int,int> vis;
    vi ch;
    for(auto v:g[u]){
        if(v!=par){
            auto pp = dfs(v,u);
            ch.push_back(pp.first);
            vis[pp.first] = pp.second;
            cnt[pp.first]++;
        }
    }
    srv(ch);
    int pw=p;
    rep(i,0,ch.size()){
        hs.first = (hs.first + (ch[i]*ch[i]%MOD + ch[i]*pw%MOD + 42)%MOD)%MOD;
    }   
    int odc = 0;
    for(auto [h,c]:cnt){
        if(c%2){
            odc++;
            if(vis[h]==0 || odc>1) {
                hs.second = 0;
                break;
            }
        }
    }
    return hs;
}
void testcase(){
    int n;
    cin >> n;
    rep(i,0,n) g[i].clear();
    rep(i,0,n-1){
        int u,v;
        cin >>u >> v;
        u--;v--;
        g[u].push_back(v);g[v].push_back(u);
    }
    auto f =dfs(0,-1);
    put(f.second  ? "YES" : "NO");
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