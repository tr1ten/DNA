#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

int nearestNumberIndex(vector<int> &menu, int n, vector<int> sortedIndex)
{
    int lastElementIndex = -1;
    for (const int index : sortedIndex)
    {
        if (menu[index] == n)
        {
            return index;
        }
        if (lastElementIndex >= 0 && menu[lastElementIndex] < n && menu[index] > n)
        {
            return index;
        }
        lastElementIndex = index;
    }
    return 0;
}
template <typename T>
vector<int> sortedIndices(const vector<T> &var)
{

    vector<int> y(var.size());
    size_t n(0);
    generate(begin(y), end(y), [&]
             { return n++; });

    sort(begin(y),
         end(y),
         [&](int i1, int i2)
         { return var[i1] < var[i2]; });

    return y;
}
int main()
{
    int N, D;
    vector<int> gmenu;
    vector<int> bmenu;
    vector<int> gMins;
    vector<int> bMins;
    cin >> N;
    cin >> D;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        bmenu.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        gmenu.push_back(a);
    }
    for (int i = 0; i < D; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        bMins.push_back(a);
        gMins.push_back(b);
    }
    // here we start
    unordered_map<int, int> bapparentToIndex;
    unordered_map<int, int> gapparentToIndex;

    vector<int> sbindex = sortedIndices(bmenu);
    vector<int> sgindex = sortedIndices(gmenu);
    for (int i = 0; i < N; i++)
    {
        bapparentToIndex.insert({sbindex[i], i});
        gapparentToIndex.insert({sgindex[i], i});

    }
    int totalExp = 0;
    for (int i = 0; i < D; i++)
    {
        int bai =(nearestNumberIndex(bmenu, bMins[i], sbindex));
        int gai = (nearestNumberIndex(gmenu, gMins[i], sgindex));
        while (bai < N && gai < N && bapparentToIndex.at(bai) != gapparentToIndex.at(gai))
        {
            if (bmenu[bapparentToIndex.at(bai)] > gmenu[gapparentToIndex.at(gai)])
            {
                gai++;
            }
            else if (bmenu[bapparentToIndex.at(bai)] == gmenu[gapparentToIndex.at(gai)])
            {
                if (gai < (N - 1) && bapparentToIndex.at(bai) == gapparentToIndex.at(gai + 1))
                {
                    gai++;
                }
                else
                {
                    bai++;
                }
            }

            else
            {
                bai++;
            }
        }
        if (bai < N && gai < N)
        {
            totalExp += (bmenu[bapparentToIndex.at(bai)] + gmenu[gapparentToIndex.at(gai)]);
        }
    }
    cout << totalExp << endl;
    return 0;
}
