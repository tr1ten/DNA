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
    int getlr(int l,int r){
        return sum(r+1)-sum(l);
    }
};


void testcase(){
    int n,k;
    cin >> n >> k;
    vii cs(k,vi(3));
    rep(i,0,k){ 
        cin >> cs[i][0] >> cs[i][1] >> cs[i][2];
        cs[i][0]--;cs[i][1]--;
    }
    sort(all(cs),[&](vi &a,vi &b){
        return a[2]<b[2];
    });
    int i = 0;
    vi ans(n,-1);
    BIT present(n);
    int cnt = 0;
    int cur = 1;
    while (cur<n+1)
    {
        vi poss(n+1);
        while(i<k && cs[i][2]==cur){
            if(present.getlr(cs[i][0],cs[i][1])==0) {
                poss[cs[i][0]]+=1;
                poss[cs[i][1]+1]-=1;
            }
            i++;
        } 
        rep(i,0,n){
            if(poss[i]==0 && ans[i]==-1){
                ans[i] = cur;
                present.update(i,1);
                cnt++;
            }
            poss[i+1] += poss[i];
        }
        cur++;
        if(cnt==n) break;
    }
    if(cnt<n){
        put(-1);
        return;
    }
    pvc(ans);
    

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
