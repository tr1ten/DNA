#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
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


const int N = 1e2+5;
VI tree[5*N]; // 1 based indexing
VI a(N);
void build_tree( int cur , int l , int r )
{
     if( l==r )
     {
            tree[cur].push_back( a[ l-1] );
            return ;
     }
     int mid = l+(r-l)/2;
     build_tree(2*cur , l , mid ); // Build left tree 
     build_tree(2*cur+1 , mid+1 , r ); // Build right tree
     merge( tree[2*cur].begin() , tree[2*cur].end(),tree[2*cur+1].begin() , tree[2*cur+1].end(),back_inserter(tree[cur]));
}
// number of element less than eq x in range ql to qr
int query( int cur, int l, int r, int x, int y, int k)
{
       if( r < x || l > y )
      {
               return 0; //out of range
      }
      if( x<=l && r<=y )
      {
              //Binary search over the current sorted vector to find elements smaller than K

              return  upper_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
      }
      int mid=l+(r-l)/2;
     return query(2*cur,l,mid,x,y,k)+query(2*cur+1,mid+1,r,x,y,k);
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a = {5,1,2,3,4};
    build_tree(1,1,5);
    return 0;
}