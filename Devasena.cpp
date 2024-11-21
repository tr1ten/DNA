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
const int N = 1e5+2;
int f[N+1],g[N+1];
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
void testcase(){
    int n;
    cin >> n;
    memset(g,0,sizeof(g));

    rep(i,0,n){
        int x;
        cin >> x;
        for(auto d:divs[x]){
        g[d]++;
        }
    }
    int ans = 1;    
    for(int i=N-1;i>=1;i--){
        g[i] = (fast_pow(2,g[i],MOD-1)-1+MOD-1)%(MOD-1);
        for(int j=2*i;j<N;j+=i){
            g[i] -=g[j];
            g[i] = (g[i]+MOD-1)%(MOD-1);
        }
        // cout << i << " " << g[i] << endl;
        ans = ans*fast_pow(i,g[i],MOD)%MOD;
    }
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
    preprocess();
    while(T--) testcase();

    return 0;
}
