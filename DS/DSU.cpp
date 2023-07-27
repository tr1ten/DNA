template <int N>
struct disjoint_set {
    int par[N + 1];

    disjoint_set() { memset(par, -1, sizeof(par)); }

    int find(int v) { return par[v] < 0 ? v : par[v] = find(par[v]); }

    void join(int u, int v) {
        if ((u = find(u)) != (v = find(v))) {
            if (par[u] > par[v]) swap(u, v);
            par[u] += par[v], par[v] = u;
        }
    }
};
