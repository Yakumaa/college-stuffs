#include <iostream>
using namespace std;
 
class Value {
public:
    int a;
 
    // This function will take an object as an argument
    void add(Value V)
    {
        a = a + V.a;
    }
};
 
// Driver Code
int main()
{
 
    // Create objects
    Value V1, V2;
 
    // Values are initialized for both objects
    V1.a = 50;
    V2.a = 100;
 
    cout << "Initial Values \n";
    cout << "Value of object 1: " << V1.a <<endl
         << "Value of object 2: " << V2.a <<endl;

 
    // Passing object as an argument
    // to function add()
    V2.add(V1);
 
    // Changed values after passing
    // object as argument
    cout << "New values \n";
    cout << "Value of object 1: " << V1.a<<endl
         << "Value of object 2: " << V2.a<< endl;
 
    return 0;
}