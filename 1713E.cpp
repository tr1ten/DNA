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

class DSU
{
public:
    int *par;
    int *sz;
    DSU(int n)
    {
        this->par = new int[n];
        this->sz = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->par[i] = i;
            this->sz[i] = 1;
        }
    }
    int find(int x)
    {
        int p = x;
        while (p != this->par[p])
        {
            p = par[p];
        }
        return p;
    }
    void connect(int u, int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if (rootu == rootv)
            return;
        if (sz[rootu] < sz[rootv])
        {
            par[rootu] = rootv;
            sz[rootv] += sz[rootu];
        }
        else
        {
            par[rootv] = rootu;
            sz[rootu] += sz[rootv];
        }
    }
};

void testcase(){
    int n;
    cin >> n;
    vii a(n,vi(n));
    rep(i,0,n){
        rep(j,0,n){
            cin >> a[i][j];
        }
    }
    DSU ds(2*n);
    rep(i,0,n){
        rep(j,0,n){
            if(a[i][j]==a[j][i]){
                continue;
            }
            if(a[i][j]<a[j][i]){
                if(ds.find(i<<1)!=ds.find((j<<1) + 1)){
                    ds.connect(i<<1,j<<1);
                    ds.connect((i<<1)+1,(j<<1)+1);
                }
            }
            else {
                if(ds.find(i<<1)!=ds.find((j<<1) )){
                    ds.connect((i<<1)+1,j<<1);
                    ds.connect((i<<1),(j<<1)+1);
                }
            }
        }
    }
    vii ans=a;
    rep(i,0,n){
        rep(j,i+1,n){
            if(ds.find(i<<1)!=ds.find(j<<1)){
                swap(ans[i][j],ans[j][i]);
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
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
