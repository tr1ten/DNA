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
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    tkv(a,n);tkv(b,n);
    vector<pi> pos;
    rep(i,0,n){
        pos.push_back({a[i],1});
        pos.push_back({b[i],-1});
    }
    srv(pos);
    int open_left = n;
    int open = 0;
    int ans = 0;
    int i = 0;
    while(i<pos.size()){
        
        pi z = pos[i];
        int opend=0,closed=0;
        while (i<pos.size() && pos[i].first==z.first)
        {
            opend += (pos[i].second==1);
            closed += pos[i].second==-1;
            i++;
        }
        open_left -= opend;
        if(open<=k){
            ans = max(ans,(open+opend+open_left)*z.first);
        }
        open += opend - closed;
    }
    put(ans);
    
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
