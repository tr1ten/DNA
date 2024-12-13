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
    int n,m,k;
    cin >> n >> m >> k;
    string s ;
    cin >> s;
    int i= 0;
    int left = 0;
    int ans = 0;
    while(i<n){
        int cnt = 0;
        char x = s[i];
        while (i<n && s[i]==x)
        {
            cnt++;
            i++;
        }
        int d = min(left,cnt);
        left -=d;
        cnt -=d;
        if(cnt<m || x=='1') continue;
        int c1 = (cnt-m+1+(k+m-2))/(k+m-1);
        left += max(0LL,(c1*k+c1*(m-1))-cnt );
        ans +=c1;
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
