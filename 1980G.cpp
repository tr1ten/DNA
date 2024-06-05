#include <iostream>
#include <vector>
using namespace std;
const int A = 2;
const int MX = 30;
template <class F>
struct y_combinator {
    F f; // the lambda will be stored here
    
    // a forwarding operator():
    template <class... Args>
    decltype(auto) operator()(Args&&... args) const {
        // we pass ourselves to f, then the arguments.
        return f(*this, std::forward<Args>(args)...);
    }
};

// helper function that deduces the type of the lambda:
template <class F>
y_combinator<std::decay_t<F>> make_y_combinator(F&& f) {
    return {std::forward<F>(f)};
}

class Node {
public:
    Node* childs[2] = {nullptr,nullptr};
    bool ended;
    int val;
    int cnt;
    
    Node() {
        ended = false;
        val = 0;
        cnt = 0;
    }
};

void add(Node* root, int x) {
    Node* cur = root;
    for (int i = MX; i >= 0; --i) { // store from msb...lsb
        int ind = (x >> i) & 1;
        if (!cur->childs[ind]) cur->childs[ind] = new Node();
        cur = cur->childs[ind];
    }
    cur->ended = true;
    cur->cnt++;
    cur->val = x;
}

void remove(Node* root, int x) {
    Node* cur = root;
    vector<pair<Node*, int>> path;
    for (int i = MX; i >= 0; --i) { // store from msb...lsb
        int ind = (x >> i) & 1;
        path.push_back({cur, ind});
        cur = cur->childs[ind];
    }
    cur->cnt--;
    if (cur->cnt == 0) {
        while (!path.empty()) {
            pair<Node*, int> p = path.back();
            path.pop_back();
            p.first->childs[p.second] = nullptr;
            if (p.first->childs[p.second ^ 1]) break;
        }
    }
}


int max_xor(Node* root, int x) {
    if (!root->childs[0] && !root->childs[1]) return 0;
    Node* cur = root;
    for (int i = MX; i >= 0; --i) {
        int ind = (x >> i) & 1;
        if (cur->childs[ind ^ 1]) cur = cur->childs[ind ^ 1];
        else cur = cur->childs[ind];
    }
    return cur->val ^ x;
}
const int N = 2e5 + 5;
int path[N];
int dd[N];

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        Node* root = new Node();
        Node* evroot = new Node();
        
        auto dfs = make_y_combinator([&](auto dfs,int u, int p, int xr, int d)->void{
            add(d ? root : evroot, xr);
            path[u] = xr;
            dd[u] = d;
            for (auto [v, w] : adj[u]) {
                if (v != p) {
                    dfs(v, u, xr ^ w, d^1);
                }
            }
        });


        dfs(0, -1, 0, 0);

        int y_ = 0;
        for (int i = 0; i < m; ++i) {
            string ip;
            cin >> ip;
            if (ip[0] == '^') {
                int y;
                cin >> y;
                y_ ^= y;
            } else {
                int v, x;
                cin >> v >> x;
                v--;
                if (dd[v]) swap(root, evroot);
                remove(evroot, path[v]);
                cout << max(max_xor(root, x ^ path[v] ^ y_), max_xor(evroot, x ^ path[v])) << " ";
                add(evroot, path[v]);
                if (dd[v]) swap(root, evroot);
            }
        }
        cout << endl;
    }
    return 0;
}
