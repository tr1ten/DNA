#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isNeg(int n)
{
    return n >> 31;
}
int max(int a,int b)
{
    int k = isNeg(b-a);
    return b*(1-k) + a*k;

}
int main()
{
    cout << max(0,-1231231);
    return 0;
}
