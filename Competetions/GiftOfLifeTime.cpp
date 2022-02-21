#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void twoSort(vector<long long> &start, vector<long long> &end)
{
    long long n = start.size();
    long long gap = n;
    while (gap != 1)
    {
        // Shrink the gap factor by 1.3
        gap = long long(gap / 1.3);
        if (gap < 1)
            gap = 1;
        for (long long i = 0; i < n - gap; i++)
        {
            if (start[i] > start[i + gap])
            {
                swap(start[i], start[i + gap]);
                swap(end[i], end[i+gap]);
            }
            else if (start[i] == start[i + gap] && end[i] > end[i + gap])
            {
                swap(end[i], end[i + gap]);
            }
        }
    }
}
long long giftOfLife(vector<long long> &start, vector<long long> &end)
{
    twoSort(start, end);
    long long n = start.size();
    unordered_set<long long> stupidHash;
    long long res = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = start[i]; j <= end[i]; j++)
        {
            if (stupidHash.find(j) == stupidHash.end())
            {
                res++;
                stupidHash.insert(j);
                break;
            }
        }
    }
    return res;
}
long long main()
{
    long long T;
    cin >> T;
    vector<vector<long long>> allStarts;
    vector<vector<long long>> allEnds;
    for (long long i = 0; i < T; i++)
    {
        long long n;
        cin >> n;
        vector<long long> start;
        vector<long long> end;
        for (long long j = 0; j < n; j++)
        {
            long long n, k;
            cin >> n;
            cin >> k;
            start.push_back(n);
            end.push_back(k);
        }
        allStarts.push_back(start);
        allEnds.push_back(end);
    }
    for (long long i = 0; i < T; i++)
    {
        cout << giftOfLife(allStarts[i], allEnds[i]) << endl;
    }

    return 0;
}