#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
int findUnsortedSubarray(vector<int>& nums) {
    int mini=  INT32_MAX;
    int maxi = INT32_MIN;
    bool flag = false;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if(nums[i-1]>nums[i])
        {
            flag = true;
        }
        if(flag)
        {
            mini = min(mini,nums[i]);
        }
    }
    flag = false;
    for (int i = n-2; i >=0; i--)
    {
        if(nums[i]>nums[i+1])
        {
            flag = true;
        }
        if(flag)
        {
            maxi = max(maxi,nums[i]);
        }
    }
    int l,r;
    for (l = 0; l < n; l++)
    {
        if(mini<nums[l])
        {
            break;
        }
    }
    for (r = n-1; r >=0; r--)
    {
        if(maxi>nums[r])
        {
            break;
        }
    }
    
    return r<l?0:r-l+1;
    
}
int main()
{
    vector<int> nums = {2,1};
    cout << findUnsortedSubarray(nums);
    return 0;
}
