#include <iostream>
#include <vector>
#include <string>
using namespace std;
int maxBits(vector<int> bn)
{
    vector<int> vec;
    for (int i = 0; i < bn.size(); i++)
    {
        if(bn[i]==0)
        {
            vec.push_back(i);
        }
    }
    int mbits = 0;
    int lbits,rbits;
    int temp;
    for (int i = 0; i < vec.size(); i++)
    {
        lbits = i!=0 ? vec[i]-vec[i-1]-1 :vec[i];
        rbits = i!=(vec.size()-1) ? vec[i+1]-vec[i]-1 :bn.size()-1-vec[i];
        temp = lbits + rbits + 1;
        if(temp>mbits)
        {
            mbits = temp;
        }
        
    }
    return mbits;
    
    
}
int main()
{
    cout << maxBits({1,1,0,1,1,1,0,1,1,1,1});
    return 0;
}
