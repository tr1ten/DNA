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
        int res =sum(r+1) - sum(l);
        // cout << l << "->"<<r<< " = " << res <<endl;
         return res;
    }
    
};

void testcase(){
    int n;
    cin >> n;
    string t;
    cin >> t;
    auto solve = [&](string s,int neq=1) {
        vector<int> pref(n+1);
        vector<int> inds;
        rep(i,0,n){
            pref[i+1]=pref[i] + (s[i]-'0');
            inds.push_back(i-2*pref[i]);
        }
        inds.push_back(n-2*pref[n]);
        srv(inds);
        unordered_map<int,int> rm;
        int j =0;
        rep(i,0,n+1){
            if(rm.count(inds[i])==0) rm[inds[i]]=j++;
        }
        BIT fsm(j),fcnt(j);
        fcnt.update(rm[0],1);
        int ans = 0;
        rep(i,1,n+1){
            int index = rm[i-2*pref[i]];
            int cnt = fcnt.sum(index+neq,j-1);
            int sm = fsm.sum(index+neq,j-1);
            ans += cnt*pref[i] - sm;
            fsm.update(index,pref[i]);
            fcnt.update(index,1);

        }
        return ans;
    };
    int a1 = solve(t);
    rep(i,0,n) {
        t[i] = ((t[i]-'0')^1) + '0';
    }
    a1 += solve(t,0);
    cout << a1 << endl;
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
