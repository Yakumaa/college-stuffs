#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char name[100];
    int age;
    ofstream outfile; //open file in write mode
    outfile.open("filehandling.txt");
    cout<<"enter your name: ";
    cin.getline(name, 100);
    outfile<<name<<endl;    //write inputted data intop filr
    cout<<"enter age: ";
    cin>>age;
    outfile<<age<<endl;
    outfile.close();
    ifstream infile;    //open a file in read mode
    infile.open("filehandling.txt");
    cout<<"reading from the file"<<endl;
    infile.getline(name, 100);
    cout<<name<<endl;   //write data at the screen
    infile>>age;    //read data from the file and display it
    cout<<age<<endl;
    infile.close();
    return 0;

}