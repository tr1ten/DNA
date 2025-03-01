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
    string s;
    cin >> s;
    int alt = 1;
    int c1 = s[0]-'0';
    rep(i,1,s.size()){
        c1 += s[i] - '0';
        if((s[i])==s[i-1]){
            alt = 0;
        }
    }
    int n = s.size();
    int c0 = s.size()-c1;
    if(alt) put(0)
    else {
        if(n%2){
            if(abs(c1-c0)==1) put(1)
            else if(abs(c1-c0)-1<=2) put(2)
            else put(3)
        }
        else {
            if(c1==c0) put(1)
            else if(abs(c1-c0)<=2) put(2)
            else put(3)
        }
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
