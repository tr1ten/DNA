#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
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
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
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
    int n,m,k;
    cin >> n >> m >> k;
    vi hs(n),xs(n);
    tkv(hs,n);
    tkv(xs,n);
        auto getr = [&](int i,int  a){
        return (a*(m+xs[i])-hs[i])/a;
    };
    auto getl=  [&](int i,int a){
        return (hs[i]-a*(m-xs[i])+a-1)/a;
    };
    auto check = [&](int a){
        vector<pi> ms;
        rep(i,0,n){
            int rb = getr(i,a);
            int lb = getl(i,a);
            if(rb<lb) continue;
            ms.push_back({rb,1});
            ms.push_back({lb,-1});
        }
        sort(all(ms));
        int ans =0;
        int cnt = 0;
        for(auto [x,y]:ms){
            cnt += y*-1;
            ans = max(ans,cnt);
        }
        
        return ans>=k;
    };
    int lo = 1,hi = 1e9+1;
    int ans = -1;
    while (lo<=hi)
    {
        int mid =(lo+hi)/2;
        if(check(mid)){
            ans= mid;
            hi  =mid-1;
        }
        else lo = mid+1;
    }
    cout << ans << endl;
    

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
