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
#define put(x) cout << (x) << endl;
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
double v[] = {-0.4422185555555555, -0.9422185555555554, 1.3844371111111113};
void testcase(){
    int n;
    double sigma;
    cin >> n >> sigma;
    if(n==1 || sigma==0){
        if(n==1 && sigma>0) {
            put(-1);
            return;
        }
        rep(i,0,n){
            cout<<0 << " ";
        }
        cout << endl;
        return;
    }
    if(n%2){
        double ld = sqrtl(3);
        for(auto x:v){
            double y = x*sigma;
            cout << fixed<<setprecision(8) << y << " ";
        }   
        n -=3;
    }
    for(int i=0;i<n;i+=2){
        cout << sigma << " "<< -sigma << " ";
    }
    cout << endl;
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
