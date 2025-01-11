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
const int N = 5005;
int dp[N][N];
int ans[N][N];

void testcase(){
    int n;
    cin >> n;   
    rep(i,0,n){
        cin >> dp[i][i];
        ans[i][i] = dp[i][i];
    }
    rep(len,2,n+1){
        rep(i,0,n-len+1){
            int j = i+len-1;
            dp[i][j] = dp[i][j-1] ^ dp[i+1][j];
        }
    }
    rep(len,2,n+1){
        rep(i,0,n-len+1){
            int j = i+len-1;
            ans[i][j] = max({ans[i+1][j],ans[i][j-1], dp[i][j]});
        }
    }
    int q;
    cin >> q;
    rep(i,0,q){
        int u,v;
        cin >> u >> v;
        u--;v--;
        put(ans[u][v]);
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
