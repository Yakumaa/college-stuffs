#include <iostream>

using namespace std;

// Function to compute the additive inverse in modulo n
int computeAdditiveInverse(int number, int modulo) {
    // Ensure the modulo is positive
    modulo = abs(modulo);

    // Compute the additive inverse
    int additiveInverse = modulo - (number % modulo);

    return additiveInverse % modulo; // Ensure the result is within the range [0, modulo)
}

int main() {
    int number, modulo;

    // Get input from the user
    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter the modulo (n): ";
    cin >> modulo;

    // Compute and display the additive inverse
    int additiveInverse = computeAdditiveInverse(number, modulo);
    cout << "The additive inverse of " << number << " in modulo " << modulo << " is: " << additiveInverse << endl;

    cout << "-------------------------------------------------------" << endl;
    cout << "Lab No.: 6" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll No.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0; // Exit successfully
}
