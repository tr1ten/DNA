#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#define N 1000000007
using namespace std;
static map<int, long long> modLookup;
int twobmodn(int b)
{
    if (modLookup.count(b) != 0)
    {
        return modLookup.at(b);
    }
    if (b <= 32)
    {
        modLookup.insert(pair<int, long long>(b, ((1LL << b) % N)));
        return modLookup.at(b);
    }
    int a = b / 2;
    long long c = twobmodn(b - a);
    long long d = twobmodn(a);
    cout << "multiply " << (long long)(c * d) << endl;
    modLookup.insert(pair<int, long long>(b, ((long long)(c * d)) % N));
    return modLookup.at(b);
}
int totalSubset(vector<int> &vec)
{
    int n = vec.size();
    int isOdd = 0;
    for (long long i : vec)
    {
        if (((int)log2(i)) % 2 != 0)
        {
            isOdd++;
            break;
        }
    }
    if (isOdd == 0)
    {
        return (twobmodn(n) + (N - 1)) % N;
    }
    else
    {
        return (twobmodn(n - 1) + (N - 1)) % N;
    }
}
int main()
{
    // int T;
    // cin >> T;
    // vector<vector<int>> tcases;
    // for (int i = 0; i < T; i++)
    // {
    //     int nN;
    //     cin >> nN;
    //     tcases.push_back({});
    //     for (int j = 0; j < nN; j++)
    //     {
    //         long long a;
    //         cin >> a;
    //         tcases[i].push_back(a);
    //     }
    // }

    // vector<int> vec = {1, 4, 16, 64};
    // for (int i = 0; i < T; i++)
    // {
    //     cout << totalSubset(tcases[i]) << endl;
    // }
    cout << twobmodn(2000000) << endl;
    return 0;
}
