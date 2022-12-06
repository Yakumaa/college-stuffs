#include <iostream>
using namespace std;
 
class Reference {
public:
    int a;
 
    // This function will take an object as an argument
    Reference *add(Reference *Ra, Reference *Rb)
    {
        Reference Rc;
        Rc.a = Ra->a + Rb->a; 
        return &Rc;
    }
};
 
// Driver Code
int main()
{
 
    // Create objects
    Reference R1, R2, R3;
 
    // Values are initialized for both objects
    R1.a = 50;
    R2.a = 100;
    R3.a = 0;
 
    cout << "Initial Values \n";
    cout << "Value of object 1: " << R1.a <<endl
         << "Value of object 2: " << R2.a <<endl
         << "Value of object 3: " << R3.a <<endl;

 
    // Passing object as an argument
    // to function add()
    R3 = *R3.add(&R1, &R2);
 
    // Changed values after passing
    // object as argument
    cout << "New values \n";
    cout << "Value of object 1: " << R1.a<<endl
         << "Value of object 2: " << R2.a<< endl
         << "Value of object 3: " << R3.a <<endl;
 
    return 0;
}