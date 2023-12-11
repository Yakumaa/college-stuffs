#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

// Function to encrypt the plaintext using Hill Cipher
void encryptHillCipher(const int keyMatrix[2][2], const char *plaintext, char *ciphertext) {
    int p1, p2, c1, c2;

    // Iterate through the plaintext in pairs
    for (int i = 0; i < strlen(plaintext); i += 2) {
        // Map characters to numerical values (A=0, B=1, ..., Z=25)
        p1 = plaintext[i] - 'A';
        p2 = plaintext[i + 1] - 'A';

        // Apply Hill Cipher encryption formula
        c1 = (keyMatrix[0][0] * p1 + keyMatrix[0][1] * p2) % 26;
        c2 = (keyMatrix[1][0] * p1 + keyMatrix[1][1] * p2) % 26;
        // cout<<c1;
        // cout<<c2;
        // Map numerical values back to characters
        ciphertext[i] = static_cast<char>(c1 + 'A');
        ciphertext[i + 1] = static_cast<char>(c2 + 'A');
    }

    // Null-terminate the ciphertext string
    ciphertext[strlen(plaintext)] = '\0';
}

// Function to decrypt the ciphertext using Hill Cipher
void decryptHillCipher(const int keyMatrix[2][2], const char *ciphertext, char *decryptedtext) {
    int p1, p2, c1, c2;

    // Calculate the determinant of the key matrix
    int determinant = (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0]) % 26;

    // Calculate the modular inverse of the determinant
    int detInverse = modInverse(determinant, 26);

    // Calculate the adjugate of the key matrix
    int adjKeyMatrix[2][2];
    adjKeyMatrix[0][0] = keyMatrix[1][1];
    adjKeyMatrix[0][1] = -keyMatrix[0][1];
    adjKeyMatrix[1][0] = -keyMatrix[1][0];
    adjKeyMatrix[1][1] = keyMatrix[0][0];

    // Apply Hill Cipher decryption formula
    for (size_t i = 0; i < strlen(ciphertext); i += 2) {
        // Map characters to numerical values (A=0, B=1, ..., Z=25)
        c1 = ciphertext[i] - 'A';
        c2 = ciphertext[i + 1] - 'A';

        // Calculate the plaintext values
        p1 = (adjKeyMatrix[0][0] * c1 + adjKeyMatrix[0][1] * c2) % 26;
        p2 = (adjKeyMatrix[1][0] * c1 + adjKeyMatrix[1][1] * c2) % 26;

        // Apply modular inverse
        p1 = (p1 * detInverse) % 26;
        p2 = (p2 * detInverse) % 26;

        // Ensure values are positive
        p1 = (p1 + 26) % 26;
        p2 = (p2 + 26) % 26;

        // Map numerical values back to characters
        decryptedtext[i] = static_cast<char>(p1 + 'A');
        decryptedtext[i + 1] = static_cast<char>(p2 + 'A');
    }

    // Null-terminate the decrypted text string
    decryptedtext[strlen(ciphertext)] = '\0';
}

int main() {
    int keyMatrix[2][2];
    char plaintext[100], ciphertext[100], decryptedtext[100];

    // Get key matrix from the user
    cout << "Enter the 2x2 key matrix (4 integers separated by spaces): ";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> keyMatrix[i][j];
        }
    }

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get plaintext from the user
    cout << "Enter the plaintext (in uppercase): ";
    cin.getline(plaintext, sizeof(plaintext));

    // Encrypt the plaintext
    encryptHillCipher(keyMatrix, plaintext, ciphertext);

    // Display the encrypted ciphertext
    cout << "Encrypted Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext
    decryptHillCipher(keyMatrix, ciphertext, decryptedtext);

    // Display the decrypted plaintext
    cout << "Decrypted Plaintext: " << decryptedtext << endl;

    return 0; // Exit successfully
}