#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// bad implementation of sieves
int nthUglyNumber(int n)
{
    int twop = 0;
    int threep = 0;
    int fivep = 0;
    vector<int> fkarr;
    unordered_set<int> hashmap;
    fkarr.push_back(1);
    int temp1 = fkarr[twop]*2;
    int temp2 = fkarr[threep]*3;
    int temp3 = fkarr[fivep]*5;

    while (fkarr.size() < n)
    {
        int mmin = min(temp1, temp2) > (temp3) ? temp3 : min(temp1, temp2);

        if (!hashmap.count(mmin))
        {
            fkarr.push_back(mmin);
            hashmap.insert(mmin);
        }

        if (mmin == temp1)
        {
            twop++;
            temp1 = fkarr[twop]*2;
        }
        if (mmin == temp2)
        {
            threep++;
            temp2 = fkarr[threep]*3;
        }
        if (mmin == temp3)
        {
            fivep++;
            temp3 = fkarr[fivep]*5;
        }
    }
    return fkarr[n - 1];
}
int main()
{
    cout << nthUglyNumber(10) << endl;
    return 0;
}