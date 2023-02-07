#pragma GCC optimize(2, 3, "Ofast", "unroll-loops", "-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef __uint128_t LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL, LL> MII;
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
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
const LL MOD = 1e9 + 7;
const LL INF = 1e10 + 5;
std::ostream&
operator<<( std::ostream& dest, __uint128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
// actual solutions
LL f(string d, int prev=10)
{
    if(d.size()==0) return 0; // base case
    int fn = d[0] - '0';
    if (fn > prev)
    {
        fn--;
    } // since we can't take adjacent number
    LL res = 0;
    int dig = d.size() - 1;
    if (prev == 10) // if first digit then need to check lower digits
    {
        res += (pow(9, dig + 1) - 1) / 8;
        fn--;
    } 
    res += pow(9,dig)*fn; // after fixing a number above 0
    if(prev!=(d[0]-'0')) res += f(d.substr(1),d[0]-'0');
    return res;
}
LL solve(int a, int b)
{
    return f(to_string(b+1))-f(to_string(a));
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;
    return 0;
}
