#include <iostream>
#include <vector>

using namespace std;

// Function to perform Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int &x, int &y) {
    // Base case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // Recursive call
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    // Update x and y using results of recursive call
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Function to compute multiplicative inverse in modulo n
int computeMultiplicativeInverse(int a, int n) {
    int x, y;
    int gcd = extendedEuclidean(a, n, x, y);

    // Check if the multiplicative inverse exists
    if (gcd != 1) {
        cout << "Multiplicative inverse does not exist for " << a << " modulo " << n << "." << endl;
        return -1; // Indicates failure
    }

    // Ensure the result is positive
    int inverse = (x % n + n) % n;

    return inverse;
}

int main() {
    int a, n;

    // Get input from the user
    cout << "Enter the number (a): ";
    cin >> a;

    cout << "Enter the modulo (n): ";
    cin >> n;

    // Compute and display the multiplicative inverse
    int multiplicativeInverse = computeMultiplicativeInverse(a, n);

    if (multiplicativeInverse != -1) {
        cout << "Multiplicative inverse of " << a << " modulo " << n << " is: " << multiplicativeInverse << endl;
    }

    return 0; // Exit successfully
}
