/////////////////////////////FIXED POINT METHOD//////////////////////////////////
#include <stdio.h>
#include <math.h>
#define EPS 0.00001


float g(float x){
    return sqrt(2*x+3);
}

int main(){
    float x0, x1;
    int n = 1;

    printf("Enter valid initial points x0 :");
    scanf("%f", &x0);
    x1 = g(x0);

    while (fabs((x1-x0)/x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = g(x0);
        printf("%f ", x1);
        if (g(x1) == 1){
            break;
        }
    }

    printf("The approximate root of given function is %f with %d number of iterations", x1, n);

    return 0;
}
