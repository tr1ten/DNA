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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void testcase(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    tkv(a,n);
    int M = 30;
    unordered_map<int,int,custom_hash> mxi[M];  
    rep(i,0,M) mxi[i].reserve(6*n);    
    int ans = n+1;
    rep(i,0,n){
        int match = 0;
        int last_i = -n;
        per(j,0,M){
            int x = a[i]>>j;
            int y = k>>j;
            mxi[j][x] = max(mxi[j][x],i);
            match = (match<<1) | (((y)^x)&1);
            if(((y)&1)==0){
                if(mxi[j].find(match^1)!=mxi[j].end()){
                    last_i = max(last_i,mxi[j][match^1]);
                }
            }
        }
        if(mxi[0].find(match)!=mxi[0].end()) last_i = max(last_i,mxi[0][match]);
        ans = min(ans,i-last_i+1);
    }
    put(ans<=n ? ans : -1);
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
