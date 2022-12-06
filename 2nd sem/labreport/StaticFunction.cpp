#include <iostream>
using namespace std;
  
class A {
public:
    static void f()
    {
        cout << "GeeksforGeeks!";
    }
};
  
// Driver Code
int main()
{
    A::f();
}