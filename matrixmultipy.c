#include <stdio.h>
// Matrix Multiplication
void make_matrix(int row, int col, int (*A)[100])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the element at (%d,%d) = ", i, j);
            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }
}

void print_matrix(int row, int col, int (*A)[100])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrix(int row, int col, int p,
                     int (*A)[100], int (*B)[100])
{
    int z[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int o = 0;
            for (int k = 0; k < p; k++)
            {
                o += A[i][k] * B[k][j];
            }
            z[i][j] = o;
        }
    }
    printf("\nMultiplied Matrix :\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row1, col1, col2;
    printf("Enter the no. of rows of 1st Matrix = ");
    scanf("%d", &row1);
    printf("\nEnter the no. of colums of 1st Matrix = ");
    scanf("%d", &col1);

    int x[row1][col1];
    make_matrix(row1, col1, x);
    print_matrix(row1, col1, x);

    printf("\n***POINT TO BE NOTED***\n");
    printf("Since we are doing matrix multiplication...\n");
    printf("This implies that - No. of Columns of 1st Matrix = No. of rows of 2nd Matrix...\n");
    printf("Therefore, we're only going to take input for no. of colums for 2nd matrix...\n\n");
    printf("Enter the no. of colums of 2nd matrix = ");
    scanf("%d", &col2);

    int y[col1][col2];
    make_matrix(row1, col1, y);
    print_matrix(row1, col1, y);

    printf("\n");

    multiply_matrix(row1, col2, col1, x, y);

    return 0;
}