#include<iostream>
using namespace std;
class time{
    private:
        int hrs, mins;
    public:
        time(int h,int m){
            hrs=h;mins=m;
        }
        void operator=(time &t){
            hrs=t.hrs;
            mins=t.mins;
        }
        void getData(){
            cout<<"("<<hrs<<","<<mins<<")"<<endl;
        }
};

int main(){
    time t1(3,55); 
    time t2(4,2);
    t1.getData();
    t1=t2;
    t1.getData();
    return 0;
    }