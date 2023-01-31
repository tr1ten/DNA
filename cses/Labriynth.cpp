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

void bfs(int x,int y,VII &mat,int endx,int endy){
    queue<PI> q; // x,y,dir
    int n=mat.size(),m=mat[0].size();
    vector<vector<bool>> vis(n,vector(m,false));
    vector<vector<int>> prevMove(n,vector(m,0));
    int dX[] = {0,0,1,-1};
    int dY[] = {1,-1,0,0};
    char dC[] = {'D','U','R','L'};
    q.push({x,y});
    vis[y][x] = true;
    while (!q.empty()) {
        FOR(d,0,4){
            int i=q.front().second+dY[d] ,j=q.front().first+dX[d];
            if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || mat[i][j]==0) continue;
            vis[i][j] = true;
            prevMove[i][j] = d;
            q.push({j,i});
        }
        q.pop();

    }
    if(vis[endy][endx]){
        int i=endy,j=endx;
        string path = "";
        while(i!=y || j!=x){
            int d = prevMove[i][j];
            path +=dC[d];
            i-=dY[d];
            j-=dX[d];
        }
        reverse(path.begin(),path.end());
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        cout<<path<<endl;
        return;
    }
    cout<<"NO"<<endl;
    
}


// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin>>N >> M;
    VII mat(N,VI(M));
    int startx=0,starty=0;
    int endx=0,endy=0;
    F0R(i,N){
        F0R(j,M){
            char c;
            cin>>c;
            // starting A and ending B 
            if(c=='#'){
                mat[i][j] = 0;
            }
            if(c=='A'){
                mat[i][j] = 2;
                startx = j;
                starty = i;
            }
            if(c=='B'){
                mat[i][j] = 3;
                endx = j;
                endy = i;
            }
            if(c=='.'){
                mat[i][j] = 1;
            }
        }
    }
    bfs(startx,starty,mat,endx,endy);
    return 0;
}
