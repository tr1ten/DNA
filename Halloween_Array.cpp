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
    int n,l,r;
    cin >> n >> l >> r;
    map<int,int> cnt;
    vi a;
    int f = 0;
    rep(i,0,n){
        int x;
        cin >> x;
        a.push_back(x);
        cnt[x]++;
        if(cnt[x]>1){
            f = 1;
        }
    }
    if(f==1){
        if(l<=0 && 0<=r){
            put("YES");
        }
        else put("NO");
        return;
    }
    else {
        int ans = 1;
        rep(i,0,n){
            rep(j,i+1,n){
                ans = ans*(a[i]^a[j]);
                if(ans>r) {
                    put("NO");
                    return;
                }
            }
        }
        if(ans>=l && ans<=r){
            put("YES");
        }
        else put("NO")
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