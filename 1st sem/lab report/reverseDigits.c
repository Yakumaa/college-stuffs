// 20.WAP to reverse the digits of a number.
#include<stdio.h>
int main(){
    int num, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num != 0)
    {
        reverse = (num % 10) + reverse * 10; 
        num = num / 10;
    }
    printf("The reversed number is %d", reverse);
    
    return 0;
}
