#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL, LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define rep(N) FOR(i, 0, N)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, arr) for (auto &a : (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name, sz, value) VI name(sz, value)
#define mk_mat(name, n, m, value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec, sz) FOR(i, 0, sz) cin >> vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec)               \
    trav(x, vec) cout << x << " "; \
    cout << endl;
#define put(x) cout << (x) << endl;
#define put2(x, y) cout << (x) << " " << (y) << endl;
#define put3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl;
#define take(x) cin >> x;
#define take2(x, y) cin >> x >> y;
#define take3(x, y, z) cin >> x >> y >> z;

#define timed(x)                                                                \
    {                                                                           \
        auto start = chrono::steady_clock::now();                               \
        x;                                                                      \
        auto end = chrono::steady_clock::now();                                 \
        auto diff = end - start;                                                \
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl; \
    }

const LL MOD = 1e9 + 7;
const LL INF = 1e10 + 5;

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        char mat[n+2][m+2];
        int gp = 0; // good people
        bool v[n+2][m+2];
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        memset(v,0,sizeof v);
        FOR(i, 1, n+1)
        {
            string row;
            cin >> row;
            FOR(j, 1, m+1)
            {
                mat[i][j] = row[j-1];
                if (mat[i][j] == 'G')
                    gp++;
                if(mat[i][j]=='#') v[i][j] = 1;
                if (mat[i][j] == 'B')
                {
                    FOR(k,0,4) {v[i+dy[k]][j+dx[k]] = 1;}
                }
            }
        }
        FOR(i,0,n+2){
            v[i][0] = 1;
            v[i][m+1] = 1;
        }
        FOR(i,0,m+2){
            v[0][i] = 1;
            v[n+1][i] = 1;
        }
        queue<pair<int, int>> q;
        if (!(v[n][m]))
        {
            q.push(make_pair(m, n )); // x,y
            while (!q.empty())
            {
                auto p = q.front();
                if(mat[p.second][p.first]=='G') gp--;
                q.pop();
                FOR(i,0,4){
                    int x=p.first+dx[i],y=p.second+dy[i];
                    if(!v[y][x]) {
                        v[y][x] = 1;
                        q.push(make_pair(x,y));}
                }

            }
        }
        if(gp==0) put("Yes")
        else put("No")
    }

    return 0;
}
