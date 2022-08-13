#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findNext(vector<int> &temps, int i, int e, int s = -1)
{
    int j = max(2 * i, s);
    while (j <= e && temps[i] <= temps[j])
    {
        j++;
    }
    return j;
}
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int lastFound = -1;
    int i = 0;
    int n = temperatures.size();
    vector<int> res(n, 0);
    while (i < n)
    {
        int j = lastFound == -1 ? findNext(temperatures, i, n - 1) : (temperatures[i - 1] > temperatures[i] ? findNext(temperatures, i, lastFound) : findNext(temperatures, i, n - 1, lastFound));
        if (j < n)
        {
            res[i] = j - i;
            lastFound = j;
        }
        i++;
    }
    return res;
}
int main()
{

    return 0;
}
