#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int a = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == a)
        {
            count++;
        }
        else if (count == 0)
        {
            a = nums[i];
        }
        else
        {
            count--;
        }

    }
    return a;
}
int main()
{

    return 0;
}
