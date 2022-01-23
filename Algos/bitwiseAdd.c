#include <stdio.h>

int addTwoNumbers(int a,int b)
{
    while (b!=0)
    {
        int temp = a & b;
        a = a ^ b;
        b = temp << 1;
    }
    return a;
    
}

int main()
{
    int a=1,n;
    scanf("%d",&n);
    do
    {
        printf("%d",a);
        a++;
    } while (a<=n);
    
    return 0;
}
