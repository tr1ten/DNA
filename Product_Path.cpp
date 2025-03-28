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
int n,m,p,q;
int get_cost(int x,int y){
    return (n%x ? 0 : max(x,n/x)) +(m%y ? 0 : max(y,m/y));
}
int bfs(int x,int y,int tx,int ty,int minx,int miny,int maxx,int maxy){
    priority_queue<vi,vii,greater<vi>> pq;
    map<tuple<int,int>,int> dp;
    int cost = get_cost(x,y);
    pq.push({x,y,cost });
    dp[{x,y}] = cost;
    vi dx = {1,-1,0,0};
    vi dy = {0,0,-1,1};
    while (pq.size() )
    {
        auto p = pq.top();
        pq.pop();
        if(p.back() > dp[{p[0],p[1]}]) continue;
        // cout << p[0] << " " << p[1] << " " << cost << endl;
        if(p[0]==tx && p[1]==ty) return p.back();
        rep(d,0,4){
            int ix = p[0]+dx[d];
            int iy = p[1] + dy[d];
            if(ix>=minx && ix<=maxx && iy>=miny && iy<=maxy && (dp.count({ix,iy})==0 ||  p.back() + get_cost(ix,iy)<dp[{ix,iy}])) {
                int cost =  p.back() + get_cost(ix,iy);
                dp[{ix,iy}] = cost;
                pq.push({ix,iy,cost});
            }   
        }
    }
    cout << x << ' ' << y << " " << tx <<" " << ty << endl;
    // assert(0);
    return INF;
}
int divisors(long long x,int l,int r){
        int sm = 0;
      for(int j=1;j*j<=x;j++)
		{		
			if(x%j==0)
			{
                if(j<=r && j>=l){
                    sm += max(j,x/j);
                }
                if(x/j!=j && x/j>=l && x/j<=r){
                    sm += max(j,x/j);
                }
            }
        }
    return sm;
}
void testcase(){
    cin >> n >> m >> p >> q;
    int x0=1,y0=1;
    while ((n%x0)==0)
    {
        x0++;
    }
    while ((m%y0)==0)
    {
        y0++;
    }
    if(x0>=p && y0>=q){
        
        put(bfs(1,1,p,q,1,1,x0,y0));
        return;
    }
    if(x0<p && y0<q){
        int c1 = bfs(1,1,x0,y0,1,1,x0,y0);
        int sx = p,sy = q;
        while (n%sx==0)
        {
            sx--;
        }
        while (m%sy==0)
        {
            sy--;
        }

        int maxx=p,maxy=q;
        while (n%maxx==0)
        {
            maxx++;
        }
        while (m%maxy==0)
        {
            maxy++;
        }
        
        int c2 = bfs(sx,sy,p,q,sx,sy,maxx,maxy);
        put(c1+c2 + divisors(n,x0+1,sx-1) + divisors(m,y0+1,sy-1));
        return;
    }
    put(-1);


    
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
