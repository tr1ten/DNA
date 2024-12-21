#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define int long long
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define pvc(vec) for(auto x:vec) cout<<x<<" "; cout<<endl;
#define put(x) cout << (x)<< endl;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
inline int ctz(int x) { return __builtin_ctzll(x);}
inline int pc(int x) {return  __builtin_popcount(x);} 
inline int hset(int x) {return __lg(x);}
/*
    NOT use unordered map use map
    NOT use seg tree use fenwick tree
    THINK before you code
*/

const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;
void testcase(){
    int n,m;
    cin >> n >> m;
    char a[n][m];
    int sti,stj;
    int ei,ej;
    rep(i,0,n){
        string  s;
        cin >> s;
        rep(j,0,m){
            a[i][j] = s[j];
            if(s[j]=='S'){
                sti = i;
                stj = j;
            }
            else if(s[j]=='T'){
                ei = i;
                ej = j;
            }
        }
    }
    priority_queue<tuple<int,int,int,int,int>,vector<tuple<int,int,int,int,int>>,greater<tuple<int,int,int,int,int>>> pq; // steps,dir,cos,i,j
    vector<vector<vector<vector<int>>>> dist(n,vector<vector<vector<int>>>(m,vii(4,vi(4,INF))));
    dist[sti][stj][0][0] = 0;
    vector<int> dirs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
    pq.push({0,0,0,sti,stj});
    while (pq.size())
    {
        auto [steps,dir,cos,i,j] = pq.top();
        pq.pop();
        if(dist[i][j][dir][cos]<steps){
            continue;
        }
        rep(d,0,4){
            int ix = i+dirs[d][0];
            int jx = j+dirs[d][1];
            if(ix<0 || ix>=n || jx<0 || jx>=m || a[ix][jx]=='#') continue;
            int new_dist = steps+1;
            int ncos;
            if(d==dir && cos==3) {ncos =2; new_dist +=2;}
            else {
                ncos = d==dir ? cos+1 : 1;
            }
            if(new_dist < dist[ix][jx][d][ncos]){
                dist[ix][jx][d][ncos] = new_dist;
                pq.push({new_dist,d,ncos,ix,jx});
            }   
        }
        
    }
    int ans = INF;
    rep(i,0,4){
        rep(j,0,4){
            ans = min(ans,dist[ei][ej][i][j]);
        }
    }
    if(ans>=INF) put(-1)
    else  put(ans);
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    // cin>>T;
    while(T--) testcase();

    return 0;
}
