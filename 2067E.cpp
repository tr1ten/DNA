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
    vi a(n);
    tkv(a,n);
    set<int> st;
    rep(i,0,n+1) st.insert(i);
    int zc = 0;
    map<int,int> cnt;
    vi b;
    rep(i,0,n){
        if(st.count(a[i])) {
            st.erase(a[i]);
        }
    }
    int mex = *st.begin();
    if(mex==0){
        put(n);
        return;
    }
    rep(i,0,n){
        if(a[i]<mex){
          b.push_back(a[i]);cnt[a[i]]++;
        }
        if(a[i]==0) zc++;
    }
    int ans = n-zc;
    int mn=INF;
    rep(i,0,b.size()){
        if(cnt[b[i]]==1 || b[i]==0){
            mn = min(mn,b[i]);
        }
        else {
            if(mn>=b[i]){
                put(ans);
                return;
            }
        }
    }
    put(ans+1);

    
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
