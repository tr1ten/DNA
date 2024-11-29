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

// s -> p 
// even distinct substring
// abc / 
// aa -> /
// ab-> a,b,ab X
// aba -> a,b,ab,ba,aba X
// abab-> a, b, ab,ba,aba,bab,abab X 
// ababa ->  a, b, ab,ba,aba,bab,abab, baba,ababa
bool check(string a) {
    if(a.size()==1) return false;
    if(a.size()==2) return a[0]==a[1]; 
    set<char> s{a[0],a[1],a[2]};
    return s.size()==3;
}
void testcase(){
    string s;
    cin >> s;
    rep(i,0,(int)s.size()-1){
        if(check(s.substr(i,2))) {
            cout << s.substr(i,2) << endl;
            return;
        }
        if(i+2<s.size() && check(s.substr(i,3))) {
            cout << s.substr(i,3) << endl;
            return;
        }
    }
    put(-1);
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
