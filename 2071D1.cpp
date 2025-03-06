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
const int N =2e5+5;
int a[N];
int X= 0;
int f(int x){
    if(x<=n){
        return a[x-1];
    }
    if(x/2 <=n){
        int res = 0;
        for(int i=1;i<=x/2;i++){
            res ^= a[i-1];
        }
        return res;
    }
    if((x/2)%2){
        return X;
    }
    return X^f(x/2);
}
void testcase(){
    cin >> n >>l >>r;
    tkv(a,n);
    if(n%2==0){
        a[n] =0 ;
        rep(i,0,n/2){
            a[n] ^= a[i];
        }
        n++;
    }
    X = 0;
    for(int i=0;i<n;i++){
        X ^=a[i];
    }
    put(f(l));

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
