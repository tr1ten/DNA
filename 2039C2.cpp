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
    int r2 =((int)pow(2LL,h+1LL))%x;
    rep(y,0,min(mx+1,m+1) ){
        // if(y!=0 && ((x^y)%y==0 && (x^y)%x!=0)){
        //     ans++;
        // }
        int have = 0;
        rep(yy,0,m+1) {
            if((yy&(mx))==y) have++;
        }
        cout << y << " have "<<have << endl;
        int z = (x^y);
        int r1 = (x-z%x)%x;
        if(r1==0){

        }
        else {
            if(r2==0 || r1%r2) continue;
            int r3 =r1/r2;
            
        }
    }
    int real = 0;
    rep(y,1,m+1){
        if((x^y)%y==0 || (x^y)%x==0){
            // cout << y << endl;
             real++;}
    }
    cout<< real << " " << ans-1 << endl;
    // assert(real==ans-1);
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
