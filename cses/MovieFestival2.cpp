#pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;
struct Interval{
    LL start, end, index;
    bool operator<(const Interval &other) const
    {
        if(start == other.start)
            return end < other.end;
        return start < other.start;
    }
};

// actual solutions
LL solve(int n,LL k, vector<Interval> &vec)
{
    sort_vec(vec);
    multiset<LL> ends; // act as min max pq
    int watch = 0;
    trav(x,vec){
        while (!ends.empty() &&  *ends.begin()<=x.start)
        {
            watch++;
            ends.erase(ends.begin());
        }
        if(ends.size()==k) {
            if(*ends.rbegin()>  x.end) { // if new movie is shorter than any prev movie then left prev and start this
                ends.erase(--ends.end());
                ends.insert(x.end);
            }
        }
        else ends.insert(x.end);
    }
    watch += ends.size();
    return watch;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL N,K;
    cin >> N>>K;
    vector<Interval> vec(N);
    F0R(i, N)
    {
        cin >> vec[i].start >> vec[i].end;
        vec[i].index = i;
    }
    cout << solve(N,K, vec) << endl;
    return 0;
}
