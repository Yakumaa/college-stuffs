// 11.WAP to determine whether the number inputted by user is prime or not.
#include<stdio.h>
int main(){
    int n, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
  
       for (int i = 1; i <= n; ++i)
       {
           if (n % i == 0)
           {
               count++;
           }
          
       }
    
    if (count == 2)
    {
        printf("it is a prime number");
    }
   
    else{
            printf("it is not a prime number");
        }

    return 0;
}
