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

/*
no pair i,j st    
a[g(i,j)] = g(a[i],a[j])


S = m integers <=n

a = n integers from set S

m<=n<=1e5

when -1?
a1 a2 a3 

a[j] ?
j = 2*i,3*i .. 
a[i] = x
a[j] = max  y st. y!=0modx

assign greedily 


proof ? 

*/


void testcase(){
    int n,m;
    cin >> n >> m;
    vi a(m);
    tkv(a,m);
    vi b(n,-1);
    vector<unordered_set<int>> divs(n);
    for(int i=1;i<=n;i++){
        per(k,0,m){
            if(divs[i-1].count(a[k])==0){
                b[i-1] = a[k];
                break;
            }
        }   
        if(b[i-1]==-1){
            put(-1);
            return;
        }
        for(int j=2*i;j<=n;j+=i) {
            divs[j-1].insert(b[i-1]);
        }
    }
    rep(i,0,n){
        cout << b[i] << ' ';
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
