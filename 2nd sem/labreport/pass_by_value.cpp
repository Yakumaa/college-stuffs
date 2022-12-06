#include <iostream>
using namespace std;

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 3, y = 5;
    cout << "Before swap"<< endl;
    cout << " value of x: " << x << "\n";
    cout << " value of y: " << y << "\n";

    swap(x, y);
    cout << "After swap"<< endl;
    cout << " value of x: " << x << "\n";
    cout << " value of y: " << y << "\n";
    return 0;
}