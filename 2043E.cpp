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


// O(N + M)
// checker: https://codeforces.com/contest/1971/submission/260766599
struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
    void impl(int a,bool na,int b,bool nb) {
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }
    void force_var(int a,int na){
        a = 2 * a ^ na;
        int neg_a = a ^ 1;
        adj[neg_a].push_back(a);   
        adj_t[a].push_back(neg_a);   
    }

    // static void example_usage() {
    //     TwoSatSolver solver(3); // a, b, c
    //     solver.add_disjunction(0, false, 1, true);  //     a  v  not b
    //     solver.add_disjunction(0, true, 1, true);   // not a  v  not b
    //     solver.add_disjunction(1, false, 2, false); //     b  v      c
    //     solver.add_disjunction(0, false, 0, false); //     a  v      a
    //     assert(solver.solve_2SAT() == true);
    //     auto expected = vector<bool>(True, False, True);
    //     assert(solver.assignment == expected);
    // }
};

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
    rep(bit,0,8){
        TwoSatSolver solver(n+m);
        int mask = 1LL<<bit;
        cout << "Solving for bit " << bit << endl;
        rep(i,0,n){
            rep(j,0,m){
                int a1=((A[i][j]>>bit)&1),b1=(B[i][j]>>bit)&1;
                if(a1 && b1){
                    solver.impl(i+m,0,m,0);
                }
                else if(a1){
                    solver.force_var(i+m,0);
                }
                else if(b1){
                    solver.force_var(j,0);
                }
                else {
                    solver.impl(j,0,i+m,0);
                }
            }
        }
        if(!solver.solve_2SAT()){
            put("No");
            return;
        }
        else pvc(solver.assignment);
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
