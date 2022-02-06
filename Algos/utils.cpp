#include "utils.h"
int arrMax(int* array,int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
    }
    return max;
}
