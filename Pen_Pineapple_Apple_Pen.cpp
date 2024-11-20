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
#define put(x) cout << x << endl;
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

const int N = 20;
int dp[1<<N];
int op=1;
void sos_fwd(){ // op value of supermask to submask
    for(int i = 0;i < N; ++i) for(int mask = (1<<N)-1; mask >=0; --mask){
	if((mask & (1<<i))==0)
		dp[mask] = max(dp[mask],dp[mask^(1<<i)]);
}
}

void testcase(){
    int n,k;
    cin >> n >> k;
    memset(dp,-1,sizeof dp);
    string s;
    cin >> s;
    rep(i,0,k){
        string g;
        cin >> g;
        int mask = 0;
        rep(j,0,g.size()){
            mask |= 1<<(g[j]-'a');
        }
        dp[mask] = i;
    }
    sos_fwd();
    int i =0;
    vector<int> ans;
    while (i<n)
    {
        int mask = 0;
        int cnt = 0;
        while (i<n && (dp[mask | (1<<(s[i]-'a'))]!=-1))
        {
            mask |=1<<(s[i]-'a');
            i++;
            cnt++;
        }
        while(cnt) {ans.push_back(dp[mask]+1);cnt--;}
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
    cin>>T;
    while(T--) testcase();

    return 0;
}
