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
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
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
const int N = 1e4+5;

void testcase(){
     int n ;
    cin >> n;
    int L=0,R=1;
    vector<set<int>> a(n);
    vi c(n);
    tkv(c,n);
    rep(i,0,n){
        rep(j,0,c[i]){
            int z;
            cin >> z;
            a[i].insert(z);

        }
    }
    vii dp(2,vi(2));
    dp[L][L] = INF;
    dp[R][L] = INF;
    rep(i,1,n){
        vii dp0(2,vi(2));
        int last = 0;
        int col2 = 0;
        int col1 = 0;
        for(auto &x:a[i]){
            if(a[i-1].count(x)){
                col1++;
            }
            if(i-2>=0 && a[i-2].count(x)){
                col2++;
            }
        }
        dp0[L][R] = min(dp[R][L],dp[L][L]);
        dp0[R][R] = min(dp[R][R],dp[L][R]);
        dp0[L][L] = min(dp[L][L],dp[R][L]+col2);
        dp0[R][L] = min(dp[L][R] + col1, dp[R][R] + col1 + col2);
        dp=dp0;
    }
    int ans = min({dp[1][0],dp[0][0]});
    cout << ans << endl;
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
