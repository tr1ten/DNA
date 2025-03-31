#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)
#define int long long

const int INF = 2e18;
const int M = 1000000007;
//const int M = 998244353;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define ll long long
#define ld long double
#define memset(arr,val) memset(arr,val,sizeof(arr))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define umap unordered_map
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define rep(i,x,y) for(int i=x; i<y; i++)
#define rrep(i,x,y) for(int i=x; i>=y; i--)
#define setbits(n)  __builtin_popcountll(n)
#define bitsize(n) (63 - __builtin_clzll(n))
#define lcm(a,b) (a/__gcd(a, b)*b)
#define yn(f) f?cout<<"YES\n":cout<<"NO\n"
#define syn(f) f?cout<<"Yes\n":cout<<"No\n"
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
// rnd() -> generates a random number

template <class T1, class T2>
ostream& operator<<(ostream &dout, pair<T1,T2> &p){ return dout<<p.ff<<' '<<p.ss<<' ';}
template <class T>
ostream& operator<<(ostream &dout, vector<T> &vec){for(auto i:vec) dout<<i<<' '; return dout;}
template <class T>
void print(T it1, T it2, char sep=' '){for(auto it=it1; it!=it2; it++) cout<<*it<<sep; cout<<'\n';}

int powm(int x,int n) {
    x%=M;
    if(n==0) return 1; else if(n==1) return x;
    int p = powm(x*x, n/2);
    if(n%2) return p*x%M; else return p;
}

int mod_div(int p, int q) { return p%M * powm(q,M-2) % M;}

vi fact, ifact;
void factCompute(int N=1e6) {
    fact.assign(N+1, 1);
    ifact.assign(N+1, 1);
    rep(i,1,N+1) fact[i] = fact[i-1] * i % M;
    ifact[N] = mod_div(1, fact[N]);
    rrep(i,N-1,0) ifact[i] = ifact[i+1] * (i+1) % M;
}

int ncr(int n, int r) {
    if(r > n) return 0;
    return fact[n] * ifact[n-r] % M * ifact[r] % M;
}

vi spf, primes;
void sieve(int N=1e7){
    spf.assign(N+1,0); rep(i,0,N+1) spf[i]=i;
    for(int i=2; i*i<=N; i++) if(spf[i]==i) for(int j=i*i; j<=N; j+=i) spf[j]=min(spf[j],i);
    rep(i,2,N+1) if(spf[i]==i) primes.pb(i);
}

/*-------------------------------------------------------------------------------------------------------------------------------------*/



void CoderAbhi27(){
    int n;
    cin>>n;
    string s; cin>>s;
    vi ans;
    int j=-1;
    rep(i,0,n-1) {
        if(s[i+1] == s[i]) continue;
        int x = i-j;
        int c = ans.size();
        rep(ii,0,2*x) {
            ans.pb(i+c+1);
        }
        j = i;
    }
    if(j==-1) {
        cout<<"-1\n";
        return;
    }
    int x = n-j-1;
    rep(ii,0,2*x) {
        ans.pb(n + ans.size() - x);
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i<<'\n';
}

int32_t main() {
    fastIO;
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r" , stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    // factCompute(1e6);
    // sieve(1e7);


    int t=1;
    cin>>t;
    rep(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
        CoderAbhi27();
    }
    return 0;
}