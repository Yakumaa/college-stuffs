#include<iostream>
using namespace std;
class distances{
    private:
        int feet, inch;
    public:
        distances(int f, int i){
            feet = f;
            inch = i;
        }
       
        operator float(){
            float b = feet + inch / 12;
            return b;
        }
};

int main(){
    distances d(3,6);
    float a = float (d);
    cout << a;
    return 0;
    }