/////////////////////////////NEWTON RAPHSON METHOD//////////////////////////////////
#include <stdio.h>
#include <math.h>
#define EPS 0.01


float f(float x){
    return log(x) - cos(x);
}
float fd(float x){
    return (1/x)+sin(x);
}

int main(){
    float x0, x1;
    int n = 1;
    do
    {
        printf("Enter valid initial points x0 :");
        scanf("%f", &x0);
        
    } while (fd(x0) == 0);
    
    x1 = x0 - (f(x0)/fd(x0));
    while (fabs((x1-x0)/x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = x0 - (f(x0)/fd(x0));
        printf("%f ", x1);
        if (f(x1) == 0){
            break;
        }
    }
    
    // do
    // {
    //     n++;
    //     x0 = x1;
    //     x1 = x0 - (f(x0)/fd(x0));
    //     if (f(x1) == 0){
    //         break;
    //     }
    // } while (fabs((x1-x0)/x1) > EPS);

    printf("The approximate root of given function is %f with %d number of iterations", x1, n);

    return 0;
}
