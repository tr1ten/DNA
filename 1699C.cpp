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
typedef long long ll;
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

const int N = 2*(1e5) + 5;
long long fact[N];
long long inv[N];
long long finv[N];

void pre() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= N; i++) {
        finv[i] = (inv[i]*finv[i-1])%MOD;
    }
}

long long nCk(int n,int k) {
    return (((fact[n]*finv[k])%MOD)*finv[n-k])%MOD;
}


void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    BIT bit(n);
    int l,r;
    vi ind(n);
    rep(i,0,n){
        ind[a[i]] = i;
        if(a[i]==0){
            l=i,r=i;
        }
    }
    set<int> mex;
    rep(i,1,n+1){
        mex.insert(i);
    }
    bit.update(0,1);
    int ans = 1;
    while (*mex.begin()<n)
    {
        int mx = *mex.begin();
        int big= 0;
        while(ind[mx]<l){
            l--;
            big++;
            bit.update(a[l],1);
            mex.erase(a[l]);
        
        }
        while(ind[mx]>r){
            r++;
            big++;
            bit.update(a[r],1);
            mex.erase(a[r]);
        }
        big--;
        int tb = bit.sum(n)-bit.sum(mx+1);
        int old = tb-big;
        // cout << tb << " " << old << " " << l << " " << r << endl;
        ans = ans*fact[tb]%MOD;
        ans = ans*finv[old]%MOD;
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
    pre();
    while(T--) testcase();

    return 0;
}
