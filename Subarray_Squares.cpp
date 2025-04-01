#include <bits/stdc++.h>
using namespace std;
/*
    NOT use unordered map use map
    NOT use seg tree use fenwick tree
    THINK before you code
*/

const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;

#define ll long long
const long long inf = 1e15;
const int N = 1005;
ll dp_prev[N],dp_cur[N];
ll i,K,n;
ll a_pref[N],c_pref[N];
ll get_cost(int k,int j){
    return (a_pref[j+1]+K*i)*(c_pref[j+1]-c_pref[k]);
}
ll mn_ans;
void solve_dp(int l,int r,int optl,int optr){
    if(l>r) return;
    int j = (l+r)>>1;
    pair<ll,int> best = {inf,n};
    for(int k=0;k<=min(j,optr);k++){
        best = min(best,{ (k? dp_prev[k-1] : 0) + get_cost(k,j),k});
    }
    dp_cur[j] = best.first;
    solve_dp(l,j-1,optl,best.second);
    solve_dp(j+1,r,best.second,optr);
}
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        n = nums.size();
        int m=n;
        K = k;
        for(int i=0;i<n;i++){
            a_pref[i+1] = a_pref[i] + nums[i];
            c_pref[i+1] = c_pref[i] + cost[i];
        } 
        mn_ans = inf;   
        i = 1;
        for(int j=0;j<n;j++){
            dp_prev[j] = get_cost(0,j);
        }
        mn_ans = dp_prev[n-1];
        while (i<=n)
        {
            i++;
            solve_dp(0,n-1,0,n-1);
            mn_ans = min(mn_ans,dp_cur[n-1]);
            swap(dp_cur,dp_prev);
        }
        return mn_ans;
    }
};

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n),cos(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> cos[i];
    cout << Solution().minimumCost(a,cos,k) << endl;
    return 0;
}
