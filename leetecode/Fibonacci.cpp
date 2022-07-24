#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int fib2(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib2(n - 1) + fib2(n - 2);
}

// fibonacci using difference equation
int fib(int n)
{
    n = n+1;
    double c1 = (5.0 - pow(5, 0.5)) / 10;
    double c2 = (5.0 + pow(5, 0.5)) / 10;
    double y1 = c1 * pow(((1.0 + pow(5, 0.5))) / 2, n);
    double y2 = c2 * pow(((1.0 - pow(5, 0.5))) / 2, n);
    return round(y1 + y2);
}
int main()
{
    // print 10 fib
    for (int i = 0; i <=30; i++)
    {
        cout << (fib(i)==fib2(i)) << endl;
    }
    return 0;
}
