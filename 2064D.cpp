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
    int n,q;
    cin >> n >> q;
    vi a(n);
    tkv(a,n);
    int M = 31;
    vii inds(M,{-1});
    rep(j,0,M){
        rep(i,0,n){
            if((a[i]>>j)&1){
                inds[j].push_back(i);
            }
        }
    }
    vi pref{0};
    rep(i,0,n){
        pref.push_back(pref.back() ^ a[i]);
    }
    rep(i,0,q){
        int x;
        cin >> x;
        int up = 0;
        int cur = n;
        int j = M-1;
        while(j>=0 && cur>0){
            int nxt=*prev(lower_bound(all(inds[j]),cur));
            int taken = (x>>j)&1;
            if(taken){
                int ate = 0;
                if(nxt>=up){
                    int val = pref[cur]^pref[nxt+1];
                    if((x^val) >= a[nxt]){
                        ate = 1;
                        cur = nxt; 
                        x ^= val^a[nxt];
                    }
                }
                if(!ate){
                    cur = max(up,nxt+1);
                    break;
                }
            }
            else {
                up = max(up,nxt+1);
                j--;
            }
        }
        cout << (n-cur) <<" ";
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
