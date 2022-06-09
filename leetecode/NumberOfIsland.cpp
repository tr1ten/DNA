#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
struct VectorHash
{
    size_t operator()(const std::vector<int> &v) const
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
        {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
void markIsland(const vector<vector<char>>& grid,vector<int> pos,unordered_set<vector<int>,VectorHash> &hset)
{
    int rows = grid.size();
    int cols = grid[0].size();
    if(pos[0]>=cols || pos[1]>=rows || pos[0] < 0 || pos[1] <0 ||  grid[pos[1]][pos[0]]=='0' || hset.count(pos))
    {
        return;
    }
    hset.insert(pos);
    markIsland(grid,{pos[0]+1,pos[1]},hset);
    markIsland(grid,{pos[0]-1,pos[1]},hset);
    markIsland(grid,{pos[0],pos[1]+1},hset);
    markIsland(grid,{pos[0],pos[1]-1},hset);

}
int numIslands(vector<vector<char>>& grid) {
    int icount = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    unordered_set<vector<int>,VectorHash> hset;
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if(!hset.count({x,y}) && grid[y][x]=='1')
            {
                icount++;
                markIsland(grid,{x,y},hset);
            }
        }
        
    }
    return icount;
       
}
int main()
{
    
    return 0;
}
