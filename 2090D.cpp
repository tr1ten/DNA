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
const int MAXN = 1e5+2;
std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
    is_composite[1] = true;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
		}
	}
}
void testcase(){
    int n;
    cin >> n;
    if(n==2) {
        cout << "2 1" << endl;
        return;
    }
    int p = -1;
    rep(i,n/3,(2*n+2)/3 + 1){
        if(!is_composite[i]){
            p = i;
            break;;
        }
    }
    vi ans;
    vi used(n+1,0);
    int i = 0;
    int sign = 1;
    while (p+i*sign>0 && p+i*sign<=n){
        ans.push_back(p+i*sign);
        used[ans.back()] = 1;
        if(sign>0) i+=1;
        sign *=-1;
    }
    rep(i,1,n+1){
        if(!used[i]){
            ans.push_back(i);
        }
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
    sieve(MAXN);
    cin>>T;
    while(T--) testcase();

    return 0;
}
