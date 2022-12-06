#include <iostream>
using namespace std;

class lecture{
    private:
        int id;
        string name;

    public:
        void readdata(){
            cout<<"enter lecture id: ";
            cin>> id;
            cout<<"enter lecture name: ";
            cin>> name;
        }
        void printdata(){
            cout << "id = " << id << endl;
            cout << "name = " << name << endl;
        }
};

class Parttime: public lecture{
    private:
        float pay_per_hr;
    public:
        void readdata(){
            cout<<"enter pay per hour: ";
            cin>> pay_per_hr;
        }
        void printdata(){
            cout << "pay per hour = " << pay_per_hr << endl;
            
        }
};

class Fulltime: public lecture{
    private:
        float pay_per_month;
    public:
        void readdata(){
            cout<<"enter pay per month: ";
            cin>> pay_per_month;
        }
        void printdata(){
            cout << "pay per month = " << pay_per_month << endl;
            
        }
};

int main(){
    // lecture l;
    // l.readdata();
    // l.printdata();

    // Parttime p;
    // p.readdata();
    // p.printdata();

    // Fulltime f;
    // f.readdata();
    // f.printdata();

    // lecture l;
    // l.lecture::readdata();
    // l.lecture::printdata();

    Parttime p;
    p.lecture::readdata();
    p.lecture::printdata();
    p.readdata();
    p.printdata();

    Fulltime f;
    // f.lecture::readdata();
    // f.lecture::printdata();
    f.Fulltime::readdata();
    f.Fulltime::printdata();

    return 0;
}