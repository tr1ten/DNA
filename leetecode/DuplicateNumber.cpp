#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    int fast = 0;
    int slow = fast;
    while (1)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
        {
            slow = 0;
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
                
            }
            return slow;
        }
    }
}
int main()
{
    vector<int> a = {3,1,3,4,2};

    cout << findDuplicate(a) << endl;
    return 0;
}
