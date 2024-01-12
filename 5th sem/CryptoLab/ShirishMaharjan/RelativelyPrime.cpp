#include <iostream>

using namespace std;

// Function to find the GCD using Euclidean Algorithm
int gcdEuclidean(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if two numbers are relatively prime
bool areRelativelyPrime(int num1, int num2) {
    // Find the GCD of the two numbers
    int gcd = gcdEuclidean(num1, num2);

    // If GCD is 1, the numbers are relatively prime; otherwise, they are not
    return gcd == 1;
}

int main() {
    int num1, num2;

    // Get input from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Check and display whether the numbers are relatively prime
    if (areRelativelyPrime(num1, num2)) {
        cout << num1 << " and " << num2 << " are relatively prime." << endl;
    } else {
        cout << num1 << " and " << num2 << " are not relatively prime." << endl;
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "Lab No.: 7" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll No.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0; // Exit successfully
}
