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
vector<vector<int>> divs;
void preprocess(int N){
    divs.clear();
    divs.resize(N+1);
    for(int x=1;x<=N;x++){
        for(int u=x;u<=N;u +=x){
            divs[u].push_back(x);   
        }
    }
}
void testcase(){
    int n;
    cin >> n;
    preprocess(n);
    vi a(n+1);
    vi f(n+1);
    rep(i,0,n){
        int x;
        cin >> x;
        a[x]++;
        for(auto d:divs[x]){
            f[d]++;
        }
        
    }
    int ans  = 0;
    per(i,1,n+1){
        f[i] = f[i]*(f[i]-1)/2;
        for(int j=2*i;j<=n;j+=i){
            f[i] -= f[j];
        }
        int ex = 0;
        for(auto d:divs[i]) {
            if(a[d]) {ex=1;break;}
        }
        if(ex==0){
            ans+= f[i];
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
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}