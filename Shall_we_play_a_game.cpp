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

const int MOD = 998244353; // change me for god sake look at problem mod
const int INF = 1e16+5;
void testcase(){
    int n;
    cin >> n;
    int p2 = 1;
    int cur = 0;
    vi last{0};
    rep(i,0,n){
        if(i%4<=1) cur+=p2;
        else cur -= p2;
        cur +=MOD;
        cur %=MOD;
        p2 = 2*p2%MOD;
        last.push_back(cur);
        if(last.size()>4){
            last.erase(last.begin());
        }
    }    
    if(n==1){
        put(1);
        return;
    }
    int mx,mn;
    if((n-1)%4==0){
        mx = last.back();
        mn = *prev(last.end(),2);
    }  
    if((n-1)%4==1){
        mx = last.back();
        mn = *prev(last.end(),3);
    }  
    if((n-1)%4==2){
        mn = last.back();
        mx = *prev(last.end(),2);
    }  
    if((n-1)%4==3){
        mn = last.back();
        mx = *prev(last.end(),3);
    }  
    put((mx-mn+MOD)%MOD);
    
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
