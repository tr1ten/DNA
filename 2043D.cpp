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
    int l,r,g;
    cin >> l >> r >> g;
    int l1 = (l+g-1)/g,r1 = r/g;
    if(l1>r1) {
        cout <<-1 << " " << -1 << endl;
        return;
    }
    pi ans = {-1,-1};
    
    if(l1==r1){
        if(__gcd(l1,r1)==1) {ans.first =l1*g,ans.second=r1*g;}
    }
    else {
        
        if(__gcd(l1,r1)!=1) {
            r1-=1;
        }
        if(__gcd(l1,r1)==1) {
            ans.first = l1*g;
            ans.second = r1*g;
        }
        else{
            ans.first = (l1+1)*g;
            ans.second = (r1+1)*g;
        }
        

    }
    if(ans.first!=-1){ assert(__gcd(ans.first,ans.second)==g);}
    cout << ans.first << " " << ans.second << endl;
    
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
