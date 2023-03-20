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
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;
// similar to binary lifiting
// number of planets and queries
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    VI next(N,0);
    VII prev(N,VI());
    FOR(i, 0, N)
    {
        int a;
        cin >> a ;
        next[i] = a-1;
        prev[next[i]].push_back(i);
    }
    // cid > 0 cycle
    // == -1 part of tree
    // == -2 not processed yet
    VI cycle_id(N,-2);
    unordered_map<int,int> cycle_len; // id - length of cycle
    FOR(u,0,N){
        if(cycle_id[u]!=-2) continue;
        VI path{u};
        int cur = u;
        while (cycle_id[next[cur]]==-2) {
            cur = next[cur];
            cycle_id[cur] = -3;
            path.push_back(cur);
        }
        bool isCycle = false;
        trav(v,path){
            isCycle |= v==next[cur];
            cycle_id[v] = isCycle ?  cycle_len.size() : -1;
        }
        if(isCycle) cycle_len[cycle_id[u]] = path.size()-1; 
    }
    VI dist(N,0); // node distance from root (or cycle)
    FOR(u,0,N){
        if(cycle_id[next[u]]==-1 || cycle_id[u]!=-1) continue; // if part of cycle or not root
        stack<int> st;
        dist[u] = 1;
        st.push(u);
        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            trav(x,prev[v]){
                dist[x] = dist[v] + 1;
                st.push(x);
            }
        }
        
    }
    FOR(u,0,N){
        cout << dist[u] + (cycle_id[u]>=0 ? cycle_len[cycle_id[u]] : 0 )<< " ";
    }
    cout << endl;
    return 0;
}
