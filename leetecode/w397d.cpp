#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define all(x) x.begin(), x.end()

const ll mod = 1e9+7; // change me for god sake look at problem mod
const ll inf = 1005;

const int N = 14;

class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1<<n,vector<int>(n+1,inf)),nxti(1<<n,vector<int>(n+1,0));
        dp[0][0] = 0;
        rep(mask,1,1<<n){
            rep(cur,0,n){
                if(!(mask&(1<<cur))) continue;
                int wm = mask^(1<<cur);
                rep(nxt,0,n){
                    if(dp[wm][nxt]==inf || cur==nxt) continue;
                    int val = dp[wm][nxt] + abs(nums[nxt] - cur);
                    if(dp[mask][cur] > val ) {
                        dp[mask][cur] = val;
                        nxti[mask][cur] = nxt;
                    }
                }
                
            }
        }
        vector<int> res{0};
        int mask = (1<<n) -1;
        while (res.size()<n)
        {
            int j = nxti[mask][res.back()];
            mask ^= 1<<res.back();
            res.push_back(j);
        }
        
        return res;
    }
};

