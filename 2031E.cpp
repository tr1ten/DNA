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
vii g;
int dfs(int u,int p){
    priority_queue<int,vi,greater<int>> pq;
    for(int v:g[u]){
        if(v!=p){
            int d = dfs(v,u);
            pq.push(d);
        }
    }
    if(pq.size()==0) return 0;
    if(pq.size()==1) return pq.top()+1;
    while (pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(b+1); 
    }
    return pq.top();
    
}
void testcase(){
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    rep(i,1,n){
        int x;
        cin >> x;
        x--;
        g[x].push_back(i);
    }   
    put(dfs(0,-1));



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
