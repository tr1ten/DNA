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

void swap(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// swap ith element with last element, now check whether its child is larger, swap with it.
void deleteHeap(int *heap,int n,int i)
{
    heap[i] = heap[n-1];
    heap[n-1] = 0;
    int ndash = n-1;
    int j=i;
    while (j<ndash)
    {
        int left = 2*i;
        int right = 2*i + 1;
        int larger = heap[left] > heap[right] ? left : right;
        if(heap[j]<heap[larger])
        {
            swap(heap,j,larger);
            j = larger;
        }
        else{
            return;
        }

    }
    
}
// insert into correct position by checking parent, swapping if needeed
void insertHeap(int value,int *heap, int n)
{
    heap[n] = value;
    int i = n;
    while (i > 1)
    {
        if (value>heap[i/2])
        {
            swap(heap,i,i/2); 
        }
        else{
            break;
        }
        i /=2;
    }
}
int heapify(int *heap, int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = left+1;
    if(left<n&&heap[left]>heap[largest])
    {
        largest = left;
    }
    if(right<n&&heap[right]>heap[largest])
    {
        largest = right;
    }
    if(heap[largest]>heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap,n,largest);
    }

}
int buildHeap(int* heap,int n)
{
    for (int i = n/2; i >0; i--)
    {
        heapify(heap,n,i);
    }
    
}
int heapSort(int *arr,int n)
{
    printArr(arr,n);
    int heap[n+1];
    heap[0]=0;
    for (int i = 0; i < n; i++)
    {
        heap[i+1] = arr[i];
    }
    buildHeap(heap,n+1);

    for (int i = n; i >0; i--)
    {
        swap(heap,1,i);
        heapify(heap,i,1);

    }
    printArr(heap,n+1);
}
int main()
{
    // int heap[9] = {0, 50, 30, 40, 10, 5, 20, 30};
    // printf("%d",heap[0]);
    // printArr(heap, 8);
    // insertHeap(60,heap,8);
    // printArr(heap,9);
    // deleteHeap(heap,9,2);
    // printArr(heap,9);
    // int nheap[] = {0,2,3};
    // printArr(nheap,3);
    // buildHeap(nheap,3);
    // printArr(nheap,7);
    int arr[] = {5,3,2,6,33};
    heapSort(arr,5);
    return 0;
}
