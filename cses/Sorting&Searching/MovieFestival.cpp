#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> PI;
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
const LL MOD = 1e9 + 7;
const int INF = 1e8 + 5;

// actual solutions max non overlapping
size_t solve(vector<vector<int>> ivals)
{
    sort_vec(ivals);
    stack<int> st;
    st.push(ivals[0][1]);
    FOR(i, 1, ivals.size())
    {
        if (!st.empty() && st.top() > ivals[i][0]) // overlap then choose which ends first
        {
            int top = st.top();
            st.pop();
            st.push(min(ivals[i][1], top));
        }
        else
        {
            st.push(ivals[i][1]);
        }
    }
    return st.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    mk_mat(arr, N, 2, 0);
    F0R(i, N)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << solve(arr) << endl;
    return 0;
}
