#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
bool dfs(int root, unordered_map<int, vector<int>> &adjacencyList, unordered_set<int> &visited, int target)
{
    if (root == target)
    {
        return true;
    }
    visited.insert(root);
    bool found=false;
    for (auto nbr : adjacencyList[root])
    {
        if (!visited.count(nbr))
        {
            found = dfs(nbr, adjacencyList, visited, target);
            if(found)
            {
                return true;
            }
        }
    }
    return false;
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    unordered_map<int, vector<int>> adjacencyList;
    unordered_set<int> visited;
    for (auto edge : edges)
    {
        int p1 = edge[0];
        int p2 = edge[1];
        if (adjacencyList.count(p1) == 0)
        {
            adjacencyList[p1] = {p2};
        }
        else
        {
            adjacencyList[p1].push_back(p2);
        }
        if (adjacencyList.count(p2) == 0)
        {
            adjacencyList[p2] = {p1};
        }
        else
        {
            adjacencyList[p2].push_back(p1);
        }
    }
    return dfs(source, adjacencyList, visited, destination);
}
int main()
{
    vector<vector<int>> edges = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
    cout << validPath(10,edges,9,5); 
    return 0;
}
