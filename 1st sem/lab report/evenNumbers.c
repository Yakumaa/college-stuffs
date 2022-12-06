// 12.WAP that asks user for a number and then display only even numbers from 2 to n
#include <stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            printf("%d\t", i);
        }
        
    }
    return 0;
}
