#include <iostream>
#include <vector>
#include <string>
using namespace std;
void rotateMatrix(vector<vector<int>> &matrix,int row,int col, int n)
{
    if(n<2)
    {
        return;
    }
    int p=0;
    int temp1,temp2,temp3;
    while (p<n-1)
    {
        temp1 = matrix[row+p][col+n-1];
        temp2 = matrix[row+n-1][col+n-1-p];
        temp3 = matrix[row+n-1-p][col];
        matrix[row+p][col+n-1] = matrix[row][col+p];
        matrix[row+n-1][col+n-1-p] = temp1;
        matrix[row+n-1-p][col] = temp2;
        matrix[row][col+p] = temp3;
        p++;
    }
    return rotateMatrix(matrix,row+1,col+1,n-2);
    
}
int main()
{
    vector<vector<int>> matrix = {
                                {1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}
                                
                                };
    rotateMatrix(matrix,0,0,4);
    return 0;
}
