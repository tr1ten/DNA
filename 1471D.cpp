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
const int N = 1e6 + 5;
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
            sieve[u] = x;
        }
    }
}

int factors(int x){
    int res  = 1;
    map<int,int> fa;
    while(x>1){
        int f = sieve[x];
        while(x%f==0) {fa[f]++;;x/=f;}
    }
    for(auto &e:fa){
        if(e.second%2){
            res *=e.first;
        }
    }
    return res;
}


void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    int q;
    cin >> q;
    int ev = 0;
    map<int,int> cnt;
    for(auto &x:a){
        cnt[factors(x)]++;
    }
    int mx= 0;
    for(auto e:cnt){
        if(e.second%2==0 || e.first==1){
            ev += e.second;
        }
        mx = max(e.second,mx);
    }
    rep(i,0,q){
        int v;
        cin >> v;
        if(v==0) {
            put(mx);
        }
        else {
            put(max(mx,ev));
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    preprocess(); // must call this
    cin>>T;
    while(T--) testcase();

    return 0;
}
