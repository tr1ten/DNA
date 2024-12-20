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
    vi a(n);
    tkv(a,n);
    int s = accumulate(all(a),0LL);
    if(s==0){
        if(count(all(a),0)==n) put(0)
        else put(-1);
        return ;
    }
    int ans = 0;
    int sign = s<0 ? -1 : 1;
    rep(i,0,n){
        if(a[i]==0) continue;
        int d = max(0LL,i+1-abs(s));
        a[0] += d*sign;
        ans +=d;

        if(s*a[i]<0){
            s -=a[i];
            ans += abs(a[i]);
            a[i] = 0;
        }
    }
    per(i,0,n){
        if(a[i]==0) continue;
        int d = abs(a[i]) - (abs(s)-i);
        a[0] += d*sign;
        ans += a[i];
        s -=a[i];

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
