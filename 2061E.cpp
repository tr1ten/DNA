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
    int n,m,k;
    cin >> n >> m >> k;
    vi a(n),b(m);
    tkv(a,n);tkv(b,m);
    vii dp(n,vi(m+1,INF));
    vi val(1<<m,(1LL<<30)-1);
    rep(mask,0,1<<m){
        rep(j,0,m){
            if(mask&(1<<j)){
                val[mask] &=b[j];
            }
        }
    }
    vi vv;
    rep(i,0,n) {
        dp[i][0] = a[i];
        rep(mask,0,1<<m){      
            dp[i][pc(mask)] = min(dp[i][pc(mask)],a[i]&val[mask]);
        }
        rep(j,1,m+1){
            vv.push_back(dp[i][j]-dp[i][j-1]);
        }
    }
    srv(vv);
    int ans = accumulate(all(a),0LL);
    rep(i,0,k){
        ans += vv[i];
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
