#include <iostream>
#include <vector>
#include <string>
using namespace std;
// min max 0,n-1 -> our  
int optimize(int i,int j,vector<int>& nums,vector<vector<int>> &dp)
{
    // base case
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return nums[i];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int case1 = nums[i] + min(optimize(i+2,j,nums,dp),optimize(i+1,j-1,nums,dp));
    int case2 = nums[j] + min(optimize(i,j-2,nums,dp),optimize(i+1,j-1,nums,dp));
    return dp[i][j] = max(case1,case2);

}
bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(50,vector<int>(50,-1));
        int total=0;
        for (int i:nums)
        {
            total +=i;
        }
        
        int player1Max = optimize(0,nums.size()-1,nums,dp);
        return (2*player1Max-total) >= 0 ? true : false;

    }
int main()
{
    vector<int> nims = {1,2,3,4};
    cout << PredictTheWinner(nims) << endl;
    return 0;
}
