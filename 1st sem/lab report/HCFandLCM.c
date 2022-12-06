// 15.WAP to find GCD (HCF)and LCM of two numbers
// #include<stdio.h>
// int main(){
//     int num1, num2, hcf, lcm, a, b, t;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &num1, &num2);
    
//     a = num1;
//     b = num2;
//     while (b != 0)
//     {
//         t = b;
//         b = a % b;
//         a = t;
//     }
    
//     hcf = a;
//     lcm = (num1 * num2) / hcf;
//     printf("HCF: %d \nLCM: %d", hcf, lcm);
//     return 0;
// }

// OR
#include<stdio.h>
int main(){
    int num1, num2, hcf, lcm, a, b, t;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
for (int i = 1 ; i < num1; i++)
{
    if (num1%i ==0 && num2%i==0)
    {
        hcf = i;
    }
    
}
    lcm = (num1 * num2) / hcf;
    printf("HCF: %d \nLCM: %d", hcf, lcm);
    return 0;
}
