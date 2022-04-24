#include <iostream>
#include <vector>
#include <string>
using namespace std;
void insertionSort(int *arr,int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (arr[j]>key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;         
    }
    
}
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
int main()
{
    int arr[] = {5,2,4,6,1,3};
    printArr(arr,6);
    insertionSort(arr,6);
    printArr(arr,6);
    return 0;
}
