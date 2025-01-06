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
    int l,r;
    cin >> l >> r;
    int best_x=l+1;
    int x = 0;
    per(bit,0,31){
        int mask = (1<<bit);
        x |= (l&mask);
        if((l&mask)==0) {
            if(x+mask>=r) continue;
            x ^=mask;
            per(i,0,bit){
                int mask = (1LL<<i);
                int a1 = (l&mask)>0,a2 = (r&mask)>0;
                if(a1^a2){
                }
                else if(!a1) {
                    if(x+mask<r) x|=mask; 
                }
            }
            if(((best_x^l) + (best_x^r)) < ((x^l) + (x^r)) ) {
                best_x = x;
            }
            x ^=mask;
        }
    }
    assert(l<best_x && best_x<r);
    // put((best_x^r) + (best_x^l)+(l^r));
    cout << l<<" " << best_x << " " << r << endl;
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
