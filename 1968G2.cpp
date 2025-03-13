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
vi zalgo(string& s) {
    vi z(s.size());
    int l=0,r=0;
    rep(i,1,s.size()) {
        if(i<=r) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<s.size() and s[z[i]]==s[i+z[i]]){
            z[i] +=1 ;
        }
        if(i+z[i]-1>r) {
            l = i;
            r = l+z[i]-1;
        }
    } 
    return z;
}
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename it, typename bin_op>
struct sparse_table {
    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op F;
 
    sparse_table(it first, it last, bin_op op) : t(1), F(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = F(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    T query(int l, int r) {
        int h = 31 - __builtin_clz(r-l+1);
        return F(t[h][l], t[h][r-(1<<h)+1]);
    }
};
void testcase(){
    int n,l,r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    vi z = zalgo(s);
    z[0] = n;
    // pvc(z);
    sparse_table st1(all(z), [&](int x, int y) { return max(x, y); }); // not sure why error
    vi ans(n+1);
    rep(i,1,n+1){
        int cur = 0;
        int cnt = 0;
        while (cur<n)
        {
            cnt++;
            cur+=i;
            int lo=cur,hi=n-1;
            int nxt = n;
            while (lo<=hi)
            {
                int mid = (lo+hi)>>1;
                if(st1.query(cur,mid)>=i) {
                    hi = mid-1;
                    nxt = mid;
                }
                else lo = mid+1;
            }
            cur = nxt;
            // cout << i << " " << cur << endl;
        }
        ans[cnt] = max(i,ans[cnt]);
    }
    per(i,0,n){
        ans[i] = max(ans[i],ans[i+1]);
    }
    rep(i,l,r+1) {
        cout << ans[i]<<" ";
    }
    cout << endl;

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
