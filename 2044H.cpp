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
// Function to get sum from r1,c1 to r2,c2 from ps
long long get_sum(int r1, int c1, int r2, int c2, const vector<vector<long long>>& ps) {
    return ps[r1][c1] - (ps[r1][c2+1] + ps[r2+1][c1]) + ps[r2+1][c2+1];
}

// Function to fill the prefixes and check if x is ok
void compute(int n, vector<vector<int>>& mat, vector<vector<long long>>& pref) {
    // Reset and fill the prefixes
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            pref[i][j] = mat[i][j] + pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1];
        }
    }
}

void testcase(){
    int n,q;
    cin >> n >> q;
    vii mat(n,vi(n)),matj(n,vi(n)),mati(n,vi(n));
    vii ps(n+1,vi(n+1)),psj(n+1,vi(n+1)),psi(n+1,vi(n+1));

    rep(i,0,n){
        rep(j,0,n){
            cin >> mat[i][j];
            mati[i][j] = (i)*mat[i][j];
            matj[i][j] = (j)*mat[i][j];
        }
    }
    compute(n,mat,ps);
    compute(n,mati,psi);
    compute(n,matj,psj);
    rep(i,0,q){
        int r1,r2,c1,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;c1--;r2--;c2--;
        int _c = c2-c1+1;
        int a1 = get_sum(r1,c1,r2,c2,psi);
        int a2 = get_sum(r1,c1,r2,c2,psj);
        int a3 = get_sum(r1,c1,r2,c2,ps);
        int ans = a1*_c + a2 + a3*(1) - a3*(c1+r1*_c);
        cout << ans <<" ";
    }
    cout <<"\n";
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
