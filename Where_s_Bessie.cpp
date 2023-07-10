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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll, ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define trav(a, arr) for (auto &a : (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name, sz, value) vi name(sz, value)
#define mk_mat(name, n, m, value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec, sz) FOR(i, 0, sz) cin >> vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec)                   \
    trav(x, vec) cout << x << " "; \
    cout << endl;
#define put(x) cout << (x) << endl;
#define put2(x, y) cout << (x) << " " << (y) << endl;
#define put3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl;
#define mod(x) (x + MOD) % MOD
// debugging
#define timed(x)                                                                \
    {                                                                           \
        auto start = chrono::steady_clock::now();                               \
        x;                                                                      \
        auto end = chrono::steady_clock::now();                                 \
        auto diff = end - start;                                                \
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl; \
    }

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 5;
const int N = 23;
ll mat[N][N];
bool vis[N][N];
bool check[N][N];
int n, m;
int i_min, i_max, j_min, j_max;
ll flood_fill(int i, int j, int c)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    vis[i][j] = 1;
    ll cun = 0;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    while (!q.empty())
    {
        auto p = q.front();
        cun += check[p.first][p.second];
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int y = p.first + dy[k], x = p.second + dx[k];
            if (x <= j_max && y <= i_max && x >= j_min && y >= i_min && !vis[y][x] && mat[y][x] == c)
            {
                vis[y][x] = 1;
                q.push(make_pair(y, x));
            }
        }
    }
    return cun;
}
bool iscow(int y1, int x1, int y2, int x2)
{
    unordered_map<int, int> cnt;
    memset(vis, 0, sizeof vis);
    i_max=y2;
    i_min=y1;
    j_max = x2;
    j_min = x1;
    int f = 0;
    rep(i, y1, y2 + 1)
    {
        rep(j, x1, x2 + 1)
        {
            if (!vis[i][j])
            {
                flood_fill(i, j, mat[i][j]);
                cnt[mat[i][j]]++;
                if (cnt.size() > 2)
                {
                    break;
                    f = 1;
                }
            }
        }
        if (f)
            break;
    }
    // debug(cnt,x1,y1,x2,y2);
    if (cnt.size() != 2)
        return 0;
    int a = 0;
    int b = 0;
    trav(x, cnt)
    {
        if (x.second == 1) a = 1;
        if (x.second>1) b = 1;        
    }
    if(!a or !b) return 0;
    return 1;
}
struct PCL {

	int i1, j1;

	int i2, j2;


	bool is_inside(PCL other) {

		return (i1 >= other.i1 && i2 <= other.i2 && j1 >= other.j1 &&

		        j2 <= other.j2);

	}

};
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        cin >> n;
        m = n;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                char x;
                cin >> x;
                mat[i][j] = x - 'A';
            }
        }
        ll res = 0;
        	vector<PCL> pcl_list;
        rep(y1, 0, n)
        {
            rep(x1, 0, n)
            {
                per(y2, y1, n)
                {
                    per(x2, x1, n)
                    {
                        if(iscow(y1, x1, y2, x2)){
                            pcl_list.push_back({y1, x1, y2, x2});
                        }
                    }
                }
            }
        }
        int pcl_count = 0;

	// If a PCL is inside another PCL, don't count it

	for (int i = 0; i < pcl_list.size(); i++) {

		bool valid_pcl = true;

		for (int j = 0; j < pcl_list.size(); j++) {

			if (i == j) { continue; }

			if (pcl_list[i].is_inside(pcl_list[j])) {

				valid_pcl = false;

				break;

			}

		}

		pcl_count += valid_pcl;

	}
        put(pcl_count);
    }

    return 0;
}
