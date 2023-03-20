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
#define mk_vec(name,sz) VI name(sz)
#define mk_mat(name,n,m) vector<vector<int>> name(n, vector<int>(m, 0))
#define contains(x) find((x)) != string::nposs

const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
size_t solve(size_t n){
    mk_vec(dp,n+1);
    FOR(i,1,n+1){
        string s = to_string(i);
        dp[i] = INF;
        FOR(j,1,10){
            if(s.find((char)(j+'0'))!=string::npos){
                if(j>i) continue;
                dp[i] = min(dp[i],dp[i-j]+1);
            }
        }
    }
    return dp[n];
}

// driver code
int main()
{
    int N;
    cin>>N;
    cout << solve(N);
    return 0;
}
