#include <iostream>
#include <vector>
#include <string>
using namespace std;
int maximumPopulation(vector<vector<int>>& logs) {
    int OFFSET = 1950;
    const static int MAXYEARS = 101;
    int arr[MAXYEARS] = {0};
    for (auto range:logs)
    {
        for (int i = range[0]; i < range[1]; i++)
        {
            arr[i-OFFSET] +=1;
        }
    }
    int largest = arr[0];
    int index = 0;
    for (int i = 1; i < MAXYEARS; i++)
    {   
        if(largest<arr[i])
        {
            largest = arr[i];
            index = i;
        }
    }
    return index+OFFSET;
    
}
int main()
{
    
    return 0;
}
