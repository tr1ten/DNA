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
const int N = 4*(1e5) + 5;
int n; // MAKE SURE TO INITIALIZE THIS TO SIZE OF ARRAY
struct Segment{
    ll ans=-INF;
} segm[4*N]; // 0 index
Segment combine(Segment left,Segment right){
    Segment res;
    res.ans = max(left.ans,right.ans);
    return res;
}

// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int i,ll value){
    if(left==i && right==i) {
            segm[node].ans = value;
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
// int main(int argc, char const *argv[])
// {   
//     cin >> n;
//     int q;
//     cin >> q;
//     for(int i=0;i<n;i++) {int x;cin >> x;update(i,x);}
//     for(int i=0;i<q;i++){
//         int x;
//         cin >> x;
//         if(x==0){
//             int ind,y;
//             cin >> ind >> y;
//             update(ind,y);
//         }
//         else{
//             int l,r;
//             cin >> l >> r;
//             r--;
//             cout << (query(l,r)).ans << endl;
//         }
//     }
    
//     return 0;
// }

void testcase(){
    int m;
    cin >> m;
    set<int> lasts;
    vector<pi> a(m);
    set<int> c;
    rep(i,0,m){
        cin >> a[i].first >> a[i].second;
        c.insert(a[i].first);
        c.insert(a[i].second);
    }
    vi inds(m);
    iota(all(inds),0LL);
    sort(all(inds),[&](int i,int j){
        return (pi){a[i].first,-a[i].second} <(pi){a[j].first,-a[j].second};
    });
    vi bs(c.begin(),c.end());
    srv(bs);
    n = bs.size();
    rep(i,0,n){
        update(i,-INF);
    }
    vi aa(m);
    rep(k,0,m){
        int i = inds[k];
        int ans=0;
        int j = (lower_bound(all(bs),a[i].second)-bs.begin());
        if(!((k && a[inds[k-1]]==a[i]) || (k+1<m && a[inds[k+1]]==a[i]))) {
            auto it = lasts.lower_bound(a[i].second);
            if(it!=lasts.end()){
                int mx_start = query(j,n-1).ans;  
                int mn_end = *it;
                ans += max(mn_end-mx_start+1-(a[i].second-a[i].first+1),0LL); 
            }
        }
        update(j,a[i].first);
        lasts.insert(a[i].second);
        aa[i] = ans;
    }
    rep(i,0,m){
        put(aa[i]);
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
