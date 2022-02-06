#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int sum = (nums.size() * (nums.size() + 1)) / 2;
    for (int i:nums)
    {
        sum -= i;
    }
    return sum;
}
int main()
{
    vector<int> nums = {3, 0, 1};
    cout<< missingNumber(nums);
    return 0;
}
