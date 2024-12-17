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
const int N=105;
int dp[N][N][2*N*N];

void testcase(){
    int n;
    cin >> n;
    vi a(n),b(n);
    rep(i,0,n){
        cin >> a[i] >> b[i];
    }
    int total=accumulate(all(b),0LL);
    rep(i,0,n){
        rep(j,0,n){
            rep(cap,0,200*n){
                dp[i][j][cap]=-INF;
            }
        }
    }
    dp[0][0][0] = 0;

    rep(i,0,n){
        rep(j,0,n){
            rep(cap,0,200*n){
                int diff=2*(a[i]-b[i]); 
                int inc = min(b[i],cap); 
                // take - cap inc, 
                dp[i+1][j+1][cap+diff] = max(dp[i+1][j+1][cap+diff],dp[i][j][cap] + 2*b[i]);
                // not take
                dp[i+1][j][cap-inc] = max(dp[i+1][j][cap-inc],dp[i][j][cap]);
                // cout << i << " " << j << " " << cap << " " << dp[i][j][cap] << endl;
            }
        }
    }
    vector<double> ans;
    rep(k,1,n+1){
        int an =0 ;
        rep(cap,0,200*n){
            an = max(an,dp[n][k][cap]+min((total*2-dp[n][k][cap]),cap));
        }
        ans.push_back(an*1.0/2);
    }
    pvc(ans);
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
