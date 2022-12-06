// 8.WAPto calculate factorial of anumber.
#include <stdio.h>
int main(){
    int num, fac = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        fac = fac * i;
    }
    printf("the factorial of %d is = %d", num, fac);

    return 0;
}