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

// actual solutions 
LL solve(int n,VI &vec){
    return n;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin>>N>>M;
    string cmds;
    cin >> cmds;
    map<LL,set<PI>> ad;
    map<LL,set<PI>> bc;
    PI current;
    FOR(i,0,N){
        LL x,y;
        cin >> x>>y;
        PI p = {x,y};
            ad[x-y].insert(p);
            bc[x+y].insert(p);
        if(i==0) current = p;
    }
    trav(c,cmds){
        if(c=='A'){
            auto it = ad.find(current.first-current.second);
            if(it==ad.end()) continue;
            auto just_greator = (*it).second.upper_bound(current);
            if(just_greator==(*it).second.end()) continue;
            (*it).second.erase((*it).second.find(current));
            auto it2 = bc.find(current.first+current.second);
            if(it2!=bc.end() && (*it).second.find(current)!=(*it).second.end()) (*it2).second.erase((*it).second.find(current));
            current = (*just_greator);
        }
        else if (c=='D')
        {
            auto it = ad.find(current.first-current.second);
            if(it==ad.end()) continue;
            auto eq = (*it).second.find(current);
            if(eq==(*it).second.begin() or eq==(*it).second.end()) continue;
            eq--;
            (*it).second.erase((*it).second.find(current));
            auto it2 = bc.find(current.first+current.second);
            if(it2!=bc.end() and (*it).second.find(current)!=(*it).second.end()) (*it2).second.erase((*it).second.find(current));
            current = (*eq);
        }
        else if(c=='B'){
            auto it = bc.find(current.first+current.second);
            if(it==bc.end()) continue;
            auto just_greator = (*it).second.upper_bound(current);
            if(just_greator==(*it).second.end()) continue;
            (*it).second.erase((*it).second.find(current));
            auto it2 = ad.find(current.first-current.second);
            if(it2!=ad.end() and (*it).second.find(current)!=(*it).second.end()) (*it2).second.erase((*it).second.find(current));
            current = (*just_greator);
        }
        else{
            auto it = bc.find(current.first+current.second);
            if(it==bc.end()) continue;
            auto eq = (*it).second.find(current);
            if(eq==(*it).second.begin() or eq==(*it).second.end()) continue;
            eq--;
            (*it).second.erase((*it).second.find(current));
            auto it2 = ad.find(current.first-current.second);
            if(it2!=ad.end() and (*it).second.find(current)!=(*it).second.end()) (*it2).second.erase((*it).second.find(current));
            current = (*eq);
        }
        
    }
    cout << current.first << " " << current.second << endl;
    
    
    return 0;
}
