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
class BIT {
private:
    std::vector<int> nums;
    int LOG;
public:
    BIT(int n) {
    	LOG = (int)log2(n)+1;
        nums.resize((1ll<<LOG) + 1);
    }
    void update(int i, int val) {
        i += 1;
        while (i < nums.size()) {
            nums[i] += val;
            i += (i & (-i));
        }
    }
    int sum(int i) {
        int r = 0;
        // i += 1, not needed here since we need sum of rank less than i rank[0...i-1]
        while (i > 0) {
            r += nums[i];
            i -= (i & (-i));
        }
        return r;
    }
};

void testcase(){
    int n,m;
    cin >> n >> m;
    BIT fen(n);
    vi last(m+1,-1);
    vi first(m+1,n);
    
    int cont = 0;
    vi a(n);
    tkv(a,n);
    
    rep(i,0,n){
        int x = a[i];
        int add = fen.sum(i)-fen.sum(last[x]+1);
        cont +=add;
        if(last[x]!=-1) fen.update(last[x],-1);
        fen.update(i,1);
        last[x] = i;
        first[x] = min(i,first[x]);
    }
    int total_unique = fen.sum(n);
    rep(i,0,n){
        int x = a[i];
        if(first[x]==i) {
            fen.update(last[x],-1);
            cont += fen.sum(n) - fen.sum(i+1);
        }
    }
    rep(i,1,m+1){
        if(last[i]==-1){
            cont += total_unique;
        }
    }
    put(cont);
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
