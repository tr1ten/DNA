
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int maxn = 1e5 + 5;
int par[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        par[i] = i;
    }
}

int fp(int x) {
    return (x == par[x]) ? x : (par[x] = fp(par[x]));
}

void merge(int a, int b) {
    a = fp(a);
    b = fp(b);
    if (a != b) {
        if (rand() % 2) swap(a, b);
        par[b] = a;
    }
}

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int32_t main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);

    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    vector<pair<int, pair<int, int>>> tmp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp.push_back({dist(pts[i], pts[j]), {i, j}});
        }
    }
    sort(tmp.begin(), tmp.end());

    init();

    int total_cost = 0;
    for (auto p : tmp) {
        int b = p.second.first;
        int a = p.first;
        int c = p.second.second;
        if (fp(b) != fp(c)) {
            merge(b, c);
            total_cost += a;
        }
    }
    cout << total_cost << endl;
}