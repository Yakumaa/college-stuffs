#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

// Function to perform Shift Cipher encryption
string encryptShiftCipher(string plaintext, int key) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext += ((plaintext[i] - base + key) % 26 + base);
        } else {
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

// Function to perform Shift Cipher decryption
string decryptShiftCipher(string ciphertext, int key) {
    return encryptShiftCipher(ciphertext, 26 - key); // Decryption is encryption with the opposite key
}

int main() {
    int key;
    string input;

    // Get input (plaintext or ciphertext) from the user
    cout << "Enter the text: ";
    getline(cin, input);

    // Get key from the user
    cout << "Enter the key for the Shift Cipher: ";
    cin >> key;

    // // Clear the input buffer
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get choice from the user (encryption or decryption)
    cout << "Enter 'E' for Encryption or 'D' for Decryption: ";
    char choice;
    cin >> choice;

    // // Clear the input buffer
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Perform encryption or decryption based on user choice
    if (toupper(choice) == 'E') {
        string ciphertext = encryptShiftCipher(input, key);
        cout << "Encrypted Text: " << ciphertext << endl;
    } else if (toupper(choice) == 'D') {
        string decryptedText = decryptShiftCipher(input, key);
        cout << "Decrypted Text: " << decryptedText << endl;
    } else {
        cerr << "Invalid choice. Please enter 'E' or 'D'." << endl;
        return 1; // Exit with an error code
    }

    return 0; // Exit successfully
}
