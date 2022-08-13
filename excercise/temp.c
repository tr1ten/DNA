#include <stdio.h>
int main()
{
    int ptr[] = {1,2,3};
    int *ptr2 = ptr+2;
    printf("%d\n", ptr2-ptr);
    return 0;
}
