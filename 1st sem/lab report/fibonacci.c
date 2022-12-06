// 17.WAP to generate Fibonacci series of n terms entered by user using iteration.
#include<stdio.h>
int main(){
    int a = 1, b = 1, n, c;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("%d \t", a);
    printf("%d \t", b);
    
    for (int i = 0; i < n; i++)
    {
        c = a+b;
        a = b;
        b = c;
        printf("%d \t", c);
    }
    return 0;
}
