//Write a program that takes any positive number and display the result after computing Totient value

#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a); //Euclidean Algorithm
}

int phi(int n)
{
    int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "phi(" << n << ") = " << phi(n) << endl;
    return 0;
}
