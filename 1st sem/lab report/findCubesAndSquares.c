//21.WAP to find cubes and squares of first n natural numbers entered by user.
#include<stdio.h>
int main(){
    int num, i, square, cube;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The squares are: ");
    for (int i = 1; i <= num; i++)
    {
        square = i * i;
        printf("%d ", square);
    }
    printf("\n");
    printf("The cubes are: ");
    for (int i = 1; i <= num; i++)
    {
        cube = i * i * i;
        printf("%d ", cube);
    }
    
    return 0;
}
