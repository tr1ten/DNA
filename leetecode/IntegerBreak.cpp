#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
public:
    struct ArrayHasher
    {
        std::size_t operator()(const std::array<unsigned int, 2> &arr) const
        {
            std::size_t h = arr[0] >= arr[1] ? arr[0] * arr[0] + arr[0] + arr[1] : arr[0] + arr[1] * arr[1];
            return h;
        }
    };
    unordered_map<array<unsigned int, 2>, unsigned int, ArrayHasher> cache;
    unsigned int rec(unsigned int root, unsigned int product, unsigned int target)
    {
        if (cache.count({root, product}))
        {
            return cache[{root, product}];
        }
        if (root == target)
        {
            return product;
        }
        if (root > target)
        {
            return 1;
        }
        unsigned int temp;
        unsigned int maxElement = rec(root + 1, product, target);
        for (unsigned int i = 2; i <= target - root; i++)
        {
            temp = rec(root + i, product * i, target);
            if (temp > maxElement)
            {
                maxElement = temp;
            }
        }
        return cache[{root, product}] = maxElement;
    }
    unsigned int integerBreak(unsigned int n)
    {
        unsigned int temp;
        unsigned int maxElement = rec(1, 1, n);
        for (unsigned int i = 1; i < n; i++)
        {

            temp = rec(i, i, n);
            if (temp > maxElement)
            {
                maxElement = temp;
            }
        }

        return maxElement;
    }
};