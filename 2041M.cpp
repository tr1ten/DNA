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
    vi a(n);
    tkv(a,n);
    vi sa = a;
    srv(sa);
    // prefix, suff
    int j  =0 ;
    priority_queue<int,vi,greater<int>> pq;
    int ans=n*n;
    rep(i,0,n){
        ans = min(ans,i*i + (n-j)*(n-j));
        pq.push(a[i]);
        while(pq.size() && j<n && sa[j]==pq.top()){
            j++;
            pq.pop();
        }
    }

    // suff, prefix
    priority_queue<int> pq2;
    j  =n-1;
    rep(i,0,n){
        ans = min(ans,i*i + (j+1)*(j+1));
        pq2.push(a[n-i-1]);
        while(pq2.size() && j>=0 && sa[j]==pq2.top()){
            j--;
            pq2.pop();
        }
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
    while(T--) testcase();

    return 0;
}
