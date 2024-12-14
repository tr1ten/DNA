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
const int MAXN = 1e6;
std::vector <int> prime;
bool is_composite[MAXN];
int phi[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	phi[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			phi[i] = i - 1;					//i is prime
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
			}
		}
	}
}
void testcase(){
    int n,k;
    cin >> n >> k;
    int j = 0;
    vi b(n,1);
    rep(i,1,n+1){   
        if(k<=n-i){
            b[i-1] = prime[j++];
            rep(ii,i,i+k){
                b[ii] = prime[j];
            }
            rep(ii,i+k,n){
                b[ii] = b[i-1]*(k==0 ? 1 : b[i]);
            }
            break;
        }
        else {b[i-1] = prime[j++];k-=(n-i);}
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
    sieve(MAXN);
    while(T--) testcase();

    return 0;
}
