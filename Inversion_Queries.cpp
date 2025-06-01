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
    int sum(int l,int r){
        return sum(r+1) - sum(l);
    }
    
};

void testcase(){
    int n,q;
    cin >> n >> q;
    vi ind(n);
    rep(i,0,n){
        int x;
        cin >> x;
        ind[--x] = i;
    }
    vi invs_l(n),invs_r(n);
    BIT bit(n);
    int tot = 0;
    rep(i,0,n){
        int index = ind[i];
        tot += bit.sum(index,n-1);
        invs_l[i] = tot;
        bit.update(index,1);
    }
    BIT bit2(n);
    tot = 0;
    per(i,0,n){
        int index = ind[i];
        tot += bit2.sum(0,index);
        invs_r[i] = tot;
        bit2.update(index,1);
        // cout << i <<" " << index << " " << tot << endl;
    }
    // pvc(invs_l);pvc(invs_r);pvc(ind);
    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        l--;r--;
        if(l==r){
            put(0);
            continue;
        }
        put(tot-invs_l[l]-invs_r[r]);
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
