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


class Node{
    public:
        int open,close;
        Node(int o,int c){
            open = o;
            close = c;
        }
        Node(){open=0;close=0;}
        void invert(){
            open ^=1;
            close ^=1;
        }
};
const int N = 1e5 + 5;
int n;
Node *t;

Node combine(Node tl,Node tr){
    Node tn;
    tn.open = max(0,tl.open - tr.close) + tr.open;
    tn.close = max(0,tr.close - tl.open) + tl.close;
    return tn;
}
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) {t[i] = combine(t[i<<1], t[i<<1|1]);}
}
void modify(int p) {

  for (t[p += n].invert(); p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=10;
    FOR(i,1,T+1){
        int len;
        scanf("%d",&len);
        n = pow(2, ceil(log(len)/log(2)));
        t = new Node[2*n+1];
        char s[len+1];
        scanf("%s",s);
        FOR(i,0,len){
            Node node;
            node.open = s[i]=='(' ? 1 : 0;
            node.close = s[i]==')' ? 1 : 0;
            t[i+n] = node;
        }
        build();
        int q;
        scanf("%d",&q);
        printf("Test %d:\n",i);
        rep(q){
            int x;
            scanf("%d",&x);
            if(x==0){
                if(t[1].open==0 && t[1].close==0) puts("YES");
                else puts("NO");
            }
            else{
                modify(--x);
            }
        }
    }

    return 0;
}
