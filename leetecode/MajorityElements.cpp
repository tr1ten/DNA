#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> dict;
    vector<int> res;
    int n = nums.size() / 3;
    for (auto a : nums)
    {
        if (dict.count(a))
        {
            dict[a]++;
        }
        else
        {
            dict[a] = 1;
        }
    }
    for (auto el : dict)
    {
        if (el.second > n)
        {
            res.push_back(el.first);
        }
    }
    return res;
}
int main()
{

    return 0;
}
