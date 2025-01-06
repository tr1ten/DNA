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
typedef long long ll;
const int N = 2*(1e5) + 5;
int n; // MAKE SURE TO INITIALIZE THIS TO SIZE OF ARRAY
struct Segment{
    ll mx1,mx2,mn1,mn2,ans;
    Segment() {
        mx1 = -INF;
        mn1 = INF;
        mx2 = -INF;
        mn2 = INF;
        ans = 0;
    }
} segm[4*N]; // 0 index
Segment combine(Segment left,Segment right){
    Segment res;
    res.ans = max({left.ans,right.ans,left.mx1-right.mn1,right.mx2-left.mn2});
    res.mx1 = max(left.mx1,right.mx1);
    res.mx2 = max(left.mx2,right.mx2);
    res.mn1 = min(left.mn1,right.mn1);
    res.mn2 = min(left.mn2,right.mn2);
    
    return res;
}

// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int i,ll value){
    if(left==i && right==i) {
            segm[node].mx1 = value+i;
            segm[node].mn1 = value+i;
            segm[node].mx2 = value-i;
            segm[node].mn2 = value-i;
            segm[node].ans =0;
        }
    else{
        int mid = (left+right)/2;
        if(i<=mid) update(2*node+1,left,mid,i,value);
        else update(2*node+2,mid+1,right,i,value);
        segm[node] = combine(segm[2*node+1] , segm[2*node+2]);
    }
    
}

Segment query(int node,int left,int right,int l,int r){
    if(left>=l && right<=r) {return segm[node];}
    int mid = (left+right)/2;
    Segment res;
    if(l<=mid) res = combine(res,query(2*node+1,left,mid,l,r));
    if(r>mid) res = combine(res,query(2*node+2,mid+1,right,l,r));

    return res;
}
// everything is zero indexed
void update(int i,ll x){
    update(0,0,n-1,i,x);
}
Segment query(int l,int r){
    return query(0,0,n-1,l,r);
}
void testcase(){
    int q;
    cin >> n >> q;
    rep(i,0,n){
        int x;
        cin >> x;
        update(i,x);
    }
    put(query(0,n-1).ans);
    rep(i,0,q){
        int p,x;
        cin >>p>> x;
        p--;
        update(p,x);
        put(query(0,n-1).ans);

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
