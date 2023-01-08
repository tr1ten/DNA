#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL; 
typedef pair<int,int> PI;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define iarr(arr) trav(a,arr) cin>>a;
#define inp(x) cin>>x;
#define inp2(x,y) cin>>x>>y;
#define inp3(x,y,z) cin>>x>>y>>z;
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
// 0/1 knapsack bounded atmost once
size_t solve(size_t n,int x,VI &prices,VI &pages){
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    FOR(i,1,n+1){
        FOR(tp,1,x+1){
            if(prices[i-1]>tp) dp[i][tp] = dp[i-1][tp];
            else dp[i][tp] = max(dp[i-1][tp],pages[i-1] + dp[i-1][tp-prices[i-1]]);
        }
    }
    return dp[n][x];
}
// driver code
int main()
{
    int N,x;
    inp2(N,x)
    VI h(N),s(N);
    iarr(h);
    iarr(s);
    cout<<solve(N,x,h,s);
    return 0;
}
