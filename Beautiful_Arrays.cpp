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
    vi b;
    map<int,int> cnt;
    rep(i,0,n){
        int x;
        cin >> x;
        cnt[x]++;
        b.push_back(x);
    }
    sort( b.begin(), b.end() );
    b.erase( unique( b.begin(), b.end() ), b.end() );
    rep(i,0,b.size()){
        if(cnt[b[i]]>1){
            if(find(all(b),b[i]*b[i])==b.end()) {
                put("no");
                return;
            }
        }
        rep(j,i+1,b.size()){
            if(find(all(b),b[i]*b[j])==b.end()) {
                put("no");
                return;
            }
        }
    }
    put("yes")
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