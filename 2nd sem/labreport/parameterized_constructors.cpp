// parameterized constructors
#include <iostream>
using namespace std;
 
class Constructor
{
private:
    int x, y;
 
public:
    // Parameterized Constructor
    Constructor(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
 
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
 
int main()
{
    // Constructor called
    Constructor c(10, 15);
 
    // Access values assigned by constructor
    cout << "x = " << c.getX() << ", y = " << c.getY();
 
    return 0;
}