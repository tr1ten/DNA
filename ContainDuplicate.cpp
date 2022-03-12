#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> hashmap;
    for (auto a : nums)
    {
        if (hashmap.count(a))
        {
            return true;
        }
        hashmap.insert(a);
    }
    return false;
}
int main()
{

    return 0;
}
