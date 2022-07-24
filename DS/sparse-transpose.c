
int get2DIndex(int i, int j, int n) {
    return i * n + j;
}
int *sparseTranspose(int *matrix,int cols)
{
    int *rm = malloc(sizeof(int)*3*cols);
    for (int i = 0; i < cols; i++)
    {
        rm[get2DIndex(0,i,cols)] = matrix[get2DIndex(1,i,cols)];
        rm[get2DIndex(1,i,cols)] = matrix[get2DIndex(0,i,cols)];
        rm[get2DIndex(2,i,cols)] = matrix[get2DIndex(2,i,cols)];

    }
    return rm;

}
void printMatrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[get2DIndex(i,j,cols)]);
        }
        printf("\n");
    }
}

int main()
{
    // sparse matrix with array representation
    int matrix[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printMatrix((int *)matrix, 3, 3);
    printf("\n");
    int *rm = sparseTranspose((int *)matrix, 3);
    printMatrix(rm, 3, 3);
    free(rm);
    return 0;
}
