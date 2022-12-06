// C program to illustrate the concept of
// returning pointer from a function
#include <iostream>
using namespace std;

// Function that returns pointer
int* func()
{
    // Declare a static integer
    static int A = 10;
    return (&A);
}
  
// Driver Code
int main()
{
    // Declare a pointer
    int* p;
  
    // Function call
    p = func();
  
    // Print value at the above address
    cout << "the vlaue is " << *p << endl;
    
    // Print Address
    cout << "the address is " << p;
  
    
    return 0;
}