#include <iostream>
#include <string>
using namespace std;

int main() {
    string binaryNum;
    cout << "Enter a binary number: ";
    cin >> binaryNum;

    // Find 2's complement of the binary number
    for(int i = 0; i < binaryNum.length(); i++) {
        if(binaryNum[i] == '0') {
            binaryNum[i] = '1';
        }
        else {
            binaryNum[i] = '0';
        }
    }
    int carry = 1;
    for(int i = binaryNum.length()-1; i >= 0; i--) {
        int num = binaryNum[i] - '0' + carry;
        binaryNum[i] = (num%2) + '0';
        carry = num/2;
    }

    cout << "2's complement is: ";
    cout << binaryNum << endl;

    return 0;
}
