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
vector<long long> divisors(long long x){
    vector<long long> cur;
      
    return cur;
}
const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;
void testcase(){
    int n;
    cin >> n;
    unordered_map<int,int> a,b;
    int mxa=0,mxb=0;
    int sma = 0,smb=0;
    rep(i,0,n){
        int x;
        cin >> x;
        a[x]++;
        sma += x;
        mxa = max(mxa,x);
    }
    rep(i,0,n){
        int x;
        cin >> x;
        smb +=x;
        mxb = max(x,mxb);
        b[x]++;
    }
    if(mxb==0){
        put(1);
        return;
    }
    if(mxb>mxa || smb>sma){
        put(-1);
        return;
    }
    int x = sma-smb;
    unordered_set<int> st;
    for(int j=1;j*j<=x;j++)
    {		
        if(x%j==0)
        {
            if(j>=mxb+1 && j<=mxa+1) st.insert(j);
            if(j != x/j){
                if(x/j>=mxb+1 && x/j<=mxa+1) st.insert(x/j);
            }
        }
    }
    st.insert(mxa+1);
    for(auto k:st){
        unordered_map<int,int> c;
        for(auto x:a){
            c[x.first%k] += x.second;
        }
        if(c==b){
            put(k);
            return;
        }
    }
    put(-1);
    
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
