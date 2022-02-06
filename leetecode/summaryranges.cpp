#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> summaryRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<string> out;
    if (n == 0)
    {
        return out;
    }
    int start = nums[0];
    int end = start;
    for (int i = 1; i <n ; i++)
    {
        if (nums[i] == (end + 1))
        {
            end = nums[i];
        }
        else
        {
            if (start < end)
            {
                out.push_back(to_string(start) + "->" + to_string(end));
            }
            else
            {
                out.push_back(to_string(start));
            }
            start = nums[i];
            end = start;
        }
    }
    if (start < end)
    {
        out.push_back( to_string(start) + "->" + to_string(end));
    }
    else
    {
        out.push_back(to_string(start));
    }
    return out;
}
int main()
{
    vector<int> arr={0,1,2,4,5,7};
    vector<string> out=summaryRanges(arr);
    for(int i=0;i<out.size();i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}
