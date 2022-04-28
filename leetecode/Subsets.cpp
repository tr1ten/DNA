#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve(vector<int> &nums, int p, vector<int> subset, vector<vector<int>> &res)
{
    if (p >= nums.size())
    {
        return res.push_back(subset);
    }
    solve(nums, p + 1, subset, res);
    subset.push_back(nums[p]);
    solve(nums, p + 1, subset, res);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    solve(nums, 0, {}, res);
    return res;
}
int main()
{
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> subs = subsets(vec);
    for (int i = 0; i < subs.size(); i++)
    {
        for (int a : subs[i])
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
