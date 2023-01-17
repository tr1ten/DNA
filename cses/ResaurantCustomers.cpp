#include <cstdio>
#include <bits/stdc++.h>
#include <stack>
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
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions max overlapping intervals   
size_t solve(vector<vector<int>> ivals){
    mk_mat(times,2*ivals.size(),2,0);
    int i=0;
    trav(x,ivals){
        times[i][0]=x[0];
        times[i][1]=1;
        times[i+ivals.size()][0]=x[1];
        times[i+ivals.size()][1]=-1;
        i++;
    }
    sort_vec(times);
    int res = 0;
    int op=0, cl =0;
    trav(x,times){
        int s=x[0],f=x[1];
        if(f<0) cl++;
        else op++;
        res = max(res,op-cl);
    }
    return res;
}
size_t solve2(vector<vector<int>> ivals){
    sort_vec(ivals);
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(ivals[0][1]);
    FOR(i,1,ivals.size()){
        if(ivals[i][0]>=pq.top()) pq.pop();
        pq.push(ivals[i][1]);
    }
    return pq. size();
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    mk_mat(arr,N,2,0);
    F0R(i,N){
        cin>>arr[i][0]>>arr[i][1];
    }
    cout<<solve2(arr)<<endl;
    return 0;
}
