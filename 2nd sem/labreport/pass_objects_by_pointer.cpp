#include <iostream>
using namespace std;
 
class Pointer {
public:
    int a;
 
    // This function will take an object as an argument
    void add(Pointer* P)
    {
        a = a + P->a;
        // cout << P<<endl;
    }
};
 
// Driver Code
int main()
{
 
    // Create objects
    Pointer P1, P2;
 
    // Values are initialized for both objects
    P1.a = 50;
    P2.a = 100;
 
    cout << "Initial Values \n";
    cout << "Value of object 1: " << P1.a <<endl
         << "Value of object 2: " << P2.a <<endl;
    // cout<<&P1<<endl;
 
    // Passing object as an argument
    // to function add()
    P2.add(&P1);
 
    // Changed values after passing
    // object as argument
    cout << "New values \n";
    cout << "Value of object 1: " << P1.a<<endl
         << "Value of object 2: " << P2.a<< endl;
 
    return 0;
}