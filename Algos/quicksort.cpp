#include <iostream>
#include <vector>
#include <string>
using namespace std;
void swap(vector<int> &arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(vector<int> &arr,int l,int r)
{
    int j=l-1;
    int pivot = arr[r];
    // starting element less than pivot
    for (int i = l; i < r; i++)
    {
        if(pivot>arr[i]){
            j++;
            swap(arr,i,j);
        }

    }
    // i is the last element smaller than pivot
    swap(arr,j+1,r);
    return j+1;
    
}
void quicksort(vector<int> &arr,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int pi = partition(arr,l,r);
    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,r);

}
void printArr(vector<int> arr)
{
    for (auto i:arr)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> arr = {8,7,6,1,0,9,2};
    quicksort(arr,0,6);
    printArr(arr);
    
    return 0;
}
