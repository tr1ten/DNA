#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// bad solution
struct ArrayHasher {
    size_t operator()(const std::array<int, 2>& a) const {
        size_t h = 0;

        for (auto e : a) {
            h ^= std::hash<int>{}(e)  + 0x9e3779b9 + (h << 6) + (h >> 2); 
        }
        return h;
    }   
};
int tryMe(int r, int c, vector<vector<int>> &obstacleGrid, int &path,unordered_map<array<int,2>, int,ArrayHasher> umap)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(umap.count({r,c}))
    {
        return umap[{r,c}];
    }
    // base case
    if (r < 0 || r >= m || c < 0 || c >=n || obstacleGrid[r][c] == 1)
    {
        return 0;
    }
    else if (r == m - 1 && c == n - 1)
    {
        path++;
        return 1;
    }

    else
    {
        // right
        umap[{r,c+1}]=tryMe(r, c + 1, obstacleGrid, path,umap);
        // down
        umap[{r+1,c}]=tryMe(r + 1, c, obstacleGrid, path,umap);
        return (umap[{r+1,c}] + umap[{r,c+1}]);
    }
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    unordered_map<array<int,2>, int, ArrayHasher> umap;
    int path = 0;
    tryMe(0, 0, obstacleGrid, path,umap);
    return path;
}
int main()
{
    vector<vector<int>> a={{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(a);

    return 0;
}
