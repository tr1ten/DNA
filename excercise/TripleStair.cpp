#include <iostream>
#include <vector>
#include <string>
using namespace std;
void tripleSum(int n,int &total)
{
    if(n<0)
    {
        return;
    }
    if(n==0)
    {
        total +=1;
        return;
    }
    tripleSum(n-1,total);
    tripleSum(n-2,total); 
    tripleSum(n-3,total);
}
int main()
{
    int total=0;
    tripleSum(4,total);
    cout << total;
    return 0;
}
