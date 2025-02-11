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
const int N = 1e3 + 5;
vi g1[N],g2[N];
int dp[N][N];
void bfs(int s1,int s2) {
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    dp[s1][s2] = 0;
    pq.push({0,s1,s2});
    while (pq.size())
    {
        auto [c,u,v] = pq.top();
        pq.pop();
        if(dp[u][v]<c) continue;
        for(auto uu:g1[u]){
            for(auto vv:g2[v]){
                int cost = c + abs(uu-vv);
                if(cost < dp[uu][vv]) {
                    dp[uu][vv] = cost;
                    pq.push({cost,uu,vv});
                }
            }
        }
    }
    
}
void testcase(){
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    s1--;s2--;
    vector<pi> edges;
    rep(i,0,n){
        g1[i].clear();
        g2[i].clear();
        rep(j,0,n){
            dp[i][j] = INF;
        }
    }
    
    int m1;
    cin >> m1;
    rep(i,0,m1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        if(u>v) swap(u,v);
        edges.push_back({u,v});
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    srv(edges);
    int m2;
    cin >> m2;
    set<int> to_check;
    rep(i,0,m2){
        int u,v;
        cin >> u >> v;
        --u;--v;
        if(u>v) swap(u,v);
        pi ed = {u,v};
        if(binary_search(all(edges),ed)) {
            to_check.insert(u);
            to_check.insert(v);

        }
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    bfs(s1,s2);
    int ans = INF;
    for(auto u:to_check){
        ans = min(dp[u][u],ans);
    }
    put(ans==INF ? -1 : ans);

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
