#include <stdio.h>
// Q1
// Implement Linear search and Binary search on 1D array of Integers and also return
// the time complexity in all the cases i.e your worst case, average case, and best case.
int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int n, int target)
{
    int high = n - 1;
    int low = 0;
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int target = 5;
//     printf("%d\n", linearSearch(arr, n, target));
//     printf("%d\n", binarySearch(arr, n, target));
//     return 0;
// }
// for modified  bb 0(n) best case  else 0(n^2) for all
// O(1) space
// Q2
// WAP to implement Bubble sort on 1D array of Faculty structures (contains
// faculty_name, faculty_ID, subject_codes, class_names) with key as faculty_ID and
// also return the time complexity in all the cases i.e your worst case, average case, and
// best case.

struct data
{
    int id;
    char name[20];
    char class[20];
    char code[20];
};

int bubbleSort()
{
    struct data d[4];
    for (int i = 0; i < 4; i++)
    {
        printf("enter the  data of %d:", i + 1);
        scanf("%d", &d[i].id);
        scanf("%s", &d[i].name);
        scanf("%s", &d[i].class);
        scanf("%s", &d[i].code);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (d[j].id > d[j + 1].id)
            {
                struct data temp;
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d. ", d[i].id);
        printf("%s ", d[i].name);
        printf("%s ", d[i].class);
        printf("%s ", d[i].code);
        printf("\n");
    }
}

// int main()
// {
//     bubbleSort();
//     return 0;
// }
// Q3
// Implement Insertion and Selection sort on 1D array of integers and also return the
// time complexity in all the cases i.e your worst case, average case, and best case.
// 0(n^2) for all
// O(1) space
// not stable
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        int in = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                in = j;
            }
        }
        swap(arr, in, i);
    }
}
void testSelectionSort()
{
    int n = 6;
    int arr[] = {6, 5, 4, 2, 2, 1};
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
// int main()
// {
//     testSelectionSort();
//     return 0;
// }

// insertion
// 0(n) best case  and 0(n^2) for others
// O(1) space
void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key <= arr[j])
        {
            swap(arr, j, j + 1);
            j--;
        }
        arr[j + 1] = key;
    }
}
void testInsertionSort()
{
    int n = 6;
    int arr[] = {6, 5, 4, 2, 2, 1};
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}
// int main()
// {
//     testInsertionSort();
//     return 0;
// }
// Q4
// (a) Implement Quick Sort with duplicate numbers in the given array/elements.
// (b) Implement the ascending and descending order using Quick Sort.
// (c) Implement Quick Sort using first/last/any random element as pivot.
typedef struct Student
{
    char name[40];
    int roll;
    int totalMarks;
} Student;

void merge(Student *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int ni = mid - low + 1;
    int nj = high - mid;
    Student *b = (Student *)malloc(sizeof(Student) * (ni + nj));
    int k = 0;
    while ((i - low) < ni && (j - mid - 1) < nj)
    {
        if (arr[i].roll < arr[j].roll)
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    while ((i - low) < ni)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while ((j - mid - 1) < ni)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[k];
        k++;
    }
}
// Q5
// WAP to implement Merge Sort on 1D array of Student structures (contains
// student_name, student_roll_no, total_marks) with key as student_roll_no and also
// return the time complexity in all the cases i.e your worst case, average case, and best
// case.
// O(nlogn) for all
// space O(n)
void mergeSort(Student *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (high + low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void testMergeSort()
{
    int n = 3;
    Student arr[] = {{"shubh", 3, 2}, {"shubh", 2, 3}, {"shubh", 1, 4}};
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i].roll);
    }
    printf("\n");
}
int main()
{
    testMergeSort();
    return 0;
}

// quick sort
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// both asc and desc
int partition(int *arr, int low, int high, int asc, int pivotIndex)
{
    int pivot = arr[pivotIndex];
    int p2 = low - 1;
    for (int i = low; i <= high; i++)
    {
        if (i != pivotIndex && ((asc && arr[i] <= pivot) || (!asc && arr[i] >= pivot)))
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
// int main()
// {
//     testQuickSort();
//     return 0;
// }