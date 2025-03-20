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
long long fast_pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int M = 30;
int get(int n,int k){
    if(n<(1LL<<k)) return 0;
    int hi = hset(n);
    int ans = 0;
    if(hi>k){
        ans += (1LL<<(hi-1));
        ans += get(n^(1LL<<hi),k);
    }
    else if(hi==k){
        ans= (n^(1LL<<k)) + 1;
    }
    // cout << n << " " << k <<" " << ans << endl;
    return ans%MOD;
}
void testcase(){
    int n,m,A,B;
    cin >> n >> m >> A >> B;
    int a= (A+1)*(B+1)%MOD;
    int b= (A+1)*((B*(B+1)/2)%MOD)%MOD;
    b = b*(fast_pow(2,m,MOD)-2+MOD)%MOD;
    int c= (B+1)*((A*(A+1)/2)%MOD)%MOD;
    c = c*(fast_pow(2,n,MOD)-2+MOD)%MOD;
    int d=0;
    int ans = a;
    ans +=b;
    ans %=MOD;
    ans +=c;
    ans %=MOD;
    rep(i,0,M){
        int p = fast_pow(2,i,MOD);
        d += (p*get(A,i)%MOD)*get(B,i)%MOD;
        d %=MOD;
    }
    d =(d*(((fast_pow(2,n,MOD)-2+MOD)%MOD)*(fast_pow(2,m,MOD)-2 + MOD)%MOD)%MOD)%MOD;
    ans +=d;
    ans %=MOD;
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
