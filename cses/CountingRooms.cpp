#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef vector<VI> VII;
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

void dfs(int x,int y,VII &mat,vector<vector<bool>> &vis){
    int adj[4][2]  = {{0,-1},{-1,0},{1,0},{0,1}};
    vis[y][x] = true;
    trav(dxy,adj){
        int i=dxy[1]+y,j=x+dxy[0];
        if(i>=0 && j>=0 && i<vis.size() && j<vis[0].size() && !vis[i][j] && mat[i][j]==0){
            dfs(j,i,mat,vis);
        }
    }

}

// actual solutions 
int solve(int n,int m,VII &mat){
    int res =0 ;
    vector<vector<bool>> vis(n,vector(m,false));
    FOR(i,0,n){
        FOR(j,0,m){
            if(mat[i][j]==0 && !vis[i][j]){
                dfs(j,i,mat,vis);
                res+=1;
            }
        }
    }
    return res;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin>>N >> M;
    VII mat(N,VI(M));
    F0R(i,N){
        F0R(j,M){
            char c;
            cin>>c;
            mat[i][j] = c=='#'?1:0;
        }
    }
    cout << solve(N,M,mat) << endl;
    return 0;
}
