#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for (int i = (a); i < (b); i++)
const int N = 2*(1e5)+5;

int c[N], deg[N], par[N], cnt1, cnt2, cnt3, bpc, bad;
vector<int> adj[N];

void dfs(int u, int p) {
    par[u] = p;
    cnt1 += c[u];
    if (c[u] && !c[p]) {
        bpc++;
    }
    int sm = 0;
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sm += c[v];
        }
    }
    if (c[u]) {
        if (sm == 2) {
            cnt2++;
            bad ^= u;
        } else if (sm > 2) {
            cnt3++;
        }
    }
    deg[u] = sm;
}

void flip(int x) {
    c[x] ^= 1; // Flip the color
    int d = c[x] ? 1 : -1; // Increment or decrement based on new color
    cnt1 += d;

    int p = par[x];
    if (!c[p]) {
        bpc += d;
    }

    cnt2 += d * (deg[x] == 2);
    cnt3 += d * (deg[x] > 2);
    if (c[x] && deg[x] == 2) {
        bad ^= x;
    }
    bpc -= d * deg[x];

    if (c[x]) {
        if (deg[p] == 2 && c[p]) {
            cnt2--;
            cnt3++;
            bad ^= p;
        }
        deg[p]++;
        if (deg[p] == 2 && c[p]) {
            cnt2++;
            bad ^= p;
        }
    } else {
        if (deg[p] == 2 && c[p]) {
            cnt2--;
            bad ^= p;
        }
        if (deg[p] == 3 && c[p]) {
            cnt3--;
            cnt2++;
            bad ^= p;
        }
        deg[p]--;
    }
}

bool check() {
    if (cnt1 == 0) return false;
    if (cnt2 > 1 || cnt3 > 0 || bpc > 1) return false;
    if (cnt2 && c[par[bad]]) return false;
    return true;
}

void init(int n) {
    rep(i, 1, n + 1) {
        adj[i].clear();
        deg[i] = 0;
    }
    cnt1 = cnt2 = cnt3 = bpc = bad = 0;
}

void testcase() {
    int n, q;
    cin >> n >> q;
    init(n);
    rep(i, 1, n + 1) cin >> c[i];
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    rep(i, 0, q) {
        int u;
        cin >> u;
        flip(u);
        cout << (check() ? "Yes" : "No") << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        testcase();
    }
    return 0;
}
