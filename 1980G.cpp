#include<bits/stdc++.h>
using namespace std;




const int A = 2;
const int MX = 30; // 10**9 < 1<<30
struct trie
{
    int v,sz;
    int val;
    trie *sons[A];
 
    trie()
    {
        v = sz = 0;
        memset(sons,0,sizeof(sons));
    }
 
    void add(int x,int m)
    {
        if ( m==-1  )
        {
            v++;
            sz++;
            val = x;
            return;
        }
        int ind = (x>>m)&1;
        if ( sons[ind ] == NULL ) sons[ind] = new trie();
 
        sz -= sons[ind]->sz;
        sons[ind]->add(x,m-1);
        sz += sons[ind]->sz;
    }
 
    void remove(int x,int m)
    {
        if ( m == -1)
        {
            v--;
            sz--;
            
            return;
        }
        int ind = (x>>m)&1;

        if ( sons[ind]->sz == 0 ) sons[ind] = new trie();
        else
        {
            sz -= sons[ind]->sz;
            sons[ind]->remove(x,m-1);
            sz += sons[ind]->sz;
            if ( sons[ind]->sz == 0 )
                sons[ind] = NULL;
        }
    }

    
    int max_xor(int x,int m){
        if(m==-1) {
            return val^x;
        }
        if(sz==0) { return 0;}
        int ind = (x>>m)&1;
        if(sons[!ind]!=NULL) return sons[!ind]->max_xor(x,m-1);
        return sons[ind]->max_xor(x,m-1);
    }
 
};

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
        
        trie root;
        trie evroot;
        
        auto dfs = make_y_combinator([&](auto dfs,int u, int p, int xr, int d)->void{
            (d ? root : evroot).add(xr,MX);
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
                evroot.remove(path[v],MX);
                cout << max(root.max_xor( x ^ path[v] ^ y_,MX), evroot.max_xor( x ^ path[v],MX)) << " ";
                evroot.add(path[v],MX);

                if (dd[v]) swap(root, evroot);
            }
        }
        cout << endl;
    }
    return 0;
}
