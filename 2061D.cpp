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
    int n,m;
    cin >> n >> m;
    map<int,int> a,b;
    rep(i,0,n){
        int x;
        cin >> x;
        a[x]++;
    }
    rep(i,0,m){
        int x;
        cin >> x;
        b[x]++;
    }
    while (!b.empty()) {
    auto it = b.begin();
    auto req = *it;  // Store value before erasing
    b.erase(it);

    int d = min(req.second, a[req.first]);
    a[req.first] -= d;
    req.second -= d;

    if (req.second) {
        if (req.first == 1) {
            put("No");
            return;
        }
        if (req.first % 2) {
            b[req.first / 2] += req.second;
            b[req.first / 2 + 1] += req.second;
        } else {
            b[req.first / 2] += 2 * req.second;
        }
    }
}

    int rem = 0;
    for(auto x:a){
        if(x.second!=0){
            put("No");
            return;
        }
    }
    put("Yes");
    
    

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
