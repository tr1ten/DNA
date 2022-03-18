#include <iostream>
#include <vector>
#include <string>
using namespace std;
// bad implementation of sieves
int countPrimes(int n) {
    vector<int> arr(n+1,1);
    if(n<3)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        int p = 2*i;
        if(!arr[i])
        {
            continue;
        }
        while (p<n)
        {
            arr[p] = 0;
            p +=i;
        }
    }
    int count=0;
    for (int i = 2; i < n; i++)
    {
        if(arr[i]) {
            count++;
        }
    }
    return count;
    
}
int main()
{
    cout << countPrimes(10) << endl;
}