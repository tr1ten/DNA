#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> decimal2bin(int n)
{
    int q=n;
    int r;
    vector<int> bin;
    while (q>0)
    {
        r = q%2;
        q = q/2;
        bin.push_back(r);
    }
    reverse(bin.begin(),bin.end());
    return bin;
    
}
int bin2decimal(vector<int> bin)
{
    int sum = 0;
    for (int i = 0; i < bin.size(); i++)
    {
        sum += (1<<i)*bin[bin.size()-i-1];
    }
    return sum;
}
void nextNumber(int n)
{
    auto bin = decimal2bin(n);
    vector<int> zeroIn;
    for (int i = 0; i < bin.size(); i++)
    {
        if(bin[i]==0)
        {
            zeroIn.push_back(i);
        }
    }
    auto nextLower= bin;
    swap(nextLower[zeroIn[0]],nextLower[zeroIn[0]-1]);
    int zi = zeroIn.size()-1;
    auto nextHigher = bin;
    while (zi>=0)
    {
        if((zeroIn[zi]+1) < nextHigher.size() && nextHigher[zeroIn[zi]+1])
        {
            swap(nextHigher[zeroIn[zi]+1],nextHigher[zeroIn[zi]])
            break;
        }
    }
    
    cout << bin2decimal(nextLower);
    
}
int main()
{
    nextNumber(44);
    return 0;
}
