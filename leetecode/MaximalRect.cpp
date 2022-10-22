#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        if (heights[i] * (n) <= maxSize)
        {
            continue;
        }
        while (j < n && heights[j] >= heights[i])
        {
            j++;
        }
        int left = i-1;
        while (left>=0 && heights[left] >= heights[i])
        {
            left--;
        }
        maxSize = max(heights[i] * (j-left-1), maxSize);
    }
    return maxSize;
}
int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp;
        int n =matrix.size(), m = matrix[0].size();
        dp.resize(n,vector<int>(m,0));
        for (int j = 0; j < m; j++)
        {
            int count=0;
            for (int i = 0; i<n; i++)
            {
                if(matrix[i][j]=='0') count=0;
                else dp[i][j] = ++count;
            }
        }
        int mx=0;
        for (int i = 0; i < n; i++)
        {
            mx = max(largestRectangleArea(dp[i]),mx);
        }
        return mx;        
        
    }
};