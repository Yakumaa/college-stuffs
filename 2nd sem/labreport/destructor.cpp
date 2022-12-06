#include <iostream>
using namespace std;

class destructor{
    public:
        destructor(){
            cout << "constructor invoked"<<endl;
        }
        ~destructor(){
            cout << "destructor invoked"<<endl;
        }
};

int main(){
    destructor d;

    return 0;
}