// 30.WAP to read n numbers from user and store in array. Add even numbers and odd numbers separately and display the result using function.
#include<stdio.h>
int n, odd_sum = 0, even_sum = 0, a[100];
int even(int num1){
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2 == 0)
        {
            even_sum += a[i];
        }
    }
    return even_sum;
}
int odd(int num2){
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2 != 0)
        {
            odd_sum += a[i];
        }      
    }
    return odd_sum;
}

int main(){
    printf("Enter nth numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("The sum of even numbers is %d\n", even(n));
    printf("The sum of odd numbers is %d", odd(n));
    return 0;
}