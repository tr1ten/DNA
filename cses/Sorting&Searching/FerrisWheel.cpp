#include <cstdio>
#include <bits/stdc++.h>

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
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i];
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
// greedy approach need to pair lightest child with heavy wt child  
size_t solve(size_t n,int mw,VI &vec){
    LL cnt = 0;
    sort(vec.begin(),vec.end());
    int p1 = 0;
    int p2 = n-1;
    while(p1<=p2){
        if(vec[p1]+vec[p2]<=mw){
            p1++;
        }
        p2--;
        cnt++;
    }
    return cnt;
}

// driver code
int main()
{
    int N,w;
    cin>>N >> w;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    cout << solve(N,w,vec);
    return 0;
}
