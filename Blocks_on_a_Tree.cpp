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
int n,K;
const int N = 2005;

vi g[N];
int flag = 0;
string res;
int par;
int node = -1;
int dfs(int u,int p){
    int total = 1;
    for(int v:g[u]){
        if(v!=p){
            total += dfs(v,u);
        }
    }
    if(total==K){
        flag = 1;
        par=p;
        node = u;
    }
    return total;
}
void dfs2(int u,int p){
    if(K){
        res[u] = '1';
        K--;
    }
    for(int v:g[u]){
        if(v!=p){
         dfs2(v,u);
        }
    }
}
void pp(string res){
    rep(i,0,n){
        cout << res[i] << " ";
    }
    cout << endl;
    return;
}
void testcase(){
    cin >> n >> K;
    res.clear();
    res.resize(n,'0');
    rep(i,0,n){
        g[i].clear();
    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        v--;u--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(K==n || K==0){
        string s(n,(K==0 ? '0' : '1'));
        put(1);
        pp(s);    
        return;
    }
    flag = 0;
    node = -1;
    rep(i,0,n){
        dfs(i,-1);
        if(flag){
            assert(node!=-1);
            dfs2(node,par);
            put(2);
            pp(res);
            return;
        }
    }
    put(3);
    dfs2(0,-1);
    pp(res);


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
