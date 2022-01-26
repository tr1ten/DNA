#include <iostream>
#include <vector>
using namespace std;
void printHonoi(vector<int> startVec, vector<int> holdVec, vector<int> targetVec,int step)
{
    cout << "Honoi Tower after "<< step<<"->\n =: ";
    for (int val : startVec)
    {
        if (val)
        {
            cout << val << " ";
        }
    }
    cout << "\n =: ";
    for (int val : holdVec)
    {
        if (val)
        {
            cout << val << " ";
        }
    }
    cout << "\n =: ";
    for (int val : targetVec)
    {
        if (val)
        {
            cout << val << " ";
        }
    }
    cout << endl;
}
int vecPop(vector<int> &vec)
{
    int temp = vec[vec.size() - 1];
    vec.pop_back();
    return temp;
}
int solveHonoi(vector<vector<int>> &honoi, int nStart, int sIdx, int hIdx, int tIdx,int &step)
{
    // base cases
    if ((nStart) == 1)
    {
        honoi[tIdx].push_back(vecPop(honoi[sIdx]));
        step++;
        printHonoi(honoi[0], honoi[1], honoi[2],step);

        // cout << "moving one el ending";
        return 1;
    }
    else if ((nStart) == 2)
    {
        honoi[hIdx].push_back(vecPop(honoi[sIdx]));
        printHonoi(honoi[0], honoi[1], honoi[2],++step);

        honoi[tIdx].push_back(vecPop(honoi[sIdx]));
        printHonoi(honoi[0], honoi[1], honoi[2],++step);

        honoi[tIdx].push_back(vecPop(honoi[hIdx]));
        printHonoi(honoi[0], honoi[1], honoi[2],++step);

        return 2;
    }

    else
    {
        // start to hold
        int n1 = solveHonoi(honoi, nStart - 1, sIdx, tIdx, hIdx,step);

        // start to target
        int n2 = solveHonoi(honoi, nStart - n1, sIdx, hIdx, tIdx,step);
        // holder to target
        int n3 = solveHonoi(honoi, nStart - 1, hIdx, sIdx, tIdx,step);

        return nStart;
    }
}
int main()
{

    int n;
    cout << "no of sticks:";
    cin >> n;
    vector<int> sVec(n, 0);
    vector<int> hVec;
    vector<int> tVec;

    for (int i = 0; i < n; i++)
    {
        sVec[i] = n - i;
    }
    int r=0;
    vector<vector<int>> honoi = {sVec, hVec, tVec};
    printHonoi(sVec, hVec, tVec,-1);
    solveHonoi(honoi, n, 0, 1, 2,r);

    return 0;
}
