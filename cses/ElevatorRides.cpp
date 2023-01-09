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
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
size_t solve(size_t n,int x,VI &wts){
    vector<pair<int,int>> dp((1<<n)+2); 
    dp[0] = make_pair(1,0);
    FOR(mask,1,1<<n){
        pair<int,int> res = make_pair(INF,INF);
        FOR(i,0,n){
            if((mask&(1<<i))==0) continue;
            auto hd = dp[(mask^(1<<i))];
            int r=hd.first;
            int wt = hd.second+wts[i];
            if(wt>x){
                wt = wts[i];
                r++;
            }
            if(r<res.first) {
                res.first = r;
                res.second = wt;
            }
            else if(r==res.first && wt<res.second) res.second = wt;
        }
        dp[mask] = res;
    }
    return dp[(1<<n)-1].first;
}
// driver code
int main()
{
    int N,x;
    cin >> N >> x;
    VI wts;
    FOR(i,0,N){
        int wt;
        cin >> wt;
        wts.PB(wt);
    }
    cout << solve(N,x,wts);
    return 0;
}
