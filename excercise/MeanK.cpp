#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool rec(vector<int> nSet,int index,int csum,int cn,int k)
{
    int n = nSet.size();
    if(csum && (csum*1.0/cn)==(double)k)
    {
        return true;
    }
    if (index>=n)
    {
        return false;
    }
    return rec(nSet,index+1,csum,cn,k) || rec(nSet,index+1,csum+nSet[index],cn+1,k);
}

int main()
{
    vector<int> ps = {-1,2,3,1,10};
    cout << rec(ps,0,0,0,4);
    return 0;
}
