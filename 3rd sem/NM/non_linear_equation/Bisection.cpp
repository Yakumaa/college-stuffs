#include <iostream>
#include <cmath>
#define EPS 0.00001
using namespace std;

float f(float x){
    return x*x*x-2*sin(x);
}

int main(){
    float a, b, c;
    int n = 0;
    // do
    // {
        cout << "Enter two valid initial points a and b :" << endl;
        cin >> a, b;
        
    // } while (f(a)*f(b) >= 0);
    
    do
    {
        n++;
        c = (a+b)/2;
        if (f(c) == 0){
            break;
        }
        else if (f(a)*f(c) < 0)
        {
            b = c;
        }
        else
            a = c;
    } while (fabs((b-a)/a) > EPS);

    cout << "The approximate root of given function is " << c << " with " << n << " number of iterations";

    return 0;
    
}
