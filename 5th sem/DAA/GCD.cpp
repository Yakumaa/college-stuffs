#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{

    int num1, num2, gcdResult;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    gcdResult = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is " << gcdResult;
    return 0;
}

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}