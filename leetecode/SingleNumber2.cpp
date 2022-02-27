#include <iostream>
#include <vector>
#include <string>
using namespace std;
// only O(N) sol i can find not intuitive at all
int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;
    for (auto el : nums)
    {
        ones = (ones ^ el) & (~twos);
        twos = (twos ^ el) & (~ones);
    }
    return ones;
}
int main()
{
    vector<int> arr = {2, 2, 2, 3};
    cout << singleNumber(arr) << endl;
    return 0;
}
