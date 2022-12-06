// 6.WAP to read multiple values of different types using single scanf function
#include <stdio.h>
#include <string.h>
int main(){
    int a;
    float b;
    char c;
    char d[10];


    scanf("%d %f %c %[^\n]s", &a, &b, &c, &d);
    // gets(d);
    printf(" this is integer: %d\n this is float: %f\n this is character: %c\n this is string: %s" , a, b, c, d);
    
    return 0;
}
