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
int main()
{
    int a[] = {1,1,0,1};
    sumTwoBit(a,a,4);
    return 0;
}
