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
    int n;
    cin >> n;
    vi pos,neg;
    int mx = 0;
    rep(i,0,n){
        int x;
        cin >> x;
        if(x>=0) pos.push_back(x);
        else neg.push_back(x);
        mx = max(mx,x);
    }
    auto check = [&](int x){
        int pref=0;
        int mnp = 0;
        int j = 0;
        rep(i,0,pos.size()){
            while (j<neg.size() && pref+pos[i]-mnp>x)
            {
                pref +=neg[j++];
                mnp  = min(mnp,pref);
            }
            pref += pos[i];
            if(pref-mnp>x) return false;
        }
        return true;
    };
    int lo=mx,hi=1e15;
    int ans = -1;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid)) {
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
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
