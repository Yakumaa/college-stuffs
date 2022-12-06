// 29.WAP to that asks for n numbers from users and store them in array and find maximum and minimum number of them.
#include<stdio.h>
int main(){
    int n, a[100];
    printf("Enter nth numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[0] > a[i])
        {
            a[0] = a[i]; 
        }
        else if (a[1] < a[i])
        {
            a[1] = a[i]; 
        }
    }
    
    printf("The maximum no is %d and minimum no is %d", a[1], a[0]);
    return 0;
}
