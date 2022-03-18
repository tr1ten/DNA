#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int rec(int n, int target, unordered_map<int, int> &hashmap)
{
    if (hashmap.count(n))
    {
        return hashmap[n];
    }
    if (target - n < 3)
    {
        return target - n;
    }
    hashmap[n] = rec(n + 1, target, hashmap) + rec(n + 2, target, hashmap);
    return hashmap[n];
}
int climbStairs(int n)
{
    unordered_map<int, int> hashmap;
    return rec(0, n, hashmap);
}
int main()
{
    cout << climbStairs(45) << endl;
    return 0;
}
