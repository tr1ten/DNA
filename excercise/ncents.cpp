#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int rec(int n,int max)
{
    if(n<0) return 0;
    if(n==0) return 1;
    int res = rec(n-1,1);
    res += max >= 5 ? rec(n-5,5) : 0;
    res += max >= 10 ? rec(n-10,10) : 0;
    res += max >= 25 ? rec(n-25,25) : 0;
    return res;

}
int main()
{
    cout << rec(10,25) << endl;
    return 0;
}
