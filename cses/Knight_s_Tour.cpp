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
#define mk_mat(name,n,m,value) vector<vector<LL>> name(n, vector<LL>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;
int N=8;
VII adj{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}}; // possible moves
int poss_moves(int x,int y,VII &board){
    int moves = 0;
    trav(a,adj){
        int nx = x+a[0];
        int ny = y+a[1];
        if(nx>=0 && nx<N && ny>=0 && ny<N && board[ny][nx]==0) moves++;
    }
    return moves;
}
void dfs(int x,int y,int d,VII &board){
    board[y][x] = d;
    int mn=9;
    int nxt[2] = {-1,-1};
    trav(a,adj){
        int nx = x+a[0];
        int ny = y+a[1];
        if(nx>=0 && nx<N && ny>=0 && ny<N && board[ny][nx]==0){
            int moves = poss_moves(nx,ny,board);
            if(moves<mn or (moves==mn and rand()%2)){
                mn = moves;
                nxt[0] = nx;
                nxt[1] = ny;
            }
        }
    }
    if(nxt[0]>=0) dfs(nxt[0],nxt[1],d+1,board);
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int x,y;
    cin>>x >> y;
    x--;
    y--;
    mk_mat(board,N,N,0);
    dfs(x,y,1,board);
    trav(a,board){
        trav(b,a) cout << b << " ";
        cout << endl;
    }
    return 0;
}
