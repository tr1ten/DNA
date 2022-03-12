#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;
// decision tree + backtract + hashmap = <3
class Solution
{
public:
    unordered_map<int, int> hashmap;
    int numSquares(int target, int sum, int count)
    {
        // cout << "\ngot sum:" << sum << " count:" << count;
        if (sum == target)
        {
            return 0;
        }
        if (hashmap.count(sum))
        {
            return hashmap[sum];
        }
        int minmmin = target;
        int tempMin;
        for (int i = 1; i <=sqrt(target); i++)
        {
            int ns = sum + pow(i, 2);
            if (ns > target)
            {
                break;
            }
            tempMin = 1 + numSquares(target, ns, count + 1);
            minmmin = min(tempMin, minmmin);
        }
        hashmap[sum] = minmmin;
        return minmmin;
    }

    int numSquares(int n)
    {
        return numSquares(n, 0, 0);
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.numSquares(100);
    return 0;
}
