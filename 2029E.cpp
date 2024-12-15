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
const int N = 5*(1e5) + 5;
int sieve[N+1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int x=2;x<=N;x++){
        if(sieve[x]!=0) continue; 
        sieve[x] = x;
        for(int u=2*x;u<=N;u +=x){
            if(sieve[u]==0) sieve[u] = x;
        }
    }
}


void testcase(){
    int n;
    cin >> n;
    int pc = 0;
    int pr = 2;
    vi a(n);
    rep(i,0,n){
        int x;
        cin >> x;
        a[i] = x;
        if(sieve[x]==x){
            pc++;
            pr = x;
        }
    }
    if(pc>=2) put(-1)
    else{
        int ans = pr;
        for(auto x:a){
            if(x==ans) continue;
            if(sieve[x]*ans>x) {
                put(-1);
                return;
            }
        }
        put(ans);
    }


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T; 
    preprocess(); // must call this

    while(T--) testcase();

    return 0;
}
