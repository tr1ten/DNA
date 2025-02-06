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
const int N = 2*(1e5) + 4;
int g[N];
long long fast_pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
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
        while (i > 0) {
            r += nums[i];
            i -= (i & (-i));
        }
        return r;
    }
};

int A = 7;
void testcase(){
    int n;
    cin >> n;
    vi arr(n);
    rep(i,0,n){
        int x;
        cin >> x;
        arr[i] = g[x];
        assert(arr[i]<A);
    }
    vector<BIT>  cnt(A,BIT(n));
    rep(i,0,n){
        cnt[arr[i]].update(i,1);
    }
    int q;
    cin >> q;
    rep(i,0,q){
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1){
            vi cc(A);
            a--;b--;
            rep(j,0,A){
                cc[j] = cnt[j].sum(b+1) - cnt[j].sum(a);
            }
            int ccc=1;
            vi pok;
            rep(j,0,A){
                if(cc[j]==0) continue;
                pok.push_back(j);
                ccc = ccc*fast_pow(2,cc[j]-1,MOD)%MOD;
            }
            int ans=0;
            rep(mask,0,1<<pok.size()){
                int cur = 0;
                rep(j,0,pok.size()){
                    if(mask&(1<<j)){
                        cur = cur^pok[j];
                    }
                }
                if(cur!=0){
                    ans +=ccc;
                    ans %=MOD;
                }
            }
            cout << ans << endl;

        }
        else {  
            int v=a,x=b;
            v--;
            cnt[arr[v]].update(v,-1);
            arr[v] = g[x];
            cnt[arr[v]].update(v,1);
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
    rep(i,1,N){
        int r =i;
        set<int> st;
        while (r>0)
        {
            if(r%10) {
                st.insert(g[i-r%10]);
            }
            r/=10;
        }
        rep(mex,0,st.size()+2){
            if(st.count(mex)==0){
                g[i] = mex;
                break; 
            }
        }
    }
    // cin>>T;
    while(T--) testcase();

    return 0;
}
