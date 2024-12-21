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
const int N = 205;
int dp[N][N][N];
int dp2[N][N];

int a[N][N];
void testcase(){
    int n,m,K;  
    cin >> n >> m >> K;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin >> a[i][j];
        }
    }
    rep(i,0,n+1){
        rep(j,0,m+1){
            rep(k,0,m+1){
                dp[i][j][k] = INF;
            }
            dp2[i][j] = INF;
        }
    }
    rep(i,0,m+1){
        dp[1][0][i] = i*K;
    }
    rep(i,1,n+1){
        rep(j,1,m+1){
            rep(k,0,m+1){
                dp[i][j][k] = min(dp[i][j][k],a[i][(j+k-1+m)%m+1] + min(dp[i][j-1][k],k*K + dp2[i-1][j]) );
                dp2[i][j] = min(dp2[i][j],dp[i][j][k]);
            }
            // cout << i << " " << j <<" " << a[i][j] << " " << dp2[i][j] << endl;
        }
    }
    put(dp2[n][m]);
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
