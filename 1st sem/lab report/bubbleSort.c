//31. WAP to read N numbers and sort them in ascending order (using bubble sort)
#include<stdio.h>
int main(){
    int n, a[100], temp;
    printf("Enter nth numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
        }
        
    }
    printf("numbers in ascending orders are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    
    return 0;
}
