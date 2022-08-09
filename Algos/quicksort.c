#include <stdio.h>
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// both asc and desc
int partition(int *arr, int low, int high, int asc, int pivotIndex)
{
    swap(arr, high, pivotIndex);
    int pivot = arr[high];
    int p2 = low - 1;
    for (int i = low; i <= high; i++)
    {
        if (i != high && ((asc && arr[i] <= pivot) || (!asc && arr[i] >= pivot)))
        {
            p2++;
            swap(arr, p2, i);
        }
    }
    swap(arr, p2 + 1, high);
    return p2 + 1;
}
// O(n^2) for worst case and O(nlogn) for other
// space O(logn)
// not stable
void quickSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pi = partition(arr, low, high, 1, (low + high) / 2);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}
void testQuickSort()
{
    int n = 6;
    int arr[] = {6, 5, 4, 2, 2, 1};
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    testQuickSort();
    return 0;
}
