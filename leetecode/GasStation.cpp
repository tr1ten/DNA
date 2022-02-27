#include <iostream>
#include <vector>
#include <string>
using namespace std;
// did differently on lc, no need to cycle 
int canCompleteCircuit(vector<int> gas, vector<int> cost)
{
    vector<int> diff;
    vector<int> pos;
    int n = gas.size();
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int df = gas[i] - cost[i];
        s += df;
        diff.push_back(df);
        if (df >= 0)
        {
            pos.push_back(i);
        }
    }
    if (s < 0)
    {
        return 0;
    }
    int sum = 0;
    int i = 0;
    int ii=pos[i];
    int t = ii;
    while (ii < n)
    {
        sum += diff[t];
        if (sum < 0)
        {
            i++;
            ii = pos[i];
            t = ii;
            sum = 0;
            continue;
        }
        t = (t + 1) == n ? 0 : t + 1;
        if (i == t)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    cout << canCompleteCircuit({2, 3, 4}, {3, 4, 3}) << endl;
    return 0;
}
