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
void testcase(){
    int n;
    cin >> n;
    vi inds(n);
    vii adj(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        inds[u]++;inds[v]++;
    }
    int mix = 0;
    rep(i,0,n){
        if(inds[i]>inds[mix]){
            mix = i;
        }
    }
    vi cc;
    for(auto v:adj[mix]){
        if(inds[v]==inds[mix]){
            cc.push_back(v);
        }
    }
    if(cc.size()>=2){
        mix = cc.back();
    }
    int ans = inds[mix];
    for(auto v:adj[mix]){
        inds[v]--;
    }
    int mix2 = -1;
    rep(i,0,n){
        if(i!=mix  && (mix2==-1 || inds[i]>inds[mix2])){
            mix2 = i;
        }
    }
    ans += inds[mix2]-1;
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
