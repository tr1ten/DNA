#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs

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
void testcase(){
    int n,q;
    cin >> n >> q;
    vi a(n),b(n);
    tkv(a,n);
    tkv(b,n);
    vi bk_a = a,bk_b = b;
    srv(a);
    srv(b);
    int j = n-1;
    int ans = 1;
    rep(i,0,n){
        ans = ans*min(a[i],b[i])%MOD;
    }
    cout << ans <<" ";
    rep(i,0,q){
        int o,x;
        cin >> o >> x;
        x--;
        if(o==1){
            int p = upper_bound(all(a),bk_a[x])-a.begin()-1;
            if(a[p]<b[p]) ans = (ans*fast_pow(a[p],MOD-2,MOD)%MOD)*(a[p]+1)%MOD;
            a[p]++;bk_a[x]++;
        }
        else {
            int p = upper_bound(all(b),bk_b[x])-b.begin()-1;
            if(a[p]>b[p]) ans = (ans*fast_pow(b[p],MOD-2,MOD)%MOD)*(b[p]+1)%MOD;
            b[p]++;bk_b[x]++;
        }
        cout << ans << " ";
    }
    cout << endl;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
