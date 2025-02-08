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

const int N = 2*(1e5) +5;
vi g[N];
pi a[N];
int ans =0 ;
int dfs(int u,int p){
    vi vals;
    for(auto v:g[u]){
        if(v!=p){
            vals.push_back(dfs(v,u));
        }
    }
    if(vals.size()==0){
        return a[u].first;
    }
    srv(vals);
    int cur = max(a[u].first,min(a[u].second,vals.back()));
    for(auto val:vals){
        if(val>cur){
            ans += val-cur;
        }
    }
    return cur;

}
void testcase(){
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i].first >> a[i].second;
        g[i].clear();
    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans =0 ;
    ans +=dfs(0,-1);
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
