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
int f(int x,int y,int p,int l1,int r1,int l2,int r2){
    if(x==l1 && y==l2 && (x+(1LL<<p))==r1 && (y+(1LL<<p))==r2 ) return 1;
    if(p==0){
        return 1;
    }
    int p2 = 1<<(p-1);
    int res  = 0;
    if(x<=l1 &&  l1<x+p2){
        if(y<=l2 && l2<y+p2){
            res += f(x,y,p-1,l1,min(r1,x+p2),l2,min(r2,y+p2));
        }
        if(y+p2<r2){
            res += f(x,y+p2,p-1,l1,min(r1,x+p2),max(y+p2,l2),r2);
        }
    }
    if(x+p2<r1){
        if(y<=l2 && l2<y+p2){
            res += f(x+p2,y,p-1,max(l1,x+p2),r1,l2,min(r2,y+p2));
        }
        if(y+p2<r2){
            res += f(x+p2,y+p2,p-1,max(l1,x+p2),r1,max(y+p2,l2),r2);
        }
    }
    cout << x << " " << y << " " << p << " " << l1 << " " <<r1 <<" " << l2 << " " << r2 <<" " << res << endl;
    return res;
}
void testcase(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    put(f(0,0,5,l1,r1,l2,r2));   
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
