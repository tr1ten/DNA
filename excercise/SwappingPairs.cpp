#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int findSwapValues(int A[], int n, int B[], int m)
{
    sort(A,A+n);
    sort(B,B+m);
    int asum = 0;
    int bsum = 0;
    for (int i = 0; i < n; i++)
    {
        asum += A[i];
    }
    for (int i = 0; i < m; i++)
    {
        bsum += B[i];
    }
    int p1=0;
    int p2=0;
    int diff = bsum-asum;
    if(diff%2!=0)
    {
        return -1;
    }
    diff /=2;
    int temp;
    while (p1<n && p2>=0)
    {
        temp =  B[p2]-A[p1];
        if(temp==diff){
            return 1;
        }
        if(temp<diff)
        {
            p2++;
        }
        else{
            p1++;
        }
    }
    return -1;

}
int main()
{
    
    return 0;
}
