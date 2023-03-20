#include <iostream>
#include <vector>
#include <algorithm>
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
#define trav(a,x) for (auto& a: x)
#define sz(x) (int)(x).size()
const LL MOD = 1e9+7;
const int MX = 1e6+5;
// actual solutions
int solve(VI coins,int x){
    VI dp(x+1);
    dp[0] = 0;
    FOR(i,1,x+1){
        dp[i] = MX;
        trav(c,coins){
            if(i-c>=0) dp[i] = min(dp[i],dp[i-c]+1);
        }
    }
    return dp[x];
}

// driver code
int main()
{   
    int N,x;
    cin>>N>>x;
    VI coins(N);
    F0R(i,N) cin>>coins[i];
    LL res = solve(coins,x);
    cout << (res>=MX ? -1 : res);
    return 0;
}
