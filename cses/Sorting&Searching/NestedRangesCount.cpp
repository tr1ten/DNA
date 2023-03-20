#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
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
const LL INF = 1e10 + 5;

class FenwickTree
{
public:
    FenwickTree(vector<long long> nums)
    {
        tree = vector<long long>(nums.size() + 1);
    }
    FenwickTree(int N)
    {
        tree = vector<long long>(N + 1);
    }
    void clear(){
        fill(tree.begin(),tree.end(),0);
    }
    void update(int i, int diff)
    {
        i += 1;
        while (i < tree.size())
        {
            tree[i] += diff;
            i += i & (-i);
        }
    }

    long long _rangeSum(int i)
    {
        i += 1;
        long long sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }

    long long rangeSum(int i, int j)
    {
        return _rangeSum(j) - _rangeSum(i - 1);
    }

    vector<long long> tree;
};
struct Interval{
    int start, end, index;
    bool operator<(const Interval &other) const
    {
        if(start == other.start)
            return end > other.end;
        return start < other.start;
    }
};

// actual solutions
void solve(int n, vector<Interval> &vec)
{

    vector<LL> containsOther(n);
    vector<LL> insideOther(n);
    sort_vec(vec);
    vector<PI> starts; // 
    vector<PI> ends; // 
    FOR(i, 0, n)
    {
        starts.push_back({vec[i].start , i});
        ends.push_back({vec[i].end, -i});
    }
    sort_vec(starts);
    sort_vec(ends);
    unordered_map<int, int> startIndex;
    FenwickTree tree(n);
    int i=0,j=0;
    while (i<n || j<n) {
        if(i<n && starts[i].first<ends[j].first ){
            tree.update(i,1);
            i++;
        }
        else{
            int si = -ends[j].second;
            tree.update(si,-1);
            insideOther[vec[si].index]= tree.rangeSum(0,si);        
            j++;
        }
    }
    i=0,j=0;
    tree.clear();
    while (i<n || j<n) {
        if(i<n && starts[i].first<ends[j].first ){
            i++;
        }
        else{
            int si = -ends[j].second;
            tree.update(si,1);
            containsOther[vec[si].index]= tree.rangeSum(si+1,n-1);        
            j++;
        }
    }
    FOR(i, 0, n) { cout << containsOther[i] << " "; }
    cout << endl;
    FOR(i, 0, n) { cout << insideOther[i] << " "; }
    cout << endl;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Interval> vec(N);
    F0R(i, N)
    {
        cin >> vec[i].start >> vec[i].end;
        vec[i].index = i;
    }
    solve(N, vec);
    return 0;
}
