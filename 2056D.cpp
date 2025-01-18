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
void testcase(){
    int m;
    cin >> m;
    vi A(m);
    tkv(A,m);
    int ans = 0;
    rep(c,1,11){
        vi b=A;
        rep(i,0,m){
            if(b[i]==c) b[i] =1;
            else if(b[i]>c) b[i]=2;
            else b[i] = 0;
        } 
        int c0=0,c01=0;
        BIT bita(2*m),bitb(2*m);
        bita.update(m,1);
        bitb.update(m,1);
        unordered_map<int,int> cur,old;
        cur[m] = 1;
        rep(i,1,m+1) {
            if(b[i-1]==1) {
                for(auto x:cur) {
                    old[x.first] +=x.second;
                }
                cur.clear();
            }
            c0 += b[i-1]==0;
            c01 += b[i-1]<=1;
            int x=2*c01-i;
            int y = 2*c0 - i;
            int cnt = bita.sum(x+m);
            cnt -= bitb.sum(y+m); // need to subs 2*c0i - i = 2*c0j - j, c1i==c1j
            cnt -= old[y+m];
            cur[y+m] +=1;
            bita.update(x+m,1);
            bitb.update(y+m,1);
            ans +=max(0LL,cnt);
        }
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
