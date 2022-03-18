#include <iostream>
#include <vector>
#include <string>
using namespace std;

int search(vector<int> &arr, int target)
{

    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {

        int mid = (end + start) / 2;
        if (target == arr[mid])
        {

            return mid;
        }
        if (arr[mid] >=arr[start])
        {
            if (arr[mid] < target || arr[start] > target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            if (arr[mid] > target || arr[end] < target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {3,1};
    cout << search(arr, 1) << endl;
    return 0;
}
