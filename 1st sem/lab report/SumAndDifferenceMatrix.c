//33.WAP to ask two m*n matrixes and display both the sum and difference of two matrices.
#include<stdio.h>
int main(){
    int matrix1[5][5], matrix2[5][5], diff[5][5], add[5][5], i, j, m, n;

    printf("Enter order for matrix: ");
    scanf("%d %d", &m, &n);

    //reading first matrix
    printf("Enter 9 number for 1st matrix: ");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    //reading second matrix
    printf("Enter 9 number for 2nd matrix: ");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }    
    }

    //calculating difference of matrices
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            diff[i][j]= matrix1[i][j] - matrix2[i][j];
        }    
    }

     //calculating addition of matrices
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            add[i][j]= matrix1[i][j] + matrix2[i][j];
        }    
    }

    printf("First matrix is: \n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Second matrix is: \n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Sum of matrix is: \n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t", add[i][j]);
        }
        printf("\n");
    }

    printf("Difference of matrix is: \n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}