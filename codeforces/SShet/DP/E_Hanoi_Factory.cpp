#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define rep(N) FOR(i,0,N)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define take(x) cin >> x;
#define take2(x,y) cin >> x >> y;
#define take3(x,y,z) cin >> x >> y >> z;

#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}


const LL MOD = 1e9+7;
const LL INF = 1e10+5;

// Fenwick tree
const int N = 3*(1e5) + 5;  // limit for array size
int n;  // array size, near power of two
LL t[2 * N];
// iterative segment tree

LL combine(LL left,LL right){return max(left,right);}
void build() {  // build the tree; fill from last secnod layer
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}


void update(int p, const LL value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

LL query(int l, int r) { // [l,r)
  LL resl=0, resr=0;
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]); // l&1 mean l is right child, parent not included so shift to parent right
    if (r&1) resr = combine(t[--r], resr); // 
  }
  return combine(resl, resr);
}


struct Ring{
    LL outer;
    LL inner;
    LL h;
    bool operator<(const Ring &other){
        if(this->outer >  other.outer) return true;
        return this->outer==other.outer ? this->inner>other.inner : false;
    }
};
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--){
        int nn;
        cin >> nn;
        vector<Ring> rings;
        map<LL,LL> cmp;
        rep(nn){
            Ring ring;
            cin >> ring.inner >> ring.outer >> ring.h;
            rings.push_back(ring);
            cmp[ring.inner]++; // coordinate compression
            cmp[ring.outer]++; // coordinate compression

        }
        unordered_map<LL,int> imap;
        trav(x,cmp){
            imap[x.first] = n++;
        }
        sort_vec(rings);
        n = pow(2, ceil(log(n)/log(2))); // n near power of 2
    
        trav(x,rings){
            update(imap[x.inner],x.h + query(0,imap[x.outer]));
        }
        put(query(0,n));
    }

    return 0;
}


