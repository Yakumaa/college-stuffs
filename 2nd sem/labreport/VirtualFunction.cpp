#include <iostream>
using namespace std;

class A{
public:
    virtual void show(){
        cout<<"this is A"<< endl;;
    }
};
class B: public A{
    public:
        
    void show(){
        cout<<"this is B";
    }

};
class C: public A{
    public:
        
    void show(){
        cout<<"this is C";
    }

};

int main(){
    A *p, a;
    B b;
    C c;
    p =&b;
    p->show(); // points to class b object function since A has virtual function
    p = &c;
    p->show();
    p =&a;
    p->show();
    
    return 0;
}