
//28. WAP to find the average of first n natural no using function
#include<stdio.h>
int average(int num){   
    int avg;
    for (int i = 1; i <= num; i++)
    {
        avg += i;
    }
    return avg/num;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The average of first %d natural no is %d", n, average(n));
    return 0;
}
