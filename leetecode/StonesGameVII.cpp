class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++) pref[i] = pref[i-1] + stones[i-1];
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int sm = pref[j+1]-pref[i];
                dp[i][j] = sm + max(-stones[i]-(i+1<n?dp[i+1][j]:0),-stones[j]-(j-1>=0?dp[i][j-1]:0));
            }
        }
        return dp[0][n-1];
    }
};