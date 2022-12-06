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
        distances(float x){
            feet = int(x);
            inch = 12*(x-feet);
        }
        void getData(){
            cout<<"feet= "<<feet<<endl;
            cout<<"inches = " << inch;
        }
};

int main(){
    distances d(3.8);
    d.getData();
    return 0;
    }