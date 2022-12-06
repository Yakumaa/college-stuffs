// 14.WAP to display the series 1/2 2/3 3/4 4/5 ....n-1/n.
#include<stdio.h>
int main(){
    int n;
    printf("Enter the nth term: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        printf("%d/%d, ", i, i+1);
    }
    
    
    return 0;
}
