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
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
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
    int n,m,L;
    cin >> n >> m >> L;
    vii dis;
    rep(i,0,n){
        int l,r;
        cin >> l >> r;
        dis.push_back({l,r-l+1});
    }
    vi xs(m),vs(m);
    rep(i,0,m){
        cin >> xs[i] >> vs[i];
    }
    multiset<int,greater<int>> ms;
    int j =0;
    int  pw = 1;
    int res = 0;
    rep(i,0,n){
        while(j<m && xs[j]<dis[i][0]){
            ms.insert(vs[j]);
            j++;
        }
        while (pw<=dis[i][1])
        {
            if(ms.size()==0){
                cout << (-1) << endl;
                return;
            }
            auto it = ms.begin();
            res++;
            pw += *it;
            ms.erase(it);
        }
    }
    cout << (res) << endl;
       
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
