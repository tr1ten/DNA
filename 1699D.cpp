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
    vii dd(n,vi(n));
    rep(i,0,n){
        vector<int> cnt(n+1);
        pi mx;
        rep(j,i,n){
            cnt[a[j]]++;
            mx = max(mx,{cnt[a[j]] , a[j]});
            if((j-i+1)%2==0 && mx.first<=j-i+1-mx.first) {
                dd[i][j] = 1;
            }
        }        
    }
    vi dp(n+1);
    dp[0] =1;
    
    rep(i,1,n+1){
        if((i)%2==0 && dd[0][i-1]){
            dp[i] = 1;
        }
        per(j,0,i){
            if((i==n || a[j]==a[i]) && dp[j]>0 && (j+1>i-1 || dd[j+1][i-1]) ) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    put(dp[n]-1);
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
