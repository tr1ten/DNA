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
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
        a[i] = a[i] > k;
    }
    int tot = count(all(a),0);
    if((a.back()==0 && a[0]==0)){
        put("YES");
        return;
    } 
    int cur = 0;
    tuple<int,int,int> st={INF,n,0};
    int val = 0;
    rep(i,0,n-2){
        cur += a[i]==0;
        val += a[i]==0 ? 1 : -1;
        if(cur*2 >= i+1){
            st = min(tuple<int,int,int>{val,i+1,cur},st);
            if(i==0 && i+1<n-2 && a[i+1]==0) break;
        }
    }
    // cout << get<1>(st) << " " << get<2>(st) << endl; 
    if(get<1>(st)<n-1){
        cur = 0;
        tot -= get<2>(st);
        rep(i,get<1>(st),n-1){
            cur += a[i]==0;
            if(cur*2 >= i-get<1>(st)+1 || (tot-cur)*2 >= (n-i-1) ){
                put("YES");
                return;
            }
        }   
    }
    reverse(all(a));
    tot = count(all(a),0);
     cur = 0;
     st={INF,n,0};
    val = 0;
    rep(i,0,n-2){
        cur += a[i]==0;
        val += a[i]==0 ? 1 : -1;
        if(cur*2 >= i+1){
            st = min(tuple<int,int,int>{val,i+1,cur},st);
            if(i==0 && i+1<n-2 && a[i+1]==0) break;
    
        }
    }
    // cout << get<1>(st) << " " << get<2>(st) << endl; 

    if(get<1>(st)<n-1){
        cur = 0;
        tot -= get<2>(st);
        rep(i,get<1>(st),n-1){
            cur += a[i]==0;
            if(cur*2 >= i-get<1>(st)+1 || (tot-cur)*2 >= (n-i-1) ){
                put("YES");
                return;
            }
        }   
    }
    
    put("NO");
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
