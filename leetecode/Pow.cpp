#include <iostream>

double myPow(double x, int n)
{
    if(n==0 || x == 1 || (x==-1 && n%2==0))
    {
        return 1;
    }
    if(x==-1 && n%2!=0)
    {
        return -1;
    }
    if(x==0)
    {
        return 0;
    }
    x = n>0?x: 1/x;
    n = abs(n);
    double res = x;
    unsigned int i = 1;
    while (i<n && res!=0)
    {
        double temp=x;
        unsigned int mul = 1;
        while ((i+mul)<=n && res!=0)
        {
            res *=temp;
            temp *=temp;
            i +=mul;
            mul +=mul;
        }
        
    }
    return res;
    
    
}
int main()
{
    std::cout << myPow(2,-2147483648) << std::endl;
    return 0;
}

