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
#define mk_vec(name,sz,value) vector<LL> name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<LL>> name(n, vector<LL>(m, value))
#define contains(x) find(x) != string::npos
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
size_t solve(size_t n){
    int target = (n*(n+1)/2);
    if(target%2!=0) return 0;
    target >>=1;
    mk_vec(dp,target+1,0L);
    dp[0] = 1;
    // Ah important not n+1, else we have to devide ans by 2 but modulo will cause issue then thus do not include last number n
    FOR(i,1,n){
        ROF(sm,0,target+1){
            if(sm>=i) dp[sm] = ((dp[sm]+dp[sm-i]))%MOD;
        }
    }
    return ((dp[target]));
}

// driver code
int main()
{
    int N;
    cin>>N;
    cout << solve(N);
    return 0;
}
