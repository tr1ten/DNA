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

    vector<LL> allocatedRooms(n);
    vector<PI> starts; // 
    vector<PI> ends; // 
    FOR(i, 0, n)
    {
        starts.push_back({vec[i].start , i});
        ends.push_back({vec[i].end, i});
    }
    sort_vec(starts);
    sort_vec(ends);
    int i=0,j=0;
    int id=1;
    stack<int> availableRooms;
    while(i<n || j<n){
        if(i<n && starts[i].first<=ends[j].first){
            if(availableRooms.empty()){
                availableRooms.push(id++);
            }
            allocatedRooms[starts[i].second] = availableRooms.top();
            availableRooms.pop();
            i++;
        }
        else{
            availableRooms.push(allocatedRooms[ends[j].second]);
            j++;
        }
    }
    cout << availableRooms.size() << endl;
    trav(r,allocatedRooms){
        cout << r << " ";
    }
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
