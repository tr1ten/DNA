#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// ht<int, null_type> g;

typedef long long ll; 
typedef unsigned long long ull; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll,custom_hash> mll;
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define int long long
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) vi name(sz,value)
#define mk_mat(name,n,m,value) vii name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define mod(x) (x + MOD)%MOD
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}


const ll MOD = 1e9+7; // change me for god sake look at problem mod
const ll INF = 1e16+5;

inline int ctz(ll x) { return __builtin_ctzll(x);}
inline int clz(ll x) {return __builtin_clzll(x);}
inline int pc(ll x) {return  __builtin_popcount(x);} 
inline int hset(ll x) {return __lg(x);}
void pyn(int x) {put(x?"YES":"NO");}
// do not use unordered map use mll
class BIT {
private:
    std::vector<int> nums;
    int LOG;
public:
    BIT(int n) {
    	LOG = (int)log2(n)+1;
        nums.resize((1ll<<LOG) + 1);
    }
    void update(int i, int val) {
        i += 1;
        while (i < nums.size()) {
            nums[i] += val;
            i += (i & (-i));
        }
    }
    int sum(int i) {
        int r = 0;
        // i += 1, not needed here since we need sum of rank less than i rank[0...i-1]
        while (i > 0) {
            r += nums[i];
            i -= (i & (-i));
        }
        return r;
    }
    // max index where sum A[0...ind] < x,return index of first number greator than or equal to x
    int lower(int x){
        ll pref = 0;
        int ind = 0;
        for(int i=LOG;i>=0;i--){
            if(nums[ind + (1ll<<i)] + pref<x){
                pref += nums[ind + (1ll<<i)];
                ind += 1ll<<i;
            }
        }
        return ind; // 0  based
    }
    
};

const int N = 3*(1e5) + 5;
int n; // MAKE SURE TO INITIALIZE THIS TO SIZE OF ARRAY
struct Segment{
    pi val;
    Segment(pi _a={-INF,N}) {
        val = _a;
    }
} min_seg[4*N],max_seg[4*N]; // 0 index
Segment combine(Segment left,Segment right){
    Segment res;
    res.val = max(left.val,right.val);
    return res;
}

// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int i,pi value,Segment segm[4*N]){
    if(left==i && right==i) {
            segm[node].val = value;
        }
    else{
        int mid = (left+right)/2;
        if(i<=mid) update(2*node+1,left,mid,i,value,segm);
        else update(2*node+2,mid+1,right,i,value,segm);
        segm[node] = combine(segm[2*node+1] , segm[2*node+2]);
    }
    
}

Segment query(int node,int left,int right,int l,int r,Segment segm[4*N]){
    if(left>=l && right<=r) {return segm[node];}
    int mid = (left+right)/2;
    Segment res;
    if(l<=mid) res = combine(res,query(2*node+1,left,mid,l,r,segm));
    if(r>mid) res = combine(res,query(2*node+2,mid+1,right,l,r,segm));

    return res;
}
// everything is zero indexed
void update(int i,pi x,Segment segm[4*N]){
    update(0,0,n-1,i,x,segm);
}
Segment query(int l,int r,Segment segm[4*N]){
    return query(0,0,n-1,l,r,segm);
}

void testcase(){
    cin >> n;
    BIT bit(n+1);
    unordered_map<int,vector<int>> inds;
    vi a(n);
    rep(i,0,n){
        int x;
        cin >> x;
        inds[x].pb(i);
        a[i] = x;
        update(i,{x,-i},max_seg);
        update(i,{-x,-i},min_seg);
    }
    mll cnt;
    per(i,0,n){
        if(cnt[a[i]]==0){
            bit.update(0,1);
            bit.update(i+1,-1);
        }
        cnt[a[i]]++;
    }
    int m = cnt.size();
    int k = m;
    vi res(m);
    int i = -1;
    rep(c,0,m){
        int lo = i+1,hi=n-1;
        int j=n;
        while (lo<=hi)
        {
            int mid = (lo+hi) >> 1;
            if(bit.sum(mid+1)>=k) {
                j = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        // debug(i,j);
        assert(j<n);
        int el=0;
        if(c%2==0) {
            auto val =query(i+1,j,max_seg).val;
            i = -val.second;
            el = val.first;
        }
        else{
            auto val = query(i+1,j,min_seg).val;
            el = -val.first;
            i = -val.ss;
        }
        assert(el>0);
        for(auto v:inds[el]){
            update(v,{-INF,-v},max_seg);
            update(v,{-INF,-v},min_seg);
        }
        bit.update(0,-1);
        bit.update(inds[el].back()+1,1);
        res[c] = el;
        // debug(c,j,el);
        k--;
    }
    put(m);
    pvc(res);

}
// driver code
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
