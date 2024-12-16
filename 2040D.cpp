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
vii adj;
const int N = 2*(1e5)+4;
const int MAXN=2*N;
std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
		}
	}
}
int n;
int ass[2*N];
int ans[N];
uint64_t random_address() { char *p = new char; delete p; return uint64_t(p); }
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
 
void bfs() {
    ans[0] = (rng()%(2*n)) + 1;
    ass[(ans[0])]=1;
    ass[0]=1;
    queue<pi> q;
    q.push({0,-1});
    int f=1;
    while (q.size())
    {
        pi u = q.front();
        q.pop();
        for(auto v:adj[u.first]){
            if(v==u.second) continue;
            while ( (ass[(ans[v])] || !is_composite[abs(ans[u.first]-ans[v])] ))
            {
                ans[v] = rng()%(2*n) + 1;
            }
            ass[ans[v]]=1;
            q.push({v,u.first});
        }
    }
}
void testcase(){
    cin >> n;
    adj.clear();
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    rep(i,0,n) ans[i] =0;
    rep(i,1,2*n+1) ass[i] = 0;
    bfs();
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
    sieve(MAXN);
    cin>>T;
    while(T--) testcase();

    return 0;
}
