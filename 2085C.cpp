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
int dp[64][8][8][8];
void testcase(){
    int x,y;
    cin >> x >> y;
    int ans = 0;
    memset(dp,-1,sizeof dp);
    auto dfs = [&](auto &self,int i,int a,int b,int c){
        // cout << i << " " << a <<" " << b <<"  " << c << endl;
        if(i==60){
            return (a+b+c==0) ? 1LL : 0LL;
        }
        if(dp[i][a][b][c]!=-1) return dp[i][a][b][c];
        int x1 = (x>>i)&1LL;
        int y1 = (y>>i)&1LL;
        if((((x1+y1+a)&1)==(((x1+b)^(y1+c))&1)) && self(self,i+1,(x1+y1+a)>>1,(x1+b)>>1,(y1+c)>>1)) {
            return dp[i][a][b][c] = 1;
        }
        if((((x1+y1+a+2)&1)==(((x1+1+b)&1)^((y1+1+c)&1)) ) && self(self,i+1,(x1+y1+a+2)>>1,(x1+1+b)>>1,(y1+1+c)>>1)) {
            ans |=1LL<<i;
            return dp[i][a][b][c]=1;
        }
        return dp[i][a][b][c]=0;
    };
    if(!dfs(dfs,0,0,0,0)){
        put(-1);
    }
    else {
        assert((x+y+2*ans)==((x+ans)^(y+ans)));
        assert(ans<=1e18);
        put(ans);
        return;
    }
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
