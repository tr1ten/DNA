#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL; 
typedef pair<int,int> PI;
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
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
void solve(int n,int m,VI &b,VI &a){
    map<int,int> bs;
    // sort(a.begin(),a.end());
    mk_vec(res,m,-1);
    trav(x,b) bs[x]++;
    FOR(i,0,m)
    {
        int x = a[i];
        auto iter = bs.upper_bound(x);
        if(iter==bs.begin()) continue;
        iter--;
        // cout << bs.size() << (iter!=bs.end())  << endl;
        if((*iter).first <=x) {
            (*iter).second--;
            if((*iter).second==0) bs.erase(iter);
            res[i] = ((*iter).first);
        }

    }
    trav(x,res){
        std::cout << x << std::endl;
    }
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;


    cin>> n >>  m;
    mk_vec(h,n,0);
    mk_vec(l,m,0);
    take_vec(h,n);
    take_vec(l,m);
    solve(n,m,h,l);
    return 0;
}
