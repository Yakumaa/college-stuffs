// 19.WAP to compute the sum of digits of a given integer number.
#include<stdio.h>
int main(){
    int num, a, b, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
        
    }
    printf("Sum of digits of given number is %d", sum);
    
    return 0;
}
