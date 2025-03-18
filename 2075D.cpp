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
const int INF = 1e18+5;
const int N = 64;
int dp[N][N][N];
int dfs(int b1,int b2,int i){
    if(max(b1,b2)==0) return 0;
    if(i>max(b1,b2)) {
        return INF;
    }
    if(dp[b1][b2][i]!=-1) return dp[b1][b2][i];
    int res=dfs(b1,b2,i+1);
    if(i<=b1){
        res = min(res,dfs(b1-i,b2,i+1) + (1LL<<i)); 
    }
    if(i<=b2){
        res = min(res,dfs(b1,b2-i,i+1) + (1LL<<i)); 
    }
    return dp[b1][b2][i] =res;
    
}
void testcase(){
    int x,y;
    cin >> x >> y;
    if(x==y){
        put(0);
        return;
    }
    int b1=62;   
    while (b1>=0 && ((x>>b1)&1)==0)
    {
        b1--;
    }
    int b2=62;   
    while (b2>=0 && ((y>>b2)&1)==0)
    {
        b2--;
    }
    int res = dfs(b1+1,b2+1+(b1==b2),1);
    while (b1>=0 && b2>=0 &&  (x>>b1)==(y>>b2))
    {
        b1--;
        b2--;
    }
    rep(i,0,N){
        if(max(b1+1,b2+1)+i>62) break;
        res = min(res,dfs(b1+1+i,b2+1+i,1));
    }
    put(res);
    
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    memset(dp,-1,sizeof dp);
    cin>>T;
    while(T--) testcase();

    return 0;
}
