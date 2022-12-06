//16. WAP  that  reads  anumber N  and generates following sequence.  If  N =  5,  series is: 5 4 3 2 1 0 1 2 3 4 5
#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = n; i > 0; i--)
    {
        printf("%d ", i);
    }
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", i);
    }
    
    return 0;
}
