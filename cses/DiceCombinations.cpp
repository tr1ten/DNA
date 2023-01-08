#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL; 
typedef pair<int,int> PI;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define sz(x) (int)(x).size()
const int MOD = 1e9+7;
const int MX = 1e6+5;

VI mem;
// actual solutions 
int solve(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(mem[n]!=-1) return mem[n];
    int ways = 0;
    FOR(i,1,7){
        ways = (ways+solve(n-i))%MOD;
    }
    mem[n] = ways;
    return ways;
}

// driver code
int main()
{
    int N;
    cin>>N;
    mem.resize(N+1,-1);
    cout << solve(N);
    return 0;
}
