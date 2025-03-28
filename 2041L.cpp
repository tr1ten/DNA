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

const int MOD = (998244353); // change me for god sake look at problem mod
const int INF = 1e16+5;
const int N = 5*1e5 + 5;
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
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    srv(a);
    int ans =0;
    rep(y,1,n+1){
        int k=a.end() -lower_bound(all(a),y);
        if(k==n || k<2) continue;
        int sub= nCk(n-1,k+1);
        int add = (n-2)*fact[n-1]%MOD;
        sub= 2*sub%MOD;
        int pp = fact[k]*fact[n-k-1]%MOD;
        sub = sub*pp%MOD;
        ans += (n-k)*(add-sub+MOD)%MOD;
        ans %=MOD;
    }
    int den = finv[n];
    put(ans*den%MOD);

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("test_cases.txt","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    pre();
    cin>>T;
    while(T--) testcase();

    return 0;
}
