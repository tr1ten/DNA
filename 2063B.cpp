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
    vi a(n);
    tkv(a,n);
    l--;r--;
    vi left;
    rep(i,0,l) {
        left.push_back(a[i]);
    }
    srv(left);
    vi mid;
    rep(i,l,r+1){
        mid.push_back(a[i]);
    }
    srv(mid);
    vi right;
    rep(i,r+1,n) {
        right.push_back(a[i]);
    }
    srv(right);
    int ans1 = 0,ans2=0;
    int j =0;
    per(i,0,mid.size()){
        if(j<left.size() && left[j]<mid[i]) {
            ans1 += left[j];
            j++;
        }
        else ans1 += mid[i];
    }
    j = 0;
    per(i,0,mid.size()){
        if(j<right.size() && right[j]<mid[i]) {
            ans2 += right[j];
            j++;
        }
        else ans2 += mid[i];
    }
    put(min(ans1,ans2));
    
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
