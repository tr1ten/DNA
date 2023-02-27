#pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

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
const int MAXN = 2e5+5;
const int LOG = 30; // ceil(log2(10^9))

// number of planets and queries
int n, q;
// parent matrix where [i][j] corresponds to i's (2^j)th parent
int dp[MAXN][LOG+1];

void preprocess(int n){
    FOR(j,1,LOG+1){
        FOR(i,0,n){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}
int query(int u,int K){
    int ans = u;
    FOR(i,0,LOG+1){
        if(K&(1<<i)){
            ans = dp[ans][i];
        }
    }
    return ans;
    
}
// similar to binary lifiting
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    FOR(i, 0, N)
    {
        int a;
        cin >> a ;
        dp[i][0] = a-1;
    }
    preprocess(N);
    FOR(i,0,M){
        int u,k;
        cin >> u >> k;
        cout << query(u-1,k)+1 << endl;
    }
    return 0;
}
