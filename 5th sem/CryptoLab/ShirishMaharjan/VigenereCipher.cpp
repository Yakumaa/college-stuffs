// #include <iostream>
// #include <cctype>
// #include <limits>

// using namespace std;

// // Function to perform Vigenere Cipher encryption
// string encryptVigenereCipher(const string &plaintext, const string &key) {
//     string ciphertext = "";
//     int keyLength = key.length();

//     for (size_t i = 0; i < plaintext.length(); ++i) {
//         char currentChar = plaintext[i];
//         char keyChar = key[i % keyLength];

//         if (isalpha(currentChar)) {
//             char base = (isupper(currentChar)) ? 'A' : 'a';
//             ciphertext += static_cast<char>((currentChar - base + keyChar - 'A') % 26 + base);
//         } else {
//             ciphertext += currentChar; // Non-alphabetic characters remain unchanged
//         }
//     }

//     return ciphertext;
// }

// // Function to perform Vigenere Cipher decryption
// string decryptVigenereCipher(const string &ciphertext, const string &key) {
//     string plaintext = "";
//     int keyLength = key.length();

//     for (size_t i = 0; i < ciphertext.length(); ++i) {
//         char currentChar = ciphertext[i];
//         char keyChar = key[i % keyLength];

//         if (isalpha(currentChar)) {
//             char base = (isupper(currentChar)) ? 'A' : 'a';
//             plaintext += static_cast<char>((currentChar - keyChar + 26) % 26 + base);
//         } else {
//             plaintext += currentChar; // Non-alphabetic characters remain unchanged
//         }
//     }

//     return plaintext;
// }

// int main() {
//     string key, input;

//     // Get key from the user
//     cout << "Enter the key for the Vigenere Cipher: ";
//     cin >> key;

//     // Clear the input buffer
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     // Get choice from the user (encryption or decryption)
//     cout << "Enter 'E' for Encryption or 'D' for Decryption: ";
//     char choice;
//     cin >> choice;

//     // Clear the input buffer
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     // Get input (plaintext or ciphertext) from the user
//     cout << "Enter the text: ";
//     getline(cin, input);

//     // Perform encryption or decryption based on user choice
//     if (toupper(choice) == 'E') {
//         string ciphertext = encryptVigenereCipher(input, key);
//         cout << "Encrypted Text: " << ciphertext << endl;
//     } else if (toupper(choice) == 'D') {
//         string decryptedText = decryptVigenereCipher(input, key);
//         cout << "Decrypted Text: " << decryptedText << endl;
//     } else {
//         cerr << "Invalid choice. Please enter 'E' or 'D'." << endl;
//         return 1; // Exit with an error code
//     }

//     return 0; // Exit successfully
// }

#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Vig {
   public:
      string k;
   Vig(string k) {
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
   string encryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + k[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
      }
      return output;
   }
   string decryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - k[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
      }
      return output;
   }
};

int main() {
  string key, input;
  // Get key from the user
  cout << "Enter the key for the Vigenere Cipher: ";
  cin >> key;

  // Clear the input buffer
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Get choice from the user (encryption or decryption)
  cout << "Enter 'E' for Encryption or 'D' for Decryption: ";
  char choice;
  cin >> choice;

  // Clear the input buffer
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Get input (plaintext or ciphertext) from the user
  cout << "Enter the text: ";
  getline(cin, input);

  Vig v(key);

  // Perform encryption or decryption based on user choice
  if (toupper(choice) == 'E') {
      string ciphertext = v.encryption(input);
      cout << "Encrypted Text: " << ciphertext << endl;
  } else if (toupper(choice) == 'D') {
      string decryptedText = v.decryption(input);
      cout << "Decrypted Text: " << decryptedText << endl;
  } else {
      cerr << "Invalid choice. Please enter 'E' or 'D'." << endl;
      return 1; // Exit with an error code
  }

  cout << "-------------------------------------------------------" << endl;
  cout << "Lab No.: 4" <<endl;
  cout << "Name: Shirish Maharjan" <<endl;
  cout << "Roll No.: 20-00036-5 (Section: 'A')" <<endl;
  cout << "-------------------------------------------------------" << endl;

  return 0; // Exit successfully
}