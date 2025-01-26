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
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    tkv(a,n);
    tkv(b,m);
    srv(a);
    srv(b);
    int kmx = 0;
    if(n>m){
        kmx = (min(n,2*m)+m)/3;
    }
    else {
        kmx = (min(m,2*n)+n)/3;
    }
    put(kmx);
    int a1=0,a2=0;
    int ans = 0;
    vi res;
    rep(i,1,kmx+1){
        int up = (2*a1 + a2 <= n-2 && 2*a2 + a1 <= m-1) ? -(a[a1]-a[n-a1-1]) : 0;
        int down = (2*a1 + a2 <= n-1 && 2*a2 + a1 <= m-2) ? -(b[a2]-b[m-a2-1]) : 0;
        if(up && ( up>down || (up==down && (n-2*a1-a2>m-2*a2-a1))) ){
            ans += up;
            a1++;
        }
        else if(down &&  (down==up || up<down)){
            ans +=down;
            a2++;
        }
        else{
            if(m-2*a2-a1>=3){
                // assert(n-2*a1-a2==0);
                a1--;
                up = (2*a1 + a2 <= n-2 && 2*a2 + a1 <= m-1) ? -(a[a1]-a[n-a1-1]) : 0;
                // assert(up!=0);
                down = (2*a1 + a2 <= n-1 && 2*a2 + a1 <= m-2) ? -(b[a2]-b[m-a2-1]) : 0;
                // assert(down!=0);
                ans -=up;
                a2++;
                ans +=down;
                down = (2*a1 + a2 <= n-1 && 2*a2 + a1 <= m-2) ? -(b[a2]-b[m-a2-1]) : 0;
                // assert(down!=0);
                ans +=down;
                a2++;
            }
            else if(n-2*a1-a2>=3) {
                // assert(m-2*a2-a1==0);
                a2--;
                down = (2*a1 + a2 <= n-1 && 2*a2 + a1 <= m-2) ? -(b[a2]-b[m-a2-1]) : 0;
                // assert(down!=0);
                up = (2*a1 + a2 <= n-2 && 2*a2 + a1 <= m-1) ? -(a[a1]-a[n-a1-1]) : 0;
                // assert(up!=0);
                ans -=down;
                a1++;
                ans += up;
                up = (2*a1 + a2 <= n-2 && 2*a2 + a1 <= m-1) ? -(a[a1]-a[n-a1-1]) : 0;
                ans +=up;
                // assert(up!=0);
                a1++;
            }
            else assert(0);
        }
        res.push_back(ans);
    }
    pvc(res);
    // cout << endl;

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
