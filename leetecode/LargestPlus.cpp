// #pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<int> VI;
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
const LL MOD = 1e9+7;
const LL INF = 1e10+5;

class Solution {
public:
    static int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<set<int>> ys(n);
        vector<set<int>> xs(n);
        trav(a,mines){
            int x=a[0],y=a[1];
            ys[y].insert(x);
            xs[x].insert(y);
        }
        int res = 0;
        FOR(y,0,n){
            FOR(x,0,n){
                if(ys[y].find(x)!=ys[y].end()) continue;
                int li = -1;
                int ri = n;
                int ui = -1;
                int di = n;
                auto xi_a = ys[y].upper_bound(x);
                if(xi_a!=ys[y].end()) ri = (*xi_a);
                if(xi_a!=ys[y].begin()) li = (*prev(xi_a));
                auto yi_a = xs[x].upper_bound(y);
                if(yi_a!=xs[x].end()) di = (*yi_a);
                if(yi_a!=xs[x].begin()) ui = (*prev(yi_a));
                res = max(res,min(min(min(x-li,ri-x),y-ui),di-y));
            }
        }
        return res;
    }
};