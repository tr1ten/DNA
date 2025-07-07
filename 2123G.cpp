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
int mod(int a, int m){
    return (a % m + m) % m;
}
void testcase(){
    int n,m,q;
    cin >> n >> m >> q;
    vi a(n);
    tkv(a,n);
    map<int,int> diffs;
    for(int i=1; i*i<=m; i++)
        if(!(m % i)){
            diffs[i] = 0;
            diffs[m/i] = 0;
        }
    for(auto d:diffs){
        diffs[d.first] += a[0]%d.first;
        rep(i,1,n){
            diffs[d.first] += mod(a[i]-a[i-1],d.first);
        }
    }
    rep(z,0,q){
        int x;
        cin >> x;
        if(x==1){
            int idx,val;
            cin >> idx >> val;
            idx--;
            for(auto d:diffs){
                int prev = idx ? a[idx-1] : 0;
                diffs[d.first] -= mod(a[idx]-prev,d.first);
                diffs[d.first] += mod(val-prev,d.first);
                if(idx+1<n){
                    diffs[d.first] -= mod(a[idx+1]-a[idx],d.first);
                    diffs[d.first] +=mod(a[idx+1]-val,d.first);
                }
            }
            a[idx] = val;
        }
        else {
            int k;
            cin >> k;
            int g = __gcd(k,m);
            assert(diffs.count(g));
            if(diffs[g]<m){
                put("YES");
            }   
            else put("NO");
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
    cin>>T;
    while(T--) testcase();

    return 0;
}
