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

// actual solutions 1-based indexing
void dfs(int x,int y,LL val,int n,int m,unordered_map<LL,LL> cnt[],VII mat){
    if(x+y==(n+m)/2+1){ // if point on diagonal
        ++cnt[y][val];
        return;
    }
    if(y<n) dfs(x,y+1,val^mat[y+1][x],n,m,cnt,mat);
    if(x<m) dfs(x+1,y,val^mat[y][x+1],n,m,cnt,mat);

}
void dfs2(int x,int y,LL val,int n,int m,unordered_map<LL,LL> cnt[],VII &mat,LL &ans,LL K){
    if(x+y==(n+m)/2+1){ // if point on diagonal
        ans += cnt[y][val^mat[y][x]^K]; // since diagonal point added twice already need to do one more time to get only once
        return;
    }
    if(y>1) dfs2(x,y-1,val^mat[y-1][x],n,m,cnt,mat,ans,K);
    if(x>1) dfs2(x-1,y,val^mat[y][x-1],n,m,cnt,mat,ans,K);

}
LL solve(VII &mat, int N, int M, LL K){
    unordered_map<LL,LL> cnt[N+1]; // cnt[x][xor_value] represent number of ways to get val in that diagonal
    LL ans = 0;
    dfs(1,1,mat[1][1],N,M,cnt,mat);
    dfs2(M,N,mat[N][M],N,M,cnt,mat,ans,K);
    return ans;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL N,M,K;
    cin>>N>>M>>K;
    VII mat(N+1,VI(M+1));
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            cin>>mat[i][j];
        }
    }
    cout<<solve(mat,N,M,K)<<endl;
    return 0;
}
