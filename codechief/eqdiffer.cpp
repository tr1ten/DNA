#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int solve(vector<int> &vec)
{
    int n = vec.size();
    if(n<3)
    {
        return 0;
    }
    unordered_map<int, int> hashmap;
    for (int i = 0; i < n; i++)
    {
        if (hashmap.count(vec[i]))
        {
            hashmap[vec[i]]++;
        }
        else
        {

            hashmap[vec[i]] = 1;
        }
    }
    int maxEl;
    int count=0;
    for (auto& it:hashmap)
    {
        if(it.second>count)
        {
            maxEl = it.first;
            count = it.second;
        }
    }
    return count==1 ?  n-2 : n-count;
    
}
int main()
{
    int T;
    cin >> T;
    vector<vector<int>> testcases;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            vec.push_back(a);
        }
        testcases.push_back(vec);
    }
    vector<int> sols;

    for (auto vec : testcases)
    {
        sols.push_back(solve(vec));
    }
    for (auto sol : sols)
    {
        cout << sol << endl;
    }

    return 0;
}
