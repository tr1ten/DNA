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
int get(int r,int p){   
    if(r<0) return 0;
    return r/p + 1;
}
void testcase(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    rep(i,0,30){
        int p = 1LL<<i;
        if(r1-p<l1 || r2-p<l2) break;
        int cnt = (get(r1-p,p)-get(l1-1,p))*(get(r2-p,p)-get(l2-1,p));
        // cout << i << " " << cnt<< endl;
        ans += i==0 ? cnt : -3*cnt;
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
