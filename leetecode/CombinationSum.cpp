#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
int hashMe(vector<int> v)
{
    sort(v.begin(),v.end());
    std::hash<int> hasher;
    size_t seed = 0;
    for (int i : v)
    {
        seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}
void rec(int target, vector<int> res, vector<vector<int>> &allRes, vector<int> &candidates, unordered_set<int> &vc)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        int hash = hashMe(res);
        if (vc.count(hash))
        {
            return;
        }
        allRes.push_back(res);
        vc.insert(hash);
        return;
    }
    for (auto a : candidates)
    {
        res.push_back(a);
        rec(target - a, res, allRes, candidates, vc);
        res.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> allRes = {};
    unordered_set<int> vc;
        rec(target, {}, allRes, candidates, vc);
    return allRes;
}
int main()
{

    return 0;
}
