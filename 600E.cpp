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
const int N = 1e5 +5;
int mx[N],cur[N],A[N],ans[N];
unordered_map<int,int> sets[N];
vi g[N];
int merge_set(int a,int b){
    if(sets[a].size()<sets[b].size()) swap(a,b);
    if(mx[a] < mx[b]){
        cur[a] = 0;
        mx[a] = mx[b];
    }
    for(auto [x,c]:sets[b]){
        sets[a][x]+=c;
        if(sets[a][x]==mx[a]){
            cur[a] += x;
        }
        else if(sets[a][x]>mx[a]){
            mx[a] = sets[a][x];
            cur[a] = x;
        }
    }
    // cout << "inside " << a << " " << b  <<" " << sets[a].size() << " " << mx[a] << " "<< cur[a] << endl;
    // for(auto [x,c]:sets[a]){
    //     cout <<x  << " " << c << endl;
    // }
    return a;
}
int dfs(int u,int par){
    int cur_set = u;
    mx[cur_set] =1;
    cur[cur_set] = A[u];
    sets[cur_set][A[u]] = 1;
    for(auto v:g[u]){
        if(v!=par){
           cur_set =  merge_set(cur_set,dfs(v,u));
        }
    }
    // cout << u<< " = " << cur_set << endl;  
    ans[u] = cur[cur_set];
    return cur_set;
}
void testcase(){
    int n;
    cin >> n;
    tkv(A,n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1);
    rep(i,0,n){
        cout << ans[i] << " ";
    }
    cout << endl;
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
