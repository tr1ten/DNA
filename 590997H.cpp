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
// N*2^N
// Think of it as N dimesion hyper cube (errichto <3): easy to visualize with 2D
// similar idea as prefix sum over each dimesion then merge 
// dimensionality reduction
const int B = 20;
int dp[1<<B];
int op=1;

const int N = (1<<B) + 5;
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
	if(n<k) return 0;
    return (((fact[n]*finv[k])%MOD)*finv[n-k])%MOD;
}
void sos_bd(){ // op(operation add or sub) value of submask to super mask
    for(int i = 0;i < B; ++i) for(int mask = 0; mask < 1<<B; ++mask){
	if(mask & (1<<i))
		dp[mask] = (dp[mask] + op*dp[mask^(1<<i)]+MOD)%MOD;
}
}

void testcase(){
	int n,k;
	cin >> n >> k;
	rep(i,0,n){
		int x;
		cin >> x;
		dp[x]++;
	}
	op = 1;
	sos_bd();
	rep(i,0,1<<B){
		dp[i] = nCk(dp[i],k);
	}
	op = -1;
	sos_bd();
	int q;
	cin >> q;
	rep(i,0,q){
		int mask;
		cin >> mask;
		cout << dp[mask] << endl;
	}

	
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
	pre();
    while(T--) testcase();

    return 0;
}
