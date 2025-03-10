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
int n,l,r;
const int N =4e5+5;
int a[N];
int X= 0;
int smr,sml;
int f(int i,int od,int ev,int y,int end){
    if(i>end) return 0;
    if(end-i<2){
        return (end-i+1)*(y^X);
    }
    int total = 2*(od+ev);
    int req = min(total,end-i+1);
    int res = 2*(y^X);
    req -=2;
    res += ((2*(req/4))*X) + min(2LL,req%4)*X;
    // res += (2*(od+ev-1))*(X);
    res +=f(2*i,od+ev,ev+od,y^X,end);
    // cout << i << " " << total << " " << end << " " << y << " " << res << endl;
    return res;
}
void testcase(){
    cin >> n >> l >>r;
    rep(i,1,n+1){
        cin >> a[i];
    }
    if(n%2==0){
        a[n+1] =0 ;
        rep(i,1,n/2 + 1){
            a[n+1] ^= a[i];
        }
        n++;
    }
    X = 0;
    for(int i=1;i<=n;i++){
        X ^=a[i];
    }
    smr = 0;
    sml = 0;
    int j = (n+1)/2;
    int xr = 0;
    rep(i,1,j){
        xr ^=a[i];
    }
    int i = n+1;
    while (i<=2*n+1)
    {
        xr^=a[j++];
        a[i] = a[i+1] = xr;
        i+=2;
    }
    rep(i,1,min(r+1,2*n+2)){
        smr += a[i];
    }
    rep(i,1,min(l,2*n+2)){
        sml += a[i];
    }
    // cout << X << " "<< smr << " " << sml << endl;
    rep(i,n+1,2*n+2){
        smr +=f(2*i,i%2,i%2==0,i%2==0 ? a[i] : 0,r);
        sml +=f(2*i,i%2,i%2==0,i%2==0 ? a[i] : 0,l-1); 
        // cout << i << " smr " << smr << " " << a[i] << endl;
    }
    put(smr-sml);
    
    

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
