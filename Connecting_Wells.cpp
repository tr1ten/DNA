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
#define pvc(vec) for(auto x:vec) cout<<x<<" "; cout<<"\n";
#define put(x) cout << (x)<< "\n";
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
inline int ctz(int x) { return __builtin_ctzll(x);}
inline int pc(int x) {return  __builtin_popcount(x);} 
inline int hset(int x) {return __lg(x);}
#define JAI_SHREE_RAM cin.sync_with_stdio(false); cin.tie(0); cout.tie(0)
/*
    NOT use unordered map use map
    NOT use seg tree use fenwick tree
    THINK before you code
*/

const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};

void testcase(){
    int n;
    cin >> n;
    DSU dsu(n);
    int cnt = n;
    vector< > edges;
    vector<pi> v(n);
    for (auto &[x, y] : v) cin >> x >> y;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            int dx = abs(v[j].first - v[i].first);
            int dy = abs(v[j].second - v[i].second);
            int weight = max(dx, dy);
            if (dy == 0) weight = (dx + 1) / 2;
            if (dx == 0) weight = (dy + 1) / 2;
            edges.push_back({weight,i, j});
        }
    }

    int ans =0;
    srv(edges);
    for(auto &[w,i,j]:edges)
    {
        if(dsu.find(i)!=dsu.find(j)){
            dsu.unite(i,j);
            cnt--;
            ans=w   ;
        }
        if(cnt==1)break;;
    }
    put(ans);
    
}
int32_t main()
{
    JAI_SHREE_RAM;
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
