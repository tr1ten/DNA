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
#define all(x) x.begin(), x.end()
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename it, typename bin_op>
struct sparse_table {
    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op F;
 
    sparse_table(it first, it last, bin_op op) : t(1), F(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = F(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    T query(int l, int r) {
        int h = 31 - __builtin_clz(r-l+1);
        return F(t[h][l], t[h][r-(1<<h)+1]);
    }
};

void testcase(){
    int n,k;
    cin >> n>> k;
    vi a(n);
    tkv(a,n);
    vi b(n);
    tkv(b,n);
    map<int,int> ind;
    map<int,vi> ind2;
    stack<int> st;
    vi r(n,n),r2(n,n),mat(n,-1);
    vi done(n,0);
    rep(ii,0,n){
        int i = ii%n;
        ind2[a[i]].push_back(i);
        if(ind2[b[i]].size() ) {
            mat[ind2[b[i]].back()] = i;
            done[i] = 1;

            ind2[b[i]].pop_back();
        }
    }
    rep(ii,0,n){
        int i = ii%n;
        if(ind2[b[i]].size() && !done[i] && mat[ind2[b[i]].back()]==-1) {
            mat[ind2[b[i]].back()] = i;
            ind2[b[i]].pop_back();
        }
    }
    ind.clear();
    rep(ii,0,2*n){
        int i = ii%n;
        while(st.size() && st.top()<=a[i]){
            ind.erase(ind.find(st.top()));
            st.pop();
        }
        st.push(a[i]);
        ind[a[i]] = i;
        auto it = ind.lower_bound(b[i]+1);
        if(it!=ind.end()){
            if(i<it->second){
                r[i] = -1;
                r2[i]=it->second;
            }
            else {r[i] = it->second;r2[i] = it->second;}
        }
    }
    sparse_table st1(all(r), [&](int x, int y) { return min(x, y); }); 
    sparse_table st2(all(r2), [&](int x, int y) { return min(x, y); }); 

    auto ok = [&](int z){
        rep(i,0,n){
            int mnj = n;
            // cout << i << " " << z <<"  " << mat[i] << endl;
            if(mat[i]!=-1 && (mat[i]-i+n)%n<=z){
                continue;
            }
            if(i+z>=n){
                mnj = min(st1.query(i,n-1),st2.query(0,(i+z)%n)); 
            }
            else {
                mnj = st1.query(i,i+z);
            }
            if(mnj>=i) return false;
        }
        return true;
    };
    int lo = 0,hi=n-1;
    int ans = n;
    pvc(r);   
    pvc(mat);
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(ok(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    put(ans+1);
    
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
