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
bool check(vi &a){
    while (a.size()>1)
    {
        rep(i,1,a.size()){
            if(a[i]<=a[i-1]) return false;
            a[i-1] = a[i]-a[i-1];
        }
        a.pop_back();
    }
    return true;
    
}
void testcase(){
    int n;
    cin >> n;
    string s(n,'0');
    vi a(n);
    tkv(a,n);
    if(n>100){
        put(s);
    }
    else {
        rep(i,0,n){
            vi b=a;
            b.erase(b.begin()+i);
            if(check(b)) s[i] = '1';
        }
        put(s);
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
