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
const int N = 63;
int dp[N][N];

long long fact[N];
long long inv[N];
long long finv[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= N; i++) {
        finv[i] = (inv[i]*finv[i-1])%MOD;
    }
}

long long nCk(int n,int k) {
    if(n==k) return 1;
    if(n<k) return 0;
    return (((fact[n]*finv[k])%MOD)*finv[n-k])%MOD;
}

int dfs(int bits,int len){
    if(len==0){
        return 1;
    }
    if(bits<=0){
        return 0;
    }
    if(dp[bits][len]!=-1) return dp[bits][len];
    int res = 0;
    rep(c,1,bits+1){
        res += nCk(bits,c)*dfs(bits-c,len-1)%MOD;
        res %=MOD;
    }
    return dp[bits][len] = res;
}
void testcase(){
    int m;
    cin >> m;
    int res = 0;
    int tot = hset(m);
    // cout << tot << endl;
    rep(len,1,tot+2){
        int cnt = 0;
        int cur = dfs(tot,len);
        per(i,0,tot){
            if((m>>i)&1){
                rep(c,0,i+1){
                    cur+= (nCk(i,c)*dfs(tot-c,len-1)%MOD)*len%MOD;
                    cur %=MOD;
                }
                cnt++;
            }
        }
        // cout << " "<< len << " " << cur << " " << cnt<< endl;
        cur+= dfs(tot-(cnt-1),len-1)*len%MOD;
        res += cur;
        res %=MOD;
    }
    put(res);
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    memset(dp,-1,sizeof dp);
    pre();
    cin>>T;
    while(T--) testcase();

    return 0;
}
