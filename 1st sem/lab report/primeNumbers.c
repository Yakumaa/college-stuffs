// 13.WAP that asks user for a number and then display only prime numbers from 2 to n.
#include <stdio.h>
int main(){
    int n, count, i, j;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("the prime numbers are: ");

    for (i = 1; i <= n; i++)
    {
        count = 0;
        for (j = 1; j <= i; j++)
        {
            if(i % j == 0)
                {
                    count++;
                }
        }

        if (count == 2)
        {
            printf("%d\t", i);
        }
    }
    return 0;
}