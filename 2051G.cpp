#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pi;
const int INF = 1e16;

int n, q;
vector<vector<int>> edge;
vector<int> sms;
vector<vector<int>> dp;
vector<pi> a;

void preprocess_edges() {
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j) continue;
            int ans = 2;
            int first = 1;
            bool valid = true;
            for (auto &[idx, op] : a) {
                if (idx == i && op == 1) first++;
                if (idx == j && op == -1) first--;
                ans = max(ans, first + 1);
            }
            edge[i][j] = ans - 2;
        }
    }
}

void solve_with_bottom_up() {
    int last = (1 << n) - 1;
    dp.assign(n, vector<int>(1 << n, INF));

    rep(i, 0, n) {
        dp[i][1<<i] = 0;
    }

    for (int vis = 1; vis <= last; vis++) {
        rep(u, 0, n) {
            if (!(vis & (1 << u))) continue; // Skip if `u` is not in `vis`
            rep(v, 0, n) {
                if (vis & (1 << v)) continue; // Skip if `v` is already visited
                dp[v][vis | (1 << v)] = min(dp[v][vis | (1 << v)], dp[u][vis] + edge[u][v]);
            }
        }
    }

    int ans = INF;
    rep(i, 0, n) {
        ans = min(ans, dp[i][last]+sms[i]);
    }
    cout << ans + n << endl;
}

void testcase() {
    cin >> n >> q;
    a.resize(q);
    sms.assign(n, 0);
    edge.assign(n, vector<int>(n, INF));

    rep(i, 0, q) {
        int x;
        char c;
        cin >> x >> c;
        a[i] = {x - 1, c == '+' ? 1 : -1};
        if (c == '+') sms[a[i].first]++;
    }

    preprocess_edges();
    solve_with_bottom_up();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) testcase();
    return 0;
}
