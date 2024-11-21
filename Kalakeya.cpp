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
    if(k>n/2){
        put(-1);
        return;
    }
    vi res(n);
    iota(all(res),1);
    if(k==0){
        pvc(res);
        return;
    }
    for(int i=1;i<=n;i+=2*k){
        auto start = res.begin() + i-1;
        auto end = start+2*k;
        if(end>res.end()){
            int rem = end-res.end();
            start = start-min(k,rem);
            end = res.end();
        }
        rotate(start,start+k,end);
    }
    rep(i,1,n+1){
        assert(abs(i-res[i-1])>=k);
    }
    pvc(res);
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
