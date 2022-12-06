#include <iostream>
using namespace std;

int square(int s)
{
    return s*s;
}
float square(float s)
{
    return s*s;
}


int main()
{
    int x = 3;
    float y = 3.3;
    cout << "The cube of 3 is: " << square(x) << "\n";
    cout << "The cube of 3.3 is: " << square(y) << "\n";
    return 0;
}