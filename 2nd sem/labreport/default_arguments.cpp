#include <iostream>
using namespace std;

int multiply(int a= 5, int b= 2){
    return a*b;
}
int main(){
    cout << "No argument passed: " << multiply() << endl;
    cout << "First argument passed: " << multiply(2)<< endl;
    cout <<  "Both arguments passed: " << multiply(3, 4) << endl;

    return 0;
}