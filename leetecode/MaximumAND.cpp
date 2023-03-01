#include <bits/stdc++.h>

using namespace std;
const int MAXN = 18;
int dp[1 << MAXN];
class Solution
{
public:
    int maximumANDSum(vector<int> &nums, int nk)
    {
        while (nums.size() < 2 * nk)
        {
            nums.push_back(0);
        }
        int n = nums.size();
        int ln = 1 << n;
        memset(dp, 0, sizeof(dp));
        for (int x = 1; x < ln; x++)
        {
            int slot = (__builtin_popcount(x) + 1) / 2;
            for (int i = 0; i < n; i++)
            {
                if ((x & (1 << i)) == 0)
                    continue;
                dp[x] = max(dp[x], dp[x ^ (1 << i)] + (nums[i] & slot));
            }
        }
        return dp[ln - 1];
    }
};