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
    int x,m;
    cin >> x >> m;
    int h = hset(x);
    int ans = 0;
    int mx=  (1LL<<(h+1))-1;
    int r2 =(int)pow(2,h+1)%x;
    int gg = x;
    while (gg%2==0)
    {
        gg/=2;
    }
    vector<int> mmp(x,-1);
    rep(i,0,x){
        int rr = i*r2%x;
        if(mmp[rr]==-1) mmp[rr] = i;
    }
    rep(y,0,min(mx+1,m+1) ){
        if(y!=0 && ((x^y)%y==0 && (x^y)%x!=0)){
            ans++;
        }
        int have = 1+((m-y)>>(h+1));
        int z = (x^y);
        int r1 = (x-z%x)%x;
        if(r1!=0 && r2==0) continue;
        if(mmp[r1]!=-1 && mmp[r1]<have) ans += (have-1-mmp[r1])/gg + 1;
    }
    put(ans-1);
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
