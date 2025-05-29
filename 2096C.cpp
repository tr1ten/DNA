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
const int INF = 1e14+5;
void testcase(){
    int n;
    cin >> n;
    vii mat(n,vi(n));
    rep(i,0,n){
        rep(j,0,n){
            cin >> mat[i][j];
        }
    }
    vi a(n),b(n);
    tkv(a,n);
    tkv(b,n);

    int ans = 0;
    int i = 0;
    int dp0=0,dp1=a[0];
    while (i<n)
    {
        int ii = i+1;
        while (ii<n)
        {
            int f1 = 1,f0=1,f=0;
            rep(j,0,n){
                if(mat[ii-1][j]==mat[ii][j]) f=1;
                if(mat[ii-1][j]==mat[ii][j]+1 ) f1=0;
                if(mat[ii-1][j]==mat[ii][j]-1) f0=0;
            }
            int tp1 = dp1;
            // cout << ii << " " << f0 <<" " << f1 << endl;

            if(!f) {    
                int mint = min(dp0,dp1);
                dp0 =  !f0 ? dp0 : mint;
                dp1 =  (!f1 ? dp1 : mint) + a[ii];  
                // if(!f1){
                //     dp1 += a[ii];
                // }
                // else {
                //     dp0 = !f0 ? dp0 : min(dp1,dp0);
                //     dp1 = dp0 + a[ii];
                // }
                break;
            }
            if(f1) dp1 = dp0 + a[ii];
            else dp1 = INF;
            if(f0) dp0 = tp1;
            else dp0 = INF;
            // cout << ii << " " << dp0 <<" " << dp1 << endl;
            ii++;
        }
        i = ii;
        // cout << ii << " " << dp0 <<" " << dp1 << endl;


    }
    ans += min(dp0,dp1);
    i = 0;
    dp0=0,dp1=b[0];
    while (i<n)
    {
        int ii = i+1;
        while (ii<n)
        {
            int f1 = 1,f0=1,f=0;
            rep(j,0,n){
                if(mat[j][ii-1]==mat[j][ii]) f=1;
                if(mat[j][ii-1]==mat[j][ii]+1) f1=0;
                if(mat[j][ii-1]==mat[j][ii]-1) f0=0;
            }
            int tp1 = dp1;
            if(!f) {
                int mint = min(dp0,dp1);
                dp0 =  !f0 ? dp0 : mint;
                dp1 =  (!f1 ? dp1 : mint) + b[ii];  
                
                // if(!f1){
                //     dp1 += b[ii];
                // }
                // else {
                //     dp0 = !f0 ? dp0 : min(dp1,dp0);
                //     dp1 = dp0 + b[ii];
                // }
                break;
            }
            if(f1) dp1 = dp0 + b[ii];
            else dp1 = INF;
            if(f0) dp0 = tp1;
            else dp0 = INF;
            ii++;
        }
        i =ii;
    }
    ans += min(dp0,dp1);
    put(ans<INF ? ans : -1);
    
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
