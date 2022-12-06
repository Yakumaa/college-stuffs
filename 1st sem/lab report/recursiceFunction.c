// 26.Write a recursive function which accepts an integer and return its factorial
#include<stdio.h>
int factorial(int num){
    if (num>=1)
    {
        return num * factorial(num-1);
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %d", n, factorial(n));
    return 0;
}

