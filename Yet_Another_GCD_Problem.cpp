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
const int N = 5+2;
int f[N];
void testcase(){
    int n,k;
    if(k>n*(n-1)/2){
        put(-1);
        return;
    }
    f[1] = k;
    rep(i,1,N){
        for(int j=2*i;j<N;j+=i){
            f[j] += f[i];
        }
    }
    unordered_map<int,int> cnt;
    per(i,2,N){
        for(int j=2*i;j<N;j+=i){
            f[i] -= f[j];
        }
        if(f[i]==0){
            continue;
        }
        int lo=1,hi=n;
        int x= -1;
        while (lo<=hi)
        {
            int mid = (lo+hi)/2;
            int va = mid*(mid-1)/2;
            if(va>=f[i]){
                hi = mid-1;
                if(va==f[i]) {
                    x = mid;
                }
            }
            else {
                lo = mid+1;
            }
        }
        if(x!=-1){
            cnt[i]= f[i];
        }
        else {
            put(-1);
            return;
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
    cin>>T;
    while(T--) testcase();

    return 0;
}
