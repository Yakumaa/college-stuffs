//32.WAP to read a matrix of order m*n from user. Pass this matrix to function and multiply each element of the matrix by 3.
#include<stdio.h>
int matrix[5][5], i, j;
int multiply(int num){
    int product;
    product = matrix[i][j] * num;
    return product;
}
int main(){
    int m, n;
    
    printf("Enter order for matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter elements for matrix: \n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The resultant matrix is: \n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t", multiply(3));
        }
        printf("\n");
    }

    return 0;
}
