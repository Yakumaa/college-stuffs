#include <iostream>
using namespace std;

class A{
public:
    void show(){
        cout<<"this is A"<< endl;;
    }
};
class B: public A{
    public:
        
    void show(){
        cout<<"this is B";
    }

};

int main(){
    B b;
    b.show();
    b.A::show(); //ambigous removed
    
    return 0;
}