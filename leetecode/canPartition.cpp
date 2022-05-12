#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
bool canPartition(vector<int> nums)
{
    unordered_set<int> hset;
    hset.insert(0);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if(sum%2!=0)
    {
        return false;
    }
    int target = sum/2;
    for (int i = nums.size()-1; i >= 0; i--)
    {
        auto temp = hset;
        for (auto val : temp)
        {
            int t = val + nums[i];
            if(t==target)
            {
                return true;
            }
            hset.insert(t);
        }
    }
    return false;
}
int main()
{
    cout << canPartition({1,5,11,3});
    return 0;
}
