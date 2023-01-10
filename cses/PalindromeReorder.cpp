#include <bits/stdc++.h>
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
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
string solve(string &s){
    unordered_map<char,int> mp;
    trav(c,s) mp[c]++;
    char oc = NULL; // odd char
    trav(p,mp) {
        if((p.second&1)>0){
            if(oc!=NULL) return "NO SOLUTION";
            else oc = p.first;
        }
    }
    deque<char> res;
    if(oc!=NULL) res.push_back(oc);
    trav(p,mp){
        FOR(i,0,p.second/2) res.push_back(p.first);
        FOR(i,0,p.second/2) res.push_front(p.first);
    }
    string ans = "";
    while (!res.empty())
    {
        ans += res.front();
        res.pop_front();
    }
    
    return ans;
}

// driver code
int main()
{
    string s;
    cin>>s;
    cout << solve(s);
    return 0;
}
