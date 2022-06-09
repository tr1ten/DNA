#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int goalPost = n-1;
    for (int i = n-2; i >=0; i++)
    {
        if(nums[i]>=(n-goalPost))
        {
            goalPost = i;
        }
    }
    
    return i==0 ? true : false;
    
}
int main()
{
    
    return 0;
}
