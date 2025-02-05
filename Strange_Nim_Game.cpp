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
const int N = 2e5 + 4;
int g[N];
long long fast_pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n){
        int x;
        cin >> x;
        a[i] = g[x];
    }
    int A = 6;
    vii cnt(n+1,vi(A));
    rep(i,0,n){
        cnt[i+1][a[i]] +=1;
        rep(j,0,A){
            cnt[i+1][j] += cnt[i][j];
        }
    }
    pvc(a);
    int q;
    cin >> q;
    rep(i,0,q){
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1){
            vi cc(A);
            a--;b--;
            rep(j,0,A){
                cc[j] = cnt[b+1][j] - cnt[a][j];
            }
            int ccc=1;
            rep(j,0,A){
                ccc = ccc*fast_pow(2,cc[j]-1,MOD);
            }
            int ans=0;
            rep(mask,0,1<<A){
                int cur = 0;
                rep(j,0,A){
                    if(mask&(1<<j)){
                        cur = cur^j;
                    }
                }
                if(cur==0){
                    ans +=ccc;
                }
            }
            cout << ans << endl;

        }
        else {  
            
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
    rep(i,1,N){
        int r =i;
        set<int> st;
        while (r>0)
        {
            if(r%10) {
                st.insert(g[i-r%10]);
            }
            r/=10;
        }
        rep(mex,0,st.size()+2){
            if(st.count(mex)==0){
                g[i] = mex;
                break; 
            }
        }
    }
    // cin>>T;
    while(T--) testcase();

    return 0;
}
