#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
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

VI subset_sum(VI& vec,int left,int right){
    int n = right-left+1;
    mk_vec(sums,1<<n,0);
    FOR(mask,0,1<<n){
        LL sm=0;
        FOR(i,0,n){
            if((mask&(1<<i))>0) sm+=vec[left+i];
        }
        sums[mask] = (sm);
    }
    return sums;
}
// actual solutions 
LL solve(int n,int k,VI &vec){
    VI left_sums = subset_sum(vec,0,(n/2)-1);
    VI right_sums = subset_sum(vec,(n/2),n-1);
    sort_vec(right_sums);
    LL res = 0;
    trav(sm,left_sums){
        LL target = k-sm;
        auto eq= upper_bound(right_sums.begin(),right_sums.end(),target-1);
        auto larger= upper_bound(right_sums.begin(),right_sums.end(),target);
        res += larger-eq;
    }
    return res;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    cin>>N >> K;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    cout << solve(N,K,vec);
    return 0;
}
