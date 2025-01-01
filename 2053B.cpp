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
    vi diff(2*n+2);
    vector<pi> a(n);
    rep(i,0,n){
        cin >> a[i].ff >> a[i].ss;
        if(a[i].first==a[i].second){
            diff[a[i].first] +=1;
            diff[a[i].second+1] -=1;
        }
    }
    set<int> st;
    rep(i,1,diff.size()){
        diff[i] +=diff[i-1];
        if(diff[i]==0){
            st.insert(i);
        }
    }
    string s(n,'0');
    rep(i,0,n){
        int need = 0;
        if(a[i].first==a[i].second){
            if(diff[a[i].first]==1) s[i] ='1';
        }
        else {
            auto lt = st.lower_bound(a[i].first);
            if(lt!=st.end() && *lt<=a[i].second){
                s[i] ='1';
            }
        }
    }
    put(s);
    
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
