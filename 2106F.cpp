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
    string s;
    cin >> s;
    vi pref(n);
    vi suff(n);
    int cnt =0;
    rep(i,0,n){
        if(s[i]=='1') cnt++;
        else {
            cnt = 0;
        }
        pref[i] = cnt;
    }
    cnt = 0;
    per(i,0,n){
        if(s[i]=='1') cnt++;
        else {
            cnt = 0;
        }
        suff[i] = cnt;
    }
    int i = 0;
    int lastb = 0;
    int ans = 0 ;
    while(i<n){
        if(s[i]=='1') {
            i++;
            continue;
        }
        int z = 0;
        int p1 = i ? pref[i-1] : 0;
        while (i<n && s[i]=='0')
        {
            i++;
            z++;
        }
        int s1  = i<n ? suff[i] : 0;
        int up = z*(z-1)/2 + (p1>0) + z*p1 + lastb;
        int down = z*(z-1)/2 + (s1>0) + z*s1;
        if(s1==1){
            lastb = down-1;
        }
        else lastb = 0;
        cout << up << " " << down << " " << z <<" " << p1 <<" " << s1<< endl;
        ans = max(ans,up);
        ans = max(ans,down);
        
    }
    put(ans);
    

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
