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
const int MAXN = 1e7+4;
std::vector <int> prime;
int sieve[MAXN];

void pre (int n) {
	std::fill (sieve, sieve + n, 0);
	for (int i = 2; i < n; ++i) {
		if (!sieve[i]) {
            sieve[i] = i;
			prime.push_back (i);
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			sieve[i * prime[j]] = prime[j];
		}
	}
}


vector<pi> factors(int x){
    vector<pi> res;
    while(x>1){
        int f = sieve[x];
        int cnt = 0;
        while(x%f==0) {x/=f;cnt++;}
        if(cnt) res.push_back({f,cnt});
    }
    return res;
}
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
void testcase(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,int> cnt;
    for(auto p:prime){
        int P = p;
        while (P<=m)
        {
            cnt[p] += m/P; P *=p;
        }
        
    }
    int par = 1;
    unordered_map<int,int> inv;
    
    for(auto [f,c]:cnt){
        par = par*(c+1)%MOD;
        inv[f] = fast_pow(c+1,MOD-2,MOD);
    }
    vi b(n);
    rep(i,0,n){
        int x;
        cin >> x;
        unordered_map<int,int> cnt2;
        int ans =par;
        for(auto [f,c]:factors(x)){
            if(inv[f]) {
                ans = ans*inv[f]%MOD;
                ans = ans*(cnt[f]+c+1)%MOD;
            }
            else ans = ans*(c+1)%MOD;
        }
        b[i] = ans;
    }
    pvc(b);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    pre(MAXN);
    while(T--) testcase();

    return 0;
}
