#pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
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
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;
LL dp[501][501] = {-1};
// actual solutions 


// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill((int*)dp,(int*)dp+sizeof(dp)/sizeof(int),0);
    FOR(a,1,501){
        FOR(b,1,501){
            if(a==b) continue;
            dp[a][b]=INF;
            FOR(i,1,a){
                dp[a][b] = min(dp[a][b],dp[a-i][b]+dp[i][b]+1);
            }
            FOR(i,1,b){
                dp[a][b] = min(dp[a][b],dp[a][b-i]+dp[a][i]+1);
            }
        }
    }
    int A,B;
    cin>>A>>B;
    cout << dp[A][B] << endl;
    return 0;
}
