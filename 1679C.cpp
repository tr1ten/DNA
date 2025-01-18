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
    // max index where sum A[0...ind] < x,return index of first number greator than or equal to x
    int lower(int x){
        ll pref = 0;
        int ind = 0;
        for(int i=LOG;i>=0;i--){
            if(nums[ind + (1ll<<i)] + pref<x){
                pref += nums[ind + (1ll<<i)];
                ind += 1ll<<i;
            }
        }
        return ind; // 0  based
    }
    
};
void testcase(){
    int n,q;
    cin >> n >> q;
    BIT fx(n),fy(n);
    vi cntx(n),cnty(n);
    rep(i,0,q){
        int t;
        cin >> t;
        if(t==1){
            int x,y;cin >> x >> y;
            x--;y--;
            if((cntx[x]++)==0) fx.update(x,1);
            if((cnty[y]++)==0) fy.update(y,1);
        }
        else if(t==2){
            int x,y;cin >> x >> y;
            x--;y--;
            if((--cntx[x])==0) fx.update(x,-1);
            if((--cnty[y])==0) fy.update(y,-1);
        }
        else {
            int x1,x2,y1,y2;cin >> x1 >> y1 >> x2 >>y2;
            x1--;x2--;y2--;y1--;
            int sx= fx.sum(x2+1)-fx.sum(x1);
            int sy = fy.sum(y2+1) - fy.sum(y1);
            put(((sx==(x2-x1+1)) || (sy==(y2-y1+1))) ?  "Yes": "No")

        }
    }


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
