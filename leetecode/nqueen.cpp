#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool inBound(int i,int j,int n)
{
    return (i<n && j<n && j>=0 && i>=0);
}
bool isSafe(vector<string> &matrix, int row, int col)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[row][i]=='Q')
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][col]=='Q')
        {
            return false;
        }
    }
    int i = row;
    int j = col;
    while (inBound(i, j, n))
    {
        if (matrix[i][j]=='Q')
        {
            return false;
        }
        i--;
        j++;
    }
    i = row;
    j = col;
    while (inBound(i, j, n))
    {
        if (matrix[i][j]=='Q')
        {
            return false;
        }
        i++;
        j--;
    }
    i = row;
    j = col;
    while (inBound(i, j, n))
    {
        if (matrix[i][j]=='Q')
        {
            return false;
        }
        i++;
        j++;
    }
    i = row;
    j = col;
    while (inBound(i, j, n))
    {
        if (matrix[i][j]=='Q')
        {
            return false;
        }
        i--;
        j--;
    }
    return true;
}
void solve(vector<string> matrix, int row,vector<vector<string>> &allSols)
{
    int n = matrix.size();
    if(row==n)
    {
        allSols.push_back(matrix);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(matrix,row,i))
        {
            matrix[row][i] = 'Q';
            solve(matrix,row+1,allSols);
            matrix[row][i] = '.';
        }
    }
    
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> matrix;
    vector<vector<string>> allSols;
    string s;
    for (int i = 0; i < n; i++)
        {
            s.push_back('.');
        }
    for (int i = 0; i < n; i++)
    {
        
        matrix.push_back(s);
    }
    solve(matrix,0,allSols);
    return allSols;
}
int main()
{
    solveNQueens(4);
    return 0;
}
