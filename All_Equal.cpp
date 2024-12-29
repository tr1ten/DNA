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
const int MAXN = 5*(1e5)+5;
std::vector <int> prime;
int minDiv[MAXN];

void sieve (int n) {
	std::fill (minDiv, minDiv + n, 0);
	for (int i = 2; i < n; ++i) {
		if (!minDiv[i]) {
            minDiv[i] = i;
			prime.push_back (i);
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			minDiv[i * prime[j]] = prime[j];
		}
	}
}
const int N = MAXN;
int h[MAXN];
vector<vector<int>> divs(N+1,{1});
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    for(int x=2;x<=N;x++){
        for(int u=x;u<=N;u +=x){
            divs[u].push_back(x);   
        }
    }
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
vector<pi> factorize(int x) {
    vector<pi> res;
    int prev = -1;
    int cnt = 0;
    while(x != 1) {
        int d = minDiv[x];
        if(d == prev) {
            cnt++;
        } else {
            if(prev != -1) res.push_back({prev, cnt});
            prev = d;
            cnt = 1;
        }
        x /= d;
    }
    res.push_back({prev, cnt});
    return res;
}
// Solve this problem given element X, how many co-primes this will have from 1 to Y. 
int sub(int X,int Y){
    
}

// number of 
void testcase(){
    int n,m;
    cin >> n >> m;
    // f(A) = # valid K st V ai [gcd(ai,k)=g] 1<=k<=m
    //
    int ans = 0;
    rep(k,1,m+1){
        for(auto g:divs[k]){
            int Y = m/g;
            int X = k/g;
            int cnt = sub(X,Y);
            ans += fast_pow(cnt,n,MOD);
            ans %=MOD;
            
        }
    }
    put(ans);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    preprocess();
    sieve(MAXN);
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
