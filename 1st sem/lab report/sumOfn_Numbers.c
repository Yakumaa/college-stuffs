// 10.WAP that asks an integer number n and print the sum of natural numbers from 1 to n.
#include<stdio.h>
int main(){
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("sum of natural number from 1 to %d = %d", n, sum);
    
    return 0;
}
