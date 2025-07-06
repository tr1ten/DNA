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
// O(LlogL)
vector<long long> divisors(long long x){
    vector<long long> cur;
      for(int j=2;j*j<=x;j++)
		{		
			if(x%j==0)
			{
				cur.push_back(j);
				if(j != x/j)
					cur.push_back(x/j);
            }
        }
    return cur;
}
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
    int n,m,q;
    cin >> n >> m >> q;
    vi a(n);
    tkv(a,n);
    auto div = divisors(m);
    unordered_map<int,BIT> diffs;
    for(auto d:div){
        vi c(n);
        int last = 0;
        rep(i,0,n){
            int st = (a[i]-(a[i]/d)*d);
            int cur = st + ((max(0LL,last-st)+d-1)/d)*d;
            c[i] = cur;
            last = cur;
        }
        diffs[d] = BIT(n);
        diffs[d].update(0,c[0]);
        rep(i,1,n){
            diffs[d].update(i,c[i]-c[i-1]);
        }

        
    }
    rep(i,0,q){
        int x;
        cin >> x;
        if(x==1){
            int idx,val;
            cin >> idx >> val;
            idx--;
            for(auto d:div){
                int cur = diffs[d].sum(0,idx);
                if(val>cur){
                    
                }
                else {

                }
            }
        }
        else {
            int k;
            cin >> k;
            int g = __gcd(k,m);
            if(diffs[g].sum(0,n-1)<m){
                put("YES");
            }
            else put("NO");
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
    cin>>T;
    while(T--) testcase();

    return 0;
}
