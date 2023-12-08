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

int main() {
    int num1, num2;

    // Get input from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Find and display the GCD using Euclidean Algorithm
    int gcd = gcdEuclidean(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0; // Exit successfully
}
