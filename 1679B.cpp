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
    int n,q;
    cin >> n >> q;
    vi a(n);
    tkv(a,n);
    vi lst(n,-1);
    pi aa = {0,-1};
    int sm =accumulate(all(a),0LL);
    rep(i,0,q){
        int t;
        cin >> t;
        if(t==1){
            int idx,x;
            cin >> idx >> x;
            idx--;
            if(aa.second>lst[idx]){
                a[idx] = aa.first;
                lst[idx] = aa.second;
            }
            sm += x-a[idx];
            a[idx]=x;
        }
        else {
            int x;
            cin >> x;
            aa = {x,i};
            sm = x*n;
        }
        put(sm);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    while(T--) testcase();

    return 0;
}
