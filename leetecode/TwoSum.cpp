#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int,int> hm;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = (target-nums[i]);
        if(diff!=nums[i] && diff>=0)
        {
            
            hm[nums[i]] = i;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = (target-nums[i]);
        if(hm.count(diff))
        {
            return {i,hm[diff]};   
        }
    }
    return {0,1};
}
int main()
{
    twoSum({2,7,11,15},9);
    return 0;
}
