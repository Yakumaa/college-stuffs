//25.Write a function that reads a float and integer numberas arguments and return their product.
#include<stdio.h>
float product(float a, int b){
    printf("Enter two numbers: ");
    scanf("%f %d", &a, &b);
    return a * b; 
}

int main(){
    float a, result;
    int b;
    
    result = product(a, b);
    printf("%f", result);
    return 0;
    
}
