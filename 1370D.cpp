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
    int n,k;
    cin >> n >> k;
    vi a(n);
    tkv(a,n);
    auto f = [&](int start,int end,int x,int req){
        int skip = 0;
        rep(i,start,end){
            if(skip){
                skip=0;
                continue;
            }
            if(a[i]>x){
                continue;
            }
            req -=1;
            skip = 1;
            if(req==0) return true;
        }
        return false;
    };
    auto check = [&](int x) {
        if(k%2==0){
            return f(0,n-1,x,k/2) || f(1,n,x,k/2);
        }
        else {
            return f(0,n,x,(k+1)/2) || f(1,n-1,x,k/2);
        }
    };

    int lo=0,hi = 1e9;
    int ans = hi;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans  = mid;
            hi = mid-1;
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
    // cin>>T;
    while(T--) testcase();

    return 0;
}
