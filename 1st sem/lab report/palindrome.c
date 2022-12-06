//35. WAP to find if the sting is palindrome or not
#include<stdio.h>
#include<string.h>
int main(){
    char s[10];
    int flag = 0, n, i;
    printf("Enter the string: ");
    gets(s);
    n = strlen(s);

    for (int i = 0; i < n/2; i++)
    {
        if (s[i] == s[n-i-1])
        {
            flag++;
        }
        
    }
    if (flag)
    {
        printf("sting is palindrome");
    }
    else{
        printf("sting is not a palindrome");
    }
    
    return 0;
}