#include <iostream>
#include <vector>
using namespace std;
// transpose then two pointer method to swap !
void rotate(vector<vector<int>>& matrix) 
{
    int N = matrix.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int  temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
        
    }
    int i=0,j=N-1;
    while(i<j)
    {
        for (int k = 0; k < N; k++)
        {
            int temp = matrix[k][i];
            matrix[k][i] = matrix[k][j];
            matrix[k][j] = temp;
        }
        i++;
        j--;
        
    }
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
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(matrix);
    rotate(matrix);
    printMatrix(matrix);

    return 0;
}
