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
// Function to calculate the number of solutions to ax ≡ b (mod m) with 0 <= x < n
// Extended Euclidean Algorithm (needed by the count_congruence_solutions function)
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}
long long count_solutions(long long a, long long b, long long m, long long n) {
    long long g = __gcd(a, m);
    if (b % g != 0) {
        return 0; // No solutions
    }

    long long a_prime = a / g;
    long long b_prime = b / g;
    long long m_prime = m / g;

    long long x, y;
    long long gcd_val = extended_gcd(a_prime, m_prime, x, y); //Reusing extended_gcd to compute inverse
    if(gcd_val != 1) return 0;

    long long x0 = (x * b_prime) % m_prime;
    if (x0 < 0) x0 += m_prime;


    if (x0 >= n) {
        return 0;
    }

    return (n - 1 - x0) / m_prime + 1;
}
void testcase(){
    int x,m;
    cin >> x >> m;
    int h = hset(x);
    int ans = 0;
    int mx=  (1LL<<(h+1))-1;
    int r2 =(int)pow(2,h+1)%x;
    rep(y,0,min(mx+1,m+1) ){
        if(y!=0 && ((x^y)%y==0 && (x^y)%x!=0)){
            ans++;
        }
        int have = 1+((m-y)>>(h+1));
        int z = (x^y);
        int r1 = (x-z%x)%x;
        ans += count_solutions(r2,r1,x,have);
    }
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
