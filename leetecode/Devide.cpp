#include <iostream>
// i hate c++ -_-
int max(long int a, long int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}

int divide(int dividend, int divisor)
{
    if(dividend==-2147483648 && divisor==-1)
    {
        return 2147483637;
    }
    if(dividend==-2147483648 && divisor==-2147483648)
    {
        return 1;
    }
    
    short int isNeg = (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) ? -1 : 1;
    long i = 0;
    long mul;
    unsigned dd = abs(dividend);
    unsigned div = abs(divisor);
    unsigned int tdiv;
    while (dd >= div)
    {
        tdiv = div;
        mul =1;
        while(dd>=tdiv )
        {
            dd -=tdiv;
            i +=mul;
            mul +=mul;
            tdiv +=tdiv;
        }
    }
    return min(2147483647,max(-2147483648,isNeg*i));
}
int main()
{
    std::cout << divide(-2147483648,-1) << std::endl;
     return 0;
}
