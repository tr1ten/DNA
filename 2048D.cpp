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
// int a[N],b[N],solved[N];
void testcase(){
    int n,m;
    cin >> n>> m;
    vi a(n),b(m),solved(m);
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,m){
        cin >> b[i];
    }
    srv(b);reverse(all(b));
    int it = m;
    rep(i,0,m){
        if(b[i]<=a[0]){
            it =i;
            break;
        }
    }
    priority_queue<int> pq;
    rep(i,1,n){
        pq.push(a[i]);
    }
    int cnt = 0;
    rep(i,0,m){
        while (pq.size() && b[i]<=pq.top())
        {
            cnt++;
            pq.pop();
        }
        solved[i] = cnt;
    }
    rep(k,1,m+1){
        int r=m%k;
        int ans = 0;
        int tt = 0;
        for(int j=it-r-1;j>=0;j-=k){
            ans += solved[j]+1;
            tt += 1;
        }
        ans += (m-it)/k;
        tt += (m-it)/k;
        assert(tt==m/k);
        cout << ans << " ";
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
