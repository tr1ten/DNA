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
    int n;
    cin >> n;
    int mat[n][n];
    rep(i,0,n){
        string s;
        cin >> s;
        rep(j,0,n){
            mat[i][j] = s[j]-'0';
        }
    }
    int cost1 = 0;
    rep(i,0,n/2){
        rep(j,0,n/2){
            pi a[] = {{i,j},{j,n-1-i},{n-1-i,n-j-1},{n-j-1,i}};
            int cs = 0;
            for(auto [x,y]:a){
                cs += mat[x][y];

            }
            cost1+= min(cs,4-cs);
        }
    }
    if(n%2){
        vi a(n);
        vi b(n);
        rep(i,0,n){
            a[i] = mat[i][n/2];
        }
        rep(i,0,n){
            b[i] = mat[n/2][i];
        }
        // pvc(a);
        // pvc(b);
        // cout << cost1 << endl;
        rep(i,0,n/2){
            int ii = n-i-1;
            if(a[i]==a[ii]){
                cost1 += b[i]^a[i];
                cost1 += b[ii]^a[i];
            }
            else if(b[i]==b[ii]) {
                cost1 += a[i]^b[i];
                cost1 += a[ii]^b[i];
            }
            else cost1 +=2;
        }
    }
    put(cost1);
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
