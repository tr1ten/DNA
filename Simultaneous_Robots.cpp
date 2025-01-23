#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define put(x) cout << (x) << '\n'
typedef pair<int, int> pi;

const int INF = 1e16;

void testcase() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    // Early termination for invalid conditions
    if (grid[1][0] == '#' || grid[0][1] == '#' || grid[n - 1][m - 2] == '#' || grid[n - 2][m - 1] == '#') {
        put(-1);
        return;
    }

    // BFS setup
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q;
    vector<pi> par(n * m, {-1, -1}); // Flattened parent array
    int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};

    // First BFS: Find the shortest path and track visited cells
    q.push({0, 0, 0});
    int a1 = INF;
    while (!q.empty()) {
        auto [cost, i, j] = q.front();
        q.pop();

        if (i == n - 1 && j == m - 1) {
            a1 = cost;
            break;
        }

        if (vis[i][j]) continue;
        vis[i][j] = true;

        rep(d, 0, 4) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] != '#') {
                par[ni * m + nj] = {i, j};
                q.push({cost + 1, ni, nj});
            }
        }
    }

    // cout << a1 << " = cost" << endl;
    if (a1 == INF) {
        put(-1);
        return;
    }

    // Mark the shortest path found in the first BFS
    fill(vis.begin(), vis.end(), vector<bool>(m, false));
    int ci = n - 1, cj = m - 1;
    while (ci != 0 || cj != 0) {
        auto [pi, pj] = par[ci * m + cj];
        // cout << pi << " " <<  pj << endl;
        vis[pi][pj] = true;
        ci = pi, cj = pj;
    }
    while (!q.empty())
    {
        q.pop();
    }
    vis[0][0] = false;
    // Second BFS: Find the shortest path avoiding the first path
    q.push({0, 0, 0});
    int a2 = INF;
    while (!q.empty()) {
        auto [cost, i, j] = q.front();
        q.pop();

        if (i == n - 1 && j == m - 1) {
            a2 = cost;
            break;
        }

        if (vis[i][j]) continue;
        vis[i][j] = true;

        rep(d, 0, 4) {
            int ni = i + dy[d], nj = j + dx[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] != '#') {
                q.push({cost + 1, ni, nj});
            }
        }
    }
    // cout << a2 << " = cost" << endl;

    if(a1==a2){
        put(a1);
    }
    else put(a1+2);
    // put(min((a1 + a2) / 2, a1 + 2));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) testcase();

    return 0;
}
