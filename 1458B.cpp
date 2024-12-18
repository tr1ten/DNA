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

void testcase(){
    int n;
    cin >> n;
    vi a(n),b(n);
    rep(i,0,n){
        cin >> a[i] >> b[i];
    }
    int total=accumulate(all(b),0LL);
    int MAX = 70*n+1;
    vector<vector<int>> dp(n+1,vector<int>(MAX,-INF));
    dp[0][0] = 0;
    rep(i,0,n){
        vector<vector<int>> dp2(n+1,vector<int>(MAX,-INF));
        rep(j,0,n){
            rep(cap,0,MAX){
                int diff=2*(a[i]-b[i]); 
                dp2[j+1][min(cap+diff,MAX-1)] = max(dp2[j+1][min(cap+diff,MAX-1)],dp[j][cap] + 2*b[i]);
                dp2[j][cap] = max(dp2[j][cap],dp[j][cap]);
            }
        }
        dp = dp2;
    }
    vector<double> ans;
    rep(k,1,n+1){
        double an =0 ;
        rep(cap,0,MAX){
            an = max(an,(dp[k][cap]+min((2*total-dp[k][cap])*1.0/2,(double)cap))*1.0/2 );
        }
        cout << an << " ";
    }
    cout<<"\n";
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
