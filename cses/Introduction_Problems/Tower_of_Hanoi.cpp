#include <iostream>
#include <vector>
using namespace std;
void printHonoi(int start,int target){
    cout << start+1 << " " << target+1 << endl;
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
        printHonoi(sIdx,tIdx);
        return 1;
    }
    else if ((nStart) == 2)
    {
        honoi[hIdx].push_back(vecPop(honoi[sIdx]));
        printHonoi(sIdx,hIdx);
        honoi[tIdx].push_back(vecPop(honoi[sIdx]));
        printHonoi(sIdx,tIdx);
        honoi[tIdx].push_back(vecPop(honoi[hIdx]));
        printHonoi(hIdx,tIdx);

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

        return  nStart;
    }
}
int main()
{

    int n;
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
    cout << (1<<n) - 1 << endl;
    solveHonoi(honoi, n, 0, 1, 2,r);

    return 0;
}
