#include<iostream>
using namespace std;
class A {
private:
    int x = 10;
public:
    A(){
        int a;
    }
    friend class B; //friend class 
};

class B {
private:
    int b;
public:
    void show(A a) {
         cout << "private member of A accessed friom B: " << a.x;
      }
};

int main() {
   A a;
   B b;
   b.show(a);
   return 0;
}