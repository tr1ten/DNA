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

const int MOD = 998244353; // change me for god sake look at problem mod
const int INF = 1e16+5;
const int N = 2e5+5;
unordered_map<int,int> dp[N][2];
int n;
int a[N];
int f(int i,int last,int j){
    if(i==n) return 1;
    if(dp[i][last].count(j)) return dp[i][last][j];
    int ways = 0;
    if(a[i]==j){
        ways = f(i+1,0,j);
    }
    if(!last){
        ways += f(i+1,1,j+1);
        ways %=MOD;
    }
    return dp[i][last][j] = ways;
}
void testcase(){
    cin >> n;
    tkv(a,n);
    rep(i,0,n){
        dp[i][0].clear();dp[i][1].clear();
    }
    put(f(0,0,0));
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
