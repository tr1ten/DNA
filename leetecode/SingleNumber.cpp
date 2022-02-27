#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int N = nums.size();
    unordered_map<int, int> a;
    for (int i : nums)
    {
        if (a.count(i))
        {
            a[i] = 2;
        }
        else
        {
            a[i] = 1;
        }
    }
    for (auto x : a)
    {
        if (x.second == 1)
        {
            return x.first;
        }
    }
}
int main()
{
    vector<int> arr = {-1, -1, -2};
    cout << singleNumber(arr) << endl;
    return 0;
}
