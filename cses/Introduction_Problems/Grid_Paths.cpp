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
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
const LL MOD = 1e9+7;
const LL INF = 1e10+5;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
const int PLen = 48;
int p[PLen];
const int GS = 9;
bool vis[GS][GS]; // padding on four sides
LL tryP(int pidx,int r,int c){ // i index
    if(pidx==PLen && r==7 && c==1) return 1; // reach target after all steps
    if(pidx==PLen || (r==7 && c==1)) return 0;  // invalid
    if(
        ((vis[r+1][c] && vis[r-1][c]) && !vis[r][c+1] && !vis[r][c-1])
        ||
        ((vis[r][c+1] && vis[r][c-1]) && !vis[r+1][c] && !vis[r-1][c])
    ) return 0; // optimization 3: if we cannot move forward but can go left and right then that mean grid split into two parts
    vis[r][c] = 1;
    LL res = 0;
    if(p[pidx]<4){
        int nr=r+dy[p[pidx]],nc = c+dx[p[pidx]];
        if(!vis[nr][nc]) res+=tryP(pidx+1,nr,nc);
    }
    else{
        FOR(i,0,4){
            int nr=r+dy[i],nc = c+dx[i];
            if(!vis[nr][nc]) res+=tryP(pidx+1,nr,nc);
        }
    }
    vis[r][c] = 0;
    return res;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--){
        string s;
        cin >> s;
        unordered_map<char,int> mp;
        mp['U'] = 0;
        mp['D'] = 1;
        mp['L'] = 2;
        mp['R'] = 3;
        mp['?'] = 4;
        FOR(i,0,s.length()){
            p[i] = mp[s[i]];   
        }
        memset(vis,0,sizeof vis);
        FOR(i,0,GS){
            vis[i][0] = true;
            vis[i][8] = true;
            vis[0][i] = true;
            vis[8][i] = true;
        }
        put(tryP(0,1,1));
    }   

    return 0;
}
