#include <iostream>
#include <vector>
#include <string>
using namespace std;
int lazyBs(vector<int> vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (vec[mid] == target)
        {
            return mid;
        }
        if (vec[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return vec[mid] < target ? mid : mid - 1;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int col = lazyBs(matrix[0], target);
    if (col < 0 || col >= matrix[0].size())
    {
        return false;
    }
    for (int j = col; j >= 0; j--)
    {
        int start = 0;
        int end = matrix.size() - 1;
        int mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (matrix[mid][j] == target)
            {
                return true;
            }
            if (matrix[mid][j] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1}};
    cout << searchMatrix(matrix, 2) << endl;
    return 0;
}
