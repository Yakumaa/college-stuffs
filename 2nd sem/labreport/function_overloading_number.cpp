#include <iostream>
using namespace std;

int area(int a)
{
    return a*a;
}
int area(int a, int b)
{
    return a*b;
}


int main()
{
    cout << "The area of square is: " << area(2) << "\n";
    cout << "The area of rectangle is: " << area(3, 4) << "\n";
    return 0;
}