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

bool detect_cycle(int u,vector<set<int>> &adj,vi &states){
    if(states[u]!) return false;
    states[u] = 1;
    for(auto v:adj[u]){
        if(states[v]){
            if(states[u]==1) return true;
        }
        else {
            bool chk = detect_cycle(v,adj,states);
            if(chk) return true;
        }
    }

    states[u] =2;
    return false;
}
void testcase(){
    int n,m;
    cin >> n >> m;
    vii A(n,vi(m)),B(n,vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin >> A[i][j];
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            cin >> B[i][j];
        }
    }
    rep(bit,0,31){
        // cout << "Solving for bit " << bit << endl;
        vector<bool> asg(n+m);
        vector<set<int>> adj(n+m);
        rep(i,0,n){
            rep(j,0,m){
                int a1=((A[i][j]>>bit)&1),b1=(B[i][j]>>bit)&1;
                if(a1!=b1){
                    if(a1) asg[i+m] = 1;
                    else asg[j] = 1;
                }
                if(b1) adj[i+m].insert(j);
                else adj[j].insert(i+m); 
            }
        }
        // this will create directed graph, where some component might create cycle now we just have to see whehter we can reach those cycle by doing necc ops
        vi states(n+m);
        rep(i,0,n+m){
            if(asg[i] && detect_cycle(i,adj,states)) {
                put("No");
                return;
            }
        }

    }
    put("Yes")
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
