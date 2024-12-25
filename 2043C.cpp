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
pi pp(vi a,set<int> &st){
    int mn=0,mx=0;
    int mxp =0,mnp = 0;
    int sm =0;
    rep(i,0,a.size()){
            sm +=a[i];
            mxp = max(mxp,sm);
            mnp = min(mnp,sm);
            mx = max(sm-mnp,mx);
            mn = min(sm-mxp,mn);
    }
    rep(i,mn,mx+1){
        st.insert(i);
    }
    pi aa= {sm-mxp,sm-mnp};
    return aa;
}
void testcase(){
    int n;
    cin >> n;
    
    set<int> st{0};
    vi a,b;
    int f = 0;
    int X;
    rep(i,0,n){
        int x;
        cin >> x;
        if(abs(x)==1){
            if(f) b.push_back(x);
            else a.push_back(x);
        }
        else {X=x;f=1;}
    }
    pi a1 = pp(a,st);
    reverse(all(b));
    pi b2 = pp(b,st);
    if(f){
        st.insert(X);
        int start = min({a1.first+b2.first,a1.first,b2.first});
        int end = max({a1.second+b2.second,a1.second,b2.second});
        rep(i,start,end+1){
            st.insert(X+i);
        }
    }
    put(st.size());
    for(auto x:st){
        cout << x << " ";
    }
    cout << endl;
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
