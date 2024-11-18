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
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
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

const int MOD = 998244353; // change me for god sake look at problem mod
const int INF = 1e16+5;
const int N = 1e6 + 5;
int sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x<=N;x++){
        if(sieve[x]!=0) continue; 
        sieve[x] = x;
        for(int u=2*x;u<=N;u +=x){
            sieve[u] = x;
        }
    }
}

vector<int> factors(int x){
    vector<int> res;
    while(x>1){
        int f = sieve[x];
        if(x%f==0) res.push_back(f);
        while(x%f==0) x/=f;
    }
    return res;
}

int sum[N];
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    vi f = factors(a[0]);
    rep(mask,1,1<<f.size()){
        int p =1;
        rep(i,0,f.size()){
            if(mask&(1<<i)){
                p *=f[i];
            }
        }    
        sum[p] +=1;
    }
    int dp=0;
    rep(i,1,n){
        dp = 0;
        vi f = factors(a[i]);
        rep(mask,1,1<<f.size()){
            int p =1;
            int t = -1;
            rep(i,0,f.size()){
                if(mask&(1<<i)){
                    p *=f[i];
                    t *=-1;
                }

            }    
            dp += (sum[p]*t+MOD)%MOD;
            dp%=MOD;
        }
        rep(mask,1,1<<f.size()){
            int p =1;
            rep(i,0,f.size()){
                if(mask&(1<<i)){
                    p *=f[i];
                }
            }    
            sum[p] +=dp;
            sum[p] %=MOD;
        }
    }
    put(dp);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    preprocess();
    while(T--) testcase();

    return 0;
}
