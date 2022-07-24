#include <stdio.h>
void printArr(int *arr, int n)
{
    // printf("%d",arr[0]);
    printf("\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]\n ");
}
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// make subtree a heap recusively, sift down
void heapify(int *heap, int i, int n)
{
    int leftC = 2 * i;
    int rightC = 2 * i + 1;
    if (leftC >= n && rightC >= n)
    {
        return;
    }
    int larger;
    if (leftC >= n)
    {
        larger = rightC;
    }
    else if (rightC >= n)
    {
        larger = leftC;
    }
    else
    {

        larger = heap[leftC] > heap[rightC] ? leftC : rightC;
    }
    if (heap[i] < heap[larger])
    {
        swap(heap, i, larger);
        heapify(heap, larger, n);
    }
}
// perform delete operation, heapify it return delete value
int extractMax(int *heap, int n)
{
    int temp = heap[1];
    heap[1] = heap[n - 1];
    heapify(heap, 1, n - 1);
    return temp;
}
void buildHeap(int *arr, int n, int *heap)
{

    for (int i = n / 2; i >= 1; i--)
    {
        heapify(heap, i, n);
    }
}
int *heapSort(int *arr, int n)
{
    int ndash = n + 1;
    int heap[ndash];
    for (int i = 0; i < n; i++)
    {
        heap[i + 1] = arr[i];
    }

    buildHeap(arr, ndash, heap);
    int *sorted = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        sorted[n - 1 - i] = extractMax(heap, ndash - i);
    }
    return sorted;
}
int main(int argc, char const *argv[])
{
    // test heap sort with random array
    int n = 199;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    printArr(arr, n);
    int *sorted = heapSort(arr, n);
    printArr(sorted, n);
    // check is array sorted
    for (int i = 0; i < n - 1; i++)
    {
        if (sorted[i] > sorted[i + 1])
        {
            printf("not sorted\n");
            break;
        }
    }
    return 0;
}
