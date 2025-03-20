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
    vi a(n);
    tkv(a,n);
    if(a[0]==0 || a[n-1]==0){
        put(1);
        return;
    } 
    vi dp(n+1,INF);
    dp[0] = 0;
    map<int,int> last;
    int min_zero_dp = INF;
    int min_dp = INF;
    rep(i,1,n+1){
        dp[i] = dp[i-1]+1;
        if(a[i-1]==0){
            min_zero_dp = min(min_zero_dp,dp[i]);
            dp[i] = min(dp[i],min_dp);            
        }
        else {
            if(last.count(a[i-1])){
                if(dp[last[a[i-1]]] < dp[i]){
                    dp[i] = dp[last[a[i-1]]];
                }
            }
            dp[i] = min(dp[i],min_zero_dp);
            last[a[i-1]] = i;
        }
        min_dp = min(dp[i],min_dp);
    }   
    put(dp.back());

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
