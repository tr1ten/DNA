#include "stdio.h"
int main(int argc, char const *argv[])
{
    register a=25;
    int *p = &a;
    printf("%d",*p);
    return 0;
}
