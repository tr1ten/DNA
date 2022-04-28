#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findRMax(int start, vector<int> &arr)
{
    int max = arr[start];
    int index = start;
    for (int i = start+1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}
int trap(vector<int> &height)
{
    int n = height.size();
    // test this hypo
    if (n < 3)
    {
        return 0;
    }
    int count = 0;
    int maxL = 0;
    int maxR = findRMax(2, height);

    for (int i = 1; i < n - 1; i++)
    {

        int temp = (min(height[maxL], height[maxR]) - height[i]);
        if (temp > 0)
        {
            count += temp;
        }
        if (height[maxL] < height[i])
        {
            maxL = i;
        }
        if (i >= maxR)
        {
            maxR = findRMax(i + 1, height);
        }
    }
    return count;
}
int main()
{
    vector<int> height = {4,2,0,3,2,5};
    cout << trap(height) << endl;
    return 0;
}
