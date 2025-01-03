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
const int N =2e5+4;
int is_leaf[N],leaf_c[N],bad[N],subtree[N];
vii adj;
int n;
void testcase(){
    cin >> n;
    adj.clear();
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int lc = 0;
    memset(is_leaf,0,n*(sizeof(int)));
    memset(leaf_c,0,n*(sizeof(int)));
    memset(bad,0,n*(sizeof(int)));
    memset(subtree,0,n*(sizeof(int)));


    rep(i,0,n) {
        is_leaf[i] = adj[i].size()==1;
        lc += is_leaf[i];
    }
    rep(i,0,n){
        for(auto v:adj[i]){
            leaf_c[i] += is_leaf[v];
        }
    }
    int ans = lc*(n-lc);
    rep(p,0,n){
        rep(m,0,n){
            if(m!=p){
                if(!is_leaf[m] && !is_leaf[p] && leaf_c[p]==0) {
                    int valid = 0;
                    for(auto v:adj[m]){
                        if(is_leaf[v]) {
                            valid = 1;
                            break;
                        }
                    }
                    for(auto q:adj[m]){
                        if(!is_leaf[q] && p!=q) {
                            ans+=1;
                        }
                    }
                    
                }
            }
        }
    }
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
