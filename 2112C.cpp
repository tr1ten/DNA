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
    // max index where sum A[0...ind] < x,return index of first number greator than or equal to x
    int sum(int l,int r){
        if(l>r) return 0;
        return sum(r+1) -sum(l);
    }
};
const int MAXN = 2*1e5+5;
BIT fw(MAXN);
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    int ans = 0;
    per(i,0,n){
        rep(j,0,i){
            ans += fw.sum(max(a.back()-a[i]-a[j],-1LL)+1,a[i]+a[j]-1);
        }
        fw.update(a[i],1);
    }   
    per(i,0,n){
        fw.update(a[i],-1);
    }    
    put(ans);
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
