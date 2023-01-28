#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef vector<VI> VII;
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

// actual solutions
size_t solve(size_t n, VI &vec, int m, VII &swaps)
{
    int res = 1;           // since we need to include round starting from 0
    mk_vec(pos, n + 1, 0); // pos of 0 is 0
    for (int i = 0; i < n; i++)
        pos[vec[i]] = i + 1; // we just need to check rel position
    trav(x, vec) if (pos[x - 1] > pos[x]) res++;
    for (auto q : swaps)
    {
        int u = q[0], v = q[1];
        if (abs(vec[u - 1] - vec[v - 1]) == 1)
        {
            int p1 = min(vec[u - 1], vec[v - 1]);
            int p2 = max(vec[u - 1], vec[v - 1]);
            if(pos[p1]<pos[p1-1] && pos[p2]>pos[p1-1]) res--; // made first chain
            if(pos[p1]>pos[p1-1] && pos[p2]<pos[p1-1]) res++; // broke
            if(p2+1<=n && pos[p2]>pos[p2+1] && pos[p1]<pos[p2+1]) res--;
            if(p2+1<=n && pos[p2]<pos[p2+1] && pos[p1]>pos[p2+1]) res++;
            if(pos[p1]>pos[p2]) res--;
            else res++;
        }
        else
        {
            int pcnt = 0;
            if (pos[vec[u - 1]] > pos[vec[u - 1] - 1])
                pcnt++;
            if (vec[u - 1] + 1 <= n && pos[vec[u - 1]] < pos[vec[u - 1] + 1])
                pcnt++;
            int wcnt = 0;
            if (pos[vec[v - 1]] > pos[vec[u - 1] - 1])
                wcnt++;
            if (vec[u - 1] - 1 <= n && pos[vec[v - 1]] < pos[vec[u - 1] + 1])
                wcnt++;
            res += (pcnt - wcnt);
            swap(u, v);
            pcnt = 0;
            if (pos[vec[u - 1]] > pos[vec[u - 1] - 1])
                pcnt++;
            if (vec[u - 1] + 1 <= n && pos[vec[u - 1]] < pos[vec[u - 1] + 1])
                pcnt++;
            wcnt = 0;
            if (pos[vec[v - 1]] > pos[vec[u - 1] - 1])
                wcnt++;
            if (vec[u - 1] - 1 <= n && pos[vec[v - 1]] < pos[vec[u - 1] + 1])
                wcnt++;
            res += (pcnt - wcnt);
        }
        swap(pos[vec[u - 1]], pos[vec[v - 1]]);
        swap(vec[u - 1], vec[v - 1]);
        std::cout << res << std::endl;
    }
    return res;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    mk_vec(vec, N, 0);
    mk_mat(swaps, M, 2, 0);
    take_vec(vec, N);
    FOR(i, 0, M)
    {
        cin >> swaps[i][0] >> swaps[i][1];
    }
    solve(N, vec, M, swaps);
    return 0;
}
