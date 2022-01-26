#include <iostream>
#include <vector>
using namespace std;
void tryMe(int r, int c, vector<vector<int>> &obstacleGrid, int &path)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // base case
    if (r < 0 || r >= m || c < 0 || c >=n || obstacleGrid[r][c] == 1)
    {
        return;
    }
    else if (r == m - 1 && c == n - 1)
    {
        path++;
    }

    else
    {
        // right
        tryMe(r, c + 1, obstacleGrid, path);
        // down
        tryMe(r + 1, c, obstacleGrid, path);
    }
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int path = 0;
    tryMe(0, 0, obstacleGrid, path);
    return path;
}
int main()
{
    vector<vector<int>> a={{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(a);

    return 0;
}
