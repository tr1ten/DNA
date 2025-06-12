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
vector<int> toposort(vector<vector<int>> &g) {
    int n = g.size();
    vector<int> ind(n);
    for(int i=0;i<n;i++) {
        for(int v:g[i]) {
            ind[v]++;
        }
    }
    queue<int> q;
    rep(i,0,n) {
        if(ind[i]==0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (q.size())
    {
        int u = q.front();
        topo.push_back(u);
        q.pop();
        for(int v:g[u]) {
            if((--ind[v])==0){
                q.push(v);
            }
        }
    }
    // assert((int)topo.size()==n);
    return topo;
}
void testcase(){
    int n;
    cin >> n;
    vii g(n);
    vi a(n);
    tkv(a,n);
    int it = 1;
    vector<pi> b;
    rep(i,0,n){
        b.push_back( {i,a[i]} );
    }
    while (b.size()>1)
    {
        
        // if(it==n) break;
        vector<pair<int,int>> c;
        // cout << "iteration " << it << endl;
        rep(i,0,b.size()){
            if(b[i].second>it || b[i].second==-1) {
                if(it%2){
                    if(i) g[b[i].first].push_back(b[i-1].first);
                    if(i+1<b.size()) g[b[i].first].push_back(b[i+1].first);
                }
                else {
                    if(i) g[b[i-1].first].push_back(b[i].first);        
                    if(i+1<b.size()) g[b[i+1].first].push_back(b[i].first);
                }
                c.push_back(b[i]);
                // cout << b[i].first <<" " << b[i].second << endl;
            }  
        }
        int i = 0;
        while (i<b.size())
        {
            if(b[i].second!=it) {
                i++;
                continue;
            }
            int j = i;
            while (j<b.size() && b[j].second==it)
            {
                j++;
            }
            if(((i>0)^(it&1))==0){
                rep(k,i+1,j){
                    g[b[k-1].first].push_back(b[k].first);
                }
            }
            else {
                rep(k,i,j-1){
                    g[b[k+1].first].push_back(b[k].first);
                }
            }
            i = j;
        }
        
        b = c;
        it++;
        
    }
    // rep(i,0,n){
    //     pvc(g[i]);
    // }
    vi topo =  toposort(g);
    vi ans(n);
    rep(i,0,n){
        ans[topo[i]] = i+1;
    }
    pvc(ans);
    
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
