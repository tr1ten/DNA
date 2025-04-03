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
int longestCommonSubsequence(string &a, string &b) {
    rep(i,1,a.size()){
        if(a[i]==a[i-1]) assert(0);
    }
    rep(i,1,b.size()){
        if(b[i]==b[i-1]) assert(0);
    }
    
    short m[1001][1001] = {};
    for (auto i = 0; i < a.size(); ++i)
        for (auto j = 0; j < b.size(); ++j)
            m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    return m[a.size()][b.size()];
}
void testcase(){
    int n,k;
    cin >> n >> k;
    string s,t;
    if(n%2 && k==n/2) {
        rep(i,0,n){
            s+= (i%2==0 ? "C" : "B");
        }
        rep(i,0,n){
            t+= (i%2==0 ? "A" : "B");
        }
    }
    else {
        if(k<n/2){
            put(-1);
            return;
        }
        string s1,s2;
        int sw = 0;
        rep(i,0,k) {s1.push_back(sw+ 'A');sw^=1;}
        sw = 1;
        
        rep(i,k,n){ s2.push_back(sw + 'B');sw^=1;}
        s= s1 + s2;
        t = s2+s1;
    }
    assert(longestCommonSubsequence(s,t)==k);
    put(s);
    put(t);

    
    
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
