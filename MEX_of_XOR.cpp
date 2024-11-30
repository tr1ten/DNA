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
    int l,r,x;
    cin >> l >> r >> x;
    int m1 = 0;
    int m2 = 0;
    int last = 0;
    int op =0;
    per(i,0,31){
        int mask = 1<<i;
        int a1 = x&mask,a2 = r&mask;
        if(a1==0 && a2){
            if(last!=0){
                op |=mask;
            }
            else m1 |=mask;
        }
        if(a1 && a2==0) {m1^=last;m1|=op;break;}
        if(a1==0 && a2==0){
            m1 ^=last;
            m1 |=op;
            m1 |=mask;
            last= mask;
        }
    }
    last = 0;
    op = 0;
    per(i,0,31){
        int mask = 1<<i;
        int a1 = x&mask,a2 = l&mask;
        if(a1==0 && a2){
            m2 ^=last;
            m2 |=op;
            break;
        }
        if(a1 && a2==0) {
            if(last!=0){
                op |=mask;
            }
            else m2 |=mask;
        }
        if(a1 && a2){
            m2 ^=last;
            m2 |=op;
            m2 |=mask;
            last= mask;
        }
    }
    int ans = x;
    if((m1^x) >r ) ans = min(ans,m1);
    if((m2^x)<l) ans = min(ans,m2);
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
