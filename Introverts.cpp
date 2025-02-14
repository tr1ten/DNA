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
vi b;
void f(int l,int r){
    if(r-l+1<=2) return;
    int mid = (r+l)/2;
    b.push_back(min(mid-l-1,r-mid-1));
    f(l,mid);
    f(mid,r);
}
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    if(n==1){
        put("YES")
        return;
    }
    else if(!((a[0]==1 && a[n-1]==2) || (a[0]==2 && a[n-1]==1))) {
        put("NO");
        return;
    }
    b.clear();b.push_back(n-2);
    f(0,n-1);
    srv(b);
    reverse(all(b));
    set<int> inds;
    inds.insert(0);
    inds.insert(n-1);
    vi iis(n);
    iota(all(iis),0);
    sort(all(iis),[&](int i,int j) {
        return a[i]<a[j];
    });
    rep(i,2,n){
        auto up = inds.lower_bound(iis[i]);
        int ds = min(*up-iis[i]-1,iis[i]- *prev(up)-1);
        // cout << i <<" " << ds << endl;
        if(ds!=b[i-1]){
            put("NO");
            return;
        }
        inds.insert(iis[i]);
    }
    put("YES");
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
