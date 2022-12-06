// Constructor overloading
#include <iostream>
using namespace std;
 
class construct{
    private:
        float area;
    public:   
        // Constructor with no parameters
        construct()
        {
            area = 0;
        }
        
        // Constructor with two parameters
        construct(int a, int b)
        {
            area = a * b;
        }
        //copy constructor
        construct(construct &x){
            area = x.area;
        }
        void display()
        {
            cout<< "area: " << area<< endl;
        }
};
 
int main()
{
    // Constructor Overloading
    // with two different constructors
    // of class name
    construct d;
    construct p( 10, 20);
    construct c(p);
     
    d.display();
    p.display();
    c.display();
    return 0;
}