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
const int N = 1e5 + 5;

int sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
std::vector <int> prime;
bool is_composite[N+1];

void preprocess (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			sieve[i] = i;
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			sieve[i*prime[j]] = min(sieve[i],prime[j]);
		}
	}
}

const int M = 21;
const int N2=2*M+5;
int f[M+1];
long long fact[N2+1];
long long inv[N2+1];
long long finv[N2+1];

void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N2; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    inv[1] = 1;
    for (int i = 2; i <= N2; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= N2; i++) {
        finv[i] = (inv[i]*finv[i-1])%MOD;
    }
}

long long nCk(int n,int k) {
    if(n<k) return 0;
    return (((fact[n]*finv[k])%MOD)*finv[n-k])%MOD;
}

void testcase(){
    int k,n;
    cin >> k >> n;
    rep(i,1,k+1){
        if(i==1){
            cout << n << " ";
            continue;
        }
        int ans = 0;
        int num = (n+1);
        rep(t,1,min(n+1,M+1)){
            int cur = 1;
            int x= i;
            while(x>1){
                int f = sieve[x];
                int cnt = 0;
                while(x%f==0) {
                    cnt++;
                    x /=f;
                }
                cur = cur*nCk(t+cnt-1,cnt)%MOD;
            }
            f[t] = cur;
            rep(tt,1,t){
                f[t]= (f[t]-f[tt]*nCk(t,tt)%MOD + MOD)%MOD;
            }
            num = num*(n+1-t)%MOD;
            int nval = num*finv[t+1]%MOD;
            ans += f[t]*nval%MOD;
            ans %= MOD;
        }
        cout << ans << " ";
    }
    cout << endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    preprocess(N+1);
    pre();
    cin>>T;
    while(T--) testcase();

    return 0;
}
