#include <iostream>
#include <bitset>

using namespace std;

// Function to perform the S-box substitution (S1)
bitset<4> sBoxSubstitutionS1(bitset<6> input) {
    // Define the S1 box matrix
    int s1Box[4][16] = {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    };

    // Extract row and column indices from the input
    int row = (input[0] << 1) + input[5];
    int col = (input[1] << 3) + (input[2] << 2) + (input[3] << 1) + input[4];

    // Perform S-box substitution
    int output = s1Box[row][col];

    // Convert the output to a 4-bit binary representation
    return bitset<4>(output);
}

int main() {
    // Example input for S1
    bitset<6> input("101010");

    // Perform S-box substitution
    bitset<4> output = sBoxSubstitutionS1(input);

    // Display the input and output
    cout << "S-box S1 Example:" << endl;
    cout << "Input:  " << input << " (binary)" << endl;
    cout << "Output: " << output << " (binary)" << endl;

    return 0;
}
