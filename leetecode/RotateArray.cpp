#include <iostream>
#include <vector>
#include <string>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k || n > 1)
    {
        k = k % n;
        vector<int> tempNums = nums;
        for (int i = k; i > 0; i--)
        {
            nums[k - i] = tempNums[n - i];
        }
        for (int i = 0; i < (n - k); i++)
        {
            nums[k + i] = tempNums[i];
        }
    }
}
int main()
{

    return 0;
}
