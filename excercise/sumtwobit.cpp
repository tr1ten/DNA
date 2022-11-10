#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printArr(int *arr, int n)
{
    // printf("%d",arr[0]);
    cout << "\n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "]\n ";
}
void sumTwoBit(int *first,int *second, int n)
{
    int res[n+1];
    int carry = 0;
    for (int i = n; i >0; i--)
    {
        int temp = first[i-1] ^ second[i-1];
        int tempC = temp ^ carry;
        carry = first[i-1] & carry || second[i-1] & carry || first[i-1] & second[i-1];
        res[i] = tempC;
    }
    res[0] = carry;
    printArr(res,n+1);
    
}   
int getSum(int a,int b)
    {
    int res = 0;
    bool carry = 0;
    int n = 32;
    bool f=0;
    bool s=0;
    for (int i = 0; i <n; i++)
    {
        f = a & (1<<i);
        s = b & (1<<i);
        bool tempC =  f ^ s ^ carry;
        carry = f & carry || s & carry || f & s;
        res = res | (tempC<<(i));
    }
    return res;
    
    }
int main()
{
    int a[] = {1,1,0,1};
    // sumTwoBit(a,a,4);
    cout << getSum(-1000,-1000);
    return 0;
}
