#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int bs(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int index = bs(nums, target);
    if(index==-1)
    {
        return {-1,-1};
    }
    vector<int> out = {index,index};
    for (int i = index+1; i < nums.size(); i++)
    {
        if(nums[i]!=target)
        {
            break;
        }
        out[1]++;
        
    }
    for (int i = index-1; i >=0; i--)
    {
        if(nums[i]!=target)
        {
            break;
        }
        out[0]--;
        
    }
    return out;
    
}
int main()
{
    vector<int> a = {};
    cout << searchRange(a, 9)[0] << " , " << searchRange(a, 9)[1] << endl;
    return 0;
}
