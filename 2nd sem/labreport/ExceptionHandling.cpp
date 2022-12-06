#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout<<"enter two nu ber: " << endl;
    cin>>a>>b;

    try{
        if (b == 0){
            throw b;
        }
        else{
            cout << a/b;
        }
    }
    catch(int x){
        cout<<"cant divide by 0";
    }
    return 0;
}