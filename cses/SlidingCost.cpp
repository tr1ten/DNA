#pragma GCC optimize(2, 3, "Ofast", "unroll-loops", "-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL;
typedef vector<int> VI;
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
const LL MOD = 1e9 + 7;
const LL INF = 1e10 + 5;

// actual solutions
void solve(int n, int k, VI &vec)
{
    multiset<int> left;
    multiset<int> right;
    LL lsum = 0; // sum of left set
    LL rsum = 0; // sum of right set
    int i = 0;
    auto balance = [&]()
    {
        while (left.size() > right.size())
        {
            lsum -= *left.rbegin();
            rsum += *left.rbegin();
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
    };
    trav(x, vec)
    {
        rsum += x;
        right.insert(x);
        rsum -= *(right.begin());
        lsum += *(right.begin());
        left.insert(right.extract(right.begin()).value());
        balance();
        if (left.size() + right.size() >= k)
        {

            LL md;
            LL nl = left.size();
            LL nr = right.size();
            if (k % 2 == 1)
            {
                md = *right.begin();
            }
            else
            {
                md = *left.rbegin();
            }
            // cout << md << " " << lsum << " " << rsum << endl;
            cout << ((nl * md - lsum) + (rsum - nr * md)) << " ";
            if (left.find(vec[i]) != left.end())
            {
                lsum -= vec[i];
                left.erase(left.find(vec[i]));
            }
            else
            {
                rsum -= vec[i];
                right.erase(right.find(vec[i]));
            }
            i++;
        }
    }
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    mk_vec(vec, N, 0);
    take_vec(vec, N);
    solve(N, K, vec);
    return 0;
}
