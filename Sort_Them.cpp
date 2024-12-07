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
    string s,p;
    cin >> s >> p;
    int dp0=0,dp1=1;
    map<char,char> repl;
    rep(i,0,26){
        repl[p[i]] = p[25-i]; 
    }
    rep(i,1,n){
        int vp0 = min(s[i-1]<=s[i] ? dp0 : INF, repl[s[i-1]]<=s[i] ? dp1 : INF ) ;
        int vp1 = min(s[i-1]<=repl[s[i]] ? dp0 : INF, repl[s[i-1]]<=repl[s[i]] ? dp1 : INF ) + 1;
        dp0=vp0,dp1=vp1;
    }
    int ans = min(dp0,dp1);
    if(ans<INF) put(ans)
    else put(-1);
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
