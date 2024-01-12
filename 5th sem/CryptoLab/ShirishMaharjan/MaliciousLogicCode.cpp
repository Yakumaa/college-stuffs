//Write a malicious logic code (Trojan Horse/Virus) program that performs some malicious works.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file;
    file.open("malicious.txt");
    file << "This is a malicious code";
    file.close();

    cout << "Malicious code executed successfully!" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Lab No.: 18" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll No.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;
}