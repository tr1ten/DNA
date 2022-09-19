#include <stdio.h>

void printArr(int *arr, int start,int n)
{
    // printf("%d",arr[0]);
    printf("\n[ ");
    for (int i = start; i < n; i++)
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

int heapify(int *heap, int n, int i)
{
    int largest = i;
    int left = 2*i+1;
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
        swap(heap,largest,i);
        heapify(heap,n,largest);
    }

}

void increaseKey(int *heap,int n,int index,int key){
    if(index>=n || heap[index]>=key) return;
    heap[index] = key;
    int i=index;
    while (i>=0 && key>heap[(i-1)/2])
    {
        swap(heap,i,(i-1)/2);
        i = (i-1)/2;
    }
    
}

// swap ith element with last element, now check whether its child is larger, swap with it.
void deleteHeap(int *heap,int n,int i)
{
    if(heap[i]<heap[n-1]) {
        return increaseKey(heap,n-1,i,heap[n-1]);
    }
    else{
        heap[i] = heap[n-1];
        heap[n-1] = 0;
        heapify(heap,n-1,i);
    }
    
}
// insert into correct position by checking parent, swapping if needeed
void insertHeap(int value,int *heap, int n)
{
    heap[n] = value;
    int i = n;
    while (i > 0)
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
int buildHeap(int* heap,int n)
{
    for (int i = n/2-1; i >=0; i--)
    {
        heapify(heap,n,i);
    }
    
}
int heapSort(int *heap,int n)
{
    buildHeap(heap,n);

    for (int i = n-1; i >=0; i--)
    {
        swap(heap,0,i);
        heapify(heap,i,0);

    }
}
int main()
{
    int n=5;
    int arr[6] = {5,3,2,6,33};
    buildHeap(arr,n);
    insertHeap(68,arr,n++);
    deleteHeap(arr,n--,0);
    printArr(arr,0,n);
    return 0;
}
