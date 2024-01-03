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
    return 0;
}