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
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions - median is optimal value for abs(ai - c) where 0<=i<n
size_t solve(size_t n,VI sticks){
    sort_vec(sticks);
    int md;
    int mid=n/2;
    if(n%2==0){
        md = (1L*sticks[mid]+(1L)*sticks[mid-1])/2;
    }else{
        md = (sticks[mid]);
    }
    LL res =0;
    trav(x,sticks) {res += abs(x-md);}
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N ;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    cout << solve(N,vec);
    return 0;
}
