#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isBadVersion(int n)
{
    return n>=4;
}
int firstBadVersion(int n) 
{
    int h,l;
    h = n-1;
    l = 0;
    int mid;
    while (l<=h)
    {
        mid = (l+h)/2;
        if(isBadVersion(mid+1))
        {
            if(!isBadVersion(mid))
            {
                return mid+1;
            }
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return mid+1;
    
    
}
int main()
{
    cout << firstBadVersion(6);
    return 0;
}
