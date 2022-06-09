#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// to do memoize
int countFive(int n)
{ 
    int total=0;
    int temp=n;
    while (temp%5==0)
    {
        total++;
        temp /=5;
    }
    return total;
    
}
int fact(int n,int &total)
{
    if(n<2)
    {
        return;
    }
    total +=countFive(n);
    fact(n-1,total);

}
int trailingZeroes(int n) {
    int total = 0;
    fact(n,total);
    return total;
}
int main()
{
    
    return 0;
}
