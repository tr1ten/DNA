#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> res;
    int m=matrix.size(),n=matrix[0].size();

    int row = 0;
    int col = 0;
    while (n>0 && m>0)
    {
        // upper
        int i;
        for (i = 0; i < n; i++)
        {
            res.push_back(matrix[row][col+i]);
        }
        i -=1;
        // right
        int j;
        for (j = 0; j < m-1; j++)
        {
            res.push_back(matrix[row+j+1][col+i]);
        }
        if(res.size()==matrix[0].size()*matrix.size())
        {
            break;
        }
        j -=1;
        // bottom
        int k;
        for (k = 0; k < n-1; k++)
        {
            res.push_back(matrix[row+j+1][col+i-k-1]);
        }
        if(res.size()==matrix[0].size()*matrix.size())
        {
            break;
        }
        k -=1;
        // left
        int p;
        for (p = 0; p < m-2; p++)
        {
            res.push_back(matrix[row+j-p][col+i-k-1]);
        }
        row ++;
        col ++;
        m -=2;
        n -=2;
    }
    return res;
}
void printMatrix(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}   
int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printMatrix(matrix);
    for(int i:spiralOrder(matrix))
    {
        cout << i << endl;
    }
    return 0;
}
