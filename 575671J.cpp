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
/*
    NOT use unordered map use map
    NOT use seg tree use fenwick tree
    THINK before you code
*/

const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;

int dijsktra(int S,int D,vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    vector<int> dist(n,INF);
    vector<int> par(n,-1);
    dist[S] = 0;
    par[S]= -1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0LL,S));
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(u.first>dist[u.second]) continue;
        for(auto &v:adj[u.second]){
            int fd = u.first + v.second;
            if(dist[v.first]>fd){
                dist[v.first] = fd;
                par[v.first] = u.second;
                pq.push(make_pair(dist[v.first],v.first));
            }
        }
    }
    set<pi> st;
    int p = D;
    while (p!=-1 && p!=S)
    {
        st.insert({p,par[p]});
        st.insert({par[p],p});
        // cout << p << "-" << par[p] << endl;
        p = par[p];
    }
    vector<vector<int>> dist2(2,vi(n,INF));
    dist2[0][S] = 0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq2;
    pq2.push({0LL,0LL,S});
    while(!pq2.empty()){
        auto [d,s,u] = pq2.top();
        pq2.pop();
        if(d>dist2[s][u]) continue;
        for(auto &v:adj[u]){
            int fd = d + v.second;
            int se = s || (st.find({u,v.first})==st.end());
            // cout << se <<" "<< u << "->" <<  v.first <<" " << fd << endl;

            if(dist2[se][v.first]>fd){
                dist2[se][v.first] = fd;
                pq2.push({fd,se,v.first});
            }
        }
    }
    // cout << dist2[0][D] << " " << dist2[1][D] << endl;

    return dist2[0][D] + dist2[1][D];
}

void testcase(){
    int n,m;
    cin >> n >> m;
    vector<vector<pi>> adj(n);
    rep(i,0,m){
        int u,v,t;
        cin >> u >> v >> t;
        u--;v--;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    int ans = dijsktra(0,n-1,adj);
    put(ans >= INF ? -1 : ans);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    while(T--) testcase();

    return 0;
}
