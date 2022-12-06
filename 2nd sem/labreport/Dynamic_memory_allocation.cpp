#include <iostream>
using namespace std;

int main(){
    // declare an int pointer
    int* pointInt;
    // dynamically allocate memory
    pointInt = new int;
    // assigning value to the memory
    *pointInt = 5;
    
    cout<< *pointInt <<endl;
    // deallocate the memory
    delete pointInt;
    
    return 0;
}