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
void testcase(){
    int n,k,x;
    cin >> n >> k >> x;
    vi a(n);
    tkv(a,n);
    vi pref(n+1);
    rep(i,0,n){
        pref[i+1] +=pref[i] + a[i];
    }
    auto getc= [&](int l) {
        return ((n*k-l)/n)*pref.back() + (l%n ? pref.back()-pref[l%n] : 0LL);
    };
    int lo=0,hi = n*k-1;
    int lr = -1;
    while (lo<=hi)
    {
        int mid = (hi-lo)/2 + lo;
        if(getc(mid)>=x){
            lr = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    put(lr+1);
    
    

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
