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
const int N = 3*(1e5)+5;
vi g[N];
map<int,int> sets[N];
int set_sm[N];
int ans = 0;
int merge_set(int u,int v){
    if(set_sm[u]<set_sm[v]) swap(u,v);
    int vs = set_sm[v];
    int us = set_sm[u];
    int a =0;
    for(auto [d,c]:sets[v]){
        a++;
        ans += c*us*(2*a - 1);
        us -= sets[u][d];
        vs -= c;
        ans += vs*sets[u][d]*(2*a-1);
        sets[u][d] += c;
        set_sm[u]+=c;
    }
    return u;
}
int dfs(int u,int par,int d){
    int cur_set = u;
    for(auto v:g[u]){
        if(v!=par){
            cur_set = merge_set(cur_set,dfs(v,u,d+1));
        }
    }
    sets[cur_set][d]++;
    set_sm[cur_set]++;
    return cur_set;

}
void testcase(){
    int n;
    cin >> n;
    rep(i,0,n){
        sets[i].clear();
        set_sm[i] = 0;
        g[i].clear();

    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(0,-1,0);
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
