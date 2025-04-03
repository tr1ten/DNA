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

const int MOD = 998244353; // change me for god sake look at problem mod
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
            nums[i] %=MOD;
            i += (i & (-i));
        }
    }
    int sum(int i) {
        int r = 0;
        // i += 1, not needed here since we need sum of rank less than i rank[0...i-1]
        while (i > 0) {
            r += nums[i];
            i -= (i & (-i));
            r %=MOD;
        }
        return r;
    }
    int get(int i){
        return sum(i+1);
    }
    void update(int l,int r,int val){
        this->update(l,val);
        this->update(r+1,(MOD-val)%MOD);

    }
    BIT(const BIT &bit) {
        this->nums = bit.nums;
        this->LOG = bit.LOG;
    }
};


void testcase(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    tkv(a,n);
    BIT fw(k+2);
    int p =1;
    per(i,0,n){
        if(a[i]==-1){
            BIT fww(fw);
            rep(nxt,2,k+1){
                fww.update(1,nxt-1,fw.get(nxt));
            }   
            fww.update(1,k,p);
            rep(nxt,1,k+1){
                fww.update(nxt,nxt,((k-1)*fw.get(nxt))%MOD);
            }   
            fw = fww;
            p *=k;
            p %=MOD;
        }   
        else {
            int ai = a[i];
            rep(nxt,ai+1,k+1){
                fw.update(ai,ai,fw.get(nxt));
            }   
            fw.update(ai,ai,p);
        }
    }
    int ans = 0;
    rep(i,1,k+1){
        ans += fw.get(i);
        ans %=MOD;
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
