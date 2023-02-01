#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
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
void solve(int n, vector<PI> vec)
{
    VI sorted(n);
    FOR(i, 0, n)
    {
        sorted[i] = i;
    }
    auto cmp = [&](int a, int b)
    {
        return vec[a].first==vec[b].first ? vec[a].second>vec[b].second : vec[a].first < vec[b].first;
    };
    sort(sorted.begin(), sorted.end(), cmp);
    vector<bool> containsOther(n);
    vector<bool> insideOther(n);
    int i = 0;
    while (i < n)
    {
        stack<LL> st;
        LL end = (vec[sorted[i]].second); // push current end
        while (i < n and vec[sorted[i]].second <= end)
        {
            if (st.empty()) {st.push(i++); continue;}
            if(vec[sorted[i]].second<=vec[sorted[st.top()]].second) containsOther[sorted[st.top()]]=true;
            else st.pop();
            insideOther[sorted[i]] = true;
            st.push(i++);
        }
        // while (st.size()>1) {
        //     insideOther[sorted[st.top()]]=true;
        //     st.pop();
        //     if(!st.empty()) containsOther[sorted[st.top()]]=true;
        // }
        
    }
    FOR(i,0,n){cout << containsOther[i] << " ";}
    cout << endl;
    FOR(i,0,n){cout << insideOther[i] << " ";}
    cout << endl;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<PI> vec(N);
    F0R(i, N)
    {
        int a, b;
        cin >> a >> b;
        vec[i] = MP(a, b);
    }
    solve(N, vec);
    return 0;
}
