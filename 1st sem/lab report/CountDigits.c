// 18.WAP to count number of digits in a number.
#include<stdio.h>
int main(){
    int num, counter;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num != 0)
    {
        num /= 10;
        counter++;
    }
    printf("THe lenght of the number is %d", counter);
    return 0;
}