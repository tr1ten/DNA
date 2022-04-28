#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef struct Position
{
    int x;
    int y;
} Position;
bool check(vector<vector<char>> &img, Position &tl, Position &tr)
{
    for (int i = 0; i <= (tr.y - tl.y); i++)
    {
        for (int j = 0; j <= (tr.x - tl.x); j++)
        {
            if (img[tl.y + j][tl.x + i] == '0')
            {
                return false;
            }
        }
    }
    return true;
}
bool convulate(vector<vector<char>> &img, int kernel_size)
{
    Position tl = {0, 0};
    Position tr = {kernel_size - 1, kernel_size - 1};
    int h = img.size();
    int w = img[0].size();
    while (tr.y < h)
    {
        while (tr.x < w)
        {
            if (check(img, tl, tr))
            {
                return true;
            }
            tr.x++;
            tl.x++;
        }
        tr.x = kernel_size-1;
        tr.y++;
        tl.x = 0;
        tl.y++;
    }
    return false;
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int kernal_size = min(m, n);
    while (kernal_size > 0)
    {
        if (convulate(matrix, kernal_size))
        {
            return kernal_size * kernal_size;
        }
        kernal_size--;
    }
    return 0;
}
int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}, {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}
