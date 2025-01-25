#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
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
const int N = 5*(1e5)+5;
vi inds[N],oud[N],deps[N],g[N];
string s;
int in[N+1],out[N+1];
int t = 0;

void dfs(int u, int d) {
    in[u] = t++;
    inds[d].push_back(in[u]);
    if(deps[d].size()==0)deps[d].push_back(0);
    int mask = 1<<(s[u] - 'a');
    deps[d].push_back(deps[d].back() ^ mask);
    for (auto v : g[u]) dfs(v, d + 1);
    out[u] = t++;
    oud[d].push_back(out[u]);
}

void testcase(){
    int n,m;
    cin >> n >> m;
    rep(i,1,n){
        int v;
        cin >> v;
        v--;
        g[v].push_back(i);
    }
    cin >> s;
    dfs(0,0);
    rep(i,0,m){
        int u,h;
        cin >> u >> h;
        u--;
        h--;
        int cnt = 0;
        int left = lower_bound(all(inds[h]), in[u]) - inds[h].begin();
        int right = upper_bound(all(oud[h]), out[u]) - oud[h].begin();
        if (left >= right ) {
            put("Yes");
            continue;
        }
        if(right>=deps[h].size()) assert(0);
        cnt += pc(deps[h][right]^deps[h][left]);
        put(cnt<2 ? "Yes" : "No");
    }
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
