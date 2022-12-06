#include<iostream>
using namespace std;
class A {
private:
    int x;
public:
    void setData(){
        x = 10;
    }
    friend void func(A a); //friend function 
};

void func(A a){
    cout << a.x/2;
}

int main() {
   A a;
   a.setData();
   func(a);
   return 0;
}