#include <iostream>
using namespace std;

namespace ns1{
    int value = 10;
}

namespace ns2{
    float value = 5.5;
}

int main(){
    cout << ns1::value <<endl;
    cout << ns2:: value <<endl;

    return 0;
}