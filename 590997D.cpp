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
int ask(int a,int b,int c){
    
    cout << "? " << a << " " << b << " " << c << endl;
    cout.flush();
    int x;
    cin >> x;
    // int x  = gcd(ansx+a,ansx+b);
    // cout << x << endl;
    return x;
}
void tell(vi x){
    cout << "! ";
    rep(i,0,x.size()){
        cout << x[i] << " ";
    }
    cout << endl;
    cout.flush();
}
void testcase(){
    int n;
    cin >> n;
    int S = 0;
    vi st;
    rep(i,2,n){
        st.push_back(ask(1,2,i+1));
        S += st.back();
    }
    int  X = (S-n*(n+1)/2)/(n-3);
    vi res(n);
    rep(i,0,n-2){
        res[i+2] = st[i] - X;
    }
    res[0] = ask(1,3,4) - (res[2] + res[3]);
    res[1] = ask(2,3,4) - (res[2] + res[3]);
    tell(res);
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
