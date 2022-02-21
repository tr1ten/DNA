#include <iostream>
#include <vector>
using namespace std;
int proposeDay(int N, vector<int> &girlQ, vector<int> &boyQ)
{
    int l;
    int r;
    l = N / 2 - 1;
    if (N % 2 == 0)
    {
        r = l + 1;
    }
    else
    {
        r = l + 2;
    }
    bool lastSwapped = true;
    bool inCorrectPos = true;
    int operations = 0;
    while (l >= 0)
    {
        if (girlQ[l] == boyQ[r] && girlQ[r] == boyQ[l])
        {
            if (l == (N / 2 - 1))
            {
                operations++;
            }
            else if (!lastSwapped)
            {
                operations += 2;
            }
            inCorrectPos = false;
            lastSwapped = true;
        }
        else
        {
            if (girlQ[l] != boyQ[l] || girlQ[r] != boyQ[r] && inCorrectPos)
            {
                inCorrectPos = false;
            }
            lastSwapped = false;
        }
        l--;
        r++;
    }
    if (inCorrectPos)
    {
        return 0;
    }
    return operations == 0 ? -1 : operations;
}

int main()
{
    int T;
    cin >> T;
    vector<vector<vector<int>>> testCases;
    for (int i = 0; i < T; i++)
    {
        int N;
        vector<vector<int>> testCase;
        cin >> N;
        testCase.push_back({});
        testCase.push_back({});

        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;
            testCase[0].push_back(n);
        }
        for (int k = 0; k < N; k++)
        {
            int n;
            cin >> n;
            testCase[1].push_back(n);
        }
        testCases.push_back(testCase);
    }
    for (int i = 0; i < T; i++)
    {
        cout << proposeDay(testCases[i][0].size(), testCases[i][1], testCases[i][0]) << endl;
    }
}
