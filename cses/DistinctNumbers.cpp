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
size_t solve(size_t n,VI &vec){
    sort(vec.begin(),vec.end());
    int ans = 0;
    FOR(i,0,n){
        if(i==0 || vec[i]!=vec[i-1]) ans++;
    }
    return ans;
}

// driver code
int main()
{
    int N;
    cin>>N;
    mk_vec(vec,N,0);
    FOR(i,0,N) cin>>vec[i];
    cout << solve(N,vec);
    return 0;
}
